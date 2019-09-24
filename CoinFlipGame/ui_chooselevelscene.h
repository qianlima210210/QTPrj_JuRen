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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseLevelScene
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QWidget *btnWidgetContainer;
    QWidget *widget_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *ChooseLevelScene)
    {
        if (ChooseLevelScene->objectName().isEmpty())
            ChooseLevelScene->setObjectName(QStringLiteral("ChooseLevelScene"));
        ChooseLevelScene->resize(320, 588);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChooseLevelScene->sizePolicy().hasHeightForWidth());
        ChooseLevelScene->setSizePolicy(sizePolicy);
        ChooseLevelScene->setMinimumSize(QSize(320, 588));
        ChooseLevelScene->setMaximumSize(QSize(320, 588));
        centralwidget = new QWidget(ChooseLevelScene);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(320, 60));
        widget->setMaximumSize(QSize(320, 60));
        widget->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(widget);

        btnWidgetContainer = new QWidget(centralwidget);
        btnWidgetContainer->setObjectName(QStringLiteral("btnWidgetContainer"));
        sizePolicy.setHeightForWidth(btnWidgetContainer->sizePolicy().hasHeightForWidth());
        btnWidgetContainer->setSizePolicy(sizePolicy);
        btnWidgetContainer->setMinimumSize(QSize(320, 441));
        btnWidgetContainer->setMaximumSize(QSize(320, 441));
        btnWidgetContainer->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(btnWidgetContainer);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(320, 70));
        widget_2->setMaximumSize(QSize(320, 70));

        verticalLayout->addWidget(widget_2);

        ChooseLevelScene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChooseLevelScene);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 17));
        ChooseLevelScene->setMenuBar(menubar);

        retranslateUi(ChooseLevelScene);

        QMetaObject::connectSlotsByName(ChooseLevelScene);
    } // setupUi

    void retranslateUi(QMainWindow *ChooseLevelScene)
    {
        ChooseLevelScene->setWindowTitle(QApplication::translate("ChooseLevelScene", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChooseLevelScene: public Ui_ChooseLevelScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELEVELSCENE_H
