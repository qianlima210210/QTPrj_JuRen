#include "grouplistviewmodel.h"
#include <QPixmap>
#include <QSize>
#include <QDebug>

GroupListViewModel::GroupListViewModel(const QList<People> &peoples, QAbstractListModel *parent)
    :QAbstractListModel(parent)
    ,m_peoples(peoples)
{
}

GroupListViewModel::GroupListViewModel(QAbstractListModel *)
{

}

int GroupListViewModel::rowCount(const QModelIndex &) const
{
    return m_peoples.count();
}

QVariant GroupListViewModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || (index.row() > m_peoples.count())) {
        return QVariant();
    }

    if(role == Qt::UserRole) {
        return m_peoples.at(index.row()).name();
    } if(role == Qt::UserRole + 1) {
        QString localPath = ":/default_head";
        QPixmap pixmap;
        pixmap.load(localPath);
        return pixmap.scaled(QSize(50, 50), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    } else if(role == Qt::UserRole + 2) {
        return m_peoples.at(index.row()).id();
    }

    return QVariant();
}

People GroupListViewModel::getPeopleById(const QString &id)
{
    People people;
    for(int i = 0; i < m_peoples.size(); i++) {
        if(m_peoples.at(i).id() == id) {
            people = m_peoples.at(i);
            break;
        }
    }
    return people;
}

bool GroupListViewModel::addPeople(const People &people)
{
    bool re =false;
    qDebug() << people.id();
    if(!isExitPeople(people.id())) {

        m_peoples.append(people);
        emit dataChanged(index(m_peoples.size()), index(m_peoples.size()));
        re = true;
    }
    emit modelDataChanged();
    return re;
}

bool GroupListViewModel::removePeople(const QString &peopleId)
{
    bool re =false;
    for(int i = 0; i < m_peoples.size(); i++) {
        if(m_peoples.at(i).id() == peopleId) {
            m_peoples.removeAt(i);
            emit dataChanged(index(i), index(i));
            re = true;
            emit modelDataChanged();
            break;
        }
    }
    return re;
}


bool GroupListViewModel::isExitPeople(const QString peopleId)
{
    bool re =false;
    for(int i = 0; i < m_peoples.size(); i++) {
        if(m_peoples.at(i).id() == peopleId) {
            re = true;
            break;
        }
    }
    return re;
}

QList<People> GroupListViewModel::getPeoples() const
{
    return m_peoples;
}

void GroupListViewModel::setPeoples(const QList<People> &peoples)
{
    m_peoples = peoples;
}

