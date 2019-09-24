#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "coinbtn.h"

namespace Ui {
class PlayScene;
}

class PlayScene : public QMainWindow
{
private:
    int levelNum;
    int gameArray[4][4] = {};
    CoinBtn *coinBtns[4][4] = {};
    bool isWin = false;

    Q_OBJECT
signals:
    void backBtnClickedInPlayScene();

public:
    explicit PlayScene(QWidget *parent = 0);
    PlayScene(int levelNum, QWidget *parent = NULL);
    ~PlayScene();

    void configPlayScene();
    void paintEvent(QPaintEvent *event);

private:
    Ui::PlayScene *ui;
};

#endif // PLAYSCENE_H
