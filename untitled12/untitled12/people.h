#ifndef PEOPLE_H
#define PEOPLE_H

#include <QString>

class People
{
public:
    People();

    QString id() const;
    void setId(const QString &id);

    QString name() const;
    void setName(const QString &name);

    QString image() const;
    void setImage(const QString &image);

    bool isValid() const;
private:
    QString m_id;
    QString m_name;
    QString m_image;
};

#endif // PEOPLE_H
