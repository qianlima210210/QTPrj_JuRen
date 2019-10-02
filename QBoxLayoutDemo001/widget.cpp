#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QPushButton>
#include "mywidget.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include <QDesktopWidget>

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

    QGridLayout *pLayout = new QGridLayout();//网格布局
    pLayout->setContentsMargins(0, 0, 0, 0);
    pLayout->setSpacing(0);

    addBtnIntoScrollAreaWidget(pLayout);
    connect(ui->addBtn, &QPushButton::clicked, this, [=]{

        QPushButton *pBtn = new QPushButton();
        pBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);//设置大小策略，宽度和高度都设置成可扩展
        pBtn->setStyleSheet("background-color: rgb(255,0, 0)");

        pBtn->setText(QStringLiteral("按钮%1").arg(pLayout->count()));
        pBtn->setMinimumSize(QSize(60,60));   //width height
        pLayout->addWidget(pBtn);//把按钮添加到布局控件中

        //setGeometry手动修改内部容器的大小
        ui->scrollArea->widget()->setGeometry(0, 0, ui->scrollArea->widget()->width(), 60 * pLayout->count());

        //调整scrollArea的高度
        qDebug() << QApplication::desktop()->height() - style()->pixelMetric(QStyle::PM_TitleBarHeight);

        if(1041 - ui->addBtn->height() > (60 * pLayout->count() + 5) )
        {
            ui->scrollArea->setFixedHeight(60 * pLayout->count() + 5);
        }

    });
}

/*
技巧：
通过上述操作，我们知道了，我们可以通过设置内部小QWidget的宽、高最小值，来让外部QScrollArea适时的出现滚动条，那么到底把小QWidget的宽、高最小值设置为多少合适呢？
答案是显然的：把小QWidget的宽、高最小值设置为刚好能容纳内部的按钮等控件，这样看起来最舒服。难道我要先计算或者观察一下按钮等控件占用的面积之后，
才能去设置小QWidget的宽、高最小值吗？
这样做太费劲了，我们肯定不会去这样做，除非是用ui设计师拖控件时，所见即所得，才无需计算小QWidget的宽、高最小值。用代码写界面时，最好的做法是：
1、向小QWidget中添加按钮等控件时，随着添加的按钮增多，小QWidget自动变大，显然用QGridLayout来做就能实现这个自动增大这个需求。自动增大也只是出现创建内部容器阶段，
一旦内部容器和布局、布局内的控件都创建和添加完毕，后续即使再向布局中添加控件，内部容器也不会自动增大了，这时只有靠setGeometry手动修改内部容器的大小了。
2、添加完控件后，手动调用一下adjustSize函数，该函数会根据所有子控件的大小之和，来调整父控件的大小。
步骤如下：先在ui中拖入一个QScrollArea控件，名字为scrollArea，然后添加代码：
*/
void Widget::addBtnIntoScrollAreaWidget(QGridLayout *pLayout)
{

    for(int i = 0; i < 3; i++)
    {
        QPushButton *pBtn = new QPushButton();
        pBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);//设置大小策略，宽度和高度都设置成可扩展

        pBtn->setStyleSheet("background-color: rgb(255,0, 0)");
        pBtn->setText(QStringLiteral("按钮%1").arg(i));
        pBtn->setMinimumSize(QSize(60,60));   //width height
        pLayout->addWidget(pBtn);//把按钮添加到布局控件中
    }

    ui->scrollArea->widget()->setLayout(pLayout);//把布局放置到QScrollArea的内部QWidget
}

void Widget::addTopWidget()
{
    //创建顶部窗口
    QWidget *widget = new QWidget();
    widget->setFixedHeight(100);
    widget->setStyleSheet("background-color: rgb(255,0, 0)");

    //获取当前布局
    QVBoxLayout *layout = (QVBoxLayout*)this->layout();
    //创建并添加widget top上面的弹簧
    QSpacerItem *item = new QSpacerItem(0, 0, QSizePolicy::Preferred, QSizePolicy::Fixed);
    layout->addSpacerItem(item);

    //将widget添加到布局
    QObject *parent = widget->parent();
    layout->addWidget(widget);
    parent = widget->parent();

     //创建并添加widget bottom上面的弹簧
    item = new QSpacerItem(0, 0, QSizePolicy::Preferred, QSizePolicy::Expanding);
    layout->addSpacerItem(item);

}

Widget::~Widget()
{
    delete ui;
}
