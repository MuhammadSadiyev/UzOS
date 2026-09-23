// WARNING! All changes made in this file will be lost!
// Created from 'widgets.style' by 'codegen_style'
//
// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#pragma once

#include "ui/style/style_core.h"

#include "styles/style_basic.h"

namespace style {
namespace internal {

void init_style_widgets(int scale);

} // namespace internal

struct TextStyle;
struct TextPalette;

struct LabelSimple {
	style::font font;
	int maxWidth;
	style::color textFg;
};

struct FlatLabel {
	style::margins margin;
	int minWidth;
	style::align align;
	style::color textFg;
	int maxHeight;
	style::TextStyle style;
	style::TextPalette palette;
};

struct DividerBar {
	style::color bg;
	style::icon top;
	style::icon bottom;
};

struct DividerLabel {
	style::DividerBar bar;
	style::FlatLabel label;
};

struct LinkButton {
	style::color color;
	style::color overColor;
	style::font font;
	style::font overFont;
	style::margins padding;
};

struct RippleAnimation {
	style::color color;
	int showDuration;
	int hideDuration;
};

struct InfiniteRadialAnimation {
	style::color color;
	int thickness;
	style::size size;
	int linearPeriod;
	int sinePeriod;
	int sineDuration;
	int sineShift;
	double arcMin;
	double arcMax;
};

struct FlatButton {
	style::color color;
	style::color overColor;
	style::color bgColor;
	style::color overBgColor;
	int width;
	int height;
	int textTop;
	style::font font;
	style::font overFont;
	style::RippleAnimation ripple;
};

struct RoundButton {
	style::color textFg;
	style::color textFgOver;
	style::color textBg;
	style::color textBgOver;
	style::color numbersTextFg;
	style::color numbersTextFgOver;
	int numbersSkip;
	int width;
	int height;
	int radius;
	bool fullRadius;
	style::margins padding;
	int textTop;
	style::icon icon;
	style::icon iconOver;
	style::point iconPosition;
	style::TextStyle style;
	style::RippleAnimation ripple;
};

struct Toggle {
	style::color toggledBg;
	style::color toggledFg;
	style::color untoggledBg;
	style::color untoggledFg;
	int duration;
	int border;
	int shift;
	int diameter;
	int width;
	int xsize;
	int vsize;
	int vshift;
	int stroke;
	style::icon lockIcon;
	int rippleAreaPadding;
};

struct Check {
	style::color bg;
	style::color untoggledFg;
	style::color toggledFg;
	int diameter;
	int thickness;
	style::icon icon;
	int duration;
	int rippleAreaPadding;
};

struct Radio {
	style::color bg;
	style::color untoggledFg;
	style::color toggledFg;
	int diameter;
	int thickness;
	int outerSkip;
	int skip;
	int duration;
	int rippleAreaPadding;
};

struct Checkbox {
	style::color textFg;
	style::color textFgActive;
	int width;
	style::margins margin;
	style::point textPosition;
	style::point checkPosition;
	style::TextStyle style;
	style::point rippleAreaPosition;
	style::color rippleBg;
	style::color rippleBgActive;
	style::RippleAnimation ripple;
	double disabledOpacity;
};

struct ScrollArea {
	style::color bg;
	style::color bgOver;
	style::color barBg;
	style::color barBgOver;
	bool barHidden;
	int round;
	int width;
	int minHeight;
	int deltax;
	int deltat;
	int deltab;
	int topsh;
	int bottomsh;
	style::color shColor;
	int duration;
	int hiding;
};

struct BoxShadow {
	int blurRadius;
	style::point offset;
	double opacity;
};

struct Shadow {
	style::icon left;
	style::icon topLeft;
	style::icon top;
	style::icon topRight;
	style::icon right;
	style::icon bottomRight;
	style::icon bottom;
	style::icon bottomLeft;
	style::margins extend;
	style::color fallback;
};

struct PanelAnimation {
	double startWidth;
	double widthDuration;
	double startHeight;
	double heightDuration;
	double startOpacity;
	double opacityDuration;
	double startFadeTop;
	double fadeHeight;
	double fadeOpacity;
	style::color fadeBg;
	style::BoxShadow shadow;
};

struct MenuSeparator {
	style::margins padding;
	int width;
	style::color fg;
};

struct Menu {
	int skip;
	style::color itemBg;
	style::color itemBgOver;
	style::color itemFg;
	style::color itemFgOver;
	style::color itemFgDisabled;
	style::color itemFgShortcut;
	style::color itemFgShortcutOver;
	style::color itemFgShortcutDisabled;
	style::margins itemPadding;
	int itemRightSkip;
	style::point itemIconPosition;
	style::TextStyle itemStyle;
	style::Toggle itemToggle;
	style::Toggle itemToggleOver;
	int itemToggleShift;
	style::MenuSeparator separator;
	style::icon arrow;
	int widthMin;
	int widthMax;
	style::RippleAnimation ripple;
};

struct PopupMenu {
	style::BoxShadow shadow;
	style::color shadowFallback;
	style::margins scrollPadding;
	int maxHeight;
	style::PanelAnimation animation;
	style::Menu menu;
	int radius;
	int duration;
	int showDuration;
};

struct PillTabs {
	int height;
	int margin;
	int borderWidth;
	style::TextStyle textStyle;
	style::color fg;
	style::color fgActive;
	style::color bg;
	style::color bgActive;
	style::color bgBorder;
	int duration;
};

struct InputField {
	style::color textBg;
	style::color textBgActive;
	style::color textFg;
	style::color textMarkBg;
	style::margins textMargins;
	style::align textAlign;
	style::color placeholderFg;
	style::color placeholderFgActive;
	style::color placeholderFgError;
	style::margins placeholderMargins;
	style::align placeholderAlign;
	double placeholderScale;
	int placeholderShift;
	style::font placeholderFont;
	int duration;
	style::color borderFg;
	style::color borderFgActive;
	style::color borderFgError;
	int border;
	int borderActive;
	int borderRadius;
	int borderDenominator;
	style::TextStyle style;
	style::PopupMenu menu;
	int width;
	int heightMin;
	int heightMax;
	int widthMin;
};

struct OutlineButton {
	style::color textBg;
	style::color textBgOver;
	style::color textFg;
	style::color textFgOver;
	style::font font;
	style::margins padding;
	style::RippleAnimation ripple;
};

struct IconButton {
	int width;
	int height;
	style::icon icon;
	style::icon iconOver;
	style::point iconPosition;
	int duration;
	style::point rippleAreaPosition;
	int rippleAreaSize;
	style::RippleAnimation ripple;
};

struct IconButtonWithText {
	style::IconButton iconButton;
	int height;
	style::color textFg;
	style::color textFgOver;
	style::margins textPadding;
	style::align textAlign;
	style::font font;
};

struct MediaSlider {
	int width;
	style::color activeFg;
	style::color inactiveFg;
	style::color activeFgOver;
	style::color inactiveFgOver;
	style::color activeFgDisabled;
	style::color inactiveFgDisabled;
	style::color receivedTillFg;
	style::size seekSize;
	int duration;
	style::color borderFg;
	int borderWidth;
};

struct FilledSlider {
	int fullWidth;
	int lineWidth;
	style::color activeFg;
	style::color inactiveFg;
	style::color disabledFg;
	int duration;
};

struct RoundCheckbox {
	style::color border;
	style::color bgInactive;
	style::color bgActive;
	int width;
	int size;
	double sizeSmall;
	int duration;
	double bgDuration;
	double fgDuration;
	style::icon check;
};

struct RoundImageCheckbox {
	int selectExtendTwice;
	int imageRadius;
	int imageSmallRadius;
	int selectWidth;
	style::color selectFg;
	int selectDuration;
	style::RoundCheckbox check;
};

struct CrossAnimation {
	style::color fg;
	int size;
	int skip;
	double stroke;
	double minScale;
};

struct CrossButton {
	int width;
	int height;
	style::CrossAnimation cross;
	style::color crossFg;
	style::color crossFgOver;
	style::point crossPosition;
	int duration;
	int loadingPeriod;
	style::RippleAnimation ripple;
};

struct CrossLineAnimation {
	style::color fg;
	style::icon icon;
	style::point startPosition;
	style::point endPosition;
	int stroke;
	int strokeDenominator;
};

struct ArcsAnimation {
	style::color fg;
	int stroke;
	int space;
	int duration;
	int deltaAngle;
	int deltaHeight;
	int deltaWidth;
	int startHeight;
	int startWidth;
};

struct MultiSelectItem {
	style::margins padding;
	int maxWidth;
	int height;
	style::TextStyle style;
	style::color textBg;
	style::color textFg;
	style::color textActiveBg;
	style::color textActiveFg;
	int duration;
	style::color deleteFg;
	style::CrossAnimation deleteCross;
	double minScale;
};

struct MultiSelect {
	style::color bg;
	style::margins padding;
	int maxHeight;
	style::ScrollArea scroll;
	style::MultiSelectItem item;
	int itemSkip;
	style::InputField field;
	int fieldMinWidth;
	style::icon fieldIcon;
	int fieldIconSkip;
	style::CrossButton fieldCancel;
	int fieldCancelSkip;
};

struct InnerDropdown {
	style::margins padding;
	style::Shadow shadow;
	style::PanelAnimation animation;
	int duration;
	int showDuration;
	int width;
	style::color bg;
	style::ScrollArea scroll;
	style::margins scrollMargin;
	style::margins scrollPadding;
};

struct DropdownMenu {
	style::InnerDropdown wrap;
	style::Menu menu;
};

struct Tooltip {
	style::color textBg;
	style::color textFg;
	style::TextStyle textStyle;
	style::color textBorder;
	style::margins textPadding;
	style::point shift;
	int skip;
	int widthMax;
	int linesMax;
};

struct ImportantTooltip {
	style::color bg;
	style::margins margin;
	style::margins padding;
	int radius;
	int arrow;
	int arrowSkipMin;
	int arrowSkip;
	int shift;
	int duration;
};

struct SettingsButton {
	style::color textFg;
	style::color textFgOver;
	style::color textBg;
	style::color textBgOver;
	style::TextStyle style;
	style::FlatLabel rightLabel;
	int height;
	style::margins padding;
	int iconLeft;
	style::Toggle toggle;
	style::Toggle toggleOver;
	int toggleSkip;
	style::RippleAnimation ripple;
};

struct SettingsCountButton {
	style::SettingsButton button;
	style::icon icon;
	style::point iconPosition;
	style::FlatLabel label;
	style::point labelPosition;
};

struct PassportScanRow {
	style::margins padding;
	int size;
	int textLeft;
	int nameTop;
	int statusTop;
	int border;
	style::color borderFg;
	style::IconButton remove;
	style::RoundButton restore;
};

struct WindowTitle {
	int height;
	style::color bg;
	style::color bgActive;
	style::color fg;
	style::color fgActive;
	bool shadow;
	bool oneSideControls;
	style::TextStyle style;
	style::IconButton minimize;
	style::icon minimizeIconActive;
	style::icon minimizeIconActiveOver;
	style::IconButton maximize;
	style::icon maximizeIconActive;
	style::icon maximizeIconActiveOver;
	style::icon restoreIcon;
	style::icon restoreIconOver;
	style::icon restoreIconActive;
	style::icon restoreIconActiveOver;
	style::IconButton close;
	style::icon closeIconActive;
	style::icon closeIconActiveOver;
};

struct SideBarButton {
	style::icon icon;
	style::icon iconActive;
	style::point iconPosition;
	int textTop;
	int textSkip;
	int minTextWidth;
	int minHeight;
	style::TextStyle style;
	style::TextStyle badgeStyle;
	int badgeSkip;
	int badgeHeight;
	int badgeStroke;
	style::point badgePosition;
	style::color textBg;
	style::color textBgActive;
	style::color textFg;
	style::color textFgActive;
	style::color badgeBg;
	style::color badgeBgActive;
	style::color badgeBgMuted;
	style::color badgeBgMutedActive;
	style::color badgeFg;
	style::RippleAnimation ripple;
};

struct Toast {
	style::TextStyle style;
	style::TextPalette palette;
	style::margins padding;
	style::margins margin;
	int minWidth;
	int maxWidth;
	int radius;
	int durationFadeIn;
	int durationFadeOut;
	int durationSlide;
};

struct Table {
	style::color headerBg;
	style::color borderFg;
	int border;
	int radius;
	int labelMinWidth;
	double labelMaxWidth;
	style::RoundButton smallButton;
	style::FlatLabel defaultLabel;
	style::FlatLabel defaultValue;
};

struct SettingsSlider {
	int padding;
	int height;
	int barTop;
	int barSkip;
	int barStroke;
	int barRadius;
	style::color barFg;
	style::color barFgActive;
	bool barSnapToLabel;
	int labelTop;
	style::TextStyle labelStyle;
	style::color labelFg;
	style::color labelFgActive;
	int strictSkip;
	int duration;
	int rippleBottomSkip;
	style::color rippleBg;
	style::color rippleBgActive;
	style::RippleAnimation ripple;
};

struct BotKeyboardButton {
	int margin;
	int padding;
	int height;
	int textTop;
	style::RippleAnimation ripple;
};

struct TwoIconButton {
	int width;
	int height;
	style::icon iconBelow;
	style::icon iconAbove;
	style::icon iconBelowOver;
	style::icon iconAboveOver;
	style::point iconPosition;
	style::point rippleAreaPosition;
	int rippleAreaSize;
	style::RippleAnimation ripple;
};

struct PeerListItem {
	int left;
	int bottom;
	int height;
	style::point photoPosition;
	style::point namePosition;
	style::TextStyle nameStyle;
	style::color nameFg;
	style::color nameFgChecked;
	style::point statusPosition;
	int photoSize;
	int maximalWidth;
	style::OutlineButton button;
	style::RoundImageCheckbox checkbox;
	style::color disabledCheckFg;
	style::color statusFg;
	style::color statusFgOver;
	style::color statusFgActive;
};

struct PeerList {
	style::margins padding;
	style::color bg;
	style::FlatLabel about;
	style::PeerListItem item;
};

struct SearchFieldRow {
	int height;
	style::margins padding;
	style::InputField field;
	style::icon fieldIcon;
	int fieldIconSkip;
	style::CrossButton fieldCancel;
	int fieldCancelSkip;
};

struct LevelMeter {
	int height;
	int lineWidth;
	int lineSpacing;
	int lineCount;
	style::color activeFg;
	style::color inactiveFg;
};

} // namespace style

namespace st {
extern const style::InfiniteRadialAnimation &defaultInfiniteRadialAnimation;
extern const style::LabelSimple &defaultLabelSimple;
extern const style::FlatLabel &defaultFlatLabel;
extern const style::FlatLabel &defaultSubTextLabel;
extern const style::icon &boxDividerTop;
extern const style::icon &boxDividerBottom;
extern const int &boxDividerHeight;
extern const style::DividerBar &defaultDividerBar;
extern const style::FlatLabel &boxDividerLabel;
extern const style::margins &defaultBoxDividerLabelPadding;
extern const style::DividerLabel &defaultDividerLabel;
extern const style::LinkButton &defaultLinkButton;
extern const style::RippleAnimation &defaultRippleAnimation;
extern const style::RippleAnimation &emptyRippleAnimation;
extern const style::RippleAnimation &defaultRippleAnimationBgOver;
extern const int &buttonRadius;
extern const style::RoundButton &defaultActiveButton;
extern const style::RoundButton &customEmojiTextBadge;
extern const style::margins &customEmojiTextBadgeMargin;
extern const style::RoundButton &defaultLightButton;
extern const style::FlatLabel &defaultTableLabel;
extern const style::FlatLabel &defaultTableValue;
extern const style::RoundButton &defaultTableSmallButton;
extern const style::Table &defaultTable;
extern const style::ScrollArea &defaultScrollArea;
extern const int &scrollBarMin;
extern const style::ScrollArea &defaultSolidScroll;
extern const style::icon &defaultCheckboxIcon;
extern const style::Check &defaultCheck;
extern const style::Radio &defaultRadio;
extern const style::Toggle &defaultToggle;
extern const style::Checkbox &defaultCheckbox;
extern const style::Shadow &defaultRoundShadow;
extern const style::Shadow &defaultEmptyShadow;
extern const style::BoxShadow &defaultBoxShadow;
extern const style::Shadow &roundShadowRadius8px;
extern const style::PanelAnimation &defaultPanelAnimation;
extern const style::icon &defaultMenuArrow;
extern const style::Toggle &defaultMenuToggle;
extern const style::Toggle &defaultMenuToggleOver;
extern const style::MenuSeparator &defaultMenuSeparator;
extern const style::Menu &defaultMenu;
extern const style::PopupMenu &defaultPopupMenu;
extern const style::PillTabs &defaultPillTabs;
extern const style::PillTabs &popupMenuPillTabs;
extern const style::TextStyle &boxTextStyle;
extern const style::InputField &defaultInputField;
extern const style::FlatLabel &defaultInputFieldLimit;
extern const style::IconButton &defaultIconButton;
extern const style::MultiSelectItem &defaultMultiSelectItem;
extern const style::InputField &defaultMultiSelectSearchField;
extern const style::icon &boxFieldSearchIcon;
extern const style::CrossButton &defaultMultiSelectSearchCancel;
extern const style::MultiSelect &defaultMultiSelect;
constexpr int widgetFadeDuration = 200;
extern const style::SettingsSlider &defaultSettingsSlider;
extern const style::SettingsSlider &defaultTabsSlider;
extern const style::MediaSlider &defaultContinuousSlider;
extern const style::RoundCheckbox &defaultRoundCheckbox;
extern const style::icon &defaultPeerListCheckIcon;
extern const style::RoundCheckbox &defaultPeerListCheck;
extern const style::RoundImageCheckbox &defaultPeerListCheckbox;
extern const int &innerDropdownRadius;
extern const style::InnerDropdown &defaultInnerDropdown;
extern const style::DropdownMenu &defaultDropdownMenu;
extern const style::Tooltip &defaultTooltip;
extern const style::ImportantTooltip &defaultImportantTooltip;
extern const style::FlatLabel &defaultImportantTooltipLabel;
constexpr int historySendActionTypingDuration = 800;
constexpr int historySendActionTypingHalfPeriod = 320;
constexpr int historySendActionTypingDeltaTime = 150;
extern const style::point &historySendActionTypingPosition;
extern const int &historySendActionTypingDelta;
extern const int &historySendActionTypingLargeNumerator;
extern const int &historySendActionTypingSmallNumerator;
constexpr double historySendActionTypingDenominator = 12;
constexpr int historySendActionRecordDuration = 500;
extern const style::point &historySendActionRecordPosition;
extern const int &historySendActionRecordDelta;
extern const int &historySendActionRecordStrokeNumerator;
constexpr double historySendActionRecordDenominator = 8;
constexpr int historySendActionUploadDuration = 500;
extern const style::point &historySendActionUploadPosition;
extern const int &historySendActionUploadDelta;
extern const int &historySendActionUploadStrokeNumerator;
extern const int &historySendActionUploadSizeNumerator;
constexpr double historySendActionUploadDenominator = 8;
constexpr int historySendActionChooseStickerDuration = 2000;
extern const style::point &historySendActionChooseStickerPosition;
extern const int &historySendActionChooseStickerEyeWidth;
extern const int &historySendActionChooseStickerEyeHeight;
extern const int &historySendActionChooseStickerEyeStep;
extern const style::point &historySendActionRoundPosition;
extern const int &historySendActionRoundRadius;
extern const style::OutlineButton &defaultPeerListButton;
extern const style::PeerListItem &defaultPeerListItem;
extern const style::FlatLabel &defaultPeerListAbout;
extern const style::PeerList &defaultPeerList;
extern const style::LevelMeter &defaultLevelMeter;
extern const style::icon &menuToggleIcon;
extern const style::icon &menuToggleIconOver;
extern const style::IconButton &menuToggle;
extern const style::icon &backButtonIcon;
extern const style::icon &backButtonIconOver;
extern const style::IconButton &backButton;
extern const style::Toggle &defaultSettingsToggle;
extern const style::Toggle &defaultSettingsToggleOver;
extern const style::FlatLabel &defaultSettingsRightLabel;
extern const style::SettingsButton &defaultSettingsButton;
extern const style::SideBarButton &defaultSideBarButton;
extern const style::TextPalette &defaultToastPalette;
extern const style::size &defaultToastLottieSize;
extern const style::margins &defaultToastIconPadding;
extern const style::Toast &defaultToast;
extern const style::Toast &defaultMultilineToast;
extern const int &windowTitleButtonWidth;
extern const int &windowTitleHeight;
extern const style::IconButton &windowTitleButton;
extern const style::IconButton &windowTitleButtonClose;
extern const style::size &windowTitleButtonSize;
extern const style::WindowTitle &defaultWindowTitle;
extern const style::icon &windowShadow;
extern const int &windowShadowShift;
extern const int &callRadius;
extern const style::margins &callShadowExtend;
extern const style::Shadow &callShadow;
extern const int &sideBarButtonLockArcOffset;
extern const style::size &sideBarButtonLockSize;
extern const int &sideBarButtonLockCornerShift;
extern const int &sideBarButtonLockArcHeight;
extern const int &sideBarButtonLockBlockHeight;
extern const int &sideBarButtonLockPenWidth;
constexpr int sideBarButtonLockPenWidthDivider = 2;
extern const style::color &menuIconColor;
extern const style::color &menuIconAttentionColor;
extern const style::icon &menuIconSubmenuArrow;
extern const style::Menu &menuWithIcons;
extern const style::Menu &menuWithIconsAttention;
extern const style::Menu &menuAttention;
extern const style::PopupMenu &popupMenuWithIcons;
extern const style::DropdownMenu &dropdownMenuWithIcons;
extern const style::RippleAnimation &universalRippleAnimation;
} // namespace st
