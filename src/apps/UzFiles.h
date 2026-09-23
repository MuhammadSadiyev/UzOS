#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QString>
#include <vector>

#include "ui/widgets/scroll_area.h"
#include "ui/widgets/labels.h"
#include "ui/widgets/buttons.h"

namespace UzOS {

struct FileItemData {
	QString name;
	QString ext;
	QString size;
	QString date;
	QString badgeColor;
};

class UzFiles : public QWidget {
public:
	explicit UzFiles(QWidget *parent = nullptr);
	~UzFiles() override = default;

private:
	void buildFileList();
	void filterFiles(const QString &category);

	Ui::ScrollArea *_scrollArea = nullptr;
	QWidget *_contentWidget = nullptr;
	QVBoxLayout *_itemsLayout = nullptr;
	Ui::FlatLabel *_statusLabel = nullptr;
	std::vector<FileItemData> _allFiles;
};

} // namespace UzOS
