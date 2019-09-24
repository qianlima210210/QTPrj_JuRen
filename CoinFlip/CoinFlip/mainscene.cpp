#include "mainscene.h"
#include "ui_mainscene.h"



MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //点击 开始 退出 退出游戏
    connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });

    //设置固定大小
    setFixedSize(350,588);

    //设置窗口标题
    setWindowTitle(QStringLiteral("翻金币游戏"));

    //设置图标
    setWindowIcon(QIcon(":/images/images/chooseCoin.png"));

    //开始按钮的创建
    MyPushButton * Startbtn = new MyPushButton(":/images/images/start.png");
    Startbtn->setParent(this);
    Startbtn->move(this->width()*0.5-Startbtn->width()*0.5,this->height()*0.7);

    //创建 第二个 选择关卡场景
    chooseScene = new ChooseLevelScene;

    //创建音效
    QSound* startsound = new QSound(":/images/images/10910.wav");

    //监听第二个场景的返回信号chooseSceneBack
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,[=](){
        //第二个场景隐藏
        chooseScene->hide();
        //设置位置
        this->setGeometry(chooseScene->geometry());
        //自身显示
        this->show();
    });

    //点击start按钮
    connect(Startbtn,&MyPushButton::clicked,[=](){
       // qDebug()<<"点击了开始按钮";
       //音效
        startsound->play();
       //设置弹跳效果
       Startbtn->Zoom1();
       Startbtn->Zoom2();

       //延迟进入第二个场景
       QTimer::singleShot(500,this,[=](){
           //将自身隐藏
           this->hide();
           //设置选择关卡场景的位置
           chooseScene->setGeometry(this->geometry());
           //进入第二个场景
           chooseScene->show();
       });


    });

}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //创建 QPixmap对象
    QPixmap pix;
    //加载背景图片
    pix.load(":/images/images/beijing.png");
    //绘制
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题图片
    pix.load(":/images/images/coin.png");
    //缩放图片
    pix = pix.scaled(pix.width()*0.6,pix.height()*0.6);
    //绘制
    painter.drawPixmap(10,30,pix);
}

MainScene::~MainScene()
{
    delete ui;
}


