#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtCore/QString>

#include "ui/widgets/fields/input_field.h"
#include "ui/widgets/labels.h"
#include <rpl/lifetime.h>

namespace UzOS {

class UzTerminal : public QWidget {
public:
	explicit UzTerminal(QWidget *parent = nullptr);
	~UzTerminal() override = default;

	void focusInput();
	void handleCommand(const QString &command);

private:
	void printOutput(const QString &text, const QString &color = "#a0d2eb");

	QTextEdit *_outputArea = nullptr;
	Ui::InputField *_inputField = nullptr;
	rpl::lifetime _lifetime;
};

} // namespace UzOS
