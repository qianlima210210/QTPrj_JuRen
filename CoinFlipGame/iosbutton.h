#ifndef IOSBUTTON_H
#define IOSBUTTON_H

#include <QPushButton>

class IosButton : public QPushButton
{
private:
    QString normalImagePath;
    QString pressedImagePath;


    Q_OBJECT
public:
    explicit IosButton(QWidget *parent = 0);
    explicit IosButton(QWidget *parent, QString normalImagePath, QString pressedImagePath = QString(""));
    ~IosButton();

    void setBtnIcon(bool normal = true);//为按钮设置图标

    void animationDown();   //下落动画
    void animationUp();     //上抛动画

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // IOSBUTTON_H
