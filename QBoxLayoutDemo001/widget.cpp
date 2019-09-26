#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include "mywidget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    //添加垂直布局
//    QVBoxLayout *layout = new QVBoxLayout();
//    layout->setContentsMargins(10, 10, 10, 10);
//    setLayout(layout);

//    addTopWidget();
}

void Widget::addTopWidget()
{
    //创建顶部窗口
    MyWidget *widget = new MyWidget();
    widget->setFixedHeight(100);
    widget->setStyleSheet("background-color: rgb(255,0, 0)");

    //获取当前布局
    QVBoxLayout *layout = (QVBoxLayout*)this->layout();
    //创建并添加widget top上面的弹簧
    QSpacerItem *item = new QSpacerItem(0, 0, QSizePolicy::Preferred, QSizePolicy::Fixed);
    layout->addSpacerItem(item);

    //将widget添加到布局
    layout->addWidget(widget);

     //创建并添加widget bottom上面的弹簧
    item = new QSpacerItem(0, 0, QSizePolicy::Preferred, QSizePolicy::Expanding);
    layout->addSpacerItem(item);

}

Widget::~Widget()
{
    delete ui;
}
