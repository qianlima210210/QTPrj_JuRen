import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Connections的使用")

    /*
        一个 Connections 对象创建一个到 QML 信号的连接。
        前面两节在处理 QML 信号时，都是用 on{Signal} 这种就地代码块的方式。
        而在有些情况下，这样的处理并不方便。比如：
        你需要将多个对象连接到同一个 QML 信号上
        你需要在发出信号的对象的作用域之外来建立连接
        发射信号的对象没有在 QML 中定义（可能是通过 C++ 导出的，这很常见）
        Connections 有一个属性名为 target ，它呢，指向发出信号的对象。
    */

    /*
    Button {
        id:quitBtn;
            text: "Quit";
            anchors.centerIn: parent;
            onClicked: {
                Qt.quit();
            }
        }

    Connections {
        target: quitBtn;
        onClicked: {
            Qt.quit();
        }
    }
    */

    Rectangle {
        width: 320;
        height: 240;
        color: "gray";
        anchors.fill: parent;

        Text {
            id: text1;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: parent.top;
            anchors.topMargin: 20;
            text: "Text One";
            color: "blue";
            font.pixelSize: 28;
        }

        Text {
            id: text2;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: text1.bottom;
            anchors.topMargin: 8;
            text: "Text Two";
            color: "blue";
            font.pixelSize: 28;
        }

        Button {
            id: changeButton;
            anchors.top: text2.bottom;
            anchors.topMargin: 8;
            anchors.horizontalCenter: parent.horizontalCenter;
            text: "Change";
        }

        Connections {
            target: changeButton;
            onClicked: {
                text1.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
                text2.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
            }
        }
    }

}
