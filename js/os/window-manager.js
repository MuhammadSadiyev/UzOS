/* ==============================================================================
   UzOS Cloud (WebOS) — Window Manager (Core Engine)
   Multi-window, Dragging, Resizing, Z-Index, Snapping, Minimize/Maximize
   ============================================================================== */

export class WindowManager {
  constructor(workspaceElement) {
    this.workspace = workspaceElement;
    this.windows = new Map(); // id -> window state
    this.activeWindowId = null;
    this.baseZIndex = 100;
    this.highestZIndex = 100;
    
    // Event callbacks
    this.onWindowListChange = null;
    this.onActiveChange = null;

    this.initGlobalListeners();
  }

  initGlobalListeners() {
    // Window click to focus
    document.addEventListener('pointerdown', (e) => {
      const winEl = e.target.closest('.uzos-window');
      if (winEl) {
        this.focusWindow(winEl.dataset.windowId);
      }
    });

    // Handle Escape or shortcut keys
    window.addEventListener('keydown', (e) => {
      if (e.key === 'Escape' && this.activeWindowId) {
        // Optional quick actions
      }
    });
  }

  createWindow({ id, title, icon = '🪟', width = 640, height = 440, minWidth = 360, minHeight = 260, content = '', appType = 'generic' }) {
    if (this.windows.has(id)) {
      const existing = this.windows.get(id);
      if (existing.minimized) {
        this.restoreWindow(id);
      }
      this.focusWindow(id);
      return existing;
    }

    // Smart cascade positioning
    const wsRect = this.workspace.getBoundingClientRect();
    const count = this.windows.size;
    const defaultX = Math.max(20, Math.min(wsRect.width - width - 40, 40 + (count % 8) * 30));
    const defaultY = Math.max(20, Math.min(wsRect.height - height - 40, 30 + (count % 8) * 30));

    // Create DOM element
    const winEl = document.createElement('div');
    winEl.className = 'uzos-window';
    winEl.dataset.windowId = id;
    winEl.style.width = `${width}px`;
    winEl.style.height = `${height}px`;
    winEl.style.left = `${defaultX}px`;
    winEl.style.top = `${defaultY}px`;
    winEl.style.zIndex = ++this.highestZIndex;

    // Window Inner Structure
    winEl.innerHTML = `
      <!-- Titlebar -->
      <div class="window-titlebar">
        <div class="window-info">
          <span class="window-icon">${icon}</span>
          <span class="window-title">${title}</span>
        </div>
        <div class="window-controls">
          <button class="win-btn minimize" title="Kichraytirish (Minimize)">―</button>
          <button class="win-btn maximize" title="Kattalashtirish (Maximize)">□</button>
          <button class="win-btn close" title="Yopish (Close)">✕</button>
        </div>
      </div>
      
      <!-- Body -->
      <div class="window-body">
        ${content}
      </div>

      <!-- Resizing Handles -->
      <div class="resize-handle resize-n"></div>
      <div class="resize-handle resize-s"></div>
      <div class="resize-handle resize-e"></div>
      <div class="resize-handle resize-w"></div>
      <div class="resize-handle resize-ne"></div>
      <div class="resize-handle resize-nw"></div>
      <div class="resize-handle resize-se"></div>
      <div class="resize-handle resize-sw"></div>
    `;

    this.workspace.appendChild(winEl);

    const winState = {
      id,
      title,
      icon,
      appType,
      element: winEl,
      minimized: false,
      maximized: false,
      minWidth,
      minHeight,
      prevBounds: { x: defaultX, y: defaultY, width, height }
    };

    this.windows.set(id, winState);

    // Bind Controls
    this.bindWindowEvents(winState);

    // Focus newly created window
    this.focusWindow(id);
    this.triggerWindowListChange();

    return winState;
  }

  bindWindowEvents(winState) {
    const el = winState.element;
    const titlebar = el.querySelector('.window-titlebar');
    const minBtn = el.querySelector('.win-btn.minimize');
    const maxBtn = el.querySelector('.win-btn.maximize');
    const closeBtn = el.querySelector('.win-btn.close');

    // Titlebar Buttons
    minBtn.addEventListener('click', (e) => {
      e.stopPropagation();
      this.minimizeWindow(winState.id);
    });

    maxBtn.addEventListener('click', (e) => {
      e.stopPropagation();
      this.toggleMaximizeWindow(winState.id);
    });

    closeBtn.addEventListener('click', (e) => {
      e.stopPropagation();
      this.closeWindow(winState.id);
    });

    // Double click titlebar to maximize/restore
    titlebar.addEventListener('dblclick', (e) => {
      if (e.target.closest('.win-btn')) return;
      this.toggleMaximizeWindow(winState.id);
    });

    // Dragging Logic
    this.enableDragging(winState, titlebar);

    // Resizing Logic
    this.enableResizing(winState);
  }

  enableDragging(winState, handle) {
    let isDragging = false;
    let startX = 0, startY = 0;
    let initialX = 0, initialY = 0;

    const onPointerDown = (e) => {
      if (e.target.closest('.win-btn') || winState.maximized) return;
      isDragging = true;
      this.focusWindow(winState.id);

      startX = e.clientX;
      startY = e.clientY;

      const rect = winState.element.getBoundingClientRect();
      const wsRect = this.workspace.getBoundingClientRect();

      initialX = rect.left - wsRect.left;
      initialY = rect.top - wsRect.top;

      document.addEventListener('pointermove', onPointerMove);
      document.addEventListener('pointerup', onPointerUp);
    };

    const onPointerMove = (e) => {
      if (!isDragging) return;
      const dx = e.clientX - startX;
      const dy = e.clientY - startY;

      const wsRect = this.workspace.getBoundingClientRect();
      const elRect = winState.element.getBoundingClientRect();

      let nextX = initialX + dx;
      let nextY = initialY + dy;

      // Bound clamping
      nextX = Math.max(-elRect.width + 100, Math.min(wsRect.width - 100, nextX));
      nextY = Math.max(0, Math.min(wsRect.height - 40, nextY));

      winState.element.style.left = `${nextX}px`;
      winState.element.style.top = `${nextY}px`;
    };

    const onPointerUp = () => {
      isDragging = false;
      document.removeEventListener('pointermove', onPointerMove);
      document.removeEventListener('pointerup', onPointerUp);
    };

    handle.addEventListener('pointerdown', onPointerDown);
  }

  enableResizing(winState) {
    const handles = winState.element.querySelectorAll('.resize-handle');
    handles.forEach(handle => {
      let isResizing = false;
      let direction = '';
      let startX = 0, startY = 0;
      let startWidth = 0, startHeight = 0;
      let startLeft = 0, startTop = 0;

      const onPointerDown = (e) => {
        if (winState.maximized) return;
        e.preventDefault();
        e.stopPropagation();
        isResizing = true;
        this.focusWindow(winState.id);

        direction = Array.from(handle.classList).find(cls => cls.startsWith('resize-') && cls !== 'resize-handle').replace('resize-', '');
        
        startX = e.clientX;
        startY = e.clientY;

        const rect = winState.element.getBoundingClientRect();
        const wsRect = this.workspace.getBoundingClientRect();

        startWidth = rect.width;
        startHeight = rect.height;
        startLeft = rect.left - wsRect.left;
        startTop = rect.top - wsRect.top;

        document.addEventListener('pointermove', onPointerMove);
        document.addEventListener('pointerup', onPointerUp);
      };

      const onPointerMove = (e) => {
        if (!isResizing) return;
        const dx = e.clientX - startX;
        const dy = e.clientY - startY;

        let newWidth = startWidth;
        let newHeight = startHeight;
        let newLeft = startLeft;
        let newTop = startTop;

        if (direction.includes('e')) newWidth = Math.max(winState.minWidth, startWidth + dx);
        if (direction.includes('s')) newHeight = Math.max(winState.minHeight, startHeight + dy);
        
        if (direction.includes('w')) {
          const possibleWidth = startWidth - dx;
          if (possibleWidth >= winState.minWidth) {
            newWidth = possibleWidth;
            newLeft = startLeft + dx;
          }
        }

        if (direction.includes('n')) {
          const possibleHeight = startHeight - dy;
          if (possibleHeight >= winState.minHeight) {
            newHeight = possibleHeight;
            newTop = startTop + dy;
          }
        }

        winState.element.style.width = `${newWidth}px`;
        winState.element.style.height = `${newHeight}px`;
        winState.element.style.left = `${newLeft}px`;
        winState.element.style.top = `${newTop}px`;
      };

      const onPointerUp = () => {
        isResizing = false;
        document.removeEventListener('pointermove', onPointerMove);
        document.removeEventListener('pointerup', onPointerUp);
      };

      handle.addEventListener('pointerdown', onPointerDown);
    });
  }

  focusWindow(id) {
    if (!this.windows.has(id)) return;
    const win = this.windows.get(id);

    if (this.activeWindowId === id && !win.minimized) return;

    // Reset others
    this.windows.forEach(w => {
      w.element.classList.remove('active');
    });

    win.element.classList.add('active');
    win.element.style.zIndex = ++this.highestZIndex;
    this.activeWindowId = id;

    if (this.onActiveChange) {
      this.onActiveChange(id);
    }
  }

  minimizeWindow(id) {
    const win = this.windows.get(id);
    if (!win) return;

    win.minimized = true;
    win.element.classList.add('minimized');
    win.element.classList.remove('active');

    // Find next window to focus
    let nextWin = null;
    let maxZ = 0;
    this.windows.forEach(w => {
      if (!w.minimized && parseInt(w.element.style.zIndex || 0) > maxZ) {
        maxZ = parseInt(w.element.style.zIndex);
        nextWin = w;
      }
    });

    if (nextWin) {
      this.focusWindow(nextWin.id);
    } else {
      this.activeWindowId = null;
      if (this.onActiveChange) this.onActiveChange(null);
    }

    this.triggerWindowListChange();
  }

  restoreWindow(id) {
    const win = this.windows.get(id);
    if (!win) return;

    win.minimized = false;
    win.element.classList.remove('minimized');
    this.focusWindow(id);
    this.triggerWindowListChange();
  }

  toggleMaximizeWindow(id) {
    const win = this.windows.get(id);
    if (!win) return;

    if (win.maximized) {
      // Restore previous size
      win.maximized = false;
      win.element.classList.remove('maximized');
      win.element.style.left = `${win.prevBounds.x}px`;
      win.element.style.top = `${win.prevBounds.y}px`;
      win.element.style.width = `${win.prevBounds.width}px`;
      win.element.style.height = `${win.prevBounds.height}px`;
    } else {
      // Save current bounds
      const rect = win.element.getBoundingClientRect();
      const wsRect = this.workspace.getBoundingClientRect();
      win.prevBounds = {
        x: rect.left - wsRect.left,
        y: rect.top - wsRect.top,
        width: rect.width,
        height: rect.height
      };

      win.maximized = true;
      win.element.classList.add('maximized');
    }
  }

  closeWindow(id) {
    const win = this.windows.get(id);
    if (!win) return;

    win.element.remove();
    this.windows.delete(id);

    if (this.activeWindowId === id) {
      this.activeWindowId = null;
      let nextWin = null;
      let maxZ = 0;
      this.windows.forEach(w => {
        if (!w.minimized && parseInt(w.element.style.zIndex || 0) > maxZ) {
          maxZ = parseInt(w.element.style.zIndex);
          nextWin = w;
        }
      });
      if (nextWin) this.focusWindow(nextWin.id);
      else if (this.onActiveChange) this.onActiveChange(null);
    }

    this.triggerWindowListChange();
  }

  triggerWindowListChange() {
    if (this.onWindowListChange) {
      const list = Array.from(this.windows.values()).map(w => ({
        id: w.id,
        title: w.title,
        icon: w.icon,
        appType: w.appType,
        minimized: w.minimized,
        active: w.id === this.activeWindowId
      }));
      this.onWindowListChange(list);
    }
  }
}
