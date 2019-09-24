#include "Widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QPushButton>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    timer->start(1000);

    connect(timer, &QTimer::timeout, [=](){
        static int num = 1;
        ui->label->setText(QString::number(num++));
    });

    connect(ui->stop, &QPushButton::clicked, [=](){
        timer->stop();
    });

    connect(ui->goOn, &QPushButton::clicked, [=](){
        timer->start();
    });

}

Widget::~Widget()
{
    delete ui;
}
