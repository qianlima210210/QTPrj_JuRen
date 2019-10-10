#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenu>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

private slots:
    void showContextMenu(const QPoint&);

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QMenu *m_contentMenu;
};

#endif // WIDGET_H
