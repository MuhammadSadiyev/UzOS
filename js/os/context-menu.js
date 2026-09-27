/* ==============================================================================
   UzOS Cloud (WebOS) — Desktop Context Menu (Right Click)
   ============================================================================== */

export class ContextMenu {
  constructor({ workspace, onAction }) {
    this.workspace = workspace;
    this.onAction = onAction;
    this.menuEl = document.getElementById('context-menu');

    this.init();
  }

  init() {
    this.workspace.addEventListener('contextmenu', (e) => {
      // If clicking inside a window or another interactive control, let default or window handle
      if (e.target.closest('.uzos-window') || e.target.closest('#sidebar') || e.target.closest('#topbar')) {
        return;
      }

      e.preventDefault();
      this.show(e.clientX, e.clientY);
    });

    document.addEventListener('click', (e) => {
      if (!e.target.closest('#context-menu')) {
        this.hide();
      }
    });

    this.menuEl.querySelectorAll('.ctx-item').forEach(item => {
      item.addEventListener('click', () => {
        const action = item.dataset.action;
        if (action && this.onAction) {
          this.onAction(action);
        }
        this.hide();
      });
    });
  }

  show(x, y) {
    this.menuEl.style.display = 'flex';
    this.menuEl.classList.add('visible');

    const rect = this.menuEl.getBoundingClientRect();
    const maxX = window.innerWidth - rect.width - 10;
    const maxY = window.innerHeight - rect.height - 10;

    this.menuEl.style.left = `${Math.min(x, maxX)}px`;
    this.menuEl.style.top = `${Math.min(y, maxY)}px`;
  }

  hide() {
    this.menuEl.classList.remove('visible');
    this.menuEl.style.display = 'none';
  }
}
