#pragma once

#include "ui/integration.h"
#include <QtCore/QDir>
#include <QtCore/QStandardPaths>
#include <QtCore/QTimer>

namespace UzOS {

class UiIntegration final : public Ui::Integration {
public:
	UiIntegration();

	void postponeCall(FnMut<void()> &&callable) override;
	void registerLeaveSubscription(not_null<QWidget*> widget) override;
	void unregisterLeaveSubscription(not_null<QWidget*> widget) override;

	QString emojiCacheFolder() override;
	QString fontsCacheFolder() override;
	QString openglCheckFilePath() override;
	QString angleBackendFilePath() override;

	void touchCounterIncrement() override;
	int touchCounterNow() override;

private:
	int _touchCounter = 0;
	QString _baseDir;
};

} // namespace UzOS
