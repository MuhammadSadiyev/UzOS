#include "UzFiles.h"
#include "styles/palette.h"
#include "styles/style_widgets.h"
#include <QtWidgets/QLabel>

namespace UzOS {

UzFiles::UzFiles(QWidget *parent)
	: QWidget(parent) {
	auto *mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(10, 10, 10, 10);
	mainLayout->setSpacing(8);

	// Tabs row
	auto *tabsLayout = new QHBoxLayout();
	tabsLayout->setSpacing(8);

	const QStringList categories = { "Barchasi", "Hujjatlar", "Dasturlar", "Rasmlar" };
	for (const auto &cat : categories) {
		auto *btn = new Ui::RoundButton(this, rpl::single(cat), (cat == "Barchasi") ? st::defaultActiveButton : st::defaultLightButton);
		btn->setFixedSize(btn->width(), btn->height());
		btn->setClickedCallback([this, cat]() {
			filterFiles(cat);
		});
		tabsLayout->addWidget(btn);
	}
	tabsLayout->addStretch();
	mainLayout->addLayout(tabsLayout);

	// Status line
	_statusLabel = new Ui::FlatLabel(this, "UzOS /home/uzos/SharedMedia katalogi", st::defaultSubTextLabel);
	_statusLabel->setStyleSheet("color: #7b99b5; background: transparent; padding-left: 4px;");
	mainLayout->addWidget(_statusLabel);

	// Scroll area
	_scrollArea = new Ui::ScrollArea(this, st::defaultScrollArea);
	_contentWidget = new QWidget();
	_itemsLayout = new QVBoxLayout(_contentWidget);
	_itemsLayout->setContentsMargins(4, 4, 4, 4);
	_itemsLayout->setSpacing(6);

	_allFiles = {
		{ "UzOS_Enterprise_LTS.iso", "ISO", "2.4 GB", "23.09.2026", "#e85454" },
		{ "O'zbekiston_Davlat_Standartlari.pdf", "PDF", "3.8 MB", "22.09.2026", "#d9534f" },
		{ "Telegram_Desktop_lib_ui.cpp", "CPP", "184 KB", "23.09.2026", "#337ab7" },
		{ "Milliy_Yadro_Konfiguratsiyasi.conf", "CONF", "42 KB", "20.09.2026", "#5cb85c" },
		{ "Uzbekistan_National_Flag_4K.png", "PNG", "4.1 MB", "18.09.2026", "#5bc0de" },
		{ "UzOS_Algoritmlar.docx", "DOC", "1.2 MB", "15.09.2026", "#337ab7" },
		{ "UzOS_Xavfsizlik_Sertifikati.crt", "CRT", "8 KB", "10.09.2026", "#f0ad4e" },
		{ "Wayland_KWin_Display_Server.tar.gz", "TAR", "48 MB", "08.09.2026", "#8a6d3b" }
	};

	buildFileList();

	_contentWidget->setLayout(_itemsLayout);
	_scrollArea->setWidget(_contentWidget);
	_scrollArea->setWidgetResizable(true);
	mainLayout->addWidget(_scrollArea, 1);
}

void UzFiles::buildFileList() {
	// Clear existing items
	QLayoutItem *child;
	while ((child = _itemsLayout->takeAt(0)) != nullptr) {
		delete child->widget();
		delete child;
	}

	for (const auto &file : _allFiles) {
		auto *card = new QWidget(_contentWidget);
		card->setStyleSheet("background-color: #17212b; border-radius: 8px; padding: 6px;");

		auto *cardLayout = new QHBoxLayout(card);
		cardLayout->setContentsMargins(10, 6, 10, 6);
		cardLayout->setSpacing(12);

		// Icon badge
		auto *badge = new QLabel(file.ext, card);
		badge->setFixedSize(40, 40);
		badge->setAlignment(Qt::AlignCenter);
		badge->setStyleSheet(QString("background-color: %1; color: #ffffff; font-weight: bold; border-radius: 6px; font-size: 11px;").arg(file.badgeColor));
		cardLayout->addWidget(badge);

		// Name & Details
		auto *infoLayout = new QVBoxLayout();
		infoLayout->setSpacing(2);

		auto *nameLabel = new Ui::FlatLabel(card, file.name, st::defaultFlatLabel);
		nameLabel->setFont(st::defaultFlatLabel.style.font->bold());
		nameLabel->setTextColorOverride(QColor(255, 255, 255));
		infoLayout->addWidget(nameLabel);

		auto *detailLabel = new Ui::FlatLabel(card, QString("%1  •  %2").arg(file.size, file.date), st::defaultSubTextLabel);
		detailLabel->setTextColorOverride(QColor("#7b99b5"));
		infoLayout->addWidget(detailLabel);

		cardLayout->addLayout(infoLayout, 1);

		// Open Button
		auto *openBtn = new Ui::RoundButton(card, rpl::single(QString("Ochish")), st::defaultLightButton);
		openBtn->setFixedSize(openBtn->width(), openBtn->height());
		const auto filename = file.name;
		openBtn->setClickedCallback([this, filename]() {
			_statusLabel->setText("Fayl ochilmoqda: " + filename);
		});
		cardLayout->addWidget(openBtn);

		_itemsLayout->addWidget(card);
	}
	_itemsLayout->addStretch();
}

void UzFiles::filterFiles(const QString &category) {
	_statusLabel->setText(QString("Kategoriya tanlandi: %1 (Jami: %2 ta fayl)").arg(category).arg(_allFiles.size()));
}

} // namespace UzOS
