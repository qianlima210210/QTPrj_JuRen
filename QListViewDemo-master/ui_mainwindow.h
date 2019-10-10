/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *allBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *redBtn;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *blueBtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *yellowBtn;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *setRedBtn;
    QSpacerItem *horizontalSpacer_2;
    QListView *listView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(763, 277);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("QWidget#centralWidget{\n"
"background-color: white;\n"
"}"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        allBtn = new QPushButton(widget);
        allBtn->setObjectName(QStringLiteral("allBtn"));
        QFont font;
        font.setPointSize(12);
        allBtn->setFont(font);
        allBtn->setStyleSheet(QLatin1String("QPushButton#allBtn{\n"
"background:white;\n"
"border:1px solid gray;\n"
"border-radius:5px;\n"
"padding:2px 4px;\n"
"color:gray;\n"
"}\n"
"\n"
"QPushButton#allBtn:checked{\n"
"background:gray;\n"
"color:white;\n"
"}"));
        allBtn->setCheckable(true);
        allBtn->setChecked(true);

        horizontalLayout->addWidget(allBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        redBtn = new QPushButton(widget);
        redBtn->setObjectName(QStringLiteral("redBtn"));
        redBtn->setFont(font);
        redBtn->setStyleSheet(QLatin1String("QPushButton#redBtn{\n"
"background:white;\n"
"border:1px solid rgb(255, 84, 92);\n"
"border-radius:5px;\n"
"padding:2px 4px;\n"
"color:rgb(255, 84, 92);\n"
"}\n"
"\n"
"QPushButton#redBtn:checked{\n"
"background:rgb(255, 84, 92);\n"
"color:white;\n"
"}"));
        redBtn->setCheckable(true);
        redBtn->setChecked(false);

        horizontalLayout->addWidget(redBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        blueBtn = new QPushButton(widget);
        blueBtn->setObjectName(QStringLiteral("blueBtn"));
        blueBtn->setFont(font);
        blueBtn->setStyleSheet(QLatin1String("QPushButton#blueBtn{\n"
"background:white;\n"
"border:1px solid #3288E8;\n"
"border-radius:5px;\n"
"padding:2px 4px;\n"
"color:#3288E8;\n"
"}\n"
"\n"
"QPushButton#blueBtn:checked{\n"
"background:#3288E8;\n"
"color:white;\n"
"}"));
        blueBtn->setCheckable(true);

        horizontalLayout->addWidget(blueBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        yellowBtn = new QPushButton(widget);
        yellowBtn->setObjectName(QStringLiteral("yellowBtn"));
        yellowBtn->setFont(font);
        yellowBtn->setStyleSheet(QLatin1String("QPushButton#yellowBtn{\n"
"background:white;\n"
"border:1px solid rgb(255, 226, 6);\n"
"border-radius:5px;\n"
"padding:2px 4px;\n"
"color:rgb(255, 226, 6);\n"
"}\n"
"\n"
"QPushButton#yellowBtn:checked{\n"
"background:rgb(255, 226, 6);\n"
"color:white;\n"
"}"));
        yellowBtn->setCheckable(true);

        horizontalLayout->addWidget(yellowBtn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        setRedBtn = new QPushButton(widget);
        setRedBtn->setObjectName(QStringLiteral("setRedBtn"));
        setRedBtn->setStyleSheet(QLatin1String("QPushButton#setRedBtn{\n"
"border:1px solid rgb(255, 84, 92);\n"
"border-radius:5px;\n"
"padding:2px 4px;\n"
"background:rgb(255, 84, 92);\n"
"color:white;\n"
"}"));

        horizontalLayout->addWidget(setRedBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("QListView {\n"
"   background-color: transparent;\n"
"	border:1px solid #EFEFEF;\n"
"}\n"
"\n"
""));
        listView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout->addWidget(listView);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        allBtn->setText(QApplication::translate("MainWindow", "all", Q_NULLPTR));
        redBtn->setText(QApplication::translate("MainWindow", "red", Q_NULLPTR));
        blueBtn->setText(QApplication::translate("MainWindow", "blue", Q_NULLPTR));
        yellowBtn->setText(QApplication::translate("MainWindow", "yellow", Q_NULLPTR));
        setRedBtn->setText(QApplication::translate("MainWindow", "set red", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
