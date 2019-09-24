#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

Student::~Student(){

}

void Student::treat(){
    qDebug() << QStringLiteral("开饭了");
}

void Student::treat(QString name){
    qDebug() << QStringLiteral("开饭了").toUtf8().data() << name.toUtf8().data();
}
