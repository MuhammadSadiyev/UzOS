#include "UzWindow.h"
#include "UzDesktopTheme.h"
#include "styles/palette.h"
#include "styles/style_basic.h"
#include "styles/style_widgets.h"

#include <QtWidgets/QLabel>
#include <QtGui/QPainter>
#include <QtGui/QPainterPath>
#include <QtGui/QMouseEvent>
#include <QtGui/QEnterEvent>

namespace {

// Official Telegram Desktop Window Control Button (Close / Minimize)
class TelegramTitleButton : public QWidget {
public:
	TelegramTitleButton(
		QWidget *parent,
		const QString &iconPath,
		bool isClose,
		std::function<void()> clicked)
		: QWidget(parent)
		, _iconPath(iconPath)
		, _isClose(isClose)
		, _clicked(std::move(clicked)) {
		setFixedSize(32, 32);
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

		if (_hovered) {
			p.setPen(Qt::NoPen);
			if (_isClose) {
				p.setBrush(QColor(0xe5, 0x39, 0x35)); // Telegram soft red on close hover
			} else {
				p.setBrush(UzTheme::kHoverBg);
			}
			p.drawRoundedRect(rect().adjusted(2, 2, -2, -2), 6, 6);
		}

		const auto iconColor = _hovered ? Qt::white : UzTheme::kIconFg;
		const auto iconPix = UzTheme::TintIcon(_iconPath, iconColor, 18);
		if (!iconPix.isNull()) {
			p.drawPixmap((width() - 18) / 2, (height() - 18) / 2, iconPix);
		}
	}

private:
	QString _iconPath;
	bool _isClose = false;
	std::function<void()> _clicked;
	bool _hovered = false;
};

} // namespace

namespace UzOS {

UzWindow::UzWindow(QWidget *parent, const QString &title, const QString &iconPath, int initialWidth, int initialHeight)
	: QWidget(parent)
	, _title(title)
	, _iconPath(iconPath) {
	resize(initialWidth, initialHeight);
	setAttribute(Qt::WA_OpaquePaintEvent, false);

	auto *mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(1, 1, 1, 1);
	mainLayout->setSpacing(0);

	// Titlebar
	_titleBar = new QWidget(this);
	_titleBar->setFixedHeight(40);
	_titleBar->setStyleSheet("background-color: #17212b; border-top-left-radius: 10px; border-top-right-radius: 10px;");

	auto *titleLayout = new QHBoxLayout(_titleBar);
	titleLayout->setContentsMargins(12, 0, 8, 0);
	titleLayout->setSpacing(8);

	// Window Icon
	auto *iconLabel = new QLabel(_titleBar);
	iconLabel->setFixedSize(18, 18);
	iconLabel->setPixmap(UzTheme::TintIcon(_iconPath, UzTheme::kTelegramBlue, 18));
	iconLabel->setStyleSheet("background: transparent; border: none;");
	titleLayout->addWidget(iconLabel);
	iconLabel->installEventFilter(this);

	_titleLabel = new Ui::FlatLabel(_titleBar, _title, st::defaultFlatLabel);
	_titleLabel->setFont(st::defaultFlatLabel.style.font->bold());
	_titleLabel->setTextColorOverride(QColor(255, 255, 255));
	titleLayout->addWidget(_titleLabel, 1);

	_titleBar->installEventFilter(this);
	_titleLabel->installEventFilter(this);

	// Minimize button with official Telegram minimize icon
	_minimizeBtn = new TelegramTitleButton(_titleBar, ":/icons/win_min.png", false, [this]() {
		if (_minimizeCallback) {
			_minimizeCallback();
		} else {
			hide();
		}
	});
	titleLayout->addWidget(_minimizeBtn);

	// Close button with official Telegram close icon
	_closeBtn = new TelegramTitleButton(_titleBar, ":/icons/win_close.png", true, [this]() {
		if (_closeCallback) {
			_closeCallback();
		} else {
			hide();
		}
	});
	titleLayout->addWidget(_closeBtn);

	mainLayout->addWidget(_titleBar);

	// Body container
	_body = new QWidget(this);
	_body->setStyleSheet("background-color: #0e1621; border-bottom-left-radius: 10px; border-bottom-right-radius: 10px;");
	mainLayout->addWidget(_body, 1);
}

bool UzWindow::eventFilter(QObject *watched, QEvent *event) {
	if (watched == _titleBar || watched == _titleLabel) {
		if (event->type() == QEvent::MouseButtonPress) {
			auto *e = static_cast<QMouseEvent*>(event);
			if (e->button() == Qt::LeftButton) {
				raise();
				_dragging = true;
				_dragStart = e->globalPosition().toPoint() - frameGeometry().topLeft();
				return true;
			}
		} else if (event->type() == QEvent::MouseMove) {
			auto *e = static_cast<QMouseEvent*>(event);
			if (_dragging && (e->buttons() & Qt::LeftButton)) {
				move(e->globalPosition().toPoint() - _dragStart);
				return true;
			}
		} else if (event->type() == QEvent::MouseButtonRelease) {
			_dragging = false;
			return true;
		}
	}
	return QWidget::eventFilter(watched, event);
}

void UzWindow::mousePressEvent(QMouseEvent *e) {
	if (e->button() == Qt::LeftButton) {
		raise();
		if (e->position().toPoint().y() <= _titleBar->height()) {
			_dragging = true;
			_dragStart = e->globalPosition().toPoint() - frameGeometry().topLeft();
		}
	}
	QWidget::mousePressEvent(e);
}

void UzWindow::mouseMoveEvent(QMouseEvent *e) {
	if (_dragging && (e->buttons() & Qt::LeftButton)) {
		move(e->globalPosition().toPoint() - _dragStart);
	}
	QWidget::mouseMoveEvent(e);
}

void UzWindow::mouseReleaseEvent(QMouseEvent *e) {
	_dragging = false;
	QWidget::mouseReleaseEvent(e);
}

void UzWindow::paintEvent(QPaintEvent *e) {
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);

	// Outer border frame
	QPainterPath path;
	path.addRoundedRect(rect().adjusted(0, 0, -1, -1), 10, 10);
	p.setPen(QPen(QColor(0x2b, 0x52, 0x78), 1));
	p.drawPath(path);
}

} // namespace UzOS
