#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{
    setMouseTracking(true);
}

MyLabel::~MyLabel(){

}

bool MyLabel::event(QEvent *e){
    if(e->type() == QEvent::MouseButtonPress || e->type() == QEvent::MouseMove){
        qDebug() << QStringLiteral("在事件分发内拦截");
        return true;
    }

    return QLabel::event(e);
}

void MyLabel::enterEvent(QEvent *event){
    //qDebug() << QStringLiteral("鼠标进入了");
}

void MyLabel::leaveEvent(QEvent *event){
    //qDebug() << QStringLiteral("鼠标离开了");
}

void MyLabel::mousePressEvent(QMouseEvent *ev){
    if(ev->button() == Qt::LeftButton){
        QString str = QString("%1, %2, %3, %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev){
    if(ev->button() == Qt::LeftButton){
        qDebug() << QStringLiteral("mouseReleaseEvent");
    }
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev){
    //if(ev->buttons() & Qt::LeftButton){
        qDebug() << QStringLiteral("mouseMoveEvent");
    //}

}
