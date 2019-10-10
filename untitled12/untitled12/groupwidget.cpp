#include "groupwidget.h"
#include "grouplistview.h"
#include "grouptitlewidget.h"
#include "grouplistviewdelegate.h"
#include "grouplistviewmodel.h"

#include <QVBoxLayout>
#include <QDebug>
#include <QScrollArea>


GroupWidget::GroupWidget(QWidget *parent) : QWidget(parent)
  ,m_widget(new QWidget(this))
{
    QVBoxLayout *layout = new QVBoxLayout();
    this->setLayout(layout);
    layout->setContentsMargins(0,0,0,0);

    m_widget->setStyleSheet("background-color: rgb(170, 170, 255);");

    QScrollArea *area = new QScrollArea(this);
    area->setStyleSheet("background-color: rgb(170, 255, 255);");
    area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);//设置垂直滚动条显示时机
    area->setAutoFillBackground(true);
    area->setWidgetResizable(true);//自动改变widget大小，以便widget大小超过自身时，滚动条显示出来
    area->setWidget(m_widget);
    layout->addWidget(area);

    connect(this, SIGNAL(deleteCurGroup(GroupBase)), this,
            SLOT(deleteGroup(GroupBase)));
}

void GroupWidget::initWidget()
{
    m_layoutForList = new QVBoxLayout();
    qDebug() << m_groupInfos.size();
    for(int i = 0; i < m_groupInfos.size(); i++) {
        addWidgetGroup(m_groupInfos.at(i));
    }
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addLayout(m_layoutForList);
    layout->addStretch(0);
    m_widget->setLayout(layout);
}

QList<Group> GroupWidget::groupInfos() const
{
    return m_groupInfos;
}

void GroupWidget::setGroupInfos(const QList<Group> &groupInfos)
{
    m_groupInfos = groupInfos;
    allGroupBaseInfo();
}

void GroupWidget::allGroupBaseInfo()
{
    m_groupbaseInfos.clear();
    for(int i = 0; i < m_groupInfos.size(); i++) {
        m_groupbaseInfos.append(m_groupInfos.at(i).groupBase());
    }
}

QList<GroupBase> GroupWidget::otherGroupBaseInfo(const GroupBase &info)
{
    QList<GroupBase> list = m_groupbaseInfos;
    list.removeOne(info);
    return list;
}

void GroupWidget::addWidgetGroup(const Group &groupInfo)
{
    GroupTitleWidget *title = new GroupTitleWidget(this);
    title->setGroupInfo(groupInfo);
    m_layoutForList->addWidget(title);
    m_groupTitles.append(title);

    connect(title, SIGNAL(deleteGroup(GroupBase)), this, SLOT(deleteGroup(GroupBase)));
    connect(title, SIGNAL(showGroup(bool,GroupBase)), this,
            SLOT(showGroupListView(bool,GroupBase)));
    connect(title, SIGNAL(addNewGroup()), this, SLOT(addGroup()));
    connect(title, SIGNAL(reNameGroup(GroupBase)), this,
            SLOT(reNameGroup(GroupBase)));

    GroupListView *view = new GroupListView(this);
    view->setOtherGroupInfos(this->otherGroupBaseInfo(groupInfo.groupBase()));
    view->setBaseInfo(groupInfo.groupBase());
    view->setPeoples(groupInfo.peoples());
    m_layoutForList->addWidget(view);
    m_listViews.append(view);

    connect(view, SIGNAL(deletePeople(QString,QString)), this,
            SLOT(deletePeople(QString,QString)));
    connect(view, SIGNAL(movePeopleToOtherGroup(QString,People,QString)),
            this, SLOT(moveNewGroup(QString,People,QString)));
}

void GroupWidget::updateGroupBaseInfos(const GroupBase &baseInfo, bool flag)
{
    for(int i = 0; i < m_groupbaseInfos.size(); i++) {
        if(m_groupbaseInfos.at(i).id() == baseInfo.id() ) {
            m_groupbaseInfos.removeAt(i);
            break;
        }
    }
    if(flag) {
        m_groupbaseInfos.append(baseInfo);
    }
    for(int i = 0; i < m_listViews.size(); i++) {
        GroupListView * listView = m_listViews.at(i);
        m_listViews.at(i)->setOtherGroupInfos(this->otherGroupBaseInfo(listView->baseInfo()));
    }
}

void GroupWidget::showGroupListView(bool flag, const GroupBase &baseInfo)
{
    for(int i = 0; i < m_listViews.size(); i++) {
        GroupListView *const listView = m_listViews.at(i);
        if(baseInfo == listView->baseInfo()) {
            if(listView->peoples().isEmpty()) {
                listView->setVisible(false);
            } else {
                listView->setVisible(flag);
            }
        }
    }
}


void GroupWidget::deleteGroup(const GroupBase &basInfo)
{
    for(int i = 0; i < m_groupTitles.size(); i++) {
        if(m_groupTitles.at(i)->groupInfo().groupBase() ==
                basInfo) {
            GroupTitleWidget*widget = m_groupTitles.at(i);
            m_groupTitles.removeAt(i);
            widget->deleteLater();
            break;
        }
    }

    for(int i = 0; i < m_listViews.size(); i++) {
        if(m_listViews.at(i)->baseInfo() ==
                basInfo) {
            GroupListView *listView = m_listViews.at(i);
            m_listViews.removeAt(i);
            listView->deleteLater();
            break;
        }
    }
}

void GroupWidget::addGroup()
{
    Group info;
    GroupBase baseInfo;
    baseInfo.setName("未命名");

    QString groupId = "test001";
    baseInfo.setId(groupId);
    info.setGroupBase(baseInfo);
    addWidgetGroup(info);

    for(int i = 0; i < m_groupTitles.size(); i++) {
        GroupTitleWidget *widget =  m_groupTitles.at(i);
        if(widget->groupInfo().groupBase().id() ==
                baseInfo.id()) {
            widget->startToReNameGroup();
            break;
        }
    }
}

void GroupWidget::reNameGroup(const GroupBase &baseInfo)
{
    updateGroupBaseInfos(baseInfo, true);
}

void GroupWidget::deleteGroupPeople(const QString &peopleId, const QString &groupId)
{
    for(int i = 0; i < m_groupTitles.size(); i++) {
        GroupTitleWidget *titleWidget = m_groupTitles.at(i);
        Group groupInfo = titleWidget->groupInfo();
        if(groupId == groupInfo.groupBase().id()) {
            if(groupInfo.deletePeople(peopleId)) {
                titleWidget->setGroupInfo(groupInfo);
                m_groupTitles.replace(i, titleWidget);
            }
            break;
        }
    }
}

void GroupWidget::deletePeople(const QString &groupId,
                                const QString &peopleId)
{
    deleteGroupPeople(peopleId, groupId);

}

void GroupWidget::moveNewGroup(const QString &fromGroupId,
                                      const People &people,
                                      const QString &toGroupId)
{
    deleteGroupPeople(fromGroupId, people.id());

    for(int i = 0; i < m_listViews.size(); i++) {
        GroupListView *listView = m_listViews.at(i);
        if(listView->baseInfo().id() ==
                toGroupId) {
            m_listViews.at(i)->addPeople(people);
            break;
        }
    }

}
