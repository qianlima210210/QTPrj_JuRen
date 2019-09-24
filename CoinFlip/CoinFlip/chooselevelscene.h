#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "playscene.h"

namespace Ui {
class ChooseLevelScene;
}

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseLevelScene(QWidget *parent = 0);

    //重写 paintEvent 函数
    void paintEvent(QPaintEvent *);

    ~ChooseLevelScene();

private:
    Ui::ChooseLevelScene *ui;
    PlayScene * playscene;
signals:
    void chooseSceneBack();
public slots:
};

#endif // CHOOSELEVELSCENE_H
