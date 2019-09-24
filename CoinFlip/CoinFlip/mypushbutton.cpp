#include "mypushbutton.h"

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
   normalImgPath = normalImg;
   pressedImgPath = pressImg;

   //加载图片
   QPixmap pix;
   bool ret = pix.load(normalImgPath);
   if(!ret)
   {
       QString str = QStringLiteral("%1 图片加载失败").arg(normalImgPath);
       qDebug()<<str;
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

}

void MyPushButton::Zoom1()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置持续时间
    animation->setDuration(2000);
    //设置动画对象起始位置
    animation->setStartValue(QVariant(QRect(this->x(),this->y(),this->width(),this->height())));
    //设置结束位置
    animation->setEndValue(QVariant(QRect(this->x(),this->y()+10,this->width(),this->height())));

    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

void MyPushButton::Zoom2()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置持续时间
    animation->setDuration(200);

    //设置动画对象起始位置
    animation->setStartValue(QVariant(QRect(this->x(),this->y()+10,this->width(),this->height())));
    //设置结束位置
    animation->setEndValue(QVariant(QRect(this->x(),this->y(),this->width(),this->height())));
    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(!pressedImgPath.isEmpty())
    {
        //传入选中后的图片路径不为空 选中后需要进行图片切换
        QPixmap pix;
        if(!pix.load(pressedImgPath))
        {
            qDebug()<<"图片加载失败";
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
    }
    //其他事情交给父类处理
    QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{

    if(!pressedImgPath.isEmpty())
    {
        //传入选中后的图片路径不为空 选中后需要进行图片切换
        QPixmap pix;
        if(!pix.load(normalImgPath))
        {
            qDebug()<<"图片加载失败";
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
    }
    //其他事情交给父类处理
    QPushButton::mouseReleaseEvent(e);


}
