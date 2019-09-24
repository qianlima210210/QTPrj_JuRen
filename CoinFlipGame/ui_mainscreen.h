/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

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

class Ui_MainScreen
{
public:
    QAction *actionquit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menubegin;

    void setupUi(QMainWindow *MainScreen)
    {
        if (MainScreen->objectName().isEmpty())
            MainScreen->setObjectName(QStringLiteral("MainScreen"));
        MainScreen->resize(320, 588);
        MainScreen->setMinimumSize(QSize(320, 588));
        MainScreen->setMaximumSize(QSize(320, 588));
        actionquit = new QAction(MainScreen);
        actionquit->setObjectName(QStringLiteral("actionquit"));
        centralWidget = new QWidget(MainScreen);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainScreen->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainScreen);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 320, 17));
        menubegin = new QMenu(menuBar);
        menubegin->setObjectName(QStringLiteral("menubegin"));
        MainScreen->setMenuBar(menuBar);

        menuBar->addAction(menubegin->menuAction());
        menubegin->addAction(actionquit);

        retranslateUi(MainScreen);

        QMetaObject::connectSlotsByName(MainScreen);
    } // setupUi

    void retranslateUi(QMainWindow *MainScreen)
    {
        MainScreen->setWindowTitle(QApplication::translate("MainScreen", "MainScreen", Q_NULLPTR));
        actionquit->setText(QApplication::translate("MainScreen", "\351\200\200\345\207\272", Q_NULLPTR));
        menubegin->setTitle(QApplication::translate("MainScreen", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainScreen: public Ui_MainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
