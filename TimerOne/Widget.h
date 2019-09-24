#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
private:
    int timerId0;
    int timerId1;

    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void timerEvent(QTimerEvent *event);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
