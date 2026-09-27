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
    this.currentPath = '/';

    // Auto-refresh when VFS changes anywhere in UzOS
    if (this.vfs && this.vfs.onChange) {
      this.unsubscribeVfs = this.vfs.onChange(() => {
        this.refreshGrid();
      });
    }

    this.render();
  }

  render() {
    this.container.innerHTML = `
      <div class="app-files">
        
        <!-- Files Toolbar -->
        <div class="files-toolbar" style="display:flex;align-items:center;justify-content:space-between;gap:8px;">
          <div class="files-breadcrumb" id="files-breadcrumb">
            <span class="files-breadcrumb-icon" id="files-breadcrumb-icon" style="display:flex;align-items:center;color:var(--tg-blue);cursor:pointer;" title="Bosh katalogga qaytish">
              ${ICONS.folder}
            </span>
            <div class="files-breadcrumb-segments" id="files-breadcrumb-segments" style="display:flex;align-items:center;gap:4px;flex-wrap:wrap;"></div>
          </div>

          <div class="files-toolbar-actions" style="display:flex;align-items:center;gap:8px;">
            <label class="tg-upload-btn" id="btn-upload-file" style="display:flex;align-items:center;gap:6px;background:rgba(36,129,204,0.18);color:#2481cc;border:1px solid rgba(36,129,204,0.35);padding:5px 12px;border-radius:8px;font-size:12px;font-weight:600;cursor:pointer;user-select:none;transition:all 0.15s ease;">
              ${FILE_SVGS.download}
              <span>Fayl Yuklash</span>
              <input type="file" id="files-host-input" multiple style="display:none;" />
            </label>
          </div>
        </div>

        <!-- Files Body (Full width Document List) -->
        <div class="files-body" id="files-drop-area">
          <div class="files-grid" id="files-grid">
            <!-- Items rendered dynamically -->
          </div>
        </div>

      </div>
    `;

    this.gridEl = this.container.querySelector('#files-grid');
    this.dropAreaEl = this.container.querySelector('#files-drop-area');
    this.breadcrumbSegments = this.container.querySelector('#files-breadcrumb-segments');
    this.breadcrumbIcon = this.container.querySelector('#files-breadcrumb-icon');
    this.hostFileInput = this.container.querySelector('#files-host-input');

    this.bindEvents();
    this.updateBreadcrumbs();
    this.refreshGrid();
  }

  bindEvents() {
    if (this.breadcrumbIcon) {
      this.breadcrumbIcon.addEventListener('click', () => {
        this.currentPath = '/';
        this.updateBreadcrumbs();
        this.refreshGrid();
      });
    }

    if (this.hostFileInput) {
      this.hostFileInput.addEventListener('change', (e) => {
        const files = Array.from(e.target.files || []);
        if (files.length > 0) {
          this.handleIncomingFiles(files);
          this.hostFileInput.value = '';
        }
      });
    }

    // Drag and drop directly into current folder inside Files App
    if (this.dropAreaEl) {
      this.dropAreaEl.addEventListener('dragover', (e) => {
        e.preventDefault();
        e.stopPropagation();
        this.dropAreaEl.style.background = 'rgba(36, 129, 204, 0.08)';
      });

      this.dropAreaEl.addEventListener('dragleave', (e) => {
        e.preventDefault();
        e.stopPropagation();
        this.dropAreaEl.style.background = '';
      });

      this.dropAreaEl.addEventListener('drop', (e) => {
        e.preventDefault();
        e.stopPropagation();
        this.dropAreaEl.style.background = '';
        const files = Array.from(e.dataTransfer.files || []);
        if (files.length > 0) {
          this.handleIncomingFiles(files);
        }
      });
    }
  }

  handleIncomingFiles(files) {
    let count = 0;
    files.forEach(file => {
      const reader = new FileReader();
      const isText = file.type.startsWith('text/') || 
                     file.name.endsWith('.txt') || 
                     file.name.endsWith('.md') || 
                     file.name.endsWith('.json') || 
                     file.name.endsWith('.js') || 
                     file.name.endsWith('.ts') || 
                     file.name.endsWith('.css') || 
                     file.name.endsWith('.html') || 
                     file.name.endsWith('.svg');

      reader.onload = (event) => {
        const content = event.target.result;
        const targetDir = this.currentPath === '/' ? '/Hujjatlar' : this.currentPath;
        const targetPath = `${targetDir}/${file.name}`.replace('//', '/');
        const mime = file.type || (isText ? 'text/plain' : 'application/octet-stream');

        this.vfs.writeFile(targetPath, content, mime);
        count++;
        if (count === files.length) {
          this.refreshGrid();
        }
      };

      if (isText) {
        reader.readAsText(file);
      } else {
        reader.readAsDataURL(file);
      }
    });
  }

  updateBreadcrumbs() {
    if (!this.breadcrumbSegments) return;
    const parts = this.currentPath.split('/').filter(Boolean);
    if (parts.length === 0) {
      this.breadcrumbSegments.innerHTML = `<span class="path-seg active" style="color:#ffffff;font-weight:600;font-size:13.5px;">/ (Bosh Katalog)</span>`;
    } else {
      let html = `<span class="path-seg" data-path="/" style="cursor:pointer;color:var(--tg-blue);font-weight:500;">/</span>`;
      let currentSub = '';
      parts.forEach((p, idx) => {
        currentSub += '/' + p;
        const isLast = idx === parts.length - 1;
        html += ` <span style="opacity:0.35;margin:0 4px;">/</span> <span class="path-seg ${isLast ? 'active' : ''}" data-path="${currentSub}" style="cursor:pointer;${isLast ? 'color:#fff;font-weight:600;' : 'color:var(--tg-blue);font-weight:500;'}">${p}</span>`;
      });
      this.breadcrumbSegments.innerHTML = html;
    }

    this.breadcrumbSegments.querySelectorAll('.path-seg[data-path]').forEach(seg => {
      seg.addEventListener('click', () => {
        this.currentPath = seg.dataset.path || '/';
        this.updateBreadcrumbs();
        this.refreshGrid();
      });
    });
  }

  updateActiveNav() {
    this.updateBreadcrumbs();
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
          <div style="font-size: 12.5px; color: var(--tg-text-secondary); max-width: 280px;">Ushbu katalogda hozircha fayllar mavjud emas.</div>
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
