#ifndef GROUPLISTVIEWDELEGATE_H
#define GROUPLISTVIEWDELEGATE_H

#include <QStyledItemDelegate>

class GroupListViewDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit GroupListViewDelegate(QObject *parent = 0);
    ~GroupListViewDelegate();

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;


signals:

public slots:
};

#endif // GROUPLISTVIEWDELEGATE_H
