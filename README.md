# UzOS — Al-Xorazmiy LTS 1.0 (Desktop Shell)

> **Milliy va zamonaviy operatsion tizim grafik muhiti (Desktop Shell)**  
> Rasmiy **Telegram Desktop C++ (`lib_ui`)** yadro arxitekturasi asosida qurilgan.

[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-blue.svg)](#)
[![Standard](https://img.shields.io/badge/C%2B%2B-20-brightgreen.svg)](#)
[![Toolkit](https://img.shields.io/badge/UI%20Engine-Telegram%20lib__ui-0088cc.svg)](#)
[![Qt](https://img.shields.io/badge/Framework-Qt%206.8.0-41cd52.svg)](#)
[![Compiler](https://img.shields.io/badge/Compiler-Clang%2022%20(LLVM--MinGW)-yellow.svg)](#)

---

## 🌟 Umumiy Ma'lumot

**UzOS Al-Xorazmiy LTS** — bu Telegram Desktop'ning rasmiy C++ grafika va animatsiyalar dvigateli (`lib_ui`, `lib_base`, `lib_rpl`, `lib_crl`) negizida yaratilgan yangi avlod ishchi stoli (Desktop Shell). 

Hech qanday soxta web-texnologiyalar yoki sekin ishlovchi HTML/CSS qatlamlarisiz, bevosita toza C++20 da yig'ilganligi sababli dastur kompyuter resurslarini deyarli sarflamaydi (RAM iste'moli: ~110 MB) va ultra-tezkor 60+ FPS kadr chastotasida ishlaydi.

---

## 🏛 Loyiha Arxitekturasi (Enterprise Structure)

```
UzOS/
├── .gitignore                   # Kompilyatsiya va kesh fayllarini inkor qilish
├── CMakeLists.txt               # Asosiy CMake yig'ish konfiguratsiyasi
├── README.md                    # Loyiha hujjatlari va yo'riqnoma
│
├── build_ui/                    # Kompilyatsiya natijalari va UzOS_TelegramUI.exe
│
├── generated/                   # Telegram uslub va emojilarining C++ kodlari
│   ├── emoji/                   # Telegram rasmiy emojilar xaritasi
│   └── styles/                  # Generated palette.cpp, style_widgets.cpp va h.k.
│
├── src/                         # UzOS dasturiy ta'minotining asosiy manba kodlari
│   ├── apps/                    # Asosiy ilovalar
│   │   ├── UzTerminal.h/.cpp    # Bash 5.2.21 terminali (neofetch, help, ls...)
│   │   ├── UzFiles.h/.cpp       # Telegram Shared Media uslubidagi fayl menejeri
│   │   └── UzSettings.h/.cpp    # Tizim boshqaruv paneli va chekbokslar
│   │
│   ├── UiIntegration.h/.cpp     # Telegram UI reaktiv hodisalari bilan integratsiya
│   ├── UzWindow.h/.cpp          # Suzuvchi darchalar tizimi (Drag & Drop, tugmalar)
│   ├── UzDesktopView.h/.cpp     # Asosiy ishchi stol konteyneri va fon
│   ├── UzTaskbar.h/.cpp         # Pastki vazifalar paneli (Dock) va jonli soat
│   ├── UzAppLauncher.h/.cpp     # Start menyusi va qidiruv tizimi
│   ├── crl_on_main_stubs.cpp    # Telegram asinxron oqimlar ko'prigi
│   └── main.cpp                 # Dastur kirish nuqtasi
│
├── tools/                       # Dasturchi asboblari va kod generatorlari
│   ├── codegen/                 # codegen_style.exe, codegen_emoji.exe
│   └── python/                  # Standart Python muhiti
│
└── tdesktop-dev/                # Telegram Desktop rasmiy yadro kutubxonalari
    └── Telegram/
        ├── lib_ui/              # Rasmiy vidjetlar (RoundButton, InputField, ScrollArea, Checkbox)
        ├── lib_base/            # Vaqt, xotira va algoritmik yordamchilar
        ├── lib_rpl/             # Reaktiv dasturlash (Reactive Programming Library)
        ├── lib_crl/             # Asinxron oqimlar (Common Run Library)
        └── ThirdParty/          # Zarur tashqi kutubxonalar (GSL, lz4, range-v3, xxHash)
```

---

## 🚀 Texnik Talablar va Qurish (Build)

### Talablar:
- **Kompilyator:** Clang 22+ (LLVM-MinGW UCRT x86_64)
- **Framework:** Qt 6.8.0 (Core, Gui, Widgets, Svg)
- **Build System:** CMake 3.20+ va Ninja

### Qurish buyruqlari:
```powershell
# 1. Build papkasiga o'tish
cd c:\Projects\UzOS\build_ui

# 2. Ninja orqali yig'ish
ninja

# 3. Ishga tushirish
.\UzOS_TelegramUI.exe
```

---

## 🎨 Asosiy Xususiyatlar

1. **Haqiqiy Telegram Komponentlari:**
   - `Ui::RoundButton` — bosgandagi ripple to'lqin animatsiyasi bilan.
   - `Ui::InputField` — shaffof fon, silliq kursor va xatosiz reaktiv hodisalar.
   - `Ui::Checkbox` — to'lqin animatsiyali reaktiv chekbokslar.
   - `Ui::ScrollArea` — elastik inersiyali Telegram skrollbari.
2. **Ko'p Darchali Tizim (UzWindow):**
   - Istalgan darchani sarlavhasidan ushlab erkin sudrash (Drag & Drop).
   - Minimallashtirish va yopish Telegram tugmalari.
3. **Interaktiv Terminal (UzTerminal):**
   - `neofetch`, `help`, `uname -a`, `free -m`, `date`, `whoami`, `ls`, `clear` kabi o'rnatilgan buyruqlar to'plami.
4. **Fayllar Boshqaruvchisi (UzFiles):**
   - Telegram'ning **Shared Media** dizaynida hujjatlar, rasmlar va dasturlarni toifalar bo'yicha ko'rish.

---

## 📄 Litsenziya

UzOS arxitekturasi ochiq kodli prinsiplar va GNU General Public License v3 talablariga mos ravishda ishlab chiqilgan.
