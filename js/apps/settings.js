/* ==============================================================================
   UzOS Cloud (WebOS) — Settings Application
   Wallpaper Customization, System Specs, Privacy, and Factory Reset
   ============================================================================== */

export class SettingsApp {
  constructor(container, onWallpaperChange, vfs, showNotification) {
    this.container = container;
    this.setWallpaper = onWallpaperChange;
    this.vfs = vfs;
    this.notify = showNotification;
    this.currentTab = 'wallpaper';

    this.render();
  }

  render() {
    this.container.innerHTML = `
      <div class="app-settings">
        <!-- Settings Nav -->
        <div class="settings-nav">
          <div class="settings-nav-btn active" data-tab="wallpaper">
            <span>🖼</span> Fon Rasmlari
          </div>
          <div class="settings-nav-btn" data-tab="about">
            <span>ℹ️</span> Tizim Haqida
          </div>
          <div class="settings-nav-btn" data-tab="storage">
            <span>💾</span> Xotira & Reset
          </div>
        </div>

        <!-- Content Area -->
        <div class="settings-content" id="settings-content-area">
          <!-- Dynamically populated based on active tab -->
        </div>
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
    if (tab === 'wallpaper') {
      this.contentEl.innerHTML = `
        <div class="settings-section-title">Ish Stoli Fon Rasmini Tanlash</div>
        <div class="settings-section-desc">Kerakli mavzuni bosing, fon rasmi darhol yangilanadi va saqlanadi.</div>

        <div class="wallpaper-grid">
          <div class="wallpaper-card" data-bg="default" style="background: radial-gradient(circle at 15% 20%, rgba(36, 129, 204, 0.18) 0%, transparent 45%), radial-gradient(circle at 85% 75%, rgba(43, 82, 120, 0.22) 0%, transparent 50%), radial-gradient(circle at 50% 50%, rgba(14, 22, 33, 0.95) 0%, #080d14 100%);">
            <div class="wallpaper-card-name">Telegram Dark (Asosiy)</div>
          </div>

          <div class="wallpaper-card" data-bg="midnight" style="background: radial-gradient(circle at 50% 20%, #1e3a8a 0%, #0f172a 60%, #020617 100%);">
            <div class="wallpaper-card-name">Midnight Aurora</div>
          </div>

          <div class="wallpaper-card" data-bg="emerald" style="background: radial-gradient(circle at 30% 30%, #064e3b 0%, #022c22 60%, #01140e 100%);">
            <div class="wallpaper-card-name">Emerald Sovereign</div>
          </div>

          <div class="wallpaper-card" data-bg="amethyst" style="background: radial-gradient(circle at 70% 30%, #581c87 0%, #2e1065 60%, #090214 100%);">
            <div class="wallpaper-card-name">Amethyst Cyber</div>
          </div>

          <div class="wallpaper-card" data-bg="pure-black" style="background: #000000;">
            <div class="wallpaper-card-name">OLED Pure Black</div>
          </div>
        </div>
      `;

      this.contentEl.querySelectorAll('.wallpaper-card').forEach(card => {
        card.addEventListener('click', () => {
          const bgType = card.dataset.bg;
          const bgStyle = card.style.background;
          this.setWallpaper(bgType, bgStyle);
          if (this.notify) this.notify("Fon Yangilandi", "Yangi ish stoli foni muvaffaqiyatli o'rnatildi", "🎨");
        });
      });

    } else if (tab === 'about') {
      this.contentEl.innerHTML = `
        <div class="settings-section-title">UzOS Cloud Tizimi Haqida</div>
        <div class="settings-section-desc">O'zbekiston Milliy Bulut Ish Stoli Ekotizimi</div>

        <div style="background: var(--bg-surface); padding: 18px; border-radius: var(--radius-card); border: 1px solid var(--border); display: flex; flex-direction: column; gap: 12px; font-size: 13px;">
          <div style="display:flex; justify-content:space-between; border-bottom:1px solid var(--border); padding-bottom:8px;">
            <span style="color:var(--text-secondary);">Tizim nomi:</span>
            <span style="font-weight:600;">UzOS Cloud WebOS</span>
          </div>
          <div style="display:flex; justify-content:space-between; border-bottom:1px solid var(--border); padding-bottom:8px;">
            <span style="color:var(--text-secondary);">Versiya:</span>
            <span style="color:var(--accent-bright); font-weight:600;">2.0.4 (Suveren Nashr)</span>
          </div>
          <div style="display:flex; justify-content:space-between; border-bottom:1px solid var(--border); padding-bottom:8px;">
            <span style="color:var(--text-secondary);">Dizayn tili:</span>
            <span>Telegram Dark Glassmorphism</span>
          </div>
          <div style="display:flex; justify-content:space-between; border-bottom:1px solid var(--border); padding-bottom:8px;">
            <span style="color:var(--text-secondary);">Telemetriya / Kuzatuv:</span>
            <span style="color:var(--green); font-weight:600;">0 B (100% Bloklangan / Zero-Telemetry)</span>
          </div>
          <div style="display:flex; justify-content:space-between; border-bottom:1px solid var(--border); padding-bottom:8px;">
            <span style="color:var(--text-secondary);">Raqamli xavfsizlik:</span>
            <span>Shaxsiy keshda mahalliy shifrlangan</span>
          </div>
          <div style="display:flex; justify-content:space-between;">
            <span style="color:var(--text-secondary);">Muallif / Ishlab chiquvchi:</span>
            <span>Muhammad Sadiyev</span>
          </div>
        </div>
      `;

    } else if (tab === 'storage') {
      this.contentEl.innerHTML = `
        <div class="settings-section-title">Xotira Boshqaruvi va Tiklash</div>
        <div class="settings-section-desc">Brauzerda saqlangan fayllar va sozlamalar nazorati.</div>

        <div style="background: var(--bg-surface); padding: 18px; border-radius: var(--radius-card); border: 1px solid var(--border); margin-bottom: 20px;">
          <div style="font-weight: 600; margin-bottom: 4px;">Virtual Fayllar Tizimi (VFS)</div>
          <div style="font-size: 12px; color: var(--text-secondary); margin-bottom: 14px;">Barcha o'zgarishlar brauzeringizning shaxsiy xotirasida (localStorage/IndexedDB) saqlanmoqda.</div>
          
          <button class="files-btn" id="btn-export-fs" style="margin-right: 8px;">
            📤 Zaxira nusxasini yuklab olish (.json)
          </button>
          
          <button class="files-btn" id="btn-reset-fs" style="background: var(--red); color: #fff; margin-top: 10px;">
            ⚠️ Tizimni qayta tiklash (Zavod holati)
          </button>
        </div>
      `;

      this.contentEl.querySelector('#btn-reset-fs').addEventListener('click', () => {
        if (confirm("Rostdan ham barcha shaxsiy fayllarni o'chirib, UzOS Cloud'ni boshlang'ich zavod holatiga qaytarmoqchimisiz?")) {
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
