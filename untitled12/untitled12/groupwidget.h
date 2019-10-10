#ifndef GROUPWIDGET_H
#define GROUPWIDGET_H

#include "group.h"
#include "people.h"
#include "groupbase.h"

#include <QWidget>
#include <QList>
class GroupTitleWidget;
class GroupListView;
class QVBoxLayout;

class GroupWidget : public QWidget
{
    Q_OBJECT
public:
    GroupWidget(QWidget *parent = 0);

    void initWidget();

    QList<Group> groupInfos() const;
    void setGroupInfos(const QList<Group> &groupInfos);


private:
    void allGroupBaseInfo();

    QList<GroupBase> otherGroupBaseInfo(const GroupBase &info);

    void addWidgetGroup(const Group &);

    void updateGroupBaseInfos(const GroupBase &baseInfo, bool flag);

signals:
    void deleteCurGroup(const GroupBase&);
private slots:
    void showGroupListView( bool flag, const GroupBase &baseInfo);

    void deleteGroup(const GroupBase&);

    void addGroup();

    void reNameGroup(const GroupBase&);

    void deletePeople(const QString &groupId, const QString &peopleId);

    void moveNewGroup(const QString &fromBaseInfo, const People &patient,
            const QString &toBaseInfo);


    void deleteGroupPeople(const QString &patientId, const QString &groupId);

private:
    QList<Group> m_groupInfos;
    QList<GroupBase> m_groupbaseInfos;
    QWidget *m_widget;
    QVBoxLayout *m_layoutForList;

    QList<GroupTitleWidget*> m_groupTitles;
    QList<GroupListView*> m_listViews;

};

#endif // GROUPWIDGET_H
