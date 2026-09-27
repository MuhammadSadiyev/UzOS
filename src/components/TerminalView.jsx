import React, { useState, useEffect, useRef } from 'react';
import { Section, Button, Cell, Text, Badge } from '@telegram-apps/telegram-ui';

export default function TerminalView() {
  const [history, setHistory] = useState([
    { type: 'info', text: 'UzOS Cloud [Versiya 2.0.4 WebOS Hypervisor]' },
    { type: 'info', text: '(c) 2026 UzOS Raqamli Suverenitet Ekotizimi.' },
    { type: 'normal', text: "Mavjud buyruqlarni ko'rish uchun 'help' deb yozing yoki tugmalarni bosing." },
    { type: 'info', text: `
         /\\           Foydalanuvchi: uzos@cloud
        /  \\          OS: UzOS Cloud 2.0 (TelegramUI Edition)
       / /\\ \\         Negiz: @telegram-apps/telegram-ui Rasmiy Komponentlari
      / /  \\ \\        Dizayn: 100% Telegram Mini App UI Design
     / / /\\ \\ \\       Yadro: Web Hypervisor / VFS Engine
    / / /  \\ \\ \\      Xotira: Virtual IndexedDB (Tezkor va Xavfsiz)
   /_/ /    \\ \\_\\     Telemetriya: 0 B (100% Zero-Telemetry)
     \\ \\    / /       Xavfsizlik: To'liq Shaxsiy Suverenitet
      \\ \\__/ /        Holat: 100% Rasmiy TelegramUI ⚡
       \\____/
    ` }
  ]);
  const [inputVal, setInputVal] = useState('');
  const outputEndRef = useRef(null);

  useEffect(() => {
    outputEndRef.current?.scrollIntoView({ behavior: 'smooth' });
  }, [history]);

  const handleCommand = (cmdStr) => {
    const trimmed = cmdStr.trim();
    if (!trimmed) return;

    const newHistory = [...history, { type: 'normal', text: `uzos@cloud:~$ ${trimmed}` }];
    const [cmd, ...args] = trimmed.split(' ');

    switch (cmd.toLowerCase()) {
      case 'help':
        newHistory.push({
          type: 'info',
          text: `Mavjud buyruqlar:
  uzosfetch    - Tizim haqida to'liq vizual ma'lumot
  ls           - Hujjatlar va papkalar ro'yxati
  pwd          - Joriy yo'l (/Hujjatlar)
  whoami       - Joriy foydalanuvchi
  date         - Sana va vaqt
  clear        - Ekranni tozalash
  matrix       - Matritsa animatsiyasi`
        });
        break;

      case 'clear':
        setHistory([]);
        return;

      case 'pwd':
        newHistory.push({ type: 'normal', text: '/Hujjatlar' });
        break;

      case 'whoami':
        newHistory.push({ type: 'normal', text: 'uzos (Milliy Administrator)' });
        break;

      case 'date':
        newHistory.push({ type: 'normal', text: new Date().toLocaleString('uz-UZ') });
        break;

      case 'ls':
        newHistory.push({ type: 'success', text: '📁 Hujjatlar/   📁 Rasmlar/   📁 Yuklamalar/   📄 Salom.txt' });
        break;

      case 'uzosfetch':
        newHistory.push({
          type: 'info',
          text: `UzOS Cloud 2.0 WebOS (TelegramUI)
Yadro: Web Hypervisor VFS
Telemetriya: 0 B
Dizayn: @telegram-apps/telegram-ui 1:1 UI Design`
        });
        break;

      case 'matrix':
        newHistory.push({ type: 'success', text: '010101UZOS_SUVEREN_CLOUD_2026_010101' });
        break;

      default:
        newHistory.push({ type: 'error', text: `Buyruq topilmadi: '${cmd}'. Yordam uchun 'help' deb yozing.` });
    }

    setHistory(newHistory);
  };

  const onSubmit = (e) => {
    e.preventDefault();
    handleCommand(inputVal);
    setInputVal('');
  };

  return (
    <div style={{ padding: '16px', display: 'flex', flexDirection: 'column', gap: '12px' }}>
      <Section
        header="UZOS CLOUD WEB SHELL"
        footer="Buyruqlarni qo'lda yozing yoki quyidagi tezkor tugmalardan foydalaning."
      >
        <div style={{ padding: '12px 16px', display: 'flex', gap: '8px', flexWrap: 'wrap', background: 'var(--tgui--secondary_bg_color)' }}>
          <Button size="s" mode="beamed" onClick={() => handleCommand('uzosfetch')}>
            ⚡ uzosfetch
          </Button>
          <Button size="s" mode="outline" onClick={() => handleCommand('help')}>
            ❓ help
          </Button>
          <Button size="s" mode="outline" onClick={() => handleCommand('ls')}>
            📁 ls
          </Button>
          <Button size="s" mode="outline" onClick={() => handleCommand('matrix')}>
            🟢 matrix
          </Button>
          <Button size="s" mode="outline" onClick={() => handleCommand('clear')}>
            🧹 tozalash
          </Button>
        </div>

        {/* Terminal Screen */}
        <div
          style={{
            background: '#090e15',
            color: '#e2e8f0',
            fontFamily: 'var(--tgui--font-mono, monospace)',
            fontSize: '13px',
            padding: '16px',
            minHeight: '280px',
            maxHeight: '380px',
            overflowY: 'auto',
            borderRadius: '0 0 12px 12px',
            lineHeight: '1.5',
            whiteSpace: 'pre-wrap'
          }}
        >
          {history.map((h, i) => (
            <div
              key={i}
              style={{
                color:
                  h.type === 'info'
                    ? '#38bdf8'
                    : h.type === 'success'
                    ? '#4ade80'
                    : h.type === 'error'
                    ? '#f87171'
                    : '#e2e8f0',
                margin: '3px 0'
              }}
            >
              {h.text}
            </div>
          ))}
          <div ref={outputEndRef} />
        </div>
      </Section>

      {/* Terminal Input Form */}
      <form onSubmit={onSubmit} style={{ display: 'flex', gap: '8px' }}>
        <input
          type="text"
          value={inputVal}
          onChange={(e) => setInputVal(e.target.value)}
          placeholder="Buyruq yozing (masalan: help, uzosfetch)..."
          style={{
            flex: 1,
            background: 'var(--tgui--secondary_bg_color)',
            border: '1px solid var(--tgui--outline)',
            color: 'var(--tgui--text_color)',
            padding: '12px 16px',
            borderRadius: '12px',
            fontSize: '14px',
            outline: 'none',
            fontFamily: 'monospace'
          }}
        />
        <Button size="l" mode="filled" type="submit">
          Bajarish
        </Button>
      </form>
    </div>
  );
}
