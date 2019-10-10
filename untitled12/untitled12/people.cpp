#include "people.h"

People::People()
{

}

QString People::id() const
{
    return m_id;
}

void People::setId(const QString &id)
{
    m_id = id;
}

QString People::name() const
{
    return m_name;
}

void People::setName(const QString &name)
{
    m_name = name;
}

QString People::image() const
{
    return m_image;
}

void People::setImage(const QString &image)
{
    m_image = image;
}

bool People::isValid() const
{
    if(m_id.isEmpty() || m_name.isEmpty()) {
        return false;
    }
    return true;
}
