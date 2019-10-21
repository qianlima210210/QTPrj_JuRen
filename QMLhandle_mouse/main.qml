import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

Window {
    id: rootWindow;
    visible: true
    width: 640
    height: 480
    title: qsTr("鼠标事件处理")
    color: "yellow"

    MouseArea {
        anchors.fill: parent;
        acceptedButtons: Qt.LeftButton | Qt.RightButton;
        onClicked: {
            if(mouse.button === Qt.RightButton){
                Qt.quit();
            }else if(mouse.button === Qt.LeftButton){
                rootWindow.color = Qt.rgba((mouse.x % 255) / 255.0, (mouse.y % 255) / 255.0, 0.6, 1.0);
                mouse.accepted = true;
            }
        }

        onDoubleClicked: {
            color = "pink"
        }

    }


}























