#include "videoplayer.h"
#include "ui_videoplayer.h"
#include "timemanager.h"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoPlayer)
{
    ui->setupUi(this);
    InitVideo();
    InitGraphics();

    //将timer连接至onTimerOut槽函数
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));

    //连接槽函数，信号为QMediaPlayer自带的durationChanged，槽就是自己定义的getduration，注意参数类型要一致
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(getduration(qint64)));

    connect(ui->horizontalSlider_Position,&QAbstractSlider::sliderPressed,this,&VideoPlayer::on_pushButton_Pause_clicked);
    connect(ui->horizontalSlider_Position,&QAbstractSlider::sliderMoved,this,&VideoPlayer::slider_progress_moved);
    connect(ui->horizontalSlider_Position,&QAbstractSlider::sliderReleased,this,&VideoPlayer::slider_progress_released);

    connect(player,SIGNAL(playbackStateChanged(QMediaPlayer::PlaybackState)),this,SLOT(onStateChanged(QMediaPlayer::PlaybackState)));

}

//初始化视图
void VideoPlayer::InitGraphics(){
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(QRectF());//传空值，scene自适应view大小
    ui->graphicsView->setAlignment(Qt::AlignHCenter);//窗口中心
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);

    ui->verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

    videoItem=new QGraphicsVideoItem;
    audio=new QAudioOutput(this);//qt6之后需要多加一个音频播放器
    videoItem->setScale(3);
    videoItem->setPos(0,0);

    videoItem->setFlags(QGraphicsVideoItem::ItemIsSelectable|
                        QGraphicsVideoItem::ItemIsFocusable);
    //qDebug()<<videoItem<<Qt::endl;
    scene->addItem(videoItem);
    player->setVideoOutput(videoItem);
    player->setAudioOutput(audio);
}

//初始化播放器
void VideoPlayer::InitVideo(){
    player=new QMediaPlayer(this);
    scene = new QGraphicsScene(this);
    listWidget = new QListWidget(this);

    timer = new QTimer(this);
    timer->setInterval(1000);//如果想看起来流畅些，可以把时间间隔调小，如100ms

    // 设置 QListWidget 的显示模式和选项
    ui->listWidget->setViewMode(QListWidget::ListMode);
    ui->listWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(ui->listWidget, &QListWidget::itemClicked, [=](QListWidgetItem *item) {
        timer->stop();
        ui->horizontalSlider_Position->setValue(0);
        QString fileName = item->text();
        ui->labelCurrentMedia->setText(fileName);
        player->setSource(QUrl::fromLocalFile(files.value(fileName)));//从哈系树通过item名即文件名获取当前文件路径

        item->setText(fileName);
        player->play();
        timer->start();
    });

    ui->listWidget->setVisible(0);

    ui->pushButton_Player->setEnabled(false);
    ui->pushButton_Sound->setEnabled(false);
    ui->pushButton_Pause->setEnabled(false);
    ui->pushButton_Stop->setEnabled(false);
    ui->horizontalSlider_Position->setEnabled(false);
    ui->horizontalSlider_Volumn->setEnabled(false);

}

VideoPlayer::~VideoPlayer()
{
    delete ui;
}

//点击 打开文件 槽函数
void VideoPlayer::on_pushButton_Add_clicked()
{
    timer->stop();
    ui->horizontalSlider_Position->setValue(0);
    QString currentpath=QDir::homePath();
    QString dlgTitle="请选择视频文件";
    QString strfilter="mp4 Files(*.mp4);;ALL Files(*.*)";
    QString allfiles=QFileDialog::getOpenFileName(this,dlgTitle,currentpath,strfilter);

    if(allfiles.isEmpty()){
        QMessageBox::critical(this,"错误","打开失败",QMessageBox::Yes);
        return;
    }

    if(allfiles.isEmpty())
        return;

    QListWidgetItem *item = new QListWidgetItem;
    QFileInfo file(allfiles);

    //如果播放列表里已经打开此视频，则不重新打开并且不再往Item中添加
    if(files.find(file.fileName())==files.end()){
        files.insert(file.fileName(),allfiles);//往视频播放列表哈系树里放入当前文件的名字与链接
        ui->labelCurrentMedia->setText(files.key(allfiles));//从哈系树获取当前文件名
        player->setSource(QUrl::fromLocalFile(allfiles));
        item->setText(files.key(allfiles));
        ui->listWidget->addItem(item);
    }
    else{
        QMessageBox::critical(this,"提示","您已经打开此视频",QMessageBox::Yes);
        return;
    }
    player->play();

    //启用按键并设置slider范围
    ui->pushButton_Player->setEnabled(true);
    ui->pushButton_Sound->setEnabled(true);
    ui->pushButton_Pause->setEnabled(true);
    ui->pushButton_Stop->setEnabled(true);
    ui->horizontalSlider_Volumn->setEnabled(true);
    ui->horizontalSlider_Position->setEnabled(true);
    ui->horizontalSlider_Position->setRange(0,maxValue);
    ui->horizontalSlider_Volumn->setRange(0,maxValue);
    timer->start();
}

void VideoPlayer::onStateChanged(QMediaPlayer::PlaybackState state){
    ui->pushButton_Player->setEnabled(!(state==QMediaPlayer::PlayingState));
    ui->pushButton_Pause->setEnabled(state==QMediaPlayer::PlayingState);
    ui->pushButton_Stop->setEnabled(state==QMediaPlayer::PlayingState);
}

void VideoPlayer::onTimerOut()
{
    ui->horizontalSlider_Position->setValue(player->position()*maxValue/player->duration());
}

void VideoPlayer::slider_progress_clicked()
{
    player->setPosition(ui->horizontalSlider_Position->value()*player->duration()/maxValue);
}

void VideoPlayer::slider_progress_moved()
{
    //暂时停止计时器，在用户拖动过程中不修改slider的值
    timer->stop();
    player->setPosition(ui->horizontalSlider_Position->value()*player->duration()/maxValue);
}

void VideoPlayer::slider_progress_released()
{
    //用户释放滑块后，重启定时器
    timer->start();
}

void VideoPlayer::on_pushButton_Player_clicked()
{
    player->play();
}

void VideoPlayer::on_pushButton_Sound_clicked()
{
    bool mte=audio->isMuted();
    audio->setMuted(!mte);

    if(!mte){
        ui->pushButton_Sound->setIcon(QIcon(":/new/prefix1/icon/VideoPlayer/mute.png"));
    }else{
        ui->pushButton_Sound->setIcon(QIcon(":/new/prefix1/icon/VideoPlayer/volumn.png"));
    }
}

void VideoPlayer::on_pushButton_Pause_clicked()
{
    player->pause();
}

void VideoPlayer::on_pushButton_Stop_clicked()
{
    player->stop();
    //全禁用
    ui->pushButton_Player->setEnabled(false);
    ui->pushButton_Sound->setEnabled(false);
    ui->pushButton_Pause->setEnabled(false);
    ui->pushButton_Stop->setEnabled(false);
    ui->horizontalSlider_Position->setEnabled(false);
    ui->horizontalSlider_Volumn->setEnabled(false);
}

void VideoPlayer::on_horizontalSlider_Volumn_valueChanged(int value)
{
    audio->setVolume(value);
}

void VideoPlayer::on_pushButton_playlist_clicked()
{
    if(ui->listWidget->isVisible())
        ui->listWidget->setVisible(0);
    else
        ui->listWidget->setVisible(1);

}

void VideoPlayer::getduration(qint64 playtime)

{
    //创建TimeManager对象用于时间格式处理
    TimeManager timemanager;
    playtime = player->duration();
    QString alltime = timemanager.formatTime(playtime);
    QString nowtime = timemanager.formatTime(player->position());
    ui->label_Ratio->setText(nowtime + " / " + alltime);
}
