#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStringListModel>
#include <QStandardItemModel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QStringListModel *stringListModel;
    QStandardItemModel *itemModel;

    void init();

private slots:
    void showClick(QModelIndex index);



};

#endif // WIDGET_H
