#include "groupbase.h"

GroupBase::GroupBase()
{

}

QString GroupBase::id() const
{
    return m_id;
}

void GroupBase::setId(const QString &id)
{
    m_id = id;
}

QString GroupBase::name() const
{
    return m_name;
}

void GroupBase::setName(const QString &name)
{
    m_name = name;
}

bool GroupBase::operator ==(const GroupBase &base) const
{
    if(m_id == base.id() ) {
        return true;
    }
    return false;
}
