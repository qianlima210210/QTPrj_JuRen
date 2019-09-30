#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QStackedLayout>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
private:

    QPushButton *preBtn;
    QPushButton *nextBtn;
    QStackedLayout *sLayout;


    QLabel *label[4];
    QLineEdit *edit[3];
    QLabel *text;
    QPushButton *btn[3];

public:
    QWidget *get1stpage();//返回子页面所在父组件
    QWidget *get2ndpage();//返回子页面所在父组件
    QWidget *get3rdpage();//返回子页面所在父组件

    void OnPreBtnClicked();//与向导按钮关联的槽函数
    void OnNextBtnClicked();

    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
