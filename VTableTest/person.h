#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person
{
public:
    string name;
public:
    Person();
     ~Person();

     void display();

     virtual void myFun(){
        cout << "Person::myFun" << endl;
    }
};

class People
{
public:
    People() {}
    ~People() {}

    virtual void test(){}
};

class Student : public Person, public People
{
public:
    Student() {}
    ~Student(){}
};

#endif // PERSON_H
