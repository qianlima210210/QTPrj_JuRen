#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QModelIndex>
#include <QIcon>
#include <QListWidget>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    //QStringListModel作为QListView的数据模型
    /*
    QStringList strlist;
    strlist<<"A"<<"B"<<"C"<<"D";
    strlist<<"A"<<"B"<<"C"<<"D";
    strlist<<"A"<<"B"<<"C"<<"D";
    strlist<<"A"<<"B"<<"C"<<"D";
    stringListModel = new QStringListModel(strlist);
    ui->listView->setModel(stringListModel);
    */

    //QStandardItemModel为QListView的数据模型
    itemModel = new QStandardItemModel(this);

    QStringList strList;
    strList.append("A");
    strList.append("B");
    strList.append("C");
    strList.append("D");
    strList.append("E");
    strList.append("F");
    strList.append("G");

    int nCount = strList.size();
    for(int i = 0; i < nCount; i++)
    {
       QString string = static_cast<QString>(strList.at(i));
       //QStandardItem *item = new QStandardItem(string);
       QIcon icon(":/images/coin.png");
       QStandardItem *item = new QStandardItem(icon, string);

       itemModel->appendRow(item);
    }
    ui->listView->setModel(itemModel);
    ui->listView->setFixedSize(200,300);

    void (QListView::*clicked)(const QModelIndex&) = &QListView::clicked;
    connect(ui->listView, clicked, this, &Widget::showClick);
    //connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(showClick(QModelIndex)));


}

void Widget::showClick(QModelIndex index)
{
    QString text = QString("%1, %2").arg(index.row()).arg(index.data().toString());
    QMessageBox::information(this, "title", text, QMessageBox::Ok);
}
