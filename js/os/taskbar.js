/* ==============================================================================
   UzOS Cloud (WebOS) — Taskbar, TopBar, Drawer, Notifications & Audio FX
   ============================================================================== */

export class TaskbarController {
  constructor({ windowManager, openAppCallback, vfs }) {
    this.wm = windowManager;
    this.openApp = openAppCallback;
    this.vfs = vfs;

    this.topbarClock = document.getElementById('topbar-clock');
    this.drawer = document.getElementById('drawer');
    this.drawerList = document.getElementById('drawer-list');
    this.drawerSearch = document.getElementById('drawer-search');
    this.quickSettings = document.getElementById('quick-settings');
    this.notificationContainer = document.getElementById('notification-container');
    this.btnToggleQs = document.getElementById('btn-toggle-quicksettings');
    this.btnLogo = document.getElementById('sidebar-logo-btn');
    this.btnFullscreen = document.getElementById('btn-fullscreen');

    this.initClock();
    this.initDrawer();
    this.initQuickSettings();
    this.initFullscreen();
    this.bindWindowEvents();
  }

  initClock() {
    const update = () => {
      const now = new Date();
      const timeStr = now.toLocaleTimeString('uz-UZ', { hour: '2-digit', minute: '2-digit', second: '2-digit', hour12: false });
      if (this.topbarClock) {
        this.topbarClock.textContent = timeStr;
      }
    };
    update();
    setInterval(update, 1000);
  }

  initDrawer() {
    if (this.btnLogo) {
      this.btnLogo.addEventListener('click', (e) => {
        e.stopPropagation();
        this.drawer.classList.toggle('collapsed');
      });
    }

    // Close drawer when clicking outside
    document.addEventListener('click', (e) => {
      if (!e.target.closest('#drawer') && !e.target.closest('#sidebar-logo-btn') && !this.drawer.classList.contains('collapsed')) {
        this.drawer.classList.add('collapsed');
      }
    });

    // Search filtering
    if (this.drawerSearch) {
      this.drawerSearch.addEventListener('input', (e) => {
        const query = e.target.value.toLowerCase().trim();
        const items = this.drawerList.querySelectorAll('.drawer-item');
        items.forEach(item => {
          const name = item.dataset.appName.toLowerCase();
          const desc = item.dataset.appDesc.toLowerCase();
          if (name.includes(query) || desc.includes(query)) {
            item.style.display = 'flex';
          } else {
            item.style.display = 'none';
          }
        });
      });
    }
  }

  initQuickSettings() {
    if (this.btnToggleQs) {
      this.btnToggleQs.addEventListener('click', (e) => {
        e.stopPropagation();
        this.quickSettings.classList.toggle('visible');
        this.btnToggleQs.classList.toggle('active', this.quickSettings.classList.contains('visible'));
      });
    }

    document.addEventListener('click', (e) => {
      if (!e.target.closest('#quick-settings') && !e.target.closest('#btn-toggle-quicksettings')) {
        this.quickSettings.classList.remove('visible');
        if (this.btnToggleQs) this.btnToggleQs.classList.remove('active');
      }
    });

    // Cards interactive click toggles
    this.quickSettings.querySelectorAll('.qs-card').forEach(card => {
      card.addEventListener('click', () => {
        card.classList.toggle('active');
        const statusEl = card.querySelector('.qs-card-status');
        if (statusEl) {
          statusEl.textContent = card.classList.contains('active') ? 'Faol' : 'O\'chiq';
        }
      });
    });
  }

  initFullscreen() {
    if (this.btnFullscreen) {
      this.btnFullscreen.addEventListener('click', () => {
        if (!document.fullscreenElement) {
          document.documentElement.requestFullscreen().catch(() => {});
          this.btnFullscreen.textContent = '⤓ Chiqish';
        } else {
          document.exitFullscreen().catch(() => {});
          this.btnFullscreen.textContent = '⛶ To\'liq ekran';
        }
      });
    }
  }

  bindWindowEvents() {
    // When windows open, close, or focus, update sidebar running indicators
    this.wm.onWindowListChange = (windows) => {
      // Update sidebar buttons
      document.querySelectorAll('.sidebar-app-btn').forEach(btn => {
        const app = btn.dataset.app;
        const isRunning = windows.some(w => w.appType === app);
        const isActive = windows.some(w => w.appType === app && w.active);

        btn.classList.toggle('running', isRunning);
        btn.classList.toggle('active', isActive);
      });
    };
  }

  showNotification(title, message, icon = '✈️') {
    this.playNotificationSound();

    const toast = document.createElement('div');
    toast.className = 'toast-item';
    toast.innerHTML = `
      <div class="toast-icon">${icon}</div>
      <div class="toast-content">
        <div class="toast-title">${title}</div>
        <div class="toast-msg">${message}</div>
      </div>
    `;

    this.notificationContainer.appendChild(toast);

    setTimeout(() => {
      toast.style.opacity = '0';
      toast.style.transform = 'translateX(40px)';
      setTimeout(() => toast.remove(), 300);
    }, 4000);
  }

  playNotificationSound() {
    try {
      const audioCtx = new (window.AudioContext || window.webkitAudioContext)();
      const osc = audioCtx.createOscillator();
      const gain = audioCtx.createGain();

      osc.type = 'sine';
      osc.frequency.setValueAtTime(587.33, audioCtx.currentTime); // D5
      osc.frequency.exponentialRampToValueAtTime(880, audioCtx.currentTime + 0.12); // A5

      gain.gain.setValueAtTime(0.08, audioCtx.currentTime);
      gain.gain.exponentialRampToValueAtTime(0.001, audioCtx.currentTime + 0.25);

      osc.connect(gain);
      gain.connect(audioCtx.destination);

      osc.start();
      osc.stop(audioCtx.currentTime + 0.25);
    } catch (e) {
      // Audio autoplay policy fallback
    }
  }
}
