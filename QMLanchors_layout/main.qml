import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("anchors(锚)布局、行布局、列布局、表格布局、流布局、嵌套布局")

    //anchors(锚)布局
    /*
    Rectangle {
        anchors.fill: parent;
        color: "#EEEEEE";
        id: rootItem;

        Text {
            id: centerText;
            text: "A Single Text.";
            anchors.centerIn: parent;
            font.pixelSize: 24;
            font.bold: true;
        }

        function setTextColor(clr){
            centerText.color = clr;
        }

        //color pickers look at parent's top
        ColorPicker {
            id: topColor1;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.top: parent.top;
            anchors.topMargin: 4;
            onColorPicked: rootItem.setTextColor(clr);
        }

        ColorPicker {
            id: topColor2;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            anchors.left: topColor1.right;
            anchors.leftMargin: 4;
            anchors.top: topColor1.top;
            onColorPicked: rootItem.setTextColor(clr);
        }

        ColorPicker {
            id: topColor3;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            anchors.right: parent.right;
            anchors.rightMargin: 4;
            anchors.top: parent.top;
            anchors.topMargin: 4;
            onColorPicked: rootItem.setTextColor(clr);
        }

        ColorPicker {
            id: topColor4;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            anchors.right: topColor3.left;
            anchors.rightMargin: 4;
            anchors.top: topColor3.top;
            onColorPicked: rootItem.setTextColor(clr);
        }

        //color pickers sit on parent's bottom
        ColorPicker {
            id: bottomColor1;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;
            onColorPicked: rootItem.setTextColor(clr);
        }

        ColorPicker {
            id: bottomColor2;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            anchors.left: bottomColor1.right;
            anchors.leftMargin: 4;
            anchors.bottom: bottomColor1.bottom;
            onColorPicked: rootItem.setTextColor(clr);
        }

        ColorPicker {
            id: bottomColor3;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            anchors.right: parent.right;
            anchors.rightMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;
            onColorPicked: rootItem.setTextColor(clr);
        }

        ColorPicker {
            id: bottomColor4;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            anchors.right: bottomColor3.left;
            anchors.rightMargin: 4;
            anchors.bottom: bottomColor3.bottom;
            onColorPicked: rootItem.setTextColor(clr);
        }

        //align to parent's left && vertical center
        ColorPicker {
            id: leftVCenterColor;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.verticalCenter: parent.verticalCenter;
            onColorPicked: rootItem.setTextColor(clr);
        }

        //align to parent's right && vertical center
        ColorPicker {
            id: rightVCenterColor;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            anchors.right: parent.right;
            anchors.rightMargin: 4;
            anchors.verticalCenter: parent.verticalCenter;
            onColorPicked: rootItem.setTextColor(clr);
        }

        //align to parent's top && horizontal center
        ColorPicker {
            id: topHCenterColor;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            anchors.top: parent.top;
            anchors.topMargin: 4;
            anchors.horizontalCenter: parent.horizontalCenter;
            onColorPicked: rootItem.setTextColor(clr);
        }

        //align to parent's bottom && horizontal center
        ColorPicker {
            id: bottomHCenterColor;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;
            anchors.horizontalCenter: parent.horizontalCenter;
            onColorPicked: rootItem.setTextColor(clr);
        }
    }
    */

    //行布局
    /*
    Rectangle {
        anchors.fill: parent;
        color: "#EEEEEE";
        id: rootItem;

        Text {
            id: centerText;
            text: "A Single Text.";
            anchors.centerIn: parent;
            font.pixelSize: 24;
            font.bold: true;
        }

        function setTextColor(clr){
            centerText.color = clr;
        }

        Row {
            //Row也是Item，它里面放置的Item你可以不管(?)，但是Row自身需要设置位置。
            anchors.left: parent.left;
            anchors.leftMargin: 10;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 10;
            spacing: 20;

            ColorPicker {
                width: 200;
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: rootItem.setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: rootItem.setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: rootItem.setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: rootItem.setTextColor(clr);
            }
        }
    }
    */

    //列布局
    /*
    Rectangle {
        anchors.fill: parent;
        color: "#EEEEEE";
        id: rootItem;

        Text {
            id: centerText;
            text: "A Single Text.";
            anchors.centerIn: parent;
            font.pixelSize: 24;
            font.bold: true;
        }

        function setTextColor(clr){
            centerText.color = clr;
        }

        Column {
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;
            spacing: 4;

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }
        }
    }
    */

    //表格布局
    /*
    Rectangle {
        anchors.fill: parent;
        color: "#EEEEEE";
        id: rootItem;

        Text {
            id: centerText;
            text: "A Single Text.";
            anchors.centerIn: parent;
            font.pixelSize: 24;
            font.bold: true;
        }

        function setTextColor(clr){
            centerText.color = clr;
        }

        Grid {
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;
            flow: Grid.TopToBottom;
            layoutDirection: Grid.RightToLeft;
            horizontalItemAlignment:Grid.AlignLeft;
            verticalItemAlignment:Grid.AlignTop;
            rows: 3;
            columns: 3;
            rowSpacing: 4;
            columnSpacing: 4;

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }
        }
    }
    */

    //流布局
    /*
    Rectangle {
        anchors.fill: parent;
        color: "#EEEEEE";
        id: rootItem;

        Text {
            id: centerText;
            text: "A Single Text.";
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: parent.top;
            font.pixelSize: 24;
            font.bold: true;
        }

        function setTextColor(clr){
            centerText.color = clr;
        }

        Flow {
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;
            anchors.right: parent.right;
            anchors.rightMargin: 4;
            spacing: 4;

            ColorPicker {
                width: 80;
                height: 20;
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                width: 100;
                height: 40;
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                width: 80;
                height: 25;
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                width: 35;
                height: 35;
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                width: 20;
                height: 80;
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                onColorPicked: setTextColor(clr);
            }
        }
    }
    */

    //嵌套布局
    Rectangle {
        width: 360;
        height: 240;
        color: "#EEEEEE";
        id: rootItem;

        Text {
            id: centerText;
            text: "A Single Text.";
            anchors.centerIn: parent;
            font.pixelSize: 24;
            font.bold: true;
        }

        function setTextColor(clr){
            centerText.color = clr;
        }

        Row {
            anchors.left: parent.left;
            anchors.leftMargin: 4;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 4;
            spacing: 4;


            Column {
                spacing: 4;
                ColorPicker {
                    color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                    onColorPicked: setTextColor(clr);
                }

                ColorPicker {
                    color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                    onColorPicked: setTextColor(clr);
                }
            }

            Column {
                spacing: 4;
                ColorPicker {
                    color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                    onColorPicked: setTextColor(clr);
                }

                ColorPicker {
                    color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                    onColorPicked: setTextColor(clr);
                }
            }

            Column {
                spacing: 4;
                ColorPicker {
                    color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                    onColorPicked: setTextColor(clr);
                }

                ColorPicker {
                    color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
                    onColorPicked: setTextColor(clr);
                }
            }
        }
    }

}
