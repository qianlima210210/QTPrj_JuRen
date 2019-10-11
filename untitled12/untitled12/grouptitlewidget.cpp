#include "grouptitlewidget.h"
#include <QToolButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QMenu>
#include <QAction>
#include <QCursor>
#include <QPoint>
#include <QStackedWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>


GroupTitleWidget::GroupTitleWidget(QWidget *parent) : QWidget(parent)
  ,m_toolButton(new QToolButton(this))
  ,m_groupNameButton(new QPushButton(this))
  ,m_groupNameEdit(new QLineEdit(this))
  ,m_flag(false)
  ,m_contentMenu(new QMenu(this))
  ,m_stackedWidget(new QStackedWidget(this))
{
    this->setFixedHeight(18);
    QHBoxLayout *layout = new QHBoxLayout();
    m_toolButton->setFixedHeight(18);
    m_stackedWidget->setFixedHeight(18);
    layout->addWidget(m_toolButton);
    layout->addWidget(m_stackedWidget);
    layout->addStretch(0);
    this->setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);

    m_stackedWidget->addWidget(m_groupNameButton);
    m_stackedWidget->addWidget(m_groupNameEdit);

    m_groupNameButton->setStyleSheet("QPushButton{text-align : left;}");
    setToolButtonIcon();

    connect(m_toolButton, SIGNAL(clicked(bool)), this, SLOT(changeFlag()));
    connect(m_groupNameButton, SIGNAL(clicked(bool)), this, SLOT(changeFlag()));
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this,
            SLOT(showContextMenu(QPoint)));

    QString str = "QMenu{background-color: #ABABAB;border: 1px solid black;}"
                  "QMenu::item {background-color: transparent;}"
                  "QMenu::item:selected {background-color: #654321;}";
    setStyleSheet(str);

    connect(m_groupNameEdit, SIGNAL(editingFinished()), this, SLOT(endNameGroup()));
}

void GroupTitleWidget::setToolButtonIcon()
{
    if(m_flag) {
        m_toolButton->setStyleSheet("QToolButton{border:none;border-image:url(:/arrowdown);}");
    } else {
        m_toolButton->setStyleSheet("QToolButton{border:none;border-image:url(:/arrow);}");
    }
}

void GroupTitleWidget::changeFlag()
{
    m_flag = !m_flag;
    setToolButtonIcon();

    emit showGroup(m_flag, m_groupInfo.groupBase());
}

void GroupTitleWidget::showContextMenu(const QPoint &)
{
    m_contentMenu->exec(QCursor::pos());
}

void GroupTitleWidget::deleteCurGroup()
{
    emit deleteGroup(m_groupInfo.groupBase());
}

void GroupTitleWidget::startToReNameGroup()
{
    m_stackedWidget->setCurrentIndex(1);
    m_groupNameEdit->setFocus();
}

void GroupTitleWidget::endNameGroup()
{
    m_stackedWidget->setCurrentIndex(0);
    GroupBase baseInfo = m_groupInfo.groupBase();
    baseInfo.setName(m_groupNameEdit->text());
    m_groupInfo.setGroupBase(baseInfo);
    m_groupNameButton->setText(baseInfo.name());
    emit reNameGroup(m_groupInfo.groupBase());
}

Group GroupTitleWidget::groupInfo() const
{
    return m_groupInfo;
}

void GroupTitleWidget::setGroupInfo(const Group &groupInfo)
{
    m_groupInfo = groupInfo;
    m_groupNameButton->setText(groupInfo.groupBase().name());
    m_groupNameEdit->setText(groupInfo.groupBase().name());
    initContentMenu();
}


void GroupTitleWidget::initContentMenu()
{
    //所有设置上下文菜单的都必须设置这个属性
    setContextMenuPolicy(Qt::CustomContextMenu);

    QAction *addAct = new QAction(this);
    addAct->setText("添加分组");
    QAction *deleteAction = new QAction(this);
    deleteAction->setText("删除分组");
    QAction *renameAction = new QAction(this);
    renameAction->setText("重命名");

    m_contentMenu->addAction(addAct);
    m_contentMenu->addAction(deleteAction);
    m_contentMenu->addAction(renameAction);

    if(m_groupInfo.peoples().size() <= 0) {
        deleteAction->setEnabled(true);
    } else {
        deleteAction->setEnabled(false);
    }

    connect(addAct, SIGNAL(triggered(bool)), this, SIGNAL( addNewGroup()));
    connect(deleteAction, SIGNAL(triggered(bool)), this, SLOT(deleteCurGroup()));
    connect(renameAction, SIGNAL(triggered(bool)), this, SLOT(startToReNameGroup()));

}
