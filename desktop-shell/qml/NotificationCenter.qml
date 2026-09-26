import QtQuick
import QtQuick.Controls

Item {
    id: root
    width: 320
    height: 400

    ListModel {
        id: notifModel
        ListElement {
            sender: "UzOS Xavfsizlik"
            message: "UzOS 24.04 LTS ishga tushdi. Barcha telemetriya bloklangan."
            timestamp: "hozir"
        }
    }

    Connections {
        target: SystemManager
        function onNotificationReceived(sender, message, timestamp) {
            notifModel.insert(0, { "sender": sender, "message": message, "timestamp": timestamp });
        }
    }

    Column {
        anchors.fill: parent
        spacing: 10

        Repeater {
            model: notifModel
            delegate: Rectangle {
                width: 320
                height: 72
                radius: Theme.radiusMd
                color: Theme.bgSurface
                border.color: Theme.border
                border.width: 1

                Row {
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 10

                    Rectangle {
                        width: 36
                        height: 36
                        radius: Theme.radiusPill
                        color: Theme.accent
                        anchors.verticalCenter: parent.verticalCenter
                        Text {
                            anchors.centerIn: parent
                            text: "✈"
                            color: "#ffffff"
                            font.pixelSize: 16
                        }
                    }

                    Column {
                        width: parent.width - 56
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 2

                        Row {
                            width: parent.width
                            Text {
                                text: model.sender
                                color: Theme.accentBright
                                font.pixelSize: 12
                                font.weight: Font.DemiBold
                                width: parent.width - 40
                                elide: Text.ElideRight
                            }
                            Text {
                                text: model.timestamp
                                color: Theme.textMuted
                                font.pixelSize: 10
                            }
                        }

                        Text {
                            text: model.message
                            color: Theme.textPrimary
                            font.pixelSize: 11.5
                            wrapMode: Text.WordWrap
                            width: parent.width
                            maximumLineCount: 2
                            elide: Text.ElideRight
                        }
                    }
                }
            }
        }
    }
}
