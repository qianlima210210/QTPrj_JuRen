#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QModelIndex>
#include <QIcon>
#include <QDebug>
#include <QPushButton>
#include <QListWidget>
#include <QInputDialog>

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

     //1、循环添加数据
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

    //设置滚动方式：ScrollPerPixel视图将一次滚动一个像素的内容；ScrollPerItem:视图将一次滚动一项内容
    ui->listView->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);

    //指定默认选中的行号
    QModelIndex currentIndex=itemModel->index(3,0);//默认选中索引
    ui->listView->setCurrentIndex(currentIndex);

    //添加行
    void (QListView::*clicked)(const QModelIndex&) = &QListView::clicked;
    connect(ui->listView, clicked, this, &Widget::showClick);
    //connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(showClick(QModelIndex)));
    connect(ui->addRow, &QPushButton::clicked, this, [=](){

        QStandardItem *item = new QStandardItem(QString("item%1").arg(itemModel->rowCount()));
        QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->listView->model());
        if(itemModel->rowCount() % 2 == 0){
            //从后面添加
            model->appendRow(item);
        }else{
            //从前面插入
            model->insertRow(0, item);

            //设置不同背景
            QLinearGradient linearGrad(QPointF(0, 0), QPointF(200, 200));
            linearGrad.setColorAt(0, Qt::darkGreen);
            linearGrad.setColorAt(1, Qt::yellow);
            QBrush brush(linearGrad);
            item->setBackground(brush);
        }

    });

    //删除行
    connect(ui->delRow, &QPushButton::clicked, this, [=](){
        QStandardItemModel*model=dynamic_cast<QStandardItemModel*>(ui->listView->model());
        qDebug() << QStringLiteral("您删除了第%1项").arg(ui->listView->currentIndex().row());
        model->removeRow(ui->listView->currentIndex().row());
    });

    //更新行
    connect(ui->updateThd, &QPushButton::clicked, this, [=](){
    int row = ui->listView->currentIndex().row();
    if(row!=-1)//-1表示没有处于选中状态的item
     {
        QStandardItemModel*listmodel=dynamic_cast<QStandardItemModel*>(ui->listView->model());
        QModelIndex index=listmodel->index(row, 0);

        QString str=listmodel->data(index,Qt::DisplayRole).toString();//get data
        bool ok;
        QString text = QInputDialog::getText(this, QStringLiteral("标题"), QStringLiteral("提示信息"), QLineEdit::Normal,
        str, &ok);
        if (ok && !text.isEmpty())
        {
            listmodel->setData(index,text,Qt::EditRole);
         }
     }else
     {
        QMessageBox::information(NULL,tr("information"),tr("please select a item"));
     }
    });
}

void Widget::showClick(QModelIndex index)
{
    QString text = QString("%1, %2").arg(index.row()).arg(index.data().toString());
    QMessageBox::information(this, "title", text, QMessageBox::Ok);
}
