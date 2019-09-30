#include "widget.h"
#include "ui_widget.h"
#include <QFormLayout>
#include <QLineEdit>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //first是组织QStackedLayout和QHBoxLayout进行整体页面布局
    QVBoxLayout* vLayout = new QVBoxLayout();
    sLayout = new QStackedLayout();
    QHBoxLayout* hLayout = new QHBoxLayout();

    //设置按钮属性
    preBtn = new QPushButton();
    preBtn->setText("Pre Page");
    preBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);//宽度可扩展，高度不变
    preBtn->setMinimumSize(160, 30);

    nextBtn = new QPushButton();
    nextBtn->setText("Next Page");
    nextBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);//宽度可扩展，高度不变
    nextBtn->setMinimumSize(160, 30);

    hLayout->addWidget(preBtn);//添加按钮到水平管理器
    hLayout->addWidget(nextBtn);

    sLayout->addWidget(get1stpage());//添加子组件到栈式管理器
    sLayout->addWidget(get2ndpage());
    sLayout->addWidget(get3rdpage());

    vLayout->addLayout(sLayout);//嵌套布局管理器
    vLayout->addLayout(hLayout);

    setLayout(vLayout);//设置顶层布局管理器

    connect(nextBtn, &QPushButton::clicked, this, &Widget::OnNextBtnClicked);
    connect(preBtn, &QPushButton::clicked,this, &Widget::OnPreBtnClicked);

}

Widget::~Widget()
{
    delete ui;
}

//返回子页面所在父组件
QWidget *Widget::get1stpage()
{
    QWidget *ret = new QWidget();
    QGridLayout *layout = new QGridLayout();

    label[0] = new QLabel("C");
    label[1] = new QLabel("C++");
    label[2] = new QLabel("Java");
    label[3] = new QLabel("Swift");

    layout->addWidget(label[0], 0, 0);
    layout->addWidget(label[1], 0, 1);
    layout->addWidget(label[2], 1, 0);
    layout->addWidget(label[3], 1, 1);

    ret->setLayout(layout);

    return ret;

}
//返回子页面所在父组件
QWidget *Widget::get2ndpage()
{
    QWidget *ret = new QWidget();
    QFormLayout *layout = new QFormLayout();

    edit[0] = new QLineEdit("welcome");
    edit[1] = new QLineEdit("every");
    edit[2] = new QLineEdit("one");

    layout->addRow("Account: ", edit[0]);
    layout->addRow("Password: ", edit[1]);
    layout->addRow("Msg: ", edit[2]);

    layout->setLabelAlignment(Qt::AlignRight);
    ret->setLayout(layout);

    return ret;
}
//返回子页面所在父组件
QWidget *Widget::get3rdpage()
{
    QWidget* ret = new QWidget();
    QHBoxLayout* HBoxLayout = new QHBoxLayout();
    QVBoxLayout* VBoxLayout = new QVBoxLayout();

    text = new QLabel("Are You Happy Now?");
    text->move(0, 0);

    btn[0] = new QPushButton("Happy very much");
    btn[1] = new QPushButton("Sad very much");
    btn[2] = new QPushButton("Just so so");

    HBoxLayout->addWidget(btn[0]);
    HBoxLayout->addWidget(btn[1]);
    HBoxLayout->addWidget(btn[2]);

    VBoxLayout->addWidget(text);
    VBoxLayout->addLayout(HBoxLayout);

    ret->setLayout(VBoxLayout);

    return ret;
}
//与向导按钮关联的槽函数
void Widget::OnPreBtnClicked()
{
    int index = ((sLayout->currentIndex() - 1) + 3) % sLayout->count();//循环切换页面
    sLayout->setCurrentIndex(index);//设置当前显示的页面
}

void Widget::OnNextBtnClicked()
{
    int index = ((sLayout->currentIndex() + 1)) % sLayout->count();
    sLayout->setCurrentIndex(index);
}
