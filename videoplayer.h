#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QGraphicsVideoItem>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QAudioOutput>
#include <QDebug>
#include <QAbstractSlider>
#include <QTimer>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMap>
#include "streamplayer.h"
#include "test.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class VideoPlayer;
}
QT_END_NAMESPACE

class VideoPlayer : public QMainWindow
{
    Q_OBJECT

public:
    VideoPlayer(QWidget *parent = nullptr);
    ~VideoPlayer();

private:
    StreamPlayer *streamPlayer;
    Test *test;
    Ui::VideoPlayer *ui;

    void InitVideo();
    void InitGraphics();

    //与Slider有关的播放控制变量
    QTimer *timer;
    qint64 maxValue=100;//设置进度条的最大值

    QMediaPlayer *player;
    QAudioOutput *audio;
    QGraphicsVideoItem *videoItem;
    QGraphicsScene *scene;

    QString durationTime;
    QString positionTime;
    QMap<QString,QString> files;//保存视频列表的名字与链接

    QListWidget *listWidget;

private slots:
    void on_liveStreamButton_clicked();
    void showVideoPlayer();

    void onStateChanged(QMediaPlayer::PlaybackState state);
    void getduration(qint64 playtime);

    void on_pushButton_Add_clicked();
    void on_pushButton_Player_clicked();
    void on_pushButton_Sound_clicked();
    void on_pushButton_Pause_clicked();
    void on_pushButton_Stop_clicked();
    void on_horizontalSlider_Volumn_valueChanged(int value);

    void onTimerOut();
    void slider_progress_clicked();
    void slider_progress_moved();
    void slider_progress_released();
    void on_pushButton_playlist_clicked();
};
#endif // VIDEOPLAYER_H
