/********************************************************************************
** Form generated from reading UI file 'formlayout.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMLAYOUT_H
#define UI_FORMLAYOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormLayout
{
public:

    void setupUi(QWidget *FormLayout)
    {
        if (FormLayout->objectName().isEmpty())
            FormLayout->setObjectName(QStringLiteral("FormLayout"));
        FormLayout->resize(400, 300);

        retranslateUi(FormLayout);

        QMetaObject::connectSlotsByName(FormLayout);
    } // setupUi

    void retranslateUi(QWidget *FormLayout)
    {
        FormLayout->setWindowTitle(QApplication::translate("FormLayout", "Formlayout\346\274\224\347\244\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormLayout: public Ui_FormLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMLAYOUT_H
