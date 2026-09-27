/* ==============================================================================
   UzOS Cloud (WebOS) — Settings Application
   100% Authentic Telegram Web Settings Screen
   ============================================================================== */

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
                <svg width="18" height="18" viewBox="0 0 16 16" fill="none">
                  <path d="M8 0L9.8 1.9L12.4 1.5L13.4 3.9L15.9 4.9L15.6 7.5L17.2 9.5L15.6 11.5L15.9 14.1L13.4 15.1L12.4 17.5L9.8 17.1L8 19L6.2 17.1L3.6 17.5L2.6 15.1L0.1 14.1L0.4 11.5L-1.2 9.5L0.4 7.5L0.1 4.9L2.6 3.9L3.6 1.5L6.2 1.9L8 0Z" transform="scale(0.8) translate(2, 0)" fill="#3390ec"/>
                  <path d="M4.5 8L6.8 10.3L11.5 5.5" stroke="white" stroke-width="1.8" stroke-linecap="round" stroke-linejoin="round"/>
                </svg>
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
                  <div class="settings-icon-bubble green">🛡️</div>
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
                  <div class="settings-icon-bubble blue">🔒</div>
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
                  <div class="settings-icon-bubble purple">ID</div>
                  <div class="settings-row-text">
                    <span class="settings-row-title">OneID.uz Identifikatsiyasi</span>
                    <span class="settings-row-desc">Milliy identifikatsiya tizimi bog'langan</span>
                  </div>
                </div>
                <span style="color:#4ade80; font-size:12.5px; font-weight:700;">FAOL</span>
              </div>

            </div>
          </div>

          <!-- Group 2: Interfeys va Rang Mavzulari -->
          <div class="settings-group">
            <div class="settings-group-header">Interfeys va Mavzular</div>
            <div class="settings-card">
              
              <div class="settings-row">
                <div class="settings-row-left">
                  <div class="settings-icon-bubble blue">🎨</div>
                  <div class="settings-row-text">
                    <span class="settings-row-title">Telegram Rang Mavzusi</span>
                    <span class="settings-row-desc">Dark (Asosiy), Blue (Klassik), Night (Chuqur)</span>
                  </div>
                </div>
                <select id="theme-selector" style="background:var(--tg-bg-search); color:#fff; border:1px solid var(--tg-border); padding:7px 14px; border-radius:10px; outline:none; font-size:13px;">
                  <option value="dark">Telegram Dark</option>
                  <option value="blue">Telegram Blue</option>
                  <option value="night">Telegram Night</option>
                </select>
              </div>

              <div class="settings-row">
                <div class="settings-row-left">
                  <div class="settings-icon-bubble orange">🇺🇿</div>
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
            <div class="settings-group-header">Xotira va Kesh (VFS)</div>
            <div class="settings-card">
              
              <div class="settings-row">
                <div class="settings-row-left">
                  <div class="settings-icon-bubble purple">💾</div>
                  <div class="settings-row-text">
                    <span class="settings-row-title">VFS Xotira Sarfi</span>
                    <span class="settings-row-desc">IndexedDB / LocalStorage orqali saqlanmoqda</span>
                  </div>
                </div>
                <span style="color:var(--tg-text-secondary); font-size:13px; font-weight:600;">~112 KB</span>
              </div>

              <div style="padding:16px 20px;">
                <button class="settings-btn-danger" id="btn-reset-vfs">
                  ⚠️ Barcha VFS Xotirani Tozalash (Factory Reset)
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
      if (this.showToast) this.showToast("Mavzu O'zgartirildi", `${e.target.selectedOptions[0].text} faollashtirildi.`, "🎨");
    });

    const zeroTelemetryToggle = this.container.querySelector('#set-zero-telemetry');
    zeroTelemetryToggle.addEventListener('change', (e) => {
      if (this.showToast) {
        this.showToast(
          "Zero-Telemetry",
          e.target.checked ? "Tashqi kuzatuv to'liq bloklandi." : "Ogohlantirish: Qalqon o'chirildi.",
          e.target.checked ? "🛡️" : "⚠️"
        );
      }
    });

    const resetBtn = this.container.querySelector('#btn-reset-vfs');
    resetBtn.addEventListener('click', () => {
      if (confirm("Diqqat! Barcha shaxsiy fayllar va VFS kesh tozalanadi. Davom etasizmi?")) {
        localStorage.clear();
        if (this.showToast) this.showToast("Kesh Tozalandi", "Tizim birlamchi holatga qaytarildi.", "✅");
        setTimeout(() => location.reload(), 1000);
      }
    });
  }
}
