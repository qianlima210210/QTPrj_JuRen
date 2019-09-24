#include "widget.h"
#include "ui_widget.h"
#include <QGroupBox>
#include <QRadioButton>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("border:none");
    connect(ui->radioButton1, &QRadioButton::clicked, [=](bool checked){
        qDebug() << checked;
    });
}

Widget::~Widget()
{
    delete ui;
}
