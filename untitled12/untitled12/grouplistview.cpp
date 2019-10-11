#include "grouplistview.h"
#include "grouplistviewmodel.h"
#include "grouplistviewdelegate.h"
#include <QWheelEvent>
#include <QMenu>
#include <QAction>
#include <QCursor>
#include <QModelIndex>
#include <QDebug>

GroupListView::GroupListView(QWidget *parent) :
    QListView(parent),
    m_contentMenu(new QMenu(this)),
    m_delegate(new GroupListViewDelegate()),
    m_model(new GroupListViewModel()),
    m_moveMenu(new QMenu(this)),
    m_deleteAction(new QAction(this))

{
    QPalette pal;
    pal.setColor(QPalette::Background, QColor(251,250,246));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    this->setItemDelegate(m_delegate);
    this->setModel(m_model);
    this->setAutoScroll(false);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVisible(false);
    this->setUpdatesEnabled(true);

    m_moveMenu->setTitle(QStringLiteral("移动联系人至"));
    m_deleteAction->setText(QStringLiteral("删除联系人"));

    m_contentMenu->addMenu(m_moveMenu);
    m_contentMenu->addAction(m_deleteAction);

    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContentMenu(QPoint)));
    connect(m_model, SIGNAL(modelDataChanged()), this, SLOT(updateFixHeight()));

    connect(m_deleteAction, SIGNAL(triggered(bool)), this, SLOT(deleteCurrentPeople()));
}

GroupListView::~GroupListView()
{
    delete m_delegate;
    delete m_model;
}


void GroupListView::wheelEvent(QWheelEvent *event)
{
    event->ignore();
}

void GroupListView::initContentMenu()
{
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    m_moveMenu->clear();


    QString str = "QMenu{background-color: #ABABAB;border: 1px solid black;}"
                  "QMenu::item {background-color: transparent;}"
                  "QMenu::item:selected {background-color: #654321;}";
    this->setStyleSheet(str);

    for(int i  = 0; i < m_otherGroupInfos.size(); i++) {
        QAction *action = new QAction(this);
        action->setText(m_otherGroupInfos.at(i).name());
        action->setData(m_otherGroupInfos.at(i).id());
        m_moveMenu->addAction(action);

        connect(action, SIGNAL(triggered(bool)), this, SLOT(movePeople()));
    }

}

void GroupListView::showContentMenu(const QPoint &)
{
    m_contentMenu->exec(QCursor::pos());
}

void GroupListView::deleteCurrentPeople()
{
    qDebug() << "delete cur patient";
    QModelIndex index = currentIndex();
    if(!index.isValid()) {
        return;
    } else {
        qDebug() << index.data(Qt::UserRole);
        QString peopleId = index.data(Qt::UserRole + 2).toString();
        m_model->removePeople(peopleId);
        emit deletePeople(m_baseInfo.id(), peopleId);
    }
}

void GroupListView::movePeople()
{
    QModelIndex index = currentIndex();
    if(!index.isValid()) {
        return;
    } else {
        qDebug() << index.data(Qt::UserRole);
        QString peopleId = index.data(Qt::UserRole+2).toString();
        People people = m_model->getPeopleById(peopleId);

        if(!people.isValid()) {
            return ;
        }

        m_model->removePeople(peopleId);

        QAction *action = dynamic_cast<QAction*>(sender());
        QString groupId = action->data().toString();

        emit movePeopleToOtherGroup(m_baseInfo.id(),
                                    people,
                                    groupId);
    }
}

void GroupListView::updateFixHeight()
{
    setFixedHeight(50 * m_model->getPeoples().size());
    if(m_model->getPeoples().size() == 0) {
        this->setVisible(false);
    }
}

QList<People> GroupListView::peoples() const
{
    return m_model->getPeoples();
}

void GroupListView::setPeoples(const QList<People> &peoples)
{
    m_model->setPeoples(peoples);
    updateFixHeight();
}

void GroupListView::addPeople(const People &people)
{
    m_model->addPeople(people);
    updateFixHeight();
}

GroupBase GroupListView::baseInfo() const
{
    return m_baseInfo;
}

void GroupListView::setBaseInfo(const GroupBase &baseInfo)
{
    m_baseInfo = baseInfo;
}

QList<GroupBase> GroupListView::otherGroupInfos() const
{
    return m_otherGroupInfos;
}

void GroupListView::setOtherGroupInfos(const QList<GroupBase> &otherGroupInfos)
{
    m_otherGroupInfos = otherGroupInfos;
    initContentMenu();
}



