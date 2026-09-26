#!/bin/sh
# ==============================================================================
# UzOS Default Environment Configuration
# Telegram UI, Wayland & GTK/Qt Integration
# ==============================================================================
export XDG_CURRENT_DESKTOP=UzOS
export XDG_SESSION_DESKTOP=UzOS
export XDG_DATA_DIRS="/usr/local/share:/usr/share:/var/lib/flatpak/exports/share:$HOME/.local/share/flatpak/exports/share"
export QT_QPA_PLATFORM="wayland;xcb"
export QT_QPA_PLATFORMTHEME=gtk3
export MOZ_ENABLE_WAYLAND=1
export GDK_BACKEND="wayland,x11"
