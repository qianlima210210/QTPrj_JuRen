#include "group.h"

Group::Group()
{

}

GroupBase Group::groupBase() const
{
    return m_groupBase;
}

void Group::setGroupBase(const GroupBase &groupBase)
{
    m_groupBase = groupBase;
}

bool Group::deletePeople(const QString &id)
{
    bool re = false;
    for(int i = 0; i < m_peoples.size(); i++) {
        if(m_peoples.at(i).id() == id) {
            m_peoples.removeAt(i);
            re = true;
            break;
        }
    }
    return re;
}

QList<People> Group::peoples() const
{
    return m_peoples;
}

void Group::setPeoples(const QList<People> &peoples)
{
    m_peoples = peoples;
}
