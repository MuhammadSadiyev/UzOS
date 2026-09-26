import QtQuick
import QtQuick.Controls

Rectangle {
    id: root
    height: 44
    color: Theme.bgDarkest
    border.color: Theme.border
    border.width: 1

    signal toggleQuickSettings()

    Row {
        anchors.left: parent.left
        anchors.leftMargin: 16
        anchors.verticalCenter: parent.verticalCenter
        spacing: 12

        Text {
            text: "UzOS 24.04 LTS"
            color: Theme.textPrimary
            font.pixelSize: 13
            font.weight: Font.DemiBold
            anchors.verticalCenter: parent.verticalCenter
        }

        // Zero Telemetry Badge
        Rectangle {
            height: 22
            width: zeroText.contentWidth + 20
            radius: Theme.radiusPill
            color: Qt.rgba(0.31, 0.68, 0.31, 0.15)
            border.color: Qt.rgba(0.31, 0.68, 0.31, 0.4)
            anchors.verticalCenter: parent.verticalCenter

            Row {
                anchors.centerIn: parent
                spacing: 6
                Rectangle {
                    width: 6
                    height: 6
                    radius: 3
                    color: Theme.green
                    anchors.verticalCenter: parent.verticalCenter
                }
                Text {
                    id: zeroText
                    text: "Zero Telemetry"
                    color: Theme.green
                    font.pixelSize: 11
                    font.weight: Font.Medium
                }
            }
        }

        // zRAM Badge
        Rectangle {
            height: 22
            width: zramText.contentWidth + 16
            radius: Theme.radiusPill
            color: Qt.rgba(0.14, 0.51, 0.8, 0.15)
            border.color: Qt.rgba(0.14, 0.51, 0.8, 0.4)
            anchors.verticalCenter: parent.verticalCenter

            Text {
                id: zramText
                anchors.centerIn: parent
                text: "zRAM: 100% zstd (" + SystemManager.ramUsedMb + " MB)"
                color: Theme.accentBright
                font.pixelSize: 11
                font.weight: Font.Medium
            }
        }
    }

    // Right Controls
    Row {
        anchors.right: parent.right
        anchors.rightMargin: 16
        anchors.verticalCenter: parent.verticalCenter
        spacing: 12

        // Quick Settings Button
        Rectangle {
            height: 28
            width: 90
            radius: Theme.radiusSm
            color: qHover.containsMouse ? Theme.bgSurface : "transparent"
            anchors.verticalCenter: parent.verticalCenter

            Row {
                anchors.centerIn: parent
                spacing: 6
                Text { text: "🎛"; font.pixelSize: 13; anchors.verticalCenter: parent.verticalCenter }
                Text { text: "Boshqaruv"; color: Theme.textSecondary; font.pixelSize: 12; anchors.verticalCenter: parent.verticalCenter }
            }

            MouseArea {
                id: qHover
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: root.toggleQuickSettings()
            }
        }

        // Clock
        Text {
            text: SystemManager.currentTime
            color: Theme.textPrimary
            font.pixelSize: 13
            font.weight: Font.DemiBold
            font.family: Theme.fontMono
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
