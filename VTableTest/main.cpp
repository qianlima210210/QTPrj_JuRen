#include <QCoreApplication>
#include "person.h"

typedef void (*Display)();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person *p = new Person();

//    void *name = (((int*)p)+1);
//    cout << "通过指针获取对象成员变量：" << *(string*)name << endl;

//   Display display = Display (*(int*)(*((int*)p)));//虚函数表地址,也是第一个虚函数地址
//   display();

    printf("为对象分配的内存大小：%d\n", sizeof(Student));
   Student s;
   //s.myFun();

   delete p;


    return a.exec();
}

/*
 * 1、有虚函数才会有虚函数表，才会在为类对象
 * 分配一个用来存放虚函数表地址的指针变量
 *
 *  2、即使本类中没有虚函数，但是基类有，则仍有自己的虚函数表，表中的函数指针从基类拷贝过来。
 *
 *
 */
