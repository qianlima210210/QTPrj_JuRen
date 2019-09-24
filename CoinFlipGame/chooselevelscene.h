#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"

namespace Ui {
class ChooseLevelScene;
}

class ChooseLevelScene : public QMainWindow
{
private:
     PlayScene *playScene = NULL;

    Q_OBJECT
signals:
    void backBtnClickedInChooseLevelScene();

public slots:

public:
    explicit ChooseLevelScene(QWidget *parent = 0);
    ~ChooseLevelScene();

    void configChooseLevelScene();
    void paintEvent(QPaintEvent *event);

private:
    Ui::ChooseLevelScene *ui;
};

#endif // CHOOSELEVELSCENE_H
