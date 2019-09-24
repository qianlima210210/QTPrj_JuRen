#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600, 400);

    //创建菜单栏 最多有一个
   QMenuBar *bar = menuBar();
   bar->setStyleSheet("background-color: rgb(255,25, 255)");

    //将菜单栏放入窗口中
   setMenuBar(bar);

   //创建菜单
   QMenu *fileMenu = bar->addMenu(QStringLiteral("文件"));
   QMenu *editMenu = bar->addMenu(QStringLiteral("编辑"));

   //创建菜单项
   QAction *create = fileMenu->addAction(QStringLiteral("新建"));
   //添加分割线
   fileMenu->addSeparator();
   QAction *edit = fileMenu->addAction(QStringLiteral("编辑"));

   //创建工具栏 可以有多个
    QToolBar *tool = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, tool);

    //设置允许的停靠范围
    tool->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

    //设置浮动
    tool->setFloatable(false);

    //设置移动（总开关）
    tool->setMovable(false);

    //工具栏中可以设置内容
    tool->addAction(create);
    tool->addSeparator();
    tool->addAction(edit);

    //工具栏中添加控件
    QPushButton *btn = new QPushButton(QStringLiteral("ok"), this);
    tool->addWidget(btn);

    //添加状态栏 最多有一个
    QStatusBar *sBar = statusBar();
    //添加到窗口中
    setStatusBar(sBar);
    //添加标签控件
    QLabel *label = new QLabel(QStringLiteral("提示信息"), this);
    sBar->addWidget(label);

    QLabel *rightlabel = new QLabel(QStringLiteral("right提示信息"), this);
    sBar->addPermanentWidget(rightlabel);

    //铆接控件（浮动窗口）可以有多个
    QDockWidget *dockWidget = new QDockWidget(QStringLiteral("浮动"), this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);

    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    //中心控件 最多一个
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{

}
