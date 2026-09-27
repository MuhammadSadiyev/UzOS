import React from 'react';
import { Section, Cell, Banner, Button, Badge, Switch, Avatar } from '@telegram-apps/telegram-ui';

export default function DashboardView({ onNavigate }) {
  return (
    <div style={{ padding: '16px', display: 'flex', flexDirection: 'column', gap: '16px' }}>
      
      {/* Official TelegramUI Banner */}
      <Banner
        type="section"
        header="UzOS Cloud 2.0 WebOS"
        subheader="O'zbekiston Milliy Suveren Operatsion Tizimi"
        description="100% Telegram UI rasmiy dizayn tizimi asosida. Hech qanday xorijiy telemetriya yo'q, xavfsiz va tezkor."
        before={
          <div style={{
            width: 48,
            height: 48,
            borderRadius: '50%',
            background: 'linear-gradient(135deg, #0284c7 0%, #38bdf8 100%)',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'center',
            boxShadow: '0 4px 12px rgba(2, 132, 199, 0.4)'
          }}>
            <svg width="28" height="28" viewBox="0 0 32 32" fill="none">
              <g stroke="white" strokeWidth="1.1" strokeLinejoin="round" fill="#0284C7">
                <polygon points="8.6,11.7 12.3,13.8 12.3,18.2 8.6,20.3 4.8,18.2 4.8,13.8"/>
                <polygon points="23.4,11.7 27.2,13.8 27.2,18.2 23.4,20.3 19.7,18.2 19.7,13.8"/>
                <polygon points="12.3,5.2 16,7.4 16,11.7 12.3,13.8 8.6,11.7 8.6,7.4"/>
                <polygon points="19.7,5.2 23.4,7.4 23.4,11.7 19.7,13.8 16,11.7 16,7.4"/>
                <polygon points="12.3,18.2 16,20.3 16,24.7 12.3,26.8 8.6,24.7 8.6,20.3"/>
                <polygon points="19.7,18.2 23.4,20.3 23.4,24.7 19.7,26.8 16,24.7 16,20.3"/>
              </g>
              <polygon points="16,11.7 19.7,13.8 19.7,18.2 16,20.3 12.3,18.2 12.3,13.8" fill="white"/>
            </svg>
          </div>
        }
      >
        <div style={{ display: 'flex', gap: '8px', marginTop: '12px' }}>
          <Button size="s" mode="filled" onClick={() => onNavigate('terminal')}>
            ⚡ Web Shell
          </Button>
          <Button size="s" mode="beamed" onClick={() => onNavigate('ai')}>
            🤖 AI Yordamchi
          </Button>
          <Button size="s" mode="outline" onClick={() => onNavigate('files')}>
            📁 Fayllar
          </Button>
        </div>
      </Banner>

      {/* Real-time System Telemetry & Monitor */}
      <Section
        header="TIZIM HOLATI VA RESURSLAR"
        footer="Web Hypervisor VFS — brauzer xotirasida to'liq mustaqil hisob-kitob."
      >
        <Cell
          before={<Avatar size={36} style={{ background: '#38bdf8', color: '#0f172a', fontWeight: 800 }}>CPU</Avatar>}
          subhead="PROTSESSOR YUKLAMASI"
          description="Web Hypervisor VFS 60+ FPS"
          after={<Badge type="number">0.9%</Badge>}
        >
          Virtual Yadro (Tejamkor)
        </Cell>

        <Cell
          before={<Avatar size={36} style={{ background: '#22c55e', color: '#0f172a', fontWeight: 800 }}>RAM</Avatar>}
          subhead="OPERATIV XOTIRA"
          description="Windows (4000 MB) vs UzOS (112 MB)"
          after={<Badge type="number">112 MB</Badge>}
        >
          Xotira Sarfi (30x Yengil)
        </Cell>

        <Cell
          before={<Avatar size={36} style={{ background: '#a855f7', color: '#fff', fontWeight: 800 }}>🛡️</Avatar>}
          subhead="KIBER-SUVERENITET"
          description="Xorijiy telemetriya serverlari: 0 dona"
          after={<Badge mode="outline">0 Bayt</Badge>}
        >
          Zero-Telemetry Himoyasi
        </Cell>

        <Cell
          Component="label"
          before={<Avatar size={36} style={{ background: '#f59e0b', color: '#fff', fontWeight: 800 }}>🔑</Avatar>}
          subhead="MAHALLIY KRIPTOGRAFIYA"
          description="Barcha ma'lumotlar AES-256 shifrlangan"
          after={<Switch defaultChecked />}
        >
          Shifrlangan VFS Xotira
        </Cell>
      </Section>

      {/* National Integration Ecosystem */}
      <Section
        header="MILLIY DAVLAT INTEGRATSIYASI"
        footer="O'zbekiston Respublikasi elektron hukumati bilan xavfsiz shlyuzlar."
      >
        <Cell
          before={<Avatar size={36} style={{ background: '#0284c7', color: '#fff', fontWeight: 800 }}>ID</Avatar>}
          subhead="YAGONA IDENTIFIKATSIYA"
          description="Jismoniy va yuridik shaxslar uchun OneID"
          after={<Badge mode="outline">Bog'langan</Badge>}
        >
          OneID.uz Identifikatsiya
        </Cell>

        <Cell
          before={<Avatar size={36} style={{ background: '#059669', color: '#fff', fontWeight: 800 }}>E</Avatar>}
          subhead="ELEKTRON RAQAMLI IMZO"
          description="Soliq va davlat xizmatlari kalitlari"
          after={<Badge mode="outline">Faol</Badge>}
        >
          E-Imzo Milliy Kriptografiya
        </Cell>

        <Cell
          before={<Avatar size={36} style={{ background: '#6366f1', color: '#fff', fontWeight: 800 }}>📊</Avatar>}
          subhead="OCHIQ MA'LUMOTLAR"
          description="Statistika va davlat ochiq reyestrlari"
          after={
            <Button size="s" mode="outline" onClick={() => window.open('https://data.gov.uz', '_blank')}>
              Ochish
            </Button>
          }
        >
          Data.gov.uz Ochiq Portali
        </Cell>
      </Section>

      {/* Quick Launch Applications */}
      <Section header="UZOS ASOSIY ILOVALARI">
        <Cell
          before={<Avatar size={40} style={{ background: '#0f172a', border: '1px solid #38bdf8', color: '#38bdf8', fontWeight: 800 }}>{'>_'}</Avatar>}
          subhead="WEB SHELL"
          description="Tizim buyruqlari, uzosfetch, ls, matrix..."
          after={<Button size="s" mode="filled" onClick={() => onNavigate('terminal')}>Ochish</Button>}
          onClick={() => onNavigate('terminal')}
        >
          UzOS Terminal
        </Cell>

        <Cell
          before={<Avatar size={40} style={{ background: 'rgba(245, 158, 11, 0.2)', color: '#f59e0b', fontSize: '20px' }}>📁</Avatar>}
          subhead="FAYLLAR TIZIMI"
          description="Bulut xotirasi, hujjatlar, loyihalar..."
          after={<Button size="s" mode="filled" onClick={() => onNavigate('files')}>Ochish</Button>}
          onClick={() => onNavigate('files')}
        >
          Virtual Fayllar Menejeri
        </Cell>

        <Cell
          before={<Avatar size={40} style={{ background: 'rgba(59, 130, 246, 0.2)', color: '#3b82f6', fontSize: '20px' }}>📝</Avatar>}
          subhead="DASTURLASH STUDIYASI"
          description="JS, CSS, Bash, Markdown muharriri..."
          after={<Button size="s" mode="filled" onClick={() => onNavigate('editor')}>Ochish</Button>}
          onClick={() => onNavigate('editor')}
        >
          UzOS Kod Muharriri
        </Cell>

        <Cell
          before={<Avatar size={40} style={{ background: 'rgba(168, 85, 247, 0.2)', color: '#a855f7', fontSize: '20px' }}>🤖</Avatar>}
          subhead="TELEGRAM CHATBOT"
          description="Kiber-maslahatchi, qonunchilik, yordam..."
          after={<Button size="s" mode="filled" onClick={() => onNavigate('ai')}>Ochish</Button>}
          onClick={() => onNavigate('ai')}
        >
          UzOS Milliy AI Maslahatchi
        </Cell>
      </Section>

    </div>
  );
}
