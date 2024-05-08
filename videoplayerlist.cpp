#include "videoplayerlist.h"

VideoPlayerList::VideoPlayerList() {
    listWidget = new QListWidget();
    item = new QListWidgetItem("Item 1");
    listWidget->addItem(item);

    // 设置 QListWidget 的显示模式和选项
    listWidget->setViewMode(QListWidget::IconMode);
    listWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    // 设置列表项的属性和样式
    item->setIcon(QIcon("path/to/icon.png"));
    item->setTextAlignment(Qt::AlignCenter);
    item->setFlags(item->flags() | Qt::ItemIsEditable);

    QObject::connect(listWidget, &QListWidget::itemClicked, [](QListWidgetItem *item) {
        qDebug() << "Item clicked:" << item->text();
    });
}
