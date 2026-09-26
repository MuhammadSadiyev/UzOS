#!/usr/bin/env bash
# ==============================================================================
# UzOS Desktop Session Startup
# ==============================================================================
set -e

export XDG_CURRENT_DESKTOP=UzOS
export XDG_SESSION_DESKTOP=UzOS
export QT_QPA_PLATFORM="wayland;xcb"
export QT_QPA_PLATFORMTHEME=gtk3
export GDK_BACKEND=wayland,x11
export MOZ_ENABLE_WAYLAND=1

# Start PipeWire low-latency sound system
if command -v pipewire &>/dev/null; then
    pipewire &
    wireplumber &
fi

# Launch Wayland window manager and native Telegram desktop shell
if command -v labwc &>/dev/null; then
    labwc -s /usr/bin/uzos-shell
elif command -v wayfire &>/dev/null; then
    wayfire &
    exec /usr/bin/uzos-shell
else
    exec /usr/bin/uzos-shell
fi
