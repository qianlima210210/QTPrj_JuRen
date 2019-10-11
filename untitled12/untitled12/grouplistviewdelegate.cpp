#include "grouplistviewdelegate.h"
#include <QFontMetrics>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QPoint>
#include <QPixmap>
#include <QSize>
GroupListViewDelegate::GroupListViewDelegate(QStyledItemDelegate *parent)
    :QStyledItemDelegate(parent)
{

}

void GroupListViewDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    const QPixmap &pixmap = qvariant_cast<QPixmap>(index.data(Qt::UserRole + 1));
    QRect pixmapRect = QRect(option.rect.topLeft(), QSize(50, 50));

    const QString &str = index.data(Qt::UserRole).toString();
    QFontMetrics font(painter->fontMetrics());
    QRect diplayRect = QRect(pixmapRect.topRight() + QPoint(20, 25), QSize(font.width(str), font.height()));
    painter->drawPixmap(pixmapRect, pixmap);
    painter->drawText(diplayRect, str);
}

QSize GroupListViewDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &/*index*/) const
{
    return QSize(option.rect.width(), 50);
}
