/* ==============================================================================
   UzOS Cloud (WebOS) — 100% Authentic Telegram Web / Desktop Master Script
   Manages 2-Column Chat Switching, Telegram Folders, Search, Menu & Apps
   ============================================================================== */

import { VirtualFileSystem } from './os/storage.js';
import { TerminalApp } from './apps/terminal.js';
import { FilesApp } from './apps/files.js';
import { EditorApp } from './apps/editor.js';
import { AIAssistantApp } from './apps/ai.js';
import { SettingsApp } from './apps/settings.js';

document.addEventListener('DOMContentLoaded', () => {
  // 1. Initialize Virtual File System
  const vfs = new VirtualFileSystem();

  // 2. Chat Metadata Definition
  const CHATS = {
    ai: {
      title: "UzOS Milliy AI",
      subtitle: "bot, doimiy onlayn",
      avatarText: "AI",
      avatarClass: "gradient-purple",
      verified: true
    },
    terminal: {
      title: "UzOS Terminal",
      subtitle: "Cloud Shell v2.0 • Web Hypervisor",
      avatarText: ">_",
      avatarClass: "gradient-dark",
      verified: false
    },
    files: {
      title: "UzOS Fayllar",
      subtitle: "Shaxsiy Bulut Xotirasi (VFS)",
      avatarText: "📁",
      avatarClass: "gradient-orange",
      verified: false
    },
    editor: {
      title: "UzOS Code Editor",
      subtitle: "JavaScript, Python, Markdown",
      avatarText: "📝",
      avatarClass: "gradient-blue",
      verified: false
    },
    settings: {
      title: "Tizim Sozlamalari",
      subtitle: "Zero-Telemetry • 100% Shaxsiy",
      avatarText: "⚙️",
      avatarClass: "gradient-slate",
      verified: false
    }
  };

  let activeChatId = 'ai';
  let editorAppInstance = null;

  // DOM Elements
  const headerAvatar = document.getElementById('header-avatar');
  const headerTitle = document.getElementById('header-title');
  const headerSubtitle = document.getElementById('header-subtitle');
  const chatList = document.getElementById('tg-chat-list');
  const searchInput = document.getElementById('tg-search-input');
  const foldersBar = document.getElementById('tg-folders-bar');
  const menuBtn = document.getElementById('btn-tg-menu');
  const sideMenu = document.getElementById('tg-side-menu');
  const menuOverlay = document.getElementById('tg-menu-overlay');
  const homeBtn = document.getElementById('btn-home');
  const fullscreenBtn = document.getElementById('btn-fullscreen');

  // 3. Initialize Built-in Apps into their containers
  const initApps = () => {
    // AI
    const aiHost = document.querySelector('.app-host-ai');
    new AIAssistantApp(aiHost);

    // Terminal
    const termHost = document.querySelector('.app-host-terminal');
    new TerminalApp(termHost, vfs, null);

    // Files
    const filesHost = document.querySelector('.app-host-files');
    new FilesApp(filesHost, vfs, null, (filePath, fileName) => {
      switchChat('editor', { filePath, fileName });
    });

    // Editor
    const editorHost = document.querySelector('.app-host-editor');
    editorAppInstance = new EditorApp(
      editorHost,
      vfs,
      '/Hujjatlar/Xush_kelibsiz.txt',
      'Xush_kelibsiz.txt',
      (title, msg, icon) => showToast(title, msg, icon)
    );

    // Settings
    const settingsHost = document.querySelector('.app-host-settings');
    new SettingsApp(
      settingsHost,
      (type, style) => {
        document.querySelector('.tg-right-body').style.background = style;
      },
      vfs,
      (title, msg, icon) => showToast(title, msg, icon)
    );
  };

  // 4. Switch Active Chat / App View
  const switchChat = (chatId, options = {}) => {
    if (!CHATS[chatId]) return;
    activeChatId = chatId;
    const meta = CHATS[chatId];

    // Update left chat list items
    chatList.querySelectorAll('.tg-chat-item').forEach(item => {
      item.classList.toggle('active', item.dataset.chatId === chatId);
    });

    // Update right header
    headerAvatar.textContent = meta.avatarText;
    headerAvatar.className = `tg-header-avatar ${meta.avatarClass}`;
    
    headerTitle.innerHTML = `
      <span>${meta.title}</span>
      ${meta.verified ? `
        <svg width="15" height="15" viewBox="0 0 16 16" fill="none">
          <path d="M8 0L9.8 1.9L12.4 1.5L13.4 3.9L15.9 4.9L15.6 7.5L17.2 9.5L15.6 11.5L15.9 14.1L13.4 15.1L12.4 17.5L9.8 17.1L8 19L6.2 17.1L3.6 17.5L2.6 15.1L0.1 14.1L0.4 11.5L-1.2 9.5L0.4 7.5L0.1 4.9L2.6 3.9L3.6 1.5L6.2 1.9L8 0Z" transform="scale(0.8) translate(2, 0)" fill="#3390ec"/>
          <path d="M4.5 8L6.8 10.3L11.5 5.5" stroke="white" stroke-width="1.8" stroke-linecap="round" stroke-linejoin="round"/>
        </svg>
      ` : ''}
    `;
    headerSubtitle.textContent = meta.subtitle;

    // Switch view container
    document.querySelectorAll('.tg-app-view').forEach(view => {
      view.classList.remove('active');
    });
    const targetView = document.getElementById(`view-${chatId}`);
    if (targetView) {
      targetView.classList.add('active');
    }

    // If opening editor with specific file
    if (chatId === 'editor' && options.filePath && editorAppInstance) {
      editorAppInstance.openNewFile(options.filePath, options.fileName);
    }
  };

  // 5. Toast Notification System
  const showToast = (title, msg, icon = '✈️') => {
    const container = document.getElementById('tg-toast-container');
    const toast = document.createElement('div');
    toast.className = 'tg-toast';
    toast.innerHTML = `
      <div style="font-size: 20px;">${icon}</div>
      <div>
        <div style="font-size: 13px; font-weight: 600; color: #fff;">${title}</div>
        <div style="font-size: 12px; color: var(--tg-text-secondary);">${msg}</div>
      </div>
    `;
    container.appendChild(toast);
    setTimeout(() => {
      toast.style.opacity = '0';
      toast.style.transform = 'translateY(-10px)';
      setTimeout(() => toast.remove(), 250);
    }, 3500);
  };

  // 6. Bind Chat Item Click Events
  chatList.querySelectorAll('.tg-chat-item').forEach(item => {
    item.addEventListener('click', () => {
      const chatId = item.dataset.chatId;
      switchChat(chatId);
      // Remove unread badge once opened
      const badge = item.querySelector('.tg-unread-badge');
      if (badge) badge.remove();
    });
  });

  // 7. Bind Search Input Filter
  searchInput.addEventListener('input', (e) => {
    const query = e.target.value.toLowerCase().trim();
    chatList.querySelectorAll('.tg-chat-item').forEach(item => {
      const name = item.querySelector('.tg-chat-name').textContent.toLowerCase();
      const desc = item.querySelector('.tg-chat-desc').textContent.toLowerCase();
      if (name.includes(query) || desc.includes(query)) {
        item.style.display = 'flex';
      } else {
        item.style.display = 'none';
      }
    });
  });

  // 8. Bind Telegram Folders Bar Tabs
  foldersBar.querySelectorAll('.tg-folder-tab').forEach(tab => {
    tab.addEventListener('click', () => {
      foldersBar.querySelectorAll('.tg-folder-tab').forEach(t => t.classList.remove('active'));
      tab.classList.add('active');

      const folder = tab.dataset.folder;
      chatList.querySelectorAll('.tg-chat-item').forEach(item => {
        const itemFolders = item.dataset.folder.split(',');
        if (folder === 'all' || itemFolders.includes(folder)) {
          item.style.display = 'flex';
        } else {
          item.style.display = 'none';
        }
      });
    });
  });

  // 9. Bind Slide-out Menu (Hamburger)
  const toggleMenu = (open) => {
    sideMenu.classList.toggle('visible', open);
    menuOverlay.classList.toggle('visible', open);
  };

  menuBtn.addEventListener('click', () => toggleMenu(true));
  menuOverlay.addEventListener('click', () => toggleMenu(false));

  sideMenu.querySelectorAll('.tg-menu-item').forEach(item => {
    item.addEventListener('click', () => {
      const action = item.dataset.action;
      toggleMenu(false);
      if (action === 'home') {
        window.location.href = 'index.html';
      } else if (CHATS[action]) {
        switchChat(action);
      }
    });
  });

  // 10. Bind Top Actions (Home, Fullscreen)
  homeBtn.addEventListener('click', () => {
    window.location.href = 'index.html';
  });

  fullscreenBtn.addEventListener('click', () => {
    if (!document.fullscreenElement) {
      document.documentElement.requestFullscreen().catch(() => {});
    } else {
      document.exitFullscreen().catch(() => {});
    }
  });

  // 11. Initialize everything
  initApps();
  switchChat('ai');

  // Welcome Toast
  setTimeout(() => {
    showToast("UzOS Cloud Faol", "Telegram WebOS interfeysi muvaffaqiyatli ishga tushdi.", "🇺🇿");
  }, 500);
});
