#include "widget.h"
#include "form.h"
#include "gridlayout.h"
#include "formlayout.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormLayout w;
    w.show();

    return a.exec();
}
