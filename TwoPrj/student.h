#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = 0);
    ~Student();

signals:

public slots:
    //早期qt版本，要求槽成员函数，必须写在public slots下;qt高版本可以写到public或全局下
    //返回值是void，需要声明，也需要实现。
    //可以有参数，也可以无参数，所以可以重载。
    void treat();
    void treat(QString name);

};

#endif // STUDENT_H
