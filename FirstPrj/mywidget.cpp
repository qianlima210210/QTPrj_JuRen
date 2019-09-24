#include "mywidget.h"
#include <QPushButton>
#include "mybutton.h"
#include <QDebug>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *button = new QPushButton(QStringLiteral("第一个按钮"), this);
    //button->show();//show以顶层方式弹出窗口控件

//    button->setParent(this);
//    button->setText(QStringLiteral("按钮"));
    button->move(100, 100);


    resize(800, 400);
    setFixedSize(600, 400);

    setWindowTitle(QStringLiteral("我的窗口"));

    MyButton *btn = new MyButton(this);
    btn->move(200, 0);
    btn->resize(300, 100);
    btn->setText(QStringLiteral("自定义按钮"));

    //信号发送者；信号对应的成员函数；信号接收者（槽）；槽的成员函数
    connect(btn, &QPushButton::clicked, this, &QWidget::close);
}

MyWidget::~MyWidget()
{
    qDebug() << QStringLiteral("MyWidget析构函数");
}
