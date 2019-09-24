#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    teacher = new Teacher(this);
    student = new Student(this);

    void (Teacher::*tfun0)() = &Teacher::hungry;
    void (Student::*sfun0)() = &Student::treat;

    //第一步建立信号&槽的链接
    connect(teacher, tfun0, student, sfun0);

    //第二步发送信号
    emit teacher->hungry();

    ///////////////////////////////
    void (Teacher::*tfun1)(QString) = &Teacher::hungry;
    void (Student::*sfun1)(QString) = &Student::treat;

    //第一步建立信号&槽的链接
    connect(teacher, tfun1, student, sfun1);

    //第二步发送信号
    emit teacher->hungry(QStringLiteral("宫爆鸡丁"));

    ///////////////////////////////
    //信号和信号的链接:注意左边信号的参数大于等于右边信号的参数，且对应参数类型列表必须一样
    QPushButton *btn = new QPushButton(QStringLiteral("下课"), this);
    connect(btn, &QPushButton::clicked, teacher, tfun0);

    //断开链接
    disconnect(btn, &QPushButton::clicked, teacher, tfun0);

    //拓展
    //1、信号可以连接信号
    //2、一个信号可以连接多个槽函数
    //3、多个信号可以链接一个槽函数
    //4、信号和槽函数的参数，必须一一对应
    //5、信号和槽函数参数个数 是不是要一致？信号的参数个数>=槽函数的参数个数。

    //lambda表达式，匿名实例方法。oc中的block，swift中的闭包。
    QPushButton *btn0 = new QPushButton(QStringLiteral("匿名按钮"), this);
    btn0->move(200, 0);
    connect(btn0, &QPushButton::clicked, this, [=](){
        //this->close();
        emit teacher->hungry(QStringLiteral("宫爆鸡丁"));
        btn0->setText("dddd");
    });

    //上面是无返回值，中括号中的等号，意味着你可访问所在代码块作用域可见的变量。
    //下面是有返回值
    int r = [=]()->int{
        return 100;
    }();


}

Widget::~Widget()
{
    delete ui;
}
