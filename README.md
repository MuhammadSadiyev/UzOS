# UzOS — O'zbekiston Milliy Operatsion Tizimi

UzOS — Ubuntu 24.04 LTS (Noble Numbat) poydevorida qurilgan, 100% ochiq kodli, telemetriya va kuzatuvlardan xoli, **Telegram UI** uslubidagi zamonaviy milliy operatsion tizim.

---

## 📁 Repozitoriy Tuzilishi

* **`ubuntu-base/`** — Ubuntu 24.04.5 LTS rasmiy minimal poydevori:
  * `/etc/lsb-release` va `/usr/lib/os-release`: UzOS 24.04 LTS nomlanishi
  * `/etc/hosts`: Canonical va Windows telemetriya domenlari blokirovkasi (Zero-Telemetry)
  * `/etc/apt/preferences.d/nosnap.pref`: Sekin ishlovchi `snapd` demonlarini taqiqlash
  * `/etc/sysctl.d/99-uzos-performance.conf`: Past kechikishli yadro tezlik sozlamalari
  * `/etc/default/zram-tools`: zstd algoritmi bilan 100% RAM siqish (4GB RAM 8GB kabi ishlaydi)
* **`desktop-shell/`** — Native C++ va Qt6/QML da yozilgan maxsus **Telegram UI** ish stoli muhiti:
  * Telegram chat papkalari uslubidagi chap panel (`Sidebar.qml`)
  * Telegram chatlar ro'yxati shaklidagi vazifalar boshqaruvi (`Drawer.qml`)
  * Telegram bildirishnoma bulutlari va ohangi (`NotificationCenter.qml`)
  * Tezkor boshqaruv markazi (`QuickSettings.qml`)
* **`website/`** — UzOS rasmiy taqdimot veb-sayti.

---

## 🛠 Kompilyatsiya Qilish (Linux / WSL2)

```bash
# 1. Kerakli kutubxonalarni o'rnatish
sudo apt update && sudo apt install -y build-essential cmake qt6-base-dev qt6-declarative-dev

# 2. Telegram UI ish stolini kompilyatsiya qilish
make shell

# 3. Natija: desktop-shell/build/uzos-shell
```
