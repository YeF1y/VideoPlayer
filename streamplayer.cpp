#include "streamplayer.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QDebug>

StreamPlayer::StreamPlayer(QWidget *parent)
    : QWidget(parent),
    mediaPlayer(new QMediaPlayer(this)),
    videoWidget(new QVideoWidget(this)),
    layout(new QVBoxLayout(this)),
    returnButton(new QPushButton("Return", this))
{
    layout->addWidget(videoWidget);
    layout->addWidget(returnButton);
    setLayout(layout);

    mediaPlayer->setVideoOutput(videoWidget);
    //mediaPlayer->setSource(QUrl("http://8.138.163.61:8080/hls/123.m3u8"));
    mediaPlayer->setSource(QUrl("rtmp://8.138.163.61:1935/live/123"));

    QObject::connect(mediaPlayer, &QMediaPlayer::errorOccurred, [](QMediaPlayer::Error error){
        qDebug() << "Error occurred:" << error;
    });


    mediaPlayer->play();

    videoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setMinimumSize(800, 600); // 确保窗口大小合适

    connect(returnButton, &QPushButton::clicked, this, &StreamPlayer::onReturnButtonClicked);
}

StreamPlayer::~StreamPlayer() {
    delete mediaPlayer;
    delete videoWidget;
    delete layout;
    delete returnButton;
}

void StreamPlayer::onReturnButtonClicked() {
    emit returnToVideoPlayer();
}
