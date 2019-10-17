import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm {
        anchors.fill: parent

//        Text {
//                width: 150;
//                height: 100;
//                wrapMode: Text.WordWrap;
//                font.bold: true;
//                font.pixelSize: 24;
//                font.underline: true;
//                text: "Hello Blue Text";
//                anchors.centerIn: parent;
//                color: "blue";
//            }

//        Rectangle {
//            width: 300;
//            height: 200;
//            Text {
//                width: 150;
//                height: 100;
//                wrapMode: Text.WordWrap;
//                font.bold: true;
//                font.pixelSize: 24;
//                font.underline: true;
//                text: "Hello Blue <font color=\"blue\">Text</font>";
//                anchors.centerIn: parent;
//            }
//        }

        Text {
                id: normal;
                anchors.left: parent.left;
                anchors.leftMargin: 20;
                anchors.top: parent.top;
                anchors.topMargin: 20;
                font.pointSize: 24;
                text: "Normal Text";
            }
            Text {
                id: raised;
                anchors.left: normal.left;
                anchors.top: normal.bottom;
                anchors.topMargin: 4;
                font.pointSize: 24;
                text: "Raised Text";
                style: Text.Raised;
                styleColor: "#AAAAAA" ;
            }
            Text {
                id: outline;
                anchors.left: normal.left;
                anchors.top: raised.bottom;
                anchors.topMargin: 4;
                font.pointSize: 24;
                text: "Outline Text";
                style: Text.Outline;
                styleColor: "red";
            }
            Text {
                anchors.left: normal.left;
                anchors.top: outline.bottom;
                anchors.topMargin: 4;
                font.pointSize: 24;
                text: "Sunken Text";
                style: Text.Sunken;
                styleColor: "#A00000";
            }

    }
}
