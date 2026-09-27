/* ==============================================================================
   UzOS Cloud (WebOS) — Settings (100% Authentic Telegram Settings Screen)
   ============================================================================== */

export class SettingsApp {
  constructor(container, onWallpaperChange, vfs, showNotification) {
    this.container = container;
    this.setWallpaper = onWallpaperChange;
    this.vfs = vfs;
    this.notify = showNotification;
    this.currentTab = 'profile';

    this.render();
  }

  render() {
    this.container.innerHTML = `
      <div class="app-settings">
        <!-- Settings Nav -->
        <div class="settings-nav">
          <div class="settings-nav-btn active" data-tab="profile">
            <span>👤</span> Profil & Tizim
          </div>
          <div class="settings-nav-btn" data-tab="wallpaper">
            <span>🖼</span> Fon Rasmlari
          </div>
          <div class="settings-nav-btn" data-tab="storage">
            <span>💾</span> Xotira & Reset
          </div>
        </div>

        <!-- Content Area -->
        <div class="settings-content" id="settings-content-area"></div>
      </div>
    `;

    this.contentEl = this.container.querySelector('#settings-content-area');
    this.bindEvents();
    this.renderTab(this.currentTab);
  }

  bindEvents() {
    this.container.querySelectorAll('.settings-nav-btn').forEach(btn => {
      btn.addEventListener('click', () => {
        this.container.querySelectorAll('.settings-nav-btn').forEach(b => b.classList.remove('active'));
        btn.classList.add('active');
        this.currentTab = btn.dataset.tab;
        this.renderTab(this.currentTab);
      });
    });
  }

  renderTab(tab) {
    if (tab === 'profile') {
      this.contentEl.innerHTML = `
        <!-- Telegram Profile Header -->
        <div style="display:flex; align-items:center; gap:16px; margin-bottom: 24px; padding: 12px 16px; background: var(--tg-surface-card); border-radius: 12px;">
          <div style="width: 54px; height: 54px; border-radius: 50%; background: linear-gradient(135deg, #2481cc 0%, #3390ec 100%); display:flex; align-items:center; justify-content:center; color:#fff; font-size:22px; font-weight:700;">
            UZ
          </div>
          <div>
            <div style="font-size:16px; font-weight:600; color:#fff; display:flex; align-items:center; gap:6px;">
              <span>UzOS Foydalanuvchisi</span>
              <span style="background:var(--tg-blue); font-size:10px; color:#fff; padding:1px 6px; border-radius:6px;">Admin</span>
            </div>
            <div style="font-size:12.5px; color:var(--tg-blue-bright); margin-top:2px;">@uzos_cloud • O'zbekiston</div>
          </div>
        </div>

        <!-- Telegram Grouped Section: System Specs -->
        <div style="font-size:12px; font-weight:600; color:var(--tg-theme-section-header-text-color); margin-bottom:8px; text-transform:uppercase; letter-spacing:0.5px; padding-left:4px;">
          Tizim Xususiyatlari
        </div>

        <div class="tg-section-card">
          <div class="tg-cell-row">
            <span class="tg-cell-label">Operatsion Tizim:</span>
            <span class="tg-cell-value">UzOS Cloud 2.0 (WebOS)</span>
          </div>
          <div class="tg-cell-row">
            <span class="tg-cell-label">Dizayn Tili:</span>
            <span class="tg-cell-value">Telegram UI (@telegram-apps/telegram-ui)</span>
          </div>
          <div class="tg-cell-row">
            <span class="tg-cell-label">Telemetriya:</span>
            <span class="tg-cell-value" style="color:var(--tg-green);">0 B (100% Zero-Telemetry)</span>
          </div>
          <div class="tg-cell-row">
            <span class="tg-cell-label">Yadro / Hypervisor:</span>
            <span class="tg-cell-value">Web Standards VFS Engine</span>
          </div>
          <div class="tg-cell-row">
            <span class="tg-cell-label">Ishlab Chiquvchi:</span>
            <span class="tg-cell-value">Muhammad Sadiyev</span>
          </div>
        </div>
      `;

    } else if (tab === 'wallpaper') {
      this.contentEl.innerHTML = `
        <div class="settings-section-title">Telegram Ish Stoli Mavzusi</div>
        <div class="settings-section-desc">Kerakli Telegram foni ustiga bosing, fon darhol saqlanadi.</div>

        <div class="wallpaper-grid">
          <div class="wallpaper-card" data-bg="default" style="background: #0e1621;">
            <div class="wallpaper-card-name">Telegram Dark (Klassik)</div>
          </div>

          <div class="wallpaper-card" data-bg="midnight" style="background: radial-gradient(circle at 50% 20%, #1e3a8a 0%, #0f172a 60%, #020617 100%);">
            <div class="wallpaper-card-name">Midnight Blue</div>
          </div>

          <div class="wallpaper-card" data-bg="emerald" style="background: radial-gradient(circle at 30% 30%, #064e3b 0%, #022c22 60%, #01140e 100%);">
            <div class="wallpaper-card-name">Emerald Dark</div>
          </div>

          <div class="wallpaper-card" data-bg="amethyst" style="background: radial-gradient(circle at 70% 30%, #581c87 0%, #2e1065 60%, #090214 100%);">
            <div class="wallpaper-card-name">Telegram Violet</div>
          </div>

          <div class="wallpaper-card" data-bg="pure-black" style="background: #000000;">
            <div class="wallpaper-card-name">OLED Black</div>
          </div>
        </div>
      `;

      this.contentEl.querySelectorAll('.wallpaper-card').forEach(card => {
        card.addEventListener('click', () => {
          const bgType = card.dataset.bg;
          const bgStyle = card.style.background;
          this.setWallpaper(bgType, bgStyle);
          if (this.notify) this.notify("Mavzu Yangilandi", "Telegram foni muvaffaqiyatli almashtirildi", "🎨");
        });
      });

    } else if (tab === 'storage') {
      this.contentEl.innerHTML = `
        <div class="settings-section-title">Xotira va Shaxsiy Ma'lumotlar</div>
        <div class="settings-section-desc">Brauzerda saqlangan fayllar va sozlamalar nazorati.</div>

        <div class="tg-section-card" style="padding: 16px;">
          <div style="font-weight: 600; margin-bottom: 6px;">Virtual Fayllar Tizimi (VFS)</div>
          <div style="font-size: 12.5px; color: var(--tg-theme-subtitle-text-color); margin-bottom: 14px;">
            Barcha ma'lumotlaringiz shaxsiy brauzeringizda shifrlangan holda saqlanmoqda.
          </div>
          
          <div style="display:flex; gap:10px; flex-wrap:wrap;">
            <button class="files-btn" id="btn-export-fs">
              📤 Zaxira nusxasini olish (.json)
            </button>
            <button class="files-btn" id="btn-reset-fs" style="background: var(--tg-red);">
              ⚠️ Qayta tiklash (Reset)
            </button>
          </div>
        </div>
      `;

      this.contentEl.querySelector('#btn-reset-fs').addEventListener('click', () => {
        if (confirm("Rostdan ham barcha shaxsiy fayllarni o'chirib, UzOS Cloud'ni boshlang'ich holatga qaytarmoqchimisiz?")) {
          this.vfs.reset();
          if (this.notify) this.notify("Tizim Tiklandi", "Fayllar tizimi boshlang'ich holatga keltirildi.", "🔄");
          setTimeout(() => location.reload(), 1000);
        }
      });

      this.contentEl.querySelector('#btn-export-fs').addEventListener('click', () => {
        const dataStr = "data:text/json;charset=utf-8," + encodeURIComponent(JSON.stringify(this.vfs.fs, null, 2));
        const dlAnchorElem = document.createElement('a');
        dlAnchorElem.setAttribute("href", dataStr);
        dlAnchorElem.setAttribute("download", "uzos_cloud_backup.json");
        dlAnchorElem.click();
        if (this.notify) this.notify("Eksport Qilindi", "Zaxira nusxasi yuklab olindi.", "📤");
      });
    }
  }
}
