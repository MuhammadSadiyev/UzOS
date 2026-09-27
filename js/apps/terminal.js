/* ==============================================================================
   UzOS Cloud (WebOS) — Terminal Application
   Full-featured Interactive Web Shell with Command History and Rich Formatting
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
        <div class="terminal-output" id="term-output">
          <div class="terminal-line info">UzOS Cloud [Versiya 2.0.4 WebOS Shell]</div>
          <div class="terminal-line info">(c) 2026 UzOS Raqamli Suverenitet Ekotizimi. Barcha huquqlar himoyalangan.</div>
          <div class="terminal-line">Mavjud buyruqlarni ko'rish uchun <span style="color:var(--yellow);">'help'</span> deb yozing.</div>
          <div class="terminal-line"></div>
        </div>
        <div class="terminal-prompt-row">
          <span class="terminal-prompt-user">uzos@cloud</span>:<span class="terminal-prompt-path" id="term-path">~${this.currentPath}</span>$
          <input type="text" class="terminal-input" id="term-input" autofocus autocomplete="off" spellcheck="false" />
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
    this.container.addEventListener('click', () => {
      this.inputEl.focus();
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
  mkdir <nom>  - Yangi papka yaratish
  touch <fayl> - Yangi bo'sh fayl yaratish
  rm <fayl>    - Faylni o'chirish
  clear        - Terminal ekranini tozalash
  date         - Joriy sana va vaqt
  whoami       - Joriy foydalanuvchi
  echo <matn>  - Matnni chop etish
  matrix       - Raqamli matritsa effektini ishga tushirish`, 'info');
        break;

      case 'clear':
        this.outputEl.innerHTML = '';
        break;

      case 'pwd':
        this.appendOutput(this.currentPath);
        break;

      case 'whoami':
        this.appendOutput('uzos (Milliy Administrator)');
        break;

      case 'date':
        this.appendOutput(new Date().toLocaleString('uz-UZ', { timeZone: 'Asia/Tashkent' }));
        break;

      case 'echo':
        this.appendOutput(args.join(' '));
        break;

      case 'ls': {
        const items = this.vfs.list(this.currentPath);
        if (items.length === 0) {
          this.appendOutput("(Katalog bo'sh)");
        } else {
          const formatted = items.map(item => item.type === 'directory' ? `📁 ${item.name}/` : `📄 ${item.name}`).join('   ');
          this.appendOutput(formatted, 'success');
        }
        break;
      }

      case 'cd': {
        const target = args[0];
        if (!target || target === '~' || target === '/') {
          this.currentPath = '/';
        } else if (target === '..') {
          const parts = this.currentPath.split('/').filter(Boolean);
          parts.pop();
          this.currentPath = '/' + parts.join('/');
        } else {
          let testPath = target.startsWith('/') ? target : `${this.currentPath}/${target}`.replace('//', '/');
          const node = this.vfs.resolvePath(testPath);
          if (node && node.type === 'directory') {
            this.currentPath = testPath;
          } else {
            this.appendOutput(`cd: papka topilmadi: ${target}`, 'error');
          }
        }
        this.pathEl.textContent = `~${this.currentPath}`;
        break;
      }

      case 'cat': {
        const file = args[0];
        if (!file) {
          this.appendOutput("Foydalanish: cat <fayl_nomi>", 'warning');
          break;
        }
        const filePath = `${this.currentPath}/${file}`.replace('//', '/');
        const content = this.vfs.readFile(filePath);
        if (content !== null) {
          this.appendOutput(content);
        } else {
          this.appendOutput(`cat: fayl topilmadi: ${file}`, 'error');
        }
        break;
      }

      case 'mkdir': {
        const folder = args[0];
        if (!folder) {
          this.appendOutput("Foydalanish: mkdir <papka_nomi>", 'warning');
          break;
        }
        const folderPath = `${this.currentPath}/${folder}`.replace('//', '/');
        if (this.vfs.createFolder(folderPath)) {
          this.appendOutput(`Papka yaratildi: ${folder}`, 'success');
        } else {
          this.appendOutput(`mkdir: yaratib bo'lmadi yoki mavjud: ${folder}`, 'error');
        }
        break;
      }

      case 'touch': {
        const file = args[0];
        if (!file) {
          this.appendOutput("Foydalanish: touch <fayl_nomi>", 'warning');
          break;
        }
        const filePath = `${this.currentPath}/${file}`.replace('//', '/');
        this.vfs.writeFile(filePath, '');
        this.appendOutput(`Fayl yaratildi: ${file}`, 'success');
        break;
      }

      case 'rm': {
        const target = args[0];
        if (!target) {
          this.appendOutput("Foydalanish: rm <nom>", 'warning');
          break;
        }
        const targetPath = `${this.currentPath}/${target}`.replace('//', '/');
        if (this.vfs.delete(targetPath)) {
          this.appendOutput(`O'chirildi: ${target}`, 'warning');
        } else {
          this.appendOutput(`rm: topilmadi: ${target}`, 'error');
        }
        break;
      }

      case 'uzosfetch':
      case 'neofetch':
        this.appendOutput(`
         /\\           Foydalanuvchi: uzos@cloud
        /  \\          OS: UzOS Cloud 2.0 WebOS (O'zbekiston)
       / /\\ \\         Negiz: Web Standards / Modern Vanilla ES6
      / /  \\ \\        Interfeys: Telegram Dark Glassmorphism
     / / /\\ \\ \\       Yadro: Cloud Hypervisor / VFS Engine
    / / /  \\ \\ \\      Xotira: Virtual IndexedDB Persistence
   /_/ /    \\ \\_\\     Telemetriya: 0 B (100% Zero-Telemetry)
     \\ \\    / /       Xavfsizlik: To'liq Shaxsiy Suverenitet
      \\ \\__/ /        Brauzer: ${navigator.userAgent.split(' ')[0]}
       \\____/         Holat: Faol va Tezkor ⚡
`, 'info');
        break;

      case 'matrix':
        this.appendOutput("Raqamli suverenitet matriksiga ulanmoqda...", 'success');
        let count = 0;
        const interval = setInterval(() => {
          const chars = "010101UzOS_SUVEREN_CLOUD_2026_010101";
          let line = "";
          for(let i=0; i<45; i++) line += chars[Math.floor(Math.random()*chars.length)];
          this.appendOutput(line, 'success');
          count++;
          if (count > 6) clearInterval(interval);
        }, 150);
        break;

      default:
        this.appendOutput(`Buyruq topilmadi: '${cmd}'. Yordam uchun 'help' deb yozing.`, 'error');
    }
  }
}
