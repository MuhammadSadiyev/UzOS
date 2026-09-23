// WARNING! All changes made in this file will be lost!
// Created from 'layers.style' by 'codegen_style'
//
// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#pragma once

#include "ui/style/style_core.h"

#include "styles/style_widgets.h"

namespace style {
namespace internal {

void init_style_layers(int scale);

} // namespace internal

struct TextStyle;
struct RoundButton;
struct Checkbox;
struct Shadow;
struct FlatLabel;
struct ScrollArea;
struct IconButton;
struct LinkButton;
struct InfiniteRadialAnimation;

struct ServiceCheck {
	style::margins margin;
	int diameter;
	int shift;
	int thickness;
	style::point tip;
	int small;
	int large;
	int stroke;
	style::color color;
	int duration;
};

struct Box {
	style::margins buttonPadding;
	int buttonHeight;
	bool buttonWide;
	style::RoundButton button;
	style::margins margin;
	style::FlatLabel title;
	style::color bg;
	style::color titleAdditionalFg;
	bool shadowIgnoreTopSkip;
	bool shadowIgnoreBottomSkip;
};

} // namespace style

namespace st {
constexpr int boxDuration = 200;
extern const int &boxRadius;
extern const style::font &boxButtonFont;
extern const style::TextStyle &defaultBoxButtonTextStyle;
extern const style::RoundButton &defaultBoxButton;
extern const style::TextStyle &boxLabelStyle;
extern const style::RoundButton &attentionBoxButton;
extern const style::Checkbox &defaultBoxCheckbox;
extern const style::Shadow &boxRoundShadow;
extern const style::font &boxTitleFont;
extern const style::FlatLabel &boxTitle;
extern const style::point &boxTitlePosition;
extern const int &boxTitleHeight;
extern const int &boxTitleAdditionalSkip;
extern const style::font &boxTitleAdditionalFont;
extern const style::ScrollArea &boxScroll;
extern const style::margins &boxRowPadding;
extern const int &boxTopMargin;
extern const style::icon &boxTitleCloseIcon;
extern const style::icon &boxTitleCloseIconOver;
extern const style::IconButton &boxTitleClose;
extern const style::IconButton &boxTitleMenu;
extern const style::LinkButton &boxLinkButton;
extern const style::margins &boxOptionListPadding;
extern const int &boxOptionListSkip;
extern const int &boxWidth;
extern const int &boxWideWidth;
extern const style::margins &boxPadding;
extern const int &boxMaxListHeight;
extern const int &boxLittleSkip;
extern const int &boxMediumSkip;
extern const style::Box &defaultBox;
extern const style::Box &layerBox;
extern const style::FlatLabel &boxLabel;
extern const style::InfiniteRadialAnimation &boxLoadingAnimation;
extern const int &boxLoadingSize;
extern const style::FlatLabel &defaultSubsectionTitle;
extern const style::margins &defaultSubsectionTitlePadding;
extern const int &separatePanelBorderCacheSize;
extern const int &separatePanelTitleHeight;
extern const int &separatePanelNoTitleHeight;
extern const int &separatePanelTitleBadgeSkip;
extern const style::IconButton &separatePanelClose;
extern const style::IconButton &separatePanelMenu;
extern const style::point &separatePanelMenuPosition;
extern const style::font &separatePanelTitleFont;
extern const style::FlatLabel &separatePanelTitle;
extern const int &separatePanelTitleTop;
extern const int &separatePanelTitleLeft;
extern const int &separatePanelTitleSkip;
extern const int &separatePanelTitleBadgeTop;
extern const style::IconButton &separatePanelSearch;
extern const style::IconButton &separatePanelBack;
constexpr int separatePanelDuration = 150;
extern const style::IconButton &fullScreenPanelClose;
extern const style::IconButton &fullScreenPanelBack;
extern const style::IconButton &fullScreenPanelMenu;
extern const style::RoundButton &webviewDialogButton;
extern const style::RoundButton &webviewDialogDestructiveButton;
extern const style::RoundButton &webviewDialogSubmit;
extern const style::margins &webviewDialogPadding;
} // namespace st
