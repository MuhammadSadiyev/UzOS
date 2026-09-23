#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QString>
#include <functional>
#include <vector>

#include "ui/widgets/fields/input_field.h"
#include "ui/widgets/scroll_area.h"
#include "ui/widgets/labels.h"
#include "ui/widgets/buttons.h"
#include "ui/widgets/checkbox.h"
#include <rpl/lifetime.h>

namespace UzOS {

struct AppEntry {
	QString id;
	QString name;
	QString desc;
	QString iconPath;
};

class UzAppLauncher : public QWidget {
public:
	explicit UzAppLauncher(QWidget *parent = nullptr);
	~UzAppLauncher() override = default;

	void setAppSelectedCallback(std::function<void(const QString &appId)> callback) {
		_appSelectedCallback = std::move(callback);
	}

	void focusSearch();

protected:
	void paintEvent(QPaintEvent *e) override;

private:
	void rebuildList(const QString &query = QString());

	Ui::InputField *_searchField = nullptr;
	Ui::ScrollArea *_scrollArea = nullptr;
	QWidget *_contentWidget = nullptr;
	QVBoxLayout *_listLayout = nullptr;

	std::vector<AppEntry> _apps;
	std::function<void(const QString &appId)> _appSelectedCallback;
	rpl::lifetime _lifetime;
};

} // namespace UzOS
