#include "Widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timerId0 = startTimer(1000);//单位是毫秒
    timerId1 = startTimer(2000);//单位是毫秒
}

Widget::~Widget()
{
    delete ui;
    killTimer(timerId0);
    killTimer(timerId1);
}

void Widget::timerEvent(QTimerEvent *event){
    static int num = 1;

    if(event->timerId() == timerId0){
        ui->label->setText(QString::number(num++));
    }else if(event->timerId() == timerId1){
        ui->label_2->setText(QString::number(num++));
    }
}
