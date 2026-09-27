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
    this.currentSnapCandidate = null;

    // Aero Snap Ghost Preview Overlay (Windows Snap)
    this.snapPreview = document.createElement('div');
    this.snapPreview.className = 'window-snap-preview';
    this.workspace.appendChild(this.snapPreview);
    
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
      snapped: null,
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
    let hasMoved = false;
    let startX = 0, startY = 0;
    let initialX = 0, initialY = 0;

    const onPointerDown = (e) => {
      if (e.target.closest('.win-btn')) return;
      if (e.button !== 0) return;
      isDragging = true;
      hasMoved = false;
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

      if (!hasMoved && Math.hypot(dx, dy) > 4) {
        hasMoved = true;
      }
      if (!hasMoved) return;

      const wsRect = this.workspace.getBoundingClientRect();

      // If user drags a maximized or snapped window, un-dock & center under cursor
      if (winState.maximized || winState.snapped) {
        const restoreW = winState.prevBounds ? winState.prevBounds.width : 680;
        const restoreH = winState.prevBounds ? winState.prevBounds.height : 480;

        this.clearSnapClasses(winState);
        winState.maximized = false;
        winState.snapped = null;

        winState.element.style.width = `${restoreW}px`;
        winState.element.style.height = `${restoreH}px`;

        const pointerX = e.clientX - wsRect.left;
        let newLeft = pointerX - (restoreW / 2);
        let newTop = (e.clientY - wsRect.top) - 18;

        newLeft = Math.max(10, Math.min(wsRect.width - restoreW - 10, newLeft));
        newTop = Math.max(0, Math.min(wsRect.height - 40, newTop));

        winState.element.style.left = `${newLeft}px`;
        winState.element.style.top = `${newTop}px`;

        initialX = newLeft;
        initialY = newTop;
        startX = e.clientX;
        startY = e.clientY;
        return;
      }

      let nextX = initialX + dx;
      let nextY = initialY + dy;

      const elRect = winState.element.getBoundingClientRect();
      nextX = Math.max(-elRect.width + 100, Math.min(wsRect.width - 100, nextX));
      nextY = Math.max(0, Math.min(wsRect.height - 40, nextY));

      winState.element.style.left = `${nextX}px`;
      winState.element.style.top = `${nextY}px`;

      // Wall Touching / Edge Snapping Detection
      const pointerX = e.clientX - wsRect.left;
      const pointerY = e.clientY - wsRect.top;

      const EDGE_MARGIN = 16;
      const CORNER_MARGIN = 80;
      let snapCandidate = null;

      if (pointerY <= EDGE_MARGIN) {
        if (pointerX <= CORNER_MARGIN) snapCandidate = 'top-left';
        else if (pointerX >= wsRect.width - CORNER_MARGIN) snapCandidate = 'top-right';
        else snapCandidate = 'maximize';
      } else if (pointerX <= EDGE_MARGIN) {
        if (pointerY <= CORNER_MARGIN) snapCandidate = 'top-left';
        else if (pointerY >= wsRect.height - CORNER_MARGIN) snapCandidate = 'bottom-left';
        else snapCandidate = 'left';
      } else if (pointerX >= wsRect.width - EDGE_MARGIN) {
        if (pointerY <= CORNER_MARGIN) snapCandidate = 'top-right';
        else if (pointerY >= wsRect.height - CORNER_MARGIN) snapCandidate = 'bottom-right';
        else snapCandidate = 'right';
      }

      this.currentSnapCandidate = snapCandidate;
      this.updateSnapPreview(snapCandidate);
    };

    const onPointerUp = () => {
      if (!isDragging) return;
      isDragging = false;
      document.removeEventListener('pointermove', onPointerMove);
      document.removeEventListener('pointerup', onPointerUp);

      this.hideSnapPreview();

      if (hasMoved) {
        if (this.currentSnapCandidate) {
          this.applySnap(winState, this.currentSnapCandidate);
          this.currentSnapCandidate = null;
        } else {
          const rect = winState.element.getBoundingClientRect();
          const wsRect = this.workspace.getBoundingClientRect();
          winState.prevBounds = {
            x: rect.left - wsRect.left,
            y: rect.top - wsRect.top,
            width: rect.width,
            height: rect.height
          };
        }
      }
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
        if (winState.maximized || winState.snapped) return;
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

    if (!winState.maximized && !winState.snapped) {
      // Save current bounds
      const rect = el.getBoundingClientRect();
      const wsRect = this.workspace.getBoundingClientRect();
      winState.prevBounds = {
        x: rect.left - wsRect.left,
        y: rect.top - wsRect.top,
        width: rect.width,
        height: rect.height
      };

      this.clearSnapClasses(winState);
      el.classList.add('maximized');
      winState.maximized = true;
      winState.snapped = null;
    } else {
      this.clearSnapClasses(winState);
      winState.maximized = false;
      winState.snapped = null;

      el.style.left = `${winState.prevBounds.x}px`;
      el.style.top = `${winState.prevBounds.y}px`;
      el.style.width = `${winState.prevBounds.width}px`;
      el.style.height = `${winState.prevBounds.height}px`;
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

  updateSnapPreview(snap) {
    if (!snap) {
      this.hideSnapPreview();
      return;
    }
    const p = this.snapPreview;
    p.classList.add('visible');

    switch (snap) {
      case 'maximize':
        p.style.left = '4px';
        p.style.top = '4px';
        p.style.width = 'calc(100% - 8px)';
        p.style.height = 'calc(100% - 8px)';
        break;
      case 'left':
        p.style.left = '4px';
        p.style.top = '4px';
        p.style.width = 'calc(50% - 6px)';
        p.style.height = 'calc(100% - 8px)';
        break;
      case 'right':
        p.style.left = 'calc(50% + 2px)';
        p.style.top = '4px';
        p.style.width = 'calc(50% - 6px)';
        p.style.height = 'calc(100% - 8px)';
        break;
      case 'top-left':
        p.style.left = '4px';
        p.style.top = '4px';
        p.style.width = 'calc(50% - 6px)';
        p.style.height = 'calc(50% - 6px)';
        break;
      case 'top-right':
        p.style.left = 'calc(50% + 2px)';
        p.style.top = '4px';
        p.style.width = 'calc(50% - 6px)';
        p.style.height = 'calc(50% - 6px)';
        break;
      case 'bottom-left':
        p.style.left = '4px';
        p.style.top = 'calc(50% + 2px)';
        p.style.width = 'calc(50% - 6px)';
        p.style.height = 'calc(50% - 6px)';
        break;
      case 'bottom-right':
        p.style.left = 'calc(50% + 2px)';
        p.style.top = 'calc(50% + 2px)';
        p.style.width = 'calc(50% - 6px)';
        p.style.height = 'calc(50% - 6px)';
        break;
    }
  }

  hideSnapPreview() {
    if (this.snapPreview) {
      this.snapPreview.classList.remove('visible');
    }
  }

  clearSnapClasses(winState) {
    winState.element.classList.remove(
      'maximized',
      'snapped-left',
      'snapped-right',
      'snapped-top-left',
      'snapped-top-right',
      'snapped-bottom-left',
      'snapped-bottom-right'
    );
  }

  applySnap(winState, snapType) {
    if (!winState.maximized && !winState.snapped) {
      const rect = winState.element.getBoundingClientRect();
      const wsRect = this.workspace.getBoundingClientRect();
      winState.prevBounds = {
        x: rect.left - wsRect.left,
        y: rect.top - wsRect.top,
        width: rect.width,
        height: rect.height
      };
    }

    this.clearSnapClasses(winState);

    // Smooth snap transition
    winState.element.style.transition = 'all 0.18s cubic-bezier(0.16, 1, 0.3, 1)';
    setTimeout(() => { winState.element.style.transition = ''; }, 200);

    if (snapType === 'maximize') {
      winState.maximized = true;
      winState.snapped = null;
      winState.element.classList.add('maximized');
    } else {
      winState.maximized = false;
      winState.snapped = snapType;
      winState.element.classList.add(`snapped-${snapType}`);
    }
  }
}
