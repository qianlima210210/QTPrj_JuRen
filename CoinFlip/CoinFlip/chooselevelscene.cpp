#include "chooselevelscene.h"
#include "ui_chooselevelscene.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseLevelScene)
{
    ui->setupUi(this);

    //设置固定大小
    setFixedSize(350,588);

    //设置窗口标题
    setWindowTitle(QStringLiteral("选择关卡"));

    //设置图标
    setWindowIcon(QIcon(":/images/images/chooseCoin.png"));


    //若不通过ui界面设计菜单栏 通过代码实现
    //创建菜单栏
    QMenuBar * bar = menuBar();
    this->setMenuBar(bar);
    //创建开始菜单
    QMenu * menu = bar->addMenu(QStringLiteral("开始啦"));
    //创建菜单项
    QAction * actionQuit = menu->addAction("退出");

    //点击 开始 退出 退出游戏
    connect(actionQuit,&QAction::triggered,[=](){
        this->close();
    });


    //创建返回按钮
    MyPushButton * chooseSceneBackBtn = new MyPushButton(":/images/images/returnAfterStyle.png",":/images/images/returnBeforeStyle.png");
    chooseSceneBackBtn->setParent(this);
    chooseSceneBackBtn->move(this->width()-chooseSceneBackBtn->width(),this->height()-chooseSceneBackBtn->height());
    connect(chooseSceneBackBtn,&MyPushButton::clicked,[=](){
        QTimer::singleShot(500,this,[=](){
            emit this->chooseSceneBack();
        });
    });

    //创建选择关卡按钮
    for(int i=0;i<20;i++)
    {
        //创建按钮
        MyPushButton * levelbtn = new MyPushButton(":/images/images/chooseCoin.png");
        levelbtn->setParent(this);
        levelbtn->move(30+(i%4)*70,(i/4)*70+150);

        //为显示关卡数创建QLabel
        QLabel * label = new QLabel(this);
        //设置标签大小
        label->setFixedSize(levelbtn->width(),levelbtn->height());
        //设置标签内容
        label->move(30+(i%4)*70,(i/4)*70+150);
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label->setText(QString::number(i+1));
        //设置鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);

        playscene = NULL;
        connect(levelbtn,&MyPushButton::clicked,[=](){

            playscene = new PlayScene(i+1);
            //自身隐藏
            this->hide();
            //设置位置
            playscene->setGeometry(this->geometry());
            //显示游戏界面
            playscene->show();

            //监听游戏界面的返回信号
            connect(playscene,&PlayScene::playSceneBack,[=](){

                //设置位置
                this->setGeometry(playscene->geometry());
                //关闭游戏界面 释放游戏界面的内存
                playscene->close();
                delete playscene;
                playscene = NULL ;

                //显示自身界面
                this->show();
            });

        });
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPixmap pix;
    //加载绘制背景图片
    pix.load(":/images/images/beijing.png");
    painter.drawPixmap(0,0,this->width(),height(),pix);

    //加载绘制背景图片
    pix.load(":/images/images/coin.png");
    pix = pix.scaled(pix.width()*0.7,pix.height()*0.7);
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix);
}

ChooseLevelScene::~ChooseLevelScene()
{
    delete ui;
}
