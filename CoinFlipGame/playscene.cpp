#include "playscene.h"
#include "ui_playscene.h"
#include "iosbutton.h"
#include "dataconfig.h"
#include <QPropertyAnimation>
#include <QAction>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QFont>
#include <QSound>
#include <QDebug>

PlayScene::PlayScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayScene)
{
    ui->setupUi(this);
}

//C++不能像java那样构造函数之间互相调用,java的构造函数只用来初始化，C++则隐藏了创建对象。
PlayScene::PlayScene(int levelNum, QWidget *parent):levelNum(levelNum),
    QMainWindow(parent), ui(new Ui::PlayScene)
{
    ui->setupUi(this);
    configPlayScene();
}

PlayScene::~PlayScene()
{
    delete ui;
}

void PlayScene::configPlayScene()
{
    //窗口固定大小
   setFixedSize(320, 588);

   //设置窗口左上角图标
   setWindowIcon(QIcon(":/images/start.png"));

   //设置窗口标题
   setWindowTitle(QStringLiteral("翻金币"));

   connect(ui->actionquit, &QAction::triggered, this, [=](){
      close();
   });

   //添加返回按钮
   IosButton *backBtn = new IosButton(ui->widget_2, QString(":/images/returnBeforeStyle.png"), QString(":/images/returnAfterStyle.png"));
   int backBtnX = ui->widget_2->width() - backBtn->width();
   int backBtnY =0;

   backBtn->move(backBtnX, backBtnY);
   connect(backBtn, &IosButton::clicked, [=]{
       emit backBtnClickedInPlayScene();
   });

   //添加关卡序号
   QLabel *label = new QLabel(ui->widget_2);
    label->setGeometry(0, 0, ui->widget_2->width() - backBtn->width(), ui->widget_2->height());
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
   QString str = QString("Level %1").arg(levelNum + 1);
   label->setText(str);

   //获取本关初始币状态
   dataconfig config;
   for(int i = 0; i < 4; i++){
       for(int j = 0; j < 4; j++){
          gameArray[i][j] = config.mData[levelNum + 1][i][j];
       }
   }

   //添加胜利图片
   QPixmap pixmap(QString(":/images/gamewin.png"));
   QLabel *winLab = new QLabel(this);
   winLab->setGeometry(width() * 0.5 - pixmap.width() * 0.5,
                       this->centralWidget()->height(),
                       pixmap.width(), pixmap.height());
   winLab->setPixmap(pixmap);
   winLab->setHidden(true);


   //添加金币背景图及初始币按钮
   int margin = (ui->middleWidget->width() - 45 * 4) / 2;
   for(int i = 0; i < 4; i++){
       for(int j = 0; j < 4; j++){
            QLabel *label = new QLabel(ui->middleWidget);

            label->setGeometry(0, 0, 45, 45);
            label->move(margin + j * (45 + 0), margin + i * (45 + 0));

            //将QLabel设置自定义样式
            label->setStyleSheet("QLabel{border-width: 1px 1px 1px 1px;"
                                 "border-style: solid;"
                                 "border-color: rgb(255,0,0);"
                                 "background-color: rgba(213, 213, 213, 125);"
                                 "border-radius:5px;}");

            //添加硬币
            QString path;
            if(gameArray[i][j] == 1)
            {
                path = ":/images/coin01.png";
            }else
            {
                path = ":/images/coin09.png";
            }
            CoinBtn *btn = new CoinBtn(ui->middleWidget, path);
            coinBtns[i][j] = btn;
            btn->move(margin + j * (45 + 0), margin + i * (45 + 0));

            btn->row = i;
            btn->colum = j;
            btn->flag = gameArray[i][j];

            connect(btn, &CoinBtn::clicked, this, [=](){
                //先判断是否胜利
                if(isWin){
                    return;
                }

                //反转自己
                btn->changeFlag();
                gameArray[i][j] =  gameArray[i][j] == 1 ? 0 : 1;
                //反转周围硬币
                if(i - 1  >= 0)//反转上面的硬币
                {
                    CoinBtn *up = coinBtns[i-1][j];
                    up->changeFlag();
                    gameArray[i - 1][j] =  gameArray[i - 1][j] == 1 ? 0 : 1;
                }

                if(i + 1  <= 3)//反转下面的硬币
                {
                    CoinBtn *up = coinBtns[i+1][j];
                    up->changeFlag();
                    gameArray[i + 1][j] =  gameArray[i + 1][j] == 1 ? 0 : 1;
                }

                if(j - 1 >= 0)//反转left的硬币
                {
                    CoinBtn *up = coinBtns[i][j-1];
                    up->changeFlag();
                    gameArray[i][j-1] =  gameArray[i][j-1] == 1 ? 0 : 1;
                }

                if(j + 1  <= 3)//反转right的硬币
                {
                    CoinBtn *up = coinBtns[i][j+1];
                    up->changeFlag();
                    gameArray[i][j+1] =  gameArray[i][j+1] == 1 ? 0 : 1;
                }

                //判断是否win
                for(int i = 0; i < 4; i++){
                    for(int j = 0; j < 4; j++){
                        if(gameArray[i][j+1] == 0){
                            return;
                        }
                    }
                }

                isWin = true;

                //显示胜利图片
                //创建动画对象
                winLab->setHidden(false);
                QPropertyAnimation *animation = new QPropertyAnimation(winLab, "geometry");
                //设置动画持续时间
                animation->setDuration(200);
                //起始位置
                animation->setStartValue(QVariant(QRect(winLab->x(), winLab->y(), winLab->width(), winLab->height())));
                //结束位置
                animation->setEndValue(QVariant(QRect(winLab->x(), winLab->y() + 15, winLab->width(), winLab->height())));

                //设置弹跳曲线
                animation->setEasingCurve(QEasingCurve::OutBounce);
                //启动动画
                animation->start();

                //播放胜利音频
                QSound *winSound = new QSound(":/images/10910.wav", this);
                winSound->play();

            });




       }
   }

}

void PlayScene::paintEvent(QPaintEvent *event)
{
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





