//Need to lower some depdencies version for Qt to work
import QtQuick 2.9
import QtQuick.Window 2.0
import QtQuick.Controls 1.5
import com.STELS.Publisher 1.0


Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Dashboard")

    Component.onCompleted: {
        btnStart.enabled = true
        btnStart2.enabled = true
    }

    Publisher {
        id:pub

    }


    Column {
        id: column
        width: 434
        height: 62
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10

        Label {
            id: lblStatus
            text: "Publisher & Subscriber"
        }



        Row {
            id: row
            width: 200
            height: 400
            spacing: 10

            Button {
                id: btnStart
                text: qsTr("Publish 1")
                onClicked: pub.publishdMsg_btn_1()

            }

            Button {
                id: btnStart2
                text: qsTr("Publish 2")
                onClicked: pub.publishdMsg_btn_2()

            }


        }
    }
}
