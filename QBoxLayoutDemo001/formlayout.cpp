#include "formlayout.h"
#include "ui_formlayout.h"
#include <QFormLayout>
#include <QLineEdit>

FormLayout::FormLayout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormLayout)
{
    ui->setupUi(this);

    /*
    QFormLayout* layout = new QFormLayout();

    QLineEdit* text1 = new QLineEdit();
    text1->setFixedHeight(100);
    QLineEdit* text2 = new QLineEdit();
    QLineEdit* text3 = new QLineEdit();

    layout->addRow("N:",text1);//
    layout->addRow("E:",text2);
    layout->addRow("A:",text3);

    layout->setSpacing(10);
    layout->setContentsMargins(20, 20, 20, 20);

    layout->setRowWrapPolicy(QFormLayout::DontWrapRows);//该参数通常适用于小屏幕中，当标签和文本框在本行显示不全时，文本框会显示在下一行，使得标签独占一行
    layout->setLabelAlignment(Qt::AlignLeft);//设置标签的对齐方式
    setLayout(layout);
    this->setWindowTitle("FTP");
    */

    QFormLayout* layout = new QFormLayout();//顶级布局管理器
    QVBoxLayout* vlayout = new QVBoxLayout();//被嵌套使用的布局管理器

    QLineEdit* text1 = new QLineEdit();
    QLineEdit* text2 = new QLineEdit();
    QLineEdit* text3 = new QLineEdit();

    vlayout->addWidget(text2);//子管理器布局
    vlayout->addWidget(text3);

    layout->addRow("Name:",text1);//往QFormLayout中添加表项
    layout->addRow("Tel:",vlayout);
    layout->setSpacing(10);

    setLayout(layout);//设置顶级布局管理器
}

FormLayout::~FormLayout()
{
    delete ui;
}
