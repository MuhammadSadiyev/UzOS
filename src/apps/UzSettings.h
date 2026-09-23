#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>

#include "ui/widgets/scroll_area.h"
#include "ui/widgets/labels.h"
#include "ui/widgets/buttons.h"
#include "ui/widgets/checkbox.h"

namespace UzOS {

class UzSettings : public QWidget {
public:
	explicit UzSettings(QWidget *parent = nullptr);
	~UzSettings() override = default;

private:
	Ui::ScrollArea *_scrollArea = nullptr;
	QWidget *_contentWidget = nullptr;
	Ui::FlatLabel *_statusLabel = nullptr;
};

} // namespace UzOS
