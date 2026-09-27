/* ==============================================================================
   UzOS Cloud (WebOS) — Milliy AI Assistant (100% Authentic Telegram Chat UI)
   ============================================================================== */

export class AIAssistantApp {
  constructor(container) {
    this.container = container;
    this.render();
  }

  getCurrentTime() {
    return new Date().toLocaleTimeString('uz-UZ', { hour: '2-digit', minute: '2-digit', hour12: false });
  }

  render() {
    this.container.innerHTML = `
      <div class="app-ai">
        <!-- Telegram Chat Header -->
        <div class="ai-chat-header">
          <div class="ai-avatar">AI</div>
          <div class="ai-user-info">
            <div class="ai-header-title">
              <span>UzOS Milliy AI</span>
              <svg class="tg-verified-icon" viewBox="0 0 16 16" fill="none">
                <path d="M8 0L9.8 1.9L12.4 1.5L13.4 3.9L15.9 4.9L15.6 7.5L17.2 9.5L15.6 11.5L15.9 14.1L13.4 15.1L12.4 17.5L9.8 17.1L8 19L6.2 17.1L3.6 17.5L2.6 15.1L0.1 14.1L0.4 11.5L-1.2 9.5L0.4 7.5L0.1 4.9L2.6 3.9L3.6 1.5L6.2 1.9L8 0Z" transform="scale(0.8) translate(2, 0)" fill="#3390ec"/>
                <path d="M4.5 8L6.8 10.3L11.5 5.5" stroke="white" stroke-width="1.8" stroke-linecap="round" stroke-linejoin="round"/>
              </svg>
            </div>
            <div class="ai-header-status">bot, doimiy onlayn</div>
          </div>
        </div>

        <!-- Telegram Chat Messages -->
        <div class="ai-chat-messages" id="ai-messages">
          <div class="tg-bubble-row bot">
            <div class="ai-bubble bot">
              Assalomu alaykum! Men <b>UzOS Milliy AI</b> yordamchisiman. 🇺🇿<br><br>
              Sizga operatsion tizim, dasturlash (Python, JavaScript, C++), texnologiyalar yoki shaxsiy masalalarda qanday yordam bera olaman?
              <div class="bubble-meta">
                <span>${this.getCurrentTime()}</span>
              </div>
            </div>
          </div>
        </div>

        <!-- Telegram Quick Prompts -->
        <div class="ai-quick-prompts">
          <div class="ai-chip" data-prompt="UzOS Cloud nima va qanday ishlaydi?">💡 UzOS nima?</div>
          <div class="ai-chip" data-prompt="Python'da Telegram bot qanday yaratiladi?">🤖 Telegram Bot</div>
          <div class="ai-chip" data-prompt="Raqamli suverenitet va Zero-Telemetry nima?">🛡 Suverenitet</div>
          <div class="ai-chip" data-prompt="JavaScript'da qiziqarli algoritm misoli keltir">⚡ Kod yozish</div>
        </div>

        <!-- Telegram Input Area -->
        <div class="ai-input-area">
          <button class="tg-attach-btn" title="Fayl biriktirish">📎</button>
          <input type="text" class="ai-input" id="ai-input-field" placeholder="Xabar yozing..." />
          <button class="ai-send-btn" id="ai-send-btn" title="Yuborish">
            <svg width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2.2" stroke-linecap="round" stroke-linejoin="round">
              <line x1="22" y1="2" x2="11" y2="13"></line>
              <polygon points="22 2 15 22 11 13 2 9 22 2"></polygon>
            </svg>
          </button>
        </div>
      </div>
    `;

    this.messagesEl = this.container.querySelector('#ai-messages');
    this.inputEl = this.container.querySelector('#ai-input-field');
    this.sendBtn = this.container.querySelector('#ai-send-btn');

    this.bindEvents();
  }

  bindEvents() {
    const handleSend = () => {
      const query = this.inputEl.value.trim();
      if (!query) return;
      this.inputEl.value = '';
      this.addUserMessage(query);
      this.generateAIResponse(query);
    };

    this.sendBtn.addEventListener('click', handleSend);
    this.inputEl.addEventListener('keydown', (e) => {
      if (e.key === 'Enter') handleSend();
    });

    this.container.querySelectorAll('.ai-chip').forEach(chip => {
      chip.addEventListener('click', () => {
        const prompt = chip.dataset.prompt;
        this.addUserMessage(prompt);
        this.generateAIResponse(prompt);
      });
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
    this.messagesEl.appendChild(row);
    this.messagesEl.scrollTop = this.messagesEl.scrollHeight;
  }

  addBotMessage(html) {
    const row = document.createElement('div');
    row.className = 'tg-bubble-row bot';
    row.innerHTML = `
      <div class="ai-bubble bot">
        ${html}
        <div class="bubble-meta">
          <span>${this.getCurrentTime()}</span>
        </div>
      </div>
    `;
    this.messagesEl.appendChild(row);
    this.messagesEl.scrollTop = this.messagesEl.scrollHeight;
  }

  escapeHtml(str) {
    return str.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;');
  }

  generateAIResponse(query) {
    const lower = query.toLowerCase();

    // Telegram typing indicator
    const typingRow = document.createElement('div');
    typingRow.className = 'tg-bubble-row bot';
    typingRow.innerHTML = `
      <div class="ai-bubble bot" style="color:var(--tg-theme-subtitle-text-color); font-size:12.5px;">
        yozmoqda... ✍️
      </div>
    `;
    this.messagesEl.appendChild(typingRow);
    this.messagesEl.scrollTop = this.messagesEl.scrollHeight;

    setTimeout(() => {
      typingRow.remove();
      let response = "";

      if (lower.includes('uzos') || lower.includes('nima')) {
        response = `<b>UzOS Cloud</b> — bu O'zbekistonda yaratilgan birinchi to'liq brauzerda ishlovchi <b>Milliy Bulut Operatsion Tizimi (WebOS)</b>.<br><br>
        Uning bosh g'oyasi: har qanday foydalanuvchiga (hatto 2GB RAM'li eng oddiy kompyuterlarda ham) havolani ochish orqali xavfsiz, tejamkor va o'zbek tilidagi shaxsiy ish stolini taqdim etishdir. Tizimda 100% Zero-Telemetry printsipi amal qiladi.`;
      } else if (lower.includes('telegram') || lower.includes('bot')) {
        response = `Telegram bot yaratish uchun <b>python-telegram-bot</b> yoki <b>aiogram</b> kutubxonasidan foydalanish tavsiya etiladi:<br>
        <pre style="background:#090e15; padding:10px; border-radius:8px; margin:6px 0; font-family:var(--tg-font-mono); font-size:11.5px; color:#4ade80;">
from aiogram import Bot, Dispatcher, types
from aiogram.utils import executor

bot = Bot(token="SIZNING_TOKENINGIZ")
dp = Dispatcher(bot)

@dp.message_handler(commands=['start'])
async def send_welcome(message: types.Message):
    await message.reply("Assalomu alaykum! UzOS Cloud botiga xush kelibsiz!")

if __name__ == '__main__':
    executor.start_polling(dp, skip_updates=True)
        </pre>
        Ushbu kodni <b>UzOS Code</b> tahrirlagichida saqlab, sinab ko'rishingiz mumkin!`;
      } else if (lower.includes('suverenitet') || lower.includes('telemetriya')) {
        response = `<b>Raqamli Suverenitet:</b> Bu fuqarolar, ta'lim muassasalari va tashkilotlarning ma'lumotlari xorijiy korporatsiyalar (Microsoft, Google va boshqalar) serverlariga noqonuniy uzatilmasligini ta'minlash demakdir.<br><br>
        UzOS Cloud sizning fayllaringizni faqat shaxsiy keshda yoki himoyalangan milliy serverlarda saqlaydi.`;
      } else if (lower.includes('javascript') || lower.includes('kod')) {
        response = `JavaScript'da ikkita massiv kesishmasini (Intersection) topish uchun zamonaviy usul:<br>
        <pre style="background:#090e15; padding:10px; border-radius:8px; margin:6px 0; font-family:var(--tg-font-mono); font-size:11.5px; color:#60a5fa;">
const arr1 = [1, 2, 3, 4, 5];
const arr2 = [3, 4, 5, 6, 7];

const kesishma = arr1.filter(item => arr2.includes(item));
console.log(kesishma); // [3, 4, 5]
        </pre>`;
      } else {
        response = `Savolingiz uchun tashakkur! UzOS Milliy AI platformasi sizning <i>"${this.escapeHtml(query)}"</i> haqidagi so'rovingizni qabul qildi. Biz har kuni yangi modellar va o'zbek tili ma'lumotlar bazasini kengaytirib bormoqdamiz. Yana qanday savollaringiz bor?`;
      }

      this.addBotMessage(response);
    }, 450);
  }
}
