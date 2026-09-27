/* ==============================================================================
   UzOS Cloud (WebOS) — Files Application (Virtual File Manager)
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
        <!-- Toolbar -->
        <div class="files-toolbar">
          <div class="files-nav-btns">
            <button class="files-btn" id="files-btn-back" title="Orqaga">⬅</button>
            <button class="files-btn" id="files-btn-up" title="Yuqoriga">⬆</button>
            <button class="files-btn" id="files-btn-new-folder">📁 +Papka</button>
            <button class="files-btn" id="files-btn-new-file">📄 +Fayl</button>
          </div>
          <div class="files-breadcrumb" id="files-breadcrumb">
            📁 ${this.currentPath}
          </div>
        </div>

        <!-- Body -->
        <div class="files-body">
          <!-- Sidebar -->
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

          <!-- Main Grid -->
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
    // Nav shortcuts
    this.container.querySelectorAll('.files-nav-item').forEach(item => {
      item.addEventListener('click', () => {
        this.currentPath = item.dataset.path;
        this.updateActiveNav();
        this.refreshGrid();
      });
    });

    // Up button
    this.container.querySelector('#files-btn-up').addEventListener('click', () => {
      if (this.currentPath !== '/' && this.currentPath !== '') {
        const parts = this.currentPath.split('/').filter(Boolean);
        parts.pop();
        this.currentPath = parts.length ? '/' + parts.join('/') : '/';
        this.updateActiveNav();
        this.refreshGrid();
      }
    });

    // New folder
    this.container.querySelector('#files-btn-new-folder').addEventListener('click', () => {
      const name = prompt("Yangi papka nomi:", "Yangi_Papka");
      if (name) {
        const path = `${this.currentPath}/${name}`.replace('//', '/');
        this.vfs.createFolder(path);
        this.refreshGrid();
      }
    });

    // New file
    this.container.querySelector('#files-btn-new-file').addEventListener('click', () => {
      const name = prompt("Yangi fayl nomi (masalan: hujjat.txt):", "yangi_fayl.txt");
      if (name) {
        const path = `${this.currentPath}/${name}`.replace('//', '/');
        this.vfs.writeFile(path, 'Yangi hujjat matni...');
        this.refreshGrid();
      }
    });
  }

  updateActiveNav() {
    this.container.querySelectorAll('.files-nav-item').forEach(el => {
      el.classList.toggle('active', el.dataset.path === this.currentPath);
    });
    this.breadcrumbEl.textContent = `📁 ${this.currentPath}`;
  }

  refreshGrid() {
    this.breadcrumbEl.textContent = `📁 ${this.currentPath}`;
    this.gridEl.innerHTML = '';

    const items = this.vfs.list(this.currentPath);
    if (items.length === 0) {
      this.gridEl.innerHTML = `<div style="grid-column: 1 / -1; padding: 24px; text-align: center; color: var(--text-muted); font-size: 13px;">Ushbu papka bo'sh. Yuqoridagi tugmalar orqali yangi fayl qo'shishingiz mumkin.</div>`;
      return;
    }

    items.forEach(item => {
      const card = document.createElement('div');
      card.className = 'file-card';
      
      let icon = '📄';
      if (item.type === 'directory') icon = '📁';
      else if (item.name.endsWith('.svg') || item.name.endsWith('.png')) icon = '🖼';
      else if (item.name.endsWith('.js') || item.name.endsWith('.html')) icon = '📜';
      else if (item.name.endsWith('.md')) icon = '📝';

      card.innerHTML = `
        <div class="file-icon">${icon}</div>
        <div class="file-name" title="${item.name}">${item.name}</div>
      `;

      card.addEventListener('dblclick', () => {
        const itemPath = `${this.currentPath}/${item.name}`.replace('//', '/');
        if (item.type === 'directory') {
          this.currentPath = itemPath;
          this.updateActiveNav();
          this.refreshGrid();
        } else {
          // Open in editor
          if (this.openEditor) {
            this.openEditor(itemPath, item.name);
          }
        }
      });

      this.gridEl.appendChild(card);
    });
  }
}
