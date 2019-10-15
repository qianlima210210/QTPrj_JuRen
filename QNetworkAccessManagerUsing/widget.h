#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public slots:
    void finishRequest(QNetworkReply*);  //处理reply的slot
    void sendRequest();
    void on_pushButton_clicked();

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void finishOtherRequest(QNetworkReply *reply);
    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    //每个网络请求都对应一个manager和request
    QNetworkAccessManager *manager = NULL;      //manager  相关注意点见后文
    QNetworkRequest *request = NULL;            //request

    QNetworkAccessManager *othermanager = NULL;      //manager  相关注意点见后文
    QNetworkRequest *otherrequest = NULL;            //request

};

#endif // WIDGET_H
