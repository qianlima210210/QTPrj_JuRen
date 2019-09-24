#include "mainscreen.h"
#include "ui_mainscreen.h"
#include <QAction>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include "iosbutton.h"

#include <QDebug>

MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent, Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);
    configMainScreen();
}

//配置主场景
void MainScreen::configMainScreen(){
    //窗口固定大小
   setFixedSize(320, 588);

   //设置窗口左上角图标
   setWindowIcon(QIcon(":/images/start.png"));

   //设置窗口标题
   setWindowTitle(QStringLiteral("翻金币"));

   connect(ui->actionquit, &QAction::triggered, [=](){
       close();
   } );

   //创建选择关卡场景
   chooseLevelScene = new ChooseLevelScene();
   connect(chooseLevelScene, &ChooseLevelScene::backBtnClickedInChooseLevelScene, this, [=](){
       this->setGeometry(this->chooseLevelScene->geometry());
       //1、隐藏选择关卡场景
       this->chooseLevelScene->hide();
       QTimer::singleShot(300, this, [=](){
           //2、先将自身显示
           this->show();
       });
   });

   //添加开始按钮
   IosButton *startBtn = new IosButton(this, QString(":/images/start.png"));
   int startBtnX = (width() - this->centralWidget()->x()) * 0.5 - startBtn->width() * 0.5;
   int startBtnY = (height() - this->centralWidget()->y()) - startBtn->height() * 1.5;
   startBtn->move(startBtnX, startBtnY);

   connect(startBtn, &IosButton::clicked, [=](){
       startBtn->animationDown();
       startBtn->animationUp();

       //1、先将自身隐藏
       this->chooseLevelScene->setGeometry(this->geometry());
       this->hide();
       QTimer::singleShot(300, this, [=](){
           //延时进入选择关卡场景
           //2、显示选择关卡场景
           this->chooseLevelScene->show();
       });

   });
}

MainScreen::~MainScreen()
{
    delete ui;
    delete chooseLevelScene;
}

void MainScreen::paintEvent(QPaintEvent *event){
    //如果窗口继承自QMainWindow，你的内容区是centralWidget所处的范围，但是坐标系还是在QMainWindow上

    //画背景
    QPainter painter(this);
    QPixmap pixmap(QString(":/images/beijing.png"));
    painter.drawPixmap(this->centralWidget()->x(), this->centralWidget()->y(),
                       width() - this->centralWidget()->x(), height() - this->centralWidget()->y(), pixmap);

    //设置背景图上的logo
    pixmap.load(QString(":/images/gamewin.png"));
    //缩放一下
    pixmap = pixmap.scaled(0.5 * pixmap.width(), 0.5 * pixmap.height());
    painter.drawPixmap(this->centralWidget()->x(), this->centralWidget()->y(), pixmap);

}







































