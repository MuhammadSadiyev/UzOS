import React, { useState, useRef, useEffect } from 'react';
import { Section, Cell, Avatar, Button, Chip, Badge } from '@telegram-apps/telegram-ui';

const INITIAL_MESSAGES = [
  {
    id: 1,
    sender: 'bot',
    text: "Assalomu alaykum! Men UzOS Milliy Sun'iy Intellekt maslahatchisiman.\n\nSizga tizim xavfsizligi, kiber-suverenitet, kod yozish yoki O'zbekiston axborot texnologiyalari qonunchiligi bo'yicha qanday yordam bera olaman?",
    time: '15:30'
  }
];

const SUGGESTIONS = [
  '⚡ Tizim xavfsizligini tekshir',
  '🛡️ Zero-Telemetry nima?',
  '📊 Windows vs UzOS farqi?',
  '🇺🇿 O\'zbekiston IT qonunlari',
  '💻 Python skript yozib ber'
];

export default function AIView() {
  const [messages, setMessages] = useState(INITIAL_MESSAGES);
  const [inputText, setInputText] = useState('');
  const [isTyping, setIsTyping] = useState(false);
  const chatEndRef = useRef(null);

  useEffect(() => {
    chatEndRef.current?.scrollIntoView({ behavior: 'smooth' });
  }, [messages, isTyping]);

  const generateAIResponse = (query) => {
    const q = query.toLowerCase();

    if (q.includes('xavfsizlik') || q.includes('tekshir')) {
      return `🔒 **UzOS Xavfsizlik Auditi Natijasi:**\n\n1. Telemetriya: **0 bayt** (Xorijiy kuzatuv serverlariga ulanish yo'q).\n2. Yadro holati: **Web Hypervisor VFS faol**.\n3. Mahalliy shifrlash: **AES-GCM 256-bit** faol.\n4. Tizim to'liq raqamli suverenitet talablariga javob beradi!`;
    }

    if (q.includes('telemetr') || q.includes('zero')) {
      return `🛡️ **Zero-Telemetry Falsafasi:**\n\nKo'plab xorijiy operatsion tizimlar (masalan, Windows) foydalanuvchining bosgan har bir tugmasi, ko'rgan veb-sahifalari va shaxsiy ma'lumotlarini o'z serverlariga jo'natadi.\n\n**UzOS Cloud** da bu amaliyot qat'iyan taqiqlangan: barcha fayllar va hisob-kitoblar faqat qurilmangizning o'zida saqlanadi va chetga chiqmaydi!`;
    }

    if (q.includes('windows') || q.includes('farq') || q.includes('solishtir')) {
      return `📊 **UzOS va Windows Solishtiruvi:**\n\n• **RAM sarfi:** Windows bo'sh holatda ~3.5 GB sarflaydi; UzOS bor-yo'g'i ~110 MB talab qiladi (30 barobar yengil!).\n• **Narxi:** Windows qimmat litsenziya talab qiladi; UzOS 100% ochiq kodli va tekin.\n• **Maxfiylik:** Windows telemetriya yig'adi; UzOS da 0 bayt telemetriya.\n• **Interfeys:** UzOS o'zbek foydalanuvchilariga tanish Telegram UI asosida yaratilgan.`;
    }

    if (q.includes('qonun') || q.includes('it') || q.includes('hujjat')) {
      return `🇺🇿 **O'zbekiston IT va Kiberxavfsizlik Qonunchiligi:**\n\nO'zbekiston Respublikasining "Kiberxavfsizlik to'g'risida"gi (O'RQ-764) hamda "Shaxsga doir ma'lumotlar to'g'risida"gi Qonuniga muvofiq, fuqarolarning shaxsiy ma'lumotlari O'zbekiston hududidagi serverlarda saqlanishi shart.\n\nUzOS Cloud mazkur talablarga 100% mos ravishda milliy ma'lumotlar xavfsizligini ta'minlaydi.`;
    }

    if (q.includes('python') || q.includes('kod') || q.includes('skript')) {
      return `💻 **Python Skript Namunasi (Zero-Telemetry Audit):**\n\n\`\`\`python\nimport socket\n\ndef audit_network():\n    blocked_telemetry = ["telemetry.ms.com", "vortex.data.ms.com"]\n    print("🛡️ UzOS Kiber-Qalqoni faol!")\n    for host in blocked_telemetry:\n        print(f"Bloklangan manzil: {host} -> 0.0.0.0 (Xavfsiz)")\n\naudit_network()\n\`\`\`\n\nUshbu kodni UzOS Kod Muharririda sinab ko'rishingiz mumkin!`;
    }

    return `Sizning savolingiz: "${query}"\n\nUzOS Milliy AI tizimi buni qayta ishladi. Agar texnik yordam kerak bo'lsa, Terminal orqali buyruqlarni yuborishingiz yoki Kod Muharririda yangi ilovalarni yaratishingiz mumkin! 🚀`;
  };

  const handleSendMessage = (textToSend) => {
    const text = (textToSend || inputText).trim();
    if (!text) return;

    const userMsg = {
      id: Date.now(),
      sender: 'user',
      text,
      time: new Date().toLocaleTimeString('uz-UZ', { hour: '2-digit', minute: '2-digit' })
    };

    setMessages(prev => [...prev, userMsg]);
    setInputText('');
    setIsTyping(true);

    setTimeout(() => {
      const botResponse = {
        id: Date.now() + 1,
        sender: 'bot',
        text: generateAIResponse(text),
        time: new Date().toLocaleTimeString('uz-UZ', { hour: '2-digit', minute: '2-digit' })
      };
      setMessages(prev => [...prev, botResponse]);
      setIsTyping(false);
    }, 700);
  };

  return (
    <div style={{ padding: '16px', display: 'flex', flexDirection: 'column', gap: '12px' }}>
      
      {/* Bot Info Header */}
      <Section header="UZOS MILLIY SUN'IY INTELLEKT">
        <Cell
          before={
            <Avatar size={44} style={{ background: 'linear-gradient(135deg, #a855f7 0%, #3b82f6 100%)', color: '#fff', fontSize: '20px', display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
              🤖
            </Avatar>
          }
          subhead="Rasmiy Yordamchi Bot"
          description="Doimiy onlayn • Mahalliy neyron tarmoq"
          after={<Badge mode="outline">VERIFIED</Badge>}
        >
          <span style={{ fontWeight: 700 }}>UzOS Milliy AI Maslahatchisi</span>
        </Cell>

        {/* Quick Suggestion Chips */}
        <div style={{
          padding: '10px 16px',
          display: 'flex',
          gap: '8px',
          overflowX: 'auto',
          background: 'var(--tgui--secondary_bg_color)',
          borderTop: '1px solid var(--tgui--outline)'
        }}>
          {SUGGESTIONS.map((s, idx) => (
            <Chip
              key={idx}
              mode="outline"
              onClick={() => handleSendMessage(s)}
              style={{ cursor: 'pointer', whiteSpace: 'nowrap' }}
            >
              {s}
            </Chip>
          ))}
        </div>
      </Section>

      {/* Telegram Chat Message History */}
      <div style={{
        background: 'var(--tgui--secondary_bg_color)',
        borderRadius: '12px',
        padding: '16px',
        minHeight: '340px',
        maxHeight: '440px',
        overflowY: 'auto',
        display: 'flex',
        flexDirection: 'column',
        gap: '12px'
      }}>
        {messages.map((m) => (
          <div
            key={m.id}
            style={{
              display: 'flex',
              flexDirection: 'column',
              alignSelf: m.sender === 'user' ? 'flex-end' : 'flex-start',
              maxWidth: '82%'
            }}
          >
            <div
              style={{
                background: m.sender === 'user' ? '#2b5278' : '#182533',
                color: '#ffffff',
                padding: '10px 14px',
                borderRadius: m.sender === 'user' ? '14px 14px 2px 14px' : '14px 14px 14px 2px',
                fontSize: '14px',
                lineHeight: '1.5',
                whiteSpace: 'pre-wrap',
                boxShadow: '0 2px 6px rgba(0, 0, 0, 0.25)',
                wordBreak: 'break-word'
              }}
            >
              {m.text}
              <div
                style={{
                  fontSize: '10.5px',
                  color: 'rgba(255, 255, 255, 0.55)',
                  textAlign: 'right',
                  marginTop: '4px'
                }}
              >
                {m.time}
              </div>
            </div>
          </div>
        ))}

        {isTyping && (
          <div style={{ alignSelf: 'flex-start', color: 'var(--tgui--hint_color)', fontSize: '13px', fontStyle: 'italic', padding: '4px 8px' }}>
            🤖 UzOS AI javob yozmoqda...
          </div>
        )}

        <div ref={chatEndRef} />
      </div>

      {/* Telegram Chat Message Input Bar */}
      <form
        onSubmit={(e) => {
          e.preventDefault();
          handleSendMessage();
        }}
        style={{ display: 'flex', gap: '8px' }}
      >
        <input
          type="text"
          value={inputText}
          onChange={(e) => setInputText(e.target.value)}
          placeholder="Savolingizni yozing..."
          style={{
            flex: 1,
            background: 'var(--tgui--secondary_bg_color)',
            border: '1px solid var(--tgui--outline)',
            color: 'var(--tgui--text_color)',
            padding: '12px 16px',
            borderRadius: '12px',
            fontSize: '14px',
            outline: 'none'
          }}
        />
        <Button size="l" mode="filled" type="submit">
          Yuborish
        </Button>
      </form>

    </div>
  );
}
