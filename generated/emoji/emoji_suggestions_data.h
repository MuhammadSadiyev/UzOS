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

#include "emoji_suggestions.h"

namespace Ui {
namespace Emoji {
namespace internal {

struct Replacement {
	utf16string emoji;
	utf16string replacement;
	std::vector<utf16string> words;
};

constexpr auto kReplacementMaxLength = 55;

void InitReplacements();
const std::vector<Replacement> &GetAllReplacements();
const std::vector<const Replacement*> *GetReplacements(utf16char first);
utf16string GetReplacementEmoji(utf16string replacement);

} // namespace internal
} // namespace Emoji
} // namespace Ui
