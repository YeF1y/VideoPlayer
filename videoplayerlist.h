#ifndef VIDEOPLAYERLIST_H
#define VIDEOPLAYERLIST_H

#include <QObject>
#include <QListWidget>
#include <QListWidgetItem>

class VideoPlayerList
{
public:
    VideoPlayerList();
private:
    QListWidget *listWidget;
    QListWidgetItem *item;
};

#endif // VIDEOPLAYERLIST_H
