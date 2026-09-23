#include <QtWidgets/QApplication>
#include <QtCore/QTimer>
#include <QtCore/QDebug>
#include <QtGui/QPixmap>

// Official Telegram style engine
#include "ui/style/style_core.h"
#include "styles/palette.h"
#include "styles/style_basic.h"
#include "styles/style_widgets.h"

// Official Telegram widgets
#include "ui/rp_widget.h"
#include "ui/effects/animations.h"
#include "emoji.h"

// Integration
#include "UiIntegration.h"

// UzOS Desktop Shell
#include "UzDesktopView.h"

// Resources
extern void qInitResources_fonts();
extern void qInitResources_win();

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	app.setApplicationName("UzOS");
	app.setApplicationDisplayName("UzOS (Telegram Desktop Core)");

	// Initialize embedded Telegram resources (Open Sans fonts, Qt configs)
	qInitResources_fonts();
	qInitResources_win();

	// Initialize Ui::Integration
	UzOS::UiIntegration integration;
	Ui::Integration::Set(&integration);

	// Initialize Telegram Emoji system
	Ui::Emoji::internal::Init();

	// Initialize Telegram Animation Manager
	auto animationManager = std::make_unique<Ui::Animations::Manager>();

	// Start Telegram Desktop Official Style Engine at 100% scale
	style::StartManager(100);

	// Create UzOS Desktop Workspace
	auto desktop = std::make_unique<UzOS::UzDesktopView>();
	desktop->show();

	// Screenshot grabber for automated testing or review
	auto *rawDesktop = desktop.get();
	const bool autoExit = app.arguments().contains("--screenshot-and-exit");
	if (autoExit) {
		QTimer::singleShot(1500, [rawDesktop]() {
			QPixmap pixmap = rawDesktop->grab();
			const QString path = "C:/Users/muhan/.gemini/antigravity-ide/brain/d90aa326-a38e-4ad6-8bf8-f5a0fa73b518/uzos_desktop_running.png";
			pixmap.save(path, "PNG");
			qDebug() << "Desktop screenshot saved to" << path;

			// Open Telegram Hamburger Sidebar Drawer
			rawDesktop->toggleLauncher();
			QTimer::singleShot(800, [rawDesktop]() {
				QPixmap pixmap2 = rawDesktop->grab();
				const QString path2 = "C:/Users/muhan/.gemini/antigravity-ide/brain/d90aa326-a38e-4ad6-8bf8-f5a0fa73b518/uzos_sidebar_running.png";
				pixmap2.save(path2, "PNG");
				qDebug() << "Sidebar drawer screenshot saved to" << path2;
				QApplication::quit();
			});
		});
	}

	const auto result = app.exec();

	// Cleanup Telegram Style Engine
	style::StopManager();

	return result;
}
