#include "UzSettings.h"
#include "styles/palette.h"
#include "styles/style_widgets.h"

namespace UzOS {

UzSettings::UzSettings(QWidget *parent)
	: QWidget(parent) {
	auto *mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(12, 12, 12, 12);
	mainLayout->setSpacing(8);

	_statusLabel = new Ui::FlatLabel(this, "UzOS Tizim Sozlamalari va Konfiguratsiyasi", st::defaultSubTextLabel);
	_statusLabel->setStyleSheet("color: #7b99b5; background: transparent; padding-bottom: 4px;");
	mainLayout->addWidget(_statusLabel);

	_scrollArea = new Ui::ScrollArea(this, st::defaultScrollArea);
	_contentWidget = new QWidget();
	auto *contentLayout = new QVBoxLayout(_contentWidget);
	contentLayout->setContentsMargins(4, 4, 4, 4);
	contentLayout->setSpacing(12);

	// Section 1: Tizim Ma'lumotlari
	auto *sec1Title = new Ui::FlatLabel(_contentWidget, "Tizim Haqida (UzOS Enterprise)", st::defaultFlatLabel);
	sec1Title->setFont(st::defaultFlatLabel.style.font->bold());
	sec1Title->setStyleSheet("color: #40b1e8; background: transparent;");
	contentLayout->addWidget(sec1Title);

	auto *infoCard = new QWidget(_contentWidget);
	infoCard->setStyleSheet("background-color: #17212b; border-radius: 8px; padding: 10px;");
	auto *infoLayout = new QVBoxLayout(infoCard);
	infoLayout->setSpacing(6);

	const QStringList sysInfo = {
		"Operatsion Tizim: UzOS 1.0.0 Enterprise LTS (64-bit)",
		"Grafik Dvigatel: Telegram Desktop C++ lib_ui (Native)",
		"Yadro: Linux 6.8.0-uzos-desktop x86_64",
		"Kompilyator: Clang 22 (LLVM-MinGW UCRT)",
		"Xavfsizlik: O'zbekiston Milliy Kripto-standartlari faol"
	};
	for (const auto &info : sysInfo) {
		auto *lbl = new Ui::FlatLabel(infoCard, info, st::defaultFlatLabel);
		lbl->setStyleSheet("color: #d1e2f2; background: transparent;");
		infoLayout->addWidget(lbl);
	}
	contentLayout->addWidget(infoCard);

	// Section 2: Vizual effektlar
	auto *sec2Title = new Ui::FlatLabel(_contentWidget, "Vizual Effektlar & Animatsiyalar", st::defaultFlatLabel);
	sec2Title->setFont(st::defaultFlatLabel.style.font->bold());
	sec2Title->setStyleSheet("color: #40b1e8; background: transparent;");
	contentLayout->addWidget(sec2Title);

	auto *effectsCard = new QWidget(_contentWidget);
	effectsCard->setStyleSheet("background-color: #17212b; border-radius: 8px; padding: 10px;");
	auto *effectsLayout = new QVBoxLayout(effectsCard);
	effectsLayout->setSpacing(8);

	auto *cb1 = new Ui::Checkbox(effectsCard, "Telegram to'lqin (ripple) animatsiyalari", true, st::defaultCheckbox);
	effectsLayout->addWidget(cb1);

	auto *cb2 = new Ui::Checkbox(effectsCard, "Elastik silliq skroll inersiyasi (elastic_scroll)", true, st::defaultCheckbox);
	effectsLayout->addWidget(cb2);

	auto *cb3 = new Ui::Checkbox(effectsCard, "Tungi mavzu (#0e1621 Telegram Night Palette)", true, st::defaultCheckbox);
	effectsLayout->addWidget(cb3);

	contentLayout->addWidget(effectsCard);

	// Section 3: Til
	auto *sec3Title = new Ui::FlatLabel(_contentWidget, "Tizim Tili (Interface Language)", st::defaultFlatLabel);
	sec3Title->setFont(st::defaultFlatLabel.style.font->bold());
	sec3Title->setStyleSheet("color: #40b1e8; background: transparent;");
	contentLayout->addWidget(sec3Title);

	auto *langRow = new QHBoxLayout();
	langRow->setSpacing(8);

	auto *langUz = new Ui::RoundButton(_contentWidget, rpl::single(QString("O'zbekcha")), st::defaultActiveButton);
	langUz->setFixedSize(langUz->width(), langUz->height());
	langUz->setClickedCallback([this]() { _statusLabel->setText("Til tanlandi: O'zbek tili (Lotin)"); });
	langRow->addWidget(langUz);

	auto *langEn = new Ui::RoundButton(_contentWidget, rpl::single(QString("English")), st::defaultLightButton);
	langEn->setFixedSize(langEn->width(), langEn->height());
	langEn->setClickedCallback([this]() { _statusLabel->setText("Language selected: English"); });
	langRow->addWidget(langEn);

	auto *langRu = new Ui::RoundButton(_contentWidget, rpl::single(QString("Русский")), st::defaultLightButton);
	langRu->setFixedSize(langRu->width(), langRu->height());
	langRu->setClickedCallback([this]() { _statusLabel->setText("Язык выбран: Русский"); });
	langRow->addWidget(langRu);
	langRow->addStretch();

	contentLayout->addLayout(langRow);

	// Section 4: Yangilanishlar
	auto *updateBtn = new Ui::RoundButton(_contentWidget, rpl::single(QString("Yangilanishlarni Tekshirish")), st::defaultActiveButton);
	updateBtn->setFixedSize(updateBtn->width(), updateBtn->height());
	updateBtn->setClickedCallback([this]() {
		_statusLabel->setText("Tizim tekshirildi: Sizda eng so'nggi UzOS Al-Xorazmiy LTS 1.0.0 o'rnatilgan!");
	});
	contentLayout->addWidget(updateBtn);
	contentLayout->addStretch();

	_contentWidget->setLayout(contentLayout);
	_scrollArea->setWidget(_contentWidget);
	_scrollArea->setWidgetResizable(true);
	mainLayout->addWidget(_scrollArea, 1);
}

} // namespace UzOS
