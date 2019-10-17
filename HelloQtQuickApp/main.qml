import QtQuick 2.6
import QtQuick.Window 2.2


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("哈皮 Qt Quick App")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }

    Rectangle {
            width: 360;
            height: 360;
            color: "yellow";
            rotation:90;//不设置，则是垂直方向
            gradient: Gradient {
                    GradientStop { position: 0.0; color: "#ff0000"; }
                    GradientStop { position: 0.33; color: "blue"; }
                    GradientStop { position: 1.0; color: "#FFFFFF"; }
                }

            border.color: "#808080";
            border.width: 2;
            radius: 12;
            anchors.centerIn: parent;
        Text {
            id: textId;
            text: qsTr("文本");
            color: "red";
            anchors.centerIn: parent;
            // prints "1 0 0 1"
            Component.onCompleted: console.log(color.r, color.g, color.b, color.a);

        }
        MouseArea {
            anchors.fill: parent;
            onClicked: {
                Qt.quit();
            }
        }
    }
}































