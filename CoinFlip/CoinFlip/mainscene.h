#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QPainter>
#include <QDebug>
#include "mypushbutton.h"
#include "chooselevelscene.h"
#include <QTimer>
#include <QSound>

namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    ~MainScene();
    void paintEvent(QPaintEvent *);

private:
    Ui::MainScene *ui;
    ChooseLevelScene * chooseScene;
};

#endif // MAINSCENE_H
