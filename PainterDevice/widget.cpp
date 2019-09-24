#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QImage>
#include <QPicture>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*
    //创建绘图设备
    QPixmap pix(300, 300);

    //设置背景填充颜色
    pix.fill(Qt::white);

    //穿件画家
    QPainter painter(&pix);
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(0, 0, 300, 300);

    //保存
    pix.save("C:\\pix.png");
    */

    /*
    //创建绘图设备
   QImage image(300, 300, QImage::Format_RGB32);

    //设置背景填充颜色
    image.fill(Qt::white);

    //穿件画家
    QPainter painter(&image);
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(0, 0, 300, 300);

    //保存
    image.save("C:\\image.png");
    */

    //QPicture绘图设备 可以记录和重现 绘图指令
    QPicture pic;

    QPainter painter;
    painter.begin(&pic);//开始在设备上画

    painter.setPen(Qt::cyan);
    painter.drawEllipse(QPoint(150, 150), 100, 100);

    painter.end();//结束画

    //保存
    pic.save("C:\\pic.zt");

}

void Widget::paintEvent(QPaintEvent *event){

    QPainter painter(this);

    /*
    //利用QImage对像素进行修改
    QImage image;
    image.load(":/new/prefix1/images/0.jpg");

    //修改像素点
    for(int i = 50; i < 100; i++){
        for(int j = 50; j < 100; j++){
            QRgb value = qRgb(255, 0, 0);
            image.setPixelColor(i, j, Qt::red);
        }
    }

    painter.drawImage(0, 0, image);
    */

    QPicture pic;
    pic.load("C:\\pic.zt");

    painter.drawPicture(0, 0, pic);
}

Widget::~Widget()
{
    delete ui;
}














