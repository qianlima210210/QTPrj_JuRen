#include "widget.h"
#include "form.h"
#include "gridlayout.h"
#include "formlayout.h"
#include "stackedlayout.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
