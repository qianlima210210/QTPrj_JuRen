import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("缩放与旋转实例")

    Rectangle {
        width: 360;
        height: 360;
        focus: true;
        Rectangle {
            width: 100;
            height: 100;
            color: "blue";
            id: transformRect;
            anchors.centerIn: parent;
        }
        PinchArea {
            anchors.fill: parent
            pinch.maximumScale: 20;
            pinch.minimumScale: 0.2;
            pinch.minimumRotation: 0;
            pinch.maximumRotation: 90;
            pinch.target: transformRect;
        }
    }

}
