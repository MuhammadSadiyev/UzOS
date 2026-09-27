import React, { useState } from 'react';
import { Section, SegmentedControl, Button, Badge } from '@telegram-apps/telegram-ui';

const DEFAULT_FILES = [
  {
    name: 'main.js',
    lang: 'javascript',
    code: `// UzOS Cloud 2.0 WebOS Core Execution
function initUzOS() {
  console.log("⚡ UzOS Cloud 2.0 WebOS ishga tushdi!");
  console.log("🔒 Xavfsizlik darajasi: 100% Zero-Telemetry.");
  
  const systemInfo = {
    os: "UzOS Cloud",
    version: "2.0.4",
    kernel: "Web Hypervisor VFS",
    status: "Suveren & Faol"
  };
  
  return systemInfo;
}

initUzOS();`
  },
  {
    name: 'style.css',
    lang: 'css',
    code: `/* UzOS TelegramUI Global Theme */
:root {
  --tgui--primary: #2481cc;
  --tgui--accent: #38bdf8;
  --tgui--suveren_green: #22c55e;
  --tgui--border_radius: 12px;
}

.uzos-badge {
  font-weight: 700;
  letter-spacing: 0.5px;
}`
  },
  {
    name: 'uzos.sh',
    lang: 'bash',
    code: `#!/bin/bash
# UzOS Milliy Tizim Avtomatizatsiya Skripti
echo "=== UZOS TELEMETRIYA AUDITI ==="
echo "Kuzatuv portlari tekshirilmoqda..."
echo "Holat: Xorijiy tarmoqlarga ulanish 0 dona topildi."
echo "Xulosa: Tizim to'liq mustaqil va xavfsiz."`
  },
  {
    name: 'Salom.txt',
    lang: 'text',
    code: `UzOS Cloud 2.0 WebOS tizimiga xush kelibsiz!
Bu yerda siz har qanday hujjatni bemalol tahrirlashingiz,
kod yozishingiz va uni brauzer ichida xavfsiz ishga tushirishingiz mumkin.`
  }
];

export default function EditorView({ initialFile }) {
  const [files, setFiles] = useState(DEFAULT_FILES);
  const [activeFileName, setActiveFileName] = useState(initialFile?.name || 'main.js');
  const [activeCode, setActiveCode] = useState(
    initialFile?.content || DEFAULT_FILES.find(f => f.name === (initialFile?.name || 'main.js'))?.code || ''
  );
  const [executionOutput, setExecutionOutput] = useState('');
  const [isSaved, setIsSaved] = useState(true);
  const [statusMessage, setStatusMessage] = useState('');

  const handleSelectTab = (fileName) => {
    // Save current file draft
    setFiles(prev => prev.map(f => f.name === activeFileName ? { ...f, code: activeCode } : f));
    
    const targetFile = files.find(f => f.name === fileName);
    if (targetFile) {
      setActiveFileName(fileName);
      setActiveCode(targetFile.code);
      setIsSaved(true);
      setStatusMessage('');
      setExecutionOutput('');
    }
  };

  const handleCodeChange = (e) => {
    setActiveCode(e.target.value);
    setIsSaved(false);
  };

  const handleSave = () => {
    setFiles(prev => prev.map(f => f.name === activeFileName ? { ...f, code: activeCode } : f));
    setIsSaved(true);
    setStatusMessage('✅ Fayl muvaffaqiyatli saqlandi!');
    setTimeout(() => setStatusMessage(''), 3000);
  };

  const handleRun = () => {
    setStatusMessage('▶️ Skript bajarilmoqda...');
    const current = files.find(f => f.name === activeFileName) || { lang: 'javascript' };

    if (activeFileName.endsWith('.js') || current.lang === 'javascript') {
      try {
        let logs = [];
        const customConsole = {
          log: (...args) => logs.push(args.map(a => typeof a === 'object' ? JSON.stringify(a, null, 2) : String(a)).join(' ')),
          error: (...args) => logs.push('❌ Xatolik: ' + args.join(' ')),
          warn: (...args) => logs.push('⚠️ Ogohlantirish: ' + args.join(' '))
        };

        const runner = new Function('console', activeCode);
        const result = runner(customConsole);
        
        let out = logs.join('\n');
        if (result !== undefined) {
          out += (out ? '\n' : '') + `[Natija]: ${JSON.stringify(result, null, 2)}`;
        }
        setExecutionOutput(out || '(Skript hech qanday ma\'lumot chop etmadi)');
        setStatusMessage('✅ Muvaffaqiyatli yakunlandi');
      } catch (err) {
        setExecutionOutput(`Sintaksis xatosi: ${err.message}`);
        setStatusMessage('❌ Skriptda xatolik yuz berdi');
      }
    } else {
      // Simulate shell / text execution
      setExecutionOutput(`[${activeFileName} VFS Interpreteri]:\nFayl muvaffaqiyatli tahlil qilindi (${activeCode.split('\n').length} qator, ${activeCode.length} bayt).`);
      setStatusMessage('✅ Tahlil yakunlandi');
    }
  };

  const linesCount = activeCode.split('\n').length;

  return (
    <div style={{ padding: '16px', display: 'flex', flexDirection: 'column', gap: '16px' }}>
      
      {/* File Selector Tabs using TelegramUI SegmentedControl */}
      <Section header="KOD MUHARRIRI (UZOS CLOUD STUDIO)">
        <div style={{ padding: '8px 16px', background: 'var(--tgui--secondary_bg_color)' }}>
          <SegmentedControl>
            {files.map(file => (
              <SegmentedControl.Item
                key={file.name}
                selected={activeFileName === file.name}
                onClick={() => handleSelectTab(file.name)}
              >
                {file.name}
              </SegmentedControl.Item>
            ))}
          </SegmentedControl>
        </div>

        {/* Editor Meta Bar */}
        <div style={{
          padding: '8px 16px',
          display: 'flex',
          justifyContent: 'space-between',
          alignItems: 'center',
          background: 'var(--tgui--bg_color)',
          borderBottom: '1px solid var(--tgui--outline)',
          fontSize: '12px'
        }}>
          <div style={{ display: 'flex', gap: '8px', alignItems: 'center' }}>
            <Badge mode={isSaved ? 'outline' : 'critical'}>
              {isSaved ? 'Saqlangan' : 'Tahrirlangan *'}
            </Badge>
            <span style={{ color: 'var(--tgui--hint_color)' }}>
              {linesCount} qator • {activeCode.length} belgi
            </span>
          </div>

          <div style={{ display: 'flex', gap: '8px' }}>
            <Button size="s" mode="filled" onClick={handleSave}>
              💾 Saqlash
            </Button>
            <Button size="s" mode="beamed" onClick={handleRun}>
              ▶ Bajarish
            </Button>
          </div>
        </div>

        {statusMessage && (
          <div style={{
            padding: '6px 16px',
            fontSize: '12px',
            background: 'rgba(34, 197, 94, 0.1)',
            color: '#4ade80'
          }}>
            {statusMessage}
          </div>
        )}

        {/* Code Input Textarea */}
        <div style={{ position: 'relative', background: '#090e15' }}>
          <textarea
            value={activeCode}
            onChange={handleCodeChange}
            spellCheck="false"
            style={{
              width: '100%',
              minHeight: '260px',
              boxSizing: 'border-box',
              background: '#090e15',
              color: '#f8fafc',
              border: 'none',
              padding: '16px',
              fontFamily: 'Consolas, Monaco, "Courier New", monospace',
              fontSize: '13.5px',
              lineHeight: '1.6',
              outline: 'none',
              resize: 'vertical',
              tabSize: 2
            }}
          />
        </div>
      </Section>

      {/* Execution Console Output */}
      {executionOutput && (
        <Section header="BAJARILISH NATIJASI (VFS CONSOLE)">
          <div style={{
            padding: '14px 16px',
            background: '#040711',
            borderRadius: '0 0 12px 12px'
          }}>
            <pre style={{
              margin: 0,
              fontFamily: 'monospace',
              fontSize: '13px',
              lineHeight: '1.5',
              color: '#38bdf8',
              whiteSpace: 'pre-wrap'
            }}>
              {executionOutput}
            </pre>
            <div style={{ marginTop: '10px', display: 'flex', justifyContent: 'flex-end' }}>
              <Button size="s" mode="outline" onClick={() => setExecutionOutput('')}>
                Konsolni tozalash
              </Button>
            </div>
          </div>
        </Section>
      )}

    </div>
  );
}
