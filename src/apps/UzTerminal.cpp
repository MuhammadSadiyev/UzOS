#include "UzTerminal.h"
#include "styles/palette.h"
#include "styles/style_widgets.h"

#include <QtCore/QDateTime>
#include <QtGui/QFontDatabase>
#include <QtWidgets/QLabel>

namespace {

const style::InputField &TerminalInputStyle() {
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
		st.borderFg = st::transparent;
		st.borderFgActive = st::transparent;
		return st;
	}();
	return result;
}

} // namespace

namespace UzOS {

UzTerminal::UzTerminal(QWidget *parent)
	: QWidget(parent) {
	auto *layout = new QVBoxLayout(this);
	layout->setContentsMargins(8, 8, 8, 8);
	layout->setSpacing(6);

	// Output Area
	_outputArea = new QTextEdit(this);
	_outputArea->setReadOnly(true);
	_outputArea->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
	_outputArea->setStyleSheet(
		"QTextEdit { background-color: #0b1016; color: #40b1e8; border: 1px solid #1c2b38; border-radius: 6px; padding: 6px; font-size: 13px; }"
		"QScrollBar:vertical { background: #0b1016; width: 6px; }"
		"QScrollBar::handle:vertical { background: #2b5278; border-radius: 3px; }"
	);
	layout->addWidget(_outputArea, 1);

	// Input row container
	auto *inputRow = new QWidget(this);
	inputRow->setObjectName("terminalInputRow");
	inputRow->setFixedHeight(44);
	inputRow->setStyleSheet("#terminalInputRow { background-color: #111a24; border-radius: 6px; border: 1px solid #1c2b38; }");
	auto *inputRowLayout = new QHBoxLayout(inputRow);
	inputRowLayout->setContentsMargins(10, 2, 8, 2);
	inputRowLayout->setSpacing(8);

	auto *prompt = new QLabel("uzos@desktop:~$", inputRow);
	prompt->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
	prompt->setStyleSheet("color: #52bf5e; font-weight: bold; background: transparent; border: none; font-size: 13px;");
	inputRowLayout->addWidget(prompt);

	_inputField = new Ui::InputField(
		inputRow,
		TerminalInputStyle(),
		rpl::single(QString("buyruq kiriting (help, neofetch, ls)..."))
	);
	_inputField->setStyleSheet("border: none; background: transparent;");
	_inputField->setPlaceholderColorOverride(st::windowSubTextFg);
	inputRowLayout->addWidget(_inputField, 1);
	layout->addWidget(inputRow);

	// Connect Enter key
	_inputField->submits(
	) | rpl::on_next([this](Qt::KeyboardModifiers) {
		const auto cmd = _inputField->getTextWithTags().text.trimmed();
		_inputField->clear();
		handleCommand(cmd);
	}, _lifetime);

	// Print welcome header
	printOutput("====================================================", "#52bf5e");
	printOutput(" UzOS Desktop (Telegram Desktop Core)               ", "#ffffff");
	printOutput(" Rasmiy C++ Yadro & Telegram lib_ui Shell faol      ", "#40b1e8");
	printOutput(" Yordam uchun 'help' deb yozing.                    ", "#b3c3d1");
	printOutput("====================================================", "#52bf5e");
}

void UzTerminal::focusInput() {
	if (_inputField) {
		_inputField->setFocus();
	}
}

void UzTerminal::printOutput(const QString &text, const QString &color) {
	_outputArea->append(QString("<span style='color:%1;'>%2</span>").arg(color, text.toHtmlEscaped()));
	auto cursor = _outputArea->textCursor();
	cursor.movePosition(QTextCursor::End);
	_outputArea->setTextCursor(cursor);
}

void UzTerminal::handleCommand(const QString &command) {
	if (command.isEmpty()) {
		return;
	}

	printOutput("uzos@desktop:~$ " + command, "#ffffff");

	const auto lower = command.toLower();
	if (lower == "help") {
		printOutput("Mavjud UzOS buyruqlari:", "#40b1e8");
		printOutput("  neofetch   - Tizim spetsifikatsiyalari va O'zbekiston bayrog'i", "#ffffff");
		printOutput("  uname -a   - UzOS yadro (kernel) ma'lumoti", "#ffffff");
		printOutput("  free -m    - Xotira (RAM/Swap) holati", "#ffffff");
		printOutput("  ls         - Tizim kataloglari ro'yxati", "#ffffff");
		printOutput("  date       - Hozirgi sana va vaqt", "#ffffff");
		printOutput("  whoami     - Joriy foydalanuvchi huquqi", "#ffffff");
		printOutput("  clear      - Konsol ekranini tozalash", "#ffffff");
	} else if (lower == "neofetch") {
		printOutput("         .,:---...         OS: UzOS (x86_64)", "#40b1e8");
		printOutput("     :==============:      Host: UzOS Desktop Shell (Telegram lib_ui)", "#40b1e8");
		printOutput("    .----------------.     Kernel: Linux 6.8.0-uzos", "#ffffff");
		printOutput("    ==================     Uptime: 24 soat, 18 daqiqa", "#ffffff");
		printOutput("    ------------------     Packages: 1420 (dpkg), 1 (flatpak)", "#e85454");
		printOutput("     :==============:      Shell: UzBash 5.2.21", "#52bf5e");
		printOutput("         `':::---'         UI: Telegram Desktop lib_ui C++ (Native)", "#52bf5e");
		printOutput("                           Compiler: Clang 22 (LLVM-MinGW UCRT)", "#52bf5e");
		printOutput("                           RAM: 112 MB / 16384 MB (Super Fast!)", "#52bf5e");
	} else if (lower == "uname -a") {
		printOutput("Linux uzos-desktop 6.8.0-31-generic #31-UzOS SMP PREEMPT_DYNAMIC x86_64 GNU/Linux", "#a0d2eb");
	} else if (lower == "clear") {
		_outputArea->clear();
	} else if (lower == "date") {
		printOutput(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss tzone: UTC+5"), "#a0d2eb");
	} else if (lower == "whoami") {
		printOutput("uzos-admin (Mustaqil O'zbekiston Milliy Foydalanuvchisi)", "#52bf5e");
	} else if (lower == "free -m") {
		printOutput("               total        used        free      shared  buff/cache   available", "#b3c3d1");
		printOutput("Mem:           16384         112       15200          14        1072       15820", "#52bf5e");
		printOutput("Swap:           4096           0        4096", "#b3c3d1");
	} else if (lower == "ls") {
		printOutput("bin/   boot/  dev/   etc/   home/  lib/   opt/   proc/  root/  sys/   tmp/   usr/   var/   uzos_core/", "#40b1e8");
	} else {
		printOutput(QString("bash: %1: buyruq topilmadi. 'help' buyrug'ini kiritib ko'ring.").arg(command), "#e85454");
	}
}

} // namespace UzOS
