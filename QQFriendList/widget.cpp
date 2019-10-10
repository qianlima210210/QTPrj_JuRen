#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_contentMenu(new QMenu(this))
{
    ui->setupUi(this);

    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this,
            SLOT(showContextMenu(QPoint)));

    QString str = "QMenu{background-color: #ABABAB;border: 1px solid black;}"
                  "QMenu::item {background-color: transparent;}"
                  "QMenu::item:selected {background-color: #654321;}";
    setStyleSheet(str);

    //所有设置上下文菜单的都必须设置这个属性
    setContextMenuPolicy(Qt::CustomContextMenu);

    QAction *addAct = new QAction(this);
    addAct->setText(QStringLiteral("添加分组"));
    QAction *deleteAction = new QAction(this);
    deleteAction->setText(QStringLiteral("删除分组"));
    QAction *renameAction = new QAction(this);
    renameAction->setText(QStringLiteral("重命名"));

    m_contentMenu->addAction(addAct);
    m_contentMenu->addAction(deleteAction);
    m_contentMenu->addAction(renameAction);
}

void Widget::showContextMenu(const QPoint &)
{
    m_contentMenu->exec(QCursor::pos());
}

Widget::~Widget()
{
    delete ui;
}
