# ==============================================================================
# UzOS — O'zbekiston Milliy Operatsion Tizimi (Build Makefile)
# ==============================================================================

.PHONY: all shell iso clean help

help:
	@echo "UzOS Yig'ish Buyruqlari:"
	@echo "  make shell     - Native C++/Qt6 Telegram UI ish stolini kompilyatsiya qilish"
	@echo "  make iso       - Bootable uzos-24.04-desktop-amd64.iso faylini yaratish"
	@echo "  make clean     - Vaqtinchalik build fayllarini tozalash"

shell:
	@echo "[UzOS] C++/Qt6 Telegram Desktop Shell kompilyatsiya qilinmoqda..."
	mkdir -p desktop-shell/build
	cd desktop-shell/build && cmake .. && make -j$$(nproc 2>/dev/null || echo 4)
	@echo "[UzOS] desktop-shell/build/uzos-shell tayyor!"

iso:
	@echo "[UzOS] Bootable ISO yig'ilmoqda..."
	sudo bash scripts/build_iso.sh

clean:
	rm -rf desktop-shell/build output/ build/

