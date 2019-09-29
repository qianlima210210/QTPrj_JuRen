#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include <QWidget>

namespace Ui {
class GridLayout;
}

class GridLayout : public QWidget
{
    Q_OBJECT

public:
    explicit GridLayout(QWidget *parent = 0);
    ~GridLayout();

private:
    Ui::GridLayout *ui;
};

#endif // GRIDLAYOUT_H
