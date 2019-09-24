#include "mycoin.h"
#include <QMessageBox>



MyCoin::MyCoin(QString CoinImg)
{
    QPixmap pix;
    bool ret = pix.load(CoinImg);
    if(!ret)
    {
        QString str = QStringLiteral("图片加载失败 %1").arg(CoinImg);
        QMessageBox::critical(this,"加载失败",str);
        return;
    }
    //设置图片大小
    setFixedSize(pix.width(),pix.height());

    //设置不规则图片样式
    setStyleSheet("QPushButton{border:0px}");

    //设置图片
    setIcon(QIcon(pix));

    //设置大小
    setIconSize(QSize(pix.width(),pix.height()));

    //初始化在是否执行动画
    isAnimation = false;

    //初始化游戏胜利标志
    isWin = false;

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    //监听金币翻银币信号
    connect(timer1,&QTimer::timeout,[=](){
        QString str = QString(":/images/images/coin0%1").arg(min++);
        QPixmap pix;
        pix.load(str);

        setFixedSize(pix.width(),pix.height());
        setStyleSheet("QPushButton{border:0px}");
        setIcon(QIcon(pix));
        setIconSize(QSize(pix.width(),pix.height()));

        if(min>max)
        {
            min = 1;
            timer1->stop();

        }
    });

    //监听银币翻金币信号
    connect(timer2,&QTimer::timeout,[=](){
        QString str = QString(":/images/images/coin0%1").arg(max--);
        QPixmap pix;
        pix.load(str);

        setFixedSize(pix.width(),pix.height());
        setStyleSheet("QPushButton{border:0px}");
        setIcon(QIcon(pix));
        setIconSize(QSize(pix.width(),pix.height()));

        if(max<min)
        {
            max = 8 ;
            timer2->stop();

        }
    });


}

void MyCoin::changeFlag()
{
    if(this->flag)
    {
        //当前为金币 开始金币翻银币定时器

        this->flag=false;
        timer1->start(30);
    }
    else
    {
        //当前为银币 开始银币翻金币定时器

        this->flag=true;
        timer2->start(30);
    }

}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation == true || isWin == true )
    {
        //正在做动画 不做响应
        return;
    }
    else
        QPushButton::mousePressEvent(e);
}
