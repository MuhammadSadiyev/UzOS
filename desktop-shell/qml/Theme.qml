import QtQuick

pragma Singleton

QtObject {
    readonly property color bgDarkest: "#0e1621"
    readonly property color bgSidebar: "#0e1621"
    readonly property color bgDrawer: "#17212b"
    readonly property color bgSurface: "#242f3d"
    readonly property color bgSurfaceHover: "#2b394a"
    readonly property color bgActive: "#2b5278"

    readonly property color accent: "#2481cc"
    readonly property color accentBright: "#3390ec"
    readonly property color accentGlow: Qt.rgba(0.2, 0.56, 0.92, 0.35)

    readonly property color green: "#4fae4e"
    readonly property color red: "#e53935"
    readonly property color yellow: "#f5a623"

    readonly property color textPrimary: "#ffffff"
    readonly property color textSecondary: "#7f91a4"
    readonly property color textMuted: "#5e7082"

    readonly property color border: Qt.rgba(1, 1, 1, 0.08)
    readonly property color borderActive: Qt.rgba(0.2, 0.56, 0.92, 0.5)

    readonly property int radiusSm: 8
    readonly property int radiusMd: 12
    readonly property int radiusLg: 16
    readonly property int radiusPill: 9999

    readonly property string fontSans: "Inter, Roboto, sans-serif"
    readonly property string fontMono: "JetBrains Mono, Fira Code, monospace"
}
