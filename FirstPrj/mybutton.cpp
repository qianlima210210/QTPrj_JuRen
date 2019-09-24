#include "mybutton.h"
#include <QDebug>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << QStringLiteral("MyButton构造函数");
}


MyButton::~MyButton(){
    qDebug() << QStringLiteral( "MyButton析构函数");
}
