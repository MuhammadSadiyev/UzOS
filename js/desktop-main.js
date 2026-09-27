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

  // 6. Desktop Icons Drag-and-Drop, Free Placement & Persistence System
  const desktopCells = document.querySelectorAll('.desktop-icon-cell');
  const GRID_SIZE_X = 92;
  const GRID_SIZE_Y = 100;
  const GRID_OFFSET_X = 20;
  const GRID_OFFSET_Y = 20;

  const defaultPositions = {
    files: { col: 0, row: 0 },
    terminal: { col: 0, row: 1 },
    editor: { col: 0, row: 2 },
    ai: { col: 0, row: 3 },
    settings: { col: 0, row: 4 }
  };

  let savedPositions = {};
  try {
    const raw = localStorage.getItem('uzos_desktop_icon_positions');
    if (raw) savedPositions = JSON.parse(raw);
  } catch (err) {
    savedPositions = {};
  }

  function applyIconPositions() {
    const wsRect = workspaceEl.getBoundingClientRect();
    const maxCols = Math.max(0, Math.floor((wsRect.width - GRID_OFFSET_X - 82) / GRID_SIZE_X));
    const maxRows = Math.max(0, Math.floor((wsRect.height - GRID_OFFSET_Y - 92) / GRID_SIZE_Y));

    desktopCells.forEach(cell => {
      const app = cell.dataset.app;
      const pos = savedPositions[app] || defaultPositions[app] || { col: 0, row: 0 };
      const col = Math.min(pos.col, maxCols);
      const row = Math.min(pos.row, maxRows);
      const left = GRID_OFFSET_X + col * GRID_SIZE_X;
      const top = GRID_OFFSET_Y + row * GRID_SIZE_Y;
      cell.style.left = `${left}px`;
      cell.style.top = `${top}px`;
    });
  }

  applyIconPositions();
  window.addEventListener('resize', applyIconPositions);

  desktopCells.forEach(cell => {
    let isDragging = false;
    let hasMoved = false;
    let startX = 0, startY = 0;
    let initLeft = 0, initTop = 0;

    const onPointerDown = (e) => {
      if (e.button !== 0) return;
      isDragging = true;
      hasMoved = false;
      startX = e.clientX;
      startY = e.clientY;

      const rect = cell.getBoundingClientRect();
      const wsRect = workspaceEl.getBoundingClientRect();
      initLeft = rect.left - wsRect.left;
      initTop = rect.top - wsRect.top;

      desktopCells.forEach(c => c.classList.remove('selected'));
      cell.classList.add('selected');

      document.addEventListener('pointermove', onPointerMove);
      document.addEventListener('pointerup', onPointerUp);
    };

    const onPointerMove = (e) => {
      if (!isDragging) return;
      const dx = e.clientX - startX;
      const dy = e.clientY - startY;

      if (!hasMoved && Math.hypot(dx, dy) > 4) {
        hasMoved = true;
        cell.classList.add('dragging');
      }

      if (hasMoved) {
        const wsRect = workspaceEl.getBoundingClientRect();
        let curX = initLeft + dx;
        let curY = initTop + dy;
        curX = Math.max(10, Math.min(wsRect.width - 82, curX));
        curY = Math.max(10, Math.min(wsRect.height - 92, curY));

        cell.style.left = `${curX}px`;
        cell.style.top = `${curY}px`;
      }
    };

    const onPointerUp = () => {
      if (!isDragging) return;
      isDragging = false;
      document.removeEventListener('pointermove', onPointerMove);
      document.removeEventListener('pointerup', onPointerUp);

      if (hasMoved) {
        cell.classList.remove('dragging');
        const wsRect = workspaceEl.getBoundingClientRect();
        const curLeft = parseFloat(cell.style.left) || initLeft;
        const curTop = parseFloat(cell.style.top) || initTop;

        const col = Math.max(0, Math.round((curLeft - GRID_OFFSET_X) / GRID_SIZE_X));
        const row = Math.max(0, Math.round((curTop - GRID_OFFSET_Y) / GRID_SIZE_Y));

        const maxCols = Math.max(0, Math.floor((wsRect.width - GRID_OFFSET_X - 82) / GRID_SIZE_X));
        const maxRows = Math.max(0, Math.floor((wsRect.height - GRID_OFFSET_Y - 92) / GRID_SIZE_Y));

        const finalCol = Math.min(col, maxCols);
        const finalRow = Math.min(row, maxRows);

        const snapLeft = GRID_OFFSET_X + finalCol * GRID_SIZE_X;
        const snapTop = GRID_OFFSET_Y + finalRow * GRID_SIZE_Y;

        cell.style.transition = 'left 0.2s cubic-bezier(0.16, 1, 0.3, 1), top 0.2s cubic-bezier(0.16, 1, 0.3, 1)';
        cell.style.left = `${snapLeft}px`;
        cell.style.top = `${snapTop}px`;
        setTimeout(() => { cell.style.transition = ''; }, 220);

        const app = cell.dataset.app;
        savedPositions[app] = { col: finalCol, row: finalRow };
        try {
          localStorage.setItem('uzos_desktop_icon_positions', JSON.stringify(savedPositions));
        } catch (err) {}
      }
    };

    cell.addEventListener('pointerdown', onPointerDown);

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

  // 7. Bind Dock Buttons (Toggle / Focus / Launch)
  document.querySelectorAll('.taskbar-app-btn[data-app], .sidebar-app-btn[data-app]').forEach(btn => {
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

        case 'arrange-icons': {
          savedPositions = {};
          try {
            localStorage.removeItem('uzos_desktop_icon_positions');
          } catch (e) {}
          desktopCells.forEach(cell => {
            cell.style.transition = 'left 0.3s cubic-bezier(0.16, 1, 0.3, 1), top 0.3s cubic-bezier(0.16, 1, 0.3, 1)';
          });
          applyIconPositions();
          setTimeout(() => {
            desktopCells.forEach(cell => { cell.style.transition = ''; });
          }, 320);
          taskbar.showNotification("Belgilar Tartiblandi", "Ish stoli belgilari birlamchi ustunga joylashtirildi.", ICONS.files);
          break;
        }

        case 'refresh':
          taskbar.showNotification("Ish Stoli Yangilandi", "Tizim jarayonlari muvaffaqiyatli sinxronlandi.", ICONS.refresh);
          break;

        case 'wallpaper': {
          const container = document.getElementById('desktop-container');
          if (container.classList.contains('wallpaper-mesh')) {
            container.className = 'default-wallpaper';
            taskbar.showNotification("Fon Rangi", "Telegram Dark (#0e1621) rangi faollashtirildi.", ICONS.palette);
          } else {
            container.className = 'default-wallpaper wallpaper-mesh';
            taskbar.showNotification("Fon Rangi", "Telegram Night (#0f141c) rangi faollashtirildi.", ICONS.palette);
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
