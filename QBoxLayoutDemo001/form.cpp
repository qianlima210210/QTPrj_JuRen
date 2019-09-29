#include "form.h"
#include "ui_form.h"
#include <QPushButton>
#include <QVBoxLayout>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    QPushButton *TestBtn1 = new QPushButton();
    QPushButton *TestBtn2  = new QPushButton();
    QPushButton *TestBtn3  = new QPushButton();
    QPushButton *TestBtn4 = new QPushButton();

    //垂直布局演示
    /*
    QVBoxLayout* layout = new QVBoxLayout();

    TestBtn1->setText("TestBtn1");
    TestBtn1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//设置大小策略，宽度和高度都设置成可扩展
    TestBtn1->setMinimumSize(160,30);//设置按钮的最小尺寸

    TestBtn2->setText("TestBtn2");
    TestBtn2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn2->setMinimumSize(160,30);

    TestBtn3->setText("TestBtn3");
    TestBtn3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn3->setMinimumSize(160,30);

    TestBtn4->setText("TestBtn4");
    TestBtn4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn4->setMinimumSize(160,30);//设置最小size

    layout->setSpacing(30);//设置按钮之间的距离
    layout->addWidget(TestBtn1);//将组件添加到布局管理器
    layout->addWidget(TestBtn2);
    layout->addWidget(TestBtn3);
    layout->addWidget(TestBtn4);

    layout->setStretch(0,1);//设置索引为0的按钮大小的比例系数为1
    layout->setStretch(1,2);//设置索引为1的按钮大小的比例系数为2
    layout->setStretch(2,3);//设置索引为2的按钮大小的比例系数为3
    layout->setStretch(3,4);//设置索引为3的按钮大小的比例系数为4

    setLayout(layout);//为顶级Widget设置一个布局管理器
    */

    //嵌套布局演示
    //一个垂直布局管理器来嵌套管理两个水平布局管理器
    QHBoxLayout* Hlayout1 = new QHBoxLayout();//两个子布局管理器
    QHBoxLayout* Hlayout2 = new QHBoxLayout();
    QVBoxLayout* Vlayout = new QVBoxLayout();//顶级布局管理器

    //设置水平布局管理器
    TestBtn1->setText("TestBtn1");
    TestBtn1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//设置大小策略，宽度和高度都设置成可扩展
    TestBtn1->setMinimumSize(160,30);

    TestBtn2->setText("TestBtn2");
    TestBtn2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn2->setMinimumSize(160,30);

    Hlayout1->setSpacing(30);//设置按钮之间的距离
    Hlayout1->addWidget(TestBtn1);//添加按钮到水平布局管理器
    Hlayout1->addWidget(TestBtn2);

    //设置水平布局管理器
    TestBtn3->setText("TestBtn3");
    TestBtn3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn3->setMinimumSize(160,30);

    TestBtn4->setText("TestBtn4");
    TestBtn4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn4->setMinimumSize(160,30);//设置最小size

    Hlayout2->setSpacing(30);//设置按钮之间的距离
    Hlayout2->addWidget(TestBtn3);//添加组件
    Hlayout2->addWidget(TestBtn4);

    //布局管理器嵌套
    Vlayout->addLayout(Hlayout1);
    Vlayout->addLayout(Hlayout2);

    //bool setStretchFactor(QWidget* widget, int stretch);
    //在一系列组件中，通过组件地址（QWidget或继承自QWidegt类对象指针即可）来设置比例系数
    Hlayout1->setStretchFactor(TestBtn1, 1);//比例为1:2:3:4
    Hlayout1->setStretchFactor(TestBtn2, 2);
    Hlayout2->setStretchFactor(TestBtn3, 3);
    Hlayout2->setStretchFactor(TestBtn4, 4);

    //bool setStretchFactor(QLayout* layout, int stretch);
    //在一系列组件中，通过布局管理器地址（QLayout或继承自QLayout类对象指针即可）来设置比例系数
    Vlayout->setStretchFactor(Hlayout1, 1);//设置布局管理器比例系数
    Vlayout->setStretchFactor(Hlayout2, 3);

    setLayout(Vlayout);//将Vlayout设置成顶级布局管理器，它能管理其他的布局管理器
}

Form::~Form()
{
    delete ui;
}
