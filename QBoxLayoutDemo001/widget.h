﻿#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void addTopWidget();
    void addBtnIntoScrollAreaWidget(QGridLayout *pLayout);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
