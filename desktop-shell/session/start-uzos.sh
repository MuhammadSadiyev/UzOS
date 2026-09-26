#!/usr/bin/env bash
set -e

export XDG_CURRENT_DESKTOP=UzOS
export XDG_SESSION_DESKTOP=UzOS
export QT_QPA_PLATFORM="wayland;xcb"
export GDK_BACKEND=wayland,x11
export MOZ_ENABLE_WAYLAND=1

# Audio
if command -v pipewire &>/dev/null; then
    pipewire &
    wireplumber &
fi

# Compositor (Labwc / Wayfire) or direct fallback
if command -v labwc &>/dev/null; then
    labwc -s /usr/bin/uzos-shell
elif command -v wayfire &>/dev/null; then
    wayfire &
    exec /usr/bin/uzos-shell
else
    exec /usr/bin/uzos-shell
fi
