import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("倒计时程序")

    MainForm {
        anchors.fill: parent

        QtObject{
                id: attrs;
                property int counter;
                Component.onCompleted:{
                    attrs.counter = 10;
                }
            }

        Text {
                id: countShow;
                anchors.centerIn: parent;
                color: "blue";
                font.pixelSize: 40;
            }

        Timer {
                id: countDown;
                interval: 1000;
                repeat: true;
                triggeredOnStart: true;
                onTriggered:{
                    countShow.text = attrs.counter;
                    attrs.counter -= 1;
                    if(attrs.counter < 0)
                    {
                        countDown.stop();
                        countShow.text = "Clap Now!";
                        console.log("----")
                    }
                }
            }

        Button {
                id: startButton;
                anchors.top: countShow.bottom;
                anchors.topMargin: 20;
                anchors.horizontalCenter: countShow.horizontalCenter;
                text: "Start";
                onClicked: {
                    countDown.start();
                    if(attrs.counter === -1){
                        attrs.counter = 10;
                    }
                }
            }
    }
}
