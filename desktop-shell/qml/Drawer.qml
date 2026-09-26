import QtQuick
import QtQuick.Controls

Rectangle {
    id: root
    width: 280
    color: Theme.bgDrawer
    border.color: Theme.border
    border.width: 1

    Column {
        anchors.fill: parent
        spacing: 0

        // Search Bar
        Rectangle {
            width: parent.width
            height: 52
            color: "transparent"

            Rectangle {
                anchors.centerIn: parent
                width: parent.width - 24
                height: 36
                radius: Theme.radiusPill
                color: Theme.bgSurface
                border.color: searchInput.activeFocus ? Theme.accent : "transparent"
                border.width: 1

                Row {
                    anchors.fill: parent
                    anchors.leftMargin: 12
                    anchors.rightMargin: 12
                    spacing: 8
                    verticalAlignment: Qt.AlignVCenter

                    Text {
                        text: "🔍"
                        font.pixelSize: 12
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    TextInput {
                        id: searchInput
                        width: parent.width - 60
                        color: Theme.textPrimary
                        font.pixelSize: 13
                        anchors.verticalCenter: parent.verticalCenter
                        clip: true

                        Text {
                            text: "Qidirish... (Ctrl+K)"
                            color: Theme.textMuted
                            font.pixelSize: 13
                            visible: !searchInput.text && !searchInput.activeFocus
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }
                }
            }
        }

        Rectangle {
            width: parent.width
            height: 1
            color: Theme.border
        }

        Text {
            text: "ILOVALAR VA OCHIQ OYNALAR"
            font.pixelSize: 11
            font.weight: Font.DemiBold
            color: Theme.accentBright
            leftPadding: 16
            topPadding: 12
            bottomPadding: 6
        }

        ListView {
            id: taskListView
            width: parent.width
            height: parent.height - 100
            clip: true
            model: [
                { name: "UzOS Terminal", desc: "Low-latency yadro", time: "hozir", cmd: "terminal", iconBg: "#111827", iconText: ">_" },
                { name: "UzOS Fayllar", desc: "Xotira boshqaruvi", time: "10:48", cmd: "files", iconBg: "#f5a623", iconText: "📁" },
                { name: "Telegram Desktop", desc: "Native Qt6 xabarchi", time: "10:40", cmd: "telegram-desktop", iconBg: "#2481cc", iconText: "✈" },
                { name: "UzOS Sozlamalar", desc: "Zero-telemetriya va zRAM", time: "10:30", cmd: "settings", iconBg: "#64748b", iconText: "⚙" },
                { name: "Dasturlar Markazi", desc: "Flathub ilovalar do'koni", time: "09:15", cmd: "store", iconBg: "#10b981", iconText: "🛍" }
            ]

            delegate: Rectangle {
                width: taskListView.width
                height: 60
                color: itemHover.containsMouse ? Theme.bgSurfaceHover : "transparent"

                Row {
                    anchors.fill: parent
                    anchors.leftMargin: 12
                    anchors.rightMargin: 12
                    spacing: 12
                    verticalAlignment: Qt.AlignVCenter

                    Rectangle {
                        width: 40
                        height: 40
                        radius: Theme.radiusPill
                        color: modelData.iconBg
                        anchors.verticalCenter: parent.verticalCenter

                        Text {
                            anchors.centerIn: parent
                            text: modelData.iconText
                            color: "#ffffff"
                            font.pixelSize: 16
                            font.bold: true
                        }
                    }

                    Column {
                        width: parent.width - 64
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 2

                        Row {
                            width: parent.width
                            Text {
                                text: modelData.name
                                color: Theme.textPrimary
                                font.pixelSize: 13
                                font.weight: Font.Medium
                                elide: Text.ElideRight
                                width: parent.width - 50
                            }
                            Text {
                                text: modelData.time
                                color: Theme.textMuted
                                font.pixelSize: 11
                            }
                        }

                        Text {
                            text: modelData.desc
                            color: Theme.textSecondary
                            font.pixelSize: 12
                            elide: Text.ElideRight
                            width: parent.width
                        }
                    }
                }

                MouseArea {
                    id: itemHover
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        if (modelData.cmd === "terminal") SystemManager.openTerminal();
                        else if (modelData.cmd === "files") SystemManager.openFileManager();
                        else if (modelData.cmd === "settings") SystemManager.openSettings();
                        else SystemManager.launchApp(modelData.cmd);
                    }
                }
            }
        }
    }
}
