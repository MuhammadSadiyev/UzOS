/* ==============================================================================
   UzOS Cloud (WebOS) — Terminal Application
   Full-featured Interactive Web Shell with Toolbar, uzosfetch & Command History
   ============================================================================== */

export class TerminalApp {
  constructor(container, vfs, windowManager) {
    this.container = container;
    this.vfs = vfs;
    this.wm = windowManager;
    this.currentPath = '/Hujjatlar';
    this.history = [];
    this.historyIndex = -1;

    this.render();
  }

  render() {
    this.container.innerHTML = `
      <div class="app-terminal">
        
        <!-- Terminal Quick Action Buttons Toolbar -->
        <div class="term-toolbar">
          <button class="term-btn" data-cmd="uzosfetch">⚡ uzosfetch</button>
          <button class="term-btn" data-cmd="help">❓ help</button>
          <button class="term-btn" data-cmd="ls">📁 ls</button>
          <button class="term-btn" data-cmd="matrix">🟢 matrix</button>
          <button class="term-btn" data-cmd="whoami">👤 whoami</button>
          <button class="term-btn" data-cmd="date">📅 date</button>
          <button class="term-btn" data-cmd="clear">🧹 tozalash</button>
        </div>

        <!-- Terminal Output Area -->
        <div class="terminal-output" id="term-output">
          <div class="terminal-line info">UzOS Cloud [Versiya 2.0.4 WebOS Hypervisor Shell]</div>
          <div class="terminal-line info">(c) 2026 UzOS Raqamli Suverenitet Ekotizimi. 100% Zero-Telemetry.</div>
          <div class="terminal-line">Mavjud buyruqlarni ko'rish uchun <span style="color:#38bdf8;">'help'</span> deb yozing yoki yuqoridagi tugmalarni bosing.</div>
          <div class="terminal-line"></div>
        </div>

        <!-- Terminal Prompt Input Row -->
        <div class="terminal-prompt-row">
          <span class="terminal-prompt-user">uzos@cloud</span>:<span class="terminal-prompt-path" id="term-path">~${this.currentPath}</span>$&nbsp;
          <input type="text" class="terminal-input" id="term-input" autofocus autocomplete="off" spellcheck="false" placeholder="Buyruq yozing..." />
        </div>

      </div>
    `;

    this.outputEl = this.container.querySelector('#term-output');
    this.inputEl = this.container.querySelector('#term-input');
    this.pathEl = this.container.querySelector('#term-path');

    this.bindEvents();
    this.executeCommand('uzosfetch');
  }

  bindEvents() {
    this.container.addEventListener('click', (e) => {
      if (!e.target.closest('.term-toolbar')) {
        this.inputEl.focus();
      }
    });

    // Toolbar buttons
    this.container.querySelectorAll('.term-btn').forEach(btn => {
      btn.addEventListener('click', () => {
        const cmd = btn.dataset.cmd;
        this.executeCommand(cmd);
      });
    });

    this.inputEl.addEventListener('keydown', (e) => {
      if (e.key === 'Enter') {
        const cmd = this.inputEl.value.trim();
        this.inputEl.value = '';
        if (cmd) {
          this.history.push(cmd);
          this.historyIndex = this.history.length;
          this.executeCommand(cmd);
        } else {
          this.appendOutput(`uzos@cloud:~${this.currentPath}$ `, 'normal');
        }
      } else if (e.key === 'ArrowUp') {
        e.preventDefault();
        if (this.historyIndex > 0) {
          this.historyIndex--;
          this.inputEl.value = this.history[this.historyIndex];
        }
      } else if (e.key === 'ArrowDown') {
        e.preventDefault();
        if (this.historyIndex < this.history.length - 1) {
          this.historyIndex++;
          this.inputEl.value = this.history[this.historyIndex];
        } else {
          this.historyIndex = this.history.length;
          this.inputEl.value = '';
        }
      }
    });
  }

  appendOutput(text, type = 'normal') {
    const line = document.createElement('div');
    line.className = `terminal-line ${type}`;
    line.textContent = text;
    this.outputEl.appendChild(line);
    this.outputEl.scrollTop = this.outputEl.scrollHeight;
  }

  executeCommand(fullCmd) {
    this.appendOutput(`uzos@cloud:~${this.currentPath}$ ${fullCmd}`, 'normal');
    const [cmd, ...args] = fullCmd.split(' ');

    switch (cmd.toLowerCase()) {
      case 'help':
        this.appendOutput(`Mavjud buyruqlar ro'yxati:
  uzosfetch    - Tizim haqida to'liq vizual ma'lumot
  ls           - Joriy katalogdagi fayllar va papkalar
  cd <yo'l>    - Boshqa katalogga o'tish (masalan: cd /Rasmlar)
  pwd          - Joriy to'liq yo'lni ko'rsatish
  cat <fayl>   - Fayl matnini o'qish va ekranga chiqarish
  whoami       - Joriy foydalanuvchi ma'lumoti
  date         - Sana va vaqt
  matrix       - Matritsa kodlar animatsiyasi
  clear        - Terminal ekranini tozalash`, 'info');
        break;

      case 'uzosfetch':
        this.appendOutput(`
         /\\           Foydalanuvchi: uzos@cloud
        /  \\          OS: UzOS Cloud 2.0.4 (Telegram Desktop WebOS)
       / /\\ \\         Yadro: Web Hypervisor VFS / Rust WebAssembly
      / /  \\ \\        Dizayn: 100% Telegram Desktop 1:1 UI
     / / /\\ \\ \\       Telemetriya: 0 B (100% Zero-Telemetry)
    / / /  \\ \\ \\      Kriptografiya: AES-GCM 256-bit Mahalliy
   /_/ /    \\ \\_\\     Xotira: 112 MB / 8 GB (30x Yengil)
     \\ \\    / /       Uptime: 99.9% (Web Sandbox)
      \\ \\__/ /        Holat: 100% Suveren & Faol ⚡
       \\____/
`, 'info');
        break;

      case 'ls': {
        const folder = this.vfs.getFolder(this.currentPath);
        if (folder && folder.children) {
          const names = Object.entries(folder.children).map(([name, item]) => {
            return item.type === 'directory' ? `📁 ${name}/` : `📄 ${name}`;
          });
          this.appendOutput(names.join('    ') || '(katalog bo\'sh)', 'success');
        } else {
          this.appendOutput('Katalog topilmadi.', 'error');
        }
        break;
      }

      case 'pwd':
        this.appendOutput(this.currentPath, 'normal');
        break;

      case 'whoami':
        this.appendOutput('uzos (Milliy Administrator • O\'zbekiston Respublikasi)', 'success');
        break;

      case 'date':
        this.appendOutput(new Date().toLocaleString('uz-UZ'), 'normal');
        break;

      case 'cd': {
        const target = args[0];
        if (!target || target === '~' || target === '/') {
          this.currentPath = '/';
        } else if (target === '..') {
          const parts = this.currentPath.split('/').filter(Boolean);
          parts.pop();
          this.currentPath = parts.length ? '/' + parts.join('/') : '/';
        } else {
          const testPath = target.startsWith('/') ? target : `${this.currentPath}/${target}`.replace('//', '/');
          const folder = this.vfs.getFolder(testPath);
          if (folder) {
            this.currentPath = testPath;
          } else {
            this.appendOutput(`cd: bunday katalog mavjud emas: ${target}`, 'error');
          }
        }
        this.pathEl.textContent = `~${this.currentPath}`;
        break;
      }

      case 'cat': {
        const fileName = args[0];
        if (!fileName) {
          this.appendOutput('Foydalanish: cat <fayl_nomi>', 'warning');
          return;
        }
        const filePath = fileName.startsWith('/') ? fileName : `${this.currentPath}/${fileName}`.replace('//', '/');
        const file = this.vfs.getFile(filePath);
        if (file) {
          this.appendOutput(file.content || '(bo\'sh fayl)', 'normal');
        } else {
          this.appendOutput(`cat: fayl topilmadi: ${fileName}`, 'error');
        }
        break;
      }

      case 'matrix':
        this.appendOutput('0101010101010101 UZOS CLOUD VFS MATRIX 0101010101010101', 'success');
        this.appendOutput('0011001001010101 ZERO TELEMETRY 2026 1010101001010101', 'info');
        this.appendOutput('1110001110001110 SUVEREN BULUT TIZIMI 0001110001110001', 'success');
        break;

      case 'clear':
        this.outputEl.innerHTML = '';
        break;

      default:
        this.appendOutput(`Buyruq topilmadi: '${cmd}'. Mavjud buyruqlar uchun 'help' deb yozing.`, 'error');
    }
  }
}
