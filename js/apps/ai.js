/* ==============================================================================
   UzOS Cloud (WebOS) — Milliy AI Assistant Application
   Native Uzbek AI Chatbot with Tech, Coding, and System Assistance
   ============================================================================== */

export class AIAssistantApp {
  constructor(container) {
    this.container = container;
    this.render();
  }

  render() {
    this.container.innerHTML = `
      <div class="app-ai">
        <!-- AI Chat Header -->
        <div class="ai-chat-header">
          <div class="ai-badge-online"></div>
          <div>
            <div class="ai-header-title">UzOS Milliy Sun'iy Intellekt</div>
            <div style="font-size: 11px; color: var(--text-secondary);">O'zbek tili va dasturlash yordamchisi</div>
          </div>
        </div>

        <!-- Chat Messages -->
        <div class="ai-chat-messages" id="ai-messages">
          <div class="ai-bubble bot">
            Assalomu alaykum! Men <b>UzOS Milliy AI</b> yordamchisiman. 🇺🇿<br><br>
            Sizga operatsion tizim, dasturlash (Python, JavaScript, C++), texnologiyalar yoki shaxsiy masalalarda qanday yordam bera olaman?
          </div>
        </div>

        <!-- Quick Prompts -->
        <div class="ai-quick-prompts">
          <div class="ai-chip" data-prompt="UzOS Cloud nima va qanday ishlaydi?">💡 UzOS nima?</div>
          <div class="ai-chip" data-prompt="Python'da Telegram bot qanday yaratiladi?">🤖 Telegram Bot</div>
          <div class="ai-chip" data-prompt="Raqamli suverenitet va Zero-Telemetry nima?">🛡 Suverenitet</div>
          <div class="ai-chip" data-prompt="JavaScript'da qiziqarli algoritm misoli keltir">⚡ Kod yozish</div>
        </div>

        <!-- Input Area -->
        <div class="ai-input-area">
          <input type="text" class="ai-input" id="ai-input-field" placeholder="Savolingizni yozing..." />
          <button class="ai-send-btn" id="ai-send-btn" title="Yuborish">➤</button>
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
    const el = document.createElement('div');
    el.className = 'ai-bubble user';
    el.textContent = text;
    this.messagesEl.appendChild(el);
    this.messagesEl.scrollTop = this.messagesEl.scrollHeight;
  }

  addBotMessage(html) {
    const el = document.createElement('div');
    el.className = 'ai-bubble bot';
    el.innerHTML = html;
    this.messagesEl.appendChild(el);
    this.messagesEl.scrollTop = this.messagesEl.scrollHeight;
  }

  generateAIResponse(query) {
    const lower = query.toLowerCase();

    // Show temporary typing indicator
    const typing = document.createElement('div');
    typing.className = 'ai-bubble bot';
    typing.innerHTML = `<span style="opacity: 0.6;">Fikrlanmoqda... ⏳</span>`;
    this.messagesEl.appendChild(typing);
    this.messagesEl.scrollTop = this.messagesEl.scrollHeight;

    setTimeout(() => {
      typing.remove();
      let response = "";

      if (lower.includes('uzos') || lower.includes('nima')) {
        response = `<b>UzOS Cloud</b> — bu O'zbekistonda yaratilgan birinchi to'liq brauzerda ishlovchi <b>Milliy Bulut Operatsion Tizimi (WebOS)</b>.<br><br>
        Uning bosh g'oyasi: har qanday foydalanuvchiga (hatto 2GB RAM'li eng oddiy kompyuterlarda ham) havolani ochish orqali xavfsiz, tejamkor va o'zbek tilidagi shaxsiy ish stolini taqdim etishdir. Tizimda 100% Zero-Telemetry printsipi amal qiladi.`;
      } else if (lower.includes('telegram') || lower.includes('bot')) {
        response = `Telegram bot yaratish uchun <b>python-telegram-bot</b> yoki <b>aiogram</b> kutubxonasidan foydalanish tavsiya etiladi:<br>
        <pre style="background:#090e15; padding:8px; border-radius:6px; margin:6px 0; font-family:var(--font-mono); font-size:11.5px; color:#4ade80;">
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
        <pre style="background:#090e15; padding:8px; border-radius:6px; margin:6px 0; font-family:var(--font-mono); font-size:11.5px; color:#60a5fa;">
const arr1 = [1, 2, 3, 4, 5];
const arr2 = [3, 4, 5, 6, 7];

const kesishma = arr1.filter(item => arr2.includes(item));
console.log(kesishma); // [3, 4, 5]
        </pre>`;
      } else {
        response = `Savolingiz uchun tashakkur! UzOS Milliy AI platformasi sizning <i>"${query}"</i> haqidagi so'rovingizni qabul qildi. Biz har kuni yangi modellar va o'zbek tili ma'lumotlar bazasini kengaytirib bormoqdamiz. Yana qanday savollaringiz bor?`;
      }

      this.addBotMessage(response);
    }, 450);
  }
}
