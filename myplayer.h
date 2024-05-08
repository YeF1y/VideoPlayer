#ifndef MYPLAYER_H
#define MYPLAYER_H

#include <QObject>
#include <QMediaPlayer>

class MyPlayer : public QMediaPlayer
{
    Q_OBJECT
public:
    explicit MyPlayer(QObject *parent = nullptr);
protected:


signals:
};

#endif // MYPLAYER_H
