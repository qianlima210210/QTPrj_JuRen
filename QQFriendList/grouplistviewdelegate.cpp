#include "grouplistviewdelegate.h"

GroupListViewDelegate::GroupListViewDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

GroupListViewDelegate::~GroupListViewDelegate()
{

}

void GroupListViewDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

}

QSize GroupListViewDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &/*index*/) const
{
    return QSize(100, 60);
}
