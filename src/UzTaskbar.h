#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtCore/QString>
#include <QtCore/QTimer>
#include <functional>
#include <map>

#include "ui/widgets/buttons.h"
#include "ui/widgets/labels.h"

namespace UzOS {

class UzWindow;

class UzTaskbar : public QWidget {
public:
	explicit UzTaskbar(QWidget *parent = nullptr);
	~UzTaskbar() override = default;

	void setStartCallback(std::function<void()> callback) {
		_startCallback = std::move(callback);
	}

	void addWindowTab(UzWindow *window);
	void removeWindowTab(UzWindow *window);

protected:
	void paintEvent(QPaintEvent *e) override;

private:
	void updateClock();

	QWidget *_startBtn = nullptr;
	QHBoxLayout *_tabsLayout = nullptr;

	// System Tray
	QWidget *_trayWidget = nullptr;
	QLabel *_wifiLabel = nullptr;
	QLabel *_volumeLabel = nullptr;
	QLabel *_batteryLabel = nullptr;
	QWidget *_langBtn = nullptr;
	QLabel *_langLabel = nullptr;
	QLabel *_timeLabel = nullptr;
	QLabel *_dateLabel = nullptr;

	QTimer *_clockTimer = nullptr;
	int _langIndex = 0;

	std::map<UzWindow*, QWidget*> _windowButtons;
	std::function<void()> _startCallback;
};

} // namespace UzOS
