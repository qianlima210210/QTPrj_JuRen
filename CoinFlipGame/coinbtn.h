#ifndef COINBTN_H
#define COINBTN_H

#include <QPushButton>
#include <QTimer>

class CoinBtn : public QPushButton
{
private:
    QString btnPath;

public:
    int row;
    int colum;
    bool flag;

    QTimer *timer0;
    QTimer *timer1;

    int min = 1;
    int max = 9;

    bool isAnimation = false;

    void changeFlag();

   Q_OBJECT

public:
    explicit CoinBtn(QWidget *parent = 0);
     CoinBtn(QWidget *parent, QString btnPath);
    ~CoinBtn();

signals:

public slots:

};

#endif // COINBTN_H
