/* ==============================================================================
   UzOS Cloud (WebOS) — Desktop Environment Master Controller
   Coordinates Multi-Window Manager, Taskbar, Dock, Drawer, VFS & Built-in Apps
   100% Vector SVG Icons, Zero Emojis, Authentic Telegram Web UI Styling
   ============================================================================== */

import { VirtualFileSystem } from './os/storage.js';
import { WindowManager } from './os/window-manager.js';
import { TaskbarController } from './os/taskbar.js';
import { ContextMenu } from './os/context-menu.js';
import { ICONS } from './os/icons.js';

import { TerminalApp } from './apps/terminal.js';
import { FilesApp } from './apps/files.js';
import { EditorApp } from './apps/editor.js';
import { AIAssistantApp } from './apps/ai.js';
import { SettingsApp } from './apps/settings.js';

document.addEventListener('DOMContentLoaded', () => {
  // 1. Initialize Virtual File System
  const vfs = new VirtualFileSystem();

  // 2. Initialize Window Manager on Workspace Canvas
  const workspaceEl = document.getElementById('workspace');
  const wm = new WindowManager(workspaceEl);

  // 3. Initialize Taskbar, Topbar, Drawer & Audio Controller
  let openAppRef = null;
  const taskbar = new TaskbarController({
    windowManager: wm,
    openAppCallback: (appType, opts) => openApp(appType, opts),
    vfs
  });

  // 4. App Instances Map & Window Configurations
  let editorAppInstance = null;

  const APP_CONFIGS = {
    ai: {
      id: 'win-ai',
      title: 'UzOS Milliy AI',
      icon: ICONS.ai,
      width: 680,
      height: 520,
      minWidth: 420,
      minHeight: 360
    },
    terminal: {
      id: 'win-terminal',
      title: 'UzOS Terminal',
      icon: ICONS.terminal,
      width: 700,
      height: 460,
      minWidth: 440,
      minHeight: 300
    },
    files: {
      id: 'win-files',
      title: 'Bulut Fayllar',
      icon: ICONS.folder,
      width: 740,
      height: 480,
      minWidth: 460,
      minHeight: 320
    },
    editor: {
      id: 'win-editor',
      title: 'Kod Muharriri',
      icon: ICONS.editor,
      width: 780,
      height: 520,
      minWidth: 480,
      minHeight: 340
    },
    settings: {
      id: 'win-settings',
      title: 'Tizim Sozlamalari',
      icon: ICONS.settings,
      width: 620,
      height: 520,
      minWidth: 400,
      minHeight: 350
    }
  };

  // 5. Master Open App Function
  function openApp(appType, options = {}) {
    const config = APP_CONFIGS[appType];
    if (!config) return;

    // Check if already open
    if (wm.windows.has(config.id)) {
      const win = wm.windows.get(config.id);
      if (win.minimized) {
        wm.restoreWindow(config.id);
      }
      wm.focusWindow(config.id);

      if (appType === 'editor' && options.filePath && editorAppInstance) {
        editorAppInstance.openNewFile(options.filePath, options.fileName);
      }
      return win;
    }

    // Create window frame
    const win = wm.createWindow({
      id: config.id,
      title: config.title,
      icon: config.icon,
      width: config.width,
      height: config.height,
      minWidth: config.minWidth,
      minHeight: config.minHeight,
      appType
    });

    const host = win.element.querySelector('.window-body');

    // Instantiate app inside window body
    switch (appType) {
      case 'ai':
        new AIAssistantApp(host);
        break;

      case 'terminal':
        new TerminalApp(host, vfs, wm);
        break;

      case 'files':
        new FilesApp(host, vfs, wm, (filePath, fileName) => {
          openApp('editor', { filePath, fileName });
        });
        break;

      case 'editor':
        editorAppInstance = new EditorApp(
          host,
          vfs,
          options.filePath || '/Hujjatlar/Xush_kelibsiz.txt',
          options.fileName || 'Xush_kelibsiz.txt',
          (title, msg, icon) => taskbar.showNotification(title, msg, icon)
        );
        break;

      case 'settings':
        new SettingsApp(
          host,
          (type, style) => {},
          vfs,
          (title, msg, icon) => taskbar.showNotification(title, msg, icon)
        );
        break;
    }

    return win;
  }

  openAppRef = openApp;

  // 6. Bind Desktop Icons (Single click = select, Double click = launch)
  const desktopCells = document.querySelectorAll('.desktop-icon-cell');
  desktopCells.forEach(cell => {
    cell.addEventListener('click', (e) => {
      e.stopPropagation();
      desktopCells.forEach(c => c.classList.remove('selected'));
      cell.classList.add('selected');
    });

    cell.addEventListener('dblclick', (e) => {
      e.stopPropagation();
      const app = cell.dataset.app;
      openApp(app);
    });

    cell.addEventListener('keydown', (e) => {
      if (e.key === 'Enter') {
        const app = cell.dataset.app;
        openApp(app);
      }
    });
  });

  // Clicking on workspace clears icon selection
  workspaceEl.addEventListener('click', (e) => {
    if (!e.target.closest('.desktop-icon-cell')) {
      desktopCells.forEach(c => c.classList.remove('selected'));
    }
  });

  // 7. Bind Sidebar Dock Buttons (Toggle / Focus / Launch)
  document.querySelectorAll('.sidebar-app-btn[data-app]').forEach(btn => {
    btn.addEventListener('click', () => {
      const app = btn.dataset.app;
      const config = APP_CONFIGS[app];
      if (!config) return;

      if (wm.windows.has(config.id)) {
        const win = wm.windows.get(config.id);
        if (win.minimized) {
          wm.restoreWindow(config.id);
        } else if (win.id === wm.activeWindowId) {
          wm.minimizeWindow(config.id);
        } else {
          wm.focusWindow(config.id);
        }
      } else {
        openApp(app);
      }
    });
  });

  // 8. Bind Drawer / Start Menu App Item Click
  document.querySelectorAll('.drawer-item[data-app]').forEach(item => {
    item.addEventListener('click', () => {
      const app = item.dataset.app;
      openApp(app);
      const drawer = document.getElementById('drawer');
      if (drawer) drawer.classList.add('collapsed');
    });
  });

  // 9. Initialize Desktop Right-Click Context Menu
  new ContextMenu({
    workspace: workspaceEl,
    onAction: (action) => {
      switch (action) {
        case 'new-file': {
          const name = prompt("Yangi fayl nomi (masalan: loyiha.txt):", "yangi_hujjat.txt");
          if (name) {
            const path = `/Hujjatlar/${name}`;
            vfs.writeFile(path, `# ${name}\nYangi yaratilgan hujjat.`);
            openApp('editor', { filePath: path, fileName: name });
            taskbar.showNotification("Fayl Yaratildi", `'${name}' VFS xotirasida ochildi.`, ICONS.newFile);
          }
          break;
        }

        case 'refresh':
          taskbar.showNotification("Ish Stoli Yangilandi", "Tizim jarayonlari muvaffaqiyatli sinxronlandi.", ICONS.refresh);
          break;

        case 'wallpaper': {
          const container = document.getElementById('desktop-container');
          if (container.classList.contains('wallpaper-mesh')) {
            container.className = 'default-wallpaper';
            taskbar.showNotification("Fon Rasmi", "Telegram Dark Vector fon faol.", ICONS.palette);
          } else {
            container.className = 'default-wallpaper wallpaper-mesh';
            taskbar.showNotification("Fon Rasmi", "Telegram Deep Indigo fon faol.", ICONS.palette);
          }
          break;
        }

        case 'sys-info':
          openApp('terminal');
          taskbar.showNotification("UzOS Cloud 2.0.4", "WebOS Web Hypervisor • 100% Zero-Telemetry", ICONS.info);
          break;
      }
    }
  });

  // 10. Auto-launch default welcome windows in cascaded arrangement
  setTimeout(() => {
    openApp('terminal');
    setTimeout(() => {
      openApp('ai');
    }, 180);
  }, 250);

  // Welcome Toast Notification
  setTimeout(() => {
    taskbar.showNotification(
      "UzOS Cloud WebOS Faol",
      "Ko'p oynali WebOS va 100% Telegram Web dizayn tili ishga tushdi.",
      ICONS.ai
    );
  }, 700);
});
