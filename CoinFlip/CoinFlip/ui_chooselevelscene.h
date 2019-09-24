/********************************************************************************
** Form generated from reading UI file 'chooselevelscene.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSELEVELSCENE_H
#define UI_CHOOSELEVELSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseLevelScene
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;

    void setupUi(QMainWindow *ChooseLevelScene)
    {
        if (ChooseLevelScene->objectName().isEmpty())
            ChooseLevelScene->setObjectName(QStringLiteral("ChooseLevelScene"));
        ChooseLevelScene->resize(800, 600);
        actionQuit = new QAction(ChooseLevelScene);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralwidget = new QWidget(ChooseLevelScene);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ChooseLevelScene->setCentralWidget(centralwidget);

        retranslateUi(ChooseLevelScene);

        QMetaObject::connectSlotsByName(ChooseLevelScene);
    } // setupUi

    void retranslateUi(QMainWindow *ChooseLevelScene)
    {
        ChooseLevelScene->setWindowTitle(QApplication::translate("ChooseLevelScene", "MainWindow", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("ChooseLevelScene", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChooseLevelScene: public Ui_ChooseLevelScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELEVELSCENE_H
