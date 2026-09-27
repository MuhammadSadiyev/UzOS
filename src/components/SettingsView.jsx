import React, { useState } from 'react';
import { Section, Cell, Switch, Badge, Button, Avatar } from '@telegram-apps/telegram-ui';

export default function SettingsView() {
  const [zeroTelemetry, setZeroTelemetry] = useState(true);
  const [localEncryption, setLocalEncryption] = useState(true);
  const [darkMode, setDarkMode] = useState(true);
  const [resetStatus, setResetStatus] = useState('');

  const handleResetVFS = () => {
    localStorage.clear();
    setResetStatus('✅ VFS xotirasi muvaffaqiyatli tozalandi va birlamchi holatga keltirildi!');
    setTimeout(() => setResetStatus(''), 4000);
  };

  return (
    <div style={{ padding: '16px', display: 'flex', flexDirection: 'column', gap: '16px' }}>
      
      {/* Profile Header */}
      <Section header="UZOS PROFILI">
        <Cell
          before={
            <Avatar size={54} style={{ background: 'linear-gradient(135deg, #0284c7 0%, #1e40af 100%)', color: '#fff', fontSize: '20px', fontWeight: 800, display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
              UZ
            </Avatar>
          }
          subhead="Tizim Administratori"
          description="@uzos_cloud • O'zbekiston Respublikasi"
          after={<Badge mode="outline">SUVEREN</Badge>}
        >
          <span style={{ fontSize: '16px', fontWeight: 700 }}>UzOS Foydalanuvchisi</span>
        </Cell>
      </Section>

      {/* Security & Sovereignty Settings */}
      <Section
        header="KIBER-XAVFSIZLIK VA MAXFIYLIK"
        footer="Zero-Telemetry: Tashqi kuzatuv tarmoqlariga hech qanday ma'lumot yuborilmaydi."
      >
        <Cell
          Component="label"
          before={<Avatar size={36} style={{ background: '#22c55e', color: '#fff' }}>🛡️</Avatar>}
          subhead="TELEMETRIYA"
          description="Barcha tashqi ma'lumot so'rovlarini to'sish"
          after={<Switch checked={zeroTelemetry} onChange={(e) => setZeroTelemetry(e.target.checked)} />}
        >
          Zero-Telemetry Himoyasi
        </Cell>

        <Cell
          Component="label"
          before={<Avatar size={36} style={{ background: '#3b82f6', color: '#fff' }}>🔒</Avatar>}
          subhead="MAHALLIY SHIFRLASH"
          description="AES-GCM 256-bit shifrlash kalitlari"
          after={<Switch checked={localEncryption} onChange={(e) => setLocalEncryption(e.target.checked)} />}
        >
          VFS Ma'lumotlar Shifrlash
        </Cell>

        <Cell
          before={<Avatar size={36} style={{ background: '#0284c7', color: '#fff', fontWeight: 800 }}>ID</Avatar>}
          subhead="IDENTIFIKATSIYA"
          description="Milliy identifikatsiya tizimi faol"
          after={<Badge mode="outline">Bog'langan</Badge>}
        >
          OneID.uz Kirish
        </Cell>
      </Section>

      {/* Interface & TelegramUI Settings */}
      <Section
        header="INTERFEYS VA DIZAYN TIZIMI"
        footer="Rasmiy @telegram-apps/telegram-ui komponentlari va CSS tokenlari qo'llanilgan."
      >
        <Cell
          before={<Avatar size={36} style={{ background: '#a855f7', color: '#fff' }}>🎨</Avatar>}
          subhead="DIZAYN ASOSI"
          description="Telegram Mini Apps Rasmiy UI Tizimi"
          after={<Badge mode="outline">1:1 UI Design</Badge>}
        >
          @telegram-apps/telegram-ui
        </Cell>

        <Cell
          Component="label"
          before={<Avatar size={36} style={{ background: '#1e293b', color: '#fff' }}>🌙</Avatar>}
          subhead="RANG MAVZUSI"
          description="Telegram Dark Mode (iOS / Desktop)"
          after={<Switch checked={darkMode} onChange={(e) => setDarkMode(e.target.checked)} />}
        >
          Qorong'i Mavzu (Dark Mode)
        </Cell>

        <Cell
          before={<Avatar size={36} style={{ background: '#059669', color: '#fff' }}>🇺🇿</Avatar>}
          subhead="TIZIM TILI"
          description="O'zbek tili (Lotin alifbosi)"
          after={<Badge mode="outline">O'zbekcha</Badge>}
        >
          Milliylik va Mahalliylashtirish
        </Cell>
      </Section>

      {/* System Information & Factory Reset */}
      <Section
        header="TIZIM HAQIDA MA'LUMOT"
        footer="UzOS — Ochiq kodli mustaqil milliy raqamli infratuzilma."
      >
        <Cell subhead="TIZIM VERSIYASI" after={<Badge>v2.0.4 WebOS</Badge>}>
          UzOS Cloud
        </Cell>

        <Cell subhead="LITSENZIYA" after={<Badge mode="outline">MIT Open Source</Badge>}>
          Dasturiy Huquqlar
        </Cell>

        <Cell subhead="YADRO ARXITEKTURASI" after={<Badge mode="outline">Web Hypervisor</Badge>}>
          Virtual Kernel
        </Cell>

        <div style={{ padding: '16px', background: 'var(--tgui--secondary_bg_color)' }}>
          {resetStatus && (
            <div style={{ padding: '8px 12px', marginBottom: '12px', background: 'rgba(34, 197, 94, 0.15)', color: '#4ade80', borderRadius: '8px', fontSize: '13px' }}>
              {resetStatus}
            </div>
          )}
          <Button size="l" mode="critical" stretched onClick={handleResetVFS}>
            ⚠️ Barcha VFS Xotirani Tozalash (Factory Reset)
          </Button>
        </div>
      </Section>

    </div>
  );
}
