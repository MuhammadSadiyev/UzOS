import React, { useState } from 'react';
import { AppRoot, FixedLayout, Tabbar, Button, Badge } from '@telegram-apps/telegram-ui';

// Components
import DashboardView from './components/DashboardView.jsx';
import TerminalView from './components/TerminalView.jsx';
import FilesView from './components/FilesView.jsx';
import EditorView from './components/EditorView.jsx';
import AIView from './components/AIView.jsx';
import SettingsView from './components/SettingsView.jsx';

export default function App() {
  const [activeTab, setActiveTab] = useState('dashboard');
  const [selectedEditorFile, setSelectedEditorFile] = useState(null);

  const renderActiveView = () => {
    switch (activeTab) {
      case 'dashboard':
        return <DashboardView onNavigate={(tab) => setActiveTab(tab)} />;
      case 'terminal':
        return <TerminalView />;
      case 'files':
        return (
          <FilesView
            onOpenFileInEditor={(file) => {
              setSelectedEditorFile(file);
              setActiveTab('editor');
            }}
          />
        );
      case 'editor':
        return <EditorView initialFile={selectedEditorFile} />;
      case 'ai':
        return <AIView />;
      case 'settings':
        return <SettingsView />;
      default:
        return <DashboardView onNavigate={(tab) => setActiveTab(tab)} />;
    }
  };

  const getTabTitle = () => {
    switch (activeTab) {
      case 'dashboard':
        return 'Tizim Markazi';
      case 'terminal':
        return 'Web Terminal';
      case 'files':
        return 'Bulut Fayllari';
      case 'editor':
        return 'Kod Muharriri';
      case 'ai':
        return 'Milliy AI Bot';
      case 'settings':
        return 'Tizim Sozlamalari';
      default:
        return 'UzOS Cloud';
    }
  };

  return (
    <AppRoot appearance="dark" platform="ios">
      <div style={{
        minHeight: '100vh',
        backgroundColor: 'var(--tgui--bg_color, #0f172a)',
        color: 'var(--tgui--text_color, #ffffff)',
        display: 'flex',
        flexDirection: 'column',
        alignItems: 'center',
        boxSizing: 'border-box'
      }}>
        
        {/* Main Telegram App Viewport Container */}
        <div style={{
          width: '100%',
          maxWidth: '720px',
          minHeight: '100vh',
          display: 'flex',
          flexDirection: 'column',
          position: 'relative',
          paddingBottom: '88px', // Space for fixed Tabbar
          boxSizing: 'border-box'
        }}>
          
          {/* Authentic Telegram Mini App Navigation Header */}
          <header style={{
            position: 'sticky',
            top: 0,
            zIndex: 100,
            backgroundColor: 'rgba(15, 23, 42, 0.88)',
            backdropFilter: 'blur(16px)',
            WebkitBackdropFilter: 'blur(16px)',
            borderBottom: '1px solid rgba(255, 255, 255, 0.08)',
            padding: '12px 16px',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'space-between'
          }}>
            <div style={{ display: 'flex', alignItems: 'center', gap: '12px' }}>
              {/* National Honeycomb Logo */}
              <div style={{
                width: 36,
                height: 36,
                borderRadius: '50%',
                background: 'linear-gradient(135deg, #0284c7 0%, #38bdf8 100%)',
                display: 'flex',
                alignItems: 'center',
                justifyContent: 'center',
                boxShadow: '0 2px 8px rgba(2, 132, 199, 0.4)'
              }}>
                <svg width="22" height="22" viewBox="0 0 32 32" fill="none">
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

              <div>
                <div style={{ display: 'flex', alignItems: 'center', gap: '6px' }}>
                  <span style={{ fontWeight: 700, fontSize: '15px', color: '#f8fafc' }}>
                    UzOS Cloud
                  </span>
                  <Badge type="number" mode="outline" style={{ fontSize: '10px' }}>
                    2.0
                  </Badge>
                </div>
                <div style={{ fontSize: '11.5px', color: 'var(--tgui--hint_color, #94a3b8)' }}>
                  {getTabTitle()} • 100% Telegram UI
                </div>
              </div>
            </div>

            <div style={{ display: 'flex', alignItems: 'center', gap: '8px' }}>
              <a
                href="/"
                style={{
                  fontSize: '12px',
                  color: '#38bdf8',
                  textDecoration: 'none',
                  padding: '6px 10px',
                  borderRadius: '8px',
                  background: 'rgba(56, 189, 248, 0.1)',
                  fontWeight: 600
                }}
              >
                🌐 Asosiy Sayt
              </a>
            </div>
          </header>

          {/* Active View Body */}
          <main style={{ flex: 1 }}>
            {renderActiveView()}
          </main>

          {/* Authentic Telegram Fixed Bottom Tabbar */}
          <FixedLayout vertical="bottom" style={{ maxWidth: '720px', left: '50%', transform: 'translateX(-50%)' }}>
            <Tabbar>
              
              <Tabbar.Item
                text="Boshqaruv"
                selected={activeTab === 'dashboard'}
                onClick={() => setActiveTab('dashboard')}
              >
                <svg width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
                  <path d="m3 9 9-7 9 7v11a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2z"/>
                  <polyline points="9 22 9 12 15 12 15 22"/>
                </svg>
              </Tabbar.Item>

              <Tabbar.Item
                text="Terminal"
                selected={activeTab === 'terminal'}
                onClick={() => setActiveTab('terminal')}
              >
                <svg width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
                  <polyline points="4 17 10 11 4 5"/>
                  <line x1="12" y1="19" x2="20" y2="19"/>
                </svg>
              </Tabbar.Item>

              <Tabbar.Item
                text="Fayllar"
                selected={activeTab === 'files'}
                onClick={() => setActiveTab('files')}
              >
                <svg width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
                  <path d="M4 20h16a2 2 0 0 0 2-2V8a2 2 0 0 0-2-2h-7.93a2 2 0 0 1-1.66-.9l-.82-1.2A2 2 0 0 0 7.93 3H4a2 2 0 0 0-2 2v13c0 1.1.9 2 2 2Z"/>
                </svg>
              </Tabbar.Item>

              <Tabbar.Item
                text="Muharrir"
                selected={activeTab === 'editor'}
                onClick={() => setActiveTab('editor')}
              >
                <svg width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
                  <path d="M12 20h9"/>
                  <path d="M16.5 3.5a2.121 2.121 0 0 1 3 3L7 19l-4 1 1-4L16.5 3.5z"/>
                </svg>
              </Tabbar.Item>

              <Tabbar.Item
                text="Milliy AI"
                selected={activeTab === 'ai'}
                onClick={() => setActiveTab('ai')}
              >
                <svg width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
                  <rect width="18" height="18" x="3" y="3" rx="2"/>
                  <path d="M9 9h.01"/>
                  <path d="M15 9h.01"/>
                  <path d="M8 15s1.5 2 4 2 4-2 4-2"/>
                  <path d="M12 3v-2"/>
                </svg>
              </Tabbar.Item>

              <Tabbar.Item
                text="Sozlamalar"
                selected={activeTab === 'settings'}
                onClick={() => setActiveTab('settings')}
              >
                <svg width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
                  <circle cx="12" cy="12" r="3"/>
                  <path d="M19.4 15a1.65 1.65 0 0 0 .33 1.82l.06.06a2 2 0 0 1 0 2.83 2 2 0 0 1-2.83 0l-.06-.06a1.65 1.65 0 0 0-1.82-.33 1.65 1.65 0 0 0-1 1.51V21a2 2 0 0 1-2 2 2 2 0 0 1-2-2v-.09A1.65 1.65 0 0 0 9 19.4a1.65 1.65 0 0 0-1.82.33l-.06.06a2 2 0 0 1-2.83 0 2 2 0 0 1 0-2.83l.06-.06a1.65 1.65 0 0 0 .33-1.82 1.65 1.65 0 0 0-1.51-1H3a2 2 0 0 1-2-2 2 2 0 0 1 2-2h.09A1.65 1.65 0 0 0 4.6 9a1.65 1.65 0 0 0-.33-1.82l-.06-.06a2 2 0 0 1 0-2.83 2 2 0 0 1 2.83 0l.06.06a1.65 1.65 0 0 0 1.82.33H9a1.65 1.65 0 0 0 1-1.51V3a2 2 0 0 1 2-2 2 2 0 0 1 2 2v.09a1.65 1.65 0 0 0 1 1.51 1.65 1.65 0 0 0 1.82-.33l.06-.06a2 2 0 0 1 2.83 0 2 2 0 0 1 0 2.83l-.06.06a1.65 1.65 0 0 0-.33 1.82V9a1.65 1.65 0 0 0 1.51 1H21a2 2 0 0 1 2 2 2 2 0 0 1-2 2h-.09a1.65 1.65 0 0 0-1.51 1z"/>
                </svg>
              </Tabbar.Item>

            </Tabbar>
          </FixedLayout>

        </div>
      </div>
    </AppRoot>
  );
}
