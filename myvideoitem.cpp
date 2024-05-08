#include "myvideoitem.h"

MyVideoItem::MyVideoItem(QGraphicsVideoItem *parent)
    : QGraphicsVideoItem{parent}
{}

// void MyVideoItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
// {
//     qDebug()<<"单击Item"<<Qt::endl;
// }

void MyVideoItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    //int mouse_x = QCursor::pos().x();
    //int mouse_y = QCursor::pos().y();
    //QWidget* subWidget = QApplication::widgetAt(mouse_x, mouse_y);
    //qDebug()<<subWidget<<Qt::endl;
    //QGraphicsVideoItem *videoItem =dynamic_cast<QGraphicsVideoItem*>(subWidget);
    //qDebug()<<"双击Item"<<Qt::endl;
    //qDebug()<<this<<Qt::endl;
}
