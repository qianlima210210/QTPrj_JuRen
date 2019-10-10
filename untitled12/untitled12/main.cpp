
#include <QApplication>
#include "groupwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

     QList<Group> groups;
     for(int i = 0; i <5; i++) {
         Group group;
         GroupBase base;
         QString groupId = "group" + QString::number(i);
         base.setId(groupId);
         base.setName(groupId);
         group.setGroupBase(base);

         QList<People> peoples;
         for(int j = 0; j < 6; j++) {
             People people;
             people.setId(groupId + "people" + QString::number(j));
             people.setName("people" +  QString::number(j));
             people.setImage(":/default_head");
             peoples.append(people);
         }
         group.setPeoples(peoples);
         groups.append(group);
     }
    GroupWidget widget;
    widget.setGroupInfos(groups);
    widget.initWidget();
    widget.show();

    return a.exec();
}
