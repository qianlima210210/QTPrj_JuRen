#ifndef GROUP_H
#define GROUP_H

#include <QString>
#include <QList>
#include "people.h"
#include "groupbase.h"

class Group
{
public:
    Group();

    GroupBase groupBase() const;
    void setGroupBase(const GroupBase &groupBase);

    bool deletePeople(const QString &id);

    QList<People> peoples() const;
    void setPeoples(const QList<People> &peoples);

private:
    GroupBase m_groupBase;
    QList<People> m_peoples;
};

#endif // GROUP_H
