import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

//    Button {
//            anchors.centerIn: parent;

//            //display: AbstractButton.IconOnly //只显示icon(QtQuick.Controls 2.3)
//            //display: AbstractButton.TextOnly //只显示文字
//            //display: AbstractButton.TextUnderIcon //文字在icon下边
//            //display: AbstractButton.TextBesideIcon  //文字在icon旁边
//            iconSource: "qrc:/images/images/coin02.png" //icon路径

//            text: "Quit";
//            onClicked: Qt.quit();
//        }

//    Button {
//        text: "Quit";
//        anchors.centerIn: parent;
//        style: ButtonStyle {
//            background: Rectangle {
//                implicitWidth: 70;
//                implicitHeight: 25;
//                border.width: control.pressed ? 2 : 1;
//                border.color: (control.hovered || control.pressed) ? "green" : "#888888";
//            }
//        }
//    }


    Component{
        id: btnStyle;
        ButtonStyle {
            background: Rectangle {
                implicitWidth: 70;
                implicitHeight: 25;
                color: "#DDDDDD";
                border.width: control.pressed ? 2 : 1;
                border.color: (control.hovered || control.pressed) ? "green" : "#888888";
            }
        }
    }

    Button {
        id: openButton;
        text: "Open";
        anchors.left: parent.left;
        anchors.leftMargin: 10;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 10;
        style: btnStyle;
    }

    Button {
        text: "Quit";
        anchors.left: openButton.right;
        anchors.leftMargin: 6;
        anchors.bottom: openButton.bottom;
        style: btnStyle;
    }

}
