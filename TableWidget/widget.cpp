#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);//列数

    QStringList stringList;
    stringList.append(QStringLiteral("姓名"));
    stringList.append(QStringLiteral("性别"));
    stringList.append(QStringLiteral("年龄"));

    ui->tableWidget->setHorizontalHeaderLabels(stringList);//每列字段名

    ui->tableWidget->setRowCount(3);//行数

    QStringList names, genders, ages;
    names << QStringLiteral("张三")<< QStringLiteral("李四")<< QStringLiteral("王五");
    genders << QStringLiteral("男")<< QStringLiteral("女")<< QStringLiteral("男");
    ages << QString::number(18) << QString::number(19)<< QString::number(20);

    for(int i = 0; i < 3; i++){
        int col = 0;
        QTableWidgetItem *nameitem = new QTableWidgetItem(names.at(i));
        ui->tableWidget->setItem(i, col, nameitem);

        col++;
        QTableWidgetItem *genderitem = new QTableWidgetItem(genders.at(i));
        ui->tableWidget->setItem(i, col, genderitem);

        col++;
        QTableWidgetItem *ageitem = new QTableWidgetItem(ages.at(i));
        ui->tableWidget->setItem(i, col, ageitem);
    }
}

Widget::~Widget()
{
    delete ui;
}






























