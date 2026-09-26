#!/usr/bin/env bash
# ==============================================================================
# UzOS 24.04 LTS — Bootable ISO Yig'ish Skripti
# ==============================================================================
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(dirname "$SCRIPT_DIR")"
ROOTFS_DIR="$ROOT_DIR/ubuntu-base/rootfs"
BUILD_DIR="$ROOT_DIR/build/iso"
OUTPUT_DIR="$ROOT_DIR/output"
ISO_NAME="uzos-24.04-desktop-amd64.iso"

echo "=========================================================="
echo " [UzOS] Bootable ISO yig'ish jarayoni boshlandi..."
echo "=========================================================="

if [ "$EUID" -ne 0 ]; then
  echo "Diqqat: Ushbu skriptni 'sudo' bilan ishga tushirish kerak!"
  exit 1
fi

mkdir -p "$BUILD_DIR/casper" "$BUILD_DIR/boot/grub" "$OUTPUT_DIR"

echo "[UzOS] GRUB menyusi sozlanmoqda..."
cat <<'EOF' > "$BUILD_DIR/boot/grub/grub.cfg"
set default=0
set timeout=5

insmod efi_gop
insmod font
insmod play

menuentry "UzOS 24.04 LTS (Zero-Telemetry & Telegram UI)" {
    set gfxpayload=keep
    linux /casper/vmlinuz boot=casper quiet splash --
    initrd /casper/initrd
}

menuentry "UzOS 24.04 LTS (Xavfsiz grafik rejim)" {
    set gfxpayload=keep
    linux /casper/vmlinuz boot=casper nomodeset quiet splash --
    initrd /casper/initrd
}
EOF

echo "[UzOS] Fayllar tizimi SquashFS formatida siqilmoqda (zstd)..."
rm -f "$BUILD_DIR/casper/filesystem.squashfs"
mksquashfs "$ROOTFS_DIR" "$BUILD_DIR/casper/filesystem.squashfs" \
  -comp zstd -Xcompression-level 19 \
  -e "boot/vmlinuz*" -e "boot/initrd.img*"

echo "[UzOS] Bootable gibrid ISO yaratilmoqda..."
grub-mkrescue -o "$OUTPUT_DIR/$ISO_NAME" "$BUILD_DIR"

echo "=========================================================="
echo " [UzOS] MUVAFFAQIShIYATLI YAKUNLANDI!"
echo " ISO fayli: $OUTPUT_DIR/$ISO_NAME"
echo "=========================================================="
