#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
   MyCoin(QString CoinImg);
   void changeFlag(); //改变标志，执行翻转效果

   int Posx;
   int Posy;
   bool flag;

   QTimer * timer1;//金币翻银币 定时器
   QTimer * timer2;//银币翻金币 定时器
   int min = 1;
   int max = 8;

   bool isAnimation; //是否在执行动画
   bool isWin; //是否胜利 ->胜利后禁用按钮


   void mousePressEvent(QMouseEvent *e);





signals:

public slots:
};

#endif // MYCOIN_H
