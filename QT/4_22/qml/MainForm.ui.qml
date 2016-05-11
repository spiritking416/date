import QtQuick 2.4
import QtQuick.Controls 1.4

Rectangle {
    property alias mouseArea: mouseArea

    width: 480
    height: 320

    color:"#121212"

    BusyIndicator{
        id:busy
        running:true
        anchors.centerIn: parent
        z:2
    }

    Text{
        id:stateLable1
        visible:false
        anchors.centerIn: parent
        z:3
    }

    Image{
        id:imageViewer
        //source:"753430.jpg";
        asynchronous:true
        cache:false
        anchors.fill:parent
        fillMode:Image.PreserveAspectFit
        onStateChanged: {
            if(imageViewer.status===Image.Loading){
                busy.running=true;
                stateLable1.visible=false;
            }
            else if(imageViewer.status===Image.Ready){
                busy.running=false;
            }
            else if(imageViewer.status===Image.Error){
                busy.running=false;
                stateLable1.visible=true;
                stateLable1.text="ERROR";
            }
        }
    }

    //Component.onCompleted: {
    //    imageViewer.source="http://img4.duitang.com/uploads/blog/201407/09/20140709125038_xC2KA.thumb.700_0.jpeg";
    //}
}
