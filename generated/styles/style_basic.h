// WARNING! All changes made in this file will be lost!
// Created from 'basic.style' by 'codegen_style'
//
// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#pragma once

#include "ui/style/style_core.h"

namespace style {
namespace internal {

void init_style_basic(int scale);

} // namespace internal

struct TextPalette {
	style::color linkFg;
	style::color monoFg;
	style::color markBg;
	style::color spoilerFg;
	style::color selectBg;
	style::color selectFg;
	style::color selectLinkFg;
	style::color selectMonoFg;
	style::color selectSpoilerFg;
	style::color selectOverlay;
	bool linkAlwaysActive;
};

struct QuoteStyle {
	style::margins padding;
	int verticalSkip;
	int header;
	style::point headerPosition;
	style::icon icon;
	style::point iconPosition;
	style::icon expand;
	style::point expandPosition;
	style::icon collapse;
	style::point collapsePosition;
	int outline;
	int outlineShift;
	int radius;
	bool scrollable;
};

struct TextStyle {
	style::font font;
	int linkUnderline;
	int lineHeight;
	bool qtextEditLineMetrics;
	style::QuoteStyle blockquote;
	style::QuoteStyle pre;
};

struct IconEmoji {
	style::icon icon;
	style::margins padding;
	bool useIconColor;
};

} // namespace style

namespace st {
constexpr int kLinkUnderlineNever = 0;
constexpr int kLinkUnderlineActive = 1;
constexpr int kLinkUnderlineAlways = 2;
extern const int &fsize;
extern const style::font &normalFont;
extern const style::font &semiboldFont;
extern const int &boxFontSize;
extern const style::font &boxTextFont;
extern const int &emojiSize;
extern const int &emojiPadding;
extern const int &lineWidth;
extern const style::TextPalette &defaultTextPalette;
extern const style::QuoteStyle &defaultQuoteStyle;
extern const style::TextStyle &defaultTextStyle;
extern const style::TextStyle &semiboldTextStyle;
constexpr int slideDuration = 240;
extern const int &slideShift;
extern const style::icon &slideShadow;
constexpr int slideWrapDuration = 150;
constexpr int fadeWrapDuration = 200;
extern const int &linkCropLimit;
extern const style::font &linkFont;
extern const style::font &linkFontOver;
extern const int &roundRadiusLarge;
extern const int &roundRadiusSmall;
extern const int &dateRadius;
extern const int &noContactsHeight;
extern const style::font &noContactsFont;
extern const style::color &noContactsColor;
constexpr int activeFadeInDuration = 500;
constexpr int activeFadeOutDuration = 3000;
extern const style::icon &smallCloseIcon;
extern const style::icon &smallCloseIconOver;
extern const style::size &radialSize;
extern const int &radialLine;
constexpr int radialDuration = 350;
constexpr int radialPeriod = 3000;
extern const style::size &locationSize;
extern const int &transparentPlaceholderSize;
extern const int &defaultVerticalListSkip;
extern const int &shakeShift;
constexpr int shakeDuration = 300;
constexpr int universalDuration = 120;
extern const style::color &roundedFg;
extern const style::color &roundedBg;
} // namespace st
