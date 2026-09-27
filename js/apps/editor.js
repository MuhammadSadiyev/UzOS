/* ==============================================================================
   UzOS Cloud (WebOS) — Code & Text Editor Application
   ============================================================================== */

export class EditorApp {
  constructor(container, vfs, filePath = '/Hujjatlar/Xush_kelibsiz.txt', fileName = 'Xush_kelibsiz.txt', showNotification) {
    this.container = container;
    this.vfs = vfs;
    this.filePath = filePath;
    this.fileName = fileName;
    this.notify = showNotification;

    this.render();
  }

  render() {
    const initialContent = this.vfs.readFile(this.filePath) || '// Yangi fayl tahrirlagichi\n';

    this.container.innerHTML = `
      <div class="app-editor">
        <!-- Tabs & Actions -->
        <div class="editor-tabs">
          <div class="editor-tab active" id="editor-active-tab">
            <span>📝</span>
            <span id="editor-filename">${this.fileName}</span>
          </div>
          <div style="margin-left: auto; display: flex; gap: 8px;">
            <button class="files-btn" id="editor-save-btn" style="padding: 2px 10px; font-size: 11.5px; background: var(--accent);">
              💾 Saqlash (Ctrl+S)
            </button>
          </div>
        </div>

        <!-- Main Editor Body -->
        <div class="editor-main">
          <div class="editor-linenums" id="editor-linenums">1</div>
          <textarea class="editor-textarea" id="editor-textarea" spellcheck="false">${initialContent}</textarea>
        </div>

        <!-- Status Bar -->
        <div class="editor-status">
          <span id="editor-stats">Qator: 1 | Ustun: 1</span>
          <span>UTF-8 | UzOS Code Engine</span>
        </div>
      </div>
    `;

    this.textarea = this.container.querySelector('#editor-textarea');
    this.linenums = this.container.querySelector('#editor-linenums');
    this.stats = this.container.querySelector('#editor-stats');
    this.saveBtn = this.container.querySelector('#editor-save-btn');

    this.bindEvents();
    this.updateLineNumbers();
  }

  bindEvents() {
    this.textarea.addEventListener('input', () => {
      this.updateLineNumbers();
    });

    this.textarea.addEventListener('scroll', () => {
      this.linenums.scrollTop = this.textarea.scrollTop;
    });

    this.textarea.addEventListener('keyup', () => {
      this.updateCursorStats();
    });

    this.textarea.addEventListener('click', () => {
      this.updateCursorStats();
    });

    // Save action
    this.saveBtn.addEventListener('click', () => {
      this.saveFile();
    });

    this.textarea.addEventListener('keydown', (e) => {
      if ((e.ctrlKey || e.metaKey) && e.key === 's') {
        e.preventDefault();
        this.saveFile();
      }
    });
  }

  saveFile() {
    const content = this.textarea.value;
    this.vfs.writeFile(this.filePath, content);
    if (this.notify) {
      this.notify("Fayl saqlandi", `'${this.fileName}' muvaffaqiyatli saqlandi!`, "💾");
    }
  }

  updateLineNumbers() {
    const lines = this.textarea.value.split('\n').length;
    let nums = '';
    for (let i = 1; i <= lines; i++) {
      nums += i + '\n';
    }
    this.linenums.textContent = nums;
  }

  updateCursorStats() {
    const text = this.textarea.value.substr(0, this.textarea.selectionStart);
    const line = text.split('\n').length;
    const col = text.split('\n').pop().length + 1;
    this.stats.textContent = `Qator: ${line} | Ustun: ${col} | Belgi: ${this.textarea.value.length}`;
  }

  openNewFile(path, name) {
    this.filePath = path;
    this.fileName = name;
    this.container.querySelector('#editor-filename').textContent = name;
    this.textarea.value = this.vfs.readFile(path) || '';
    this.updateLineNumbers();
    this.updateCursorStats();
  }
}
