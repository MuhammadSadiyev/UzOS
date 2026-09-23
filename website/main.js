/**
 * UzOS — O'zbekiston Milliy Operatsion Tizimi
 * 1:1 TON.org Dynamics & 3D Interactive Dot-Matrix Globe
 */

document.addEventListener('DOMContentLoaded', () => {
  
  // 1. Site Header on-scroll glassmorphism
  const siteHeader = document.getElementById('site-header');
  if (siteHeader) {
    window.addEventListener('scroll', () => {
      if (window.scrollY > 20) {
        siteHeader.classList.add('scrolled');
      } else {
        siteHeader.classList.remove('scrolled');
      }
    });
  }

  // 2. Interactive 3D Dot-Matrix Network Globe (1:1 TON.org Canvas Globe)
  const canvas = document.getElementById('hero-globe-canvas');
  if (canvas) {
    const ctx = canvas.getContext('2d');
    let width = canvas.width;
    let height = canvas.height;

    function resizeCanvas() {
      const rect = canvas.getBoundingClientRect();
      const dpr = window.devicePixelRatio || 1;
      canvas.width = rect.width * dpr;
      canvas.height = rect.height * dpr;
      ctx.scale(dpr, dpr);
      width = rect.width;
      height = rect.height;
    }
    resizeCanvas();
    window.addEventListener('resize', resizeCanvas);

    // Fibonacci Sphere Distribution (260 points on a unit sphere)
    const numPoints = 260;
    const points = [];
    const phi = Math.PI * (3 - Math.sqrt(5));

    for (let i = 0; i < numPoints; i++) {
      const y = 1 - (i / (numPoints - 1)) * 2;
      const r = Math.sqrt(1 - y * y);
      const theta = phi * i;

      const x = Math.cos(theta) * r;
      const z = Math.sin(theta) * r;

      points.push({
        unitX: x,
        unitY: y,
        unitZ: z,
        isNode: i % 18 === 0 // Key national nodes
      });
    }

    let rotX = 0.2;
    let rotY = 0;
    let speedY = 0.0035;
    let isDragging = false;
    let lastMouseX = 0;
    let lastMouseY = 0;

    canvas.addEventListener('mousedown', (e) => {
      isDragging = true;
      lastMouseX = e.clientX;
      lastMouseY = e.clientY;
    });

    window.addEventListener('mouseup', () => {
      isDragging = false;
    });

    window.addEventListener('mousemove', (e) => {
      if (!isDragging) return;
      const dx = e.clientX - lastMouseX;
      const dy = e.clientY - lastMouseY;
      rotY += dx * 0.005;
      rotX += dy * 0.005;
      lastMouseX = e.clientX;
      lastMouseY = e.clientY;
    });

    // Touch events for mobile
    canvas.addEventListener('touchstart', (e) => {
      if (e.touches.length === 1) {
        isDragging = true;
        lastMouseX = e.touches[0].clientX;
        lastMouseY = e.touches[0].clientY;
      }
    }, { passive: true });

    window.addEventListener('touchend', () => {
      isDragging = false;
    });

    window.addEventListener('touchmove', (e) => {
      if (!isDragging || e.touches.length !== 1) return;
      const dx = e.touches[0].clientX - lastMouseX;
      const dy = e.touches[0].clientY - lastMouseY;
      rotY += dx * 0.006;
      rotX += dy * 0.006;
      lastMouseX = e.touches[0].clientX;
      lastMouseY = e.touches[0].clientY;
    }, { passive: true });

    let pulseAngle = 0;

    function render() {
      ctx.clearRect(0, 0, width, height);

      if (!isDragging) {
        rotY += speedY;
      }

      pulseAngle += 0.04;
      const pulseScale = 1 + Math.sin(pulseAngle) * 0.15;

      const cosX = Math.cos(rotX);
      const sinX = Math.sin(rotX);
      const cosY = Math.cos(rotY);
      const sinY = Math.sin(rotY);

      const centerX = width / 2;
      const centerY = height / 2;

      // Dynamic radius scaling smoothly for mobile and desktop screens
      const currentRadius = Math.min(width, height) * 0.32;
      const fov = currentRadius * 2.3;

      const projected = [];
      const keyNodes = [];

      for (let i = 0; i < points.length; i++) {
        const p = points[i];

        const bx = p.unitX * currentRadius;
        const by = p.unitY * currentRadius;
        const bz = p.unitZ * currentRadius;

        let x1 = bx * cosY - bz * sinY;
        let z1 = bz * cosY + bx * sinY;

        let y1 = by * cosX - z1 * sinX;
        let z2 = z1 * cosX + by * sinX;

        const scale = fov / (fov + z2);
        const projX = centerX + x1 * scale;
        const projY = centerY + y1 * scale;
        const alpha = (z2 + currentRadius) / (2 * currentRadius);

        const item = {
          x: projX,
          y: projY,
          z: z2,
          scale: scale,
          alpha: Math.max(0.12, Math.min(1, alpha)),
          isNode: p.isNode
        };

        projected.push(item);
        if (p.isNode && z2 > -40) {
          keyNodes.push(item);
        }
      }

      // Connecting arcs between key nodes
      ctx.beginPath();
      const maxConnectDist = currentRadius * 0.85;
      for (let i = 0; i < keyNodes.length; i++) {
        for (let j = i + 1; j < keyNodes.length; j++) {
          const n1 = keyNodes[i];
          const n2 = keyNodes[j];
          const dist = Math.hypot(n1.x - n2.x, n1.y - n2.y);
          if (dist < maxConnectDist) {
            ctx.moveTo(n1.x, n1.y);
            const midX = (n1.x + n2.x) / 2 + (n1.x - centerX) * 0.12;
            const midY = (n1.y + n2.y) / 2 + (n1.y - centerY) * 0.12;
            ctx.quadraticCurveTo(midX, midY, n2.x, n2.y);
          }
        }
      }
      ctx.strokeStyle = 'rgba(30, 174, 251, 0.16)';
      ctx.lineWidth = 1;
      ctx.stroke();

      // Render dots
      projected.sort((a, b) => a.z - b.z);

      for (let i = 0; i < projected.length; i++) {
        const p = projected[i];

        if (p.isNode) {
          ctx.beginPath();
          ctx.arc(p.x, p.y, 4.5 * p.scale, 0, Math.PI * 2);
          ctx.fillStyle = `rgba(30, 174, 251, ${p.alpha * 0.95})`;
          ctx.fill();

          ctx.beginPath();
          ctx.arc(p.x, p.y, 7 * p.scale * pulseScale, 0, Math.PI * 2);
          ctx.strokeStyle = `rgba(30, 174, 251, ${p.alpha * 0.35})`;
          ctx.lineWidth = 1.2;
          ctx.stroke();
        } else {
          ctx.beginPath();
          const dotSize = p.z > 0 ? 1.8 * p.scale : 1.2 * p.scale;
          ctx.arc(p.x, p.y, dotSize, 0, Math.PI * 2);
          ctx.fillStyle = p.z > 0 
            ? `rgba(147, 165, 184, ${p.alpha * 0.75})`
            : `rgba(98, 114, 132, ${p.alpha * 0.35})`;
          ctx.fill();
        }
      }

      requestAnimationFrame(render);
    }

    render();
  }

});
