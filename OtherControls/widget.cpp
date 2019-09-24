#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QStackedWidget>
#include <QPicture>
#include <QPixmap>
#include <QComboBox>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->one, &QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->two, &QPushButton::clicked,[=](){
       //ui->stackedWidget->setCurrentIndex(1);
        ui->comboBox->setCurrentIndex(2);
    });

    ui->label->setPixmap(QPixmap("images/btn_allcourse@3x.png"));

    QStringList strList;
    strList.append(QStringLiteral("宝马"));
    strList.append(QStringLiteral("奥迪"));
    strList.append(QStringLiteral("奔驰"));
    ui->comboBox->addItems(strList);
    //void currentIndexChanged(int index);
    void (QComboBox::*fun)(int) =  &QComboBox::currentIndexChanged;
    connect(ui->comboBox,fun, [=](int index){
        qDebug() << QString::number(index);
    });


}

Widget::~Widget()
{
    delete ui;
}
