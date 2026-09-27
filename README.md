# UzOS Cloud — Milliy Suveren Bulut Ish Stoli (WebOS)

UzOS Cloud — brauzer ichida ishlovchi, 100% ochiq kodli, **Telegram Desktop / Web UI** uslubidagi zamonaviy milliy bulut ish stoli muhiti (WebOS Workspace).

Tizim foydalanuvchiga hech qanday o'rnatishsiz (Zero-Install), istalgan brauzer orqali to'liq ko'p oynali shaxsiy ish stoli, xavfsiz shifrlangan fayllar ombori, terminal va dasturlash studiyasini taqdim etadi.

---

## 🛡️ Asosiy Xususiyatlari va Kiberxavfsizlik

* **Telegram Desktop UI Dizayni** — 100% vektorli SVG piktogrammalar, Telegram Dark shisha (glassmorphism) interfeysi va ko'p oynali boshqaruv.
* **Xotira Yadro (VFS v2.0)** — Eskirgan 5 MB'lik `localStorage` o'rniga brauzerning **IndexedDB** ombori (50 GB+ sig'im) joriy etilgan.
* **W3C Web Crypto API (AES-GCM 256-bit)** — Barcha shaxsiy fayllar va papkalar diskka yozilishidan oldin apparat darajasida 256-bitli AES bilan shifrlanadi.
* **Web Terminal (xterm.js 5.5)** — Sanoat standarti terminal dvigateli: 256-rangli ANSI, Tab bilan buyruq va fayllarni avtoto'ldirish, buyruqlar tarixi va VFS bilan bog'langan fayl operatsiyalari (`ls`, `cd`, `cat`, `touch`, `mkdir`, `rm`, `echo >`, `crypto`, `vfs`, `matrix`).
* **Izolyatsiyalangan Sandbox** — Kod Muharririda yozilgan JavaScript skriptlari izolyatsiyalangan **Web Worker** ichida ishlaydi (DOM, kuki va xotiraga daxl qila olmaydi, 5 soniyalik cheksiz sikl to'xtatuvchisiga ega).
* **Vazifalar Menejeri (Task Manager)** — Real vaqtda CPU va RAM resurslari monitoringi, faol oynalar ro'yxati va `Ctrl + Shift + Esc` orqali tezkor chaqirish.
* **Zero-Knowledge E2EE Cloud Sync** — Shaxsiy fayllar bulutga yuborilishidan oldin mijozning o'zida shifrlanadi; server fayllar mazmunini o'qiy olmaydi.
* **PWA va Oflayn Rejim** — Service Worker orqali internet uzilganda ham to'liq oflayn ishlaydi.
* **100% Zero-Telemetry** — Tashqi kuzatuv, tahliliy skriptlar yoki ma'lumot uzatish umuman yo'q.

---

## 📁 Loyiha Tuzilishi

```text
UzOS/
├── css/
│   ├── apps.css            # Ilovalar (Terminal, Task Manager, Editor, Files) stillari
│   ├── desktop.css         # Ish stoli, oynalar, taskbar, dock va popuplar
│   └── telegram-ui.css     # Telegram ranglar palitrasi va tokenlar
├── js/
│   ├── apps/
│   │   ├── editor.js       # Kod muharriri (Web Worker Sandbox)
│   │   ├── files.js        # Fayllar boshqaruvi (VFS fayl menejeri)
│   │   ├── settings.js     # Tizim sozlamalari va zaxira nusxa
│   │   ├── taskmanager.js  # Vazifalar menejeri (Resurslar monitoringi)
│   │   └── terminal.js     # xterm.js POSIX Web Terminal
│   ├── os/
│   │   ├── context-menu.js # Ish stoli o'ng tugma kontekst menyusi
│   │   ├── icons.js        # Vektorli SVG piktogrammalar
│   │   ├── storage.js      # IndexedDB + AES-GCM 256 VFS xotira dvigateli
│   │   ├── taskbar.js      # Taskbar, soat va tezkor boshqaruv
│   │   └── window-manager.js # Ko'p oynali boshqaruv dvigateli
│   └── desktop-main.js     # WebOS boshqaruvchisi
├── functions/              # Cloudflare Pages Edge Serverless Functions
│   └── api/
│       ├── health.js       # Tizim holati tekshiruvi
│       ├── system/
│       │   └── metrics.js  # Server resurslari
│       ├── auth/
│       │   ├── oneid.js    # OneID.uz OAuth2 oqimi
│       │   └── me.js       # Sessiya ma'lumoti
│       └── vfs/
│           └── sync.js     # E2EE bulutli sinxronizatsiya
├── public/                 # Statik resurslar (PWA manifest, ikonkalar, _headers, _redirects)
├── index.html              # Bosh sahifa (Landing Page)
├── desktop.html            # WebOS ish stoli muhiti
├── server.js               # Node.js REST API va statik fayl serveri
├── wrangler.toml           # Cloudflare Pages / Workers konfiguratsiyasi
└── vite.config.js          # Vite yig'uvchi sozlamalari
```

---

## 💻 Mahalliy Ishga Tushirish (Local Development)

```bash
# 1. Kutubxonalarni o'rnatish
npm install

# 2. Vite orqali dasturchi rejimida ishga tushirish (Hot-Reload)
npm run dev

# 3. Yoki to'liq production serverni ishga tushirish:
npm run build
npm start
```
Brauzerda `http://localhost:8080/` yoki `http://localhost:8080/desktop.html` manzilini oching.

---

## ☁️ Cloudflare Pages ga Deploy Qilish Qo'llanmasi

Loyiha Cloudflare Pages uchun 100% moslab tayyorlangan (`_headers`, `_redirects`, `functions/api/`, `wrangler.toml`).

### 1-USUL: Wrangler CLI orqali (Eng tezkor va oson — 1 daqiqada)

Terminalda quyidagi buyruqni bering:

```bash
# 1. Loyihani yig'ish va Cloudflare ga yuborish
npm run deploy
```

*Agar Cloudflare hisobingizga hali kirmagan bo'lsangiz, terminal brauzerni ochadi va 1 marta tasdiqlashni so'raydi. Shundan so'ng tizim bir zumda `https://uzos.pages.dev` manziliga joylashtiriladi!*

---

### 2-USUL: Cloudflare Dashboard + GitHub orqali (Avtomatik CI/CD)

1. Loyihangizni GitHub repository'ingizga yuboring (`git push origin main`).
2. [dash.cloudflare.com](https://dash.cloudflare.com/) ga kiring.
3. Chap menyudan **Workers & Pages** -> **Create application** -> **Pages** -> **Connect to Git** ni tanlang.
4. GitHub hisobingizni ulab, `UzOS` omborini tanlang.
5. Sozlamalarni quyidagicha to'ldiring:
   * **Project name:** `uzos` (yoki xohlagan nomingiz)
   * **Production branch:** `main`
   * **Framework preset:** `Vite` (yoki `None`)
   * **Build command:** `npm run build`
   * **Build output directory:** `dist`
6. **Save and Deploy** tugmasini bosing!

> **Natija:** Cloudflare avtomatik ravishda bepul SSL sertifikati (`https://`), global CDN (300+ ma'lumot markazlari, jumladan Toshkent edge tuguni) va serverless `/api/...` funksiyalarini faollashtiradi.

---

## ⌨️ Asosiy Tugmalar (Hotkeys)

* **`Ctrl + Shift + Esc`** — Vazifalar Menejerini ochish (Task Manager);
* **`Alt + Tab`** — Oynalarni almashtirish (Windows uslubidagi HUD);
* **`Ctrl + Alt + T`** — Terminalni bir zumda ochish;
* **`Ctrl + Shift + E`** — Bulut Fayllarni ochish;
* **`Win + D` yoki `Alt + D`** — Barcha oynalarni kichraytirib, ish stolini ko'rsatish;
* **`Escape`** — Ochilgan popover, kontekst menyu va start menyuni yopish.

---

## 📜 Litsenziya

100% Ochiq Kodli — [MIT License](LICENSE).
Muallif: **Muhammad Sadiyev**.
