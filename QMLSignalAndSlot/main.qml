import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("连接信号与槽")

    id: relay;

    signal messageReceived(string person, string notice);
    signal send();

    onSend: {
        console.log("Send clicked");
    }

    Component.onCompleted: {
        //将信号连接到槽
        relay.messageReceived.connect(sendToPost);
        relay.messageReceived.connect(sendToTelegraph);
        relay.messageReceived.connect(sendToEmail);

        //发送信号
        relay.messageReceived("Tom", "Happy Birthday");

        //将信号连接到信号
        mousearea.clicked.connect(send);
    }

    function sendToPost(person, notice) {
        console.log("Sending to post: " + person + ", " + notice);
    }
    function sendToTelegraph(person, notice) {
        console.log("Sending to telegraph: " + person + ", " + notice);
    }
    function sendToEmail(person, notice) {
        console.log("Sending to email: " + person + ", " + notice);
    }

    MouseArea {
        id: mousearea;
        anchors.fill: parent;
        onClicked: console.log("MouseArea clicked");
    }

}
