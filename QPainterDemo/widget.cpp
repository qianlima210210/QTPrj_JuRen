#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->move, &QPushButton::clicked, [=](){
          offsetX += 20;
          update();//手动触发paintEvent
    });


}

Widget::~Widget()
{
    delete ui;
}

 void Widget::paintEvent(QPaintEvent *event){
     //QPainter *painter = new QPainter(this);//参数表示谁是画布

     /*
      * //一般使用
     QPen pen = QPen(QColor(255, 0, 0));
     pen.setWidth(3);
     pen.setStyle(Qt::DotLine);
     painter->setPen(pen);

     QBrush brush = QBrush(Qt::cyan);
     brush.setStyle(Qt::CrossPattern);
     painter->setBrush(brush);

     painter->drawLine(0, 0, this->width(), this->height());

     painter->drawEllipse(QPoint(this->width() / 2, this->height() / 2), 100, 100);

     painter->drawRect(50, 50, 100, 100);

     painter->drawText(QRectF(20, 100, 50, 60), QStringLiteral("参数表示谁是画布"));
    */

     //高级使用
     /*
     painter->drawEllipse(100, 50, 50, 50);
     painter->setRenderHint(QPainter::HighQualityAntialiasing);
     painter->drawEllipse(150, 50, 50, 50);
     */

     /*
     painter->drawEllipse(100, 50, 50, 50);

     painter->translate(100, 0);
     painter->save();
     painter->drawEllipse(110, 50, 50, 50);

     painter->translate(100, 0);
     painter->restore();
     painter->drawEllipse(120, 50, 50, 50);
     */

     if(offsetX > this->width()){
         offsetX = 0;
     }
     QPainter painer(this);
     painer.drawPixmap(offsetX, 0, 100, 100, QPixmap(QString(":/images/0.jpg")));


 }










