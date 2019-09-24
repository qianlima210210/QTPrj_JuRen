#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include "chooselevelscene.h"

namespace Ui {
    class MainScreen;
}

class MainScreen : public QMainWindow
{
private:
    ChooseLevelScene *chooseLevelScene;

    Q_OBJECT
signals:

public slots:

public:
    explicit MainScreen(QWidget *parent = 0);
    ~MainScreen();

    void paintEvent(QPaintEvent *event);
    void configMainScreen();

private:
    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_H
