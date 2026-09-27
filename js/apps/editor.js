/* ==============================================================================
   UzOS Cloud (WebOS) — Code Editor Application
   Telegram Developer Studio with Syntax Gutter, Tabs & Live JavaScript Runner
   100% Vector SVG Icons, Zero Emojis
   ============================================================================== */

import { ICONS } from '../os/icons.js';

const EDITOR_SVGS = {
  save: `<svg width="15" height="15" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M19 21H5a2 2 0 0 1-2-2V5a2 2 0 0 1 2-2h11l5 5v11a2 2 0 0 1-2 2z"/><polyline points="17 21 17 13 7 13 7 21"/><polyline points="7 3 7 8 15 8"/></svg>`,
  run: `<svg width="15" height="15" viewBox="0 0 24 24" fill="currentColor"><polygon points="5 3 19 12 5 21 5 3"/></svg>`,
  file: `<svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M14 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V8z"/><polyline points="14 2 14 8 20 8"/></svg>`
};

export class EditorApp {
  constructor(container, vfs, initialPath = '/Hujjatlar/Xush_kelibsiz.txt', initialName = 'Xush_kelibsiz.txt', showToast = null) {
    this.container = container;
    this.vfs = vfs;
    this.showToast = showToast;
    this.openTabs = [
      { path: '/Hujjatlar/Xush_kelibsiz.txt', name: 'Xush_kelibsiz.txt' },
      { path: '/Hujjatlar/script.js', name: 'script.js' },
      { path: '/Hujjatlar/Loyiha_haqida.md', name: 'Loyiha_haqida.md' }
    ];
    this.currentPath = initialPath;
    this.currentName = initialName;

    this.render();
  }

  render() {
    this.container.innerHTML = `
      <div class="app-editor">
        
        <!-- Editor Tabs and Action Bar -->
        <div class="editor-tabs">
          <div class="editor-tab-list" id="editor-tab-list">
            <!-- Tabs rendered dynamically -->
          </div>
          <div class="editor-actions">
            <button class="editor-act-btn" id="editor-btn-save" title="Saqlash (Ctrl+S)">
              ${EDITOR_SVGS.save}
              <span>Saqlash</span>
            </button>
            <button class="editor-act-btn run" id="editor-btn-run" title="Bajarish">
              ${EDITOR_SVGS.run}
              <span>Bajarish</span>
            </button>
          </div>
        </div>

        <!-- Main Editor Workspace -->
        <div class="editor-main">
          <div class="editor-linenums" id="editor-linenums">1</div>
          <textarea class="editor-textarea" id="editor-textarea" spellcheck="false"></textarea>
        </div>

        <!-- Live VFS Console Output Pane -->
        <div class="editor-console-pane" id="editor-console" style="display:none;"></div>

        <!-- Status Bar -->
        <div class="editor-status">
          <span id="editor-status-file" style="display:flex;align-items:center;gap:6px;">
            ${EDITOR_SVGS.file}
            <span>${this.currentName}</span>
          </span>
          <span id="editor-status-pos">Qator: 1, Ustun: 1 • UTF-8 • Zero-Telemetry</span>
        </div>

      </div>
    `;

    this.tabListEl = this.container.querySelector('#editor-tab-list');
    this.textarea = this.container.querySelector('#editor-textarea');
    this.linenums = this.container.querySelector('#editor-linenums');
    this.consolePane = this.container.querySelector('#editor-console');
    this.statusFile = this.container.querySelector('#editor-status-file');
    this.statusPos = this.container.querySelector('#editor-status-pos');

    this.bindEvents();
    this.renderTabs();
    this.loadFile(this.currentPath, this.currentName);
  }

  bindEvents() {
    this.textarea.addEventListener('input', () => {
      this.updateLineNumbers();
    });

    this.textarea.addEventListener('scroll', () => {
      this.linenums.scrollTop = this.textarea.scrollTop;
    });

    this.textarea.addEventListener('keyup', () => {
      this.updateCursorPos();
    });

    this.textarea.addEventListener('click', () => {
      this.updateCursorPos();
    });

    this.container.querySelector('#editor-btn-save').addEventListener('click', () => {
      this.saveCurrentFile();
    });

    this.container.querySelector('#editor-btn-run').addEventListener('click', () => {
      this.runCurrentCode();
    });

    // Ctrl+S shortcut
    this.textarea.addEventListener('keydown', (e) => {
      if ((e.ctrlKey || e.metaKey) && e.key === 's') {
        e.preventDefault();
        this.saveCurrentFile();
      }
    });
  }

  updateLineNumbers() {
    const lines = this.textarea.value.split('\n').length;
    let nums = '';
    for (let i = 1; i <= Math.max(lines, 1); i++) {
      nums += i + '<br>';
    }
    this.linenums.innerHTML = nums;
  }

  updateCursorPos() {
    const pos = this.textarea.selectionStart;
    const lines = this.textarea.value.substr(0, pos).split('\n');
    const lineNum = lines.length;
    const colNum = lines[lines.length - 1].length + 1;
    this.statusPos.textContent = `Qator: ${lineNum}, Ustun: ${colNum} • UTF-8 • Zero-Telemetry`;
  }

  renderTabs() {
    this.tabListEl.innerHTML = '';
    this.openTabs.forEach(tab => {
      const tabEl = document.createElement('div');
      tabEl.className = `editor-tab ${tab.path === this.currentPath ? 'active' : ''}`;
      tabEl.textContent = tab.name;
      tabEl.addEventListener('click', () => {
        this.loadFile(tab.path, tab.name);
      });
      this.tabListEl.appendChild(tabEl);
    });
  }

  loadFile(path, name) {
    this.currentPath = path;
    this.currentName = name;
    if (this.statusFile) {
      this.statusFile.innerHTML = `
        <span style="display:flex;align-items:center;color:var(--tg-blue);">${EDITOR_SVGS.file}</span>
        <span>${name}</span>
      `;
    }

    const file = this.vfs.getFile(path);
    if (file) {
      this.textarea.value = file.content || '';
    } else {
      this.textarea.value = `// ${name}\n`;
    }

    this.updateLineNumbers();
    this.renderTabs();
    this.consolePane.style.display = 'none';
  }

  openNewFile(path, name) {
    if (!this.openTabs.some(t => t.path === path)) {
      this.openTabs.push({ path, name });
    }
    this.loadFile(path, name);
  }

  saveCurrentFile() {
    this.vfs.writeFile(this.currentPath, this.textarea.value);
    if (this.showToast) {
      this.showToast("Fayl Saqlandi", `'${this.currentName}' VFS xotirasida muvaffaqiyatli saqlandi.`, ICONS.editor);
    }
  }

  runCurrentCode() {
    const code = this.textarea.value;
    this.consolePane.style.display = 'block';

    if (this.currentName.endsWith('.js')) {
      let logs = [];
      const customConsole = {
        log: (...args) => logs.push(args.map(a => typeof a === 'object' ? JSON.stringify(a, null, 2) : String(a)).join(' ')),
        error: (...args) => logs.push('[Xatolik]: ' + args.join(' ')),
        warn: (...args) => logs.push('[Ogohlantirish]: ' + args.join(' '))
      };

      try {
        const runner = new Function('console', code);
        const result = runner(customConsole);
        let out = logs.join('\n');
        if (result !== undefined) {
          out += (out ? '\n' : '') + `[Natija]: ${JSON.stringify(result, null, 2)}`;
        }
        this.consolePane.textContent = `[UzOS JS VFS Interpreteri]:\n${out || '(Skript muvaffaqiyatli bajarildi, chiqish bo\'sh)'}`;
        if (this.showToast) this.showToast("Skript Bajarildi", "JavaScript muvaffaqiyatli yakunlandi.", ICONS.terminal);
      } catch (err) {
        this.consolePane.textContent = `[Sintaksis xatosi]:\n${err.message}`;
        if (this.showToast) this.showToast("Skript Xatosi", err.message, ICONS.shield);
      }
    } else {
      this.consolePane.textContent = `[${this.currentName} Tahlili]:\nFayl muvaffaqiyatli o'qildi (${code.split('\n').length} qator, ${code.length} bayt).`;
      if (this.showToast) this.showToast("Tahlil Yakunlandi", `${this.currentName} fayli tekshirildi.`, ICONS.editor);
    }
  }
}
