/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *delRow;
    QPushButton *addRow;
    QPushButton *updateThd;
    QListView *listView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        delRow = new QPushButton(widget);
        delRow->setObjectName(QStringLiteral("delRow"));

        horizontalLayout->addWidget(delRow);

        addRow = new QPushButton(widget);
        addRow->setObjectName(QStringLiteral("addRow"));

        horizontalLayout->addWidget(addRow);

        updateThd = new QPushButton(widget);
        updateThd->setObjectName(QStringLiteral("updateThd"));

        horizontalLayout->addWidget(updateThd);


        verticalLayout->addWidget(widget);

        listView = new QListView(Widget);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "QlistView \347\256\200\345\215\225\345\272\224\347\224\250https://blog.csdn.net/yifanmoon/article/details/80495293", Q_NULLPTR));
        delRow->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", Q_NULLPTR));
        addRow->setText(QApplication::translate("Widget", "\346\267\273\345\212\240", Q_NULLPTR));
        updateThd->setText(QApplication::translate("Widget", "\346\233\264\346\226\260\347\254\254\344\270\211\351\241\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
