// WARNING! All changes made in this file will be lost!
// Created from 'empty' by 'codegen_emoji'
//
// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#pragma once

#include <QtCore/QChar>
#include <QtCore/QString>
#include <QtCore/QVector>

#include <vector>

namespace Ui {
namespace Emoji {
class One;
} // namespace Emoji
} // namespace Ui

using EmojiPtr = const Ui::Emoji::One*;
using EmojiPack = QVector<EmojiPtr>;

namespace Ui {
namespace Emoji {
namespace internal {

void Init();

int FullCount();
EmojiPtr ByIndex(int index);

EmojiPtr Find(const QChar *ch, const QChar *end, int *outLength = nullptr);

const std::vector<std::pair<QString, int>> GetReplacementPairs();
EmojiPtr FindReplace(const QChar *ch, const QChar *end, int *outLength = nullptr);

} // namespace internal

constexpr auto kPostfix = static_cast<ushort>(0xFE0F);

enum class Section {
	Recent,
	People,
	Nature,
	Food,
	Activity,
	Travel,
	Objects,
	Symbols,
};

int GetSectionCount(Section section);
QVector<const One*> GetSection(Section section);

} // namespace Emoji
} // namespace Ui
