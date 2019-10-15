#include "widget.h"
#include "ui_widget.h"

#include <QThread>
#include <QMessageBox>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::finishRequest(QNetworkReply *reply)
{
    qDebug() << "requestUrl = " << reply->request().url().toString();
    if (reply->error())
    {
        qDebug()<<"Error!"<<endl;
    }else
    {
        //解析reply中携带的Json
        QByteArray byte_array = reply->readAll();  //Json ducument
        QJsonParseError json_error;
        QJsonDocument parse_document = QJsonDocument::fromJson(byte_array, &json_error);
        if(json_error.error == QJsonParseError::NoError)
        {
              if(parse_document.isObject())
              {
                  QJsonObject obj = parse_document.object();
                  if(obj.contains("errmsg"))
                  {
                      QJsonValue errmsg = obj.take("errmsg");
                      QString msg = errmsg.toString();
                      QMessageBox::warning(this, "Error", msg, QMessageBox::Yes);
                }
           }
        }
    }
    reply->deleteLater();
}

void Widget::sendRequest()
{
    //获取用户名、密码
    QString username = "username";
    QString password = "password";
    if(username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this,"Warning","Username or password is empty!", QMessageBox::Yes);
    }
    else{
    //通过QJsonObject得到post需要的参数data， data形式为： "data={"username": "haha","passwd": 123456}"

    QJsonObject json;
    json.insert("username",username);
    json.insert("passwd",password);

    QJsonDocument document;
    document.setObject(json);

    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QByteArray data;
    data.append("data="+byte_array);

    //设置request
    if(request)
    {
        delete request;
    }
    request= new QNetworkRequest();;
    request->setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");  //上面语句固定这么写，要不然会报错“contest—type is missing”
    request->setRawHeader("XXX3", "XXX4");
    request->setUrl(QUrl("https://www.juren.cn/api/v1/auth/token"));  //"http："不要少

    //manager发送请求，并接收reply，委托给slot处理
    if(manager)
    {
        delete manager;
    }
    manager = new QNetworkAccessManager();
    manager->post(*request,data);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finishRequest(QNetworkReply*)));
  }
}

void Widget::on_pushButton_clicked()
{
    sendRequest();
}

void Widget::on_pushButton_2_clicked()
{
    QJsonObject json;//空字典

    QJsonDocument document;
    document.setObject(json);

    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QByteArray data;
    data.append(""+byte_array);

    //设置request
    if(otherrequest)
    {
        delete otherrequest;
    }
    otherrequest = new QNetworkRequest();;
    otherrequest->setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");  //上面语句固定这么写，要不然会报错“contest—type is missing”
    otherrequest->setRawHeader("XXX3", "XXX4");
    otherrequest->setUrl(QUrl("https://www.juren.cn/api/v1/mycourses/list"));  //"http："不要少

    //manager发送请求，并接收reply，委托给slot处理
    if(othermanager)
    {
        delete othermanager;
    }
    othermanager = new QNetworkAccessManager();
    othermanager->post(*otherrequest,data);
    connect(othermanager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finishOtherRequest(QNetworkReply*)));

}

void Widget::finishOtherRequest(QNetworkReply *reply)
{
    qDebug() << "OtherRequestUrl = " << reply->request().url().toString();
    if (reply->error())
    {
        qDebug()<<"Error!"<<endl;
    }else
    {
        //解析reply中携带的Json
        QByteArray byte_array = reply->readAll();  //Json ducument
        QJsonParseError json_error;
        QJsonDocument parse_document = QJsonDocument::fromJson(byte_array, &json_error);
        if(json_error.error == QJsonParseError::NoError)
        {
              if(parse_document.isObject())
              {
                  QJsonObject obj = parse_document.object();
                  if(obj.contains("errmsg"))
                  {
                      QJsonValue errmsg = obj.take("errmsg");
                      QString msg = errmsg.toString();
                      QMessageBox::warning(this, "Error", msg, QMessageBox::Yes);
                }
           }
        }
    }
    reply->deleteLater();
}
