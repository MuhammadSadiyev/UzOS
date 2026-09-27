/* ==============================================================================
   UzOS Cloud (WebOS) — Virtual File System (VFS)
   Persistent Browser Storage with Folder Hierarchy and File Management
   ============================================================================== */

export class VirtualFileSystem {
  constructor() {
    this.STORAGE_KEY = 'uzos_cloud_vfs_v1';
    this.fs = this.loadFileSystem();
  }

  loadFileSystem() {
    try {
      const saved = localStorage.getItem(this.STORAGE_KEY);
      if (saved) {
        return JSON.parse(saved);
      }
    } catch (e) {
      console.warn('VFS failed to load from localStorage:', e);
    }
    return this.createDefaultFileSystem();
  }

  save() {
    try {
      localStorage.setItem(this.STORAGE_KEY, JSON.stringify(this.fs));
    } catch (e) {
      console.error('VFS save error:', e);
    }
  }

  createDefaultFileSystem() {
    return {
      name: '/',
      type: 'directory',
      children: {
        'Hujjatlar': {
          type: 'directory',
          children: {
            'Xush_kelibsiz.txt': {
              type: 'file',
              mime: 'text/plain',
              content: "Assalomu alaykum!\n\nUzOS Cloud — O'zbekiston Milliy Bulut Operatsion Tizimiga xush kelibsiz!\nBu brauzerda 1 soniyada ochiluvchi, 100% ochiq kodli va xavfsiz shaxsiy ish stoli muhitidir.\n\nSiz bu yerda fayllar yaratishingiz, tahrirlashingiz, terminalda buyruqlar bajarishingiz va Milliy AI yordamchisidan foydalanishingiz mumkin."
            },
            'Loyiha_haqida.md': {
              type: 'file',
              mime: 'text/markdown',
              content: "# UzOS Cloud (WebOS)\n\n* **Maqsad:** Milliy raqamli suverenitet va erkin bulut ish stoli\n* **Texnologiya:** Web Standards, Vanilla JS, Telegram Dark Glassmorphism\n* **Muallif:** Muhammad Sadiyev\n* **Status:** 100% Zero-Telemetry, Tejamkor va O'ta Tezkor"
            },
            'script.js': {
              type: 'file',
              mime: 'text/javascript',
              content: "// UzOS Cloud Web Script\nfunction salomlash() {\n  const davlat = \"O'zbekiston\";\n  console.log(`Assalomu alaykum, ${davlat}!`);\n}\nsalomlash();\n"
            }
          }
        },
        'Rasmlar': {
          type: 'directory',
          children: {
            'Oʻzbekiston_bayrogʻi.svg': {
              type: 'file',
              mime: 'image/svg+xml',
              content: `<svg xmlns="http://www.w3.org/2000/svg" width="250" height="125" viewBox="0 0 500 250">
  <rect width="500" height="250" fill="#1eb53a"/>
  <rect width="500" height="166.6" fill="#ce1126"/>
  <rect width="500" height="161.6" fill="#fff"/>
  <rect width="500" height="88.3" fill="#ce1126"/>
  <rect width="500" height="83.3" fill="#0099b5"/>
  <circle cx="70" cy="41.6" r="30" fill="#fff"/>
  <circle cx="80" cy="41.6" r="30" fill="#0099b5"/>
</svg>`
            }
          }
        },
        'Yuklamalar': {
          type: 'directory',
          children: {}
        },
        'Chiqindilar': {
          type: 'directory',
          children: {}
        }
      }
    };
  }

  resolvePath(path) {
    if (!path || path === '/' || path === '') return this.fs;
    const parts = path.split('/').filter(p => p.length > 0);
    let current = this.fs;

    for (const part of parts) {
      if (current.type !== 'directory' || !current.children || !current.children[part]) {
        return null;
      }
      current = current.children[part];
    }
    return current;
  }

  list(path = '/') {
    const node = this.resolvePath(path);
    if (!node || node.type !== 'directory') return [];

    return Object.entries(node.children).map(([name, item]) => ({
      name,
      type: item.type,
      mime: item.mime || null,
      size: item.content ? item.content.length : 0
    }));
  }

  readFile(filePath) {
    const node = this.resolvePath(filePath);
    if (!node || node.type !== 'file') return null;
    return node.content;
  }

  writeFile(filePath, content, mime = 'text/plain') {
    const parts = filePath.split('/').filter(p => p.length > 0);
    const fileName = parts.pop();
    const parentPath = parts.join('/');

    const parentNode = this.resolvePath(parentPath);
    if (!parentNode || parentNode.type !== 'directory') return false;

    parentNode.children[fileName] = {
      type: 'file',
      mime,
      content
    };

    this.save();
    return true;
  }

  createFolder(folderPath) {
    const parts = folderPath.split('/').filter(p => p.length > 0);
    const folderName = parts.pop();
    const parentPath = parts.join('/');

    const parentNode = this.resolvePath(parentPath);
    if (!parentNode || parentNode.type !== 'directory') return false;

    if (parentNode.children[folderName]) return false; // Already exists

    parentNode.children[folderName] = {
      type: 'directory',
      children: {}
    };

    this.save();
    return true;
  }

  delete(path) {
    const parts = path.split('/').filter(p => p.length > 0);
    const targetName = parts.pop();
    const parentPath = parts.join('/');

    const parentNode = this.resolvePath(parentPath);
    if (!parentNode || parentNode.type !== 'directory') return false;

    if (parentNode.children[targetName]) {
      delete parentNode.children[targetName];
      this.save();
      return true;
    }
    return false;
  }

  reset() {
    this.fs = this.createDefaultFileSystem();
    this.save();
  }
}
