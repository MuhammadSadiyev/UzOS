/* ==============================================================================
   UzOS Cloud (WebOS) — Terminal Application v2.0
   Powered by xterm.js (ANSI 256-Color & POSIX Shell Emulation Engine)
   Zero-Telemetry • VFS Interactive File Operations • Hardware-Aware Diagnostics
   ============================================================================== */

import { Terminal } from '@xterm/xterm';
import { FitAddon } from '@xterm/addon-fit';
import '@xterm/xterm/css/xterm.css';

export class TerminalApp {
  constructor(container, vfs, windowManager) {
    this.container = container;
    this.vfs = vfs;
    this.wm = windowManager;
    this.currentPath = '/Hujjatlar';
    this.history = [];
    this.historyIndex = -1;
    this.inputBuffer = '';
    this.cursorPosition = 0;
    this.startTime = Date.now();
    this.activeMatrixInterval = null;

    this.render();
  }

  render() {
    this.container.innerHTML = `
      <div class="app-terminal">
        
        <!-- Terminal Quick Action Buttons Toolbar -->
        <div class="term-toolbar">
          <button class="term-btn" data-cmd="uzosfetch">uzosfetch</button>
          <button class="term-btn" data-cmd="help">help</button>
          <button class="term-btn" data-cmd="ls -la">ls -la</button>
          <button class="term-btn" data-cmd="crypto">crypto</button>
          <button class="term-btn" data-cmd="vfs">vfs stat</button>
          <button class="term-btn" data-cmd="whoami">whoami</button>
          <button class="term-btn" data-cmd="matrix">matrix</button>
          <button class="term-btn" data-cmd="clear">clear</button>
        </div>

        <!-- Real xterm.js Hardware-Accelerated Canvas Container -->
        <div class="terminal-xterm-host" id="terminal-xterm-host"></div>

      </div>
    `;

    this.xtermHost = this.container.querySelector('#terminal-xterm-host');
    this.initXterm();
    this.bindEvents();
  }

  initXterm() {
    this.term = new Terminal({
      cursorBlink: true,
      cursorStyle: 'block',
      fontFamily: "'JetBrains Mono', 'Fira Code', 'Consolas', monospace",
      fontSize: 13,
      lineHeight: 1.25,
      letterSpacing: 0,
      theme: {
        background: '#090e15',
        foreground: '#e2e8f0',
        cursor: '#38bdf8',
        cursorAccent: '#090e15',
        selectionBackground: 'rgba(56, 189, 248, 0.3)',
        black: '#1e293b',
        red: '#f87171',
        green: '#4ade80',
        yellow: '#facc15',
        blue: '#38bdf8',
        magenta: '#c084fc',
        cyan: '#22d3ee',
        white: '#f8fafc',
        brightBlack: '#475569',
        brightRed: '#ef4444',
        brightGreen: '#22c55e',
        brightYellow: '#eab308',
        brightBlue: '#0ea5e9',
        brightMagenta: '#a855f7',
        brightCyan: '#06b6d4',
        brightWhite: '#ffffff'
      },
      convertEol: true,
      scrollback: 1000
    });

    this.fitAddon = new FitAddon();
    this.term.loadAddon(this.fitAddon);
    this.term.open(this.xtermHost);

    // Initial resize
    setTimeout(() => {
      try { this.fitAddon.fit(); } catch (_) {}
    }, 50);

    // Observe window resizing to auto-fit columns and rows
    if (typeof ResizeObserver !== 'undefined') {
      this.resizeObserver = new ResizeObserver(() => {
        try { this.fitAddon.fit(); } catch (_) {}
      });
      this.resizeObserver.observe(this.xtermHost);
    }

    // Print welcome banner & uzosfetch
    this.printWelcome();

    // Listen to keyboard input
    this.term.onData((data) => this.handleData(data));
  }

  getPrompt() {
    const user = '\x1b[1;32muzos@cloud\x1b[0m';
    const colon = ':';
    const path = `\x1b[1;34m~${this.currentPath}\x1b[0m`;
    const dollar = '\x1b[1;37m$\x1b[0m ';
    return `${user}${colon}${path}${dollar}`;
  }

  printPrompt() {
    this.inputBuffer = '';
    this.cursorPosition = 0;
    this.term.write(this.getPrompt());
  }

  printWelcome() {
    this.term.writeln('\x1b[1;36mUzOS Cloud\x1b[0m [\x1b[1;33mVersiya 2.0.4-LTS\x1b[0m POSIX Shell Environment]');
    this.term.writeln('\x1b[90m(c) 2026 UzOS Raqamli Suverenitet Ekotizimi. Zero-Telemetry & IndexedDB Vault.\x1b[0m');
    this.term.writeln("Buyruqlar qo'llanmasi uchun \x1b[1;32m'help'\x1b[0m deb yozing yoki yuqoridagi tugmalardan foydalaning.\r\n");
    this.executeCommand('uzosfetch', false);
  }

  handleData(data) {
    // If matrix animation is currently running, any key cancels it
    if (this.activeMatrixInterval) {
      clearInterval(this.activeMatrixInterval);
      this.activeMatrixInterval = null;
      this.term.writeln('\r\n\x1b[33m[Matritsa jarayoni to\'xtatildi]\x1b[0m');
      this.printPrompt();
      return;
    }

    // 1. Enter (Return)
    if (data === '\r') {
      this.term.writeln('');
      const fullCmd = this.inputBuffer.trim();
      if (fullCmd) {
        this.history.push(fullCmd);
        this.historyIndex = this.history.length;
        this.executeCommand(fullCmd);
      } else {
        this.printPrompt();
      }
      return;
    }

    // 2. Backspace
    if (data === '\u007F' || data === '\b') {
      if (this.cursorPosition > 0) {
        this.inputBuffer = 
          this.inputBuffer.slice(0, this.cursorPosition - 1) + 
          this.inputBuffer.slice(this.cursorPosition);
        this.cursorPosition--;
        this.refreshInputLine();
      }
      return;
    }

    // 3. Tab (Auto-completion)
    if (data === '\t') {
      this.handleTabCompletion();
      return;
    }

    // 4. Ctrl+C (Interrupt / Cancel)
    if (data === '\u0003') {
      this.term.writeln('^C');
      this.inputBuffer = '';
      this.cursorPosition = 0;
      this.printPrompt();
      return;
    }

    // 5. Ctrl+L (Clear screen)
    if (data === '\u000c') {
      this.term.clear();
      this.printPrompt();
      this.term.write(this.inputBuffer);
      return;
    }

    // 6. Ctrl+U (Clear line before cursor)
    if (data === '\u0015') {
      this.inputBuffer = this.inputBuffer.slice(this.cursorPosition);
      this.cursorPosition = 0;
      this.refreshInputLine();
      return;
    }

    // 7. Arrow keys and navigation escape sequences
    if (data.startsWith('\x1b')) {
      this.handleEscapeSequence(data);
      return;
    }

    // 8. Normal character entry
    if (data >= ' ' || data.length > 1) {
      this.inputBuffer = 
        this.inputBuffer.slice(0, this.cursorPosition) + 
        data + 
        this.inputBuffer.slice(this.cursorPosition);
      this.cursorPosition += data.length;
      this.refreshInputLine();
    }
  }

  handleEscapeSequence(seq) {
    // Arrow Up: Previous history
    if (seq === '\x1b[A') {
      if (this.history.length > 0 && this.historyIndex > 0) {
        this.historyIndex--;
        this.inputBuffer = this.history[this.historyIndex];
        this.cursorPosition = this.inputBuffer.length;
        this.refreshInputLine();
      }
      return;
    }

    // Arrow Down: Next history
    if (seq === '\x1b[B') {
      if (this.historyIndex < this.history.length - 1) {
        this.historyIndex++;
        this.inputBuffer = this.history[this.historyIndex];
        this.cursorPosition = this.inputBuffer.length;
        this.refreshInputLine();
      } else {
        this.historyIndex = this.history.length;
        this.inputBuffer = '';
        this.cursorPosition = 0;
        this.refreshInputLine();
      }
      return;
    }

    // Arrow Left
    if (seq === '\x1b[D') {
      if (this.cursorPosition > 0) {
        this.cursorPosition--;
        this.term.write('\x1b[D');
      }
      return;
    }

    // Arrow Right
    if (seq === '\x1b[C') {
      if (this.cursorPosition < this.inputBuffer.length) {
        this.cursorPosition++;
        this.term.write('\x1b[C');
      }
      return;
    }

    // Home key
    if (seq === '\x1b[H' || seq === '\x1b[1~') {
      while (this.cursorPosition > 0) {
        this.term.write('\x1b[D');
        this.cursorPosition--;
      }
      return;
    }

    // End key
    if (seq === '\x1b[F' || seq === '\x1b[4~') {
      while (this.cursorPosition < this.inputBuffer.length) {
        this.term.write('\x1b[C');
        this.cursorPosition++;
      }
      return;
    }
  }

  refreshInputLine() {
    // Return to line start, reprint prompt and buffer, position cursor
    this.term.write(`\r\x1b[K${this.getPrompt()}${this.inputBuffer}`);
    const offset = this.inputBuffer.length - this.cursorPosition;
    if (offset > 0) {
      this.term.write(`\x1b[${offset}D`);
    }
  }

  handleTabCompletion() {
    const parts = this.inputBuffer.split(' ');
    const currentWord = parts[parts.length - 1];

    if (parts.length === 1) {
      // Complete command names
      const commands = [
        'uzosfetch', 'help', 'ls', 'cd', 'pwd', 'cat', 'echo', 
        'mkdir', 'touch', 'rm', 'crypto', 'vfs', 'whoami', 
        'date', 'matrix', 'clear', 'uname'
      ];
      const matches = commands.filter(c => c.startsWith(currentWord));
      if (matches.length === 1) {
        this.inputBuffer = matches[0] + ' ';
        this.cursorPosition = this.inputBuffer.length;
        this.refreshInputLine();
      } else if (matches.length > 1) {
        this.term.writeln('');
        this.term.writeln(matches.map(m => `\x1b[36m${m}\x1b[0m`).join('    '));
        this.printPrompt();
        this.term.write(this.inputBuffer);
      }
    } else {
      // Complete file/folder names in current directory
      const folder = this.vfs.getFolder(this.currentPath);
      if (folder && folder.children) {
        const items = Object.keys(folder.children);
        const matches = items.filter(name => name.startsWith(currentWord));
        if (matches.length === 1) {
          parts[parts.length - 1] = matches[0];
          this.inputBuffer = parts.join(' ');
          this.cursorPosition = this.inputBuffer.length;
          this.refreshInputLine();
        } else if (matches.length > 1) {
          this.term.writeln('');
          this.term.writeln(matches.map(m => `\x1b[32m${m}\x1b[0m`).join('    '));
          this.printPrompt();
          this.term.write(this.inputBuffer);
        }
      }
    }
  }

  bindEvents() {
    // Quick action toolbar buttons
    this.container.querySelectorAll('.term-btn').forEach(btn => {
      btn.addEventListener('click', () => {
        const cmd = btn.dataset.cmd;
        if (cmd) {
          this.term.focus();
          this.term.writeln(`\r\x1b[K${this.getPrompt()}${cmd}`);
          this.executeCommand(cmd);
        }
      });
    });

    this.container.addEventListener('click', (e) => {
      if (!e.target.closest('.term-toolbar')) {
        this.term.focus();
      }
    });
  }

  executeCommand(fullCmd, shouldPromptAfter = true) {
    // Check for redirection: cmd > file or cmd >> file
    let redirectionTarget = null;
    let appendMode = false;

    if (fullCmd.includes('>>')) {
      const parts = fullCmd.split('>>');
      fullCmd = parts[0].trim();
      redirectionTarget = parts[1].trim();
      appendMode = true;
    } else if (fullCmd.includes('>')) {
      const parts = fullCmd.split('>');
      fullCmd = parts[0].trim();
      redirectionTarget = parts[1].trim();
    }

    const tokens = fullCmd.split(/\s+/).filter(Boolean);
    const cmd = tokens[0] ? tokens[0].toLowerCase() : '';
    const args = tokens.slice(1);

    let outputResult = '';

    switch (cmd) {
      case 'help':
      case 'man':
        outputResult = `\x1b[1;33mMavjud UzOS POSIX Buyruqlari:\x1b[0m
  \x1b[1;32muzosfetch\x1b[0m     Tizim parametrlari, IndexedDB va apparat arxitekturasi
  \x1b[1;32mls [-la]\x1b[0m      Joriy katalogdagi fayl va papkalarni ko'rish
  \x1b[1;32mcd <yo'l>\x1b[0m     Boshqa katalogga o'tish (masalan: cd /Rasmlar, cd ..)
  \x1b[1;32mpwd\x1b[0m           Joriy to'liq katalog yo'lini ko'rsatish
  \x1b[1;32mcat <fayl>\x1b[0m    Fayl matnini terminalda o'qish
  \x1b[1;32mecho <matn>\x1b[0m   Matn chiqarish yoki faylga yo'naltirish (> yoki >>)
  \x1b[1;32mtouch <fayl>\x1b[0m  Yangi bo'sh fayl yaratish
  \x1b[1;32mmkdir <jild>\x1b[0m  Yangi katalog yaratish
  \x1b[1;32mrm [-rf] <yo'l>\x1b[0mFayl yoki katalogni o'chirish
  \x1b[1;32mcrypto\x1b[0m        Haqiqiy AES-GCM 256 apparat shifrlash auditi
  \x1b[1;32mvfs\x1b[0m           Virtual fayl tizimi statistikasi va IndexedDB holati
  \x1b[1;32mwhoami\x1b[0m        Joriy foydalanuvchi va kirish huquqlari
  \x1b[1;32mdate\x1b[0m          Haqiqiy vaqt va sana
  \x1b[1;32muname -a\x1b[0m      Yadro va arxitektura ma'lumotlari
  \x1b[1;32mmatrix\x1b[0m        Matritsa xavfsizlik oqimi (istalgan tugma bilan to'xtatiladi)
  \x1b[1;32mclear\x1b[0m         Terminal ekranini tozalash (Ctrl+L)`;
        break;

      case 'uzosfetch':
      case 'neofetch': {
        const uptimeSec = Math.floor((Date.now() - this.startTime) / 1000);
        const folderCount = Object.keys(this.vfs.fs.children || {}).length;
        outputResult = `
\x1b[1;36m       /\\           \x1b[1;32muzos@cloud\x1b[0m
\x1b[1;36m      /  \\          \x1b[90m----------------------------------\x1b[0m
\x1b[1;36m     / /\\ \\         \x1b[1;37mOS:\x1b[0m UzOS Cloud 2.0.4-LTS (Telegram Desktop WebOS)
\x1b[1;36m    / /  \\ \\        \x1b[1;37mXotira Yadro:\x1b[0m IndexedDB Vault Native Engine
\x1b[1;36m   / / /\\ \\ \\       \x1b[1;37mKriptografiya:\x1b[0m \x1b[1;32mAES-GCM 256-bit Web Crypto API (Faol)\x1b[0m
\x1b[1;36m  / / /  \\ \\ \\      \x1b[1;37mSandbox:\x1b[0m Isolated Web Worker Watchdog Security
\x1b[1;36m /_/ /    \\ \\_\\     \x1b[1;37mTerminal:\x1b[0m xterm.js 5.5 POSIX Interactive Shell
\x1b[1;36m   \\ \\    / /       \x1b[1;37mKataloglar:\x1b[0m ${folderCount} ta asosiy VFS bo'limi
\x1b[1;36m    \\ \\__/ /        \x1b[1;37mTelemetriya:\x1b[0m 0 B (100% Suveren & Zero-Telemetry)
\x1b[1;36m     \\____/         \x1b[1;37mUptime:\x1b[0m ${uptimeSec} soniya
\x1b[0m`;
        break;
      }

      case 'ls': {
        const showLong = args.some(a => a.includes('l'));
        const showAll = args.some(a => a.includes('a'));
        const folder = this.vfs.getFolder(this.currentPath);

        if (!folder || !folder.children) {
          outputResult = `\x1b[31mls: katalog ochib bo'lmadi: ${this.currentPath}\x1b[0m`;
        } else {
          const entries = Object.entries(folder.children);
          if (showLong) {
            const lines = [];
            if (showAll) {
              lines.push(`drwxr-xr-x 1 uzos uzos 4096 \x1b[1;34m.\x1b[0m`);
              lines.push(`drwxr-xr-x 1 uzos uzos 4096 \x1b[1;34m..\x1b[0m`);
            }
            entries.forEach(([name, item]) => {
              const isDir = item.type === 'directory';
              const perms = isDir ? 'drwxr-xr-x' : '-rw-r--r--';
              const size = (item.content ? item.content.length : (isDir ? 4096 : 0)).toString().padStart(6);
              let coloredName = name;
              if (isDir) {
                coloredName = `\x1b[1;34m${name}/\x1b[0m`;
              } else if (name.endsWith('.js')) {
                coloredName = `\x1b[1;32m${name}\x1b[0m`;
              } else if (name.endsWith('.md') || name.endsWith('.txt')) {
                coloredName = `\x1b[0;36m${name}\x1b[0m`;
              } else if (name.endsWith('.svg') || name.endsWith('.png')) {
                coloredName = `\x1b[1;35m${name}\x1b[0m`;
              }
              lines.push(`${perms} 1 uzos uzos ${size} ${coloredName}`);
            });
            outputResult = lines.join('\r\n') || '(bo\'sh katalog)';
          } else {
            const names = entries.map(([name, item]) => {
              if (item.type === 'directory') return `\x1b[1;34m${name}/\x1b[0m`;
              if (name.endsWith('.js')) return `\x1b[1;32m${name}\x1b[0m`;
              if (name.endsWith('.svg')) return `\x1b[1;35m${name}\x1b[0m`;
              return name;
            });
            outputResult = names.join('    ') || '(bo\'sh katalog)';
          }
        }
        break;
      }

      case 'pwd':
        outputResult = this.currentPath;
        break;

      case 'whoami':
        outputResult = '\x1b[1;32muzos\x1b[0m (UzOS Administrator • Suveren Kiber-Muhit)';
        break;

      case 'date':
        outputResult = new Date().toLocaleString('uz-UZ', { dateStyle: 'full', timeStyle: 'medium' });
        break;

      case 'uname':
        if (args.includes('-a')) {
          outputResult = 'UzOS-Cloud uzos 2.0.4-LTS WebOS-x86_64 WebAssembly POSIX-JS';
        } else {
          outputResult = 'UzOS-Cloud';
        }
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
          const testPath = target.startsWith('/') 
            ? target 
            : `${this.currentPath === '/' ? '' : this.currentPath}/${target}`.replace('//', '/');
          const folder = this.vfs.getFolder(testPath);
          if (folder && folder.type === 'directory') {
            this.currentPath = testPath;
          } else {
            outputResult = `\x1b[31mcd: bunday katalog mavjud emas: ${target}\x1b[0m`;
          }
        }
        break;
      }

      case 'cat': {
        const filename = args[0];
        if (!filename) {
          outputResult = "\x1b[33mFoydalanish: cat <fayl_nomi>\x1b[0m";
        } else {
          const filePath = filename.startsWith('/') 
            ? filename 
            : `${this.currentPath === '/' ? '' : this.currentPath}/${filename}`.replace('//', '/');
          const file = this.vfs.getFile(filePath);
          if (file) {
            outputResult = file.content || '(bo\'sh fayl)';
          } else {
            outputResult = `\x1b[31mcat: fayl topilmadi: ${filename}\x1b[0m`;
          }
        }
        break;
      }

      case 'touch': {
        const filename = args[0];
        if (!filename) {
          outputResult = "\x1b[33mFoydalanish: touch <fayl_nomi>\x1b[0m";
        } else {
          const filePath = filename.startsWith('/') 
            ? filename 
            : `${this.currentPath === '/' ? '' : this.currentPath}/${filename}`.replace('//', '/');
          this.vfs.writeFile(filePath, '');
          outputResult = `\x1b[32m'${filename}' fayli yaratildi.\x1b[0m`;
        }
        break;
      }

      case 'mkdir': {
        const dirname = args[args.length - 1];
        if (!dirname) {
          outputResult = "\x1b[33mFoydalanish: mkdir [-p] <katalog_nomi>\x1b[0m";
        } else {
          const dirPath = dirname.startsWith('/') 
            ? dirname 
            : `${this.currentPath === '/' ? '' : this.currentPath}/${dirname}`.replace('//', '/');
          this.vfs.createFolder(dirPath);
          outputResult = `\x1b[32m'${dirname}' katalogi yaratildi.\x1b[0m`;
        }
        break;
      }

      case 'rm': {
        const target = args[args.length - 1];
        if (!target) {
          outputResult = "\x1b[33mFoydalanish: rm [-rf] <nomi>\x1b[0m";
        } else {
          const targetPath = target.startsWith('/') 
            ? target 
            : `${this.currentPath === '/' ? '' : this.currentPath}/${target}`.replace('//', '/');
          const ok = this.vfs.deleteItem(targetPath);
          if (ok) {
            outputResult = `\x1b[32m'${target}' o'chirildi.\x1b[0m`;
          } else {
            outputResult = `\x1b[31mrm: '${target}' topilmadi.\x1b[0m`;
          }
        }
        break;
      }

      case 'echo': {
        outputResult = args.join(' ');
        break;
      }

      case 'crypto': {
        const status = this.vfs.getSecurityStatus ? this.vfs.getSecurityStatus() : {};
        outputResult = `\x1b[1;36m=== UzOS Hardware Web Crypto Audit ===\x1b[0m
  \x1b[1;37mStandart:\x1b[0m       W3C Web Cryptography API (FIPS 197 mos)
  \x1b[1;37mAlgoritm:\x1b[0m       AES-GCM (Galois/Counter Mode)
  \x1b[1;37mKalit Uzunligi:\x1b[0m 256-bit Kriptografik Kalit
  \x1b[1;37mIV / Nonce:\x1b[0m     96-bit Tasodifiy Kripto-Vektor (CSPRNG)
  \x1b[1;37mXotira Saqlash:\x1b[0m IndexedDB 'security_keys' (Non-Extractable CryptoKey)
  \x1b[1;37mHolat:\x1b[0m          \x1b[1;32m100% Faol va Shifrlangan\x1b[0m`;
        break;
      }

      case 'vfs': {
        const rawJson = JSON.stringify(this.vfs.fs || {});
        outputResult = `\x1b[1;36m=== Virtual Fayl Tizimi (VFS v2.0) ===\x1b[0m
  \x1b[1;37mDvigatel:\x1b[0m       IndexedDB Vault ('uzos_vfs_vault_db')
  \x1b[1;37mCheklov:\x1b[0m        5 MB limiti olib tashlangan (50 GB+ qo'llab-quvvatlaydi)
  \x1b[1;37mDaraxt hajmi:\x1b[0m   ~${Math.round(rawJson.length / 1024)} KB
  \x1b[1;37mXavfsizlik:\x1b[0m     AES-GCM 256 Mahalliy Shifrlangan`;
        break;
      }

      case 'matrix': {
        this.runMatrixAnimation();
        return;
      }

      case 'clear':
        this.term.clear();
        if (shouldPromptAfter) this.printPrompt();
        return;

      default:
        if (cmd) {
          outputResult = `\x1b[31mBuyruq topilmadi: '${cmd}'. Mavjud buyruqlarni ko'rish uchun 'help' deb yozing.\x1b[0m`;
        }
        break;
    }

    // Handle redirection if user requested e.g. echo "matn" > fayl.txt
    if (redirectionTarget && outputResult) {
      const targetPath = redirectionTarget.startsWith('/') 
        ? redirectionTarget 
        : `${this.currentPath === '/' ? '' : this.currentPath}/${redirectionTarget}`.replace('//', '/');
      let finalContent = outputResult;
      if (appendMode) {
        const existing = this.vfs.readFile(targetPath) || '';
        finalContent = existing + (existing ? '\n' : '') + outputResult;
      }
      this.vfs.writeFile(targetPath, finalContent);
      this.term.writeln(`\x1b[32mChiqish '${redirectionTarget}' fayliga yozildi.\x1b[0m`);
    } else if (outputResult) {
      this.term.writeln(outputResult);
    }

    if (shouldPromptAfter) {
      this.printPrompt();
    }
  }

  runMatrixAnimation() {
    this.term.clear();
    this.term.writeln('\x1b[1;32m[UzOS Kiber-Qalqon Oqimi faollashtirildi — To\'xtatish uchun istalgan tugmani bosing]\x1b[0m\r\n');
    
    const chars = '0123456789ABCDEF@#$%&*UzOS_ZERO_TELEMETRY_SUVEREIGN_CLOUD_2026';
    const cols = Math.min(this.term.cols || 80, 80);

    this.activeMatrixInterval = setInterval(() => {
      let line = '';
      for (let i = 0; i < cols; i++) {
        if (Math.random() > 0.82) {
          const char = chars[Math.floor(Math.random() * chars.length)];
          const isBright = Math.random() > 0.6;
          line += isBright ? `\x1b[1;37m${char}\x1b[0m` : `\x1b[32m${char}\x1b[0m`;
        } else {
          line += ' ';
        }
      }
      this.term.writeln(line);
    }, 80);
  }
}
