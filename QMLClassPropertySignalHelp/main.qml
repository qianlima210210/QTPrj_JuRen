import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("从 Qt Quick 头文件查看属性相关的信号")


    Text {
        id: text1;
        anchors.centerIn: parent;
        text: "Hello World!";
        color: "blue";
        font.pixelSize: 32;
    }

    Button {
        id: button1;
        text: "A Button";
        anchors.top: text1.bottom;
        anchors.topMargin: 4;
    }

    Image {
        id: image1;
    }

    Component.onCompleted: {
        console.log("QML Text\'s C++ type - ", text1);
        console.log("QML Button\'s C++ type - ", button1);
        console.log("QML Image\'s C++ type - ", image1);
    }

}
