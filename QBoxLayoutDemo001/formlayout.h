#ifndef FORMLAYOUT_H
#define FORMLAYOUT_H

#include <QWidget>

namespace Ui {
class FormLayout;
}

class FormLayout : public QWidget
{
    Q_OBJECT

public:
    explicit FormLayout(QWidget *parent = 0);
    ~FormLayout();

private:
    Ui::FormLayout *ui;
};

#endif // FORMLAYOUT_H
