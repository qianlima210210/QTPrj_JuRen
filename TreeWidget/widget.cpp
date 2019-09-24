#include "widget.h"
#include "ui_widget.h"
#include <QList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //头部标签
    ui->treeWidget->setHeaderLabels(QStringList() << QStringLiteral("项目名") << QStringLiteral("功能描述"));

    //添加顶级项
   QTreeWidgetItem *item0 = new QTreeWidgetItem(QStringList() << "00" << "001");
   QTreeWidgetItem *item1 = new QTreeWidgetItem(QStringList() << "01" << "011");
   QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList() << "02" << "021");

   QList<QTreeWidgetItem*> list = QList<QTreeWidgetItem*>();
   list.append(item0);
   list.append(item1);
   list.append(item2);
   ui->treeWidget->addTopLevelItems(list);

   //添加次顶级项
   QTreeWidgetItem *item10 = new QTreeWidgetItem(QStringList() << "10" << "000");
   QTreeWidgetItem *item11 = new QTreeWidgetItem(QStringList() << "11" << "111");
   QTreeWidgetItem *item21 = new QTreeWidgetItem(QStringList() << "21" << "222");

   QList<QTreeWidgetItem*> childlist = QList<QTreeWidgetItem*>();
   childlist.append(item10);
   childlist.append(item11);
   childlist.append(item21);

   item0->addChildren(childlist);

}

Widget::~Widget()
{
    delete ui;
}

































