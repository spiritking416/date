import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2

Window {
    id: window1
    visible: true;
    width:600;
    height:480;
    minimumWidth: 480;
    minimumHeight: 380;

    BusyIndicator{
        id:busy;
        running:false;
        anchors.centerIn: parent;
        x:2;
    }

    Text {
        id: stateLable1;
        visible:false;
        anchors.centerIn: parent;
        x:3;
    }

    Button{
        id:openFile;
        text:"Open";
        anchors.left: parent.left;
        anchors.leftMargin: 8;
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        style:ButtonStyle{
            background: Rectangle{
                implicitWidth: 70;
                implicitHeight: 25;
                color:control.hovered ? "#c0c0c0" : "#a0a0a0";
                border.color: (control.hovered || control.pressed) ? "green" : "#888888";
            }
        }
        onClicked: FileDialog.open();
        z:4;
    }
}
