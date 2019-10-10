#ifndef GROUPTITLEWIDGET_H
#define GROUPTITLEWIDGET_H

#include <QWidget>
#include "group.h"

class QToolButton;
class QPushButton;
class QLineEdit;
class QMenu;
class QStackedWidget;

class GroupTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GroupTitleWidget(QWidget *parent = 0);

    void initContentMenu();

    Group groupInfo() const;
    void setGroupInfo(const Group &groupInfo);


private:
    void setToolButtonIcon();

signals:
    void showGroup( bool flag, const GroupBase &id);

    void addNewGroup();

    void deleteGroup(const GroupBase&);

    void reNameGroup(const GroupBase &);

public slots:
    void startToReNameGroup();

private slots:
    void changeFlag();

    void showContextMenu(const QPoint&);

    void deleteCurGroup();

    void endNameGroup();

private:
    QToolButton *m_toolButton;
    QPushButton *m_groupNameButton;
    QLineEdit *m_groupNameEdit;
    Group m_groupInfo;
    bool m_flag;
    QMenu *m_contentMenu;
    QStackedWidget *m_stackedWidget;
};

#endif // GROUPTITLEWIDGET_H
