#include "SmallWidget.h"
#include "ui_SmallWidget.h"
#include <QSpinBox>
#include <QSlider>
#include <QDebug>

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);
    void (QSpinBox:: *valueChanged)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, valueChanged, ui->horizontalSlider, &QSlider::setValue);

    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
    connect(ui->horizontalSlider, &QSlider::valueChanged, [=](int value){
       qDebug() <<  QString::number(value);
    });


}

SmallWidget::~SmallWidget()
{
    delete ui;
}

int SmallWidget::getNum(){
    return ui->spinBox->value();
}

void SmallWidget::setNum(int num){
    ui->spinBox->setValue(num);
}









