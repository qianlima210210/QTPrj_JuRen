#include "stackedlayout.h"
#include "ui_stackedlayout.h"
#include <QPushButton>
#include <QStackedLayout>

StackedLayout::StackedLayout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StackedLayout)
{
    ui->setupUi(this);


    QPushButton *TestBtn1 = new QPushButton("One");
    QPushButton *TestBtn2 = new QPushButton("Two");
    QPushButton *TestBtn3 = new QPushButton("Three");
    QPushButton *TestBtn4 = new QPushButton("Four");

    /*
    QStackedLayout* stacklayout  = new QStackedLayout();

    TestBtn1->setText("TestBtn1");
    TestBtn2->setText("TestBtn2");
    TestBtn3->setText("TestBtn3");
    TestBtn4->setText("TestBtn4");

    stacklayout->addWidget(TestBtn1);//0
    stacklayout->addWidget(TestBtn2);//1
    stacklayout->addWidget(TestBtn3);//2
    stacklayout->addWidget(TestBtn4);//3

    stacklayout->setCurrentIndex(2);//设置要显示的组件编号

    this->setLayout(stacklayout);
    */

    QStackedLayout* stacklayout  = new QStackedLayout();
    QVBoxLayout* vlayout = new QVBoxLayout(); //创建一个垂直布局管理器
    QWidget* widget = new QWidget();//创建一个widget对象,要想进行嵌套使用需要添加一个中间件，widget就是这个中间件

    //将按钮2、3的父组件设置成widget这个中间组件，最后将中间组件设置到栈式布局管理器
    vlayout->addWidget(TestBtn2);//添加组件到布局管理器
    vlayout->addWidget(TestBtn3);
    widget->setLayout(vlayout);//设置widget的布局管理器

    stacklayout->addWidget(TestBtn1);//0
    stacklayout->addWidget(widget);//1  //添加中间组件到栈式布局管理器
    stacklayout->addWidget(TestBtn4);//2

    stacklayout->setCurrentIndex(1);//设置初始显示组件
    setLayout(stacklayout);//设置顶层组件
}

StackedLayout::~StackedLayout()
{
    delete ui;
}
