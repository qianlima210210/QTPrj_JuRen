/********************************************************************************
** Form generated from reading UI file 'gridlayout.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRIDLAYOUT_H
#define UI_GRIDLAYOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GridLayout
{
public:

    void setupUi(QWidget *GridLayout)
    {
        if (GridLayout->objectName().isEmpty())
            GridLayout->setObjectName(QStringLiteral("GridLayout"));
        GridLayout->resize(400, 300);

        retranslateUi(GridLayout);

        QMetaObject::connectSlotsByName(GridLayout);
    } // setupUi

    void retranslateUi(QWidget *GridLayout)
    {
        GridLayout->setWindowTitle(QApplication::translate("GridLayout", "Gridlayout\346\274\224\347\244\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GridLayout: public Ui_GridLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRIDLAYOUT_H
