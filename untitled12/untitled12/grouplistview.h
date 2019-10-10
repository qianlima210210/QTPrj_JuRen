#ifndef GROUPLISTVIEW_H
#define GROUPLISTVIEW_H

#include "groupbase.h"
#include "people.h"
#include <QWidget>
#include <QListView>
#include <QList>

class QWheelEvent;
class QMenu;
class GroupListViewDelegate;
class GroupListViewModel;

class GroupListView : public QListView
{
    Q_OBJECT
public:
    explicit GroupListView(QWidget *parent = 0);
    ~GroupListView();

    QList<GroupBase> otherGroupInfos() const;
    void setOtherGroupInfos(const QList<GroupBase> &otherGroupInfos);

    GroupBase baseInfo() const;
    void setBaseInfo(const GroupBase &baseInfo);


    void addPeople(const People &people);

    QList<People> peoples() const;
    void setPeoples(const QList<People> &peoples);

protected:
    void wheelEvent(QWheelEvent *event);

private:
    void initContentMenu();
signals:
    void deletePeople(const QString &groupId, const QString &peopelId);

    void movePeopleToOtherGroup(const QString &fromBaseInfo, const People &patient,
                               const QString &toBaseInfo);
private slots:
    void showContentMenu(const QPoint &);

    void deleteCurrentPeople();

    void movePeople();

    void updateFixHeight();


private:
    GroupBase m_baseInfo;
    QMenu *m_contentMenu;
    QList<GroupBase> m_otherGroupInfos;
    GroupListViewDelegate *m_delegate;
    GroupListViewModel *m_model;
    QMenu *m_moveMenu;
    QAction *m_deleteAction;
};

#endif // GROUPLISTVIEW_H
