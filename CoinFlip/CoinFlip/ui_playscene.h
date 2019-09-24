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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayScene
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *PlayScene)
    {
        if (PlayScene->objectName().isEmpty())
            PlayScene->setObjectName(QStringLiteral("PlayScene"));
        PlayScene->resize(800, 600);
        actionQuit = new QAction(PlayScene);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralwidget = new QWidget(PlayScene);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        PlayScene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlayScene);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        PlayScene->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionQuit);

        retranslateUi(PlayScene);

        QMetaObject::connectSlotsByName(PlayScene);
    } // setupUi

    void retranslateUi(QMainWindow *PlayScene)
    {
        PlayScene->setWindowTitle(QApplication::translate("PlayScene", "MainWindow", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("PlayScene", "\351\200\200\345\207\272", Q_NULLPTR));
        menu->setTitle(QApplication::translate("PlayScene", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlayScene: public Ui_PlayScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYSCENE_H
