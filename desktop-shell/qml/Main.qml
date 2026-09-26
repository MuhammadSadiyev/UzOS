import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    id: appWindow
    visible: true
    width: 1280
    height: 800
    title: "UzOS Desktop — Telegram UI Edition"
    color: Theme.bgDarkest

    // Background Gradient
    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: Theme.bgDarkest }
            GradientStop { position: 0.7; color: "#0b121a" }
            GradientStop { position: 1.0; color: "#080d14" }
        }
    }

    // Top Status Bar
    TopBar {
        id: topBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        z: 100
        onToggleQuickSettings: {
            quickSettings.visible = !quickSettings.visible
        }
    }

    // Main Content
    Item {
        anchors.top: topBar.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        Row {
            anchors.fill: parent
            spacing: 0

            // Far-Left Pill Sidebar
            Sidebar {
                id: sidebar
                height: parent.height
                onToggleDrawer: {
                    drawer.visible = !drawer.visible
                }
            }

            // Telegram-style Task Drawer
            Drawer {
                id: drawer
                height: parent.height
                visible: true
            }

            // Desktop Canvas
            Item {
                id: workspace
                width: parent.width - sidebar.width - (drawer.visible ? drawer.width : 0)
                height: parent.height

                Text {
                    anchors.centerIn: parent
                    text: "UzOS"
                    font.pixelSize: 72
                    font.weight: Font.Black
                    color: Qt.rgba(1, 1, 1, 0.03)
                }

                NotificationCenter {
                    anchors.top: parent.top
                    anchors.topMargin: 16
                    anchors.right: parent.right
                    anchors.rightMargin: 16
                    z: 90
                }
            }
        }
    }

    // Quick Settings Popover
    QuickSettings {
        id: quickSettings
        anchors.top: topBar.bottom
        anchors.topMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 16
        visible: false
        z: 200
    }
}
