#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //生成Json字符串
    void generateJsonStringForQJsonObject();

    //解析Json字符串
    void parseJsonStringForQJsonObject(QByteArray byte_array);

    //生成Json字符串
    void generateJsonStringForQJsonArray();

    //解析Json字符串
    void parseJsonStringForQJsonArray(QByteArray byte_array);


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
