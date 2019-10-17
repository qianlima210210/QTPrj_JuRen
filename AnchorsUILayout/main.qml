import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm {
        anchors.fill: parent
        color: "red";
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background'))
        }


        Rectangle {
            width: 300;
            height: 200;

            Rectangle {
                id: rect1;
                anchors.left: parent.left;
                anchors.leftMargin: 20;
                anchors.top: parent.top;
                anchors.topMargin: 20;
                width: 120;
                height: 120;
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#202020"; }
                    GradientStop { position: 1.0; color: "#A0A0A0"; }
                }
            }

            Rectangle {
                anchors.left: rect1.right;
                anchors.leftMargin: 20;
                anchors.top: rect1.top;
                width: 120;
                height: 120;
                rotation: 90;
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#202020"; }
                    GradientStop { position: 1.0; color: "#A0A0A0"; }
                }
            }
        }

        Rectangle {
            width: 300;
            height: 200;
            anchors.centerIn: parent;

            Rectangle {
                color: "blue";
                anchors.fill: parent;
                border.width: 6;
                border.color: "#888888";

                Rectangle {
                    anchors.centerIn: parent;
                    width: 120;
                    height: 120;
                    radius: 8;
                    border.width: 2;
                    border.color: "black";
                    antialiasing: true;
                    color: "red";
                }
            }
        }
    }


}
