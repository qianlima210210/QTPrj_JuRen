#include "widget.h"
#include "ui_widget.h"
#include <QStandardItemModel>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel();

    for (int i = 0; i < 150; ++i) {
        QString iconPath = QString(":/images/%1.png").arg(i%2==0? "x":"y");
        QString text = i%2==0? QStringLiteral("东邪西毒\n南帝北丐"):QStringLiteral("中神通"); // 可以多行显示
        QStandardItem *item = new QStandardItem(QIcon(iconPath), text);
        item->setBackground(QBrush(Qt::green));
        item->setToolTip(QStringLiteral("天地不仁, 以万物为刍狗<br>圣人不仁, 以百姓为刍狗<br><font color=\"darkred\">结刍为狗, 用之祭祀, 既毕事则弃而践之</font><br><img src=\":/images/x.png\">"));


        model->appendRow(item);
    }

    ui->listView->setModel(model);
    ui->listView->setSpacing(0);                   //为视图设置控件间距

    ui->listView->setWrapping(true); // 空间不够显示后自动折叠,就是自动换行
    ui->listView->setFlow(QListView::LeftToRight); // 从左向右排列
    ui->listView->setViewMode(QListView::IconMode); // 文字在图标下面
    ui->listView->setResizeMode(QListView::Adjust); // 大小变化后重新布局 items
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers); // 不允许编辑
    ui->listView->setIconSize(QSize(64, 64)); // 图标大小
    //ui->listView->setGridSize(QSize(160, 75)); // item 的最大大小
    //ui->listView->setUniformItemSizes(true); // 所有的 item 一样大
}

Widget::~Widget()
{
    delete ui;
}
