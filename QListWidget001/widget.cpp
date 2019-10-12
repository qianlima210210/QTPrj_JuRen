#include "widget.h"
#include "ui_widget.h"
#include "itemwidget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    for(int i =0; i < 10; i++)
    {
        createListWidgetItem();
    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::createListWidgetItem()
{
    ItemWidget *itemWidget = new ItemWidget(ui->listWidget);

    //将widget作为列表的item
    QListWidgetItem *ITEM = new QListWidgetItem();

    QSize size = ITEM->sizeHint();
    ITEM->setSizeHint(QSize(size.width(), 56));
    ui->listWidget->addItem(ITEM);
    itemWidget->setSizeIncrement(size.width(), 56);

    ui->listWidget->setItemWidget(ITEM, itemWidget);
}
