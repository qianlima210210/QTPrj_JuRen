#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QToolButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [=](){
       qDebug() << QString::number(ui->widget->getNum());
    });

    connect(ui->toolButton, &QToolButton::clicked, [=](){
        ui->widget->setNum(90);
    });
}

Widget::~Widget()
{
    delete ui;
}
