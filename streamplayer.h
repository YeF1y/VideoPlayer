#ifndef STREAMPLAYER_H
#define STREAMPLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QPushButton>

class StreamPlayer : public QWidget {
    Q_OBJECT

public:
    explicit StreamPlayer(QWidget *parent = nullptr);
    ~StreamPlayer();

signals:
    void returnToVideoPlayer(); // 新增信号

private slots:
    void onReturnButtonClicked(); // 新增槽函数

private:
    QMediaPlayer *mediaPlayer;
    QVideoWidget *videoWidget;
    QVBoxLayout *layout;
    QPushButton *returnButton; // 新增返回按钮
};

#endif // STREAMPLAYER_H
