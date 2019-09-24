/********************************************************************************
** Form generated from reading UI file 'playscene.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYSCENE_H
#define UI_PLAYSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayScene
{
public:
    QAction *actionquit;
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *middleWidget;
    QLabel *label;
    QWidget *widget_2;
    QMenuBar *menubar;
    QMenu *menustart;

    void setupUi(QMainWindow *PlayScene)
    {
        if (PlayScene->objectName().isEmpty())
            PlayScene->setObjectName(QStringLiteral("PlayScene"));
        PlayScene->resize(320, 588);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PlayScene->sizePolicy().hasHeightForWidth());
        PlayScene->setSizePolicy(sizePolicy);
        PlayScene->setMinimumSize(QSize(320, 588));
        PlayScene->setMaximumSize(QSize(320, 588));
        actionquit = new QAction(PlayScene);
        actionquit->setObjectName(QStringLiteral("actionquit"));
        centralwidget = new QWidget(PlayScene);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 320, 60));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(320, 60));
        widget->setMaximumSize(QSize(320, 60));
        middleWidget = new QWidget(centralwidget);
        middleWidget->setObjectName(QStringLiteral("middleWidget"));
        middleWidget->setGeometry(QRect(0, 60, 320, 441));
        sizePolicy.setHeightForWidth(middleWidget->sizePolicy().hasHeightForWidth());
        middleWidget->setSizePolicy(sizePolicy);
        middleWidget->setMinimumSize(QSize(320, 441));
        middleWidget->setMaximumSize(QSize(320, 441));
        label = new QLabel(middleWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 350, 41, 9));
        label->setStyleSheet(QLatin1String("background-color: rgba(213, 213, 213, 125);\n"
"border-color: rgb(255, 0, 0);"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 501, 320, 70));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(320, 70));
        widget_2->setMaximumSize(QSize(320, 70));
        PlayScene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlayScene);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 17));
        menustart = new QMenu(menubar);
        menustart->setObjectName(QStringLiteral("menustart"));
        PlayScene->setMenuBar(menubar);

        menubar->addAction(menustart->menuAction());
        menustart->addAction(actionquit);

        retranslateUi(PlayScene);

        QMetaObject::connectSlotsByName(PlayScene);
    } // setupUi

    void retranslateUi(QMainWindow *PlayScene)
    {
        PlayScene->setWindowTitle(QApplication::translate("PlayScene", "MainWindow", Q_NULLPTR));
        actionquit->setText(QApplication::translate("PlayScene", "\351\200\200\345\207\272", Q_NULLPTR));
        label->setText(QApplication::translate("PlayScene", "TextLabel", Q_NULLPTR));
        menustart->setTitle(QApplication::translate("PlayScene", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlayScene: public Ui_PlayScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYSCENE_H
