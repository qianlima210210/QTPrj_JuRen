#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QDebug>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "mycoin.h"
#include <QPropertyAnimation>
#include <QSound>

namespace Ui {
class PlayScene;
}

class PlayScene : public QMainWindow
{
    Q_OBJECT

public:

    PlayScene(int index);
   void paintEvent(QPaintEvent *);

    ~PlayScene();


private:
    Ui::PlayScene *ui;
    //当前的关卡号
    int index;
    int gameArray[4][4];
    MyCoin * coinBtn[4][4];
    //胜利标志
    bool isWin;

signals:
    void playSceneBack();
public slots:
};

#endif // PLAYSCENE_H
