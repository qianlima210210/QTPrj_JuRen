#ifndef GROUPLISTVIEWDELEGATE_H
#define GROUPLISTVIEWDELEGATE_H

#include <QStyledItemDelegate>

class GroupListViewDelegate : public QStyledItemDelegate
{
public:
    GroupListViewDelegate(QStyledItemDelegate *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const;
};

#endif // GROUPLISTVIEWDELEGATE_H
