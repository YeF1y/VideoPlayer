#ifndef MYVIDEOITEM_H
#define MYVIDEOITEM_H

#include <QGraphicsVideoItem>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>


class MyVideoItem : public QGraphicsVideoItem
{
    Q_OBJECT
public:
    explicit MyVideoItem(QGraphicsVideoItem *parent = nullptr);
protected:
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

};

#endif // MYVIDEOITEM_H
