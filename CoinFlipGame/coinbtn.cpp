#include "coinbtn.h"
#include <QPixmap>
#include <QDebug>

CoinBtn::CoinBtn(QWidget *parent):QPushButton(parent)
{

}

 CoinBtn::CoinBtn(QWidget *parent, QString btnPath):QPushButton(parent)
 {
    QPixmap pixmap;
    if(pixmap.load(btnPath) == false)
    {
        QString msg = QStringLiteral("%1无效").arg(btnPath);
        qDebug() << msg;
        return;
    }

    setFixedSize(pixmap.width(), pixmap.height());
    //将按钮设置为“不规则样式”
    setStyleSheet("QPushButton{border:0px;}");
    setIcon(pixmap);
    setIconSize(QSize(pixmap.width(), pixmap.height()));

    timer0 = new QTimer(this);
    connect(timer0, &QTimer::timeout, this, [=](){
        QString picPath = QString(":/images/coin0%1.png").arg(min++);

        QPixmap pixmap;
        if(pixmap.load(picPath) == false)
        {
            QString msg = QStringLiteral("%1无效").arg(picPath);
            qDebug() << msg;
            return;
        }

        setFixedSize(pixmap.width(), pixmap.height());
        //将按钮设置为“不规则样式”
        setStyleSheet("QPushButton{border:0px;}");
        setIcon(pixmap);
        setIconSize(QSize(pixmap.width(), pixmap.height()));

        if(min > max){
            min = 1;
            timer0->stop();
            isAnimation = false;
        }

    });

    timer1 = new QTimer(this);
    connect(timer1, &QTimer::timeout, this, [=](){

        QString picPath = QString(":/images/coin0%1.png").arg(max--);

        QPixmap pixmap;
        if(pixmap.load(picPath) == false)
        {
            QString msg = QStringLiteral("%1无效").arg(picPath);
            qDebug() << msg;
            return;
        }

        setFixedSize(pixmap.width(), pixmap.height());
        //将按钮设置为“不规则样式”
        setStyleSheet("QPushButton{border:0px;}");
        setIcon(pixmap);
        setIconSize(QSize(pixmap.width(), pixmap.height()));

        if(max < min){
            max = 8;
            timer1->stop();
            isAnimation = false;
        }

    });
 }

CoinBtn::~CoinBtn()
{

}

void CoinBtn::changeFlag()
{
    if(isAnimation)
    {
        return;
    }

    isAnimation = true;
    if(flag){
        timer0->start(20);
        flag = false;
    }else{
        timer1->start(20);
        flag = true;
    }
}














































