#include "CalculatorWidget.h"

CalculatorWidget::CalculatorWidget(QWidget *parent) : QWidget(parent)
{
    strList << "C" << "del" << "0" << "/"
            << "7" << "8" << "9" << "x"
            << "4" << "5" << "6" << "-"
            << "1" << "2" << "3" << "=";

    //定义边界、编辑框高度、按钮高度、宽度
    int margin = 10;
    int lineEditHeight = 20;
    int btnWidth = 40;
    int btnHeight = 40;

    //添加编辑框
    lineEdit = new QLineEdit(this);
    lineEdit->setReadOnly(true);
    lineEdit->move(margin, margin);
    lineEdit->resize(4 * btnWidth + 3 * margin, lineEditHeight);

    //添加按钮
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            btns[i * 4 + j] = new QPushButton(strList[i * 4 + j], this);
            btns[i * 4 + j]->resize(btnWidth, btnHeight);
            btns[i * 4 + j]->move(margin + (btnWidth + margin) * j, lineEdit->y() + lineEditHeight + margin + (btnHeight + margin) * i);
        }
    }
}

CalculatorWidget::~CalculatorWidget(){

}

void CalculatorWidget::show(){
    QWidget::show();
    setFixedSize(width(), height());
}
