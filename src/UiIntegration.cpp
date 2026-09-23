#include "UiIntegration.h"
#include <QtCore/QCoreApplication>
#include <QtCore/QDir>
#include <crl/crl_on_main.h>

namespace UzOS {

UiIntegration::UiIntegration() {
	_baseDir = QCoreApplication::applicationDirPath() + "/tdata";
	QDir().mkpath(_baseDir + "/emoji");
	QDir().mkpath(_baseDir + "/fonts");
}

void UiIntegration::postponeCall(FnMut<void()> &&callable) {
	QMetaObject::invokeMethod(QCoreApplication::instance(), [c = std::move(callable)]() mutable {
		c();
	}, Qt::QueuedConnection);
}

void UiIntegration::registerLeaveSubscription(not_null<QWidget*> widget) {
}

void UiIntegration::unregisterLeaveSubscription(not_null<QWidget*> widget) {
}

QString UiIntegration::emojiCacheFolder() {
	return _baseDir + "/emoji";
}

QString UiIntegration::fontsCacheFolder() {
	return _baseDir + "/fonts";
}

QString UiIntegration::openglCheckFilePath() {
	return _baseDir + "/opengl";
}

QString UiIntegration::angleBackendFilePath() {
	return _baseDir + "/angle";
}

void UiIntegration::touchCounterIncrement() {
	++_touchCounter;
}

int UiIntegration::touchCounterNow() {
	return _touchCounter;
}

} // namespace UzOS
