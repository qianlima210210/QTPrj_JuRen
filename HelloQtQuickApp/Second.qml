﻿import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("哈皮")

    Rectangle {
        width: 300;
        height: 200;
        Item {
            id: gradientGroup;
            Rectangle {
                x: 20;
                y: 20;
                width: 120;
                height: 120;
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#202020"; }
                    GradientStop { position: 1.0; color: "#A0A0A0"; }
                }
            }

            Rectangle {
                x: 160;
                y: 20;
                width: 120;
                height: 120;
                rotation: 90;
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#202020"; }
                    GradientStop { position: 1.0; color: "#A0A0A0"; }
                }
            }
        }

        Component.onCompleted: {
            console.log("visible children: " ,gradientGroup.visibleChildren.length);
            console.log("visible children: " ,gradientGroup.children.length);
            for(var i = 0; i < gradientGroup.children.length; i++){
                console.log("child " , i, " x = ", gradientGroup.children[i].x);
            }
        }
    }
}
