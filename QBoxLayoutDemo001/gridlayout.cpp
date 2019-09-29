﻿#include "gridlayout.h"
#include "ui_gridlayout.h"
#include <QPushButton>
#include <QGridLayout>

GridLayout::GridLayout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GridLayout)
{
    ui->setupUi(this);
    QPushButton *TestBtn1 = new QPushButton();
    QPushButton *TestBtn2  = new QPushButton();
    QPushButton *TestBtn3  = new QPushButton();
    QPushButton *TestBtn4 = new QPushButton();


    QGridLayout* layout = new QGridLayout();

    TestBtn1->setText("Test Button 1");
    TestBtn1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//设置组件大小可扩展
    TestBtn1->setMinimumSize(160, 30);//设置最小尺寸

    TestBtn2->setText("Test Button 2");
    TestBtn2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn2->setMinimumSize(160, 30);

    TestBtn3->setText("Test Button 3");
    TestBtn3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn3->setMinimumSize(160, 30);

    TestBtn4->setText("Test Button 4");
    TestBtn4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn4->setMinimumSize(160, 30);

    layout->setSpacing(10);//设置间距
    layout->addWidget(TestBtn1, 0, 0);//往网格的不同坐标添加不同的组件
    layout->addWidget(TestBtn2, 0, 1);
    layout->addWidget(TestBtn3, 1, 0);
    layout->addWidget(TestBtn4, 1, 1);

//    layout->setRowStretch(0, 1);//设置行列比例系数
//    layout->setRowStretch(1, 3);
//    layout->setColumnStretch(0, 1);
//    layout->setColumnStretch(1, 3);

    setLayout(layout);//设置顶级布局管理器
}

GridLayout::~GridLayout()
{
    delete ui;
}
