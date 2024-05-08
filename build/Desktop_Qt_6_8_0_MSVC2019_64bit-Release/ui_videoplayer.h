/********************************************************************************
** Form generated from reading UI file 'videoplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYER_H
#define UI_VIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoPlayer
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_Add;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Pause;
    QPushButton *pushButton_Player;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_Sound;
    QSlider *horizontalSlider_Volumn;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelCurrentMedia;
    QSpacerItem *horizontalSpacer;
    QSlider *horizontalSlider_Position;
    QLabel *label_Ratio;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_playlist;
    QSpacerItem *horizontalSpacer_8;
    QListWidget *listWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VideoPlayer)
    {
        if (VideoPlayer->objectName().isEmpty())
            VideoPlayer->setObjectName("VideoPlayer");
        VideoPlayer->resize(1077, 712);
        centralwidget = new QWidget(VideoPlayer);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter);

        verticalLayout->addWidget(graphicsView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        pushButton_Add = new QPushButton(centralwidget);
        pushButton_Add->setObjectName("pushButton_Add");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icon/VideoPlayer/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Add->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_Add);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_Stop = new QPushButton(centralwidget);
        pushButton_Stop->setObjectName("pushButton_Stop");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icon/VideoPlayer/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Stop->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButton_Stop);

        pushButton_Pause = new QPushButton(centralwidget);
        pushButton_Pause->setObjectName("pushButton_Pause");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icon/VideoPlayer/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Pause->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButton_Pause);

        pushButton_Player = new QPushButton(centralwidget);
        pushButton_Player->setObjectName("pushButton_Player");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icon/VideoPlayer/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Player->setIcon(icon3);

        horizontalLayout_2->addWidget(pushButton_Player);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButton_Sound = new QPushButton(centralwidget);
        pushButton_Sound->setObjectName("pushButton_Sound");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/icon/VideoPlayer/volumn.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Sound->setIcon(icon4);

        horizontalLayout_2->addWidget(pushButton_Sound);

        horizontalSlider_Volumn = new QSlider(centralwidget);
        horizontalSlider_Volumn->setObjectName("horizontalSlider_Volumn");
        horizontalSlider_Volumn->setMaximum(100);
        horizontalSlider_Volumn->setSingleStep(10);
        horizontalSlider_Volumn->setValue(60);
        horizontalSlider_Volumn->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_Volumn);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        labelCurrentMedia = new QLabel(centralwidget);
        labelCurrentMedia->setObjectName("labelCurrentMedia");

        horizontalLayout->addWidget(labelCurrentMedia);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSlider_Position = new QSlider(centralwidget);
        horizontalSlider_Position->setObjectName("horizontalSlider_Position");
        horizontalSlider_Position->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_Position);

        label_Ratio = new QLabel(centralwidget);
        label_Ratio->setObjectName("label_Ratio");

        horizontalLayout->addWidget(label_Ratio);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        pushButton_playlist = new QPushButton(centralwidget);
        pushButton_playlist->setObjectName("pushButton_playlist");

        horizontalLayout->addWidget(pushButton_playlist);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        horizontalLayout_3->addWidget(listWidget);

        horizontalLayout_3->setStretch(0, 4);
        horizontalLayout_3->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        VideoPlayer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(VideoPlayer);
        statusbar->setObjectName("statusbar");
        VideoPlayer->setStatusBar(statusbar);

        retranslateUi(VideoPlayer);

        QMetaObject::connectSlotsByName(VideoPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *VideoPlayer)
    {
        VideoPlayer->setWindowTitle(QCoreApplication::translate("VideoPlayer", "\344\270\207\350\203\275\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250---\345\260\217\351\270\241\347\211\210", nullptr));
#if QT_CONFIG(tooltip)
        graphicsView->setToolTip(QCoreApplication::translate("VideoPlayer", "<html><head/><body><p>\350\247\206\351\242\221</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        graphicsView->setWhatsThis(QCoreApplication::translate("VideoPlayer", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_Add->setText(QCoreApplication::translate("VideoPlayer", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        pushButton_Stop->setText(QCoreApplication::translate("VideoPlayer", "\345\201\234\346\255\242", nullptr));
        pushButton_Pause->setText(QCoreApplication::translate("VideoPlayer", "\346\232\202\345\201\234", nullptr));
        pushButton_Player->setText(QCoreApplication::translate("VideoPlayer", "\346\222\255\346\224\276", nullptr));
        pushButton_Sound->setText(QCoreApplication::translate("VideoPlayer", "\351\237\263\351\207\217", nullptr));
        labelCurrentMedia->setText(QCoreApplication::translate("VideoPlayer", "\346\226\207\344\273\266\345\220\215\347\247\260", nullptr));
        label_Ratio->setText(QCoreApplication::translate("VideoPlayer", "\346\222\255\346\224\276\350\277\233\345\272\246", nullptr));
        pushButton_playlist->setText(QCoreApplication::translate("VideoPlayer", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoPlayer: public Ui_VideoPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYER_H
