#include "widget.h"
#include <QApplication>
#include <QThread>
#include <QDebug>

int main(int argc, char *argv[])
{
    qDebug() << "main thread: " << QThread::currentThreadId();
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
