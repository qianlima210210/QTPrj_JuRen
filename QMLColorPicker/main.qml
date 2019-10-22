import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("在单独文件中定义组件")

    Text {
            id: coloredText;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: parent.top;
            anchors.topMargin: 4;
            text: "Hello World!";
            font.pixelSize: 32;
        }

    function setTextColor(clr){
         coloredText.color = clr;
    }

    ColorPicker {
            id: redColor;
            color: "red";
            focus: true;
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;

            KeyNavigation.right: blueColor;
            KeyNavigation.tab: blueColor;
            onColorPicked:{
                coloredText.color = clr;
            }
        }

        ColorPicker {
            id: blueColor;
            color: "blue";
            anchors.left: redColor.right;
            anchors.leftMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;

            KeyNavigation.left: redColor;
            KeyNavigation.right: pinkColor;
            KeyNavigation.tab: pinkColor;
        }

        ColorPicker {
            id: pinkColor;
            color: "pink";
            anchors.left: blueColor.right;
            anchors.leftMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;

            KeyNavigation.left: blueColor;
            KeyNavigation.tab: redColor;
        }

        Component.onCompleted:{
            blueColor.colorPicked.connect(setTextColor);
            pinkColor.colorPicked.connect(setTextColor);
        }

}
