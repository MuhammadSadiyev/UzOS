import QtQuick
import QtQuick.Controls

Rectangle {
    id: root
    width: 280
    height: 240
    radius: Theme.radiusMd
    color: Theme.bgSurface
    border.color: Theme.border
    border.width: 1

    Column {
        anchors.fill: parent
        anchors.margins: 14
        spacing: 12

        Text {
            text: "Tezkor Boshqaruv Markazi"
            font.pixelSize: 13
            font.weight: Font.DemiBold
            color: Theme.accentBright
        }

        Grid {
            columns: 2
            spacing: 8
            width: parent.width

            Repeater {
                model: [
                    { title: "📶 Wi-Fi", sub: "UzOS_5G", active: true },
                    { title: "ᛒ Bluetooth", sub: "Faol", active: true },
                    { title: "🛡 Zero Spy", sub: "100% Blok", active: true },
                    { title: "⚡ Turbo zRAM", sub: "zstd Faol", active: true }
                ]

                Rectangle {
                    width: (parent.width - 8) / 2
                    height: 52
                    radius: Theme.radiusSm
                    color: modelData.active ? Theme.accent : Theme.bgDarkest

                    Column {
                        anchors.centerIn: parent
                        spacing: 2
                        Text {
                            text: modelData.title
                            color: "#ffffff"
                            font.pixelSize: 12
                            font.weight: Font.Medium
                        }
                        Text {
                            text: modelData.sub
                            color: Qt.rgba(1, 1, 1, 0.75)
                            font.pixelSize: 10
                        }
                    }
                }
            }
        }

        Row {
            width: parent.width
            spacing: 8

            Rectangle {
                width: (parent.width - 8) / 2
                height: 32
                radius: Theme.radiusSm
                color: Theme.bgDarkest
                border.color: Theme.border

                Text {
                    anchors.centerIn: parent
                    text: "⟳ Qayta yuklash"
                    color: Theme.textSecondary
                    font.pixelSize: 11
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: SystemManager.reboot()
                }
            }

            Rectangle {
                width: (parent.width - 8) / 2
                height: 32
                radius: Theme.radiusSm
                color: Theme.red

                Text {
                    anchors.centerIn: parent
                    text: "⏻ O'chirish"
                    color: "#ffffff"
                    font.pixelSize: 11
                    font.bold: true
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: SystemManager.powerOff()
                }
            }
        }
    }
}
