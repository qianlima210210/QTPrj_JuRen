
#include <QApplication>
#include "CalculatorWidget.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    CalculatorWidget *w = new CalculatorWidget();

    //显示顶级窗口
    w->show();

    int r = a.exec();
    delete w;

    return r;
}
