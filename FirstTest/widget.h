#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

   QPushButton *btn;
   QWidget *otherWidget;

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void openOtherWidget();
    void closeOtherWidget();
};

#endif // WIDGET_H
