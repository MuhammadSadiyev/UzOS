/* ==============================================================================
   UzOS Cloud (WebOS) — Settings Application
   100% Authentic Telegram Web Settings Screen with Vector SVGs, Zero Emojis
   ============================================================================== */

import { ICONS } from '../os/icons.js';

export class SettingsApp {
  constructor(container, setWallpaperCallback, vfs, showToast) {
    this.container = container;
    this.setWallpaper = setWallpaperCallback;
    this.vfs = vfs;
    this.showToast = showToast;

    this.render();
  }

  render() {
    this.container.innerHTML = `
      <div class="app-settings">
        <div class="settings-container">
          
          <!-- Profile Card (Telegram Web Style) -->
          <div class="settings-profile-card">
            <div class="settings-avatar">UZ</div>
            <div class="settings-profile-info">
              <div class="settings-name">
                <span>UzOS Foydalanuvchisi</span>
                ${ICONS.verified}
              </div>
              <div class="settings-username">@uzos_cloud • Administrator</div>
              <div class="settings-bio">O'zbekiston Milliy Raqamli Suveren Bulut Tizimi</div>
            </div>
          </div>

          <!-- Group 1: Kiber-Xavfsizlik -->
          <div class="settings-group">
            <div class="settings-group-header">Kiber-Xavfsizlik va Maxfiylik</div>
            <div class="settings-card">
              
              <div class="settings-row">
                <div class="settings-row-left">
                  <div class="settings-icon-bubble green">
                    ${ICONS.shield}
                  </div>
                  <div class="settings-row-text">
                    <span class="settings-row-title">Zero-Telemetry Qalqoni</span>
                    <span class="settings-row-desc">Xorijiy kuzatuv serverlariga so'rov: 0 bayt</span>
                  </div>
                </div>
                <label class="tg-switch">
                  <input type="checkbox" id="set-zero-telemetry" checked />
                  <span class="tg-slider"></span>
                </label>
              </div>

              <div class="settings-row">
                <div class="settings-row-left">
                  <div class="settings-icon-bubble blue">
                    ${ICONS.shield}
                  </div>
                  <div class="settings-row-text">
                    <span class="settings-row-title">Mahalliy AES-256 Shifrlash</span>
                    <span class="settings-row-desc">Barcha VFS fayllari brauzer ichida shifrlanadi</span>
                  </div>
                </div>
                <label class="tg-switch">
                  <input type="checkbox" id="set-local-encrypt" checked />
                  <span class="tg-slider"></span>
                </label>
              </div>

              <div class="settings-row">
                <div class="settings-row-left">
                  <div class="settings-icon-bubble purple">
                    ${ICONS.globe}
                  </div>
                  <div class="settings-row-text">
                    <span class="settings-row-title">OneID.uz Identifikatsiyasi</span>
                    <span class="settings-row-desc">Milliy identifikatsiya tizimi bog'langan</span>
                  </div>
                </div>
                <span style="color:#4ade80; font-size:12px; font-weight:700; letter-spacing:0.5px;">FAOL</span>
              </div>

            </div>
          </div>

          <!-- Group 2: Interfeys va Rang Mavzulari -->
          <div class="settings-group">
            <div class="settings-group-header">Interfeys va Mavzular</div>
            <div class="settings-card">
              
              <div class="settings-row">
                <div class="settings-row-left">
                  <div class="settings-icon-bubble blue">
                    ${ICONS.palette}
                  </div>
                  <div class="settings-row-text">
                    <span class="settings-row-title">Telegram Rang Mavzusi</span>
                    <span class="settings-row-desc">Dark (Standart), Blue (Klassik), Night (Chuqur)</span>
                  </div>
                </div>
                <select id="theme-selector" style="background:var(--tg-bg-search); color:#fff; border:1px solid var(--tg-border); padding:7px 14px; border-radius:10px; outline:none; font-size:13px; cursor:pointer;">
                  <option value="dark">Telegram Dark</option>
                  <option value="blue">Telegram Blue</option>
                  <option value="night">Telegram Night</option>
                </select>
              </div>

              <div class="settings-row">
                <div class="settings-row-left">
                  <div class="settings-icon-bubble orange">
                    ${ICONS.globe}
                  </div>
                  <div class="settings-row-text">
                    <span class="settings-row-title">Tizim Tili</span>
                    <span class="settings-row-desc">O'zbek tili (Lotin alifbosi)</span>
                  </div>
                </div>
                <span style="color:var(--tg-blue); font-size:13px; font-weight:600;">O'zbekcha</span>
              </div>

            </div>
          </div>

          <!-- Group 3: Xotira va Kesh -->
          <div class="settings-group">
            <div class="settings-group-header">Xotira, Zaxira va Tiklash (VFS)</div>
            <div class="settings-card">
              
              <div class="settings-row">
                <div class="settings-row-left">
                  <div class="settings-icon-bubble purple">
                    ${ICONS.folder}
                  </div>
                  <div class="settings-row-text">
                    <span class="settings-row-title">VFS Xotira Sarfi</span>
                    <span class="settings-row-desc">Brauzer lokal xotirasida (Offline) saqlanmoqda</span>
                  </div>
                </div>
                <span id="vfs-size-badge" style="color:var(--tg-blue); font-size:13px; font-weight:600;">~${Math.max(1, Math.round(JSON.stringify(this.vfs.fs || {}).length / 1024))} KB</span>
              </div>

              <!-- Backup & Restore Actions -->
              <div class="settings-row" style="flex-wrap:wrap; gap:10px;">
                <div class="settings-row-left">
                  <div class="settings-icon-bubble blue">
                    ${ICONS.newFile}
                  </div>
                  <div class="settings-row-text">
                    <span class="settings-row-title">Tizim Zaxira Nusxasi (Backup)</span>
                    <span class="settings-row-desc">Barcha fayllar va sozlamalarni .json faylga saqlash</span>
                  </div>
                </div>
                <div style="display:flex; gap:8px;">
                  <button id="btn-export-backup" style="background:#2481cc; color:#fff; border:none; padding:7px 14px; border-radius:8px; font-size:12.5px; font-weight:600; cursor:pointer; display:flex; align-items:center; gap:6px;">
                    <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M21 15v4a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2v-4m4-5 5 5 5-5m-5 5V3"/></svg>
                    <span>Yuklab Olish</span>
                  </button>
                  <label style="background:rgba(255,255,255,0.08); color:#fff; border:1px solid var(--tg-border); padding:7px 14px; border-radius:8px; font-size:12.5px; font-weight:600; cursor:pointer; display:flex; align-items:center; gap:6px;">
                    <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M21 15v4a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2v-4m-7-9-5-5-5 5m5-5v12"/></svg>
                    <span>Tiklash</span>
                    <input type="file" id="input-restore-backup" accept=".json" style="display:none;" />
                  </label>
                </div>
              </div>

              <div style="padding:14px 18px;">
                <button class="settings-btn-danger" id="btn-reset-vfs" style="display:flex;align-items:center;justify-content:center;gap:8px;cursor:pointer;width:100%;">
                  <span>Barcha VFS Xotirani Tozalash (Factory Reset)</span>
                </button>
              </div>

            </div>
          </div>

          <!-- Group 4: Tizim Haqida -->
          <div class="settings-group">
            <div class="settings-group-header">Tizim Haqida</div>
            <div class="settings-card">
              
              <div class="settings-row">
                <span style="color:var(--tg-text-secondary);">Tizim Versiyasi</span>
                <span style="font-weight:600; color:#fff;">UzOS Cloud 2.0.4 WebOS</span>
              </div>
              <div class="settings-row">
                <span style="color:var(--tg-text-secondary);">Dasturiy Huquqlar</span>
                <span style="color:var(--tg-blue); font-weight:600;">100% Ochiq Kodli (MIT)</span>
              </div>
              <div class="settings-row">
                <span style="color:var(--tg-text-secondary);">Yadro Tizimi</span>
                <span style="font-weight:600; color:#fff;">Web Hypervisor VFS</span>
              </div>

            </div>
          </div>

        </div>
      </div>
    `;

    this.bindEvents();
  }

  bindEvents() {
    const themeSelect = this.container.querySelector('#theme-selector');
    themeSelect.addEventListener('change', (e) => {
      document.body.className = '';
      if (e.target.value === 'blue') {
        document.body.classList.add('tg-theme-blue');
      } else if (e.target.value === 'night') {
        document.body.classList.add('tg-theme-night');
      }
      if (this.showToast) this.showToast("Mavzu O'zgartirildi", `${e.target.selectedOptions[0].text} faollashtirildi.`, ICONS.palette);
    });

    const zeroTelemetryToggle = this.container.querySelector('#set-zero-telemetry');
    zeroTelemetryToggle.addEventListener('change', (e) => {
      if (this.showToast) {
        this.showToast(
          "Zero-Telemetry",
          e.target.checked ? "Tashqi kuzatuv to'liq bloklandi." : "Ogohlantirish: Qalqon o'chirildi.",
          ICONS.shield
        );
      }
    });

    // Export Backup
    const btnExport = this.container.querySelector('#btn-export-backup');
    if (btnExport) {
      btnExport.addEventListener('click', () => {
        try {
          const backup = this.vfs.exportBackup();
          const jsonStr = JSON.stringify(backup, null, 2);
          const blob = new Blob([jsonStr], { type: 'application/json' });
          const url = URL.createObjectURL(blob);
          const a = document.createElement('a');
          const dateStr = new Date().toISOString().split('T')[0];
          a.href = url;
          a.download = `uzos_backup_${dateStr}.json`;
          a.click();
          URL.revokeObjectURL(url);
          if (this.showToast) {
            this.showToast("Zaxira Nusxasi Saqlandi", "uzos_backup.json fayli yuklab olindi.", ICONS.newFile);
          }
        } catch (err) {
          alert("Zaxirani yuklab olishda xatolik: " + err.message);
        }
      });
    }

    // Restore Backup
    const inputRestore = this.container.querySelector('#input-restore-backup');
    if (inputRestore) {
      inputRestore.addEventListener('change', (e) => {
        const file = e.target.files && e.target.files[0];
        if (!file) return;

        const reader = new FileReader();
        reader.onload = (evt) => {
          try {
            const data = JSON.parse(evt.target.result);
            this.vfs.importBackup(data);
            if (this.showToast) {
              this.showToast("Tizim Tiklandi", "Fayllar va sozlamalar muvaffaqiyatli tiklandi. Qayta ishga tushirilmoqda...", ICONS.refresh);
            }
            setTimeout(() => location.reload(), 1200);
          } catch (err) {
            alert("Zaxira faylini tiklashda xatolik: " + err.message);
          }
        };
        reader.readAsText(file);
      });
    }

    const resetBtn = this.container.querySelector('#btn-reset-vfs');
    resetBtn.addEventListener('click', () => {
      if (confirm("Diqqat! Barcha shaxsiy fayllar va VFS kesh tozalanadi. Davom etasizmi?")) {
        localStorage.clear();
        if (this.showToast) this.showToast("Kesh Tozalandi", "Tizim birlamchi holatga qaytarildi.", ICONS.refresh);
        setTimeout(() => location.reload(), 1000);
      }
    });
  }
}
