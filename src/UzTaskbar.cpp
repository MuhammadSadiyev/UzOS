#include "UzTaskbar.h"
#include "UzWindow.h"
#include "UzDesktopTheme.h"
#include "styles/palette.h"
#include "styles/style_widgets.h"

#include <QtCore/QTime>
#include <QtCore/QDate>
#include <QtGui/QPainter>
#include <QtGui/QMouseEvent>
#include <QtGui/QEnterEvent>

namespace {

// Custom Start button with authentic Telegram hamburger icon and text
class TelegramStartButton : public QWidget {
public:
	TelegramStartButton(QWidget *parent, std::function<void()> clicked)
		: QWidget(parent)
		, _clicked(std::move(clicked)) {
		setFixedSize(92, 38);
		setCursor(Qt::PointingHandCursor);
		setAttribute(Qt::WA_Hover, true);
	}

protected:
	void enterEvent(QEnterEvent *e) override {
		_hovered = true;
		update();
		QWidget::enterEvent(e);
	}

	void leaveEvent(QEvent *e) override {
		_hovered = false;
		update();
		QWidget::leaveEvent(e);
	}

	void mousePressEvent(QMouseEvent *e) override {
		if (e->button() == Qt::LeftButton && _clicked) {
			_clicked();
		}
		QWidget::mousePressEvent(e);
	}

	void paintEvent(QPaintEvent *e) override {
		QPainter p(this);
		p.setRenderHint(QPainter::Antialiasing, true);
		p.setRenderHint(QPainter::SmoothPixmapTransform, true);

		// Background pill
		p.setPen(Qt::NoPen);
		p.setBrush(_hovered ? UzTheme::kActiveBg : UzTheme::kSearchBg);
		p.drawRoundedRect(rect(), 19, 19);

		// Telegram Hamburger icon (20x20)
		const auto iconPix = UzTheme::TintIcon(":/icons/hamburger.png", Qt::white, 20);
		if (!iconPix.isNull()) {
			p.drawPixmap(12, (height() - 20) / 2, iconPix);
		}

		// Text "UzOS"
		p.setFont(QFont("Segoe UI", 10, QFont::Bold));
		p.setPen(Qt::white);
		p.drawText(38, 24, "UzOS");
	}

private:
	std::function<void()> _clicked;
	bool _hovered = false;
};

// Custom Window Tab with authentic Telegram icon and text
class TelegramWindowTab : public QWidget {
public:
	TelegramWindowTab(
		QWidget *parent,
		UzOS::UzWindow *window,
		const QString &title,
		const QString &iconPath)
		: QWidget(parent)
		, _window(window)
		, _title(title)
		, _iconPath(iconPath) {
		setFixedHeight(34);
		setCursor(Qt::PointingHandCursor);
		setAttribute(Qt::WA_Hover, true);
		
		QFont font("Segoe UI", 9, QFont::DemiBold);
		QFontMetrics fm(font);
		const int textW = fm.horizontalAdvance(_title);
		setFixedWidth(36 + textW + 16);
	}

protected:
	void enterEvent(QEnterEvent *e) override {
		_hovered = true;
		update();
		QWidget::enterEvent(e);
	}

	void leaveEvent(QEvent *e) override {
		_hovered = false;
		update();
		QWidget::leaveEvent(e);
	}

	void mousePressEvent(QMouseEvent *e) override {
		if (e->button() == Qt::LeftButton && _window) {
			if (_window->isHidden()) {
				_window->show();
				_window->raise();
			} else {
				_window->raise();
			}
		}
		QWidget::mousePressEvent(e);
	}

	void paintEvent(QPaintEvent *e) override {
		QPainter p(this);
		p.setRenderHint(QPainter::Antialiasing, true);
		p.setRenderHint(QPainter::SmoothPixmapTransform, true);

		p.setPen(Qt::NoPen);
		p.setBrush(_hovered ? UzTheme::kHoverBg : UzTheme::kSearchBg);
		p.drawRoundedRect(rect(), 6, 6);

		// Icon
		const auto iconPix = UzTheme::TintIcon(_iconPath, _hovered ? Qt::white : UzTheme::kTelegramBlue, 18);
		if (!iconPix.isNull()) {
			p.drawPixmap(8, (height() - 18) / 2, iconPix);
		}

		// Title
		p.setFont(QFont("Segoe UI", 9, QFont::DemiBold));
		p.setPen(Qt::white);
		p.drawText(32, 22, _title);
	}

private:
	UzOS::UzWindow *_window = nullptr;
	QString _title;
	QString _iconPath;
	bool _hovered = false;
};

// Helper for clickable tray items (Language switcher)
class ClickableTrayItem : public QWidget {
public:
	ClickableTrayItem(QWidget *parent, std::function<void()> clicked)
		: QWidget(parent)
		, _clicked(std::move(clicked)) {
		setCursor(Qt::PointingHandCursor);
		setAttribute(Qt::WA_Hover, true);
	}

protected:
	void enterEvent(QEnterEvent *e) override {
		_hovered = true;
		update();
		QWidget::enterEvent(e);
	}

	void leaveEvent(QEvent *e) override {
		_hovered = false;
		update();
		QWidget::leaveEvent(e);
	}

	void mousePressEvent(QMouseEvent *e) override {
		if (e->button() == Qt::LeftButton && _clicked) {
			_clicked();
		}
		QWidget::mousePressEvent(e);
	}

	void paintEvent(QPaintEvent *e) override {
		if (_hovered) {
			QPainter p(this);
			p.setRenderHint(QPainter::Antialiasing, true);
			p.setPen(Qt::NoPen);
			p.setBrush(UzTheme::kHoverBg);
			p.drawRoundedRect(rect(), 6, 6);
		}
		QWidget::paintEvent(e);
	}

private:
	std::function<void()> _clicked;
	bool _hovered = false;
};

} // namespace

namespace UzOS {

UzTaskbar::UzTaskbar(QWidget *parent)
	: QWidget(parent) {
	setFixedHeight(48);

	auto *mainLayout = new QHBoxLayout(this);
	mainLayout->setContentsMargins(10, 4, 12, 4);
	mainLayout->setSpacing(10);

	// 1. Bespoke UzOS Start Button with Official Telegram Hamburger Icon
	_startBtn = new TelegramStartButton(this, [this]() {
		if (_startCallback) {
			_startCallback();
		}
	});
	mainLayout->addWidget(_startBtn);

	// 2. Open Windows Tabs Layout
	_tabsLayout = new QHBoxLayout();
	_tabsLayout->setSpacing(6);
	_tabsLayout->setContentsMargins(4, 0, 4, 0);
	mainLayout->addLayout(_tabsLayout);

	mainLayout->addStretch(1);

	// =========================================================================
	// 3. System Tray Container (Official Telegram Icons)
	// =========================================================================
	_trayWidget = new QWidget(this);
	_trayWidget->setFixedHeight(38);
	_trayWidget->setStyleSheet("background-color: #17212b; border-radius: 8px; border: 1px solid #242f3d;");
	auto *trayLayout = new QHBoxLayout(_trayWidget);
	trayLayout->setContentsMargins(10, 2, 10, 2);
	trayLayout->setSpacing(14);

	// 1. Wi-Fi / Network Status Indicator (Official Telegram Network Icon)
	auto *wifiBox = new QWidget(_trayWidget);
	auto *wifiBoxLayout = new QHBoxLayout(wifiBox);
	wifiBoxLayout->setContentsMargins(0, 0, 0, 0);
	_wifiLabel = new QLabel(wifiBox);
	_wifiLabel->setPixmap(UzTheme::TintIcon(":/icons/network.png", UzTheme::kTelegramBlue, 18));
	_wifiLabel->setToolTip("UzOS Tarmoq: Ulangan (100 Mbps)");
	wifiBoxLayout->addWidget(_wifiLabel);
	trayLayout->addWidget(wifiBox);

	// 2. Volume Indicator (Official Telegram Sound Icon)
	auto *volBox = new QWidget(_trayWidget);
	auto *volBoxLayout = new QHBoxLayout(volBox);
	volBoxLayout->setContentsMargins(0, 0, 0, 0);
	volBoxLayout->setSpacing(4);

	auto *volIcon = new QLabel(volBox);
	volIcon->setPixmap(UzTheme::TintIcon(":/icons/sound.png", UzTheme::kIconFg, 18));
	volBoxLayout->addWidget(volIcon);

	_volumeLabel = new QLabel("85%", volBox);
	_volumeLabel->setStyleSheet("color: #7f91a4; font-size: 11px; font-weight: 500; background: transparent; border: none;");
	volBoxLayout->addWidget(_volumeLabel);
	volBox->setToolTip("Ovoz balandligi: 85%");
	trayLayout->addWidget(volBox);

	// 3. Battery / Power Indicator (Official Telegram Battery Icon)
	auto *batBox = new QWidget(_trayWidget);
	auto *batBoxLayout = new QHBoxLayout(batBox);
	batBoxLayout->setContentsMargins(0, 0, 0, 0);
	batBoxLayout->setSpacing(4);

	auto *batIcon = new QLabel(batBox);
	batIcon->setPixmap(UzTheme::TintIcon(":/icons/battery.png", QColor(0x4c, 0xd9, 0x64), 18));
	batBoxLayout->addWidget(batIcon);

	_batteryLabel = new QLabel("100%", batBox);
	_batteryLabel->setStyleSheet("color: #4cd964; font-size: 11px; font-weight: bold; background: transparent; border: none;");
	batBoxLayout->addWidget(_batteryLabel);
	batBox->setToolTip("Quvvat: 100% (Tarmoqqa ulangan)");
	trayLayout->addWidget(batBox);

	// Divider
	auto *divider = new QWidget(_trayWidget);
	divider->setFixedSize(1, 18);
	divider->setStyleSheet("background-color: #242f3d;");
	trayLayout->addWidget(divider);

	// 4. Language Switcher (Official Telegram Language Icon + UZ/EN/RU)
	const QStringList langs = { "UZ", "EN", "RU" };
	auto *langBox = new ClickableTrayItem(_trayWidget, [this, langs]() {
		_langIndex = (_langIndex + 1) % langs.size();
		_langLabel->setText(langs[_langIndex]);
	});
	langBox->setFixedHeight(28);
	auto *langBoxLayout = new QHBoxLayout(langBox);
	langBoxLayout->setContentsMargins(4, 2, 4, 2);
	langBoxLayout->setSpacing(4);

	auto *langIcon = new QLabel(langBox);
	langIcon->setPixmap(UzTheme::TintIcon(":/icons/language.png", UzTheme::kIconFg, 16));
	langBoxLayout->addWidget(langIcon);

	_langLabel = new QLabel("UZ", langBox);
	_langLabel->setStyleSheet("color: #ffffff; font-size: 11px; font-weight: bold; background: transparent; border: none;");
	langBoxLayout->addWidget(_langLabel);
	langBox->setToolTip("Tilni almashtirish (UZ / EN / RU)");
	trayLayout->addWidget(langBox);

	// 5. Digital Clock & Date Container (Telegram Typography)
	auto *dateTimeLayout = new QVBoxLayout();
	dateTimeLayout->setContentsMargins(4, 2, 2, 2);
	dateTimeLayout->setSpacing(0);

	_timeLabel = new QLabel(QTime::currentTime().toString("HH:mm"), _trayWidget);
	_timeLabel->setStyleSheet("color: #ffffff; font-weight: bold; font-size: 12px; background: transparent; border: none;");
	_timeLabel->setAlignment(Qt::AlignCenter);
	dateTimeLayout->addWidget(_timeLabel);

	_dateLabel = new QLabel(QDate::currentDate().toString("dd.MM.yyyy"), _trayWidget);
	_dateLabel->setStyleSheet("color: #7f91a4; font-size: 10px; background: transparent; border: none;");
	_dateLabel->setAlignment(Qt::AlignCenter);
	dateTimeLayout->addWidget(_dateLabel);

	trayLayout->addLayout(dateTimeLayout);
	mainLayout->addWidget(_trayWidget);

	// Timer for live clock & date update
	_clockTimer = new QTimer(this);
	connect(_clockTimer, &QTimer::timeout, this, &UzTaskbar::updateClock);
	_clockTimer->start(1000);
}

void UzTaskbar::updateClock() {
	if (_timeLabel) {
		_timeLabel->setText(QTime::currentTime().toString("HH:mm"));
	}
	if (_dateLabel) {
		_dateLabel->setText(QDate::currentDate().toString("dd.MM.yyyy"));
	}
}

void UzTaskbar::addWindowTab(UzWindow *window) {
	if (!window || _windowButtons.find(window) != _windowButtons.end()) {
		return;
	}

	QString tabText = "Ilova";
	QString iconPath = ":/icons/terminal.png";

	const QString winTitle = window->title();
	if (winTitle.contains("Terminal", Qt::CaseInsensitive)) {
		tabText = "Terminal";
		iconPath = ":/icons/terminal.png";
	} else if (winTitle.contains("Files", Qt::CaseInsensitive) || winTitle.contains("Fayllar", Qt::CaseInsensitive)) {
		tabText = "Fayllar";
		iconPath = ":/icons/files.png";
	} else if (winTitle.contains("Sozlamalar", Qt::CaseInsensitive) || winTitle.contains("Settings", Qt::CaseInsensitive)) {
		tabText = "Sozlamalar";
		iconPath = ":/icons/settings.png";
	}

	auto *tabBtn = new TelegramWindowTab(this, window, tabText, iconPath);
	_tabsLayout->addWidget(tabBtn);
	_windowButtons[window] = tabBtn;
}

void UzTaskbar::removeWindowTab(UzWindow *window) {
	auto it = _windowButtons.find(window);
	if (it != _windowButtons.end()) {
		_tabsLayout->removeWidget(it->second);
		delete it->second;
		_windowButtons.erase(it);
	}
}

void UzTaskbar::paintEvent(QPaintEvent *e) {
	QPainter p(this);
	p.fillRect(rect(), UzTheme::kSidebarBg);
	p.setPen(QPen(UzTheme::kBorderColor, 1));
	p.drawLine(0, 0, width(), 0);
}

} // namespace UzOS
