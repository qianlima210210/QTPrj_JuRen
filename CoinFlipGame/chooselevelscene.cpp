#include "chooselevelscene.h"
#include "ui_chooselevelscene.h"
#include "iosbutton.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QLabel>
#include <QFont>
#include <QDebug>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseLevelScene)
{
    ui->setupUi(this);
    configChooseLevelScene();
}

ChooseLevelScene::~ChooseLevelScene()
{
    delete ui;
}

void ChooseLevelScene::configChooseLevelScene(){
    //设置固定大小
    this->setFixedSize(320, 588);

    //设置窗口左上角图标
    setWindowIcon(QIcon(":/images/chooseCoin.png"));

    //设置窗口标题
    setWindowTitle(QStringLiteral("选择关卡"));

    //添加菜单栏
    QMenuBar *menuBar = this->menuBar();
    setMenuBar(menuBar);

    QMenu *startMenu = menuBar->addMenu(QStringLiteral("开始"));
    QAction *action = startMenu->addAction(QStringLiteral("退出"));

    connect(action, &QAction::triggered, [=](){
        this->close();
    });

    //添加返回按钮
    IosButton *backBtn = new IosButton(this, QString(":/images/returnBeforeStyle.png"), QString(":/images/returnAfterStyle.png"));
    int backBtnX = this->width() - backBtn->width();
    int backBtnY = this->height() - backBtn->height();

    backBtn->move(backBtnX, backBtnY);
    connect(backBtn, &IosButton::clicked, [=]{
        emit backBtnClickedInChooseLevelScene();
    });

    //添加关卡按钮
    int margin = (ui->btnWidgetContainer->width() - 43 * 4) / 5;

    for(int i = 0; i < 20; i++){
        //获取行号
        int row = i / 4;

        //获取列号
         int column = i % 4;

         IosButton *btn = new IosButton(ui->btnWidgetContainer, ":/images/coin09.png");
         btn->move(margin + column * (43 + margin), margin + row * (43 + margin));

         connect(btn, &IosButton::clicked, this, [=](){
             QString msg = QStringLiteral("你选择的第%1关").arg(i + 1);
             qDebug() << msg;

             playScene = new PlayScene(i);
             playScene->setGeometry(this->geometry());
             //隐藏自己
             this->hide();
             QTimer::singleShot(100, this, [=](){
                 //显示所选关卡场景
                 playScene->show();
             });

             connect(playScene, &PlayScene::backBtnClickedInPlayScene, this, [=](){
                this->setGeometry(playScene->geometry());
                 QTimer::singleShot(100, this, [=](){
                     //2、将自身显示
                      this->show();
                     //1、关闭关卡场景
                     playScene->close();
                     delete playScene;
                     playScene = NULL;


                 });
             });

         });

         //添加标签
         QString text = QString("%1").arg(i + 1);
         QLabel *label = new QLabel(text, ui->btnWidgetContainer);
         label->setStyleSheet("color:#ff6600;");
         label->setFont(QFont("“Microsoft YaHei", 13, 75));//第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）

         label->move(btn->x(), btn->y());
         label->setFixedSize(btn->width(), btn->height());
         label->setAlignment(Qt::AlignCenter);

         //设置鼠标穿透事件
         label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *event){
    //如果窗口继承自QMainWindow，你的内容区是centralWidget所处的范围，但是坐标系还是在QMainWindow上

    //画背景
    QPainter painter(this);
    QPixmap pixmap(QString(":/images/beijing.png"));
    painter.drawPixmap(this->centralWidget()->x(), this->centralWidget()->y(),
                       width() - this->centralWidget()->x(), height() - this->centralWidget()->y(), pixmap);

    //设置背景图上的logo
    pixmap.load(QString(":/images/coin.png"));
    //缩放一下
    pixmap = pixmap.scaled(0.3 * pixmap.width(), 0.3 * pixmap.height());
    painter.drawPixmap(width() * 0.5 - pixmap.width() * 0.5,
                       this->centralWidget()->y(),
                       pixmap);
}





















