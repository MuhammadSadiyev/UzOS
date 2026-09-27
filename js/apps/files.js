/* ==============================================================================
   UzOS Cloud (WebOS) — Files Application (Virtual File Manager)
   100% Vector SVG Icons, Zero Emojis, Telegram Shared Media / Document Cards
   ============================================================================== */

import { ICONS } from '../os/icons.js';

const FILE_SVGS = {
  up: `<svg width="15" height="15" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2.2" stroke-linecap="round" stroke-linejoin="round"><path d="m18 15-6-6-6 6"/></svg>`,
  trash: `<svg width="15" height="15" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M3 6h18m-2 0v14c0 1-1 2-2 2H7c-1 0-2-1-2-2V6m3 0V4c0-1 1-2 2-2h4c1 0 2 1 2 2v2"/></svg>`,
  download: `<svg width="15" height="15" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M21 15v4a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2v-4m4-5 5 5 5-5m-5 5V3"/></svg>`,
  edit: `<svg width="15" height="15" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M12 20h9"/><path d="M16.5 3.5a2.12 2.12 0 0 1 3 3L7 19l-4 1 1-4Z"/></svg>`,
  image: `<svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><rect width="18" height="18" x="3" y="3" rx="2" ry="2"/><circle cx="9" cy="9" r="2"/><path d="m21 15-3.086-3.086a2 2 0 0 0-2.828 0L6 21"/></svg>`,
  doc: `<svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M14 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V8z"/><polyline points="14 2 14 8 20 8"/><line x1="16" y1="13" x2="8" y2="13"/><line x1="16" y1="17" x2="8" y2="17"/></svg>`
};

export class FilesApp {
  constructor(container, vfs, windowManager, openEditorCallback) {
    this.container = container;
    this.vfs = vfs;
    this.wm = windowManager;
    this.openEditor = openEditorCallback;
    this.currentPath = '/Hujjatlar';

    this.render();
  }

  render() {
    this.container.innerHTML = `
      <div class="app-files">
        
        <!-- Files Toolbar -->
        <div class="files-toolbar">
          <div class="files-nav-btns">
            <button class="files-btn" id="files-btn-up" title="Yuqoriga">
              ${FILE_SVGS.up}
              <span>Chiqish</span>
            </button>
            <button class="files-btn" id="files-btn-new-folder">
              ${ICONS.folder}
              <span>Yangi Papka</span>
            </button>
            <button class="files-btn" id="files-btn-new-file">
              ${ICONS.newFile}
              <span>Yangi Fayl</span>
            </button>
          </div>
          <div class="files-breadcrumb" id="files-breadcrumb">
            <span style="display:flex;align-items:center;color:var(--tg-blue);">${ICONS.folder}</span>
            <span id="files-breadcrumb-text">${this.currentPath}</span>
          </div>
        </div>

        <!-- Files Body -->
        <div class="files-body">
          
          <!-- Files Sidebar -->
          <div class="files-sidebar">
            <div class="files-nav-item ${this.currentPath === '/Hujjatlar' ? 'active' : ''}" data-path="/Hujjatlar">
              <span style="display:flex;align-items:center;">${FILE_SVGS.doc}</span>
              <span>Hujjatlar</span>
            </div>
            <div class="files-nav-item ${this.currentPath === '/Rasmlar' ? 'active' : ''}" data-path="/Rasmlar">
              <span style="display:flex;align-items:center;">${FILE_SVGS.image}</span>
              <span>Rasmlar</span>
            </div>
            <div class="files-nav-item ${this.currentPath === '/Yuklamalar' ? 'active' : ''}" data-path="/Yuklamalar">
              <span style="display:flex;align-items:center;">${FILE_SVGS.download}</span>
              <span>Yuklamalar</span>
            </div>
            <div class="files-nav-item ${this.currentPath === '/Chiqindilar' ? 'active' : ''}" data-path="/Chiqindilar">
              <span style="display:flex;align-items:center;">${FILE_SVGS.trash}</span>
              <span>Chiqindilar</span>
            </div>
          </div>

          <!-- Files Document Rows List -->
          <div class="files-grid" id="files-grid">
            <!-- Items rendered dynamically -->
          </div>

        </div>

      </div>
    `;

    this.gridEl = this.container.querySelector('#files-grid');
    this.breadcrumbText = this.container.querySelector('#files-breadcrumb-text');

    this.bindEvents();
    this.refreshGrid();
  }

  bindEvents() {
    this.container.querySelectorAll('.files-nav-item').forEach(item => {
      item.addEventListener('click', () => {
        this.currentPath = item.dataset.path;
        this.updateActiveNav();
        this.refreshGrid();
      });
    });

    this.container.querySelector('#files-btn-up').addEventListener('click', () => {
      if (this.currentPath !== '/' && this.currentPath !== '') {
        const parts = this.currentPath.split('/').filter(Boolean);
        parts.pop();
        this.currentPath = parts.length ? '/' + parts.join('/') : '/';
        this.updateActiveNav();
        this.refreshGrid();
      }
    });

    this.container.querySelector('#files-btn-new-folder').addEventListener('click', () => {
      const name = prompt("Yangi papka nomi:", "Yangi_Papka");
      if (name) {
        const path = `${this.currentPath}/${name}`.replace('//', '/');
        this.vfs.createFolder(path);
        this.refreshGrid();
      }
    });

    this.container.querySelector('#files-btn-new-file').addEventListener('click', () => {
      const name = prompt("Yangi fayl nomi (masalan: hisobot.txt):", "yangi_fayl.txt");
      if (name) {
        const path = `${this.currentPath}/${name}`.replace('//', '/');
        this.vfs.writeFile(path, `# ${name}\nYangi yaratilgan fayl.`);
        this.refreshGrid();
        if (this.openEditor) {
          this.openEditor(path, name);
        }
      }
    });
  }

  updateActiveNav() {
    this.container.querySelectorAll('.files-nav-item').forEach(item => {
      item.classList.toggle('active', item.dataset.path === this.currentPath);
    });
    if (this.breadcrumbText) {
      this.breadcrumbText.textContent = this.currentPath;
    }
  }

  getFileIconInfo(name, isFolder) {
    if (isFolder) {
      return { iconSvg: ICONS.folder, type: 'folder' };
    }
    if (name.endsWith('.js') || name.endsWith('.ts') || name.endsWith('.py') || name.endsWith('.sh') || name.endsWith('.rs')) {
      return { iconSvg: ICONS.terminal, type: 'code' };
    }
    if (name.endsWith('.md') || name.endsWith('.docx') || name.endsWith('.doc')) {
      return { iconSvg: FILE_SVGS.doc, type: 'doc' };
    }
    if (name.endsWith('.pdf')) {
      return { iconSvg: FILE_SVGS.doc, type: 'pdf' };
    }
    return { iconSvg: ICONS.newFile, type: 'text' };
  }

  downloadFile(name, content) {
    const blob = new Blob([content], { type: 'text/plain;charset=utf-8' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = name;
    a.click();
    URL.revokeObjectURL(url);
  }

  refreshGrid() {
    this.gridEl.innerHTML = '';
    const folder = this.vfs.getFolder(this.currentPath);

    if (!folder || !folder.children || Object.keys(folder.children).length === 0) {
      this.gridEl.innerHTML = `
        <div style="text-align: center; color: var(--tg-text-muted); padding: 50px 20px; display: flex; flex-direction: column; align-items: center; gap: 12px;">
          <div style="width: 48px; height: 48px; border-radius: 12px; background: rgba(255,255,255,0.06); display: flex; align-items: center; justify-content: center; color: var(--tg-blue);">
            ${ICONS.folder}
          </div>
          <div style="font-size: 14px; font-weight: 500; color: #fff;">Bu papka bo'sh</div>
          <div style="font-size: 12.5px; color: var(--tg-text-secondary); max-width: 280px;">Yuqoridagi 'Yangi Fayl' yoki 'Yangi Papka' tugmalari orqali fayl qo'shishingiz mumkin.</div>
        </div>
      `;
      return;
    }

    Object.entries(folder.children).forEach(([name, item]) => {
      const isFolder = item.type === 'directory';
      const iconInfo = this.getFileIconInfo(name, isFolder);
      const filePath = `${this.currentPath}/${name}`.replace('//', '/');
      const sizeStr = isFolder ? 'Katalog' : `${(item.content || '').length} bayt`;

      const row = document.createElement('div');
      row.className = 'tg-file-row';
      row.innerHTML = `
        <div class="tg-file-left">
          <div class="tg-file-icon-box ${iconInfo.type}">
            ${iconInfo.iconSvg}
          </div>
          <div class="tg-file-meta">
            <span class="tg-file-title">${name}</span>
            <span class="tg-file-sub">${sizeStr} • Bugun</span>
          </div>
        </div>
        <div class="tg-file-actions">
          ${!isFolder ? `
            <button class="tg-file-act-btn edit-btn" title="Tahrirlash">
              ${FILE_SVGS.edit}
              <span>Tahrir</span>
            </button>
          ` : ''}
          ${!isFolder ? `
            <button class="tg-file-act-btn dl-btn" title="Yuklab olish">
              ${FILE_SVGS.download}
              <span>Yuklash</span>
            </button>
          ` : ''}
          <button class="tg-file-act-btn delete del-btn" title="O'chirish">
            ${FILE_SVGS.trash}
          </button>
        </div>
      `;

      // Click row to navigate if folder, or open editor if file
      row.addEventListener('click', (e) => {
        if (e.target.closest('.tg-file-actions')) return;
        if (isFolder) {
          this.currentPath = filePath;
          this.updateActiveNav();
          this.refreshGrid();
        } else {
          if (this.openEditor) {
            this.openEditor(filePath, name);
          }
        }
      });

      // Actions
      const editBtn = row.querySelector('.edit-btn');
      if (editBtn) {
        editBtn.addEventListener('click', (e) => {
          e.stopPropagation();
          if (this.openEditor) this.openEditor(filePath, name);
        });
      }

      const dlBtn = row.querySelector('.dl-btn');
      if (dlBtn) {
        dlBtn.addEventListener('click', (e) => {
          e.stopPropagation();
          this.downloadFile(name, item.content || '');
        });
      }

      const delBtn = row.querySelector('.del-btn');
      if (delBtn) {
        delBtn.addEventListener('click', (e) => {
          e.stopPropagation();
          if (confirm(`Haqiqatan ham '${name}'ni o'chirmoqchimisiz?`)) {
            this.vfs.deleteItem(filePath);
            this.refreshGrid();
          }
        });
      }

      this.gridEl.appendChild(row);
    });
  }
}
