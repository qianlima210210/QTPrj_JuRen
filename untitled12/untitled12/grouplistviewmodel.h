#ifndef GROUPLISTVIEWMODEL_H
#define GROUPLISTVIEWMODEL_H

#include "people.h"
#include <QAbstractListModel>
#include <QMap>
#include <QString>

class QModelIndex;
class QVariant;

class GroupListViewModel : public QAbstractListModel
{
    Q_OBJECT
public:
    GroupListViewModel(const QList<People> &peoples, QAbstractListModel *parent = 0);
    GroupListViewModel(QAbstractListModel *parent = 0);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;



    People getPeopleById(const QString &id);

    bool addPeople(const People &people);
    bool removePeople(const QString &patientId);


    QList<People> getPeoples() const;
    void setPeoples(const QList<People> &peoples);

private:
    bool isExitPeople(const QString peopleId);

signals:
    void modelDataChanged();

private:
    QList<People> m_peoples;
};

#endif // GROUPLISTVIEWMODEL_H
