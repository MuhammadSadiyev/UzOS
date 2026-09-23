#pragma once

#include <QtWidgets/QWidget>
#include <QtCore/QString>
#include <QtGui/QResizeEvent>
#include <QtGui/QMouseEvent>

#include "ui/rp_widget.h"
#include "UzWindow.h"
#include "UzTaskbar.h"
#include "UzAppLauncher.h"
#include "apps/UzTerminal.h"
#include "apps/UzFiles.h"
#include "apps/UzSettings.h"

namespace UzOS {

class UzDesktopView : public Ui::RpWidget {
public:
	explicit UzDesktopView(QWidget *parent = nullptr);
	~UzDesktopView() override = default;

	void openApp(const QString &appId);
	void toggleLauncher();

protected:
	void resizeEvent(QResizeEvent *e) override;
	void mousePressEvent(QMouseEvent *e) override;
	void paintEvent(QPaintEvent *e) override;

private:
	void createWindows();

	UzTaskbar *_taskbar = nullptr;
	QWidget *_backdrop = nullptr;
	UzAppLauncher *_launcher = nullptr;

	UzWindow *_terminalWin = nullptr;
	UzTerminal *_terminalApp = nullptr;

	UzWindow *_filesWin = nullptr;
	UzFiles *_filesApp = nullptr;

	UzWindow *_settingsWin = nullptr;
	UzSettings *_settingsApp = nullptr;
};

} // namespace UzOS
