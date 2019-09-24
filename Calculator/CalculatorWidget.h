#ifndef CALCULATORWIDGET_H
#define CALCULATORWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class CalculatorWidget : public QWidget
{

    QLineEdit *lineEdit;
    QPushButton *btns[16];
    QStringList strList;

    Q_OBJECT
public:
    explicit CalculatorWidget(QWidget *parent = 0);
    ~CalculatorWidget();

    void show();

signals:

public slots:
};

#endif // CALCULATORWIDGET_H
