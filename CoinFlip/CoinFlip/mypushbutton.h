#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QDebug>
#include <QPropertyAnimation>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:

    MyPushButton(QString normalImg , QString pressImg = "");

    QString normalImgPath;
    QString pressedImgPath;

    //弹跳
    void Zoom1();
    void Zoom2();
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *e);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
