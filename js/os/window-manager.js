/* ==============================================================================
   UzOS Cloud (WebOS) — Window Manager (Core Engine)
   Multi-window, Dragging, Resizing, Z-Index, Minimize/Maximize with SVG Controls
   ============================================================================== */

export class WindowManager {
  constructor(workspaceElement) {
    this.workspace = workspaceElement;
    this.windows = new Map(); // id -> window state
    this.activeWindowId = null;
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
  }

  createWindow({ id, title, icon = '', width = 680, height = 480, minWidth = 380, minHeight = 280, content = '', appType = 'generic' }) {
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
    const defaultX = Math.max(20, Math.min(wsRect.width - width - 40, 60 + (count % 6) * 35));
    const defaultY = Math.max(20, Math.min(wsRect.height - height - 40, 40 + (count % 6) * 35));

    // Create DOM element
    const winEl = document.createElement('div');
    winEl.className = 'uzos-window';
    winEl.dataset.windowId = id;
    winEl.style.width = `${width}px`;
    winEl.style.height = `${height}px`;
    winEl.style.left = `${defaultX}px`;
    winEl.style.top = `${defaultY}px`;
    winEl.style.zIndex = ++this.highestZIndex;

    // Window Inner Structure (macOS / Telegram Dark Style)
    winEl.innerHTML = `
      <!-- Titlebar -->
      <div class="window-titlebar">
        <div class="window-controls">
          <button class="win-btn close" title="Yopish" aria-label="Yopish"></button>
          <button class="win-btn minimize" title="Kichraytirish" aria-label="Kichraytirish"></button>
          <button class="win-btn maximize" title="Kattalashtirish" aria-label="Kattalashtirish"></button>
        </div>
        
        <div class="window-info">
          <span class="window-icon">${icon}</span>
          <span class="window-title">${title}</span>
        </div>

        <div class="window-titlebar-right"></div>
      </div>
      
      <!-- Body -->
      <div class="window-body">
        ${content}
      </div>

      <!-- Resizing Handles (8 directions) -->
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
    const winState = this.windows.get(id);

    // Update z-index
    winState.element.style.zIndex = ++this.highestZIndex;
    this.activeWindowId = id;

    // Toggle active classes
    this.windows.forEach(w => {
      w.element.classList.toggle('active', w.id === id);
    });

    if (this.onActiveChange) {
      this.onActiveChange(winState);
    }
  }

  minimizeWindow(id) {
    if (!this.windows.has(id)) return;
    const winState = this.windows.get(id);
    winState.minimized = true;
    winState.element.classList.add('minimized');

    this.triggerWindowListChange();
  }

  restoreWindow(id) {
    if (!this.windows.has(id)) return;
    const winState = this.windows.get(id);
    winState.minimized = false;
    winState.element.classList.remove('minimized');
    this.focusWindow(id);

    this.triggerWindowListChange();
  }

  toggleMaximizeWindow(id) {
    if (!this.windows.has(id)) return;
    const winState = this.windows.get(id);
    const el = winState.element;

    if (!winState.maximized) {
      // Save current bounds
      const rect = el.getBoundingClientRect();
      const wsRect = this.workspace.getBoundingClientRect();
      winState.prevBounds = {
        x: rect.left - wsRect.left,
        y: rect.top - wsRect.top,
        width: rect.width,
        height: rect.height
      };

      el.classList.add('maximized');
      winState.maximized = true;
    } else {
      el.classList.remove('maximized');
      el.style.left = `${winState.prevBounds.x}px`;
      el.style.top = `${winState.prevBounds.y}px`;
      el.style.width = `${winState.prevBounds.width}px`;
      el.style.height = `${winState.prevBounds.height}px`;
      winState.maximized = false;
    }
  }

  closeWindow(id) {
    if (!this.windows.has(id)) return;
    const winState = this.windows.get(id);
    winState.element.remove();
    this.windows.delete(id);

    if (this.activeWindowId === id) {
      this.activeWindowId = null;
      // Focus highest remaining window
      let topWin = null;
      let topZ = -1;
      this.windows.forEach(w => {
        if (!w.minimized && parseInt(w.element.style.zIndex) > topZ) {
          topZ = parseInt(w.element.style.zIndex);
          topWin = w;
        }
      });
      if (topWin) this.focusWindow(topWin.id);
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
