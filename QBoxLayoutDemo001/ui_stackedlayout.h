/********************************************************************************
** Form generated from reading UI file 'stackedlayout.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STACKEDLAYOUT_H
#define UI_STACKEDLAYOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StackedLayout
{
public:

    void setupUi(QWidget *StackedLayout)
    {
        if (StackedLayout->objectName().isEmpty())
            StackedLayout->setObjectName(QStringLiteral("StackedLayout"));
        StackedLayout->resize(400, 300);

        retranslateUi(StackedLayout);

        QMetaObject::connectSlotsByName(StackedLayout);
    } // setupUi

    void retranslateUi(QWidget *StackedLayout)
    {
        StackedLayout->setWindowTitle(QApplication::translate("StackedLayout", "StackedLayout\346\274\224\347\244\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StackedLayout: public Ui_StackedLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STACKEDLAYOUT_H
