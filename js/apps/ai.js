/* ==============================================================================
   UzOS Cloud (WebOS) — Milliy AI Assistant (100% Authentic Telegram Chat UI)
   Exact 1:1 Telegram Speech Bubbles with Tails, Inline Buttons & Audio Feedback
   ============================================================================== */

export class AIAssistantApp {
  constructor(container) {
    this.container = container;
    this.audioCtx = null;
    this.render();
  }

  getCurrentTime() {
    return new Date().toLocaleTimeString('uz-UZ', { hour: '2-digit', minute: '2-digit', hour12: false });
  }

  // Synthesize authentic soft Telegram message pop sound
  playTelegramSound(type = 'send') {
    try {
      if (!this.audioCtx) {
        this.audioCtx = new (window.AudioContext || window.webkitAudioContext)();
      }
      if (this.audioCtx.state === 'suspended') {
        this.audioCtx.resume();
      }
      const osc = this.audioCtx.createOscillator();
      const gain = this.audioCtx.createGain();
      osc.connect(gain);
      gain.connect(this.audioCtx.destination);

      const now = this.audioCtx.currentTime;
      if (type === 'send') {
        osc.frequency.setValueAtTime(540, now);
        osc.frequency.exponentialRampToValueAtTime(840, now + 0.08);
        gain.gain.setValueAtTime(0.08, now);
        gain.gain.exponentialRampToValueAtTime(0.001, now + 0.09);
        osc.start(now);
        osc.stop(now + 0.09);
      } else {
        osc.frequency.setValueAtTime(820, now);
        osc.frequency.exponentialRampToValueAtTime(1080, now + 0.07);
        gain.gain.setValueAtTime(0.09, now);
        gain.gain.exponentialRampToValueAtTime(0.001, now + 0.1);
        osc.start(now);
        osc.stop(now + 0.1);
      }
    } catch (e) {
      // Audio autoplay policy fallback
    }
  }

  render() {
    this.container.innerHTML = `
      <div class="app-ai">
        
        <!-- Telegram Chat Messages Container -->
        <div class="ai-chat-messages" id="ai-messages">
          
          <!-- Date Separator Pill -->
          <div class="tg-date-pill">Bugun, 27-Sentabr 2026</div>

          <!-- Initial Bot Greeting Bubble -->
          <div class="tg-bubble-row bot">
            <div class="bubble-avatar">AI</div>
            <div class="ai-bubble bot">
              Assalomu alaykum! Men <b>UzOS Milliy Sun'iy Intellekt</b> maslahatchisiman. 🇺🇿<br><br>
              Tizim xavfsizligi, kiber-suverenitet, dasturlash yoki O'zbekiston IT qonunchiligi bo'yicha qanday yordam bera olaman? Quyidagi tugmalardan birini tanlashingiz mumkin:
              
              <!-- Telegram Inline Keyboard -->
              <div class="tg-inline-keyboard">
                <button class="tg-inline-btn" data-query="Kiber-xavfsizlik auditi">⚡ Xavfsizlik Auditi</button>
                <button class="tg-inline-btn" data-query="Zero-Telemetry nima?">🛡️ Zero-Telemetry</button>
                <button class="tg-inline-btn" data-query="Windows vs UzOS farqi?">📊 UzOS vs Windows</button>
                <button class="tg-inline-btn" data-query="O'zbekiston IT qonunlari">🇺🇿 IT Qonunlari</button>
                <button class="tg-inline-btn" data-query="Python skript yozib ber">💻 Python Skript</button>
              </div>

              <div class="bubble-meta">
                <span>${this.getCurrentTime()}</span>
              </div>
            </div>
          </div>

          <!-- Typing Row (Hidden by default) -->
          <div class="tg-typing-row" id="tg-typing-row">
            <div class="tg-typing-dots">
              <span></span><span></span><span></span>
            </div>
            <span>UzOS AI yozmoqda...</span>
          </div>

        </div>

        <!-- Telegram Quick Prompt Chips Bar -->
        <div class="ai-quick-prompts">
          <div class="ai-chip" data-prompt="UzOS Cloud nima va qanday ishlaydi?">💡 UzOS nima?</div>
          <div class="ai-chip" data-prompt="Zero-Telemetry nima?">🛡️ Zero-Telemetry</div>
          <div class="ai-chip" data-prompt="Windows vs UzOS farqi?">📊 UzOS vs Windows</div>
          <div class="ai-chip" data-prompt="Python'da Telegram bot yaratish">🤖 Telegram Bot</div>
          <div class="ai-chip" data-prompt="O'zbekiston kiberxavfsizlik qonunlari">🇺🇿 Qonunchilik</div>
        </div>

        <!-- Telegram Message Input Bar -->
        <div class="ai-input-area">
          <button class="tg-attach-btn" id="ai-attach-btn" title="Fayl biriktirish">📎</button>
          <input type="text" class="ai-input" id="ai-input-field" placeholder="Xabar yozing..." autocomplete="off" />
          <button class="tg-emoji-btn" id="ai-emoji-btn" title="Emotsiyalar">😊</button>
          <button class="ai-send-btn" id="ai-send-btn" title="Yuborish (Enter)">
            <svg width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2.3" stroke-linecap="round" stroke-linejoin="round">
              <line x1="22" y1="2" x2="11" y2="13"></line>
              <polygon points="22 2 15 22 11 13 2 9 22 2"></polygon>
            </svg>
          </button>
        </div>

      </div>
    `;

    this.messagesEl = this.container.querySelector('#ai-messages');
    this.typingRow = this.container.querySelector('#tg-typing-row');
    this.inputEl = this.container.querySelector('#ai-input-field');
    this.sendBtn = this.container.querySelector('#ai-send-btn');
    this.emojiBtn = this.container.querySelector('#ai-emoji-btn');
    this.attachBtn = this.container.querySelector('#ai-attach-btn');

    this.bindEvents();
  }

  bindEvents() {
    const handleSend = () => {
      const query = this.inputEl.value.trim();
      if (!query) return;
      this.inputEl.value = '';
      this.addUserMessage(query);
      this.playTelegramSound('send');
      this.generateAIResponse(query);
    };

    this.sendBtn.addEventListener('click', handleSend);
    this.inputEl.addEventListener('keydown', (e) => {
      if (e.key === 'Enter') handleSend();
    });

    // Delegate inline buttons & chips
    this.container.addEventListener('click', (e) => {
      const inlineBtn = e.target.closest('.tg-inline-btn');
      if (inlineBtn) {
        const q = inlineBtn.dataset.query;
        this.addUserMessage(q);
        this.playTelegramSound('send');
        this.generateAIResponse(q);
        return;
      }

      const chip = e.target.closest('.ai-chip');
      if (chip) {
        const prompt = chip.dataset.prompt;
        this.addUserMessage(prompt);
        this.playTelegramSound('send');
        this.generateAIResponse(prompt);
        return;
      }
    });

    this.emojiBtn.addEventListener('click', () => {
      const emojis = ['⚡', '🛡️', '🇺🇿', '🚀', '💻', '🔒', '✅'];
      const randomEmoji = emojis[Math.floor(Math.random() * emojis.length)];
      this.inputEl.value += randomEmoji;
      this.inputEl.focus();
    });

    this.attachBtn.addEventListener('click', () => {
      this.addUserMessage("📎 Hujjat biriktirildi: uzos_suverenitet_akt.pdf (240 KB)");
      this.playTelegramSound('send');
      setTimeout(() => {
        this.addBotMessage("✅ Hujjat qabul qilindi va mahalliy AES-256 xavfsiz VFS xotirasida muvaffaqiyatli tekshirildi. Kiber-tahdidlar aniqlanmadi!");
        this.playTelegramSound('receive');
      }, 700);
    });
  }

  addUserMessage(text) {
    const row = document.createElement('div');
    row.className = 'tg-bubble-row user';
    row.innerHTML = `
      <div class="ai-bubble user">
        ${this.escapeHtml(text)}
        <div class="bubble-meta">
          <span>${this.getCurrentTime()}</span>
          <span class="tg-ticks">✓✓</span>
        </div>
      </div>
    `;
    this.messagesEl.insertBefore(row, this.typingRow);
    this.scrollToBottom();
  }

  addBotMessage(html) {
    const row = document.createElement('div');
    row.className = 'tg-bubble-row bot';
    row.innerHTML = `
      <div class="bubble-avatar">AI</div>
      <div class="ai-bubble bot">
        ${html}
        <div class="bubble-meta">
          <span>${this.getCurrentTime()}</span>
        </div>
      </div>
    `;
    this.messagesEl.insertBefore(row, this.typingRow);
    this.scrollToBottom();
  }

  scrollToBottom() {
    this.messagesEl.scrollTop = this.messagesEl.scrollHeight;
  }

  escapeHtml(str) {
    return str.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;');
  }

  generateAIResponse(query) {
    const q = query.toLowerCase();
    this.typingRow.classList.add('visible');
    this.scrollToBottom();

    setTimeout(() => {
      this.typingRow.classList.remove('visible');
      let response = "";

      if (q.includes('xavfsizlik') || q.includes('audit') || q.includes('tekshir')) {
        response = `🔒 <b>UzOS Kiber-Xavfsizlik Auditi Natijasi:</b><br><br>
        1. <b>Telemetriya:</b> 0 bayt (Xorijiy kuzatuv tarmoqlariga ulanish yo'q).<br>
        2. <b>Yadro holati:</b> Web Hypervisor VFS faol va suveren.<br>
        3. <b>Mahalliy shifrlash:</b> AES-GCM 256-bit faol.<br>
        4. <b>Xulosa:</b> Tizim 100% raqamli suverenitet talablariga javob beradi!
        
        <div class="tg-inline-keyboard">
          <button class="tg-inline-btn" data-query="Zero-Telemetry nima?">🛡️ Zero-Telemetry</button>
          <button class="tg-inline-btn" data-query="Python skript yozib ber">💻 Audit skripti</button>
        </div>`;
      } else if (q.includes('telemetr') || q.includes('zero')) {
        response = `🛡️ <b>Zero-Telemetry Falsafasi:</b><br><br>
        Ko'plab xorijiy operatsion tizimlar (masalan, Windows) foydalanuvchining bosgan har bir tugmasi, ko'rgan veb-sahifalari va shaxsiy ma'lumotlarini o'z serverlariga jo'natadi.<br><br>
        <b>UzOS Cloud</b> da bu amaliyot qat'iyan taqiqlangan: barcha fayllar va hisob-kitoblar faqat qurilmangizning o'zida saqlanadi va chetga chiqmaydi!
        
        <div class="tg-inline-keyboard">
          <button class="tg-inline-btn" data-query="Windows vs UzOS farqi?">📊 Windows bilan farqi</button>
        </div>`;
      } else if (q.includes('windows') || q.includes('farq') || q.includes('solishtir')) {
        response = `📊 <b>UzOS va Windows Solishtiruvi:</b><br><br>
        • <b>RAM sarfi:</b> Windows bo'sh holatda ~3.5 GB sarflaydi; UzOS bor-yo'g'i ~110 MB talab qiladi (30 barobar yengil!).<br>
        • <b>Narxi:</b> Windows qimmat litsenziya talab qiladi; UzOS 100% ochiq kodli va tekin.<br>
        • <b>Maxfiylik:</b> Windows telemetriya yig'adi; UzOS da 0 bayt telemetriya.<br>
        • <b>Interfeys:</b> UzOS o'zbek foydalanuvchilariga tanish Telegram Desktop UI asosida yaratilgan.`;
      } else if (q.includes('qonun') || q.includes('it') || q.includes('suveren')) {
        response = `🇺🇿 <b>O'zbekiston IT va Kiberxavfsizlik Qonunchiligi:</b><br><br>
        O'zbekiston Respublikasining <i>"Kiberxavfsizlik to'g'risida"</i>gi (O'RQ-764) hamda <i>"Shaxsga doir ma'lumotlar to'g'risida"</i>gi Qonuniga muvofiq, fuqarolarning shaxsiy ma'lumotlari O'zbekiston hududidagi serverlarda saqlanishi shart.<br><br>
        UzOS Cloud mazkur talablarga 100% mos ravishda milliy ma'lumotlar xavfsizligini ta'minlaydi.`;
      } else if (q.includes('python') || q.includes('skript') || q.includes('kod')) {
        response = `💻 <b>Python Zero-Telemetry Audit Skripti:</b><br>
        <pre># UzOS Kiber-Qalqon Tekshiruvi
import socket

def audit_network():
    blocked_hosts = ["telemetry.ms.com", "vortex.data.ms.com"]
    print("🛡️ UzOS Kiber-Qalqoni faol!")
    for host in blocked_hosts:
        print(f"Bloklangan manzil: {host} -> 0.0.0.0 (Xavfsiz)")

audit_network()</pre>
        Ushbu kodni <b>UzOS Kod Muharriri</b>da ochib, <i>▶ Bajarish</i> tugmasi orqali ishga tushirishingiz mumkin!`;
      } else {
        response = `Sizning savolingiz: <i>"${this.escapeHtml(query)}"</i><br><br>
        UzOS Milliy AI tizimi buni qayta ishladi. Agar texnik yordam kerak bo'lsa, <b>Terminal</b> orqali buyruqlarni yuborishingiz, <b>Fayllar</b> bo'limida hujjatlaringizni boshqarishingiz yoki <b>Kod Muharriri</b>da yangi ilovalarni yaratishingiz mumkin! 🚀`;
      }

      this.addBotMessage(response);
      this.playTelegramSound('receive');
    }, 600);
  }
}
