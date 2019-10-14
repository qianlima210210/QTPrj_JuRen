#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QVariant>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //listDemo001();
    mapDemo001();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::listDemo001()
{
    QList<int> list;
    list<<1<<2<<3<<4<<5;

    QList<int>::iterator i;//QList<int>::iterator是int*,即列表首指针。
    for(i=list.begin();i!=list.end();++i)
    {
        qDebug()<<(*i);
        *i=(*i)+10;
    }

    qDebug()<<"-----------------------------------";
    for(i=list.begin();i!=list.end();++i)
    {
        qDebug()<<(*i);
    }
}

void Widget::mapDemo001()
{
    /*
    QMap<QString, QString> map;
    map.insert("beijing","111");
    map.insert("shanghai","021");
    map.insert("jinan","0531");

    QMap<QString,QString>::iterator i;
    for(i=map.begin();i!=map.end();++i)
    {
        qDebug()<<i.key()<<" "<<i.value();
    }

    i=map.find("beijing");
    qDebug()<<i.key()<<" "<<i.value();

    if(i!=map.end())
        i.value()="010";
    */

    QMap<QString, QVariant> map;
    map.insert("key0", QVariant(99));

   bool ok;
   int value0 = map.value("key0").toInt(&ok);
   if(ok)//转换成功
   {
       qDebug() << value0;
   }

   map.insert("key1", QVariant(QStringLiteral("您好")));
   QString value1 = map.value("key1").toString();
   qDebug() << value1;


}



















