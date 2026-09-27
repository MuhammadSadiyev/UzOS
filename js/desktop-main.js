/* ==============================================================================
   UzOS Cloud (WebOS) — Main Entry Point
   Integrates WindowManager, VirtualFileSystem, Taskbar, ContextMenu & Apps
   ============================================================================== */

import { VirtualFileSystem } from './os/storage.js';
import { WindowManager } from './os/window-manager.js';
import { TaskbarController } from './os/taskbar.js';
import { ContextMenu } from './os/context-menu.js';

import { TerminalApp } from './apps/terminal.js';
import { FilesApp } from './apps/files.js';
import { EditorApp } from './apps/editor.js';
import { AIAssistantApp } from './apps/ai.js';
import { SettingsApp } from './apps/settings.js';

document.addEventListener('DOMContentLoaded', () => {
  const desktopContainer = document.getElementById('desktop-container');
  const workspaceEl = document.getElementById('workspace');

  // 1. Initialize Storage & Window Manager
  const vfs = new VirtualFileSystem();
  const wm = new WindowManager(workspaceEl);

  // 2. Wallpaper management
  const savedBg = localStorage.getItem('uzos_wallpaper_style');
  if (savedBg) {
    desktopContainer.style.background = savedBg;
  }

  const setWallpaper = (type, style) => {
    desktopContainer.style.background = style;
    localStorage.setItem('uzos_wallpaper_style', style);
  };

  // 3. App Dispatcher
  const openApp = (appType, options = {}) => {
    switch (appType) {
      case 'terminal': {
        const win = wm.createWindow({
          id: 'app-terminal',
          title: 'UzOS Terminal — Web Shell',
          icon: '💻',
          width: 680,
          height: 440,
          minWidth: 400,
          minHeight: 280,
          appType: 'terminal',
          content: '<div class="terminal-host" style="height:100%; display:flex;"></div>'
        });
        const host = win.element.querySelector('.terminal-host');
        if (!host.dataset.initialized) {
          new TerminalApp(host, vfs, wm);
          host.dataset.initialized = 'true';
        }
        break;
      }

      case 'files': {
        const win = wm.createWindow({
          id: 'app-files',
          title: 'UzOS Fayllar — Shaxsiy Bulut',
          icon: '📁',
          width: 720,
          height: 460,
          minWidth: 480,
          minHeight: 320,
          appType: 'files',
          content: '<div class="files-host" style="height:100%; display:flex;"></div>'
        });
        const host = win.element.querySelector('.files-host');
        if (!host.dataset.initialized) {
          new FilesApp(host, vfs, wm, (path, name) => {
            openApp('editor', { filePath: path, fileName: name });
          });
          host.dataset.initialized = 'true';
        }
        break;
      }

      case 'editor': {
        const winId = 'app-editor';
        const win = wm.createWindow({
          id: winId,
          title: `UzOS Code — ${options.fileName || 'Xush_kelibsiz.txt'}`,
          icon: '📝',
          width: 760,
          height: 500,
          minWidth: 450,
          minHeight: 300,
          appType: 'editor',
          content: '<div class="editor-host" style="height:100%; display:flex;"></div>'
        });
        const host = win.element.querySelector('.editor-host');
        if (!host.dataset.initialized) {
          win.editorInstance = new EditorApp(
            host,
            vfs,
            options.filePath || '/Hujjatlar/Xush_kelibsiz.txt',
            options.fileName || 'Xush_kelibsiz.txt',
            (title, msg, icon) => taskbar.showNotification(title, msg, icon)
          );
          host.dataset.initialized = 'true';
        } else if (options.filePath && win.editorInstance) {
          win.editorInstance.openNewFile(options.filePath, options.fileName);
          win.element.querySelector('.window-title').textContent = `UzOS Code — ${options.fileName}`;
        }
        break;
      }

      case 'ai': {
        const win = wm.createWindow({
          id: 'app-ai',
          title: 'UzOS Milliy Sun\'iy Intellekt',
          icon: '🤖',
          width: 620,
          height: 480,
          minWidth: 380,
          minHeight: 340,
          appType: 'ai',
          content: '<div class="ai-host" style="height:100%; display:flex;"></div>'
        });
        const host = win.element.querySelector('.ai-host');
        if (!host.dataset.initialized) {
          new AIAssistantApp(host);
          host.dataset.initialized = 'true';
        }
        break;
      }

      case 'settings': {
        const win = wm.createWindow({
          id: 'app-settings',
          title: 'Tizim Sozlamalari',
          icon: '⚙️',
          width: 680,
          height: 440,
          minWidth: 420,
          minHeight: 300,
          appType: 'settings',
          content: '<div class="settings-host" style="height:100%; display:flex;"></div>'
        });
        const host = win.element.querySelector('.settings-host');
        if (!host.dataset.initialized) {
          new SettingsApp(host, setWallpaper, vfs, (title, msg, icon) => taskbar.showNotification(title, msg, icon));
          host.dataset.initialized = 'true';
        }
        break;
      }
    }
  };

  // 4. Initialize Taskbar Controller
  const taskbar = new TaskbarController({
    windowManager: wm,
    openAppCallback: openApp,
    vfs
  });

  // 5. Initialize Desktop Context Menu
  new ContextMenu({
    workspace: workspaceEl,
    onAction: (action) => {
      switch (action) {
        case 'new-folder': {
          const name = prompt("Yangi papka nomi:", "Yangi_Papka");
          if (name) {
            vfs.createFolder(`/Hujjatlar/${name}`);
            taskbar.showNotification("Papka Yaratildi", `/Hujjatlar/${name} yaratildi`, "📁");
            openApp('files');
          }
          break;
        }
        case 'new-file': {
          const name = prompt("Yangi fayl nomi:", "hujjat.txt");
          if (name) {
            vfs.writeFile(`/Hujjatlar/${name}`, 'Yangi fayl matni...');
            taskbar.showNotification("Fayl Yaratildi", `/Hujjatlar/${name} yaratildi`, "📄");
            openApp('editor', { filePath: `/Hujjatlar/${name}`, fileName: name });
          }
          break;
        }
        case 'open-terminal':
          openApp('terminal');
          break;
        case 'open-settings':
          openApp('settings');
          break;
        case 'about':
          openApp('settings');
          break;
        case 'reload':
          location.reload();
          break;
      }
    }
  });

  // 6. Bind Sidebar Buttons
  document.querySelectorAll('.sidebar-app-btn[data-app]').forEach(btn => {
    btn.addEventListener('click', () => {
      const app = btn.dataset.app;
      openApp(app);
    });
  });

  // 7. Bind Drawer Items
  document.querySelectorAll('.drawer-item[data-app]').forEach(item => {
    item.addEventListener('click', () => {
      const app = item.dataset.app;
      openApp(app);
      document.getElementById('drawer').classList.add('collapsed');
    });
  });

  // 8. Bind Desktop Icons (Single or Double Click)
  document.querySelectorAll('.desktop-icon-cell[data-app]').forEach(iconCell => {
    let clickTimeout = null;

    iconCell.addEventListener('click', () => {
      document.querySelectorAll('.desktop-icon-cell').forEach(c => c.classList.remove('selected'));
      iconCell.classList.add('selected');
    });

    iconCell.addEventListener('dblclick', () => {
      clearTimeout(clickTimeout);
      const app = iconCell.dataset.app;
      openApp(app);
    });
  });

  // Deselect icons when clicking workspace empty area
  workspaceEl.addEventListener('click', (e) => {
    if (!e.target.closest('.desktop-icon-cell')) {
      document.querySelectorAll('.desktop-icon-cell').forEach(c => c.classList.remove('selected'));
    }
  });

  // Navigation back to Landing Page
  const goHome = () => { window.location.href = 'index.html'; };
  document.getElementById('topbar-home-btn')?.addEventListener('click', goHome);
  document.getElementById('sidebar-landing-btn')?.addEventListener('click', goHome);

  // 9. Initial Launch Welcome & Defaults
  setTimeout(() => {
    taskbar.showNotification(
      "UzOS Cloud 2.0 Ishga Tushdi",
      "100% Zero-Telemetry va shaxsiy suveren bulut muhitiga xush kelibsiz! 🇺🇿",
      "🚀"
    );
  }, 400);

  // Auto-launch Terminal and Welcome Note by default
  setTimeout(() => {
    openApp('terminal');
  }, 600);

  setTimeout(() => {
    openApp('editor', {
      filePath: '/Hujjatlar/Xush_kelibsiz.txt',
      fileName: 'Xush_kelibsiz.txt'
    });
  }, 1000);
});
