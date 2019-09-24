#include "Widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *watched, QEvent *event){
    if(ui->label == watched){
        if(event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseMove){
            qDebug() << QStringLiteral("在事件分发前拦截");
            return true;
        }
    }

    return false;
}
