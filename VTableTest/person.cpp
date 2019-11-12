#include "person.h"

Person::Person()
{
    name = "Jone";
    cout << "Person构造函数" << endl;
}

Person::~Person()
{
    cout << "Person析构函数" << endl;
}

void Person::display()
{
    cout << "Person::display" << endl;
}



