import QtQuick
import QtQuick.Controls

Rectangle {
    id: root
    width: 64
    color: Theme.bgSidebar
    border.color: Theme.border
    border.width: 1

    signal toggleDrawer()
    property string currentFolder: "all"

    Column {
        anchors.top: parent.top
        anchors.topMargin: 12
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 12
        width: parent.width

        // UzOS Logo
        Rectangle {
            width: 44
            height: 44
            radius: Theme.radiusMd
            color: "transparent"
            anchors.horizontalCenter: parent.horizontalCenter

            Canvas {
                id: logoCanvas
                anchors.centerIn: parent
                width: 32
                height: 32
                onPaint: {
                    var ctx = getContext("2d");
                    ctx.reset();
                    ctx.fillStyle = Theme.accent;
                    ctx.beginPath();
                    ctx.moveTo(16, 4);
                    ctx.lineTo(28, 11);
                    ctx.lineTo(28, 25);
                    ctx.lineTo(16, 32);
                    ctx.lineTo(4, 25);
                    ctx.lineTo(4, 11);
                    ctx.closePath();
                    ctx.fill();

                    ctx.fillStyle = "#ffffff";
                    ctx.beginPath();
                    ctx.arc(16, 18, 4, 0, 2 * Math.PI);
                    ctx.fill();
                }
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: root.toggleDrawer()
            }
        }

        Rectangle {
            width: 32
            height: 1
            color: Theme.border
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // Folder pills
        Repeater {
            model: [
                { id: "all", icon: "⊞" },
                { id: "dev", icon: "</>" },
                { id: "files", icon: "📁" },
                { id: "store", icon: "🛍" }
            ]

            Rectangle {
                width: 44
                height: 44
                radius: Theme.radiusPill
                anchors.horizontalCenter: parent.horizontalCenter
                color: root.currentFolder === modelData.id ? Theme.accent : (pillHover.containsMouse ? Theme.bgSurface : "transparent")

                Text {
                    anchors.centerIn: parent
                    text: modelData.icon
                    font.pixelSize: 16
                    color: root.currentFolder === modelData.id ? "#ffffff" : Theme.textSecondary
                }

                MouseArea {
                    id: pillHover
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onClicked: root.currentFolder = modelData.id
                }
            }
        }
    }

    // Bottom Settings Button
    Rectangle {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 14
        anchors.horizontalCenter: parent.horizontalCenter
        width: 40
        height: 40
        radius: Theme.radiusPill
        color: setHover.containsMouse ? Theme.bgSurface : "transparent"

        Text {
            anchors.centerIn: parent
            text: "⚙"
            font.pixelSize: 18
            color: Theme.textSecondary
        }

        MouseArea {
            id: setHover
            anchors.fill: parent
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor
            onClicked: SystemManager.openSettings()
        }
    }
}
