#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
/*
1.展示了如何通过QJsonDocument得到QJsonObject、QJsonArray, 与Json document之间转换；
2. Json document 由QByteArray或者QString来表示；
3. QJsonParseError用于解析
*/
#include <QJsonObject>//字典对象
#include <QJsonArray>//数组对象
#include <QJsonDocument>//


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    generateJsonStringForQJsonObject();
    generateJsonStringForQJsonArray();

}

Widget::~Widget()
{
    delete ui;
}

//生成Json字符串
void Widget::generateJsonStringForQJsonObject()
{
    QJsonObject json;
    json.insert("name", QString("Qt"));
    json.insert("version", 5);
    json.insert("windows", true);

    qDebug() << json.value("name").toString();

    QJsonDocument document;
    document.setObject(json);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString json_str(byte_array);

    qDebug() << json_str;
    qDebug() << "------------------------------------------------------";

    parseJsonStringForQJsonObject(byte_array);
}

//解析Json字符串
void Widget::parseJsonStringForQJsonObject(QByteArray byte_array)
{
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        if(parse_doucment.isObject())//是个字典对象吗?
        {
            QJsonObject obj = parse_doucment.object();
            if(obj.contains("name"))
            {
                QJsonValue name_value = obj.take("name");
                if(name_value.isString())
                {
                    QString name = name_value.toString();
                    qDebug() << QString("name:%1").arg(name);
                }

            }

            if(obj.contains("version"))
            {
                QJsonValue version_value = obj.take("version");
                if(version_value.isDouble())
                {
                    double version = version_value.toVariant().toDouble();
                    qDebug() << QString("version:%1").arg(version);
                }
            }

            if(obj.contains("windows"))
            {
                QJsonValue version_value = obj.take("windows");
                if(version_value.isBool())
                {
                    bool flag = version_value.toBool();
                    qDebug() << QString("flag:%1").arg(flag);
                }
            }
        }
    }

    qDebug() << "------------------------------------------------------";
}

//生成Json字符串
void Widget::generateJsonStringForQJsonArray()
{
    QJsonArray json;
    json.insert(0, QString("Qt"));
    json.insert(1, QString("version"));
    json.insert(2, true);

    QJsonDocument document;
    document.setArray(json);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString json_str(byte_array);

    qDebug() << json_str;
    qDebug() << "------------------------------------------------------";

    parseJsonStringForQJsonArray(byte_array);
}

//解析Json字符串
void Widget::parseJsonStringForQJsonArray(QByteArray byte_array)
{
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        if(parse_doucment.isArray())
        {
            QJsonArray array = parse_doucment.array();
            int size = array.size();
            for(int i=0; i < size;i++)
            {
                QJsonValue value = array.at(i);
                if(value.isString())
                {
                    QString name = value.toString();
                    qDebug() << name;
                }
                else if(value.isBool())
                {
                    bool flag = value.toBool();
                    qDebug() << flag;
                }
            }
       }
    }
}

























