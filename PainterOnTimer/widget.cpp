#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    timer->start(100);

    connect(timer, &QTimer::timeout, [=](){
        offsetX += 20;
        if(offsetX > this->width()){
            offsetX = 0;
        }

        update();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(offsetX, 0, 200, 200, QPixmap(":/images/1.jpg"));
}


















