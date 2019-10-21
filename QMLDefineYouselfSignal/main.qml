import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("自定义信号与使用")

    Text {
            id: coloredText;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: parent.top;
            anchors.topMargin: 4;
            text: "Hello World!";
            font.pixelSize: 32;
        }

    Component {
            id: colorComponent;
            Rectangle {
                id: colorPicker;
                width: 50;
                height: 30;
                signal colorPicked(color clr);//自定义信号
                MouseArea {
                    anchors.fill: parent
                    onPressed: colorPicker.colorPicked(colorPicker.color);//信号的发射，就是方法的调用
                }
            }
        }

    //Loader 是专门用来动态创建组件的
    Loader{
           id: redLoader;
           anchors.left: parent.left;
           anchors.leftMargin: 4;
           anchors.bottom: parent.bottom;
           anchors.bottomMargin: 4;
           sourceComponent: colorComponent;
           onLoaded:{
               item.color = "red";//这里的item就是Component里的Rectangle
               console.log("redLoader onLoaded");
           }
       }

       Loader{
           id: blueLoader;
           anchors.left: redLoader.right;
           anchors.leftMargin: 4;
           anchors.bottom: parent.bottom;
           anchors.bottomMargin: 4;
           sourceComponent: colorComponent;
           onLoaded:{
               item.color = "blue";
               console.log("blueLoader onLoaded");
           }
       }

       Connections {
               target: blueLoader.item;
               onColorPicked:{
                   coloredText.color = clr;
               }
           }

       Connections {
           target: redLoader.item;
           onColorPicked: {
               coloredText.color = clr;
           }
       }

}
