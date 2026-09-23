#include "UzDesktopView.h"
#include "UzDesktopTheme.h"
#include "styles/palette.h"
#include "styles/style_widgets.h"

#include <QtGui/QPainter>

namespace UzOS {

UzDesktopView::UzDesktopView(QWidget *parent)
	: Ui::RpWidget(parent) {
	setWindowTitle("UzOS (Telegram Desktop C++ Shell)");
	resize(1180, 780);

	// 1. Taskbar
	_taskbar = new UzTaskbar(this);
	_taskbar->setStartCallback([this]() {
		toggleLauncher();
	});

	// 2. Backdrop Overlay (Telegram modal layer: covers screen behind drawer)
	_backdrop = new QWidget(this);
	_backdrop->setStyleSheet("background-color: rgba(0, 0, 0, 130);");
	_backdrop->hide();

	// 3. Telegram Hamburger Sidebar Drawer
	_launcher = new UzAppLauncher(this);
	_launcher->setAppSelectedCallback([this](const QString &appId) {
		openApp(appId);
	});
	_launcher->hide();

	// 4. Windows
	createWindows();
}

void UzDesktopView::createWindows() {
	// 1. Terminal Window
	_terminalWin = new UzWindow(this, "Terminal (Bash 5.2.21)", ":/icons/terminal.png", 580, 420);
	_terminalApp = new UzTerminal(_terminalWin->body());
	auto *termLayout = new QVBoxLayout(_terminalWin->body());
	termLayout->setContentsMargins(0, 0, 0, 0);
	termLayout->addWidget(_terminalApp);
	_terminalWin->move(60, 50);
	_taskbar->addWindowTab(_terminalWin);

	// 2. Files Window
	_filesWin = new UzWindow(this, "Fayllar (Shared Media)", ":/icons/files.png", 580, 420);
	_filesApp = new UzFiles(_filesWin->body());
	auto *filesLayout = new QVBoxLayout(_filesWin->body());
	filesLayout->setContentsMargins(0, 0, 0, 0);
	filesLayout->addWidget(_filesApp);
	_filesWin->move(480, 100);
	_taskbar->addWindowTab(_filesWin);

	// 3. Settings Window (created, but hidden by default)
	_settingsWin = new UzWindow(this, "Sozlamalar", ":/icons/settings.png", 540, 440);
	_settingsApp = new UzSettings(_settingsWin->body());
	auto *settingsLayout = new QVBoxLayout(_settingsWin->body());
	settingsLayout->setContentsMargins(0, 0, 0, 0);
	settingsLayout->addWidget(_settingsApp);
	_settingsWin->move(260, 80);
	_settingsWin->hide();

	// Show terminal and files by default
	_terminalWin->show();
	_filesWin->show();
	_terminalWin->raise();
}

void UzDesktopView::toggleLauncher() {
	if (_launcher->isHidden()) {
		const int drawerH = height() - _taskbar->height();
		_backdrop->setGeometry(0, 0, width(), drawerH);
		_backdrop->show();
		_backdrop->raise();

		_launcher->setGeometry(0, 0, 300, drawerH);
		_launcher->show();
		_launcher->raise();
		_launcher->focusSearch();
	} else {
		_launcher->hide();
		_backdrop->hide();
	}
}

void UzDesktopView::openApp(const QString &appId) {
	_launcher->hide();
	_backdrop->hide();

	if (appId == "terminal") {
		_terminalWin->show();
		_terminalWin->raise();
		_taskbar->addWindowTab(_terminalWin);
		_terminalApp->focusInput();
	} else if (appId == "files") {
		_filesWin->show();
		_filesWin->raise();
		_taskbar->addWindowTab(_filesWin);
	} else if (appId == "settings") {
		_settingsWin->show();
		_settingsWin->raise();
		_taskbar->addWindowTab(_settingsWin);
	} else if (appId == "about") {
		_terminalWin->show();
		_terminalWin->raise();
		_taskbar->addWindowTab(_terminalWin);
		_terminalApp->handleCommand("neofetch");
	} else {
		_terminalWin->show();
		_terminalWin->raise();
	}
}

void UzDesktopView::resizeEvent(QResizeEvent *e) {
	Ui::RpWidget::resizeEvent(e);

	const int tbHeight = _taskbar->height();
	_taskbar->setGeometry(0, height() - tbHeight, width(), tbHeight);

	const int drawerH = height() - tbHeight;
	if (_backdrop && !_backdrop->isHidden()) {
		_backdrop->setGeometry(0, 0, width(), drawerH);
	}
	if (_launcher && !_launcher->isHidden()) {
		_launcher->setGeometry(0, 0, 300, drawerH);
	}
}

void UzDesktopView::mousePressEvent(QMouseEvent *e) {
	if (_launcher && !_launcher->isHidden()) {
		if (!_launcher->geometry().contains(e->position().toPoint())) {
			_launcher->hide();
			_backdrop->hide();
		}
	}
	Ui::RpWidget::mousePressEvent(e);
}

void UzDesktopView::paintEvent(QPaintEvent *e) {
	QPainter p(this);
	// Pure solid official Telegram Dark Background (#0e1621)
	p.fillRect(rect(), UzTheme::kBgDark);
}

} // namespace UzOS
