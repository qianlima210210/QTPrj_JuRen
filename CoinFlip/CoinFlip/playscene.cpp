#include "playscene.h"
#include "ui_playscene.h"

#include "dataconfig.h"


PlayScene::PlayScene(int index): ui(new Ui::PlayScene)
{
     ui->setupUi(this);
    //点击 开始 退出 退出游戏
    connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });

    this->index = index;

    //设置固定大小
    setFixedSize(320,588);

    //设置窗口标题
    setWindowTitle("游戏");

    //设置图标
    setWindowIcon(QIcon(":/images/images/chooseCoin.png"));

    //创建返回按钮
    MyPushButton * playSceneBackBtn = new MyPushButton(":/images/images/returnAfterStyle.png",":/images/images/returnBeforeStyle.png");
    playSceneBackBtn->setParent(this);
    playSceneBackBtn->move(this->width()-playSceneBackBtn->width(),this->height()-playSceneBackBtn->height());

    //点击返回按钮 发送信号
    connect(playSceneBackBtn,&MyPushButton::clicked,[=](){
        QTimer::singleShot(500,this,[=](){
            emit this->playSceneBack();
        });
    });

    //显示具体关卡
    QLabel * label = new QLabel(this);
    //设置label的大小和位置 也可以通过move和setfixedsize设置
    label->setGeometry(QRect(10,this->height()-50,120,50));
    //设置字体
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(22);
    label->setFont(font);
    //设置颜色
    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::red);
    label->setPalette(palette);
    //显示文字
    QString str = QString("Level %1").arg(index);
    label->setText(str);

    //创建胜利后的图片
    QLabel * successlabel = new QLabel(this);
    QPixmap pix;
    pix.load(":/images/images/gamewin.png");
//    successlabel->setFixedSize(pix.width(),pix.height());
    successlabel->setGeometry(0,0,pix.width(),pix.height());
    successlabel->setPixmap(pix);
    successlabel->move((this->width()-pix.width())*0.5,-pix.height());


    //创建音效
    QSound* winsound = new QSound(":/images/images/4899.wav");

    //初始化胜利标志
    isWin = false;

    //初始化二维数组
    dataconfig data(NULL);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
              gameArray[i][j]=data.mData[this->index][i][j];
        }
    }



    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            //创建金币的背景图片
            QLabel * bg = new QLabel(this);
            bg->setGeometry(QRect(60+i*50,200+j*50,50,50));
            bg->setPixmap(QPixmap(":/images/images/boardNode.png"));

            //创建金币或者银币
            QString str;
            if(gameArray[i][j] == 1)
            {
                //金币
                str=":/images/images/coin01.png";
            }
            else
            {
                //银币
                str=":/images/images/coin09.png";
            }

            MyCoin * mycoin = new MyCoin(str);
            mycoin->setParent(this);
            mycoin->move(62+i*50,202+j*50);

            //硬币的有关信息
            mycoin->Posx = i;
            mycoin->Posy = j;
            mycoin->flag = gameArray[i][j];

            //记录 否则翻转周围硬币时 找不到周围硬币的对象
            coinBtn[i][j] = mycoin;

            //点击金币进行翻转
            connect(mycoin,&MyCoin::clicked,[=](){

                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                       coinBtn[i][j]->isAnimation = true; //执行翻转动作,动作完成前 禁用所有按钮
                    }
                }


//                if(!mycoin->isAnimation)   也可以通过重写硬币的鼠标按下事件
//                {
//                    mycoin->changeFlag();
//                    //同步维护内部二维数组的数据
//                    gameArray[i][j]=(gameArray[i][j]==0?1:0);
//                }

                mycoin->changeFlag();
                //同步维护内部二维数组的数据
                gameArray[i][j]=(gameArray[i][j]==0?1:0);


                //延时翻转周围的硬币
                QTimer::singleShot(300,this,[=](){
                    //翻转上侧
                    if(j-1>=0)
                    {
                      coinBtn[i][j-1]->changeFlag();
                      gameArray[i][j-1]=(gameArray[i][j-1]==0?1:0);
                    }
                    //翻转下侧
                    if(j+1<=3)
                    {
                      coinBtn[i][j+1]->changeFlag();
                      gameArray[i][j+1]=(gameArray[i][j+1]==0?1:0);
                    }
                    //翻转左侧
                    if(i-1>=0)
                    {
                      coinBtn[i-1][j]->changeFlag();
                      gameArray[i-1][j]=(gameArray[i-1][j]==0?1:0);
                    }
                    //翻转右侧
                    if(i+1<=3)
                    {
                      coinBtn[i+1][j]->changeFlag();
                      gameArray[i+1][j]=(gameArray[i+1][j]==0?1:0);
                    }

                    //执行完翻转 开启按钮
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                          coinBtn[i][j]->isAnimation = false;
                        }
                    }

                    //检测是否胜利
                    isWin = true;
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            if(coinBtn[i][j]->flag == 0)
                            {
                                isWin = false;
                                break;
                            }
                        }
                    }
                    if(isWin == true)
                    {

                        for(int i=0;i<4;i++)
                        {
                            for(int j=0;j<4;j++)
                            {
                                coinBtn[i][j]->isWin = true;
                            }
                        }

                        //显示胜利
                        winsound->play();
                        update();
                        QPropertyAnimation * animation = new QPropertyAnimation(successlabel,"geometry");
                        animation->setDuration(1000);
                        animation->setStartValue(QVariant(QRect(successlabel->x(),successlabel->y(),successlabel->width(),successlabel->height())));
                        animation->setEndValue(QVariant(QRect(successlabel->x(),successlabel->y()+150,successlabel->width(),successlabel->height())));
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();
                    }
                });
            });
        }
    }


}

void PlayScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制背景图片
    QPixmap pix;
    pix.load(":/images/images/beijing.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    if(!isWin)
    {
        //绘制标题
        pix.load(":/images/images/coin.png");
        //缩放图片
        pix = pix.scaled(pix.width()*0.6,pix.height()*0.6);
        //绘制
        painter.drawPixmap(10,30,pix);
    }


}




PlayScene::~PlayScene()
{
    delete ui;
}
