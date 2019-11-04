#ifndef COLORMAKER_H
#define COLORMAKER_H

#include <QObject>
#include <QColor>
#include <QDateTime>
#include <QTimerEvent>

class ColorMaker : public QObject
{
    Q_OBJECT
    Q_ENUMS(GenerateAlgorithm)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QColor timeColor READ timeColor)


public:
    explicit ColorMaker(QObject *parent = 0);
    ~ColorMaker();

    enum GenerateAlgorithm{
            RandomRGB,
            RandomRed,
            RandomGreen,
            RandomBlue,
            LinearIncrease
        };

    QColor color() const;
    void setColor(const QColor & color);
    QColor timeColor() const;



    //让一个类能够进入 Qt 强大的元对象系统（meta-object system）中，只有使用元对象系统，
    //一个类的某些方法或属性才可能通过字符串形式的名字来调用，才具有了在 QML 中访问的基础条件。
    // Q_INVOKABLE 宏来修饰，就可以让该方法被元对象系统调用
    Q_INVOKABLE GenerateAlgorithm algorithm() const;
    Q_INVOKABLE void setAlgorithm(GenerateAlgorithm algorithm);

signals:
    void colorChanged(const QColor & color);
    void currentTime(const QString &strTime);

public slots:
    void start();
    void stop();

protected:
    void timerEvent(QTimerEvent *e);

private:
    GenerateAlgorithm m_algorithm;
    QColor m_currentColor;
    int m_nColorTimer;


};

#endif // COLORMAKER_H
