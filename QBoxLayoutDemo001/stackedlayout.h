#ifndef STACKEDLAYOUT_H
#define STACKEDLAYOUT_H

#include <QWidget>

namespace Ui {
class StackedLayout;
}

class StackedLayout : public QWidget
{
    Q_OBJECT

public:
    explicit StackedLayout(QWidget *parent = 0);
    ~StackedLayout();

private:
    Ui::StackedLayout *ui;
};

#endif // STACKEDLAYOUT_H
