#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    btn = new QPushButton(QStringLiteral("打开"), this);
    this->resize(600, 400);
    connect(btn,&QPushButton::clicked, this, &Widget::openOtherWidget);
}

Widget::~Widget()
{

}

void Widget::openOtherWidget(){
    disconnect(btn,&QPushButton::clicked, this, &Widget::openOtherWidget);
    btn->setText(QStringLiteral("关闭"));
    connect(btn,&QPushButton::clicked, this, &Widget::closeOtherWidget);

    otherWidget = new QWidget();
    otherWidget->setWindowTitle(QStringLiteral("其他窗口"));
    otherWidget->resize(300, 200);
    otherWidget->show();
}

void Widget::closeOtherWidget(){
    disconnect(btn,&QPushButton::clicked, this, &Widget::closeOtherWidget);
    btn->setText(QStringLiteral("打开"));
    connect(btn,&QPushButton::clicked, this, &Widget::openOtherWidget);

    otherWidget->close();
    delete otherWidget;
    otherWidget = NULL;
}







