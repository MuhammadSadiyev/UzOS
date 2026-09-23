#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QMouseEvent>
#include <QtCore/QString>
#include <functional>

#include "ui/rp_widget.h"
#include "ui/widgets/labels.h"

namespace UzOS {

class UzWindow : public QWidget {
public:
	UzWindow(QWidget *parent, const QString &title, const QString &iconPath = ":/icons/terminal.png", int initialWidth = 560, int initialHeight = 400);
	~UzWindow() override = default;

	[[nodiscard]] QWidget *body() const { return _body; }
	[[nodiscard]] QString title() const { return _title; }
	[[nodiscard]] QString iconPath() const { return _iconPath; }

	void setCloseCallback(std::function<void()> callback) { _closeCallback = std::move(callback); }
	void setMinimizeCallback(std::function<void()> callback) { _minimizeCallback = std::move(callback); }

protected:
	bool eventFilter(QObject *watched, QEvent *event) override;
	void mousePressEvent(QMouseEvent *e) override;
	void mouseMoveEvent(QMouseEvent *e) override;
	void mouseReleaseEvent(QMouseEvent *e) override;
	void paintEvent(QPaintEvent *e) override;

private:
	QString _title;
	QString _iconPath;
	QWidget *_titleBar = nullptr;
	Ui::FlatLabel *_titleLabel = nullptr;
	QWidget *_minimizeBtn = nullptr;
	QWidget *_closeBtn = nullptr;
	QWidget *_body = nullptr;

	bool _dragging = false;
	QPoint _dragStart;

	std::function<void()> _closeCallback;
	std::function<void()> _minimizeCallback;
};

} // namespace UzOS
