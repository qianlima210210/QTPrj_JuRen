import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

Window {
    visible: true
    width: 640
    height: 480
    color: "#121212";
    title: qsTr("Image的使用")

    //简单的显示一张本地图片或网络图片
    /*
    Image {
        //source: "qrc:/images/images/coin02.png"
        source: "http://pic.pc6.com/up/2013-7/2013726153358.png";
        asynchronous: true;
    }
    */

    /*
      显示网络上的图片，在下载和加载前显示一个转圈圈的 Loading 图标，
      图片加载成功后隐藏 Loading 图标，如果加载出错，则显示一个简单的错误消息
    */

    BusyIndicator {
            id: busy;
            running: true;
            anchors.centerIn: parent;
            // Item 除了 x 、 y 属性，其实还有一个 z 属性，用来指定图元在场景中的 Z 序。
            // z 属性的类型是 real ，数值越小，图元就越垫底（远离我们），数值越大，图元就越靠近我们。
            z: 2;
        }

        Label {
            id: stateLabel;
            visible: true;
            color: "white";
            text: "加载中..."
            anchors.top: busy.bottom;
            anchors.topMargin: 20;
            anchors.horizontalCenter: busy.horizontalCenter;
            anchors.horizontalCenterOffset: 100 //水平中心的偏移量
            z: 3;
        }

        Image {
                id: imageViewer;
                asynchronous: true;
                cache: false;
                anchors.fill: parent;
                fillMode: Image.PreserveAspectFit;
                onStatusChanged: {
                    if (imageViewer.status === Image.Loading) {
                        busy.running = true;
                        stateLabel.visible = true;
                    }
                    else if(imageViewer.status === Image.Ready){
                        busy.running = false;
                        stateLabel.visible = false;
                    }
                    else if(imageViewer.status === Image.Error){
                        busy.running = false;
                        stateLabel.visible = true;
                        stateLabel.text = "ERROR";
                    }
                }
            }

        //Emitted after the object has been instantiated.
        Component.onCompleted: {
                imageViewer.source = "http://02imgmini.eastday.com/mobile/20181121/20181121141918_2523d88a00e8d41309349f8e887715f0_1_mwpm_03200403.jpg";
            }

}
