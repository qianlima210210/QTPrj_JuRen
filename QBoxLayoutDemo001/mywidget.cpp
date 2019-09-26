#include "mywidget.h"
#include <QStyleOption>
#include <QPushButton>
#include <QPainter>
#include <QHBoxLayout>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QPushButton *pButton1 = new QPushButton("One");
    QPushButton *pButton2 = new QPushButton("Two");
    QPushButton *pButton3 = new QPushButton("Three");
    QPushButton *pButton4 = new QPushButton("Four");
    QPushButton *pButton5 = new QPushButton("Five");

    QHBoxLayout *pHLayout = new QHBoxLayout();
    pHLayout->setContentsMargins(0, 0, 0, 0);
    pHLayout->setSpacing(0);

    pHLayout->addWidget(pButton1);

    QSpacerItem *item = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Expanding);
    pHLayout->addSpacerItem(item);
    pHLayout->addWidget(pButton2);

    item = new QSpacerItem(30, 0, QSizePolicy::Fixed, QSizePolicy::Expanding);
    pHLayout->addSpacerItem(item);
    pHLayout->addWidget(pButton3);

    item = new QSpacerItem(90, 0, QSizePolicy::Fixed, QSizePolicy::Expanding);
    pHLayout->addSpacerItem(item);
    pHLayout->addWidget(pButton4);

    item = new QSpacerItem(150, 0, QSizePolicy::Fixed, QSizePolicy::Expanding);
    pHLayout->addSpacerItem(item);
    pHLayout->addWidget(pButton5);

    setLayout(pHLayout);
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
