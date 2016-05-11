import QtQuick 2.4
import QtQuick.Window 2.2
import xd.api.read_data 1.0

Window {
    visible: true

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            Qt.quit();
        }
    }

    Text{
        text:"dfasdf"
    }
}
