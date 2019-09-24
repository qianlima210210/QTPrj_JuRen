#include "iosbutton.h"
#include <QPixmap>
#include <QIcon>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QDebug>

IosButton::IosButton(QWidget *parent) : QPushButton(parent)
{

}

IosButton::IosButton(QWidget *parent, QString normalImagePath, QString pressedImagePath) : QPushButton(parent)
{
    this->normalImagePath = normalImagePath;
    this->pressedImagePath = pressedImagePath;

    this->setBtnIcon(true);
}

void IosButton::setBtnIcon(bool normal){

    QString fileName = normal ? this->normalImagePath : this->pressedImagePath;

    QPixmap pixmap;
    if(pixmap.load(fileName) == false){
        qDebug() << QStringLiteral("路径无效");
        return;
    }

    //将按钮设置为图片大小
    this->setFixedSize(pixmap.width(), pixmap.height());

    //将按钮设置为“不规则样式”
    this->setStyleSheet("QPushButton{border:0px;}");

    //为按钮设置图标
    this->setIcon(QIcon(pixmap));

    //设置图标大小
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));
}

IosButton::~IosButton(){

}

void IosButton::animationDown()   //下落动画
{
    //创建动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画持续时间
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QVariant(QRect(this->x(), this->y(), this->width(), this->height())));
    //结束位置
    animation->setEndValue(QVariant(QRect(this->x(), this->y() + 10, this->width(), this->height())));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //启动动画
    animation->start();
}

void IosButton::animationUp()     //上抛动画
{
    //创建动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画持续时间
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QVariant(QRect(this->x(), this->y() + 10, this->width(), this->height())));
    //结束位置
    animation->setEndValue(QVariant(QRect(this->x(), this->y(), this->width(), this->height())));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //启动动画
    animation->start();
}

void IosButton::mousePressEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        if(this->pressedImagePath != ""){//不为空，说明需要在按下时设置图标
            this->setBtnIcon(false);
        }
    }

    QPushButton::mousePressEvent(e);
}

void IosButton::mouseReleaseEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        if(this->pressedImagePath != ""){//不为空，说明需要在释放时设置图标
            this->setBtnIcon(true);
        }
    }

    QPushButton::mouseReleaseEvent(e);
}


















































