#include "UzAppLauncher.h"
#include "UzDesktopTheme.h"
#include "styles/palette.h"
#include "styles/style_widgets.h"

#include <QtWidgets/QLabel>
#include <QtGui/QPainter>
#include <QtGui/QPainterPath>
#include <QtGui/QMouseEvent>
#include <QtGui/QEnterEvent>

namespace {

const style::InputField &LauncherSearchStyle() {
	static const auto result = [] {
		auto st = st::defaultMultiSelectSearchField;
		st.textBg = st::transparent;
		st.textBgActive = st::transparent;
		st.textFg = st::white;
		st.placeholderFg = st::windowSubTextFg;
		st.placeholderFgActive = st::windowSubTextFg;
		st.border = 0;
		st.borderActive = 0;
		st.borderRadius = 0;
		return st;
	}();
	return result;
}

// Authentic Telegram Menu Row Item with smooth hover and exact metrics
class TelegramMenuRow : public QWidget {
public:
	TelegramMenuRow(
		QWidget *parent,
		const QString &id,
		const QString &name,
		const QString &desc,
		const QString &iconPath,
		std::function<void(const QString &)> clicked)
		: QWidget(parent)
		, _id(id)
		, _name(name)
		, _desc(desc)
		, _iconPath(iconPath)
		, _clicked(std::move(clicked)) {
		setFixedHeight(50);
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
			_clicked(_id);
		}
		QWidget::mousePressEvent(e);
	}

	void paintEvent(QPaintEvent *e) override {
		QPainter p(this);
		p.setRenderHint(QPainter::Antialiasing, true);
		p.setRenderHint(QPainter::SmoothPixmapTransform, true);

		// Hover background
		if (_hovered) {
			p.setPen(Qt::NoPen);
			p.setBrush(UzTheme::kHoverBg);
			p.drawRoundedRect(rect().adjusted(4, 2, -4, -2), 8, 8);
		}

		// Official Telegram Icon (24x24 px)
		const auto iconColor = _hovered ? UzTheme::kIconHoverFg : UzTheme::kIconFg;
		const auto iconPix = UzTheme::TintIcon(_iconPath, iconColor, 24);
		if (!iconPix.isNull()) {
			p.drawPixmap(16, (height() - 24) / 2, iconPix);
		}

		// Title
		p.setFont(QFont("Segoe UI", 10, QFont::DemiBold));
		p.setPen(_hovered ? Qt::white : QColor(245, 245, 245));
		p.drawText(56, 21, _name);

		// Description / Subtitle
		p.setFont(QFont("Segoe UI", 8, QFont::Normal));
		p.setPen(UzTheme::kSubTextFg);
		p.drawText(56, 38, _desc);
	}

private:
	QString _id;
	QString _name;
	QString _desc;
	QString _iconPath;
	std::function<void(const QString &)> _clicked;
	bool _hovered = false;
};

} // namespace

namespace UzOS {

UzAppLauncher::UzAppLauncher(QWidget *parent)
	: QWidget(parent) {
	setFixedWidth(300);
	setAttribute(Qt::WA_OpaquePaintEvent, false);

	auto *mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);
	mainLayout->setSpacing(0);

	// =========================================================================
	// 1. Telegram Drawer Profile Header Card (Exact Telegram Design)
	// =========================================================================
	auto *headerCard = new QWidget(this);
	headerCard->setFixedHeight(126);
	headerCard->setStyleSheet("background-color: #242f3d; border-bottom: 1px solid #1c2b38;");

	auto *headerLayout = new QVBoxLayout(headerCard);
	headerLayout->setContentsMargins(20, 16, 20, 16);
	headerLayout->setSpacing(10);

	// Avatar & Online indicator
	auto *avatarRow = new QHBoxLayout();
	auto *avatar = new QLabel(headerCard);
	avatar->setFixedSize(44, 44);
	avatar->setPixmap(UzTheme::CreateTelegramAvatar(44, "UZ"));
	avatarRow->addWidget(avatar);
	avatarRow->addStretch(1);

	auto *onlineBadge = new QLabel("● Faol tizim", headerCard);
	onlineBadge->setStyleSheet("color: #4cd964; font-size: 11px; font-weight: bold; background: transparent; border: none;");
	avatarRow->addWidget(onlineBadge);
	headerLayout->addLayout(avatarRow);

	// User info
	auto *infoLayout = new QVBoxLayout();
	infoLayout->setSpacing(2);

	auto *userName = new QLabel("UzOS Desktop", headerCard);
	userName->setStyleSheet("color: #ffffff; font-weight: bold; font-size: 14px; background: transparent; border: none;");
	infoLayout->addWidget(userName);

	auto *userSub = new QLabel("Telegram Desktop C++ Shell", headerCard);
	userSub->setStyleSheet("color: #7f91a4; font-size: 11px; background: transparent; border: none;");
	infoLayout->addWidget(userSub);

	headerLayout->addLayout(infoLayout);
	mainLayout->addWidget(headerCard);

	// =========================================================================
	// 2. Search Field Container with Telegram Search Icon
	// =========================================================================
	auto *searchRow = new QWidget(this);
	searchRow->setStyleSheet("background-color: #17212b; border-bottom: 1px solid #1c2b38;");
	auto *searchLayout = new QHBoxLayout(searchRow);
	searchLayout->setContentsMargins(12, 8, 12, 8);

	auto *searchBox = new QWidget(searchRow);
	searchBox->setFixedHeight(36);
	searchBox->setStyleSheet("background-color: #242f3d; border-radius: 8px; border: 1px solid #1c2b38;");
	auto *searchBoxLayout = new QHBoxLayout(searchBox);
	searchBoxLayout->setContentsMargins(8, 0, 8, 0);
	searchBoxLayout->setSpacing(8);

	// Search icon
	auto *searchIcon = new QLabel(searchBox);
	searchIcon->setFixedSize(18, 18);
	searchIcon->setPixmap(UzTheme::TintIcon(":/icons/search.png", UzTheme::kSubTextFg, 18));
	searchBoxLayout->addWidget(searchIcon);

	_searchField = new Ui::InputField(
		searchBox,
		LauncherSearchStyle(),
		rpl::single(QString("Qidirish..."))
	);
	_searchField->setStyleSheet("border: none; background: transparent;");
	searchBoxLayout->addWidget(_searchField, 1);

	searchLayout->addWidget(searchBox);
	mainLayout->addWidget(searchRow);

	// =========================================================================
	// 3. Telegram Menu Items List (Official Telegram Icons)
	// =========================================================================
	_scrollArea = new Ui::ScrollArea(this, st::defaultScrollArea);
	_contentWidget = new QWidget();
	_contentWidget->setStyleSheet("background-color: #17212b;");
	_listLayout = new QVBoxLayout(_contentWidget);
	_listLayout->setContentsMargins(6, 6, 6, 6);
	_listLayout->setSpacing(2);

	_apps = {
		{ "terminal", "Terminal", "Bash 5.2.21 konsoli", ":/icons/terminal.png" },
		{ "files", "Fayllar", "Shared Media fayl menejeri", ":/icons/files.png" },
		{ "settings", "Sozlamalar", "Tizim parametrlari va til", ":/icons/settings.png" },
		{ "about", "UzOS Haqida", "Telegram C++ Yadro (neofetch)", ":/icons/info.png" }
	};

	rebuildList();

	_contentWidget->setLayout(_listLayout);
	_scrollArea->setWidget(_contentWidget);
	_scrollArea->setWidgetResizable(true);
	mainLayout->addWidget(_scrollArea, 1);

	// =========================================================================
	// 4. Drawer Footer: Night Mode & Power Options with Official Icons
	// =========================================================================
	auto *footerCard = new QWidget(this);
	footerCard->setStyleSheet("background-color: #131c26; border-top: 1px solid #1c2b38;");
	auto *footerLayout = new QVBoxLayout(footerCard);
	footerLayout->setContentsMargins(14, 10, 14, 12);
	footerLayout->setSpacing(8);

	// Night Mode row: Moon icon + Text + Ui::Checkbox
	auto *nightRow = new QHBoxLayout();
	nightRow->setContentsMargins(4, 0, 4, 0);
	nightRow->setSpacing(8);

	auto *moonIcon = new QLabel(footerCard);
	moonIcon->setFixedSize(20, 20);
	moonIcon->setPixmap(UzTheme::TintIcon(":/icons/night.png", UzTheme::kIconFg, 20));
	nightRow->addWidget(moonIcon);

	auto *nightLabel = new QLabel("Tungi rejim", footerCard);
	nightLabel->setStyleSheet("color: #ffffff; font-size: 13px; font-weight: 500; background: transparent; border: none;");
	nightRow->addWidget(nightLabel, 1);

	auto *nightToggle = new Ui::Checkbox(footerCard, QString(), true, st::defaultCheckbox);
	nightRow->addWidget(nightToggle);
	footerLayout->addLayout(nightRow);

	// Separator
	auto *sep = new QWidget(footerCard);
	sep->setFixedHeight(1);
	sep->setStyleSheet("background-color: #1f2b38;");
	footerLayout->addWidget(sep);

	// Power / Shutdown row
	auto *powerRow = new QHBoxLayout();
	powerRow->setSpacing(8);

	auto *powerBtn = new Ui::RoundButton(footerCard, rpl::single(QString("O'chirish")), st::defaultLightButton);
	powerBtn->setFixedSize(128, 32);
	powerBtn->setClickedCallback([this]() {
		hide();
		if (_appSelectedCallback) {
			_appSelectedCallback("terminal");
		}
	});
	powerRow->addWidget(powerBtn);

	auto *restartBtn = new Ui::RoundButton(footerCard, rpl::single(QString("Qayta yuklash")), st::defaultLightButton);
	restartBtn->setFixedSize(128, 32);
	restartBtn->setClickedCallback([this]() {
		hide();
	});
	powerRow->addWidget(restartBtn);

	footerLayout->addLayout(powerRow);
	mainLayout->addWidget(footerCard);

	// Connect search changes
	_searchField->changes(
	) | rpl::on_next([this]() {
		rebuildList(_searchField->getTextWithTags().text.trimmed());
	}, _lifetime);
}

void UzAppLauncher::focusSearch() {
	if (_searchField) {
		_searchField->setFocus();
	}
}

void UzAppLauncher::rebuildList(const QString &query) {
	// Clear items
	QLayoutItem *child;
	while ((child = _listLayout->takeAt(0)) != nullptr) {
		delete child->widget();
		delete child;
	}

	for (const auto &app : _apps) {
		if (!query.isEmpty() && !app.name.contains(query, Qt::CaseInsensitive) && !app.desc.contains(query, Qt::CaseInsensitive)) {
			continue;
		}

		auto *itemRow = new TelegramMenuRow(
			_contentWidget,
			app.id,
			app.name,
			app.desc,
			app.iconPath,
			[this](const QString &appId) {
				hide();
				if (_appSelectedCallback) {
					_appSelectedCallback(appId);
				}
			}
		);

		_listLayout->addWidget(itemRow);
	}

	_listLayout->addStretch(1);
}

void UzAppLauncher::paintEvent(QPaintEvent *e) {
	QPainter p(this);
	p.fillRect(rect(), UzTheme::kSidebarBg);

	// Drop shadow / edge divider on right border
	p.setPen(QPen(QColor(0, 0, 0, 60), 2));
	p.drawLine(width() - 1, 0, width() - 1, height());
}

} // namespace UzOS
