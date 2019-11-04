#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "colormaker.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<ColorMaker>("an.qt.myCPP", 1, 0, "ColorMaker");//注册 QML 类型

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
