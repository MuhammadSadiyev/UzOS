import React, { useState } from 'react';
import { Section, Cell, Button, Badge, Avatar, Input, Placeholder } from '@telegram-apps/telegram-ui';

const INITIAL_VFS = {
  '/': [
    { name: 'Hujjatlar', type: 'folder', size: '3 element', date: 'Bugun, 14:20' },
    { name: 'Loyihalar', type: 'folder', size: '2 element', date: 'Kecha, 18:00' },
    { name: 'Skriptlar', type: 'folder', size: '4 element', date: '25-Sentabr' },
    { name: 'Salom.txt', type: 'file', size: '240 B', date: 'Bugun, 15:10', content: 'UzOS Cloud 2.0 WebOS tizimiga xush kelibsiz!\nBu fayl Virtual File System (VFS) xotirasida xavfsiz saqlanmoqda.' },
    { name: 'Ochiq_Konstitutsiya.md', type: 'file', size: '1.4 KB', date: 'Bugun, 12:00', content: '# O\'zbekiston Respublikasi Raqamli Suvereniteti\n\n1-modda: Har bir fuqaroning shaxsiy ma\'lumotlari xorijiy telemetriya kuzatuvlaridan daxlsizdir.\n2-modda: Milliy operatsion tizim xavfsiz va tejamkor texnologiyalar asosida barpo etiladi.' },
    { name: 'uzos_manifest.json', type: 'file', size: '512 B', date: 'Bugun, 09:30', content: '{\n  "os": "UzOS Cloud",\n  "version": "2.0.4",\n  "engine": "Web Hypervisor VFS",\n  "telemetry": "0B",\n  "ui": "@telegram-apps/telegram-ui"\n}' }
  ],
  '/Hujjatlar': [
    { name: 'Davlat_Dasturi_2026.docx', type: 'file', size: '24 KB', date: '20-Sentabr', content: 'O\'zbekiston 2030 strategiyasi doirasida to\'liq mustaqil axborot texnologiyalari infratuzilmasini yaratish.' },
    { name: 'Raqamli_Iqtisodiyot_Hisobot.pdf', type: 'file', size: '180 KB', date: '22-Sentabr', content: 'Yillik hisobot: Milliy dasturiy ta\'minotlar ulushi 45% ga oshdi.' },
    { name: 'Qonun_Loyihasi.txt', type: 'file', size: '12 KB', date: '24-Sentabr', content: 'Axborot xavfsizligi va suvereniteti to\'g\'risidagi qonun loyihasi bandlari.' }
  ],
  '/Loyihalar': [
    { name: 'UzOS_WebShell.rs', type: 'file', size: '3.2 KB', date: '26-Sentabr', content: '// UzOS WebShell Core in Rust WebAssembly\nfn main() {\n    println!("UzOS Rust Hypervisor Online!");\n}' },
    { name: 'OneID_Connector.ts', type: 'file', size: '1.8 KB', date: '27-Sentabr', content: '// OneID Milliy Shlyuz API Klienti\nexport const authenticateOneId = async (token: string) => { return true; };' }
  ],
  '/Skriptlar': [
    { name: 'backup_vfs.sh', type: 'file', size: '420 B', date: 'Bugun, 08:00', content: '#!/bin/bash\n# VFS zaxira nusxasini shifrlangan holatda saqlash\necho "Zaxiralash yakunlandi."' },
    { name: 'zero_telemetry_audit.py', type: 'file', size: '890 B', date: 'Kecha, 21:00', content: '# Telemetriya paketlarini tekshirish skripti\nprint("Kuzatuv paketlari: 0 dona topildi.")' }
  ]
};

export default function FilesView({ onOpenFileInEditor }) {
  const [vfs, setVfs] = useState(INITIAL_VFS);
  const [currentPath, setCurrentPath] = useState('/');
  const [selectedFile, setSelectedFile] = useState(null);
  const [newFileName, setNewFileName] = useState('');
  const [isCreatingFile, setIsCreatingFile] = useState(false);

  const currentItems = vfs[currentPath] || [];

  const handleOpenItem = (item) => {
    if (item.type === 'folder') {
      const nextPath = currentPath === '/' ? `/${item.name}` : `${currentPath}/${item.name}`;
      if (!vfs[nextPath]) {
        setVfs(prev => ({ ...prev, [nextPath]: [] }));
      }
      setCurrentPath(nextPath);
      setSelectedFile(null);
    } else {
      setSelectedFile(item);
    }
  };

  const handleGoBack = () => {
    if (currentPath === '/') return;
    const parts = currentPath.split('/').filter(Boolean);
    parts.pop();
    const parentPath = parts.length === 0 ? '/' : `/${parts.join('/')}`;
    setCurrentPath(parentPath);
    setSelectedFile(null);
  };

  const handleCreateFile = () => {
    if (!newFileName.trim()) return;
    const name = newFileName.trim();
    const isFolder = name.endsWith('/');
    const cleanName = isFolder ? name.replace(/\/+$/, '') : name;

    const newItem = isFolder
      ? { name: cleanName, type: 'folder', size: '0 element', date: 'Hozir' }
      : { name: cleanName, type: 'file', size: '0 B', date: 'Hozir', content: `# ${cleanName}\nYangi yaratilgan fayl.` };

    setVfs(prev => ({
      ...prev,
      [currentPath]: [...(prev[currentPath] || []), newItem],
      ...(isFolder ? { [`${currentPath === '/' ? '' : currentPath}/${cleanName}`]: [] } : {})
    }));

    setNewFileName('');
    setIsCreatingFile(false);
  };

  const handleDeleteItem = (itemName) => {
    setVfs(prev => ({
      ...prev,
      [currentPath]: (prev[currentPath] || []).filter(item => item.name !== itemName)
    }));
    if (selectedFile?.name === itemName) {
      setSelectedFile(null);
    }
  };

  return (
    <div style={{ padding: '16px', display: 'flex', flexDirection: 'column', gap: '16px' }}>
      
      {/* Path Bar & Actions */}
      <Section
        header={`FAYLLAR TIZIMI: ${currentPath}`}
        footer="Xavfsiz shifrlangan VFS bulut xotirasi. Hech qanday xorijiy serverga uzatilmaydi."
      >
        <div style={{ padding: '10px 16px', display: 'flex', justifyContent: 'space-between', alignItems: 'center', background: 'var(--tgui--secondary_bg_color)' }}>
          <div style={{ display: 'flex', gap: '8px', alignItems: 'center' }}>
            {currentPath !== '/' && (
              <Button size="s" mode="outline" onClick={handleGoBack}>
                ⬅ Orqaga
              </Button>
            )}
            <Badge type="number" mode="outline">
              {currentItems.length} ta element
            </Badge>
          </div>

          <Button size="s" mode="filled" onClick={() => setIsCreatingFile(!isCreatingFile)}>
            {isCreatingFile ? 'Bekor qilish' : '+ Yangi fayl'}
          </Button>
        </div>

        {isCreatingFile && (
          <div style={{ padding: '12px 16px', display: 'flex', gap: '8px', background: 'var(--tgui--bg_color)', borderBottom: '1px solid var(--tgui--outline)' }}>
            <input
              type="text"
              placeholder="Fayl nomi (masalan: hisobot.txt yoki papka/)"
              value={newFileName}
              onChange={(e) => setNewFileName(e.target.value)}
              style={{
                flex: 1,
                background: 'var(--tgui--secondary_bg_color)',
                border: '1px solid var(--tgui--outline)',
                color: 'var(--tgui--text_color)',
                padding: '8px 12px',
                borderRadius: '8px',
                fontSize: '14px',
                outline: 'none'
              }}
              onKeyDown={(e) => e.key === 'Enter' && handleCreateFile()}
            />
            <Button size="s" mode="filled" onClick={handleCreateFile}>
              Yaratish
            </Button>
          </div>
        )}

        {/* File and Folder Cells */}
        {currentItems.length === 0 ? (
          <Placeholder
            header="Bu papka bo'sh"
            description="Yangi fayl yoki papka yaratish uchun yuqoridagi tugmani bosing."
          />
        ) : (
          currentItems.map((item) => (
            <Cell
              key={item.name}
              before={
                <Avatar
                  size={40}
                  style={{
                    backgroundColor: item.type === 'folder' ? 'rgba(56, 189, 248, 0.15)' : 'rgba(168, 85, 247, 0.15)',
                    display: 'flex',
                    alignItems: 'center',
                    justifyContent: 'center',
                    fontSize: '20px'
                  }}
                >
                  {item.type === 'folder' ? '📁' : '📄'}
                </Avatar>
              }
              subhead={item.type === 'folder' ? 'Papka' : item.size}
              description={item.date}
              after={
                <div style={{ display: 'flex', gap: '6px', alignItems: 'center' }}>
                  {item.type === 'file' && onOpenFileInEditor && (
                    <Button
                      size="s"
                      mode="outline"
                      onClick={(e) => {
                        e.stopPropagation();
                        onOpenFileInEditor(item);
                      }}
                    >
                      Tahrirlash
                    </Button>
                  )}
                  <Button
                    size="s"
                    mode="plain"
                    onClick={(e) => {
                      e.stopPropagation();
                      handleDeleteItem(item.name);
                    }}
                    style={{ color: '#ef4444' }}
                  >
                    🗑
                  </Button>
                </div>
              }
              onClick={() => handleOpenItem(item)}
            >
              <span style={{ fontWeight: 600 }}>{item.name}</span>
            </Cell>
          ))
        )}
      </Section>

      {/* Selected File Viewer Sheet */}
      {selectedFile && (
        <Section
          header={`FAYL MAZMUNI: ${selectedFile.name}`}
          footer={`Hajmi: ${selectedFile.size} • Saqlangan vaqti: ${selectedFile.date}`}
        >
          <div style={{ padding: '16px', background: 'var(--tgui--secondary_bg_color)' }}>
            <pre
              style={{
                margin: 0,
                padding: '12px',
                background: '#090e15',
                color: '#38bdf8',
                borderRadius: '8px',
                fontSize: '13px',
                lineHeight: '1.5',
                fontFamily: 'monospace',
                overflowX: 'auto',
                whiteSpace: 'pre-wrap'
              }}
            >
              {selectedFile.content || '(Fayl mazmuni bo\'sh)'}
            </pre>
            <div style={{ marginTop: '12px', display: 'flex', gap: '8px', justifyContent: 'flex-end' }}>
              {onOpenFileInEditor && (
                <Button
                  size="m"
                  mode="filled"
                  onClick={() => onOpenFileInEditor(selectedFile)}
                >
                  📝 Muharrirda ochish
                </Button>
              )}
              <Button size="m" mode="outline" onClick={() => setSelectedFile(null)}>
                Yopish
              </Button>
            </div>
          </div>
        </Section>
      )}

    </div>
  );
}
