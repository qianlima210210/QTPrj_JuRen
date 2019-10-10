#ifndef GROUPBASE_H
#define GROUPBASE_H

#include <QString>

class GroupBase
{
public:
    GroupBase();

    QString id() const;
    void setId(const QString &id);

    QString name() const;
    void setName(const QString &name);

    bool operator ==(const GroupBase &base) const;

private:
    QString m_id;
    QString m_name;
};

#endif // GROUPBASE_H
