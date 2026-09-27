/* ==============================================================================
   UzOS Cloud (WebOS) — Files Application (Virtual File Manager)
   1:1 Telegram Shared Media / Files List Layout with Actions
   ============================================================================== */

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
            <button class="files-btn" id="files-btn-up" title="Yuqoriga">⬆ Chiqish</button>
            <button class="files-btn" id="files-btn-new-folder">📁 +Papka</button>
            <button class="files-btn" id="files-btn-new-file">📄 +Fayl</button>
          </div>
          <div class="files-breadcrumb" id="files-breadcrumb">
            📁 ${this.currentPath}
          </div>
        </div>

        <!-- Files Body -->
        <div class="files-body">
          
          <!-- Files Sidebar -->
          <div class="files-sidebar">
            <div class="files-nav-item ${this.currentPath === '/Hujjatlar' ? 'active' : ''}" data-path="/Hujjatlar">
              <span>📄</span> Hujjatlar
            </div>
            <div class="files-nav-item ${this.currentPath === '/Rasmlar' ? 'active' : ''}" data-path="/Rasmlar">
              <span>🖼</span> Rasmlar
            </div>
            <div class="files-nav-item ${this.currentPath === '/Yuklamalar' ? 'active' : ''}" data-path="/Yuklamalar">
              <span>⬇</span> Yuklamalar
            </div>
            <div class="files-nav-item ${this.currentPath === '/Chiqindilar' ? 'active' : ''}" data-path="/Chiqindilar">
              <span>🗑</span> Chiqindilar
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
    this.breadcrumbEl = this.container.querySelector('#files-breadcrumb');

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
    this.breadcrumbEl.textContent = `📁 ${this.currentPath}`;
  }

  getFileIconClass(name, isFolder) {
    if (isFolder) return { icon: '📁', type: 'folder' };
    if (name.endsWith('.js') || name.endsWith('.ts') || name.endsWith('.py') || name.endsWith('.sh') || name.endsWith('.rs')) {
      return { icon: '</>', type: 'code' };
    }
    if (name.endsWith('.md') || name.endsWith('.docx') || name.endsWith('.doc')) {
      return { icon: 'DOC', type: 'doc' };
    }
    if (name.endsWith('.pdf')) {
      return { icon: 'PDF', type: 'pdf' };
    }
    return { icon: 'TXT', type: 'text' };
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
        <div style="text-align: center; color: var(--tg-text-muted); padding: 40px; font-size: 13.5px;">
          📁 Bu papka bo'sh.<br><br>
          Yuqoridagi <b>+Fayl</b> yoki <b>+Papka</b> tugmasi orqali yangi element yarating.
        </div>
      `;
      return;
    }

    Object.entries(folder.children).forEach(([name, item]) => {
      const isFolder = item.type === 'directory';
      const iconInfo = this.getFileIconClass(name, isFolder);
      const filePath = `${this.currentPath}/${name}`.replace('//', '/');
      const sizeStr = isFolder ? 'Katalog' : `${(item.content || '').length} bayt`;

      const row = document.createElement('div');
      row.className = 'tg-file-row';
      row.innerHTML = `
        <div class="tg-file-left">
          <div class="tg-file-icon-box ${iconInfo.type}">
            ${iconInfo.icon}
          </div>
          <div class="tg-file-meta">
            <span class="tg-file-title">${name}</span>
            <span class="tg-file-sub">${sizeStr} • Bugun</span>
          </div>
        </div>
        <div class="tg-file-actions">
          ${!isFolder ? `<button class="tg-file-act-btn edit-btn">📝 Tahrirlash</button>` : ''}
          ${!isFolder ? `<button class="tg-file-act-btn dl-btn">⬇ Yuklash</button>` : ''}
          <button class="tg-file-act-btn delete del-btn">🗑</button>
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
