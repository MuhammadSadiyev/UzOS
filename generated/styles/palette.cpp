// WARNING! All changes made in this file will be lost!
// Created from 'colors.palette' by 'codegen_style'
//
// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#include "palette.h"

#include "ui/style/style_core_palette.h"

namespace {

bool inited = false;

class Module_palette : public style::internal::ModuleBase {
public:
	Module_palette() { style::internal::registerModule(this); }

	void start(int scale) override {
		style::internal::init_palette(scale);
	}
};
Module_palette registrator;

style::palette _palette;

} // namespace

namespace st {
const style::color &transparent(_palette.transparent()); // special color
const style::color &white(_palette.white()); // special color
const style::color &windowBg(_palette.windowBg());
const style::color &windowFg(_palette.windowFg());
const style::color &windowBgOver(_palette.windowBgOver());
const style::color &windowBgRipple(_palette.windowBgRipple());
const style::color &windowFgOver(_palette.windowFgOver());
const style::color &windowSubTextFg(_palette.windowSubTextFg());
const style::color &windowSubTextFgOver(_palette.windowSubTextFgOver());
const style::color &windowBoldFg(_palette.windowBoldFg());
const style::color &windowBoldFgOver(_palette.windowBoldFgOver());
const style::color &windowBgActive(_palette.windowBgActive());
const style::color &windowFgActive(_palette.windowFgActive());
const style::color &windowActiveTextFg(_palette.windowActiveTextFg());
const style::color &windowShadowFg(_palette.windowShadowFg());
const style::color &windowShadowFgFallback(_palette.windowShadowFgFallback());
const style::color &shadowFg(_palette.shadowFg());
const style::color &slideFadeOutBg(_palette.slideFadeOutBg());
const style::color &slideFadeOutShadowFg(_palette.slideFadeOutShadowFg());
const style::color &imageBg(_palette.imageBg());
const style::color &imageBgTransparent(_palette.imageBgTransparent());
const style::color &activeButtonBg(_palette.activeButtonBg());
const style::color &activeButtonBgOver(_palette.activeButtonBgOver());
const style::color &activeButtonBgRipple(_palette.activeButtonBgRipple());
const style::color &activeButtonFg(_palette.activeButtonFg());
const style::color &activeButtonFgOver(_palette.activeButtonFgOver());
const style::color &activeButtonSecondaryFg(_palette.activeButtonSecondaryFg());
const style::color &activeButtonSecondaryFgOver(_palette.activeButtonSecondaryFgOver());
const style::color &activeLineFg(_palette.activeLineFg());
const style::color &activeLineFgError(_palette.activeLineFgError());
const style::color &lightButtonBg(_palette.lightButtonBg());
const style::color &lightButtonBgOver(_palette.lightButtonBgOver());
const style::color &lightButtonBgRipple(_palette.lightButtonBgRipple());
const style::color &lightButtonFg(_palette.lightButtonFg());
const style::color &lightButtonFgOver(_palette.lightButtonFgOver());
const style::color &attentionButtonFg(_palette.attentionButtonFg());
const style::color &attentionButtonFgOver(_palette.attentionButtonFgOver());
const style::color &attentionButtonBgOver(_palette.attentionButtonBgOver());
const style::color &attentionButtonBgRipple(_palette.attentionButtonBgRipple());
const style::color &menuBg(_palette.menuBg());
const style::color &menuBgOver(_palette.menuBgOver());
const style::color &menuBgRipple(_palette.menuBgRipple());
const style::color &menuIconFg(_palette.menuIconFg());
const style::color &menuIconFgOver(_palette.menuIconFgOver());
const style::color &menuSubmenuArrowFg(_palette.menuSubmenuArrowFg());
const style::color &menuFgDisabled(_palette.menuFgDisabled());
const style::color &menuSeparatorFg(_palette.menuSeparatorFg());
const style::color &scrollBarBg(_palette.scrollBarBg());
const style::color &scrollBarBgOver(_palette.scrollBarBgOver());
const style::color &scrollBg(_palette.scrollBg());
const style::color &scrollBgOver(_palette.scrollBgOver());
const style::color &smallCloseIconFg(_palette.smallCloseIconFg());
const style::color &smallCloseIconFgOver(_palette.smallCloseIconFgOver());
const style::color &radialFg(_palette.radialFg());
const style::color &radialBg(_palette.radialBg());
const style::color &placeholderFg(_palette.placeholderFg());
const style::color &placeholderFgActive(_palette.placeholderFgActive());
const style::color &inputBorderFg(_palette.inputBorderFg());
const style::color &filterInputBorderFg(_palette.filterInputBorderFg());
const style::color &filterInputActiveBg(_palette.filterInputActiveBg());
const style::color &filterInputInactiveBg(_palette.filterInputInactiveBg());
const style::color &checkboxFg(_palette.checkboxFg());
const style::color &botKbBg(_palette.botKbBg());
const style::color &botKbDownBg(_palette.botKbDownBg());
const style::color &botKbColor(_palette.botKbColor());
const style::color &botKbPrimaryBg(_palette.botKbPrimaryBg());
const style::color &botKbDangerBg(_palette.botKbDangerBg());
const style::color &botKbSuccessBg(_palette.botKbSuccessBg());
const style::color &botKbInlinePrimaryBg(_palette.botKbInlinePrimaryBg());
const style::color &botKbInlineDangerBg(_palette.botKbInlineDangerBg());
const style::color &botKbInlineSuccessBg(_palette.botKbInlineSuccessBg());
const style::color &sliderBgInactive(_palette.sliderBgInactive());
const style::color &sliderBgActive(_palette.sliderBgActive());
const style::color &tooltipBg(_palette.tooltipBg());
const style::color &tooltipFg(_palette.tooltipFg());
const style::color &tooltipBorderFg(_palette.tooltipBorderFg());
const style::color &titleShadow(_palette.titleShadow());
const style::color &titleBg(_palette.titleBg());
const style::color &titleBgActive(_palette.titleBgActive());
const style::color &titleButtonBg(_palette.titleButtonBg());
const style::color &titleButtonFg(_palette.titleButtonFg());
const style::color &titleButtonBgOver(_palette.titleButtonBgOver());
const style::color &titleButtonFgOver(_palette.titleButtonFgOver());
const style::color &titleButtonBgActive(_palette.titleButtonBgActive());
const style::color &titleButtonFgActive(_palette.titleButtonFgActive());
const style::color &titleButtonBgActiveOver(_palette.titleButtonBgActiveOver());
const style::color &titleButtonFgActiveOver(_palette.titleButtonFgActiveOver());
const style::color &titleButtonCloseBg(_palette.titleButtonCloseBg());
const style::color &titleButtonCloseFg(_palette.titleButtonCloseFg());
const style::color &titleButtonCloseBgOver(_palette.titleButtonCloseBgOver());
const style::color &titleButtonCloseFgOver(_palette.titleButtonCloseFgOver());
const style::color &titleButtonCloseBgActive(_palette.titleButtonCloseBgActive());
const style::color &titleButtonCloseFgActive(_palette.titleButtonCloseFgActive());
const style::color &titleButtonCloseBgActiveOver(_palette.titleButtonCloseBgActiveOver());
const style::color &titleButtonCloseFgActiveOver(_palette.titleButtonCloseFgActiveOver());
const style::color &titleFg(_palette.titleFg());
const style::color &titleFgActive(_palette.titleFgActive());
const style::color &trayCounterBg(_palette.trayCounterBg());
const style::color &trayCounterBgMute(_palette.trayCounterBgMute());
const style::color &trayCounterFg(_palette.trayCounterFg());
const style::color &trayCounterBgMacInvert(_palette.trayCounterBgMacInvert());
const style::color &trayCounterFgMacInvert(_palette.trayCounterFgMacInvert());
const style::color &layerBg(_palette.layerBg());
const style::color &cancelIconFg(_palette.cancelIconFg());
const style::color &cancelIconFgOver(_palette.cancelIconFgOver());
const style::color &boxBg(_palette.boxBg());
const style::color &boxTextFg(_palette.boxTextFg());
const style::color &boxTextFgGood(_palette.boxTextFgGood());
const style::color &boxTextFgError(_palette.boxTextFgError());
const style::color &boxTitleFg(_palette.boxTitleFg());
const style::color &boxSearchBg(_palette.boxSearchBg());
const style::color &boxTitleAdditionalFg(_palette.boxTitleAdditionalFg());
const style::color &boxTitleCloseFg(_palette.boxTitleCloseFg());
const style::color &boxTitleCloseFgOver(_palette.boxTitleCloseFgOver());
const style::color &boxDividerBg(_palette.boxDividerBg());
const style::color &boxDividerFg(_palette.boxDividerFg());
const style::color &paymentsTipActive(_palette.paymentsTipActive());
const style::color &membersAboutLimitFg(_palette.membersAboutLimitFg());
const style::color &contactsBg(_palette.contactsBg());
const style::color &contactsBgOver(_palette.contactsBgOver());
const style::color &contactsNameFg(_palette.contactsNameFg());
const style::color &contactsStatusFg(_palette.contactsStatusFg());
const style::color &contactsStatusFgOver(_palette.contactsStatusFgOver());
const style::color &contactsStatusFgOnline(_palette.contactsStatusFgOnline());
const style::color &photoCropFadeBg(_palette.photoCropFadeBg());
const style::color &photoCropPointFg(_palette.photoCropPointFg());
const style::color &callArrowFg(_palette.callArrowFg());
const style::color &callArrowMissedFg(_palette.callArrowMissedFg());
const style::color &introBg(_palette.introBg());
const style::color &introTitleFg(_palette.introTitleFg());
const style::color &introDescriptionFg(_palette.introDescriptionFg());
const style::color &introCoverTopBg(_palette.introCoverTopBg());
const style::color &introCoverBottomBg(_palette.introCoverBottomBg());
const style::color &introCoverIconsFg(_palette.introCoverIconsFg());
const style::color &introCoverPlaneTrace(_palette.introCoverPlaneTrace());
const style::color &introCoverPlaneInner(_palette.introCoverPlaneInner());
const style::color &introCoverPlaneOuter(_palette.introCoverPlaneOuter());
const style::color &introCoverPlaneTop(_palette.introCoverPlaneTop());
const style::color &dialogsMenuIconFg(_palette.dialogsMenuIconFg());
const style::color &dialogsMenuIconFgOver(_palette.dialogsMenuIconFgOver());
const style::color &dialogsBg(_palette.dialogsBg());
const style::color &dialogsNameFg(_palette.dialogsNameFg());
const style::color &dialogsChatIconFg(_palette.dialogsChatIconFg());
const style::color &dialogsDateFg(_palette.dialogsDateFg());
const style::color &dialogsTextFg(_palette.dialogsTextFg());
const style::color &dialogsTextFgService(_palette.dialogsTextFgService());
const style::color &dialogsDraftFg(_palette.dialogsDraftFg());
const style::color &dialogsVerifiedIconBg(_palette.dialogsVerifiedIconBg());
const style::color &dialogsVerifiedIconFg(_palette.dialogsVerifiedIconFg());
const style::color &dialogsSendingIconFg(_palette.dialogsSendingIconFg());
const style::color &dialogsSentIconFg(_palette.dialogsSentIconFg());
const style::color &dialogsUnreadBg(_palette.dialogsUnreadBg());
const style::color &dialogsUnreadBgMuted(_palette.dialogsUnreadBgMuted());
const style::color &dialogsUnreadFg(_palette.dialogsUnreadFg());
const style::color &dialogsArchiveFg(_palette.dialogsArchiveFg());
const style::color &dialogsOnlineBadgeFg(_palette.dialogsOnlineBadgeFg());
const style::color &dialogsScamFg(_palette.dialogsScamFg());
const style::color &dialogsBgOver(_palette.dialogsBgOver());
const style::color &dialogsNameFgOver(_palette.dialogsNameFgOver());
const style::color &dialogsChatIconFgOver(_palette.dialogsChatIconFgOver());
const style::color &dialogsDateFgOver(_palette.dialogsDateFgOver());
const style::color &dialogsTextFgOver(_palette.dialogsTextFgOver());
const style::color &dialogsTextFgServiceOver(_palette.dialogsTextFgServiceOver());
const style::color &dialogsDraftFgOver(_palette.dialogsDraftFgOver());
const style::color &dialogsVerifiedIconBgOver(_palette.dialogsVerifiedIconBgOver());
const style::color &dialogsVerifiedIconFgOver(_palette.dialogsVerifiedIconFgOver());
const style::color &dialogsSendingIconFgOver(_palette.dialogsSendingIconFgOver());
const style::color &dialogsSentIconFgOver(_palette.dialogsSentIconFgOver());
const style::color &dialogsUnreadBgOver(_palette.dialogsUnreadBgOver());
const style::color &dialogsUnreadBgMutedOver(_palette.dialogsUnreadBgMutedOver());
const style::color &dialogsUnreadFgOver(_palette.dialogsUnreadFgOver());
const style::color &dialogsArchiveFgOver(_palette.dialogsArchiveFgOver());
const style::color &dialogsScamFgOver(_palette.dialogsScamFgOver());
const style::color &dialogsBgActive(_palette.dialogsBgActive());
const style::color &dialogsNameFgActive(_palette.dialogsNameFgActive());
const style::color &dialogsChatIconFgActive(_palette.dialogsChatIconFgActive());
const style::color &dialogsDateFgActive(_palette.dialogsDateFgActive());
const style::color &dialogsTextFgActive(_palette.dialogsTextFgActive());
const style::color &dialogsTextFgServiceActive(_palette.dialogsTextFgServiceActive());
const style::color &dialogsDraftFgActive(_palette.dialogsDraftFgActive());
const style::color &dialogsVerifiedIconBgActive(_palette.dialogsVerifiedIconBgActive());
const style::color &dialogsVerifiedIconFgActive(_palette.dialogsVerifiedIconFgActive());
const style::color &dialogsSendingIconFgActive(_palette.dialogsSendingIconFgActive());
const style::color &dialogsSentIconFgActive(_palette.dialogsSentIconFgActive());
const style::color &dialogsUnreadBgActive(_palette.dialogsUnreadBgActive());
const style::color &dialogsUnreadBgMutedActive(_palette.dialogsUnreadBgMutedActive());
const style::color &dialogsUnreadFgActive(_palette.dialogsUnreadFgActive());
const style::color &dialogsOnlineBadgeFgActive(_palette.dialogsOnlineBadgeFgActive());
const style::color &dialogsScamFgActive(_palette.dialogsScamFgActive());
const style::color &dialogsRippleBg(_palette.dialogsRippleBg());
const style::color &dialogsRippleBgActive(_palette.dialogsRippleBgActive());
const style::color &searchedBarBg(_palette.searchedBarBg());
const style::color &searchedBarFg(_palette.searchedBarFg());
const style::color &searchedTextMatchBg(_palette.searchedTextMatchBg());
const style::color &searchedTextMatchFg(_palette.searchedTextMatchFg());
const style::color &searchedTextCurrentMatchBg(_palette.searchedTextCurrentMatchBg());
const style::color &searchedTextCurrentMatchFg(_palette.searchedTextCurrentMatchFg());
const style::color &topBarBg(_palette.topBarBg());
const style::color &emojiPanBg(_palette.emojiPanBg());
const style::color &emojiPanCategories(_palette.emojiPanCategories());
const style::color &emojiPanHeaderFg(_palette.emojiPanHeaderFg());
const style::color &emojiPanHeaderBg(_palette.emojiPanHeaderBg());
const style::color &emojiIconFg(_palette.emojiIconFg());
const style::color &emojiSubIconFgActive(_palette.emojiSubIconFgActive());
const style::color &stickerPanDeleteBg(_palette.stickerPanDeleteBg());
const style::color &stickerPanDeleteFg(_palette.stickerPanDeleteFg());
const style::color &stickerPreviewBg(_palette.stickerPreviewBg());
const style::color &stickerPanPremium1(_palette.stickerPanPremium1());
const style::color &stickerPanPremium2(_palette.stickerPanPremium2());
const style::color &historyTextInFg(_palette.historyTextInFg());
const style::color &historyTextInFgSelected(_palette.historyTextInFgSelected());
const style::color &historyTextOutFg(_palette.historyTextOutFg());
const style::color &historyTextOutFgSelected(_palette.historyTextOutFgSelected());
const style::color &historyLinkInFg(_palette.historyLinkInFg());
const style::color &historyLinkInFgSelected(_palette.historyLinkInFgSelected());
const style::color &historyLinkOutFg(_palette.historyLinkOutFg());
const style::color &historyLinkOutFgSelected(_palette.historyLinkOutFgSelected());
const style::color &historyFileNameInFg(_palette.historyFileNameInFg());
const style::color &historyFileNameInFgSelected(_palette.historyFileNameInFgSelected());
const style::color &historyFileNameOutFg(_palette.historyFileNameOutFg());
const style::color &historyFileNameOutFgSelected(_palette.historyFileNameOutFgSelected());
const style::color &historyOutIconFg(_palette.historyOutIconFg());
const style::color &historyOutIconFgSelected(_palette.historyOutIconFgSelected());
const style::color &historyIconFgInverted(_palette.historyIconFgInverted());
const style::color &historySendingOutIconFg(_palette.historySendingOutIconFg());
const style::color &historySendingInIconFg(_palette.historySendingInIconFg());
const style::color &historySendingInvertedIconFg(_palette.historySendingInvertedIconFg());
const style::color &historyCallArrowInFg(_palette.historyCallArrowInFg());
const style::color &historyCallArrowInFgSelected(_palette.historyCallArrowInFgSelected());
const style::color &historyCallArrowMissedInFg(_palette.historyCallArrowMissedInFg());
const style::color &historyCallArrowMissedInFgSelected(_palette.historyCallArrowMissedInFgSelected());
const style::color &historyCallArrowOutFg(_palette.historyCallArrowOutFg());
const style::color &historyCallArrowOutFgSelected(_palette.historyCallArrowOutFgSelected());
const style::color &historyUnreadBarBg(_palette.historyUnreadBarBg());
const style::color &historyUnreadBarBorder(_palette.historyUnreadBarBorder());
const style::color &historyUnreadBarFg(_palette.historyUnreadBarFg());
const style::color &historyForwardChooseBg(_palette.historyForwardChooseBg());
const style::color &historyForwardChooseFg(_palette.historyForwardChooseFg());
const style::color &historyPeer1NameFg(_palette.historyPeer1NameFg());
const style::color &historyPeer1NameFgSelected(_palette.historyPeer1NameFgSelected());
const style::color &historyPeer1UserpicBg(_palette.historyPeer1UserpicBg());
const style::color &historyPeer2NameFg(_palette.historyPeer2NameFg());
const style::color &historyPeer2NameFgSelected(_palette.historyPeer2NameFgSelected());
const style::color &historyPeer2UserpicBg(_palette.historyPeer2UserpicBg());
const style::color &historyPeer3NameFg(_palette.historyPeer3NameFg());
const style::color &historyPeer3NameFgSelected(_palette.historyPeer3NameFgSelected());
const style::color &historyPeer3UserpicBg(_palette.historyPeer3UserpicBg());
const style::color &historyPeer4NameFg(_palette.historyPeer4NameFg());
const style::color &historyPeer4NameFgSelected(_palette.historyPeer4NameFgSelected());
const style::color &historyPeer4UserpicBg(_palette.historyPeer4UserpicBg());
const style::color &historyPeer5NameFg(_palette.historyPeer5NameFg());
const style::color &historyPeer5NameFgSelected(_palette.historyPeer5NameFgSelected());
const style::color &historyPeer5UserpicBg(_palette.historyPeer5UserpicBg());
const style::color &historyPeer6NameFg(_palette.historyPeer6NameFg());
const style::color &historyPeer6NameFgSelected(_palette.historyPeer6NameFgSelected());
const style::color &historyPeer6UserpicBg(_palette.historyPeer6UserpicBg());
const style::color &historyPeer7NameFg(_palette.historyPeer7NameFg());
const style::color &historyPeer7NameFgSelected(_palette.historyPeer7NameFgSelected());
const style::color &historyPeer7UserpicBg(_palette.historyPeer7UserpicBg());
const style::color &historyPeer8NameFg(_palette.historyPeer8NameFg());
const style::color &historyPeer8NameFgSelected(_palette.historyPeer8NameFgSelected());
const style::color &historyPeer8UserpicBg(_palette.historyPeer8UserpicBg());
const style::color &historyPeerUserpicFg(_palette.historyPeerUserpicFg());
const style::color &historyPeerSavedMessagesBg(_palette.historyPeerSavedMessagesBg());
const style::color &historyPeerArchiveUserpicBg(_palette.historyPeerArchiveUserpicBg());
const style::color &historyPeer1UserpicBg2(_palette.historyPeer1UserpicBg2());
const style::color &historyPeer2UserpicBg2(_palette.historyPeer2UserpicBg2());
const style::color &historyPeer3UserpicBg2(_palette.historyPeer3UserpicBg2());
const style::color &historyPeer4UserpicBg2(_palette.historyPeer4UserpicBg2());
const style::color &historyPeer5UserpicBg2(_palette.historyPeer5UserpicBg2());
const style::color &historyPeer6UserpicBg2(_palette.historyPeer6UserpicBg2());
const style::color &historyPeer7UserpicBg2(_palette.historyPeer7UserpicBg2());
const style::color &historyPeer8UserpicBg2(_palette.historyPeer8UserpicBg2());
const style::color &historyPeerSavedMessagesBg2(_palette.historyPeerSavedMessagesBg2());
const style::color &settingsIconBg1(_palette.settingsIconBg1());
const style::color &settingsIconBg2(_palette.settingsIconBg2());
const style::color &settingsIconBg3(_palette.settingsIconBg3());
const style::color &settingsIconBg4(_palette.settingsIconBg4());
const style::color &settingsIconBg5(_palette.settingsIconBg5());
const style::color &settingsIconBg6(_palette.settingsIconBg6());
const style::color &settingsIconBg8(_palette.settingsIconBg8());
const style::color &settingsIconBgArchive(_palette.settingsIconBgArchive());
const style::color &settingsIconFg(_palette.settingsIconFg());
const style::color &historyScrollBarBg(_palette.historyScrollBarBg());
const style::color &historyScrollBarBgOver(_palette.historyScrollBarBgOver());
const style::color &historyScrollBg(_palette.historyScrollBg());
const style::color &historyScrollBgOver(_palette.historyScrollBgOver());
const style::color &msgInBg(_palette.msgInBg());
const style::color &msgInBgSelected(_palette.msgInBgSelected());
const style::color &msgOutBg(_palette.msgOutBg());
const style::color &msgOutBgSelected(_palette.msgOutBgSelected());
const style::color &msgSelectOverlay(_palette.msgSelectOverlay());
const style::color &msgStickerOverlay(_palette.msgStickerOverlay());
const style::color &msgInServiceFg(_palette.msgInServiceFg());
const style::color &msgInServiceFgSelected(_palette.msgInServiceFgSelected());
const style::color &msgOutServiceFg(_palette.msgOutServiceFg());
const style::color &msgOutServiceFgSelected(_palette.msgOutServiceFgSelected());
const style::color &msgInShadow(_palette.msgInShadow());
const style::color &msgInShadowSelected(_palette.msgInShadowSelected());
const style::color &msgOutShadow(_palette.msgOutShadow());
const style::color &msgOutShadowSelected(_palette.msgOutShadowSelected());
const style::color &msgInDateFg(_palette.msgInDateFg());
const style::color &msgInDateFgSelected(_palette.msgInDateFgSelected());
const style::color &msgOutDateFg(_palette.msgOutDateFg());
const style::color &msgOutDateFgSelected(_palette.msgOutDateFgSelected());
const style::color &msgServiceFg(_palette.msgServiceFg());
const style::color &msgServiceBg(_palette.msgServiceBg());
const style::color &msgServiceBgSelected(_palette.msgServiceBgSelected());
const style::color &msgInReplyBarColor(_palette.msgInReplyBarColor());
const style::color &msgInReplyBarSelColor(_palette.msgInReplyBarSelColor());
const style::color &msgOutReplyBarColor(_palette.msgOutReplyBarColor());
const style::color &msgOutReplyBarSelColor(_palette.msgOutReplyBarSelColor());
const style::color &msgImgReplyBarColor(_palette.msgImgReplyBarColor());
const style::color &msgInMonoFg(_palette.msgInMonoFg());
const style::color &msgOutMonoFg(_palette.msgOutMonoFg());
const style::color &msgInMonoFgSelected(_palette.msgInMonoFgSelected());
const style::color &msgOutMonoFgSelected(_palette.msgOutMonoFgSelected());
const style::color &msgDateImgFg(_palette.msgDateImgFg());
const style::color &msgDateImgBg(_palette.msgDateImgBg());
const style::color &msgDateImgBgOver(_palette.msgDateImgBgOver());
const style::color &msgDateImgBgSelected(_palette.msgDateImgBgSelected());
const style::color &msgFileThumbLinkInFg(_palette.msgFileThumbLinkInFg());
const style::color &msgFileThumbLinkInFgSelected(_palette.msgFileThumbLinkInFgSelected());
const style::color &msgFileThumbLinkOutFg(_palette.msgFileThumbLinkOutFg());
const style::color &msgFileThumbLinkOutFgSelected(_palette.msgFileThumbLinkOutFgSelected());
const style::color &msgFileInBg(_palette.msgFileInBg());
const style::color &msgFileInBgOver(_palette.msgFileInBgOver());
const style::color &msgFileInBgSelected(_palette.msgFileInBgSelected());
const style::color &msgFileOutBg(_palette.msgFileOutBg());
const style::color &msgFileOutBgSelected(_palette.msgFileOutBgSelected());
const style::color &msgFile1Bg(_palette.msgFile1Bg());
const style::color &msgFile1BgDark(_palette.msgFile1BgDark());
const style::color &msgFile1BgOver(_palette.msgFile1BgOver());
const style::color &msgFile1BgSelected(_palette.msgFile1BgSelected());
const style::color &msgFile2Bg(_palette.msgFile2Bg());
const style::color &msgFile2BgDark(_palette.msgFile2BgDark());
const style::color &msgFile2BgOver(_palette.msgFile2BgOver());
const style::color &msgFile2BgSelected(_palette.msgFile2BgSelected());
const style::color &msgFile3Bg(_palette.msgFile3Bg());
const style::color &msgFile3BgDark(_palette.msgFile3BgDark());
const style::color &msgFile3BgOver(_palette.msgFile3BgOver());
const style::color &msgFile3BgSelected(_palette.msgFile3BgSelected());
const style::color &msgFile4Bg(_palette.msgFile4Bg());
const style::color &msgFile4BgDark(_palette.msgFile4BgDark());
const style::color &msgFile4BgOver(_palette.msgFile4BgOver());
const style::color &msgFile4BgSelected(_palette.msgFile4BgSelected());
const style::color &historyFileInIconFg(_palette.historyFileInIconFg());
const style::color &historyFileInIconFgSelected(_palette.historyFileInIconFgSelected());
const style::color &historyFileInRadialFg(_palette.historyFileInRadialFg());
const style::color &historyFileInRadialFgSelected(_palette.historyFileInRadialFgSelected());
const style::color &historyFileOutIconFg(_palette.historyFileOutIconFg());
const style::color &historyFileOutIconFgSelected(_palette.historyFileOutIconFgSelected());
const style::color &historyFileOutRadialFg(_palette.historyFileOutRadialFg());
const style::color &historyFileOutRadialFgSelected(_palette.historyFileOutRadialFgSelected());
const style::color &historyFileThumbIconFg(_palette.historyFileThumbIconFg());
const style::color &historyFileThumbIconFgSelected(_palette.historyFileThumbIconFgSelected());
const style::color &historyFileThumbRadialFg(_palette.historyFileThumbRadialFg());
const style::color &historyFileThumbRadialFgSelected(_palette.historyFileThumbRadialFgSelected());
const style::color &historyVideoMessageProgressFg(_palette.historyVideoMessageProgressFg());
const style::color &msgWaveformInActive(_palette.msgWaveformInActive());
const style::color &msgWaveformInActiveSelected(_palette.msgWaveformInActiveSelected());
const style::color &msgWaveformInInactive(_palette.msgWaveformInInactive());
const style::color &msgWaveformInInactiveSelected(_palette.msgWaveformInInactiveSelected());
const style::color &msgWaveformOutActive(_palette.msgWaveformOutActive());
const style::color &msgWaveformOutActiveSelected(_palette.msgWaveformOutActiveSelected());
const style::color &msgWaveformOutInactive(_palette.msgWaveformOutInactive());
const style::color &msgWaveformOutInactiveSelected(_palette.msgWaveformOutInactiveSelected());
const style::color &msgBotKbOverBgAdd(_palette.msgBotKbOverBgAdd());
const style::color &msgBotKbIconFg(_palette.msgBotKbIconFg());
const style::color &msgBotKbRippleBg(_palette.msgBotKbRippleBg());
const style::color &mediaInFg(_palette.mediaInFg());
const style::color &mediaInFgSelected(_palette.mediaInFgSelected());
const style::color &mediaOutFg(_palette.mediaOutFg());
const style::color &mediaOutFgSelected(_palette.mediaOutFgSelected());
const style::color &youtubePlayIconBg(_palette.youtubePlayIconBg());
const style::color &youtubePlayIconFg(_palette.youtubePlayIconFg());
const style::color &videoPlayIconBg(_palette.videoPlayIconBg());
const style::color &videoPlayIconFg(_palette.videoPlayIconFg());
const style::color &toastBg(_palette.toastBg());
const style::color &toastFg(_palette.toastFg());
const style::color &historyToDownBg(_palette.historyToDownBg());
const style::color &historyToDownBgOver(_palette.historyToDownBgOver());
const style::color &historyToDownBgRipple(_palette.historyToDownBgRipple());
const style::color &historyToDownFg(_palette.historyToDownFg());
const style::color &historyToDownFgOver(_palette.historyToDownFgOver());
const style::color &historyToDownShadow(_palette.historyToDownShadow());
const style::color &historyComposeAreaBg(_palette.historyComposeAreaBg());
const style::color &historyComposeAreaFg(_palette.historyComposeAreaFg());
const style::color &historyComposeAreaFgService(_palette.historyComposeAreaFgService());
const style::color &historyComposeIconFg(_palette.historyComposeIconFg());
const style::color &historyComposeIconFgOver(_palette.historyComposeIconFgOver());
const style::color &historySendIconFg(_palette.historySendIconFg());
const style::color &historySendIconFgOver(_palette.historySendIconFgOver());
const style::color &historyPinnedBg(_palette.historyPinnedBg());
const style::color &historyReplyBg(_palette.historyReplyBg());
const style::color &historyReplyIconFg(_palette.historyReplyIconFg());
const style::color &historyReplyCancelFg(_palette.historyReplyCancelFg());
const style::color &historyReplyCancelFgOver(_palette.historyReplyCancelFgOver());
const style::color &historyComposeButtonBg(_palette.historyComposeButtonBg());
const style::color &historyComposeButtonBgOver(_palette.historyComposeButtonBgOver());
const style::color &historyComposeButtonBgRipple(_palette.historyComposeButtonBgRipple());
const style::color &mapPointDrop(_palette.mapPointDrop());
const style::color &mapPointDot(_palette.mapPointDot());
const style::color &overviewCheckBg(_palette.overviewCheckBg());
const style::color &overviewCheckBgActive(_palette.overviewCheckBgActive());
const style::color &overviewCheckBorder(_palette.overviewCheckBorder());
const style::color &overviewCheckFgActive(_palette.overviewCheckFgActive());
const style::color &overviewPhotoSelectOverlay(_palette.overviewPhotoSelectOverlay());
const style::color &profileStatusFgOver(_palette.profileStatusFgOver());
const style::color &profileVerifiedCheckBg(_palette.profileVerifiedCheckBg());
const style::color &profileVerifiedCheckFg(_palette.profileVerifiedCheckFg());
const style::color &profileAdminStartFg(_palette.profileAdminStartFg());
const style::color &notificationsBoxMonitorFg(_palette.notificationsBoxMonitorFg());
const style::color &notificationsBoxScreenBg(_palette.notificationsBoxScreenBg());
const style::color &notificationSampleUserpicFg(_palette.notificationSampleUserpicFg());
const style::color &notificationSampleCloseFg(_palette.notificationSampleCloseFg());
const style::color &notificationSampleTextFg(_palette.notificationSampleTextFg());
const style::color &notificationSampleNameFg(_palette.notificationSampleNameFg());
const style::color &mainMenuBg(_palette.mainMenuBg());
const style::color &mainMenuCoverBg(_palette.mainMenuCoverBg());
const style::color &mainMenuCloudFg(_palette.mainMenuCloudFg());
const style::color &mainMenuCloudBg(_palette.mainMenuCloudBg());
const style::color &mediaPlayerBg(_palette.mediaPlayerBg());
const style::color &mediaPlayerActiveFg(_palette.mediaPlayerActiveFg());
const style::color &mediaPlayerInactiveFg(_palette.mediaPlayerInactiveFg());
const style::color &mediaPlayerDisabledFg(_palette.mediaPlayerDisabledFg());
const style::color &mediaviewFileBg(_palette.mediaviewFileBg());
const style::color &mediaviewFileNameFg(_palette.mediaviewFileNameFg());
const style::color &mediaviewFileSizeFg(_palette.mediaviewFileSizeFg());
const style::color &mediaviewFileRedCornerFg(_palette.mediaviewFileRedCornerFg());
const style::color &mediaviewFileYellowCornerFg(_palette.mediaviewFileYellowCornerFg());
const style::color &mediaviewFileGreenCornerFg(_palette.mediaviewFileGreenCornerFg());
const style::color &mediaviewFileBlueCornerFg(_palette.mediaviewFileBlueCornerFg());
const style::color &mediaviewFileExtFg(_palette.mediaviewFileExtFg());
const style::color &mediaviewMenuBg(_palette.mediaviewMenuBg());
const style::color &mediaviewMenuBgOver(_palette.mediaviewMenuBgOver());
const style::color &mediaviewMenuBgRipple(_palette.mediaviewMenuBgRipple());
const style::color &mediaviewMenuFg(_palette.mediaviewMenuFg());
const style::color &mediaviewBg(_palette.mediaviewBg());
const style::color &mediaviewVideoBg(_palette.mediaviewVideoBg());
const style::color &mediaviewControlBg(_palette.mediaviewControlBg());
const style::color &mediaviewControlFg(_palette.mediaviewControlFg());
const style::color &mediaviewCaptionBg(_palette.mediaviewCaptionBg());
const style::color &mediaviewCaptionFg(_palette.mediaviewCaptionFg());
const style::color &mediaviewTextLinkFg(_palette.mediaviewTextLinkFg());
const style::color &mediaviewSaveMsgBg(_palette.mediaviewSaveMsgBg());
const style::color &mediaviewSaveMsgFg(_palette.mediaviewSaveMsgFg());
const style::color &mediaviewPlaybackActive(_palette.mediaviewPlaybackActive());
const style::color &mediaviewPlaybackInactive(_palette.mediaviewPlaybackInactive());
const style::color &mediaviewPlaybackActiveOver(_palette.mediaviewPlaybackActiveOver());
const style::color &mediaviewPlaybackInactiveOver(_palette.mediaviewPlaybackInactiveOver());
const style::color &mediaviewPlaybackProgressFg(_palette.mediaviewPlaybackProgressFg());
const style::color &mediaviewPlaybackIconFg(_palette.mediaviewPlaybackIconFg());
const style::color &mediaviewPlaybackIconFgOver(_palette.mediaviewPlaybackIconFgOver());
const style::color &mediaviewPlaybackIconRipple(_palette.mediaviewPlaybackIconRipple());
const style::color &mediaviewPipControlsFg(_palette.mediaviewPipControlsFg());
const style::color &mediaviewPipControlsFgOver(_palette.mediaviewPipControlsFgOver());
const style::color &mediaviewPipPlaybackActive(_palette.mediaviewPipPlaybackActive());
const style::color &mediaviewPipPlaybackInactive(_palette.mediaviewPipPlaybackInactive());
const style::color &mediaviewTransparentBg(_palette.mediaviewTransparentBg());
const style::color &mediaviewTransparentFg(_palette.mediaviewTransparentFg());
const style::color &notificationBg(_palette.notificationBg());
const style::color &callBg(_palette.callBg());
const style::color &callBgOpaque(_palette.callBgOpaque());
const style::color &callBgButton(_palette.callBgButton());
const style::color &callNameFg(_palette.callNameFg());
const style::color &callStatusFg(_palette.callStatusFg());
const style::color &callIconBg(_palette.callIconBg());
const style::color &callIconFg(_palette.callIconFg());
const style::color &callIconBgActive(_palette.callIconBgActive());
const style::color &callIconFgActive(_palette.callIconFgActive());
const style::color &callIconActiveRipple(_palette.callIconActiveRipple());
const style::color &callAnswerBg(_palette.callAnswerBg());
const style::color &callAnswerRipple(_palette.callAnswerRipple());
const style::color &callAnswerBgOuter(_palette.callAnswerBgOuter());
const style::color &callHangupBg(_palette.callHangupBg());
const style::color &callHangupRipple(_palette.callHangupRipple());
const style::color &callMuteRipple(_palette.callMuteRipple());
const style::color &groupCallBg(_palette.groupCallBg());
const style::color &groupCallActiveFg(_palette.groupCallActiveFg());
const style::color &groupCallMembersBg(_palette.groupCallMembersBg());
const style::color &groupCallMembersBgOver(_palette.groupCallMembersBgOver());
const style::color &groupCallMembersBgRipple(_palette.groupCallMembersBgRipple());
const style::color &groupCallMembersFg(_palette.groupCallMembersFg());
const style::color &groupCallMemberActiveIcon(_palette.groupCallMemberActiveIcon());
const style::color &groupCallMemberActiveStatus(_palette.groupCallMemberActiveStatus());
const style::color &groupCallMemberInactiveIcon(_palette.groupCallMemberInactiveIcon());
const style::color &groupCallMemberInactiveStatus(_palette.groupCallMemberInactiveStatus());
const style::color &groupCallMemberMutedIcon(_palette.groupCallMemberMutedIcon());
const style::color &groupCallMemberNotJoinedStatus(_palette.groupCallMemberNotJoinedStatus());
const style::color &groupCallIconFg(_palette.groupCallIconFg());
const style::color &groupCallLive1(_palette.groupCallLive1());
const style::color &groupCallLive2(_palette.groupCallLive2());
const style::color &groupCallMuted1(_palette.groupCallMuted1());
const style::color &groupCallMuted2(_palette.groupCallMuted2());
const style::color &groupCallForceMutedBar1(_palette.groupCallForceMutedBar1());
const style::color &groupCallForceMutedBar2(_palette.groupCallForceMutedBar2());
const style::color &groupCallForceMutedBar3(_palette.groupCallForceMutedBar3());
const style::color &groupCallForceMuted1(_palette.groupCallForceMuted1());
const style::color &groupCallForceMuted2(_palette.groupCallForceMuted2());
const style::color &groupCallForceMuted3(_palette.groupCallForceMuted3());
const style::color &groupCallMenuBg(_palette.groupCallMenuBg());
const style::color &groupCallMenuBgOver(_palette.groupCallMenuBgOver());
const style::color &groupCallMenuBgRipple(_palette.groupCallMenuBgRipple());
const style::color &groupCallLeaveBg(_palette.groupCallLeaveBg());
const style::color &groupCallLeaveBgRipple(_palette.groupCallLeaveBgRipple());
const style::color &groupCallVideoTextFg(_palette.groupCallVideoTextFg());
const style::color &groupCallVideoSubTextFg(_palette.groupCallVideoSubTextFg());
const style::color &callBarBg(_palette.callBarBg());
const style::color &callBarMuteRipple(_palette.callBarMuteRipple());
const style::color &callBarBgMuted(_palette.callBarBgMuted());
const style::color &callBarFg(_palette.callBarFg());
const style::color &importantTooltipBg(_palette.importantTooltipBg());
const style::color &importantTooltipFg(_palette.importantTooltipFg());
const style::color &importantTooltipFgLink(_palette.importantTooltipFgLink());
const style::color &outdatedFg(_palette.outdatedFg());
const style::color &outdateSoonBg(_palette.outdateSoonBg());
const style::color &outdatedBg(_palette.outdatedBg());
const style::color &spellUnderline(_palette.spellUnderline());
const style::color &walletTitleBg(_palette.walletTitleBg());
const style::color &walletTitleBgActive(_palette.walletTitleBgActive());
const style::color &walletTitleButtonBg(_palette.walletTitleButtonBg());
const style::color &walletTitleButtonFg(_palette.walletTitleButtonFg());
const style::color &walletTitleButtonBgOver(_palette.walletTitleButtonBgOver());
const style::color &walletTitleButtonFgOver(_palette.walletTitleButtonFgOver());
const style::color &walletTitleButtonBgActive(_palette.walletTitleButtonBgActive());
const style::color &walletTitleButtonFgActive(_palette.walletTitleButtonFgActive());
const style::color &walletTitleButtonBgActiveOver(_palette.walletTitleButtonBgActiveOver());
const style::color &walletTitleButtonFgActiveOver(_palette.walletTitleButtonFgActiveOver());
const style::color &walletTitleButtonCloseBg(_palette.walletTitleButtonCloseBg());
const style::color &walletTitleButtonCloseFg(_palette.walletTitleButtonCloseFg());
const style::color &walletTitleButtonCloseBgOver(_palette.walletTitleButtonCloseBgOver());
const style::color &walletTitleButtonCloseFgOver(_palette.walletTitleButtonCloseFgOver());
const style::color &walletTitleButtonCloseBgActive(_palette.walletTitleButtonCloseBgActive());
const style::color &walletTitleButtonCloseFgActive(_palette.walletTitleButtonCloseFgActive());
const style::color &walletTitleButtonCloseBgActiveOver(_palette.walletTitleButtonCloseBgActiveOver());
const style::color &walletTitleButtonCloseFgActiveOver(_palette.walletTitleButtonCloseFgActiveOver());
const style::color &walletTopBg(_palette.walletTopBg());
const style::color &walletBalanceFg(_palette.walletBalanceFg());
const style::color &walletSubBalanceFg(_palette.walletSubBalanceFg());
const style::color &walletTopLabelFg(_palette.walletTopLabelFg());
const style::color &walletTopIconFg(_palette.walletTopIconFg());
const style::color &walletTopIconRipple(_palette.walletTopIconRipple());
const style::color &sideBarBg(_palette.sideBarBg());
const style::color &sideBarBgActive(_palette.sideBarBgActive());
const style::color &sideBarBgRipple(_palette.sideBarBgRipple());
const style::color &sideBarTextFg(_palette.sideBarTextFg());
const style::color &sideBarTextFgActive(_palette.sideBarTextFgActive());
const style::color &sideBarIconFg(_palette.sideBarIconFg());
const style::color &sideBarIconFgActive(_palette.sideBarIconFgActive());
const style::color &sideBarBadgeBg(_palette.sideBarBadgeBg());
const style::color &sideBarBadgeBgActive(_palette.sideBarBadgeBgActive());
const style::color &sideBarBadgeBgMuted(_palette.sideBarBadgeBgMuted());
const style::color &sideBarBadgeBgMutedActive(_palette.sideBarBadgeBgMutedActive());
const style::color &sideBarBadgeFg(_palette.sideBarBadgeFg());
const style::color &songCoverOverlayFg(_palette.songCoverOverlayFg());
const style::color &photoEditorItemBaseHandleFg(_palette.photoEditorItemBaseHandleFg());
const style::color &premiumButtonBg1(_palette.premiumButtonBg1());
const style::color &premiumButtonBg2(_palette.premiumButtonBg2());
const style::color &premiumButtonBg3(_palette.premiumButtonBg3());
const style::color &premiumButtonFg(_palette.premiumButtonFg());
const style::color &premiumIconBg1(_palette.premiumIconBg1());
const style::color &premiumIconBg2(_palette.premiumIconBg2());
const style::color &premiumIconBg3(_palette.premiumIconBg3());
const style::color &statisticsChartInactive(_palette.statisticsChartInactive());
const style::color &statisticsChartActive(_palette.statisticsChartActive());
const style::color &statisticsChartLineBlue(_palette.statisticsChartLineBlue());
const style::color &statisticsChartLineGreen(_palette.statisticsChartLineGreen());
const style::color &statisticsChartLineRed(_palette.statisticsChartLineRed());
const style::color &statisticsChartLineGolden(_palette.statisticsChartLineGolden());
const style::color &statisticsChartLineLightblue(_palette.statisticsChartLineLightblue());
const style::color &statisticsChartLineLightgreen(_palette.statisticsChartLineLightgreen());
const style::color &statisticsChartLineOrange(_palette.statisticsChartLineOrange());
const style::color &statisticsChartLineIndigo(_palette.statisticsChartLineIndigo());
const style::color &statisticsChartLinePurple(_palette.statisticsChartLinePurple());
const style::color &statisticsChartLineCyan(_palette.statisticsChartLineCyan());
const style::color &creditsBg1(_palette.creditsBg1());
const style::color &creditsBg2(_palette.creditsBg2());
const style::color &creditsBg3(_palette.creditsBg3());
const style::color &creditsFg(_palette.creditsFg());
const style::color &creditsStroke(_palette.creditsStroke());
const style::color &currencyFg(_palette.currencyFg());
const style::color &rankAdminFg(_palette.rankAdminFg());
const style::color &rankOwnerFg(_palette.rankOwnerFg());
const style::color &rankUserFg(_palette.rankUserFg());
const style::color &dialogsMentionIconFg(_palette.dialogsMentionIconFg());
const style::color &dialogsReactionIconFg(_palette.dialogsReactionIconFg());
const style::color &dialogsPollIconFg(_palette.dialogsPollIconFg());
} // namespace st

namespace style {

void palette_data::finalize(palette &that) {
	that.compute(0, -1, { 255, 255, 255, 0}); // special color transparent
	that.compute(1, -1, { 255, 255, 255, 255}); // special color white
	that.compute(2, -1, { 255, 255, 255, 255 });
	that.compute(3, -1, { 0, 0, 0, 255 });
	that.compute(4, -1, { 241, 241, 241, 255 });
	that.compute(5, -1, { 229, 229, 229, 255 });
	that.compute(6, 3, { 0, 0, 0, 255 });
	that.compute(7, -1, { 153, 153, 153, 255 });
	that.compute(8, -1, { 145, 145, 145, 255 });
	that.compute(9, -1, { 34, 34, 34, 255 });
	that.compute(10, -1, { 34, 34, 34, 255 });
	that.compute(11, -1, { 64, 167, 227, 255 });
	that.compute(12, -1, { 255, 255, 255, 255 });
	that.compute(13, -1, { 22, 138, 205, 255 });
	that.compute(14, -1, { 0, 0, 0, 255 });
	that.compute(15, -1, { 241, 241, 241, 255 });
	that.compute(16, -1, { 0, 0, 0, 24 });
	that.compute(17, -1, { 0, 0, 0, 60 });
	that.compute(18, 14, { 0, 0, 0, 255 });
	that.compute(19, -1, { 0, 0, 0, 255 });
	that.compute(20, -1, { 255, 255, 255, 255 });
	that.compute(21, 11, { 64, 167, 227, 255 });
	that.compute(22, -1, { 57, 165, 219, 255 });
	that.compute(23, -1, { 32, 149, 208, 255 });
	that.compute(24, 12, { 255, 255, 255, 255 });
	that.compute(25, 24, { 255, 255, 255, 255 });
	that.compute(26, -1, { 204, 238, 255, 255 });
	that.compute(27, 26, { 204, 238, 255, 255 });
	that.compute(28, -1, { 55, 161, 222, 255 });
	that.compute(29, -1, { 228, 131, 131, 255 });
	that.compute(30, 2, { 255, 255, 255, 255 });
	that.compute(31, -1, { 227, 241, 250, 255 });
	that.compute(32, -1, { 201, 228, 246, 255 });
	that.compute(33, 13, { 22, 138, 205, 255 });
	that.compute(34, 33, { 22, 138, 205, 255 });
	that.compute(35, -1, { 209, 78, 78, 255 });
	that.compute(36, -1, { 209, 78, 78, 255 });
	that.compute(37, -1, { 252, 223, 222, 255 });
	that.compute(38, -1, { 244, 195, 194, 255 });
	that.compute(39, 2, { 255, 255, 255, 255 });
	that.compute(40, 4, { 241, 241, 241, 255 });
	that.compute(41, 5, { 229, 229, 229, 255 });
	that.compute(42, -1, { 153, 153, 153, 255 });
	that.compute(43, -1, { 138, 138, 138, 255 });
	that.compute(44, -1, { 55, 55, 55, 255 });
	that.compute(45, -1, { 204, 204, 204, 255 });
	that.compute(46, -1, { 241, 241, 241, 255 });
	that.compute(47, -1, { 0, 0, 0, 83 });
	that.compute(48, -1, { 0, 0, 0, 122 });
	that.compute(49, -1, { 0, 0, 0, 26 });
	that.compute(50, -1, { 0, 0, 0, 44 });
	that.compute(51, -1, { 199, 199, 199, 255 });
	that.compute(52, -1, { 163, 163, 163, 255 });
	that.compute(53, 12, { 255, 255, 255, 255 });
	that.compute(54, -1, { 0, 0, 0, 86 });
	that.compute(55, 7, { 153, 153, 153, 255 });
	that.compute(56, -1, { 170, 170, 170, 255 });
	that.compute(57, -1, { 224, 224, 224, 255 });
	that.compute(58, -1, { 84, 195, 243, 255 });
	that.compute(59, 2, { 255, 255, 255, 255 });
	that.compute(60, 4, { 241, 241, 241, 255 });
	that.compute(61, -1, { 179, 179, 179, 255 });
	that.compute(62, 40, { 241, 241, 241, 255 });
	that.compute(63, 41, { 229, 229, 229, 255 });
	that.compute(64, 10, { 34, 34, 34, 255 });
	that.compute(65, -1, { 41, 138, 207, 204 });
	that.compute(66, -1, { 224, 83, 86, 204 });
	that.compute(67, -1, { 97, 199, 82, 204 });
	that.compute(68, -1, { 55, 142, 174, 179 });
	that.compute(69, -1, { 201, 84, 62, 179 });
	that.compute(70, -1, { 72, 157, 56, 179 });
	that.compute(71, -1, { 225, 234, 239, 255 });
	that.compute(72, 11, { 64, 167, 227, 255 });
	that.compute(73, -1, { 238, 242, 245, 255 });
	that.compute(74, -1, { 93, 108, 128, 255 });
	that.compute(75, -1, { 201, 209, 219, 255 });
	that.compute(76, -1, { 0, 0, 0, 3 });
	that.compute(77, 4, { 241, 241, 241, 255 });
	that.compute(78, 77, { 241, 241, 241, 255 });
	that.compute(79, 77, { 241, 241, 241, 255 });
	that.compute(80, -1, { 171, 171, 171, 255 });
	that.compute(81, -1, { 229, 229, 229, 255 });
	that.compute(82, -1, { 154, 154, 154, 255 });
	that.compute(83, 79, { 241, 241, 241, 255 });
	that.compute(84, 80, { 171, 171, 171, 255 });
	that.compute(85, 81, { 229, 229, 229, 255 });
	that.compute(86, 82, { 154, 154, 154, 255 });
	that.compute(87, 79, { 241, 241, 241, 255 });
	that.compute(88, 80, { 171, 171, 171, 255 });
	that.compute(89, -1, { 232, 17, 35, 255 });
	that.compute(90, 12, { 255, 255, 255, 255 });
	that.compute(91, 87, { 241, 241, 241, 255 });
	that.compute(92, 88, { 171, 171, 171, 255 });
	that.compute(93, 89, { 232, 17, 35, 255 });
	that.compute(94, 90, { 255, 255, 255, 255 });
	that.compute(95, -1, { 172, 172, 172, 255 });
	that.compute(96, -1, { 62, 60, 62, 255 });
	that.compute(97, -1, { 242, 60, 52, 255 });
	that.compute(98, -1, { 136, 136, 136, 255 });
	that.compute(99, -1, { 255, 255, 255, 255 });
	that.compute(100, -1, { 255, 255, 255, 255 });
	that.compute(101, -1, { 255, 255, 255, 1 });
	that.compute(102, -1, { 0, 0, 0, 127 });
	that.compute(103, 42, { 153, 153, 153, 255 });
	that.compute(104, 43, { 138, 138, 138, 255 });
	that.compute(105, 2, { 255, 255, 255, 255 });
	that.compute(106, 3, { 0, 0, 0, 255 });
	that.compute(107, -1, { 74, 180, 74, 255 });
	that.compute(108, -1, { 216, 77, 77, 255 });
	that.compute(109, -1, { 64, 64, 64, 255 });
	that.compute(110, 105, { 255, 255, 255, 255 });
	that.compute(111, -1, { 128, 128, 128, 255 });
	that.compute(112, 103, { 153, 153, 153, 255 });
	that.compute(113, 104, { 138, 138, 138, 255 });
	that.compute(114, 4, { 241, 241, 241, 255 });
	that.compute(115, 14, { 0, 0, 0, 255 });
	that.compute(116, -1, { 1, 173, 15, 255 });
	that.compute(117, 8, { 145, 145, 145, 255 });
	that.compute(118, 2, { 255, 255, 255, 255 });
	that.compute(119, 4, { 241, 241, 241, 255 });
	that.compute(120, 106, { 0, 0, 0, 255 });
	that.compute(121, 7, { 153, 153, 153, 255 });
	that.compute(122, 8, { 145, 145, 145, 255 });
	that.compute(123, 13, { 22, 138, 205, 255 });
	that.compute(124, 102, { 0, 0, 0, 127 });
	that.compute(125, -1, { 255, 255, 255, 127 });
	that.compute(126, 107, { 45, 173, 45, 255 });
	that.compute(127, 108, { 221, 91, 74, 255 });
	that.compute(128, 2, { 255, 255, 255, 255 });
	that.compute(129, 9, { 34, 34, 34, 255 });
	that.compute(130, 7, { 153, 153, 153, 255 });
	that.compute(131, -1, { 15, 137, 208, 255 });
	that.compute(132, -1, { 57, 176, 240, 255 });
	that.compute(133, -1, { 94, 198, 255, 255 });
	that.compute(134, -1, { 94, 198, 255, 105 });
	that.compute(135, -1, { 198, 216, 232, 255 });
	that.compute(136, -1, { 161, 190, 212, 255 });
	that.compute(137, -1, { 255, 255, 255, 255 });
	that.compute(138, 42, { 153, 153, 153, 255 });
	that.compute(139, 43, { 138, 138, 138, 255 });
	that.compute(140, 2, { 255, 255, 255, 255 });
	that.compute(141, 9, { 34, 34, 34, 255 });
	that.compute(142, 141, { 34, 34, 34, 255 });
	that.compute(143, 7, { 153, 153, 153, 255 });
	that.compute(144, 7, { 153, 153, 153, 255 });
	that.compute(145, 13, { 22, 138, 205, 255 });
	that.compute(146, -1, { 221, 75, 57, 255 });
	that.compute(147, 11, { 64, 167, 227, 255 });
	that.compute(148, 12, { 255, 255, 255, 255 });
	that.compute(149, -1, { 193, 193, 193, 255 });
	that.compute(150, -1, { 93, 196, 82, 255 });
	that.compute(151, 11, { 64, 167, 227, 255 });
	that.compute(152, -1, { 187, 187, 187, 255 });
	that.compute(153, 12, { 255, 255, 255, 255 });
	that.compute(154, 141, { 82, 82, 82, 255 });
	that.compute(155, 151, { 77, 201, 32, 255 });
	that.compute(156, 146, { 221, 75, 57, 255 });
	that.compute(157, 4, { 241, 241, 241, 255 });
	that.compute(158, 10, { 34, 34, 34, 255 });
	that.compute(159, 158, { 34, 34, 34, 255 });
	that.compute(160, 8, { 145, 145, 145, 255 });
	that.compute(161, 8, { 145, 145, 145, 255 });
	that.compute(162, 145, { 22, 138, 205, 255 });
	that.compute(163, 146, { 221, 75, 57, 255 });
	that.compute(164, 147, { 64, 167, 227, 255 });
	that.compute(165, 148, { 255, 255, 255, 255 });
	that.compute(166, 149, { 193, 193, 193, 255 });
	that.compute(167, -1, { 88, 184, 77, 255 });
	that.compute(168, 151, { 64, 167, 227, 255 });
	that.compute(169, 152, { 187, 187, 187, 255 });
	that.compute(170, 153, { 255, 255, 255, 255 });
	that.compute(171, 158, { 82, 82, 82, 255 });
	that.compute(172, 163, { 221, 75, 57, 255 });
	that.compute(173, -1, { 65, 159, 217, 255 });
	that.compute(174, 12, { 255, 255, 255, 255 });
	that.compute(175, 174, { 255, 255, 255, 255 });
	that.compute(176, 12, { 255, 255, 255, 255 });
	that.compute(177, 12, { 255, 255, 255, 255 });
	that.compute(178, 177, { 255, 255, 255, 255 });
	that.compute(179, -1, { 198, 225, 247, 255 });
	that.compute(180, 177, { 255, 255, 255, 255 });
	that.compute(181, 173, { 65, 159, 217, 255 });
	that.compute(182, -1, { 255, 255, 255, 153 });
	that.compute(183, 177, { 255, 255, 255, 255 });
	that.compute(184, 177, { 255, 255, 255, 255 });
	that.compute(185, 179, { 198, 225, 247, 255 });
	that.compute(186, 173, { 65, 159, 217, 255 });
	that.compute(187, -1, { 255, 255, 255, 255 });
	that.compute(188, 179, { 198, 225, 247, 255 });
	that.compute(189, 5, { 229, 229, 229, 255 });
	that.compute(190, 23, { 32, 149, 208, 255 });
	that.compute(191, 4, { 241, 241, 241, 255 });
	that.compute(192, 8, { 145, 145, 145, 255 });
	that.compute(193, -1, { 255, 252, 103, 255 });
	that.compute(194, -1, { 0, 0, 0, 255 });
	that.compute(195, -1, { 245, 171, 92, 255 });
	that.compute(196, -1, { 0, 0, 0, 255 });
	that.compute(197, 2, { 255, 255, 255, 255 });
	that.compute(198, 2, { 255, 255, 255, 255 });
	that.compute(199, 2, { 247, 247, 247, 255 });
	that.compute(200, 7, { 153, 153, 153, 255 });
	that.compute(201, 198, { 255, 255, 255, 242 });
	that.compute(202, -1, { 153, 153, 153, 255 });
	that.compute(203, 9, { 102, 102, 102, 255 });
	that.compute(204, -1, { 0, 0, 0, 255 });
	that.compute(205, 12, { 255, 255, 255, 255 });
	that.compute(206, -1, { 255, 255, 255, 176 });
	that.compute(207, -1, { 90, 153, 255, 255 });
	that.compute(208, -1, { 69, 185, 243, 255 });
	that.compute(209, 3, { 0, 0, 0, 255 });
	that.compute(210, 209, { 0, 0, 0, 255 });
	that.compute(211, 3, { 0, 0, 0, 255 });
	that.compute(212, 211, { 0, 0, 0, 255 });
	that.compute(213, 13, { 22, 138, 205, 255 });
	that.compute(214, 213, { 22, 138, 205, 255 });
	that.compute(215, 13, { 22, 138, 205, 255 });
	that.compute(216, 215, { 22, 138, 205, 255 });
	that.compute(217, 209, { 0, 0, 0, 255 });
	that.compute(218, 217, { 0, 0, 0, 255 });
	that.compute(219, 211, { 0, 0, 0, 255 });
	that.compute(220, 219, { 0, 0, 0, 255 });
	that.compute(221, -1, { 87, 184, 76, 255 });
	that.compute(222, -1, { 69, 163, 170, 255 });
	that.compute(223, 12, { 255, 255, 255, 255 });
	that.compute(224, -1, { 152, 210, 146, 255 });
	that.compute(225, -1, { 160, 173, 181, 255 });
	that.compute(226, -1, { 255, 255, 255, 200 });
	that.compute(227, -1, { 50, 176, 50, 255 });
	that.compute(228, -1, { 37, 146, 168, 255 });
	that.compute(229, 127, { 221, 91, 74, 255 });
	that.compute(230, 127, { 221, 91, 74, 255 });
	that.compute(231, 227, { 50, 176, 50, 255 });
	that.compute(232, 228, { 37, 146, 168, 255 });
	that.compute(233, -1, { 252, 251, 250, 255 });
	that.compute(234, 16, { 0, 0, 0, 24 });
	that.compute(235, -1, { 83, 139, 180, 255 });
	that.compute(236, -1, { 0, 0, 0, 76 });
	that.compute(237, 12, { 255, 255, 255, 255 });
	that.compute(238, -1, { 192, 61, 51, 255 });
	that.compute(239, 238, { 192, 61, 51, 255 });
	that.compute(240, -1, { 255, 132, 94, 255 });
	that.compute(241, -1, { 79, 173, 45, 255 });
	that.compute(242, 241, { 79, 173, 45, 255 });
	that.compute(243, -1, { 154, 209, 100, 255 });
	that.compute(244, -1, { 208, 147, 6, 255 });
	that.compute(245, 244, { 208, 147, 6, 255 });
	that.compute(246, -1, { 229, 202, 119, 255 });
	that.compute(247, 13, { 22, 138, 205, 255 });
	that.compute(248, 247, { 22, 138, 205, 255 });
	that.compute(249, -1, { 92, 175, 250, 255 });
	that.compute(250, -1, { 133, 68, 214, 255 });
	that.compute(251, 250, { 133, 68, 214, 255 });
	that.compute(252, -1, { 182, 148, 249, 255 });
	that.compute(253, -1, { 205, 64, 115, 255 });
	that.compute(254, 253, { 205, 64, 115, 255 });
	that.compute(255, -1, { 255, 138, 172, 255 });
	that.compute(256, -1, { 41, 150, 173, 255 });
	that.compute(257, 256, { 41, 150, 173, 255 });
	that.compute(258, -1, { 91, 203, 227, 255 });
	that.compute(259, -1, { 206, 103, 27, 255 });
	that.compute(260, 259, { 206, 103, 27, 255 });
	that.compute(261, -1, { 254, 187, 91, 255 });
	that.compute(262, 12, { 255, 255, 255, 255 });
	that.compute(263, 249, { 92, 175, 250, 255 });
	that.compute(264, 152, { 187, 187, 187, 255 });
	that.compute(265, 240, { 212, 82, 70, 255 });
	that.compute(266, 243, { 70, 186, 67, 255 });
	that.compute(267, 246, { 229, 202, 119, 255 });
	that.compute(268, 249, { 64, 138, 207, 255 });
	that.compute(269, 252, { 108, 97, 223, 255 });
	that.compute(270, 255, { 217, 85, 116, 255 });
	that.compute(271, 258, { 53, 154, 212, 255 });
	that.compute(272, 261, { 246, 129, 54, 255 });
	that.compute(273, 268, { 64, 138, 207, 255 });
	that.compute(274, -1, { 240, 105, 100, 255 });
	that.compute(275, -1, { 109, 197, 52, 255 });
	that.compute(276, -1, { 237, 159, 32, 255 });
	that.compute(277, -1, { 86, 179, 245, 255 });
	that.compute(278, -1, { 117, 149, 255, 255 });
	that.compute(279, -1, { 181, 128, 226, 255 });
	that.compute(280, -1, { 242, 146, 91, 255 });
	that.compute(281, -1, { 157, 162, 176, 255 });
	that.compute(282, -1, { 255, 255, 255, 255 });
	that.compute(283, -1, { 81, 124, 65, 122 });
	that.compute(284, -1, { 81, 124, 65, 188 });
	that.compute(285, -1, { 81, 124, 65, 76 });
	that.compute(286, -1, { 81, 124, 65, 107 });
	that.compute(287, 2, { 255, 255, 255, 255 });
	that.compute(288, -1, { 194, 220, 242, 255 });
	that.compute(289, -1, { 239, 253, 222, 255 });
	that.compute(290, -1, { 183, 219, 219, 255 });
	that.compute(291, -1, { 53, 140, 212, 76 });
	that.compute(292, -1, { 53, 140, 212, 127 });
	that.compute(293, 13, { 22, 138, 205, 255 });
	that.compute(294, 13, { 22, 138, 205, 255 });
	that.compute(295, -1, { 69, 163, 45, 255 });
	that.compute(296, -1, { 70, 153, 146, 255 });
	that.compute(297, -1, { 116, 142, 162, 41 });
	that.compute(298, -1, { 84, 141, 187, 41 });
	that.compute(299, -1, { 58, 195, 70, 29 });
	that.compute(300, -1, { 55, 167, 141, 34 });
	that.compute(301, -1, { 160, 172, 182, 255 });
	that.compute(302, -1, { 106, 156, 197, 255 });
	that.compute(303, -1, { 109, 181, 102, 255 });
	that.compute(304, -1, { 86, 178, 166, 255 });
	that.compute(305, 12, { 255, 255, 255, 255 });
	that.compute(306, -1, { 81, 124, 65, 127 });
	that.compute(307, -1, { 150, 179, 139, 162 });
	that.compute(308, 28, { 55, 161, 222, 255 });
	that.compute(309, 28, { 55, 161, 222, 255 });
	that.compute(310, -1, { 94, 184, 84, 255 });
	that.compute(311, 222, { 69, 163, 170, 255 });
	that.compute(312, 305, { 255, 255, 255, 255 });
	that.compute(313, -1, { 78, 115, 145, 255 });
	that.compute(314, -1, { 69, 152, 102, 255 });
	that.compute(315, 313, { 78, 115, 145, 255 });
	that.compute(316, 314, { 69, 152, 102, 255 });
	that.compute(317, 305, { 255, 255, 255, 255 });
	that.compute(318, -1, { 0, 0, 0, 84 });
	that.compute(319, -1, { 0, 0, 0, 116 });
	that.compute(320, -1, { 28, 74, 113, 135 });
	that.compute(321, 33, { 22, 138, 205, 255 });
	that.compute(322, 34, { 22, 138, 205, 255 });
	that.compute(323, -1, { 75, 168, 49, 255 });
	that.compute(324, -1, { 49, 162, 152, 255 });
	that.compute(325, 11, { 64, 167, 227, 255 });
	that.compute(326, -1, { 78, 173, 227, 255 });
	that.compute(327, -1, { 81, 163, 211, 255 });
	that.compute(328, -1, { 95, 190, 103, 255 });
	that.compute(329, -1, { 80, 172, 155, 255 });
	that.compute(330, -1, { 114, 177, 223, 255 });
	that.compute(331, -1, { 92, 158, 206, 255 });
	that.compute(332, -1, { 82, 148, 196, 255 });
	that.compute(333, -1, { 80, 153, 208, 255 });
	that.compute(334, -1, { 95, 190, 103, 255 });
	that.compute(335, -1, { 77, 168, 89, 255 });
	that.compute(336, -1, { 68, 160, 80, 255 });
	that.compute(337, -1, { 80, 172, 155, 255 });
	that.compute(338, -1, { 228, 114, 114, 255 });
	that.compute(339, -1, { 205, 91, 94, 255 });
	that.compute(340, -1, { 195, 81, 84, 255 });
	that.compute(341, -1, { 159, 106, 130, 255 });
	that.compute(342, -1, { 239, 194, 116, 255 });
	that.compute(343, -1, { 230, 165, 97, 255 });
	that.compute(344, -1, { 220, 156, 90, 255 });
	that.compute(345, -1, { 177, 157, 132, 255 });
	that.compute(346, 287, { 255, 255, 255, 255 });
	that.compute(347, 288, { 194, 220, 242, 255 });
	that.compute(348, 346, { 255, 255, 255, 255 });
	that.compute(349, 347, { 194, 220, 242, 255 });
	that.compute(350, 289, { 239, 253, 222, 255 });
	that.compute(351, 290, { 183, 219, 219, 255 });
	that.compute(352, 350, { 239, 253, 222, 255 });
	that.compute(353, 351, { 183, 219, 219, 255 });
	that.compute(354, 287, { 255, 255, 255, 255 });
	that.compute(355, 288, { 194, 220, 242, 255 });
	that.compute(356, 354, { 255, 255, 255, 255 });
	that.compute(357, 355, { 194, 220, 242, 255 });
	that.compute(358, 354, { 255, 255, 255, 255 });
	that.compute(359, 11, { 64, 167, 227, 255 });
	that.compute(360, -1, { 81, 163, 211, 255 });
	that.compute(361, -1, { 212, 222, 230, 255 });
	that.compute(362, -1, { 156, 193, 225, 255 });
	that.compute(363, -1, { 94, 189, 102, 255 });
	that.compute(364, -1, { 107, 173, 173, 255 });
	that.compute(365, -1, { 179, 226, 180, 255 });
	that.compute(366, -1, { 145, 195, 195, 255 });
	that.compute(367, -1, { 255, 255, 255, 32 });
	that.compute(368, 305, { 255, 255, 255, 255 });
	that.compute(369, -1, { 0, 0, 0, 32 });
	that.compute(370, 301, { 160, 172, 182, 255 });
	that.compute(371, 302, { 106, 156, 197, 255 });
	that.compute(372, 303, { 109, 181, 102, 255 });
	that.compute(373, 304, { 86, 178, 166, 255 });
	that.compute(374, -1, { 232, 49, 49, 200 });
	that.compute(375, 12, { 255, 255, 255, 255 });
	that.compute(376, -1, { 0, 0, 0, 127 });
	that.compute(377, -1, { 255, 255, 255, 255 });
	that.compute(378, -1, { 44, 48, 51, 229 });
	that.compute(379, -1, { 255, 255, 255, 255 });
	that.compute(380, 2, { 255, 255, 255, 255 });
	that.compute(381, 4, { 241, 241, 241, 255 });
	that.compute(382, 5, { 229, 229, 229, 255 });
	that.compute(383, 42, { 153, 153, 153, 255 });
	that.compute(384, 43, { 138, 138, 138, 255 });
	that.compute(385, -1, { 0, 0, 0, 64 });
	that.compute(386, 287, { 255, 255, 255, 255 });
	that.compute(387, 209, { 0, 0, 0, 255 });
	that.compute(388, 301, { 160, 172, 182, 255 });
	that.compute(389, 42, { 153, 153, 153, 255 });
	that.compute(390, 43, { 138, 138, 138, 255 });
	that.compute(391, 11, { 64, 167, 227, 255 });
	that.compute(392, 11, { 64, 167, 227, 255 });
	that.compute(393, 386, { 255, 255, 255, 255 });
	that.compute(394, 386, { 255, 255, 255, 255 });
	that.compute(395, 11, { 64, 167, 227, 255 });
	that.compute(396, 103, { 153, 153, 153, 255 });
	that.compute(397, 104, { 138, 138, 138, 255 });
	that.compute(398, 386, { 255, 255, 255, 255 });
	that.compute(399, 4, { 241, 241, 241, 255 });
	that.compute(400, 5, { 229, 229, 229, 255 });
	that.compute(401, -1, { 253, 68, 68, 255 });
	that.compute(402, -1, { 255, 255, 255, 255 });
	that.compute(403, -1, { 0, 0, 0, 64 });
	that.compute(404, 11, { 64, 167, 227, 255 });
	that.compute(405, 2, { 255, 255, 255, 255 });
	that.compute(406, 2, { 255, 255, 255, 255 });
	that.compute(407, -1, { 64, 172, 227, 51 });
	that.compute(408, -1, { 124, 153, 178, 255 });
	that.compute(409, 11, { 64, 167, 227, 255 });
	that.compute(410, 12, { 255, 255, 255, 255 });
	that.compute(411, 11, { 64, 167, 227, 255 });
	that.compute(412, 3, { 0, 0, 0, 255 });
	that.compute(413, 173, { 65, 159, 217, 255 });
	that.compute(414, 11, { 64, 167, 227, 255 });
	that.compute(415, 7, { 215, 215, 215, 255 });
	that.compute(416, 7, { 215, 215, 215, 255 });
	that.compute(417, 7, { 147, 147, 147, 255 });
	that.compute(418, 2, { 255, 255, 255, 255 });
	that.compute(419, 173, { 65, 159, 217, 255 });
	that.compute(420, 24, { 255, 255, 255, 255 });
	that.compute(421, 23, { 39, 133, 191, 255 });
	that.compute(422, 2, { 255, 255, 255, 255 });
	that.compute(423, 11, { 64, 167, 227, 255 });
	that.compute(424, 71, { 225, 234, 239, 255 });
	that.compute(425, -1, { 157, 209, 239, 255 });
	that.compute(426, 2, { 255, 255, 255, 255 });
	that.compute(427, 3, { 0, 0, 0, 255 });
	that.compute(428, 7, { 153, 153, 153, 255 });
	that.compute(429, -1, { 213, 89, 89, 255 });
	that.compute(430, -1, { 232, 166, 89, 255 });
	that.compute(431, -1, { 73, 169, 87, 255 });
	that.compute(432, -1, { 89, 157, 207, 255 });
	that.compute(433, 24, { 255, 255, 255, 255 });
	that.compute(434, -1, { 56, 56, 56, 255 });
	that.compute(435, -1, { 80, 80, 80, 255 });
	that.compute(436, -1, { 103, 103, 103, 255 });
	that.compute(437, 12, { 255, 255, 255, 255 });
	that.compute(438, -1, { 34, 34, 34, 235 });
	that.compute(439, 19, { 0, 0, 0, 255 });
	that.compute(440, -1, { 0, 0, 0, 60 });
	that.compute(441, -1, { 255, 255, 255, 255 });
	that.compute(442, -1, { 17, 17, 17, 128 });
	that.compute(443, 441, { 255, 255, 255, 255 });
	that.compute(444, -1, { 77, 184, 255, 255 });
	that.compute(445, 378, { 44, 48, 51, 229 });
	that.compute(446, 379, { 255, 255, 255, 255 });
	that.compute(447, -1, { 199, 199, 199, 255 });
	that.compute(448, -1, { 37, 37, 37, 255 });
	that.compute(449, -1, { 255, 255, 255, 255 });
	that.compute(450, -1, { 71, 71, 71, 255 });
	that.compute(451, -1, { 255, 255, 255, 199 });
	that.compute(452, 447, { 199, 199, 199, 255 });
	that.compute(453, 449, { 255, 255, 255, 255 });
	that.compute(454, -1, { 255, 255, 255, 20 });
	that.compute(455, -1, { 255, 255, 255, 217 });
	that.compute(456, -1, { 255, 255, 255, 255 });
	that.compute(457, -1, { 255, 255, 255, 218 });
	that.compute(458, -1, { 255, 255, 255, 38 });
	that.compute(459, -1, { 255, 255, 255, 255 });
	that.compute(460, -1, { 204, 204, 204, 255 });
	that.compute(461, 2, { 255, 255, 255, 255 });
	that.compute(462, -1, { 38, 40, 44, 242 });
	that.compute(463, -1, { 27, 31, 35, 255 });
	that.compute(464, -1, { 27, 31, 35, 127 });
	that.compute(465, -1, { 255, 255, 255, 255 });
	that.compute(466, -1, { 170, 171, 172, 255 });
	that.compute(467, -1, { 255, 255, 255, 31 });
	that.compute(468, -1, { 255, 255, 255, 255 });
	that.compute(469, -1, { 255, 255, 255, 229 });
	that.compute(470, -1, { 34, 34, 34, 255 });
	that.compute(471, -1, { 241, 241, 241, 255 });
	that.compute(472, -1, { 102, 201, 91, 255 });
	that.compute(473, -1, { 82, 177, 73, 255 });
	that.compute(474, -1, { 80, 235, 65, 38 });
	that.compute(475, -1, { 215, 90, 90, 255 });
	that.compute(476, -1, { 192, 70, 70, 255 });
	that.compute(477, -1, { 255, 255, 255, 18 });
	that.compute(478, -1, { 26, 32, 38, 255 });
	that.compute(479, -1, { 77, 184, 255, 255 });
	that.compute(480, -1, { 44, 51, 61, 255 });
	that.compute(481, -1, { 50, 58, 69, 255 });
	that.compute(482, -1, { 57, 66, 79, 255 });
	that.compute(483, -1, { 255, 255, 255, 255 });
	that.compute(484, -1, { 141, 235, 144, 255 });
	that.compute(485, -1, { 141, 235, 144, 255 });
	that.compute(486, -1, { 132, 136, 143, 255 });
	that.compute(487, -1, { 97, 192, 255, 255 });
	that.compute(488, -1, { 237, 115, 114, 255 });
	that.compute(489, -1, { 145, 151, 158, 255 });
	that.compute(490, -1, { 255, 255, 255, 255 });
	that.compute(491, -1, { 13, 204, 57, 255 });
	that.compute(492, -1, { 11, 182, 189, 255 });
	that.compute(493, -1, { 9, 146, 239, 255 });
	that.compute(494, -1, { 22, 204, 251, 255 });
	that.compute(495, -1, { 198, 84, 147, 255 });
	that.compute(496, -1, { 122, 106, 241, 255 });
	that.compute(497, -1, { 95, 149, 232, 255 });
	that.compute(498, -1, { 79, 156, 255, 255 });
	that.compute(499, -1, { 155, 82, 233, 255 });
	that.compute(500, -1, { 235, 83, 83, 255 });
	that.compute(501, -1, { 41, 45, 51, 255 });
	that.compute(502, -1, { 52, 57, 64, 255 });
	that.compute(503, -1, { 58, 64, 71, 255 });
	that.compute(504, -1, { 247, 92, 92, 127 });
	that.compute(505, -1, { 247, 92, 92, 158 });
	that.compute(506, -1, { 255, 255, 255, 224 });
	that.compute(507, -1, { 255, 255, 255, 192 });
	that.compute(508, 173, { 65, 159, 217, 255 });
	that.compute(509, 190, { 32, 149, 208, 255 });
	that.compute(510, 152, { 143, 143, 143, 255 });
	that.compute(511, 174, { 255, 255, 255, 255 });
	that.compute(512, 378, { 44, 48, 51, 229 });
	that.compute(513, 379, { 255, 255, 255, 255 });
	that.compute(514, 444, { 77, 184, 255, 255 });
	that.compute(515, -1, { 255, 255, 255, 255 });
	that.compute(516, -1, { 224, 133, 67, 255 });
	that.compute(517, -1, { 224, 87, 69, 255 });
	that.compute(518, 35, { 255, 0, 0, 136 });
	that.compute(519, -1, { 18, 18, 19, 255 });
	that.compute(520, 519, { 18, 18, 19, 255 });
	that.compute(521, 519, { 18, 18, 19, 255 });
	that.compute(522, -1, { 90, 90, 91, 255 });
	that.compute(523, -1, { 55, 55, 56, 255 });
	that.compute(524, -1, { 116, 116, 117, 255 });
	that.compute(525, 521, { 18, 18, 19, 255 });
	that.compute(526, 522, { 90, 90, 91, 255 });
	that.compute(527, 523, { 55, 55, 56, 255 });
	that.compute(528, 524, { 116, 116, 117, 255 });
	that.compute(529, 521, { 18, 18, 19, 255 });
	that.compute(530, 522, { 90, 90, 91, 255 });
	that.compute(531, 89, { 232, 17, 35, 255 });
	that.compute(532, 90, { 255, 255, 255, 255 });
	that.compute(533, 529, { 18, 18, 19, 255 });
	that.compute(534, 530, { 90, 90, 91, 255 });
	that.compute(535, 531, { 232, 17, 35, 255 });
	that.compute(536, 532, { 255, 255, 255, 255 });
	that.compute(537, -1, { 30, 31, 33, 255 });
	that.compute(538, -1, { 255, 255, 255, 255 });
	that.compute(539, -1, { 249, 249, 249, 255 });
	that.compute(540, -1, { 153, 153, 153, 255 });
	that.compute(541, 540, { 153, 153, 153, 255 });
	that.compute(542, -1, { 255, 255, 255, 18 });
	that.compute(543, -1, { 41, 58, 76, 255 });
	that.compute(544, -1, { 23, 33, 43, 255 });
	that.compute(545, -1, { 30, 43, 56, 255 });
	that.compute(546, -1, { 136, 151, 166, 255 });
	that.compute(547, -1, { 100, 185, 250, 255 });
	that.compute(548, -1, { 131, 147, 163, 255 });
	that.compute(549, -1, { 94, 181, 247, 255 });
	that.compute(550, -1, { 94, 181, 247, 255 });
	that.compute(551, 550, { 94, 181, 247, 255 });
	that.compute(552, -1, { 131, 147, 163, 255 });
	that.compute(553, 550, { 94, 181, 247, 255 });
	that.compute(554, -1, { 255, 255, 255, 255 });
	that.compute(555, -1, { 0, 0, 0, 102 });
	that.compute(556, -1, { 60, 202, 239, 255 });
	that.compute(557, -1, { 85, 165, 255, 255 });
	that.compute(558, -1, { 167, 103, 255, 255 });
	that.compute(559, -1, { 219, 92, 157, 255 });
	that.compute(560, -1, { 255, 255, 255, 255 });
	that.compute(561, -1, { 243, 137, 38, 255 });
	that.compute(562, -1, { 228, 68, 86, 255 });
	that.compute(563, -1, { 74, 205, 67, 255 });
	that.compute(564, -1, { 226, 238, 249, 153 });
	that.compute(565, -1, { 186, 204, 217, 216 });
	that.compute(566, -1, { 50, 127, 229, 255 });
	that.compute(567, -1, { 97, 199, 82, 255 });
	that.compute(568, -1, { 224, 83, 86, 255 });
	that.compute(569, -1, { 235, 165, 45, 255 });
	that.compute(570, -1, { 88, 168, 237, 255 });
	that.compute(571, -1, { 143, 207, 57, 255 });
	that.compute(572, -1, { 242, 140, 57, 255 });
	that.compute(573, -1, { 127, 121, 243, 255 });
	that.compute(574, -1, { 159, 121, 232, 255 });
	that.compute(575, -1, { 64, 208, 202, 255 });
	that.compute(576, -1, { 255, 178, 34, 255 });
	that.compute(577, -1, { 255, 217, 81, 255 });
	that.compute(578, -1, { 240, 180, 0, 255 });
	that.compute(579, -1, { 186, 112, 0, 255 });
	that.compute(580, -1, { 218, 135, 53, 255 });
	that.compute(581, -1, { 22, 138, 205, 255 });
	that.compute(582, -1, { 73, 163, 85, 255 });
	that.compute(583, -1, { 149, 106, 200, 255 });
	that.compute(584, 7, { 153, 153, 153, 255 });
	that.compute(585, 147, { 64, 167, 227, 255 });
	that.compute(586, 35, { 224, 83, 86, 255 });
	that.compute(587, 250, { 153, 123, 225, 255 });


	internal::EnsureContrast(*data(138), *data(140));
	internal::EnsureContrast(*data(9), *data(2));
}

int32 palette_data::Checksum() {
	return 1445656676;
}

namespace internal {

int GetPaletteIndex(QLatin1String name) {
	auto size = name.size();
	auto data = name.data();
	if (size >= 5) switch (data[0]) {
	case 'y':
		if (size >= 17 && !memcmp(data + 1, "outubePlayIcon", 14)) {
			switch (data[15]) {
			case 'F':
				if (data[16] == 'g') {
					return (size == 17) ? 375 : -1;
				}
			break;
			case 'B':
				if (data[16] == 'g') {
					return (size == 17) ? 374 : -1;
				}
			break;
			}
		}
	break;
	case 'w':
		if (size >= 8) switch (data[1]) {
		case 'i':
			if (!memcmp(data + 2, "ndow", 4)) {
				switch (data[6]) {
				case 'S':
					if (size >= 14) switch (data[7]) {
					case 'u':
						if (size >= 15 && !memcmp(data + 8, "bTextFg", 7)) {
							if (size >= 19 && !memcmp(data + 15, "Over", 4)) {
								return (size == 19) ? 8 : -1;
							}
							return (size == 15) ? 7 : -1;
						}
					break;
					case 'h':
						if (!memcmp(data + 8, "adowFg", 6)) {
							if (size >= 22 && !memcmp(data + 14, "Fallback", 8)) {
								return (size == 22) ? 15 : -1;
							}
							return (size == 14) ? 14 : -1;
						}
					break;
					}
				break;
				case 'F':
					if (data[7] == 'g') {
						if (size >= 12) switch (data[8]) {
						case 'O':
							if (!memcmp(data + 9, "ver", 3)) {
								return (size == 12) ? 6 : -1;
							}
						break;
						case 'A':
							if (!memcmp(data + 9, "ctive", 5)) {
								return (size == 14) ? 12 : -1;
							}
						break;
						}
						return (size == 8) ? 3 : -1;
					}
				break;
				case 'B':
					switch (data[7]) {
					case 'o':
						if (size >= 12 && !memcmp(data + 8, "ldFg", 4)) {
							if (size >= 16 && !memcmp(data + 12, "Over", 4)) {
								return (size == 16) ? 10 : -1;
							}
							return (size == 12) ? 9 : -1;
						}
					break;
					case 'g':
						if (size >= 12) switch (data[8]) {
						case 'R':
							if (size >= 14 && !memcmp(data + 9, "ipple", 5)) {
								return (size == 14) ? 5 : -1;
							}
						break;
						case 'O':
							if (!memcmp(data + 9, "ver", 3)) {
								return (size == 12) ? 4 : -1;
							}
						break;
						case 'A':
							if (!memcmp(data + 9, "ctive", 5)) {
								return (size == 14) ? 11 : -1;
							}
						break;
						}
						return (size == 8) ? 2 : -1;
					break;
					}
				break;
				case 'A':
					if (!memcmp(data + 7, "ctiveTextFg", 11)) {
						return (size == 18) ? 13 : -1;
					}
				break;
				}
			}
		break;
		case 'a':
			if (!memcmp(data + 2, "llet", 4)) {
				switch (data[6]) {
				case 'T':
					switch (data[7]) {
					case 'o':
						if (data[8] == 'p') {
							switch (data[9]) {
							case 'L':
								if (size >= 16 && !memcmp(data + 10, "abelFg", 6)) {
									return (size == 16) ? 540 : -1;
								}
							break;
							case 'I':
								if (size >= 15 && !memcmp(data + 10, "con", 3)) {
									switch (data[13]) {
									case 'R':
										if (size >= 19 && !memcmp(data + 14, "ipple", 5)) {
											return (size == 19) ? 542 : -1;
										}
									break;
									case 'F':
										if (data[14] == 'g') {
											return (size == 15) ? 541 : -1;
										}
									break;
									}
								}
							break;
							case 'B':
								if (data[10] == 'g') {
									return (size == 11) ? 537 : -1;
								}
							break;
							}
						}
					break;
					case 'i':
						if (!memcmp(data + 8, "tleB", 4)) {
							switch (data[12]) {
							case 'u':
								if (size >= 19 && !memcmp(data + 13, "tton", 4)) {
									switch (data[17]) {
									case 'F':
										if (data[18] == 'g') {
											if (size >= 23) switch (data[19]) {
											case 'O':
												if (!memcmp(data + 20, "ver", 3)) {
													return (size == 23) ? 524 : -1;
												}
											break;
											case 'A':
												if (!memcmp(data + 20, "ctive", 5)) {
													if (size >= 29 && !memcmp(data + 25, "Over", 4)) {
														return (size == 29) ? 528 : -1;
													}
													return (size == 25) ? 526 : -1;
												}
											break;
											}
											return (size == 19) ? 522 : -1;
										}
									break;
									case 'C':
										if (size >= 24 && !memcmp(data + 18, "lose", 4)) {
											switch (data[22]) {
											case 'F':
												if (data[23] == 'g') {
													if (size >= 28) switch (data[24]) {
													case 'O':
														if (!memcmp(data + 25, "ver", 3)) {
															return (size == 28) ? 532 : -1;
														}
													break;
													case 'A':
														if (!memcmp(data + 25, "ctive", 5)) {
															if (size >= 34 && !memcmp(data + 30, "Over", 4)) {
																return (size == 34) ? 536 : -1;
															}
															return (size == 30) ? 534 : -1;
														}
													break;
													}
													return (size == 24) ? 530 : -1;
												}
											break;
											case 'B':
												if (data[23] == 'g') {
													if (size >= 28) switch (data[24]) {
													case 'O':
														if (!memcmp(data + 25, "ver", 3)) {
															return (size == 28) ? 531 : -1;
														}
													break;
													case 'A':
														if (!memcmp(data + 25, "ctive", 5)) {
															if (size >= 34 && !memcmp(data + 30, "Over", 4)) {
																return (size == 34) ? 535 : -1;
															}
															return (size == 30) ? 533 : -1;
														}
													break;
													}
													return (size == 24) ? 529 : -1;
												}
											break;
											}
										}
									break;
									case 'B':
										if (data[18] == 'g') {
											if (size >= 23) switch (data[19]) {
											case 'O':
												if (!memcmp(data + 20, "ver", 3)) {
													return (size == 23) ? 523 : -1;
												}
											break;
											case 'A':
												if (!memcmp(data + 20, "ctive", 5)) {
													if (size >= 29 && !memcmp(data + 25, "Over", 4)) {
														return (size == 29) ? 527 : -1;
													}
													return (size == 25) ? 525 : -1;
												}
											break;
											}
											return (size == 19) ? 521 : -1;
										}
									break;
									}
								}
							break;
							case 'g':
								if (size >= 19 && !memcmp(data + 13, "Active", 6)) {
									return (size == 19) ? 520 : -1;
								}
								return (size == 13) ? 519 : -1;
							break;
							}
						}
					break;
					}
				break;
				case 'S':
					if (size >= 18 && !memcmp(data + 7, "ubBalanceFg", 11)) {
						return (size == 18) ? 539 : -1;
					}
				break;
				case 'B':
					if (!memcmp(data + 7, "alanceFg", 8)) {
						return (size == 15) ? 538 : -1;
					}
				break;
				}
			}
		break;
		}
	break;
	case 'v':
		if (size >= 15 && !memcmp(data + 1, "ideoPlayIcon", 12)) {
			switch (data[13]) {
			case 'F':
				if (data[14] == 'g') {
					return (size == 15) ? 377 : -1;
				}
			break;
			case 'B':
				if (data[14] == 'g') {
					return (size == 15) ? 376 : -1;
				}
			break;
			}
		}
	break;
	case 't':
		if (size >= 7) switch (data[1]) {
		case 'r':
			if (size >= 13 && !memcmp(data + 2, "ayCounter", 9)) {
				switch (data[11]) {
				case 'F':
					if (data[12] == 'g') {
						if (size >= 22 && !memcmp(data + 13, "MacInvert", 9)) {
							return (size == 22) ? 101 : -1;
						}
						return (size == 13) ? 99 : -1;
					}
				break;
				case 'B':
					if (data[12] == 'g') {
						if (size >= 17 && data[13] == 'M') {
							switch (data[14]) {
							case 'u':
								if (!memcmp(data + 15, "te", 2)) {
									return (size == 17) ? 98 : -1;
								}
							break;
							case 'a':
								if (!memcmp(data + 15, "cInvert", 7)) {
									return (size == 22) ? 100 : -1;
								}
							break;
							}
						}
						return (size == 13) ? 97 : -1;
					}
				break;
				}
			}
		break;
		case 'o':
			switch (data[2]) {
			case 'p':
				if (size >= 8 && !memcmp(data + 3, "BarBg", 5)) {
					return (size == 8) ? 197 : -1;
				}
			break;
			case 'o':
				if (size >= 9 && !memcmp(data + 3, "ltip", 4)) {
					switch (data[7]) {
					case 'F':
						if (data[8] == 'g') {
							return (size == 9) ? 74 : -1;
						}
					break;
					case 'B':
						switch (data[8]) {
						case 'o':
							if (size >= 15 && !memcmp(data + 9, "rderFg", 6)) {
								return (size == 15) ? 75 : -1;
							}
						break;
						case 'g':
							return (size == 9) ? 73 : -1;
						break;
						}
					break;
					}
				}
			break;
			case 'a':
				if (!memcmp(data + 3, "st", 2)) {
					switch (data[5]) {
					case 'F':
						if (data[6] == 'g') {
							return (size == 7) ? 379 : -1;
						}
					break;
					case 'B':
						if (data[6] == 'g') {
							return (size == 7) ? 378 : -1;
						}
					break;
					}
				}
			break;
			}
		break;
		case 'i':
			if (!memcmp(data + 2, "tle", 3)) {
				switch (data[5]) {
				case 'S':
					if (size >= 11 && !memcmp(data + 6, "hadow", 5)) {
						return (size == 11) ? 76 : -1;
					}
				break;
				case 'F':
					if (data[6] == 'g') {
						if (size >= 13 && !memcmp(data + 7, "Active", 6)) {
							return (size == 13) ? 96 : -1;
						}
						return (size == 7) ? 95 : -1;
					}
				break;
				case 'B':
					switch (data[6]) {
					case 'u':
						if (size >= 13 && !memcmp(data + 7, "tton", 4)) {
							switch (data[11]) {
							case 'F':
								if (data[12] == 'g') {
									if (size >= 17) switch (data[13]) {
									case 'O':
										if (!memcmp(data + 14, "ver", 3)) {
											return (size == 17) ? 82 : -1;
										}
									break;
									case 'A':
										if (!memcmp(data + 14, "ctive", 5)) {
											if (size >= 23 && !memcmp(data + 19, "Over", 4)) {
												return (size == 23) ? 86 : -1;
											}
											return (size == 19) ? 84 : -1;
										}
									break;
									}
									return (size == 13) ? 80 : -1;
								}
							break;
							case 'C':
								if (size >= 18 && !memcmp(data + 12, "lose", 4)) {
									switch (data[16]) {
									case 'F':
										if (data[17] == 'g') {
											if (size >= 22) switch (data[18]) {
											case 'O':
												if (!memcmp(data + 19, "ver", 3)) {
													return (size == 22) ? 90 : -1;
												}
											break;
											case 'A':
												if (!memcmp(data + 19, "ctive", 5)) {
													if (size >= 28 && !memcmp(data + 24, "Over", 4)) {
														return (size == 28) ? 94 : -1;
													}
													return (size == 24) ? 92 : -1;
												}
											break;
											}
											return (size == 18) ? 88 : -1;
										}
									break;
									case 'B':
										if (data[17] == 'g') {
											if (size >= 22) switch (data[18]) {
											case 'O':
												if (!memcmp(data + 19, "ver", 3)) {
													return (size == 22) ? 89 : -1;
												}
											break;
											case 'A':
												if (!memcmp(data + 19, "ctive", 5)) {
													if (size >= 28 && !memcmp(data + 24, "Over", 4)) {
														return (size == 28) ? 93 : -1;
													}
													return (size == 24) ? 91 : -1;
												}
											break;
											}
											return (size == 18) ? 87 : -1;
										}
									break;
									}
								}
							break;
							case 'B':
								if (data[12] == 'g') {
									if (size >= 17) switch (data[13]) {
									case 'O':
										if (!memcmp(data + 14, "ver", 3)) {
											return (size == 17) ? 81 : -1;
										}
									break;
									case 'A':
										if (!memcmp(data + 14, "ctive", 5)) {
											if (size >= 23 && !memcmp(data + 19, "Over", 4)) {
												return (size == 23) ? 85 : -1;
											}
											return (size == 19) ? 83 : -1;
										}
									break;
									}
									return (size == 13) ? 79 : -1;
								}
							break;
							}
						}
					break;
					case 'g':
						if (size >= 13 && !memcmp(data + 7, "Active", 6)) {
							return (size == 13) ? 78 : -1;
						}
						return (size == 7) ? 77 : -1;
					break;
					}
				break;
				}
			}
		break;
		}
	break;
	case 's':
		if (size >= 8) switch (data[1]) {
		case 't':
			if (size >= 16) switch (data[2]) {
			case 'i':
				if (!memcmp(data + 3, "ckerP", 5)) {
					switch (data[8]) {
					case 'r':
						if (!memcmp(data + 9, "eviewBg", 7)) {
							return (size == 16) ? 206 : -1;
						}
					break;
					case 'a':
						if (data[9] == 'n') {
							switch (data[10]) {
							case 'P':
								if (!memcmp(data + 11, "remium", 6)) {
									switch (data[17]) {
									case '2':
										return (size == 18) ? 208 : -1;
									break;
									case '1':
										return (size == 18) ? 207 : -1;
									break;
									}
								}
							break;
							case 'D':
								if (!memcmp(data + 11, "elete", 5)) {
									switch (data[16]) {
									case 'F':
										if (data[17] == 'g') {
											return (size == 18) ? 205 : -1;
										}
									break;
									case 'B':
										if (data[17] == 'g') {
											return (size == 18) ? 204 : -1;
										}
									break;
									}
								}
							break;
							}
						}
					break;
					}
				}
			break;
			case 'a':
				if (!memcmp(data + 3, "tisticsChart", 12)) {
					switch (data[15]) {
					case 'L':
						if (size >= 22 && !memcmp(data + 16, "ine", 3)) {
							switch (data[19]) {
							case 'R':
								if (!memcmp(data + 20, "ed", 2)) {
									return (size == 22) ? 568 : -1;
								}
							break;
							case 'P':
								if (size >= 25 && !memcmp(data + 20, "urple", 5)) {
									return (size == 25) ? 574 : -1;
								}
							break;
							case 'O':
								if (size >= 25 && !memcmp(data + 20, "range", 5)) {
									return (size == 25) ? 572 : -1;
								}
							break;
							case 'L':
								if (size >= 28 && !memcmp(data + 20, "ight", 4)) {
									switch (data[24]) {
									case 'g':
										if (size >= 29 && !memcmp(data + 25, "reen", 4)) {
											return (size == 29) ? 571 : -1;
										}
									break;
									case 'b':
										if (!memcmp(data + 25, "lue", 3)) {
											return (size == 28) ? 570 : -1;
										}
									break;
									}
								}
							break;
							case 'I':
								if (size >= 25 && !memcmp(data + 20, "ndigo", 5)) {
									return (size == 25) ? 573 : -1;
								}
							break;
							case 'G':
								if (size >= 24) switch (data[20]) {
								case 'r':
									if (!memcmp(data + 21, "een", 3)) {
										return (size == 24) ? 567 : -1;
									}
								break;
								case 'o':
									if (!memcmp(data + 21, "lden", 4)) {
										return (size == 25) ? 569 : -1;
									}
								break;
								}
							break;
							case 'C':
								if (!memcmp(data + 20, "yan", 3)) {
									return (size == 23) ? 575 : -1;
								}
							break;
							case 'B':
								if (!memcmp(data + 20, "lue", 3)) {
									return (size == 23) ? 566 : -1;
								}
							break;
							}
						}
					break;
					case 'I':
						if (size >= 23 && !memcmp(data + 16, "nactive", 7)) {
							return (size == 23) ? 564 : -1;
						}
					break;
					case 'A':
						if (!memcmp(data + 16, "ctive", 5)) {
							return (size == 21) ? 565 : -1;
						}
					break;
					}
				}
			break;
			}
		break;
		case 'p':
			if (size >= 14 && !memcmp(data + 2, "ellUnderline", 12)) {
				return (size == 14) ? 518 : -1;
			}
		break;
		case 'o':
			if (size >= 18 && !memcmp(data + 2, "ngCoverOverlayFg", 16)) {
				return (size == 18) ? 555 : -1;
			}
		break;
		case 'm':
			if (size >= 16 && !memcmp(data + 2, "allCloseIconFg", 14)) {
				if (size >= 20 && !memcmp(data + 16, "Over", 4)) {
					return (size == 20) ? 52 : -1;
				}
				return (size == 16) ? 51 : -1;
			}
		break;
		case 'l':
			if (size >= 14 && !memcmp(data + 2, "ide", 3)) {
				switch (data[5]) {
				case 'r':
					if (!memcmp(data + 6, "Bg", 2)) {
						switch (data[8]) {
						case 'I':
							if (size >= 16 && !memcmp(data + 9, "nactive", 7)) {
								return (size == 16) ? 71 : -1;
							}
						break;
						case 'A':
							if (!memcmp(data + 9, "ctive", 5)) {
								return (size == 14) ? 72 : -1;
							}
						break;
						}
					}
				break;
				case 'F':
					if (!memcmp(data + 6, "adeOut", 6)) {
						switch (data[12]) {
						case 'S':
							if (size >= 20 && !memcmp(data + 13, "hadowFg", 7)) {
								return (size == 20) ? 18 : -1;
							}
						break;
						case 'B':
							if (data[13] == 'g') {
								return (size == 14) ? 17 : -1;
							}
						break;
						}
					}
				break;
				}
			}
		break;
		case 'i':
			if (size >= 9 && !memcmp(data + 2, "deBar", 5)) {
				switch (data[7]) {
				case 'T':
					if (size >= 13 && !memcmp(data + 8, "extFg", 5)) {
						if (size >= 19 && !memcmp(data + 13, "Active", 6)) {
							return (size == 19) ? 547 : -1;
						}
						return (size == 13) ? 546 : -1;
					}
				break;
				case 'I':
					if (size >= 13 && !memcmp(data + 8, "conFg", 5)) {
						if (size >= 19 && !memcmp(data + 13, "Active", 6)) {
							return (size == 19) ? 549 : -1;
						}
						return (size == 13) ? 548 : -1;
					}
				break;
				case 'B':
					switch (data[8]) {
					case 'g':
						if (size >= 15) switch (data[9]) {
						case 'R':
							if (!memcmp(data + 10, "ipple", 5)) {
								return (size == 15) ? 545 : -1;
							}
						break;
						case 'A':
							if (!memcmp(data + 10, "ctive", 5)) {
								return (size == 15) ? 544 : -1;
							}
						break;
						}
						return (size == 9) ? 543 : -1;
					break;
					case 'a':
						if (!memcmp(data + 9, "dge", 3)) {
							switch (data[12]) {
							case 'F':
								if (data[13] == 'g') {
									return (size == 14) ? 554 : -1;
								}
							break;
							case 'B':
								if (data[13] == 'g') {
									if (size >= 19) switch (data[14]) {
									case 'M':
										if (!memcmp(data + 15, "uted", 4)) {
											if (size >= 25 && !memcmp(data + 19, "Active", 6)) {
												return (size == 25) ? 553 : -1;
											}
											return (size == 19) ? 552 : -1;
										}
									break;
									case 'A':
										if (!memcmp(data + 15, "ctive", 5)) {
											return (size == 20) ? 551 : -1;
										}
									break;
									}
									return (size == 14) ? 550 : -1;
								}
							break;
							}
						}
					break;
					}
				break;
				}
			}
		break;
		case 'h':
			if (!memcmp(data + 2, "adowFg", 6)) {
				return (size == 8) ? 16 : -1;
			}
		break;
		case 'e':
			if (size >= 13) switch (data[2]) {
			case 't':
				if (size >= 14 && !memcmp(data + 3, "tingsIcon", 9)) {
					switch (data[12]) {
					case 'F':
						if (data[13] == 'g') {
							return (size == 14) ? 282 : -1;
						}
					break;
					case 'B':
						if (data[13] == 'g') {
							switch (data[14]) {
							case 'A':
								if (size >= 21 && !memcmp(data + 15, "rchive", 6)) {
									return (size == 21) ? 281 : -1;
								}
							break;
							case '8':
								return (size == 15) ? 280 : -1;
							break;
							case '6':
								return (size == 15) ? 279 : -1;
							break;
							case '5':
								return (size == 15) ? 278 : -1;
							break;
							case '4':
								return (size == 15) ? 277 : -1;
							break;
							case '3':
								return (size == 15) ? 276 : -1;
							break;
							case '2':
								return (size == 15) ? 275 : -1;
							break;
							case '1':
								return (size == 15) ? 274 : -1;
							break;
							}
						}
					break;
					}
				}
			break;
			case 'a':
				if (!memcmp(data + 3, "rched", 5)) {
					switch (data[8]) {
					case 'T':
						if (size >= 19 && !memcmp(data + 9, "ext", 3)) {
							switch (data[12]) {
							case 'M':
								if (!memcmp(data + 13, "atch", 4)) {
									switch (data[17]) {
									case 'F':
										if (data[18] == 'g') {
											return (size == 19) ? 194 : -1;
										}
									break;
									case 'B':
										if (data[18] == 'g') {
											return (size == 19) ? 193 : -1;
										}
									break;
									}
								}
							break;
							case 'C':
								if (!memcmp(data + 13, "urrentMatch", 11)) {
									switch (data[24]) {
									case 'F':
										if (data[25] == 'g') {
											return (size == 26) ? 196 : -1;
										}
									break;
									case 'B':
										if (data[25] == 'g') {
											return (size == 26) ? 195 : -1;
										}
									break;
									}
								}
							break;
							}
						}
					break;
					case 'B':
						if (!memcmp(data + 9, "ar", 2)) {
							switch (data[11]) {
							case 'F':
								if (data[12] == 'g') {
									return (size == 13) ? 192 : -1;
								}
							break;
							case 'B':
								if (data[12] == 'g') {
									return (size == 13) ? 191 : -1;
								}
							break;
							}
						}
					break;
					}
				}
			break;
			}
		break;
		case 'c':
			if (!memcmp(data + 2, "rollB", 5)) {
				switch (data[7]) {
				case 'g':
					if (size >= 12 && !memcmp(data + 8, "Over", 4)) {
						return (size == 12) ? 50 : -1;
					}
					return (size == 8) ? 49 : -1;
				break;
				case 'a':
					if (!memcmp(data + 8, "rBg", 3)) {
						if (size >= 15 && !memcmp(data + 11, "Over", 4)) {
							return (size == 15) ? 48 : -1;
						}
						return (size == 11) ? 47 : -1;
					}
				break;
				}
			}
		break;
		}
	break;
	case 'r':
		if (size >= 8 && data[1] == 'a') {
			switch (data[2]) {
			case 'n':
				if (size >= 10 && data[3] == 'k') {
					switch (data[4]) {
					case 'U':
						if (!memcmp(data + 5, "serFg", 5)) {
							return (size == 10) ? 584 : -1;
						}
					break;
					case 'O':
						if (!memcmp(data + 5, "wnerFg", 6)) {
							return (size == 11) ? 583 : -1;
						}
					break;
					case 'A':
						if (!memcmp(data + 5, "dminFg", 6)) {
							return (size == 11) ? 582 : -1;
						}
					break;
					}
				}
			break;
			case 'd':
				if (!memcmp(data + 3, "ial", 3)) {
					switch (data[6]) {
					case 'F':
						if (data[7] == 'g') {
							return (size == 8) ? 53 : -1;
						}
					break;
					case 'B':
						if (data[7] == 'g') {
							return (size == 8) ? 54 : -1;
						}
					break;
					}
				}
			break;
			}
		}
	break;
	case 'p':
		if (size >= 13) switch (data[1]) {
		case 'r':
			if (size >= 14) switch (data[2]) {
			case 'o':
				if (size >= 19 && !memcmp(data + 3, "file", 4)) {
					switch (data[7]) {
					case 'V':
						if (size >= 22 && !memcmp(data + 8, "erifiedCheck", 12)) {
							switch (data[20]) {
							case 'F':
								if (data[21] == 'g') {
									return (size == 22) ? 410 : -1;
								}
							break;
							case 'B':
								if (data[21] == 'g') {
									return (size == 22) ? 409 : -1;
								}
							break;
							}
						}
					break;
					case 'S':
						if (!memcmp(data + 8, "tatusFgOver", 11)) {
							return (size == 19) ? 408 : -1;
						}
					break;
					case 'A':
						if (!memcmp(data + 8, "dminStartFg", 11)) {
							return (size == 19) ? 411 : -1;
						}
					break;
					}
				}
			break;
			case 'e':
				if (!memcmp(data + 3, "mium", 4)) {
					switch (data[7]) {
					case 'I':
						if (!memcmp(data + 8, "conBg", 5)) {
							switch (data[13]) {
							case '3':
								return (size == 14) ? 563 : -1;
							break;
							case '2':
								return (size == 14) ? 562 : -1;
							break;
							case '1':
								return (size == 14) ? 561 : -1;
							break;
							}
						}
					break;
					case 'B':
						if (!memcmp(data + 8, "utton", 5)) {
							switch (data[13]) {
							case 'F':
								if (data[14] == 'g') {
									return (size == 15) ? 560 : -1;
								}
							break;
							case 'B':
								if (data[14] == 'g') {
									switch (data[15]) {
									case '3':
										return (size == 16) ? 559 : -1;
									break;
									case '2':
										return (size == 16) ? 558 : -1;
									break;
									case '1':
										return (size == 16) ? 557 : -1;
									break;
									}
								}
							break;
							}
						}
					break;
					}
				}
			break;
			}
		break;
		case 'l':
			if (!memcmp(data + 2, "aceholderFg", 11)) {
				if (size >= 19 && !memcmp(data + 13, "Active", 6)) {
					return (size == 19) ? 56 : -1;
				}
				return (size == 13) ? 55 : -1;
			}
		break;
		case 'h':
			if (!memcmp(data + 2, "oto", 3)) {
				switch (data[5]) {
				case 'E':
					if (size >= 27 && !memcmp(data + 6, "ditorItemBaseHandleFg", 21)) {
						return (size == 27) ? 556 : -1;
					}
				break;
				case 'C':
					if (!memcmp(data + 6, "rop", 3)) {
						switch (data[9]) {
						case 'P':
							if (size >= 16 && !memcmp(data + 10, "ointFg", 6)) {
								return (size == 16) ? 125 : -1;
							}
						break;
						case 'F':
							if (!memcmp(data + 10, "adeBg", 5)) {
								return (size == 15) ? 124 : -1;
							}
						break;
						}
					}
				break;
				}
			}
		break;
		case 'a':
			if (!memcmp(data + 2, "ymentsTipActive", 15)) {
				return (size == 17) ? 116 : -1;
			}
		break;
		}
	break;
	case 'o':
		if (size >= 10) switch (data[1]) {
		case 'v':
			if (size >= 15 && !memcmp(data + 2, "erview", 6)) {
				switch (data[8]) {
				case 'P':
					if (size >= 26 && !memcmp(data + 9, "hotoSelectOverlay", 17)) {
						return (size == 26) ? 407 : -1;
					}
				break;
				case 'C':
					if (!memcmp(data + 9, "heck", 4)) {
						switch (data[13]) {
						case 'F':
							if (size >= 21 && !memcmp(data + 14, "gActive", 7)) {
								return (size == 21) ? 406 : -1;
							}
						break;
						case 'B':
							switch (data[14]) {
							case 'o':
								if (size >= 19 && !memcmp(data + 15, "rder", 4)) {
									return (size == 19) ? 405 : -1;
								}
							break;
							case 'g':
								if (size >= 21 && !memcmp(data + 15, "Active", 6)) {
									return (size == 21) ? 404 : -1;
								}
								return (size == 15) ? 403 : -1;
							break;
							}
						break;
						}
					}
				break;
				}
			}
		break;
		case 'u':
			if (!memcmp(data + 2, "tdate", 5)) {
				switch (data[7]) {
				case 'd':
					switch (data[8]) {
					case 'F':
						if (data[9] == 'g') {
							return (size == 10) ? 515 : -1;
						}
					break;
					case 'B':
						if (data[9] == 'g') {
							return (size == 10) ? 517 : -1;
						}
					break;
					}
				break;
				case 'S':
					if (!memcmp(data + 8, "oonBg", 5)) {
						return (size == 13) ? 516 : -1;
					}
				break;
				}
			}
		break;
		}
	break;
	case 'n':
		if (size >= 14 && !memcmp(data + 1, "otification", 11)) {
			switch (data[12]) {
			case 's':
				if (size >= 24 && !memcmp(data + 13, "Box", 3)) {
					switch (data[16]) {
					case 'S':
						if (!memcmp(data + 17, "creenBg", 7)) {
							return (size == 24) ? 413 : -1;
						}
					break;
					case 'M':
						if (!memcmp(data + 17, "onitorFg", 8)) {
							return (size == 25) ? 412 : -1;
						}
					break;
					}
				}
			break;
			case 'S':
				if (size >= 24 && !memcmp(data + 13, "ample", 5)) {
					switch (data[18]) {
					case 'U':
						if (size >= 27 && !memcmp(data + 19, "serpicFg", 8)) {
							return (size == 27) ? 414 : -1;
						}
					break;
					case 'T':
						if (!memcmp(data + 19, "extFg", 5)) {
							return (size == 24) ? 416 : -1;
						}
					break;
					case 'N':
						if (!memcmp(data + 19, "ameFg", 5)) {
							return (size == 24) ? 417 : -1;
						}
					break;
					case 'C':
						if (!memcmp(data + 19, "loseFg", 6)) {
							return (size == 25) ? 415 : -1;
						}
					break;
					}
				}
			break;
			case 'B':
				if (data[13] == 'g') {
					return (size == 14) ? 461 : -1;
				}
			break;
			}
		}
	break;
	case 'm':
		if (size >= 6) switch (data[1]) {
		case 's':
			if (size >= 7 && data[2] == 'g') {
				switch (data[3]) {
				case 'W':
					if (size >= 19 && !memcmp(data + 4, "aveform", 7)) {
						switch (data[11]) {
						case 'O':
							if (size >= 20 && !memcmp(data + 12, "ut", 2)) {
								switch (data[14]) {
								case 'I':
									if (size >= 22 && !memcmp(data + 15, "nactive", 7)) {
										if (size >= 30 && !memcmp(data + 22, "Selected", 8)) {
											return (size == 30) ? 366 : -1;
										}
										return (size == 22) ? 365 : -1;
									}
								break;
								case 'A':
									if (!memcmp(data + 15, "ctive", 5)) {
										if (size >= 28 && !memcmp(data + 20, "Selected", 8)) {
											return (size == 28) ? 364 : -1;
										}
										return (size == 20) ? 363 : -1;
									}
								break;
								}
							}
						break;
						case 'I':
							if (data[12] == 'n') {
								switch (data[13]) {
								case 'I':
									if (size >= 21 && !memcmp(data + 14, "nactive", 7)) {
										if (size >= 29 && !memcmp(data + 21, "Selected", 8)) {
											return (size == 29) ? 362 : -1;
										}
										return (size == 21) ? 361 : -1;
									}
								break;
								case 'A':
									if (!memcmp(data + 14, "ctive", 5)) {
										if (size >= 27 && !memcmp(data + 19, "Selected", 8)) {
											return (size == 27) ? 360 : -1;
										}
										return (size == 19) ? 359 : -1;
									}
								break;
								}
							}
						break;
						}
					}
				break;
				case 'S':
					if (size >= 12) switch (data[4]) {
					case 't':
						if (size >= 17 && !memcmp(data + 5, "ickerOverlay", 12)) {
							return (size == 17) ? 292 : -1;
						}
					break;
					case 'e':
						switch (data[5]) {
						case 'r':
							if (!memcmp(data + 6, "vice", 4)) {
								switch (data[10]) {
								case 'F':
									if (data[11] == 'g') {
										return (size == 12) ? 305 : -1;
									}
								break;
								case 'B':
									if (data[11] == 'g') {
										if (size >= 20 && !memcmp(data + 12, "Selected", 8)) {
											return (size == 20) ? 307 : -1;
										}
										return (size == 12) ? 306 : -1;
									}
								break;
								}
							}
						break;
						case 'l':
							if (!memcmp(data + 6, "ectOverlay", 10)) {
								return (size == 16) ? 291 : -1;
							}
						break;
						}
					break;
					}
				break;
				case 'O':
					if (size >= 8 && !memcmp(data + 4, "ut", 2)) {
						switch (data[6]) {
						case 'S':
							if (size >= 12) switch (data[7]) {
							case 'h':
								if (!memcmp(data + 8, "adow", 4)) {
									if (size >= 20 && !memcmp(data + 12, "Selected", 8)) {
										return (size == 20) ? 300 : -1;
									}
									return (size == 12) ? 299 : -1;
								}
							break;
							case 'e':
								if (!memcmp(data + 8, "rviceFg", 7)) {
									if (size >= 23 && !memcmp(data + 15, "Selected", 8)) {
										return (size == 23) ? 296 : -1;
									}
									return (size == 15) ? 295 : -1;
								}
							break;
							}
						break;
						case 'R':
							if (size >= 19 && !memcmp(data + 7, "eplyBar", 7)) {
								switch (data[14]) {
								case 'S':
									if (size >= 22 && !memcmp(data + 15, "elColor", 7)) {
										return (size == 22) ? 311 : -1;
									}
								break;
								case 'C':
									if (!memcmp(data + 15, "olor", 4)) {
										return (size == 19) ? 310 : -1;
									}
								break;
								}
							}
						break;
						case 'M':
							if (size >= 12 && !memcmp(data + 7, "onoFg", 5)) {
								if (size >= 20 && !memcmp(data + 12, "Selected", 8)) {
									return (size == 20) ? 316 : -1;
								}
								return (size == 12) ? 314 : -1;
							}
						break;
						case 'D':
							if (size >= 12 && !memcmp(data + 7, "ateFg", 5)) {
								if (size >= 20 && !memcmp(data + 12, "Selected", 8)) {
									return (size == 20) ? 304 : -1;
								}
								return (size == 12) ? 303 : -1;
							}
						break;
						case 'B':
							if (data[7] == 'g') {
								if (size >= 16 && !memcmp(data + 8, "Selected", 8)) {
									return (size == 16) ? 290 : -1;
								}
								return (size == 8) ? 289 : -1;
							}
						break;
						}
					}
				break;
				case 'I':
					switch (data[4]) {
					case 'n':
						switch (data[5]) {
						case 'S':
							if (size >= 11) switch (data[6]) {
							case 'h':
								if (!memcmp(data + 7, "adow", 4)) {
									if (size >= 19 && !memcmp(data + 11, "Selected", 8)) {
										return (size == 19) ? 298 : -1;
									}
									return (size == 11) ? 297 : -1;
								}
							break;
							case 'e':
								if (!memcmp(data + 7, "rviceFg", 7)) {
									if (size >= 22 && !memcmp(data + 14, "Selected", 8)) {
										return (size == 22) ? 294 : -1;
									}
									return (size == 14) ? 293 : -1;
								}
							break;
							}
						break;
						case 'R':
							if (size >= 18 && !memcmp(data + 6, "eplyBar", 7)) {
								switch (data[13]) {
								case 'S':
									if (size >= 21 && !memcmp(data + 14, "elColor", 7)) {
										return (size == 21) ? 309 : -1;
									}
								break;
								case 'C':
									if (!memcmp(data + 14, "olor", 4)) {
										return (size == 18) ? 308 : -1;
									}
								break;
								}
							}
						break;
						case 'M':
							if (size >= 11 && !memcmp(data + 6, "onoFg", 5)) {
								if (size >= 19 && !memcmp(data + 11, "Selected", 8)) {
									return (size == 19) ? 315 : -1;
								}
								return (size == 11) ? 313 : -1;
							}
						break;
						case 'D':
							if (size >= 11 && !memcmp(data + 6, "ateFg", 5)) {
								if (size >= 19 && !memcmp(data + 11, "Selected", 8)) {
									return (size == 19) ? 302 : -1;
								}
								return (size == 11) ? 301 : -1;
							}
						break;
						case 'B':
							if (data[6] == 'g') {
								if (size >= 15 && !memcmp(data + 7, "Selected", 8)) {
									return (size == 15) ? 288 : -1;
								}
								return (size == 7) ? 287 : -1;
							}
						break;
						}
					break;
					case 'm':
						if (!memcmp(data + 5, "gReplyBarColor", 14)) {
							return (size == 19) ? 312 : -1;
						}
					break;
					}
				break;
				case 'F':
					if (!memcmp(data + 4, "ile", 3)) {
						switch (data[7]) {
						case 'T':
							if (size >= 20 && !memcmp(data + 8, "humbLink", 8)) {
								switch (data[16]) {
								case 'O':
									if (size >= 21 && !memcmp(data + 17, "utFg", 4)) {
										if (size >= 29 && !memcmp(data + 21, "Selected", 8)) {
											return (size == 29) ? 324 : -1;
										}
										return (size == 21) ? 323 : -1;
									}
								break;
								case 'I':
									if (!memcmp(data + 17, "nFg", 3)) {
										if (size >= 28 && !memcmp(data + 20, "Selected", 8)) {
											return (size == 28) ? 322 : -1;
										}
										return (size == 20) ? 321 : -1;
									}
								break;
								}
							}
						break;
						case 'O':
							if (size >= 12 && !memcmp(data + 8, "utBg", 4)) {
								if (size >= 20 && !memcmp(data + 12, "Selected", 8)) {
									return (size == 20) ? 329 : -1;
								}
								return (size == 12) ? 328 : -1;
							}
						break;
						case 'I':
							if (size >= 11 && !memcmp(data + 8, "nBg", 3)) {
								if (size >= 15) switch (data[11]) {
								case 'S':
									if (size >= 19 && !memcmp(data + 12, "elected", 7)) {
										return (size == 19) ? 327 : -1;
									}
								break;
								case 'O':
									if (!memcmp(data + 12, "ver", 3)) {
										return (size == 15) ? 326 : -1;
									}
								break;
								}
								return (size == 11) ? 325 : -1;
							}
						break;
						case '4':
							if (!memcmp(data + 8, "Bg", 2)) {
								if (size >= 14) switch (data[10]) {
								case 'S':
									if (size >= 18 && !memcmp(data + 11, "elected", 7)) {
										return (size == 18) ? 345 : -1;
									}
								break;
								case 'O':
									if (!memcmp(data + 11, "ver", 3)) {
										return (size == 14) ? 344 : -1;
									}
								break;
								case 'D':
									if (!memcmp(data + 11, "ark", 3)) {
										return (size == 14) ? 343 : -1;
									}
								break;
								}
								return (size == 10) ? 342 : -1;
							}
						break;
						case '3':
							if (!memcmp(data + 8, "Bg", 2)) {
								if (size >= 14) switch (data[10]) {
								case 'S':
									if (size >= 18 && !memcmp(data + 11, "elected", 7)) {
										return (size == 18) ? 341 : -1;
									}
								break;
								case 'O':
									if (!memcmp(data + 11, "ver", 3)) {
										return (size == 14) ? 340 : -1;
									}
								break;
								case 'D':
									if (!memcmp(data + 11, "ark", 3)) {
										return (size == 14) ? 339 : -1;
									}
								break;
								}
								return (size == 10) ? 338 : -1;
							}
						break;
						case '2':
							if (!memcmp(data + 8, "Bg", 2)) {
								if (size >= 14) switch (data[10]) {
								case 'S':
									if (size >= 18 && !memcmp(data + 11, "elected", 7)) {
										return (size == 18) ? 337 : -1;
									}
								break;
								case 'O':
									if (!memcmp(data + 11, "ver", 3)) {
										return (size == 14) ? 336 : -1;
									}
								break;
								case 'D':
									if (!memcmp(data + 11, "ark", 3)) {
										return (size == 14) ? 335 : -1;
									}
								break;
								}
								return (size == 10) ? 334 : -1;
							}
						break;
						case '1':
							if (!memcmp(data + 8, "Bg", 2)) {
								if (size >= 14) switch (data[10]) {
								case 'S':
									if (size >= 18 && !memcmp(data + 11, "elected", 7)) {
										return (size == 18) ? 333 : -1;
									}
								break;
								case 'O':
									if (!memcmp(data + 11, "ver", 3)) {
										return (size == 14) ? 332 : -1;
									}
								break;
								case 'D':
									if (!memcmp(data + 11, "ark", 3)) {
										return (size == 14) ? 331 : -1;
									}
								break;
								}
								return (size == 10) ? 330 : -1;
							}
						break;
						}
					}
				break;
				case 'D':
					if (!memcmp(data + 4, "ateImg", 6)) {
						switch (data[10]) {
						case 'F':
							if (data[11] == 'g') {
								return (size == 12) ? 317 : -1;
							}
						break;
						case 'B':
							if (data[11] == 'g') {
								if (size >= 16) switch (data[12]) {
								case 'S':
									if (size >= 20 && !memcmp(data + 13, "elected", 7)) {
										return (size == 20) ? 320 : -1;
									}
								break;
								case 'O':
									if (!memcmp(data + 13, "ver", 3)) {
										return (size == 16) ? 319 : -1;
									}
								break;
								}
								return (size == 12) ? 318 : -1;
							}
						break;
						}
					}
				break;
				case 'B':
					if (!memcmp(data + 4, "otKb", 4)) {
						switch (data[8]) {
						case 'R':
							if (size >= 16 && !memcmp(data + 9, "ippleBg", 7)) {
								return (size == 16) ? 369 : -1;
							}
						break;
						case 'O':
							if (size >= 17 && !memcmp(data + 9, "verBgAdd", 8)) {
								return (size == 17) ? 367 : -1;
							}
						break;
						case 'I':
							if (!memcmp(data + 9, "conFg", 5)) {
								return (size == 14) ? 368 : -1;
							}
						break;
						}
					}
				break;
				}
			}
		break;
		case 'e':
			switch (data[2]) {
			case 'n':
				if (data[3] == 'u') {
					switch (data[4]) {
					case 'S':
						if (size >= 15) switch (data[5]) {
						case 'u':
							if (size >= 18 && !memcmp(data + 6, "bmenuArrowFg", 12)) {
								return (size == 18) ? 44 : -1;
							}
						break;
						case 'e':
							if (!memcmp(data + 6, "paratorFg", 9)) {
								return (size == 15) ? 46 : -1;
							}
						break;
						}
					break;
					case 'I':
						if (size >= 10 && !memcmp(data + 5, "conFg", 5)) {
							if (size >= 14 && !memcmp(data + 10, "Over", 4)) {
								return (size == 14) ? 43 : -1;
							}
							return (size == 10) ? 42 : -1;
						}
					break;
					case 'F':
						if (size >= 14 && !memcmp(data + 5, "gDisabled", 9)) {
							return (size == 14) ? 45 : -1;
						}
					break;
					case 'B':
						if (data[5] == 'g') {
							if (size >= 10) switch (data[6]) {
							case 'R':
								if (size >= 12 && !memcmp(data + 7, "ipple", 5)) {
									return (size == 12) ? 41 : -1;
								}
							break;
							case 'O':
								if (!memcmp(data + 7, "ver", 3)) {
									return (size == 10) ? 40 : -1;
								}
							break;
							}
							return (size == 6) ? 39 : -1;
						}
					break;
					}
				}
			break;
			case 'm':
				if (size >= 19 && !memcmp(data + 3, "bersAboutLimitFg", 16)) {
					return (size == 19) ? 117 : -1;
				}
			break;
			case 'd':
				if (!memcmp(data + 3, "ia", 2)) {
					switch (data[5]) {
					case 'v':
						if (size >= 11 && !memcmp(data + 6, "iew", 3)) {
							switch (data[9]) {
							case 'V':
								if (size >= 16 && !memcmp(data + 10, "ideoBg", 6)) {
									return (size == 16) ? 439 : -1;
								}
							break;
							case 'T':
								if (size >= 19) switch (data[10]) {
								case 'r':
									if (size >= 22 && !memcmp(data + 11, "ansparent", 9)) {
										switch (data[20]) {
										case 'F':
											if (data[21] == 'g') {
												return (size == 22) ? 460 : -1;
											}
										break;
										case 'B':
											if (data[21] == 'g') {
												return (size == 22) ? 459 : -1;
											}
										break;
										}
									}
								break;
								case 'e':
									if (!memcmp(data + 11, "xtLinkFg", 8)) {
										return (size == 19) ? 444 : -1;
									}
								break;
								}
							break;
							case 'S':
								if (size >= 18 && !memcmp(data + 10, "aveMsg", 6)) {
									switch (data[16]) {
									case 'F':
										if (data[17] == 'g') {
											return (size == 18) ? 446 : -1;
										}
									break;
									case 'B':
										if (data[17] == 'g') {
											return (size == 18) ? 445 : -1;
										}
									break;
									}
								}
							break;
							case 'P':
								if (size >= 22) switch (data[10]) {
								case 'l':
									if (size >= 23 && !memcmp(data + 11, "ayback", 6)) {
										switch (data[17]) {
										case 'P':
											if (size >= 27 && !memcmp(data + 18, "rogressFg", 9)) {
												return (size == 27) ? 451 : -1;
											}
										break;
										case 'I':
											switch (data[18]) {
											case 'n':
												if (size >= 25 && !memcmp(data + 19, "active", 6)) {
													if (size >= 29 && !memcmp(data + 25, "Over", 4)) {
														return (size == 29) ? 450 : -1;
													}
													return (size == 25) ? 448 : -1;
												}
											break;
											case 'c':
												if (!memcmp(data + 19, "on", 2)) {
													switch (data[21]) {
													case 'R':
														if (size >= 27 && !memcmp(data + 22, "ipple", 5)) {
															return (size == 27) ? 454 : -1;
														}
													break;
													case 'F':
														if (data[22] == 'g') {
															if (size >= 27 && !memcmp(data + 23, "Over", 4)) {
																return (size == 27) ? 453 : -1;
															}
															return (size == 23) ? 452 : -1;
														}
													break;
													}
												}
											break;
											}
										break;
										case 'A':
											if (!memcmp(data + 18, "ctive", 5)) {
												if (size >= 27 && !memcmp(data + 23, "Over", 4)) {
													return (size == 27) ? 449 : -1;
												}
												return (size == 23) ? 447 : -1;
											}
										break;
										}
									}
								break;
								case 'i':
									if (data[11] == 'p') {
										switch (data[12]) {
										case 'P':
											if (size >= 26 && !memcmp(data + 13, "layback", 7)) {
												switch (data[20]) {
												case 'I':
													if (size >= 28 && !memcmp(data + 21, "nactive", 7)) {
														return (size == 28) ? 458 : -1;
													}
												break;
												case 'A':
													if (!memcmp(data + 21, "ctive", 5)) {
														return (size == 26) ? 457 : -1;
													}
												break;
												}
											}
										break;
										case 'C':
											if (!memcmp(data + 13, "ontrolsFg", 9)) {
												if (size >= 26 && !memcmp(data + 22, "Over", 4)) {
													return (size == 26) ? 456 : -1;
												}
												return (size == 22) ? 455 : -1;
											}
										break;
										}
									}
								break;
								}
							break;
							case 'M':
								if (size >= 15 && !memcmp(data + 10, "enu", 3)) {
									switch (data[13]) {
									case 'F':
										if (data[14] == 'g') {
											return (size == 15) ? 437 : -1;
										}
									break;
									case 'B':
										if (data[14] == 'g') {
											if (size >= 19) switch (data[15]) {
											case 'R':
												if (size >= 21 && !memcmp(data + 16, "ipple", 5)) {
													return (size == 21) ? 436 : -1;
												}
											break;
											case 'O':
												if (!memcmp(data + 16, "ver", 3)) {
													return (size == 19) ? 435 : -1;
												}
											break;
											}
											return (size == 15) ? 434 : -1;
										}
									break;
									}
								}
							break;
							case 'F':
								if (size >= 15 && !memcmp(data + 10, "ile", 3)) {
									switch (data[13]) {
									case 'Y':
										if (size >= 27 && !memcmp(data + 14, "ellowCornerFg", 13)) {
											return (size == 27) ? 430 : -1;
										}
									break;
									case 'S':
										if (size >= 19 && !memcmp(data + 14, "izeFg", 5)) {
											return (size == 19) ? 428 : -1;
										}
									break;
									case 'R':
										if (size >= 24 && !memcmp(data + 14, "edCornerFg", 10)) {
											return (size == 24) ? 429 : -1;
										}
									break;
									case 'N':
										if (size >= 19 && !memcmp(data + 14, "ameFg", 5)) {
											return (size == 19) ? 427 : -1;
										}
									break;
									case 'G':
										if (size >= 26 && !memcmp(data + 14, "reenCornerFg", 12)) {
											return (size == 26) ? 431 : -1;
										}
									break;
									case 'E':
										if (size >= 18 && !memcmp(data + 14, "xtFg", 4)) {
											return (size == 18) ? 433 : -1;
										}
									break;
									case 'B':
										switch (data[14]) {
										case 'l':
											if (size >= 25 && !memcmp(data + 15, "ueCornerFg", 10)) {
												return (size == 25) ? 432 : -1;
											}
										break;
										case 'g':
											return (size == 15) ? 426 : -1;
										break;
										}
									break;
									}
								}
							break;
							case 'C':
								if (size >= 18) switch (data[10]) {
								case 'o':
									if (!memcmp(data + 11, "ntrol", 5)) {
										switch (data[16]) {
										case 'F':
											if (data[17] == 'g') {
												return (size == 18) ? 441 : -1;
											}
										break;
										case 'B':
											if (data[17] == 'g') {
												return (size == 18) ? 440 : -1;
											}
										break;
										}
									}
								break;
								case 'a':
									if (!memcmp(data + 11, "ption", 5)) {
										switch (data[16]) {
										case 'F':
											if (data[17] == 'g') {
												return (size == 18) ? 443 : -1;
											}
										break;
										case 'B':
											if (data[17] == 'g') {
												return (size == 18) ? 442 : -1;
											}
										break;
										}
									}
								break;
								}
							break;
							case 'B':
								if (data[10] == 'g') {
									return (size == 11) ? 438 : -1;
								}
							break;
							}
						}
					break;
					case 'P':
						if (size >= 13 && !memcmp(data + 6, "layer", 5)) {
							switch (data[11]) {
							case 'I':
								if (size >= 21 && !memcmp(data + 12, "nactiveFg", 9)) {
									return (size == 21) ? 424 : -1;
								}
							break;
							case 'D':
								if (size >= 21 && !memcmp(data + 12, "isabledFg", 9)) {
									return (size == 21) ? 425 : -1;
								}
							break;
							case 'B':
								if (data[12] == 'g') {
									return (size == 13) ? 422 : -1;
								}
							break;
							case 'A':
								if (!memcmp(data + 12, "ctiveFg", 7)) {
									return (size == 19) ? 423 : -1;
								}
							break;
							}
						}
					break;
					case 'O':
						if (size >= 10 && !memcmp(data + 6, "utFg", 4)) {
							if (size >= 18 && !memcmp(data + 10, "Selected", 8)) {
								return (size == 18) ? 373 : -1;
							}
							return (size == 10) ? 372 : -1;
						}
					break;
					case 'I':
						if (!memcmp(data + 6, "nFg", 3)) {
							if (size >= 17 && !memcmp(data + 9, "Selected", 8)) {
								return (size == 17) ? 371 : -1;
							}
							return (size == 9) ? 370 : -1;
						}
					break;
					}
				}
			break;
			}
		break;
		case 'a':
			switch (data[2]) {
			case 'p':
				if (size >= 11 && !memcmp(data + 3, "PointD", 6)) {
					switch (data[9]) {
					case 'r':
						if (size >= 12 && !memcmp(data + 10, "op", 2)) {
							return (size == 12) ? 401 : -1;
						}
					break;
					case 'o':
						if (data[10] == 't') {
							return (size == 11) ? 402 : -1;
						}
					break;
					}
				}
			break;
			case 'i':
				if (!memcmp(data + 3, "nMenu", 5)) {
					switch (data[8]) {
					case 'C':
						if (size >= 15) switch (data[9]) {
						case 'o':
							if (!memcmp(data + 10, "verBg", 5)) {
								return (size == 15) ? 419 : -1;
							}
						break;
						case 'l':
							if (!memcmp(data + 10, "oud", 3)) {
								switch (data[13]) {
								case 'F':
									if (data[14] == 'g') {
										return (size == 15) ? 420 : -1;
									}
								break;
								case 'B':
									if (data[14] == 'g') {
										return (size == 15) ? 421 : -1;
									}
								break;
								}
							}
						break;
						}
					break;
					case 'B':
						if (data[9] == 'g') {
							return (size == 10) ? 418 : -1;
						}
					break;
					}
				}
			break;
			}
		break;
		}
	break;
	case 'l':
		if (size >= 7) switch (data[1]) {
		case 'i':
			if (size >= 13 && !memcmp(data + 2, "ghtButton", 9)) {
				switch (data[11]) {
				case 'F':
					if (data[12] == 'g') {
						if (size >= 17 && !memcmp(data + 13, "Over", 4)) {
							return (size == 17) ? 34 : -1;
						}
						return (size == 13) ? 33 : -1;
					}
				break;
				case 'B':
					if (data[12] == 'g') {
						if (size >= 17) switch (data[13]) {
						case 'R':
							if (size >= 19 && !memcmp(data + 14, "ipple", 5)) {
								return (size == 19) ? 32 : -1;
							}
						break;
						case 'O':
							if (!memcmp(data + 14, "ver", 3)) {
								return (size == 17) ? 31 : -1;
							}
						break;
						}
						return (size == 13) ? 30 : -1;
					}
				break;
				}
			}
		break;
		case 'a':
			if (!memcmp(data + 2, "yerBg", 5)) {
				return (size == 7) ? 102 : -1;
			}
		break;
		}
	break;
	case 'i':
		if (size >= 7) switch (data[1]) {
		case 'n':
			switch (data[2]) {
			case 't':
				if (!memcmp(data + 3, "ro", 2)) {
					switch (data[5]) {
					case 'T':
						if (size >= 12 && !memcmp(data + 6, "itleFg", 6)) {
							return (size == 12) ? 129 : -1;
						}
					break;
					case 'D':
						if (size >= 18 && !memcmp(data + 6, "escriptionFg", 12)) {
							return (size == 18) ? 130 : -1;
						}
					break;
					case 'C':
						if (size >= 15 && !memcmp(data + 6, "over", 4)) {
							switch (data[10]) {
							case 'T':
								if (!memcmp(data + 11, "opBg", 4)) {
									return (size == 15) ? 131 : -1;
								}
							break;
							case 'P':
								if (size >= 18 && !memcmp(data + 11, "lane", 4)) {
									switch (data[15]) {
									case 'T':
										switch (data[16]) {
										case 'r':
											if (size >= 20 && !memcmp(data + 17, "ace", 3)) {
												return (size == 20) ? 134 : -1;
											}
										break;
										case 'o':
											if (data[17] == 'p') {
												return (size == 18) ? 137 : -1;
											}
										break;
										}
									break;
									case 'O':
										if (!memcmp(data + 16, "uter", 4)) {
											return (size == 20) ? 136 : -1;
										}
									break;
									case 'I':
										if (!memcmp(data + 16, "nner", 4)) {
											return (size == 20) ? 135 : -1;
										}
									break;
									}
								}
							break;
							case 'I':
								if (!memcmp(data + 11, "consFg", 6)) {
									return (size == 17) ? 133 : -1;
								}
							break;
							case 'B':
								if (!memcmp(data + 11, "ottomBg", 7)) {
									return (size == 18) ? 132 : -1;
								}
							break;
							}
						}
					break;
					case 'B':
						if (data[6] == 'g') {
							return (size == 7) ? 128 : -1;
						}
					break;
					}
				}
			break;
			case 'p':
				if (!memcmp(data + 3, "utBorderFg", 10)) {
					return (size == 13) ? 57 : -1;
				}
			break;
			}
		break;
		case 'm':
			switch (data[2]) {
			case 'p':
				if (size >= 18 && !memcmp(data + 3, "ortantTooltip", 13)) {
					switch (data[16]) {
					case 'F':
						if (data[17] == 'g') {
							if (size >= 22 && !memcmp(data + 18, "Link", 4)) {
								return (size == 22) ? 514 : -1;
							}
							return (size == 18) ? 513 : -1;
						}
					break;
					case 'B':
						if (data[17] == 'g') {
							return (size == 18) ? 512 : -1;
						}
					break;
					}
				}
			break;
			case 'a':
				if (!memcmp(data + 3, "geBg", 4)) {
					if (size >= 18 && !memcmp(data + 7, "Transparent", 11)) {
						return (size == 18) ? 20 : -1;
					}
					return (size == 7) ? 19 : -1;
				}
			break;
			}
		break;
		}
	break;
	case 'h':
		if (size >= 14 && !memcmp(data + 1, "istory", 6)) {
			switch (data[7]) {
			case 'V':
				if (size >= 29 && !memcmp(data + 8, "ideoMessageProgressFg", 21)) {
					return (size == 29) ? 358 : -1;
				}
			break;
			case 'U':
				if (size >= 18 && !memcmp(data + 8, "nreadBar", 8)) {
					switch (data[16]) {
					case 'F':
						if (data[17] == 'g') {
							return (size == 18) ? 235 : -1;
						}
					break;
					case 'B':
						switch (data[17]) {
						case 'o':
							if (size >= 22 && !memcmp(data + 18, "rder", 4)) {
								return (size == 22) ? 234 : -1;
							}
						break;
						case 'g':
							return (size == 18) ? 233 : -1;
						break;
						}
					break;
					}
				}
			break;
			case 'T':
				if (size >= 15) switch (data[8]) {
				case 'o':
					if (!memcmp(data + 9, "Down", 4)) {
						switch (data[13]) {
						case 'S':
							if (size >= 19 && !memcmp(data + 14, "hadow", 5)) {
								return (size == 19) ? 385 : -1;
							}
						break;
						case 'F':
							if (data[14] == 'g') {
								if (size >= 19 && !memcmp(data + 15, "Over", 4)) {
									return (size == 19) ? 384 : -1;
								}
								return (size == 15) ? 383 : -1;
							}
						break;
						case 'B':
							if (data[14] == 'g') {
								if (size >= 19) switch (data[15]) {
								case 'R':
									if (size >= 21 && !memcmp(data + 16, "ipple", 5)) {
										return (size == 21) ? 382 : -1;
									}
								break;
								case 'O':
									if (!memcmp(data + 16, "ver", 3)) {
										return (size == 19) ? 381 : -1;
									}
								break;
								}
								return (size == 15) ? 380 : -1;
							}
						break;
						}
					}
				break;
				case 'e':
					if (!memcmp(data + 9, "xt", 2)) {
						switch (data[11]) {
						case 'O':
							if (size >= 16 && !memcmp(data + 12, "utFg", 4)) {
								if (size >= 24 && !memcmp(data + 16, "Selected", 8)) {
									return (size == 24) ? 212 : -1;
								}
								return (size == 16) ? 211 : -1;
							}
						break;
						case 'I':
							if (!memcmp(data + 12, "nFg", 3)) {
								if (size >= 23 && !memcmp(data + 15, "Selected", 8)) {
									return (size == 23) ? 210 : -1;
								}
								return (size == 15) ? 209 : -1;
							}
						break;
						}
					}
				break;
				}
			break;
			case 'S':
				if (size >= 15) switch (data[8]) {
				case 'e':
					if (size >= 17 && !memcmp(data + 9, "nd", 2)) {
						switch (data[11]) {
						case 'i':
							if (size >= 22 && !memcmp(data + 12, "ng", 2)) {
								switch (data[14]) {
								case 'O':
									if (size >= 23 && !memcmp(data + 15, "utIconFg", 8)) {
										return (size == 23) ? 224 : -1;
									}
								break;
								case 'I':
									if (data[15] == 'n') {
										switch (data[16]) {
										case 'v':
											if (size >= 28 && !memcmp(data + 17, "ertedIconFg", 11)) {
												return (size == 28) ? 226 : -1;
											}
										break;
										case 'I':
											if (!memcmp(data + 17, "conFg", 5)) {
												return (size == 22) ? 225 : -1;
											}
										break;
										}
									}
								break;
								}
							}
						break;
						case 'I':
							if (!memcmp(data + 12, "conFg", 5)) {
								if (size >= 21 && !memcmp(data + 17, "Over", 4)) {
									return (size == 21) ? 392 : -1;
								}
								return (size == 17) ? 391 : -1;
							}
						break;
						}
					}
				break;
				case 'c':
					if (!memcmp(data + 9, "rollB", 5)) {
						switch (data[14]) {
						case 'g':
							if (size >= 19 && !memcmp(data + 15, "Over", 4)) {
								return (size == 19) ? 286 : -1;
							}
							return (size == 15) ? 285 : -1;
						break;
						case 'a':
							if (!memcmp(data + 15, "rBg", 3)) {
								if (size >= 22 && !memcmp(data + 18, "Over", 4)) {
									return (size == 22) ? 284 : -1;
								}
								return (size == 18) ? 283 : -1;
							}
						break;
						}
					}
				break;
				}
			break;
			case 'R':
				if (!memcmp(data + 8, "eply", 4)) {
					switch (data[12]) {
					case 'I':
						if (size >= 18 && !memcmp(data + 13, "conFg", 5)) {
							return (size == 18) ? 395 : -1;
						}
					break;
					case 'C':
						if (size >= 20 && !memcmp(data + 13, "ancelFg", 7)) {
							if (size >= 24 && !memcmp(data + 20, "Over", 4)) {
								return (size == 24) ? 397 : -1;
							}
							return (size == 20) ? 396 : -1;
						}
					break;
					case 'B':
						if (data[13] == 'g') {
							return (size == 14) ? 394 : -1;
						}
					break;
					}
				}
			break;
			case 'P':
				switch (data[8]) {
				case 'i':
					if (!memcmp(data + 9, "nnedBg", 6)) {
						return (size == 15) ? 393 : -1;
					}
				break;
				case 'e':
					if (!memcmp(data + 9, "er", 2)) {
						switch (data[11]) {
						case 'U':
							if (size >= 20 && !memcmp(data + 12, "serpicFg", 8)) {
								return (size == 20) ? 262 : -1;
							}
						break;
						case 'S':
							if (size >= 26 && !memcmp(data + 12, "avedMessagesBg", 14)) {
								if (size >= 27 && data[26] == '2') {
									return (size == 27) ? 273 : -1;
								}
								return (size == 26) ? 263 : -1;
							}
						break;
						case 'A':
							if (size >= 27 && !memcmp(data + 12, "rchiveUserpicBg", 15)) {
								return (size == 27) ? 264 : -1;
							}
						break;
						case '8':
							switch (data[12]) {
							case 'U':
								if (size >= 21 && !memcmp(data + 13, "serpicBg", 8)) {
									if (size >= 22 && data[21] == '2') {
										return (size == 22) ? 272 : -1;
									}
									return (size == 21) ? 261 : -1;
								}
							break;
							case 'N':
								if (!memcmp(data + 13, "ameFg", 5)) {
									if (size >= 26 && !memcmp(data + 18, "Selected", 8)) {
										return (size == 26) ? 260 : -1;
									}
									return (size == 18) ? 259 : -1;
								}
							break;
							}
						break;
						case '7':
							switch (data[12]) {
							case 'U':
								if (size >= 21 && !memcmp(data + 13, "serpicBg", 8)) {
									if (size >= 22 && data[21] == '2') {
										return (size == 22) ? 271 : -1;
									}
									return (size == 21) ? 258 : -1;
								}
							break;
							case 'N':
								if (!memcmp(data + 13, "ameFg", 5)) {
									if (size >= 26 && !memcmp(data + 18, "Selected", 8)) {
										return (size == 26) ? 257 : -1;
									}
									return (size == 18) ? 256 : -1;
								}
							break;
							}
						break;
						case '6':
							switch (data[12]) {
							case 'U':
								if (size >= 21 && !memcmp(data + 13, "serpicBg", 8)) {
									if (size >= 22 && data[21] == '2') {
										return (size == 22) ? 270 : -1;
									}
									return (size == 21) ? 255 : -1;
								}
							break;
							case 'N':
								if (!memcmp(data + 13, "ameFg", 5)) {
									if (size >= 26 && !memcmp(data + 18, "Selected", 8)) {
										return (size == 26) ? 254 : -1;
									}
									return (size == 18) ? 253 : -1;
								}
							break;
							}
						break;
						case '5':
							switch (data[12]) {
							case 'U':
								if (size >= 21 && !memcmp(data + 13, "serpicBg", 8)) {
									if (size >= 22 && data[21] == '2') {
										return (size == 22) ? 269 : -1;
									}
									return (size == 21) ? 252 : -1;
								}
							break;
							case 'N':
								if (!memcmp(data + 13, "ameFg", 5)) {
									if (size >= 26 && !memcmp(data + 18, "Selected", 8)) {
										return (size == 26) ? 251 : -1;
									}
									return (size == 18) ? 250 : -1;
								}
							break;
							}
						break;
						case '4':
							switch (data[12]) {
							case 'U':
								if (size >= 21 && !memcmp(data + 13, "serpicBg", 8)) {
									if (size >= 22 && data[21] == '2') {
										return (size == 22) ? 268 : -1;
									}
									return (size == 21) ? 249 : -1;
								}
							break;
							case 'N':
								if (!memcmp(data + 13, "ameFg", 5)) {
									if (size >= 26 && !memcmp(data + 18, "Selected", 8)) {
										return (size == 26) ? 248 : -1;
									}
									return (size == 18) ? 247 : -1;
								}
							break;
							}
						break;
						case '3':
							switch (data[12]) {
							case 'U':
								if (size >= 21 && !memcmp(data + 13, "serpicBg", 8)) {
									if (size >= 22 && data[21] == '2') {
										return (size == 22) ? 267 : -1;
									}
									return (size == 21) ? 246 : -1;
								}
							break;
							case 'N':
								if (!memcmp(data + 13, "ameFg", 5)) {
									if (size >= 26 && !memcmp(data + 18, "Selected", 8)) {
										return (size == 26) ? 245 : -1;
									}
									return (size == 18) ? 244 : -1;
								}
							break;
							}
						break;
						case '2':
							switch (data[12]) {
							case 'U':
								if (size >= 21 && !memcmp(data + 13, "serpicBg", 8)) {
									if (size >= 22 && data[21] == '2') {
										return (size == 22) ? 266 : -1;
									}
									return (size == 21) ? 243 : -1;
								}
							break;
							case 'N':
								if (!memcmp(data + 13, "ameFg", 5)) {
									if (size >= 26 && !memcmp(data + 18, "Selected", 8)) {
										return (size == 26) ? 242 : -1;
									}
									return (size == 18) ? 241 : -1;
								}
							break;
							}
						break;
						case '1':
							switch (data[12]) {
							case 'U':
								if (size >= 21 && !memcmp(data + 13, "serpicBg", 8)) {
									if (size >= 22 && data[21] == '2') {
										return (size == 22) ? 265 : -1;
									}
									return (size == 21) ? 240 : -1;
								}
							break;
							case 'N':
								if (!memcmp(data + 13, "ameFg", 5)) {
									if (size >= 26 && !memcmp(data + 18, "Selected", 8)) {
										return (size == 26) ? 239 : -1;
									}
									return (size == 18) ? 238 : -1;
								}
							break;
							}
						break;
						}
					}
				break;
				}
			break;
			case 'O':
				if (size >= 16 && !memcmp(data + 8, "utIconFg", 8)) {
					if (size >= 24 && !memcmp(data + 16, "Selected", 8)) {
						return (size == 24) ? 222 : -1;
					}
					return (size == 16) ? 221 : -1;
				}
			break;
			case 'L':
				if (!memcmp(data + 8, "ink", 3)) {
					switch (data[11]) {
					case 'O':
						if (size >= 16 && !memcmp(data + 12, "utFg", 4)) {
							if (size >= 24 && !memcmp(data + 16, "Selected", 8)) {
								return (size == 24) ? 216 : -1;
							}
							return (size == 16) ? 215 : -1;
						}
					break;
					case 'I':
						if (!memcmp(data + 12, "nFg", 3)) {
							if (size >= 23 && !memcmp(data + 15, "Selected", 8)) {
								return (size == 23) ? 214 : -1;
							}
							return (size == 15) ? 213 : -1;
						}
					break;
					}
				}
			break;
			case 'I':
				if (size >= 21 && !memcmp(data + 8, "conFgInverted", 13)) {
					return (size == 21) ? 223 : -1;
				}
			break;
			case 'F':
				switch (data[8]) {
				case 'o':
					if (size >= 22 && !memcmp(data + 9, "rwardChoose", 11)) {
						switch (data[20]) {
						case 'F':
							if (data[21] == 'g') {
								return (size == 22) ? 237 : -1;
							}
						break;
						case 'B':
							if (data[21] == 'g') {
								return (size == 22) ? 236 : -1;
							}
						break;
						}
					}
				break;
				case 'i':
					if (!memcmp(data + 9, "le", 2)) {
						switch (data[11]) {
						case 'T':
							if (size >= 22 && !memcmp(data + 12, "humb", 4)) {
								switch (data[16]) {
								case 'R':
									if (size >= 24 && !memcmp(data + 17, "adialFg", 7)) {
										if (size >= 32 && !memcmp(data + 24, "Selected", 8)) {
											return (size == 32) ? 357 : -1;
										}
										return (size == 24) ? 356 : -1;
									}
								break;
								case 'I':
									if (!memcmp(data + 17, "conFg", 5)) {
										if (size >= 30 && !memcmp(data + 22, "Selected", 8)) {
											return (size == 30) ? 355 : -1;
										}
										return (size == 22) ? 354 : -1;
									}
								break;
								}
							}
						break;
						case 'O':
							if (size >= 20 && !memcmp(data + 12, "ut", 2)) {
								switch (data[14]) {
								case 'R':
									if (size >= 22 && !memcmp(data + 15, "adialFg", 7)) {
										if (size >= 30 && !memcmp(data + 22, "Selected", 8)) {
											return (size == 30) ? 353 : -1;
										}
										return (size == 22) ? 352 : -1;
									}
								break;
								case 'I':
									if (!memcmp(data + 15, "conFg", 5)) {
										if (size >= 28 && !memcmp(data + 20, "Selected", 8)) {
											return (size == 28) ? 351 : -1;
										}
										return (size == 20) ? 350 : -1;
									}
								break;
								}
							}
						break;
						case 'N':
							if (!memcmp(data + 12, "ame", 3)) {
								switch (data[15]) {
								case 'O':
									if (size >= 20 && !memcmp(data + 16, "utFg", 4)) {
										if (size >= 28 && !memcmp(data + 20, "Selected", 8)) {
											return (size == 28) ? 220 : -1;
										}
										return (size == 20) ? 219 : -1;
									}
								break;
								case 'I':
									if (!memcmp(data + 16, "nFg", 3)) {
										if (size >= 27 && !memcmp(data + 19, "Selected", 8)) {
											return (size == 27) ? 218 : -1;
										}
										return (size == 19) ? 217 : -1;
									}
								break;
								}
							}
						break;
						case 'I':
							if (data[12] == 'n') {
								switch (data[13]) {
								case 'R':
									if (size >= 21 && !memcmp(data + 14, "adialFg", 7)) {
										if (size >= 29 && !memcmp(data + 21, "Selected", 8)) {
											return (size == 29) ? 349 : -1;
										}
										return (size == 21) ? 348 : -1;
									}
								break;
								case 'I':
									if (!memcmp(data + 14, "conFg", 5)) {
										if (size >= 27 && !memcmp(data + 19, "Selected", 8)) {
											return (size == 27) ? 347 : -1;
										}
										return (size == 19) ? 346 : -1;
									}
								break;
								}
							}
						break;
						}
					}
				break;
				}
			break;
			case 'C':
				switch (data[8]) {
				case 'o':
					if (!memcmp(data + 9, "mpose", 5)) {
						switch (data[14]) {
						case 'I':
							if (!memcmp(data + 15, "conFg", 5)) {
								if (size >= 24 && !memcmp(data + 20, "Over", 4)) {
									return (size == 24) ? 390 : -1;
								}
								return (size == 20) ? 389 : -1;
							}
						break;
						case 'B':
							if (size >= 22 && !memcmp(data + 15, "uttonBg", 7)) {
								if (size >= 26) switch (data[22]) {
								case 'R':
									if (size >= 28 && !memcmp(data + 23, "ipple", 5)) {
										return (size == 28) ? 400 : -1;
									}
								break;
								case 'O':
									if (!memcmp(data + 23, "ver", 3)) {
										return (size == 26) ? 399 : -1;
									}
								break;
								}
								return (size == 22) ? 398 : -1;
							}
						break;
						case 'A':
							if (!memcmp(data + 15, "rea", 3)) {
								switch (data[18]) {
								case 'F':
									if (data[19] == 'g') {
										if (size >= 27 && !memcmp(data + 20, "Service", 7)) {
											return (size == 27) ? 388 : -1;
										}
										return (size == 20) ? 387 : -1;
									}
								break;
								case 'B':
									if (data[19] == 'g') {
										return (size == 20) ? 386 : -1;
									}
								break;
								}
							}
						break;
						}
					}
				break;
				case 'a':
					if (!memcmp(data + 9, "llArrow", 7)) {
						switch (data[16]) {
						case 'O':
							if (size >= 21 && !memcmp(data + 17, "utFg", 4)) {
								if (size >= 29 && !memcmp(data + 21, "Selected", 8)) {
									return (size == 29) ? 232 : -1;
								}
								return (size == 21) ? 231 : -1;
							}
						break;
						case 'M':
							if (size >= 26 && !memcmp(data + 17, "issedInFg", 9)) {
								if (size >= 34 && !memcmp(data + 26, "Selected", 8)) {
									return (size == 34) ? 230 : -1;
								}
								return (size == 26) ? 229 : -1;
							}
						break;
						case 'I':
							if (!memcmp(data + 17, "nFg", 3)) {
								if (size >= 28 && !memcmp(data + 20, "Selected", 8)) {
									return (size == 28) ? 228 : -1;
								}
								return (size == 20) ? 227 : -1;
							}
						break;
						}
					}
				break;
				}
			break;
			}
		}
	break;
	case 'g':
		if (size >= 11 && !memcmp(data + 1, "roupCall", 8)) {
			switch (data[9]) {
			case 'V':
				if (size >= 20 && !memcmp(data + 10, "ideo", 4)) {
					switch (data[14]) {
					case 'T':
						if (!memcmp(data + 15, "extFg", 5)) {
							return (size == 20) ? 506 : -1;
						}
					break;
					case 'S':
						if (!memcmp(data + 15, "ubTextFg", 8)) {
							return (size == 23) ? 507 : -1;
						}
					break;
					}
				}
			break;
			case 'M':
				if (size >= 15) switch (data[10]) {
				case 'u':
					if (!memcmp(data + 11, "ted", 3)) {
						switch (data[14]) {
						case '2':
							return (size == 15) ? 494 : -1;
						break;
						case '1':
							return (size == 15) ? 493 : -1;
						break;
						}
					}
				break;
				case 'e':
					switch (data[11]) {
					case 'n':
						if (!memcmp(data + 12, "uBg", 3)) {
							if (size >= 19) switch (data[15]) {
							case 'R':
								if (size >= 21 && !memcmp(data + 16, "ipple", 5)) {
									return (size == 21) ? 503 : -1;
								}
							break;
							case 'O':
								if (!memcmp(data + 16, "ver", 3)) {
									return (size == 19) ? 502 : -1;
								}
							break;
							}
							return (size == 15) ? 501 : -1;
						}
					break;
					case 'm':
						if (!memcmp(data + 12, "ber", 3)) {
							switch (data[15]) {
							case 's':
								switch (data[16]) {
								case 'F':
									if (data[17] == 'g') {
										return (size == 18) ? 483 : -1;
									}
								break;
								case 'B':
									if (data[17] == 'g') {
										if (size >= 22) switch (data[18]) {
										case 'R':
											if (size >= 24 && !memcmp(data + 19, "ipple", 5)) {
												return (size == 24) ? 482 : -1;
											}
										break;
										case 'O':
											if (!memcmp(data + 19, "ver", 3)) {
												return (size == 22) ? 481 : -1;
											}
										break;
										}
										return (size == 18) ? 480 : -1;
									}
								break;
								}
							break;
							case 'N':
								if (size >= 30 && !memcmp(data + 16, "otJoinedStatus", 14)) {
									return (size == 30) ? 489 : -1;
								}
							break;
							case 'M':
								if (!memcmp(data + 16, "utedIcon", 8)) {
									return (size == 24) ? 488 : -1;
								}
							break;
							case 'I':
								if (size >= 27 && !memcmp(data + 16, "nactive", 7)) {
									switch (data[23]) {
									case 'S':
										if (size >= 29 && !memcmp(data + 24, "tatus", 5)) {
											return (size == 29) ? 487 : -1;
										}
									break;
									case 'I':
										if (!memcmp(data + 24, "con", 3)) {
											return (size == 27) ? 486 : -1;
										}
									break;
									}
								}
							break;
							case 'A':
								if (!memcmp(data + 16, "ctive", 5)) {
									switch (data[21]) {
									case 'S':
										if (size >= 27 && !memcmp(data + 22, "tatus", 5)) {
											return (size == 27) ? 485 : -1;
										}
									break;
									case 'I':
										if (!memcmp(data + 22, "con", 3)) {
											return (size == 25) ? 484 : -1;
										}
									break;
									}
								}
							break;
							}
						}
					break;
					}
				break;
				}
			break;
			case 'L':
				if (size >= 14) switch (data[10]) {
				case 'i':
					if (!memcmp(data + 11, "ve", 2)) {
						switch (data[13]) {
						case '2':
							return (size == 14) ? 492 : -1;
						break;
						case '1':
							return (size == 14) ? 491 : -1;
						break;
						}
					}
				break;
				case 'e':
					if (!memcmp(data + 11, "aveBg", 5)) {
						if (size >= 22 && !memcmp(data + 16, "Ripple", 6)) {
							return (size == 22) ? 505 : -1;
						}
						return (size == 16) ? 504 : -1;
					}
				break;
				}
			break;
			case 'I':
				if (size >= 15 && !memcmp(data + 10, "conFg", 5)) {
					return (size == 15) ? 490 : -1;
				}
			break;
			case 'F':
				if (size >= 20 && !memcmp(data + 10, "orceMuted", 9)) {
					switch (data[19]) {
					case 'B':
						if (size >= 23 && !memcmp(data + 20, "ar", 2)) {
							switch (data[22]) {
							case '3':
								return (size == 23) ? 497 : -1;
							break;
							case '2':
								return (size == 23) ? 496 : -1;
							break;
							case '1':
								return (size == 23) ? 495 : -1;
							break;
							}
						}
					break;
					case '3':
						return (size == 20) ? 500 : -1;
					break;
					case '2':
						return (size == 20) ? 499 : -1;
					break;
					case '1':
						return (size == 20) ? 498 : -1;
					break;
					}
				}
			break;
			case 'B':
				if (data[10] == 'g') {
					return (size == 11) ? 478 : -1;
				}
			break;
			case 'A':
				if (!memcmp(data + 10, "ctiveFg", 7)) {
					return (size == 17) ? 479 : -1;
				}
			break;
			}
		}
	break;
	case 'f':
		if (size >= 19 && !memcmp(data + 1, "ilterInput", 10)) {
			switch (data[11]) {
			case 'I':
				if (size >= 21 && !memcmp(data + 12, "nactiveBg", 9)) {
					return (size == 21) ? 60 : -1;
				}
			break;
			case 'B':
				if (!memcmp(data + 12, "orderFg", 7)) {
					return (size == 19) ? 58 : -1;
				}
			break;
			case 'A':
				if (!memcmp(data + 12, "ctiveBg", 7)) {
					return (size == 19) ? 59 : -1;
				}
			break;
			}
		}
	break;
	case 'e':
		if (size >= 10 && !memcmp(data + 1, "moji", 4)) {
			switch (data[5]) {
			case 'S':
				if (size >= 20 && !memcmp(data + 6, "ubIconFgActive", 14)) {
					return (size == 20) ? 203 : -1;
				}
			break;
			case 'P':
				if (!memcmp(data + 6, "an", 2)) {
					switch (data[8]) {
					case 'H':
						if (size >= 16 && !memcmp(data + 9, "eader", 5)) {
							switch (data[14]) {
							case 'F':
								if (data[15] == 'g') {
									return (size == 16) ? 200 : -1;
								}
							break;
							case 'B':
								if (data[15] == 'g') {
									return (size == 16) ? 201 : -1;
								}
							break;
							}
						}
					break;
					case 'C':
						if (size >= 18 && !memcmp(data + 9, "ategories", 9)) {
							return (size == 18) ? 199 : -1;
						}
					break;
					case 'B':
						if (data[9] == 'g') {
							return (size == 10) ? 198 : -1;
						}
					break;
					}
				}
			break;
			case 'I':
				if (!memcmp(data + 6, "conFg", 5)) {
					return (size == 11) ? 202 : -1;
				}
			break;
			}
		}
	break;
	case 'd':
		if (size >= 9 && !memcmp(data + 1, "ialogs", 6)) {
			switch (data[7]) {
			case 'V':
				if (size >= 21 && !memcmp(data + 8, "erifiedIcon", 11)) {
					switch (data[19]) {
					case 'F':
						if (data[20] == 'g') {
							if (size >= 25) switch (data[21]) {
							case 'O':
								if (!memcmp(data + 22, "ver", 3)) {
									return (size == 25) ? 165 : -1;
								}
							break;
							case 'A':
								if (!memcmp(data + 22, "ctive", 5)) {
									return (size == 27) ? 181 : -1;
								}
							break;
							}
							return (size == 21) ? 148 : -1;
						}
					break;
					case 'B':
						if (data[20] == 'g') {
							if (size >= 25) switch (data[21]) {
							case 'O':
								if (!memcmp(data + 22, "ver", 3)) {
									return (size == 25) ? 164 : -1;
								}
							break;
							case 'A':
								if (!memcmp(data + 22, "ctive", 5)) {
									return (size == 27) ? 180 : -1;
								}
							break;
							}
							return (size == 21) ? 147 : -1;
						}
					break;
					}
				}
			break;
			case 'U':
				if (size >= 15 && !memcmp(data + 8, "nread", 5)) {
					switch (data[13]) {
					case 'F':
						if (data[14] == 'g') {
							if (size >= 19) switch (data[15]) {
							case 'O':
								if (!memcmp(data + 16, "ver", 3)) {
									return (size == 19) ? 170 : -1;
								}
							break;
							case 'A':
								if (!memcmp(data + 16, "ctive", 5)) {
									return (size == 21) ? 186 : -1;
								}
							break;
							}
							return (size == 15) ? 153 : -1;
						}
					break;
					case 'B':
						if (data[14] == 'g') {
							if (size >= 19) switch (data[15]) {
							case 'O':
								if (!memcmp(data + 16, "ver", 3)) {
									return (size == 19) ? 168 : -1;
								}
							break;
							case 'M':
								if (!memcmp(data + 16, "uted", 4)) {
									if (size >= 24) switch (data[20]) {
									case 'O':
										if (!memcmp(data + 21, "ver", 3)) {
											return (size == 24) ? 169 : -1;
										}
									break;
									case 'A':
										if (!memcmp(data + 21, "ctive", 5)) {
											return (size == 26) ? 185 : -1;
										}
									break;
									}
									return (size == 20) ? 152 : -1;
								}
							break;
							case 'A':
								if (!memcmp(data + 16, "ctive", 5)) {
									return (size == 21) ? 184 : -1;
								}
							break;
							}
							return (size == 15) ? 151 : -1;
						}
					break;
					}
				}
			break;
			case 'T':
				if (size >= 13 && !memcmp(data + 8, "extFg", 5)) {
					if (size >= 17) switch (data[13]) {
					case 'S':
						if (size >= 20 && !memcmp(data + 14, "ervice", 6)) {
							if (size >= 24) switch (data[20]) {
							case 'O':
								if (!memcmp(data + 21, "ver", 3)) {
									return (size == 24) ? 162 : -1;
								}
							break;
							case 'A':
								if (!memcmp(data + 21, "ctive", 5)) {
									return (size == 26) ? 178 : -1;
								}
							break;
							}
							return (size == 20) ? 145 : -1;
						}
					break;
					case 'O':
						if (!memcmp(data + 14, "ver", 3)) {
							return (size == 17) ? 161 : -1;
						}
					break;
					case 'A':
						if (!memcmp(data + 14, "ctive", 5)) {
							return (size == 19) ? 177 : -1;
						}
					break;
					}
					return (size == 13) ? 144 : -1;
				}
			break;
			case 'S':
				if (size >= 13) switch (data[8]) {
				case 'e':
					if (size >= 17 && data[9] == 'n') {
						switch (data[10]) {
						case 't':
							if (!memcmp(data + 11, "IconFg", 6)) {
								if (size >= 21) switch (data[17]) {
								case 'O':
									if (!memcmp(data + 18, "ver", 3)) {
										return (size == 21) ? 167 : -1;
									}
								break;
								case 'A':
									if (!memcmp(data + 18, "ctive", 5)) {
										return (size == 23) ? 183 : -1;
									}
								break;
								}
								return (size == 17) ? 150 : -1;
							}
						break;
						case 'd':
							if (!memcmp(data + 11, "ingIconFg", 9)) {
								if (size >= 24) switch (data[20]) {
								case 'O':
									if (!memcmp(data + 21, "ver", 3)) {
										return (size == 24) ? 166 : -1;
									}
								break;
								case 'A':
									if (!memcmp(data + 21, "ctive", 5)) {
										return (size == 26) ? 182 : -1;
									}
								break;
								}
								return (size == 20) ? 149 : -1;
							}
						break;
						}
					}
				break;
				case 'c':
					if (!memcmp(data + 9, "amFg", 4)) {
						if (size >= 17) switch (data[13]) {
						case 'O':
							if (!memcmp(data + 14, "ver", 3)) {
								return (size == 17) ? 172 : -1;
							}
						break;
						case 'A':
							if (!memcmp(data + 14, "ctive", 5)) {
								return (size == 19) ? 188 : -1;
							}
						break;
						}
						return (size == 13) ? 156 : -1;
					}
				break;
				}
			break;
			case 'R':
				if (size >= 15) switch (data[8]) {
				case 'i':
					if (!memcmp(data + 9, "ppleBg", 6)) {
						if (size >= 21 && !memcmp(data + 15, "Active", 6)) {
							return (size == 21) ? 190 : -1;
						}
						return (size == 15) ? 189 : -1;
					}
				break;
				case 'e':
					if (!memcmp(data + 9, "actionIconFg", 12)) {
						return (size == 21) ? 586 : -1;
					}
				break;
				}
			break;
			case 'P':
				if (size >= 17 && !memcmp(data + 8, "ollIconFg", 9)) {
					return (size == 17) ? 587 : -1;
				}
			break;
			case 'O':
				if (size >= 20 && !memcmp(data + 8, "nlineBadgeFg", 12)) {
					if (size >= 26 && !memcmp(data + 20, "Active", 6)) {
						return (size == 26) ? 187 : -1;
					}
					return (size == 20) ? 155 : -1;
				}
			break;
			case 'N':
				if (size >= 13 && !memcmp(data + 8, "ameFg", 5)) {
					if (size >= 17) switch (data[13]) {
					case 'O':
						if (!memcmp(data + 14, "ver", 3)) {
							return (size == 17) ? 158 : -1;
						}
					break;
					case 'A':
						if (!memcmp(data + 14, "ctive", 5)) {
							return (size == 19) ? 174 : -1;
						}
					break;
					}
					return (size == 13) ? 141 : -1;
				}
			break;
			case 'M':
				if (size >= 17 && !memcmp(data + 8, "en", 2)) {
					switch (data[10]) {
					case 'u':
						if (!memcmp(data + 11, "IconFg", 6)) {
							if (size >= 21 && !memcmp(data + 17, "Over", 4)) {
								return (size == 21) ? 139 : -1;
							}
							return (size == 17) ? 138 : -1;
						}
					break;
					case 't':
						if (!memcmp(data + 11, "ionIconFg", 9)) {
							return (size == 20) ? 585 : -1;
						}
					break;
					}
				}
			break;
			case 'D':
				if (size >= 13) switch (data[8]) {
				case 'r':
					if (size >= 14 && !memcmp(data + 9, "aftFg", 5)) {
						if (size >= 18) switch (data[14]) {
						case 'O':
							if (!memcmp(data + 15, "ver", 3)) {
								return (size == 18) ? 163 : -1;
							}
						break;
						case 'A':
							if (!memcmp(data + 15, "ctive", 5)) {
								return (size == 20) ? 179 : -1;
							}
						break;
						}
						return (size == 14) ? 146 : -1;
					}
				break;
				case 'a':
					if (!memcmp(data + 9, "teFg", 4)) {
						if (size >= 17) switch (data[13]) {
						case 'O':
							if (!memcmp(data + 14, "ver", 3)) {
								return (size == 17) ? 160 : -1;
							}
						break;
						case 'A':
							if (!memcmp(data + 14, "ctive", 5)) {
								return (size == 19) ? 176 : -1;
							}
						break;
						}
						return (size == 13) ? 143 : -1;
					}
				break;
				}
			break;
			case 'C':
				if (size >= 17 && !memcmp(data + 8, "hatIconFg", 9)) {
					if (size >= 21) switch (data[17]) {
					case 'O':
						if (!memcmp(data + 18, "ver", 3)) {
							return (size == 21) ? 159 : -1;
						}
					break;
					case 'A':
						if (!memcmp(data + 18, "ctive", 5)) {
							return (size == 23) ? 175 : -1;
						}
					break;
					}
					return (size == 17) ? 142 : -1;
				}
			break;
			case 'B':
				if (data[8] == 'g') {
					if (size >= 13) switch (data[9]) {
					case 'O':
						if (!memcmp(data + 10, "ver", 3)) {
							return (size == 13) ? 157 : -1;
						}
					break;
					case 'A':
						if (!memcmp(data + 10, "ctive", 5)) {
							return (size == 15) ? 173 : -1;
						}
					break;
					}
					return (size == 9) ? 140 : -1;
				}
			break;
			case 'A':
				if (!memcmp(data + 8, "rchiveFg", 8)) {
					if (size >= 20 && !memcmp(data + 16, "Over", 4)) {
						return (size == 20) ? 171 : -1;
					}
					return (size == 16) ? 154 : -1;
				}
			break;
			}
		}
	break;
	case 'c':
		if (size >= 6) switch (data[1]) {
		case 'u':
			if (size >= 10 && !memcmp(data + 2, "rrencyFg", 8)) {
				return (size == 10) ? 581 : -1;
			}
		break;
		case 'r':
			if (size >= 9 && !memcmp(data + 2, "edits", 5)) {
				switch (data[7]) {
				case 'S':
					if (size >= 13 && !memcmp(data + 8, "troke", 5)) {
						return (size == 13) ? 580 : -1;
					}
				break;
				case 'F':
					if (data[8] == 'g') {
						return (size == 9) ? 579 : -1;
					}
				break;
				case 'B':
					if (data[8] == 'g') {
						switch (data[9]) {
						case '3':
							return (size == 10) ? 578 : -1;
						break;
						case '2':
							return (size == 10) ? 577 : -1;
						break;
						case '1':
							return (size == 10) ? 576 : -1;
						break;
						}
					}
				break;
				}
			}
		break;
		case 'o':
			if (size >= 10 && !memcmp(data + 2, "ntacts", 6)) {
				switch (data[8]) {
				case 'S':
					if (size >= 16 && !memcmp(data + 9, "tatusFg", 7)) {
						if (size >= 20 && data[16] == 'O') {
							switch (data[17]) {
							case 'v':
								if (!memcmp(data + 18, "er", 2)) {
									return (size == 20) ? 122 : -1;
								}
							break;
							case 'n':
								if (!memcmp(data + 18, "line", 4)) {
									return (size == 22) ? 123 : -1;
								}
							break;
							}
						}
						return (size == 16) ? 121 : -1;
					}
				break;
				case 'N':
					if (size >= 14 && !memcmp(data + 9, "ameFg", 5)) {
						return (size == 14) ? 120 : -1;
					}
				break;
				case 'B':
					if (data[9] == 'g') {
						if (size >= 14 && !memcmp(data + 10, "Over", 4)) {
							return (size == 14) ? 119 : -1;
						}
						return (size == 10) ? 118 : -1;
					}
				break;
				}
			}
		break;
		case 'h':
			if (size >= 10 && !memcmp(data + 2, "eckboxFg", 8)) {
				return (size == 10) ? 61 : -1;
			}
		break;
		case 'a':
			switch (data[2]) {
			case 'n':
				if (size >= 12 && !memcmp(data + 3, "celIconFg", 9)) {
					if (size >= 16 && !memcmp(data + 12, "Over", 4)) {
						return (size == 16) ? 104 : -1;
					}
					return (size == 12) ? 103 : -1;
				}
			break;
			case 'l':
				if (data[3] == 'l') {
					switch (data[4]) {
					case 'S':
						if (size >= 12 && !memcmp(data + 5, "tatusFg", 7)) {
							return (size == 12) ? 466 : -1;
						}
					break;
					case 'N':
						if (size >= 10 && !memcmp(data + 5, "ameFg", 5)) {
							return (size == 10) ? 465 : -1;
						}
					break;
					case 'M':
						if (size >= 14 && !memcmp(data + 5, "uteRipple", 9)) {
							return (size == 14) ? 477 : -1;
						}
					break;
					case 'I':
						if (size >= 10 && !memcmp(data + 5, "con", 3)) {
							switch (data[8]) {
							case 'F':
								if (data[9] == 'g') {
									if (size >= 16 && !memcmp(data + 10, "Active", 6)) {
										return (size == 16) ? 470 : -1;
									}
									return (size == 10) ? 468 : -1;
								}
							break;
							case 'B':
								if (data[9] == 'g') {
									if (size >= 16 && !memcmp(data + 10, "Active", 6)) {
										return (size == 16) ? 469 : -1;
									}
									return (size == 10) ? 467 : -1;
								}
							break;
							case 'A':
								if (!memcmp(data + 9, "ctiveRipple", 11)) {
									return (size == 20) ? 471 : -1;
								}
							break;
							}
						}
					break;
					case 'H':
						if (size >= 12 && !memcmp(data + 5, "angup", 5)) {
							switch (data[10]) {
							case 'R':
								if (size >= 16 && !memcmp(data + 11, "ipple", 5)) {
									return (size == 16) ? 476 : -1;
								}
							break;
							case 'B':
								if (data[11] == 'g') {
									return (size == 12) ? 475 : -1;
								}
							break;
							}
						}
					break;
					case 'B':
						switch (data[5]) {
						case 'g':
							if (size >= 12) switch (data[6]) {
							case 'O':
								if (!memcmp(data + 7, "paque", 5)) {
									return (size == 12) ? 463 : -1;
								}
							break;
							case 'B':
								if (!memcmp(data + 7, "utton", 5)) {
									return (size == 12) ? 464 : -1;
								}
							break;
							}
							return (size == 6) ? 462 : -1;
						break;
						case 'a':
							if (data[6] == 'r') {
								switch (data[7]) {
								case 'M':
									if (size >= 17 && !memcmp(data + 8, "uteRipple", 9)) {
										return (size == 17) ? 509 : -1;
									}
								break;
								case 'F':
									if (data[8] == 'g') {
										return (size == 9) ? 511 : -1;
									}
								break;
								case 'B':
									if (data[8] == 'g') {
										if (size >= 14 && !memcmp(data + 9, "Muted", 5)) {
											return (size == 14) ? 510 : -1;
										}
										return (size == 9) ? 508 : -1;
									}
								break;
								}
							}
						break;
						}
					break;
					case 'A':
						switch (data[5]) {
						case 'r':
							if (!memcmp(data + 6, "row", 3)) {
								switch (data[9]) {
								case 'M':
									if (size >= 17 && !memcmp(data + 10, "issedFg", 7)) {
										return (size == 17) ? 127 : -1;
									}
								break;
								case 'F':
									if (data[10] == 'g') {
										return (size == 11) ? 126 : -1;
									}
								break;
								}
							}
						break;
						case 'n':
							if (!memcmp(data + 6, "swer", 4)) {
								switch (data[10]) {
								case 'R':
									if (size >= 16 && !memcmp(data + 11, "ipple", 5)) {
										return (size == 16) ? 473 : -1;
									}
								break;
								case 'B':
									if (data[11] == 'g') {
										if (size >= 17 && !memcmp(data + 12, "Outer", 5)) {
											return (size == 17) ? 474 : -1;
										}
										return (size == 12) ? 472 : -1;
									}
								break;
								}
							}
						break;
						}
					break;
					}
				}
			break;
			}
		break;
		}
	break;
	case 'b':
		if (data[1] == 'o') {
			switch (data[2]) {
			case 'x':
				switch (data[3]) {
				case 'T':
					if (size >= 9) switch (data[4]) {
					case 'i':
						if (size >= 10 && !memcmp(data + 5, "tle", 3)) {
							switch (data[8]) {
							case 'F':
								if (data[9] == 'g') {
									return (size == 10) ? 109 : -1;
								}
							break;
							case 'C':
								if (!memcmp(data + 9, "loseFg", 6)) {
									if (size >= 19 && !memcmp(data + 15, "Over", 4)) {
										return (size == 19) ? 113 : -1;
									}
									return (size == 15) ? 112 : -1;
								}
							break;
							case 'A':
								if (!memcmp(data + 9, "dditionalFg", 11)) {
									return (size == 20) ? 111 : -1;
								}
							break;
							}
						}
					break;
					case 'e':
						if (!memcmp(data + 5, "xtFg", 4)) {
							if (size >= 13) switch (data[9]) {
							case 'G':
								if (!memcmp(data + 10, "ood", 3)) {
									return (size == 13) ? 107 : -1;
								}
							break;
							case 'E':
								if (!memcmp(data + 10, "rror", 4)) {
									return (size == 14) ? 108 : -1;
								}
							break;
							}
							return (size == 9) ? 106 : -1;
						}
					break;
					}
				break;
				case 'S':
					if (size >= 11 && !memcmp(data + 4, "earchBg", 7)) {
						return (size == 11) ? 110 : -1;
					}
				break;
				case 'D':
					if (size >= 12 && !memcmp(data + 4, "ivider", 6)) {
						switch (data[10]) {
						case 'F':
							if (data[11] == 'g') {
								return (size == 12) ? 115 : -1;
							}
						break;
						case 'B':
							if (data[11] == 'g') {
								return (size == 12) ? 114 : -1;
							}
						break;
						}
					}
				break;
				case 'B':
					if (data[4] == 'g') {
						return (size == 5) ? 105 : -1;
					}
				break;
				}
			break;
			case 't':
				if (!memcmp(data + 3, "Kb", 2)) {
					switch (data[5]) {
					case 'S':
						if (size >= 14 && !memcmp(data + 6, "uccessBg", 8)) {
							return (size == 14) ? 67 : -1;
						}
					break;
					case 'P':
						if (size >= 14 && !memcmp(data + 6, "rimaryBg", 8)) {
							return (size == 14) ? 65 : -1;
						}
					break;
					case 'I':
						if (size >= 19 && !memcmp(data + 6, "nline", 5)) {
							switch (data[11]) {
							case 'S':
								if (size >= 20 && !memcmp(data + 12, "uccessBg", 8)) {
									return (size == 20) ? 70 : -1;
								}
							break;
							case 'P':
								if (size >= 20 && !memcmp(data + 12, "rimaryBg", 8)) {
									return (size == 20) ? 68 : -1;
								}
							break;
							case 'D':
								if (!memcmp(data + 12, "angerBg", 7)) {
									return (size == 19) ? 69 : -1;
								}
							break;
							}
						}
					break;
					case 'D':
						if (size >= 11) switch (data[6]) {
						case 'o':
							if (!memcmp(data + 7, "wnBg", 4)) {
								return (size == 11) ? 63 : -1;
							}
						break;
						case 'a':
							if (!memcmp(data + 7, "ngerBg", 6)) {
								return (size == 13) ? 66 : -1;
							}
						break;
						}
					break;
					case 'C':
						if (size >= 10 && !memcmp(data + 6, "olor", 4)) {
							return (size == 10) ? 64 : -1;
						}
					break;
					case 'B':
						if (data[6] == 'g') {
							return (size == 7) ? 62 : -1;
						}
					break;
					}
				}
			break;
			}
		}
	break;
	case 'a':
		switch (data[1]) {
		case 't':
			if (size >= 17 && !memcmp(data + 2, "tentionButton", 13)) {
				switch (data[15]) {
				case 'F':
					if (data[16] == 'g') {
						if (size >= 21 && !memcmp(data + 17, "Over", 4)) {
							return (size == 21) ? 36 : -1;
						}
						return (size == 17) ? 35 : -1;
					}
				break;
				case 'B':
					if (data[16] == 'g') {
						switch (data[17]) {
						case 'R':
							if (size >= 23 && !memcmp(data + 18, "ipple", 5)) {
								return (size == 23) ? 38 : -1;
							}
						break;
						case 'O':
							if (!memcmp(data + 18, "ver", 3)) {
								return (size == 21) ? 37 : -1;
							}
						break;
						}
					}
				break;
				}
			}
		break;
		case 'c':
			if (!memcmp(data + 2, "tive", 4)) {
				switch (data[6]) {
				case 'L':
					if (!memcmp(data + 7, "ineFg", 5)) {
						if (size >= 17 && !memcmp(data + 12, "Error", 5)) {
							return (size == 17) ? 29 : -1;
						}
						return (size == 12) ? 28 : -1;
					}
				break;
				case 'B':
					if (!memcmp(data + 7, "utton", 5)) {
						switch (data[12]) {
						case 'S':
							if (size >= 23 && !memcmp(data + 13, "econdaryFg", 10)) {
								if (size >= 27 && !memcmp(data + 23, "Over", 4)) {
									return (size == 27) ? 27 : -1;
								}
								return (size == 23) ? 26 : -1;
							}
						break;
						case 'F':
							if (data[13] == 'g') {
								if (size >= 18 && !memcmp(data + 14, "Over", 4)) {
									return (size == 18) ? 25 : -1;
								}
								return (size == 14) ? 24 : -1;
							}
						break;
						case 'B':
							if (data[13] == 'g') {
								if (size >= 18) switch (data[14]) {
								case 'R':
									if (size >= 20 && !memcmp(data + 15, "ipple", 5)) {
										return (size == 20) ? 23 : -1;
									}
								break;
								case 'O':
									if (!memcmp(data + 15, "ver", 3)) {
										return (size == 18) ? 22 : -1;
									}
								break;
								}
								return (size == 14) ? 21 : -1;
							}
						break;
						}
					}
				break;
				}
			}
		break;
		}
	break;
	}

	return -1;
}

} // namespace internal

namespace main_palette {

not_null<const palette*> get() {
	return &_palette;
}

QList<row> data() {
	auto result = QList<row>();
	result.reserve(588);

	result.push_back({ qstr("windowBg"), qstr("#ffffff"), qstr(""), qstr("white: fallback for background") });
	result.push_back({ qstr("windowFg"), qstr("#000000"), qstr(""), qstr("black: fallback for text") });
	result.push_back({ qstr("windowBgOver"), qstr("#f1f1f1"), qstr(""), qstr("light gray: fallback for background with mouse over") });
	result.push_back({ qstr("windowBgRipple"), qstr("#e5e5e5"), qstr(""), qstr("darker gray: fallback for ripple effect") });
	result.push_back({ qstr("windowFgOver"), qstr("windowFg"), qstr(""), qstr("black: fallback for text with mouse over") });
	result.push_back({ qstr("windowSubTextFg"), qstr("#999999"), qstr(""), qstr("gray: fallback for additional text") });
	result.push_back({ qstr("windowSubTextFgOver"), qstr("#919191"), qstr(""), qstr("darker gray: fallback for additional text with mouse over") });
	result.push_back({ qstr("windowBoldFg"), qstr("#222222"), qstr(""), qstr("dark gray: fallback for bold text") });
	result.push_back({ qstr("windowBoldFgOver"), qstr("#222222"), qstr(""), qstr("dark gray: fallback for bold text with mouse over") });
	result.push_back({ qstr("windowBgActive"), qstr("#40a7e3"), qstr(""), qstr("bright blue: fallback for blue filled active areas") });
	result.push_back({ qstr("windowFgActive"), qstr("#ffffff"), qstr(""), qstr("white: fallback for text on active areas") });
	result.push_back({ qstr("windowActiveTextFg"), qstr("#168acd"), qstr(""), qstr("online blue: fallback for active text like online status") });
	result.push_back({ qstr("windowShadowFg"), qstr("#000000"), qstr(""), qstr("black: fallback for shadow") });
	result.push_back({ qstr("windowShadowFgFallback"), qstr("#f1f1f1"), qstr(""), qstr("gray: fallback for shadow without opacity") });
	result.push_back({ qstr("shadowFg"), qstr("#00000018"), qstr(""), qstr("most shadows (including opacity)") });
	result.push_back({ qstr("slideFadeOutBg"), qstr("#0000003c"), qstr(""), qstr("slide animation (chat to profile) fade out filling") });
	result.push_back({ qstr("slideFadeOutShadowFg"), qstr("windowShadowFg"), qstr(""), qstr("slide animation (chat to profile) fade out right section shadow") });
	result.push_back({ qstr("imageBg"), qstr("#000000"), qstr(""), qstr("image background fallback (when photo size is less than minimum allowed)") });
	result.push_back({ qstr("imageBgTransparent"), qstr("#ffffff"), qstr(""), qstr("image background when displaying an image with opacity where no opacity is needed") });
	result.push_back({ qstr("activeButtonBg"), qstr("windowBgActive"), qstr(""), qstr("default active button background") });
	result.push_back({ qstr("activeButtonBgOver"), qstr("#39a5db"), qstr(""), qstr("default active button background with mouse over") });
	result.push_back({ qstr("activeButtonBgRipple"), qstr("#2095d0"), qstr(""), qstr("default active button ripple effect") });
	result.push_back({ qstr("activeButtonFg"), qstr("windowFgActive"), qstr(""), qstr("default active button text") });
	result.push_back({ qstr("activeButtonFgOver"), qstr("activeButtonFg"), qstr(""), qstr("default active button text with mouse over") });
	result.push_back({ qstr("activeButtonSecondaryFg"), qstr("#cceeff"), qstr(""), qstr("\
default active button additional text (selected messages counter in forward / del\
ete buttons)") });
	result.push_back({ qstr("activeButtonSecondaryFgOver"), qstr("activeButtonSecondaryFg"), qstr(""), qstr("default active button additional text with mouse over") });
	result.push_back({ qstr("activeLineFg"), qstr("#37a1de"), qstr(""), qstr("\
default active line (like code input field bottom border when you log in and fiel\
d is focused)") });
	result.push_back({ qstr("activeLineFgError"), qstr("#e48383"), qstr(""), qstr("\
default active line for error state (like code input field bottom border when you\
 log in and you've entered incorrect code)") });
	result.push_back({ qstr("lightButtonBg"), qstr("windowBg"), qstr(""), qstr("default light button background (like buttons in boxes)") });
	result.push_back({ qstr("lightButtonBgOver"), qstr("#e3f1fa"), qstr(""), qstr("default light button background with mouse over") });
	result.push_back({ qstr("lightButtonBgRipple"), qstr("#c9e4f6"), qstr(""), qstr("default light button ripple effect") });
	result.push_back({ qstr("lightButtonFg"), qstr("windowActiveTextFg"), qstr(""), qstr("default light button text") });
	result.push_back({ qstr("lightButtonFgOver"), qstr("lightButtonFg"), qstr(""), qstr("default light button text with mouse over") });
	result.push_back({ qstr("attentionButtonFg"), qstr("#d14e4e"), qstr(""), qstr("default attention button text (like confirm button on log out)") });
	result.push_back({ qstr("attentionButtonFgOver"), qstr("#d14e4e"), qstr(""), qstr("default attention button text with mouse over") });
	result.push_back({ qstr("attentionButtonBgOver"), qstr("#fcdfde"), qstr(""), qstr("default attention button background with mouse over") });
	result.push_back({ qstr("attentionButtonBgRipple"), qstr("#f4c3c2"), qstr(""), qstr("default attention button ripple effect") });
	result.push_back({ qstr("menuBg"), qstr("windowBg"), qstr(""), qstr("default popup menu background") });
	result.push_back({ qstr("menuBgOver"), qstr("windowBgOver"), qstr(""), qstr("default popup menu item background with mouse over") });
	result.push_back({ qstr("menuBgRipple"), qstr("windowBgRipple"), qstr(""), qstr("default popup menu item ripple effect") });
	result.push_back({ qstr("menuIconFg"), qstr("#999999"), qstr(""), qstr("default popup menu item icon (like main menu)") });
	result.push_back({ qstr("menuIconFgOver"), qstr("#8a8a8a"), qstr(""), qstr("default popup menu item icon with mouse over") });
	result.push_back({ qstr("menuSubmenuArrowFg"), qstr("#373737"), qstr(""), qstr("\
default popup menu submenu arrow icon (like in message field context menu in case\
 of RTL system language)") });
	result.push_back({ qstr("menuFgDisabled"), qstr("#cccccc"), qstr(""), qstr("\
default popup menu item disabled text (like unavailable items in message field co\
ntext menu)") });
	result.push_back({ qstr("menuSeparatorFg"), qstr("#f1f1f1"), qstr(""), qstr("default popup menu separator (like in message field context menu)") });
	result.push_back({ qstr("scrollBarBg"), qstr("#00000053"), qstr(""), qstr("default scroll bar current rectangle, the bar itself (like in chats list)") });
	result.push_back({ qstr("scrollBarBgOver"), qstr("#0000007a"), qstr(""), qstr("default scroll bar current rectangle with mouse over it") });
	result.push_back({ qstr("scrollBg"), qstr("#0000001a"), qstr(""), qstr("default scroll bar background") });
	result.push_back({ qstr("scrollBgOver"), qstr("#0000002c"), qstr(""), qstr("default scroll bar background with mouse over the scroll bar") });
	result.push_back({ qstr("smallCloseIconFg"), qstr("#c7c7c7"), qstr(""), qstr("\
small X icon (like in Show all sessions box to the right for sessions termination\
)") });
	result.push_back({ qstr("smallCloseIconFgOver"), qstr("#a3a3a3"), qstr(""), qstr("small X icon with mouse over") });
	result.push_back({ qstr("radialFg"), qstr("windowFgActive"), qstr(""), qstr("default radial loader line (like in Media Viewer when loading a photo)") });
	result.push_back({ qstr("radialBg"), qstr("#00000056"), qstr(""), qstr("default radial loader background (like in Media Viewer when loading a photo)") });
	result.push_back({ qstr("placeholderFg"), qstr("windowSubTextFg"), qstr(""), qstr("\
default input field placeholder when field is not focused (like in phone input fi\
eld when you log in)") });
	result.push_back({ qstr("placeholderFgActive"), qstr("#aaaaaa"), qstr(""), qstr("default input field placeholder when field is focused") });
	result.push_back({ qstr("inputBorderFg"), qstr("#e0e0e0"), qstr(""), qstr("\
default input field bottom border (like in code input field when you log in and f\
ield is not focused)") });
	result.push_back({ qstr("filterInputBorderFg"), qstr("#54c3f3"), qstr(""), qstr("\
default rounded input field border (like in chats list search field when field is\
 focused)") });
	result.push_back({ qstr("filterInputActiveBg"), qstr("windowBg"), qstr(""), qstr("\
default rounded input field active background (like in chats list search field wh\
en field is focused)") });
	result.push_back({ qstr("filterInputInactiveBg"), qstr("windowBgOver"), qstr(""), qstr("\
default rounded input field inactive background (like in chats list search field \
when field is inactive)") });
	result.push_back({ qstr("checkboxFg"), qstr("#b3b3b3"), qstr(""), qstr("default unchecked checkbox rounded rectangle") });
	result.push_back({ qstr("botKbBg"), qstr("menuBgOver"), qstr(""), qstr("bot keyboard button background") });
	result.push_back({ qstr("botKbDownBg"), qstr("menuBgRipple"), qstr(""), qstr("bot keyboard button ripple effect") });
	result.push_back({ qstr("botKbColor"), qstr("windowBoldFgOver"), qstr(""), qstr("bot keyboard button text") });
	result.push_back({ qstr("botKbPrimaryBg"), qstr("#298acfcc"), qstr(""), qstr("bot keyboard Primary button background") });
	result.push_back({ qstr("botKbDangerBg"), qstr("#e05356cc"), qstr(""), qstr("bot keyboard Danger button background") });
	result.push_back({ qstr("botKbSuccessBg"), qstr("#61c752cc"), qstr(""), qstr("bot keyboard Success button background") });
	result.push_back({ qstr("botKbInlinePrimaryBg"), qstr("#378eaeb3"), qstr(""), qstr("inline bot keyboard Primary button background") });
	result.push_back({ qstr("botKbInlineDangerBg"), qstr("#c9543eb3"), qstr(""), qstr("inline bot keyboard Danger button background") });
	result.push_back({ qstr("botKbInlineSuccessBg"), qstr("#489d38b3"), qstr(""), qstr("inline bot keyboard Success button background") });
	result.push_back({ qstr("sliderBgInactive"), qstr("#e1eaef"), qstr(""), qstr("\
default slider not active bar (like in Settings when you choose interface scale o\
r custom notifications count)") });
	result.push_back({ qstr("sliderBgActive"), qstr("windowBgActive"), qstr(""), qstr("\
default slider active bar (like in Settings when you choose interface scale or cu\
stom notifications count)") });
	result.push_back({ qstr("tooltipBg"), qstr("#eef2f5"), qstr(""), qstr("tooltip background (like when you put mouse over the message timestamp and wait)") });
	result.push_back({ qstr("tooltipFg"), qstr("#5d6c80"), qstr(""), qstr("tooltip text") });
	result.push_back({ qstr("tooltipBorderFg"), qstr("#c9d1db"), qstr(""), qstr("tooltip border") });
	result.push_back({ qstr("titleShadow"), qstr("#00000003"), qstr(""), qstr("one pixel line shadow at the bottom of custom window title") });
	result.push_back({ qstr("titleBg"), qstr("windowBgOver"), qstr(""), qstr("custom window title background when window is inactive") });
	result.push_back({ qstr("titleBgActive"), qstr("titleBg"), qstr(""), qstr("custom window title background when window is active") });
	result.push_back({ qstr("titleButtonBg"), qstr("titleBg"), qstr(""), qstr("\
custom window title minimize/maximize/restore button background when window is in\
active (Windows only)") });
	result.push_back({ qstr("titleButtonFg"), qstr("#ababab"), qstr(""), qstr("\
custom window title minimize/maximize/restore button icon when window is inactive\
 (Windows only)") });
	result.push_back({ qstr("titleButtonBgOver"), qstr("#e5e5e5"), qstr(""), qstr("\
custom window title minimize/maximize/restore button background with mouse over w\
hen window is inactive (Windows only)") });
	result.push_back({ qstr("titleButtonFgOver"), qstr("#9a9a9a"), qstr(""), qstr("\
custom window title minimize/maximize/restore button icon with mouse over when wi\
ndow is inactive (Windows only)") });
	result.push_back({ qstr("titleButtonBgActive"), qstr("titleButtonBg"), qstr(""), qstr("\
custom window title minimize/maximize/restore button background when window is ac\
tive (Windows only)") });
	result.push_back({ qstr("titleButtonFgActive"), qstr("titleButtonFg"), qstr(""), qstr("\
custom window title minimize/maximize/restore button icon when window is active (\
Windows only)") });
	result.push_back({ qstr("titleButtonBgActiveOver"), qstr("titleButtonBgOver"), qstr(""), qstr("\
custom window title minimize/maximize/restore button background with mouse over w\
hen window is active (Windows only)") });
	result.push_back({ qstr("titleButtonFgActiveOver"), qstr("titleButtonFgOver"), qstr(""), qstr("\
custom window title minimize/maximize/restore button icon with mouse over when wi\
ndow is active (Windows only)") });
	result.push_back({ qstr("titleButtonCloseBg"), qstr("titleButtonBg"), qstr(""), qstr("\
custom window title close button background when window is inactive (Windows only\
)") });
	result.push_back({ qstr("titleButtonCloseFg"), qstr("titleButtonFg"), qstr(""), qstr("custom window title close button icon when window is inactive (Windows only)") });
	result.push_back({ qstr("titleButtonCloseBgOver"), qstr("#e81123"), qstr(""), qstr("\
custom window title close button background with mouse over when window is inacti\
ve (Windows only)") });
	result.push_back({ qstr("titleButtonCloseFgOver"), qstr("windowFgActive"), qstr(""), qstr("\
custom window title close button icon with mouse over when window is inactive (Wi\
ndows only)") });
	result.push_back({ qstr("titleButtonCloseBgActive"), qstr("titleButtonCloseBg"), qstr(""), qstr("custom window title close button background when window is active (Windows only)") });
	result.push_back({ qstr("titleButtonCloseFgActive"), qstr("titleButtonCloseFg"), qstr(""), qstr("custom window title close button icon when window is active (Windows only)") });
	result.push_back({ qstr("titleButtonCloseBgActiveOver"), qstr("titleButtonCloseBgOver"), qstr(""), qstr("\
custom window title close button background with mouse over when window is active\
 (Windows only)") });
	result.push_back({ qstr("titleButtonCloseFgActiveOver"), qstr("titleButtonCloseFgOver"), qstr(""), qstr("\
custom window title close button icon with mouse over when window is active (Wind\
ows only)") });
	result.push_back({ qstr("titleFg"), qstr("#acacac"), qstr(""), qstr("custom window title text when window is inactive (Windows 11 and macOS)") });
	result.push_back({ qstr("titleFgActive"), qstr("#3e3c3e"), qstr(""), qstr("custom window title text when window is active (Windows 11 and macOS)") });
	result.push_back({ qstr("trayCounterBg"), qstr("#f23c34"), qstr(""), qstr("tray icon counter background") });
	result.push_back({ qstr("trayCounterBgMute"), qstr("#888888"), qstr(""), qstr("tray icon counter background if all unread messages are muted") });
	result.push_back({ qstr("trayCounterFg"), qstr("#ffffff"), qstr(""), qstr("tray icon counter text") });
	result.push_back({ qstr("trayCounterBgMacInvert"), qstr("#ffffff"), qstr(""), qstr("\
tray icon counter background when tray icon is pressed or when dark theme of macO\
S is used (macOS only)") });
	result.push_back({ qstr("trayCounterFgMacInvert"), qstr("#ffffff01"), qstr(""), qstr("\
tray icon counter text when tray icon is pressed or when dark theme of macOS is u\
sed (macOS only)") });
	result.push_back({ qstr("layerBg"), qstr("#0000007f"), qstr(""), qstr("box and main menu background layer fade") });
	result.push_back({ qstr("cancelIconFg"), qstr("menuIconFg"), qstr(""), qstr("default for settings close icon and box search cancel icon") });
	result.push_back({ qstr("cancelIconFgOver"), qstr("menuIconFgOver"), qstr(""), qstr("default for settings close icon and box search cancel icon with mouse over") });
	result.push_back({ qstr("boxBg"), qstr("windowBg"), qstr(""), qstr("box background") });
	result.push_back({ qstr("boxTextFg"), qstr("windowFg"), qstr(""), qstr("box text") });
	result.push_back({ qstr("boxTextFgGood"), qstr("#4ab44a"), qstr(""), qstr("accepted box text (like when choosing username that is not occupied)") });
	result.push_back({ qstr("boxTextFgError"), qstr("#d84d4d"), qstr(""), qstr("rejecting box text (like when choosing username that is occupied)") });
	result.push_back({ qstr("boxTitleFg"), qstr("#404040"), qstr(""), qstr("box title text") });
	result.push_back({ qstr("boxSearchBg"), qstr("boxBg"), qstr(""), qstr("box search field background (like in contacts box)") });
	result.push_back({ qstr("boxTitleAdditionalFg"), qstr("#808080"), qstr(""), qstr("\
box title additional text (like in create group box when you see chosen members c\
ount)") });
	result.push_back({ qstr("boxTitleCloseFg"), qstr("cancelIconFg"), qstr(""), qstr("settings close icon and box search cancel icon (like in contacts box)") });
	result.push_back({ qstr("boxTitleCloseFgOver"), qstr("cancelIconFgOver"), qstr(""), qstr("\
settings close icon and box search cancel icon (like in contacts box) with mouse \
over") });
	result.push_back({ qstr("boxDividerBg"), qstr("windowBgOver"), qstr(""), qstr("gray divider in boxes and layers") });
	result.push_back({ qstr("boxDividerFg"), qstr("windowShadowFg"), qstr(""), qstr("gray divider shadow in boxes and layers") });
	result.push_back({ qstr("paymentsTipActive"), qstr("#01ad0f"), qstr(""), qstr("tip button text in payments checkout form") });
	result.push_back({ qstr("membersAboutLimitFg"), qstr("windowSubTextFgOver"), qstr(""), qstr("text in channel members box about the limit (max 200 last members are shown)") });
	result.push_back({ qstr("contactsBg"), qstr("windowBg"), qstr(""), qstr("contacts (and some other) box row background") });
	result.push_back({ qstr("contactsBgOver"), qstr("windowBgOver"), qstr(""), qstr("contacts (and some other) box row background with mouse over") });
	result.push_back({ qstr("contactsNameFg"), qstr("boxTextFg"), qstr(""), qstr("contacts (and some other) box row name text") });
	result.push_back({ qstr("contactsStatusFg"), qstr("windowSubTextFg"), qstr(""), qstr("contacts (and some other) box row additional text (like last seen stamp)") });
	result.push_back({ qstr("contactsStatusFgOver"), qstr("windowSubTextFgOver"), qstr(""), qstr("\
contacts (and some other) box row additional text (like last seen stamp) with mou\
se over") });
	result.push_back({ qstr("contactsStatusFgOnline"), qstr("windowActiveTextFg"), qstr(""), qstr("contacts (and some other) box row active additional text (like online status)") });
	result.push_back({ qstr("photoCropFadeBg"), qstr("layerBg"), qstr(""), qstr("\
avatar crop box fade background (when choosing a new photo in Settings or for a g\
roup)") });
	result.push_back({ qstr("photoCropPointFg"), qstr("#ffffff7f"), qstr(""), qstr("\
avatar crop box corner rectangles (when choosing a new photo in Settings or for a\
 group)") });
	result.push_back({ qstr("callArrowFg"), qstr("#2dad2d"), qstr("boxTextFgGood"), qstr("received phone call arrow (in calls list box)") });
	result.push_back({ qstr("callArrowMissedFg"), qstr("#dd5b4a"), qstr("boxTextFgError"), qstr("missed phone call arrow (in calls list box)") });
	result.push_back({ qstr("introBg"), qstr("windowBg"), qstr(""), qstr("login background") });
	result.push_back({ qstr("introTitleFg"), qstr("windowBoldFg"), qstr(""), qstr("login title text") });
	result.push_back({ qstr("introDescriptionFg"), qstr("windowSubTextFg"), qstr(""), qstr("login description text") });
	result.push_back({ qstr("introCoverTopBg"), qstr("#0f89d0"), qstr(""), qstr("intro gradient top (from)") });
	result.push_back({ qstr("introCoverBottomBg"), qstr("#39b0f0"), qstr(""), qstr("intro gradient bottom (to)") });
	result.push_back({ qstr("introCoverIconsFg"), qstr("#5ec6ff"), qstr(""), qstr("intro cloud graphics") });
	result.push_back({ qstr("introCoverPlaneTrace"), qstr("#5ec6ff69"), qstr(""), qstr("intro plane traces") });
	result.push_back({ qstr("introCoverPlaneInner"), qstr("#c6d8e8"), qstr(""), qstr("intro plane part") });
	result.push_back({ qstr("introCoverPlaneOuter"), qstr("#a1bed4"), qstr(""), qstr("intro plane part") });
	result.push_back({ qstr("introCoverPlaneTop"), qstr("#ffffff"), qstr(""), qstr("intro plane part") });
	result.push_back({ qstr("dialogsMenuIconFg"), qstr("menuIconFg"), qstr(""), qstr("main menu and passcode lock icon") });
	result.push_back({ qstr("dialogsMenuIconFgOver"), qstr("menuIconFgOver"), qstr(""), qstr("main menu and passcode lock icon with mouse over") });
	result.push_back({ qstr("dialogsBg"), qstr("windowBg"), qstr(""), qstr("chat list background") });
	result.push_back({ qstr("dialogsNameFg"), qstr("windowBoldFg"), qstr(""), qstr("chat list name text") });
	result.push_back({ qstr("dialogsChatIconFg"), qstr("dialogsNameFg"), qstr(""), qstr("chat list group or channel icon") });
	result.push_back({ qstr("dialogsDateFg"), qstr("windowSubTextFg"), qstr(""), qstr("chat list date text") });
	result.push_back({ qstr("dialogsTextFg"), qstr("windowSubTextFg"), qstr(""), qstr("chat list message text") });
	result.push_back({ qstr("dialogsTextFgService"), qstr("windowActiveTextFg"), qstr(""), qstr("chat list group sender name text (or media message type text)") });
	result.push_back({ qstr("dialogsDraftFg"), qstr("#dd4b39"), qstr(""), qstr("chat list draft label") });
	result.push_back({ qstr("dialogsVerifiedIconBg"), qstr("windowBgActive"), qstr(""), qstr("chat list verified icon background") });
	result.push_back({ qstr("dialogsVerifiedIconFg"), qstr("windowFgActive"), qstr(""), qstr("chat list verified icon check") });
	result.push_back({ qstr("dialogsSendingIconFg"), qstr("#c1c1c1"), qstr(""), qstr("chat list sending message icon (clock)") });
	result.push_back({ qstr("dialogsSentIconFg"), qstr("#5dc452"), qstr(""), qstr("chat list sent message tick / double tick icon") });
	result.push_back({ qstr("dialogsUnreadBg"), qstr("windowBgActive"), qstr(""), qstr("chat list unread badge background for not muted chat") });
	result.push_back({ qstr("dialogsUnreadBgMuted"), qstr("#bbbbbb"), qstr(""), qstr("chat list unread badge background for muted chat") });
	result.push_back({ qstr("dialogsUnreadFg"), qstr("windowFgActive"), qstr(""), qstr("chat list unread badge text") });
	result.push_back({ qstr("dialogsArchiveFg"), qstr("#525252"), qstr("dialogsNameFg"), qstr("chat list archive name text") });
	result.push_back({ qstr("dialogsOnlineBadgeFg"), qstr("#4dc920"), qstr("dialogsUnreadBg"), qstr("chat list online status") });
	result.push_back({ qstr("dialogsScamFg"), qstr("dialogsDraftFg"), qstr(""), qstr("chat list scam label") });
	result.push_back({ qstr("dialogsBgOver"), qstr("windowBgOver"), qstr(""), qstr("chat list background with mouse over") });
	result.push_back({ qstr("dialogsNameFgOver"), qstr("windowBoldFgOver"), qstr(""), qstr("chat list name text with mouse over") });
	result.push_back({ qstr("dialogsChatIconFgOver"), qstr("dialogsNameFgOver"), qstr(""), qstr("chat list group or channel icon with mouse over") });
	result.push_back({ qstr("dialogsDateFgOver"), qstr("windowSubTextFgOver"), qstr(""), qstr("chat list date text with mouse over") });
	result.push_back({ qstr("dialogsTextFgOver"), qstr("windowSubTextFgOver"), qstr(""), qstr("chat list message text with mouse over") });
	result.push_back({ qstr("dialogsTextFgServiceOver"), qstr("dialogsTextFgService"), qstr(""), qstr("chat list group sender name text with mouse over") });
	result.push_back({ qstr("dialogsDraftFgOver"), qstr("dialogsDraftFg"), qstr(""), qstr("chat list draft label with mouse over") });
	result.push_back({ qstr("dialogsVerifiedIconBgOver"), qstr("dialogsVerifiedIconBg"), qstr(""), qstr("chat list verified icon background with mouse over") });
	result.push_back({ qstr("dialogsVerifiedIconFgOver"), qstr("dialogsVerifiedIconFg"), qstr(""), qstr("chat list verified icon check with mouse over") });
	result.push_back({ qstr("dialogsSendingIconFgOver"), qstr("dialogsSendingIconFg"), qstr(""), qstr("chat list sending message icon (clock) with mouse over") });
	result.push_back({ qstr("dialogsSentIconFgOver"), qstr("#58b84d"), qstr(""), qstr("chat list sent message tick / double tick icon with mouse over") });
	result.push_back({ qstr("dialogsUnreadBgOver"), qstr("dialogsUnreadBg"), qstr(""), qstr("chat list unread badge background for not muted chat with mouse over") });
	result.push_back({ qstr("dialogsUnreadBgMutedOver"), qstr("dialogsUnreadBgMuted"), qstr(""), qstr("chat list unread badge background for muted chat with mouse over") });
	result.push_back({ qstr("dialogsUnreadFgOver"), qstr("dialogsUnreadFg"), qstr(""), qstr("chat list unread badge text with mouse over") });
	result.push_back({ qstr("dialogsArchiveFgOver"), qstr("#525252"), qstr("dialogsNameFgOver"), qstr("chat list archive name text with mouse over") });
	result.push_back({ qstr("dialogsScamFgOver"), qstr("dialogsDraftFgOver"), qstr(""), qstr("chat list scam label with mouse over") });
	result.push_back({ qstr("dialogsBgActive"), qstr("#419fd9"), qstr(""), qstr("chat list background for current (active) chat") });
	result.push_back({ qstr("dialogsNameFgActive"), qstr("windowFgActive"), qstr(""), qstr("chat list name text for current (active) chat") });
	result.push_back({ qstr("dialogsChatIconFgActive"), qstr("dialogsNameFgActive"), qstr(""), qstr("chat list group or channel icon for current (active) chat") });
	result.push_back({ qstr("dialogsDateFgActive"), qstr("windowFgActive"), qstr(""), qstr("chat list date text for current (active) chat") });
	result.push_back({ qstr("dialogsTextFgActive"), qstr("windowFgActive"), qstr(""), qstr("chat list message text for current (active) chat") });
	result.push_back({ qstr("dialogsTextFgServiceActive"), qstr("dialogsTextFgActive"), qstr(""), qstr("chat list group sender name text for current (active) chat") });
	result.push_back({ qstr("dialogsDraftFgActive"), qstr("#c6e1f7"), qstr(""), qstr("chat list draft label for current (active) chat") });
	result.push_back({ qstr("dialogsVerifiedIconBgActive"), qstr("dialogsTextFgActive"), qstr(""), qstr("chat list verified icon background for current (active) chat") });
	result.push_back({ qstr("dialogsVerifiedIconFgActive"), qstr("dialogsBgActive"), qstr(""), qstr("chat list verified icon check for current (active) chat") });
	result.push_back({ qstr("dialogsSendingIconFgActive"), qstr("#ffffff99"), qstr(""), qstr("chat list sending message icon (clock) for current (active) chat") });
	result.push_back({ qstr("dialogsSentIconFgActive"), qstr("dialogsTextFgActive"), qstr(""), qstr("chat list sent message tick / double tick icon for current (active) chat") });
	result.push_back({ qstr("dialogsUnreadBgActive"), qstr("dialogsTextFgActive"), qstr(""), qstr("chat list unread badge background for not muted chat for current (active) chat") });
	result.push_back({ qstr("dialogsUnreadBgMutedActive"), qstr("dialogsDraftFgActive"), qstr(""), qstr("chat list unread badge background for muted chat for current (active) chat") });
	result.push_back({ qstr("dialogsUnreadFgActive"), qstr("dialogsBgActive"), qstr(""), qstr("chat list unread badge text for current (active) chat") });
	result.push_back({ qstr("dialogsOnlineBadgeFgActive"), qstr("#ffffff"), qstr(""), qstr("chat list online status for current (active) chat") });
	result.push_back({ qstr("dialogsScamFgActive"), qstr("dialogsDraftFgActive"), qstr(""), qstr("chat list scam label for current (active) chat") });
	result.push_back({ qstr("dialogsRippleBg"), qstr("windowBgRipple"), qstr(""), qstr("chat list background ripple effect") });
	result.push_back({ qstr("dialogsRippleBgActive"), qstr("activeButtonBgRipple"), qstr(""), qstr("chat list background ripple effect for current (active) chat") });
	result.push_back({ qstr("searchedBarBg"), qstr("windowBgOver"), qstr(""), qstr("search results bar background (in chats list, contacts box..)") });
	result.push_back({ qstr("searchedBarFg"), qstr("windowSubTextFgOver"), qstr(""), qstr("search results bar text (in chats list, contacts box..)") });
	result.push_back({ qstr("searchedTextMatchBg"), qstr("#fffc67"), qstr(""), qstr("in-page search results highlight background (Instant View, markdown editor)") });
	result.push_back({ qstr("searchedTextMatchFg"), qstr("#000000"), qstr(""), qstr("in-page search results highlight text (Instant View, markdown editor)") });
	result.push_back({ qstr("searchedTextCurrentMatchBg"), qstr("#f5ab5c"), qstr(""), qstr("\
in-page search current result highlight background (Instant View, markdown editor\
)") });
	result.push_back({ qstr("searchedTextCurrentMatchFg"), qstr("#000000"), qstr(""), qstr("in-page search current result highlight text (Instant View, markdown editor)") });
	result.push_back({ qstr("topBarBg"), qstr("windowBg"), qstr(""), qstr("top bar background (in chat view, media overview..)") });
	result.push_back({ qstr("emojiPanBg"), qstr("windowBg"), qstr(""), qstr("emoji panel background") });
	result.push_back({ qstr("emojiPanCategories"), qstr("#f7f7f7"), qstr("windowBg"), qstr("emoji panel categories background") });
	result.push_back({ qstr("emojiPanHeaderFg"), qstr("windowSubTextFg"), qstr(""), qstr("emoji panel section header text") });
	result.push_back({ qstr("emojiPanHeaderBg"), qstr("#fffffff2"), qstr("emojiPanBg"), qstr("emoji panel section header background") });
	result.push_back({ qstr("emojiIconFg"), qstr("#999999"), qstr(""), qstr("emoji category icon") });
	result.push_back({ qstr("emojiSubIconFgActive"), qstr("#666666"), qstr("windowBoldFg"), qstr("active emoji subcategory icon") });
	result.push_back({ qstr("stickerPanDeleteBg"), qstr("#000000"), qstr(""), qstr("delete X button background for custom sent stickers in stickers panel (legacy)") });
	result.push_back({ qstr("stickerPanDeleteFg"), qstr("windowFgActive"), qstr(""), qstr("delete X button icon for custom sent stickers in stickers panel (legacy)") });
	result.push_back({ qstr("stickerPreviewBg"), qstr("#ffffffb0"), qstr(""), qstr("sticker and GIF preview background (when you press and hold on a sticker)") });
	result.push_back({ qstr("stickerPanPremium1"), qstr("#5a99ff"), qstr(""), qstr("premium sticker pack icon gradient 1") });
	result.push_back({ qstr("stickerPanPremium2"), qstr("#45b9f3"), qstr(""), qstr("premium sticker pack icon gradient 2") });
	result.push_back({ qstr("historyTextInFg"), qstr("windowFg"), qstr(""), qstr("inbox message text") });
	result.push_back({ qstr("historyTextInFgSelected"), qstr("historyTextInFg"), qstr(""), qstr("inbox message selected text or text in a selected message") });
	result.push_back({ qstr("historyTextOutFg"), qstr("windowFg"), qstr(""), qstr("outbox message text") });
	result.push_back({ qstr("historyTextOutFgSelected"), qstr("historyTextOutFg"), qstr(""), qstr("outbox message selected text or text in a selected message") });
	result.push_back({ qstr("historyLinkInFg"), qstr("windowActiveTextFg"), qstr(""), qstr("inbox message link") });
	result.push_back({ qstr("historyLinkInFgSelected"), qstr("historyLinkInFg"), qstr(""), qstr("inbox message link in a selected text or message") });
	result.push_back({ qstr("historyLinkOutFg"), qstr("windowActiveTextFg"), qstr(""), qstr("outbox message link") });
	result.push_back({ qstr("historyLinkOutFgSelected"), qstr("historyLinkOutFg"), qstr(""), qstr("outbox message link in a selected text or message") });
	result.push_back({ qstr("historyFileNameInFg"), qstr("historyTextInFg"), qstr(""), qstr("inbox media filename text") });
	result.push_back({ qstr("historyFileNameInFgSelected"), qstr("historyFileNameInFg"), qstr(""), qstr("inbox media filename text in a selected message") });
	result.push_back({ qstr("historyFileNameOutFg"), qstr("historyTextOutFg"), qstr(""), qstr("outbox media filename text") });
	result.push_back({ qstr("historyFileNameOutFgSelected"), qstr("historyFileNameOutFg"), qstr(""), qstr("outbox media filename text in a selected message") });
	result.push_back({ qstr("historyOutIconFg"), qstr("#57b84c"), qstr(""), qstr("outbox message tick / double tick icon") });
	result.push_back({ qstr("historyOutIconFgSelected"), qstr("#45a3aa"), qstr(""), qstr("outbox message tick / double tick icon in a selected message") });
	result.push_back({ qstr("historyIconFgInverted"), qstr("windowFgActive"), qstr(""), qstr("media message tick / double tick icon (like in sent photo)") });
	result.push_back({ qstr("historySendingOutIconFg"), qstr("#98d292"), qstr(""), qstr("outbox sending message icon (clock)") });
	result.push_back({ qstr("historySendingInIconFg"), qstr("#a0adb5"), qstr(""), qstr("\
inbox sending message icon (clock) (like in sent messages to yourself or in sent \
messages to a channel)") });
	result.push_back({ qstr("historySendingInvertedIconFg"), qstr("#ffffffc8"), qstr(""), qstr("media sending message icon (clock) (like in sent photo)") });
	result.push_back({ qstr("historyCallArrowInFg"), qstr("#32b032"), qstr(""), qstr("received phone call arrow") });
	result.push_back({ qstr("historyCallArrowInFgSelected"), qstr("#2592a8"), qstr(""), qstr("received phone call arrow in a selected message") });
	result.push_back({ qstr("historyCallArrowMissedInFg"), qstr("callArrowMissedFg"), qstr(""), qstr("missed phone call arrow") });
	result.push_back({ qstr("historyCallArrowMissedInFgSelected"), qstr("callArrowMissedFg"), qstr(""), qstr("missed phone call arrow in a selected message") });
	result.push_back({ qstr("historyCallArrowOutFg"), qstr("historyCallArrowInFg"), qstr(""), qstr("outgoing phone call arrow") });
	result.push_back({ qstr("historyCallArrowOutFgSelected"), qstr("historyCallArrowInFgSelected"), qstr(""), qstr("outgoing phone call arrow") });
	result.push_back({ qstr("historyUnreadBarBg"), qstr("#fcfbfa"), qstr(""), qstr("new unread messages bar background") });
	result.push_back({ qstr("historyUnreadBarBorder"), qstr("shadowFg"), qstr(""), qstr("new unread messages bar shadow") });
	result.push_back({ qstr("historyUnreadBarFg"), qstr("#538bb4"), qstr(""), qstr("new unread messages bar text") });
	result.push_back({ qstr("historyForwardChooseBg"), qstr("#0000004c"), qstr(""), qstr("forwarding messages in a large window size \"choose recipient\" background") });
	result.push_back({ qstr("historyForwardChooseFg"), qstr("windowFgActive"), qstr(""), qstr("forwarding messages in a large window size \"choose recipient\" text") });
	result.push_back({ qstr("historyPeer1NameFg"), qstr("#c03d33"), qstr(""), qstr("red group member name") });
	result.push_back({ qstr("historyPeer1NameFgSelected"), qstr("historyPeer1NameFg"), qstr(""), qstr("red group member name in a selected message") });
	result.push_back({ qstr("historyPeer1UserpicBg"), qstr("#ff845e"), qstr(""), qstr("red userpic background") });
	result.push_back({ qstr("historyPeer2NameFg"), qstr("#4fad2d"), qstr(""), qstr("green group member name") });
	result.push_back({ qstr("historyPeer2NameFgSelected"), qstr("historyPeer2NameFg"), qstr(""), qstr("green group member name in a selected message") });
	result.push_back({ qstr("historyPeer2UserpicBg"), qstr("#9ad164"), qstr(""), qstr("green userpic background") });
	result.push_back({ qstr("historyPeer3NameFg"), qstr("#d09306"), qstr(""), qstr("yellow group member name (actually unused)") });
	result.push_back({ qstr("historyPeer3NameFgSelected"), qstr("historyPeer3NameFg"), qstr(""), qstr("yellow group member name in a selected message (actually unused)") });
	result.push_back({ qstr("historyPeer3UserpicBg"), qstr("#e5ca77"), qstr(""), qstr("yellow userpic background (actually unused)") });
	result.push_back({ qstr("historyPeer4NameFg"), qstr("windowActiveTextFg"), qstr(""), qstr("blue group member name") });
	result.push_back({ qstr("historyPeer4NameFgSelected"), qstr("historyPeer4NameFg"), qstr(""), qstr("blue group member name in a selected message") });
	result.push_back({ qstr("historyPeer4UserpicBg"), qstr("#5caffa"), qstr(""), qstr("blue userpic background") });
	result.push_back({ qstr("historyPeer5NameFg"), qstr("#8544d6"), qstr(""), qstr("purple group member name") });
	result.push_back({ qstr("historyPeer5NameFgSelected"), qstr("historyPeer5NameFg"), qstr(""), qstr("purple group member name in a selected message") });
	result.push_back({ qstr("historyPeer5UserpicBg"), qstr("#b694f9"), qstr(""), qstr("purple userpic background") });
	result.push_back({ qstr("historyPeer6NameFg"), qstr("#cd4073"), qstr(""), qstr("pink group member name") });
	result.push_back({ qstr("historyPeer6NameFgSelected"), qstr("historyPeer6NameFg"), qstr(""), qstr("pink group member name in a selected message") });
	result.push_back({ qstr("historyPeer6UserpicBg"), qstr("#ff8aac"), qstr(""), qstr("pink userpic background") });
	result.push_back({ qstr("historyPeer7NameFg"), qstr("#2996ad"), qstr(""), qstr("sea group member name") });
	result.push_back({ qstr("historyPeer7NameFgSelected"), qstr("historyPeer7NameFg"), qstr(""), qstr("sea group member name in a selected message") });
	result.push_back({ qstr("historyPeer7UserpicBg"), qstr("#5bcbe3"), qstr(""), qstr("sea userpic background") });
	result.push_back({ qstr("historyPeer8NameFg"), qstr("#ce671b"), qstr(""), qstr("orange group member name") });
	result.push_back({ qstr("historyPeer8NameFgSelected"), qstr("historyPeer8NameFg"), qstr(""), qstr("orange group member name in a selected message") });
	result.push_back({ qstr("historyPeer8UserpicBg"), qstr("#febb5b"), qstr(""), qstr("orange userpic background") });
	result.push_back({ qstr("historyPeerUserpicFg"), qstr("windowFgActive"), qstr(""), qstr("default userpic initials") });
	result.push_back({ qstr("historyPeerSavedMessagesBg"), qstr("historyPeer4UserpicBg"), qstr(""), qstr("saved messages userpic background") });
	result.push_back({ qstr("historyPeerArchiveUserpicBg"), qstr("dialogsUnreadBgMuted"), qstr(""), qstr("archive folder userpic background") });
	result.push_back({ qstr("historyPeer1UserpicBg2"), qstr("#d45246"), qstr("historyPeer1UserpicBg"), qstr("the second red userpic background") });
	result.push_back({ qstr("historyPeer2UserpicBg2"), qstr("#46ba43"), qstr("historyPeer2UserpicBg"), qstr("the second green userpic background") });
	result.push_back({ qstr("historyPeer3UserpicBg2"), qstr("#e5ca77"), qstr("historyPeer3UserpicBg"), qstr("the second yellow userpic background (actually unused)") });
	result.push_back({ qstr("historyPeer4UserpicBg2"), qstr("#408acf"), qstr("historyPeer4UserpicBg"), qstr("the second blue userpic background") });
	result.push_back({ qstr("historyPeer5UserpicBg2"), qstr("#6c61df"), qstr("historyPeer5UserpicBg"), qstr("the second purple userpic background") });
	result.push_back({ qstr("historyPeer6UserpicBg2"), qstr("#d95574"), qstr("historyPeer6UserpicBg"), qstr("the second pink userpic background") });
	result.push_back({ qstr("historyPeer7UserpicBg2"), qstr("#359ad4"), qstr("historyPeer7UserpicBg"), qstr("the second sea userpic background") });
	result.push_back({ qstr("historyPeer8UserpicBg2"), qstr("#f68136"), qstr("historyPeer8UserpicBg"), qstr("the second orange userpic background") });
	result.push_back({ qstr("historyPeerSavedMessagesBg2"), qstr("historyPeer4UserpicBg2"), qstr(""), qstr("the second saved messages userpic background") });
	result.push_back({ qstr("settingsIconBg1"), qstr("#f06964"), qstr(""), qstr("red settings icon background") });
	result.push_back({ qstr("settingsIconBg2"), qstr("#6dc534"), qstr(""), qstr("green settings icon background") });
	result.push_back({ qstr("settingsIconBg3"), qstr("#ed9f20"), qstr(""), qstr("light-orange settings icon background") });
	result.push_back({ qstr("settingsIconBg4"), qstr("#56b3f5"), qstr(""), qstr("light-blue settings icon background") });
	result.push_back({ qstr("settingsIconBg5"), qstr("#7595ff"), qstr(""), qstr("dark-blue settings icon background") });
	result.push_back({ qstr("settingsIconBg6"), qstr("#b580e2"), qstr(""), qstr("purple settings icon background") });
	result.push_back({ qstr("settingsIconBg8"), qstr("#f2925b"), qstr(""), qstr("dark-orange settings icon background") });
	result.push_back({ qstr("settingsIconBgArchive"), qstr("#9da2b0"), qstr(""), qstr("archive main menu icon background") });
	result.push_back({ qstr("settingsIconFg"), qstr("#ffffff"), qstr(""), qstr("settings icon shape") });
	result.push_back({ qstr("historyScrollBarBg"), qstr("#517c417a"), qstr(""), qstr("scroll bar current rectangle, the bar itself in the chat view (adjusted)") });
	result.push_back({ qstr("historyScrollBarBgOver"), qstr("#517c41bc"), qstr(""), qstr("scroll bar current rectangle with mouse over it in the chat view (adjusted)") });
	result.push_back({ qstr("historyScrollBg"), qstr("#517c414c"), qstr(""), qstr("scroll bar background (adjusted)") });
	result.push_back({ qstr("historyScrollBgOver"), qstr("#517c416b"), qstr(""), qstr("scroll bar background with mouse over the scroll bar (adjusted)") });
	result.push_back({ qstr("msgInBg"), qstr("windowBg"), qstr(""), qstr("inbox message background") });
	result.push_back({ qstr("msgInBgSelected"), qstr("#c2dcf2"), qstr(""), qstr("\
inbox selected message background (and background of selected text in those messa\
ges)") });
	result.push_back({ qstr("msgOutBg"), qstr("#effdde"), qstr(""), qstr("outbox message background") });
	result.push_back({ qstr("msgOutBgSelected"), qstr("#b7dbdb"), qstr(""), qstr("\
outbox selected message background (and background of selected text in those mess\
ages)") });
	result.push_back({ qstr("msgSelectOverlay"), qstr("#358cd44c"), qstr(""), qstr("\
overlay which is filling the media parts of selected messages (like in selected p\
hoto message)") });
	result.push_back({ qstr("msgStickerOverlay"), qstr("#358cd47f"), qstr(""), qstr("overlay which is filling the selected sticker message") });
	result.push_back({ qstr("msgInServiceFg"), qstr("windowActiveTextFg"), qstr(""), qstr("\
inbox message information text (like information about a forwarded message origin\
al sender)") });
	result.push_back({ qstr("msgInServiceFgSelected"), qstr("windowActiveTextFg"), qstr(""), qstr("\
inbox selected message information text (like information about a forwarded messa\
ge original sender)") });
	result.push_back({ qstr("msgOutServiceFg"), qstr("#45a32d"), qstr(""), qstr("\
outbox message information text (like information about a forwarded message origi\
nal sender)") });
	result.push_back({ qstr("msgOutServiceFgSelected"), qstr("#469992"), qstr(""), qstr("\
outbox message information text (like information about a forwarded message origi\
nal sender)") });
	result.push_back({ qstr("msgInShadow"), qstr("#748ea229"), qstr(""), qstr("inbox message shadow (below the bubble)") });
	result.push_back({ qstr("msgInShadowSelected"), qstr("#548dbb29"), qstr(""), qstr("inbox selected message shadow (below the bubble)") });
	result.push_back({ qstr("msgOutShadow"), qstr("#3ac3461d"), qstr(""), qstr("outbox message shadow (below the bubble)") });
	result.push_back({ qstr("msgOutShadowSelected"), qstr("#37a78d22"), qstr(""), qstr("outbox selected message shadow (below the bubble)") });
	result.push_back({ qstr("msgInDateFg"), qstr("#a0acb6"), qstr(""), qstr("inbox message time text") });
	result.push_back({ qstr("msgInDateFgSelected"), qstr("#6a9cc5"), qstr(""), qstr("inbox selected message time text") });
	result.push_back({ qstr("msgOutDateFg"), qstr("#6db566"), qstr(""), qstr("outbox message time text") });
	result.push_back({ qstr("msgOutDateFgSelected"), qstr("#56b2a6"), qstr(""), qstr("outbox selected message time text") });
	result.push_back({ qstr("msgServiceFg"), qstr("windowFgActive"), qstr(""), qstr("\
service message text (like date dividers or service message about the group title\
 being changed)") });
	result.push_back({ qstr("msgServiceBg"), qstr("#517c417f"), qstr(""), qstr("\
service message background (like in a service message about group title being cha\
nged) (adjusted)") });
	result.push_back({ qstr("msgServiceBgSelected"), qstr("#96b38ba2"), qstr(""), qstr("\
service message selected text background (like in a service message about group t\
itle being changed) (adjusted)") });
	result.push_back({ qstr("msgInReplyBarColor"), qstr("activeLineFg"), qstr(""), qstr("inbox message reply outline") });
	result.push_back({ qstr("msgInReplyBarSelColor"), qstr("activeLineFg"), qstr(""), qstr("inbox selected message reply outline") });
	result.push_back({ qstr("msgOutReplyBarColor"), qstr("#5eb854"), qstr(""), qstr("outbox message reply outline") });
	result.push_back({ qstr("msgOutReplyBarSelColor"), qstr("historyOutIconFgSelected"), qstr(""), qstr("outbox selected message reply outline") });
	result.push_back({ qstr("msgImgReplyBarColor"), qstr("msgServiceFg"), qstr(""), qstr("sticker message reply outline") });
	result.push_back({ qstr("msgInMonoFg"), qstr("#4e7391"), qstr(""), qstr("inbox message monospace text (like a message sent with `test` text)") });
	result.push_back({ qstr("msgOutMonoFg"), qstr("#459866"), qstr(""), qstr("outbox message monospace text") });
	result.push_back({ qstr("msgInMonoFgSelected"), qstr("msgInMonoFg"), qstr(""), qstr("inbox message monospace text in a selected text or message") });
	result.push_back({ qstr("msgOutMonoFgSelected"), qstr("msgOutMonoFg"), qstr(""), qstr("outbox message monospace text in a selected text or message") });
	result.push_back({ qstr("msgDateImgFg"), qstr("msgServiceFg"), qstr(""), qstr("media message time text (like time text in a sent photo)") });
	result.push_back({ qstr("msgDateImgBg"), qstr("#00000054"), qstr(""), qstr("\
media message time bubble background (like time bubble in a sent photo) or file w\
ith thumbnail download icon circle background") });
	result.push_back({ qstr("msgDateImgBgOver"), qstr("#00000074"), qstr(""), qstr("\
media message download icon circle background with mouse over (like file with thu\
mbnail download icon)") });
	result.push_back({ qstr("msgDateImgBgSelected"), qstr("#1c4a7187"), qstr(""), qstr("selected media message time bubble background") });
	result.push_back({ qstr("msgFileThumbLinkInFg"), qstr("lightButtonFg"), qstr(""), qstr("inbox media file message with thumbnail download / open with button text") });
	result.push_back({ qstr("msgFileThumbLinkInFgSelected"), qstr("lightButtonFgOver"), qstr(""), qstr("inbox selected media file message with thumbnail download / open with button text") });
	result.push_back({ qstr("msgFileThumbLinkOutFg"), qstr("#4ba831"), qstr(""), qstr("outbox media file message with thumbnail download / open with button text") });
	result.push_back({ qstr("msgFileThumbLinkOutFgSelected"), qstr("#31a298"), qstr(""), qstr("\
outbox selected media file message with thumbnail download / open with button tex\
t") });
	result.push_back({ qstr("msgFileInBg"), qstr("windowBgActive"), qstr(""), qstr("inbox audio file download circle background") });
	result.push_back({ qstr("msgFileInBgOver"), qstr("#4eade3"), qstr(""), qstr("inbox audio file download circle background with mouse over") });
	result.push_back({ qstr("msgFileInBgSelected"), qstr("#51a3d3"), qstr(""), qstr("inbox selected audio file download circle background") });
	result.push_back({ qstr("msgFileOutBg"), qstr("#5fbe67"), qstr(""), qstr("outbox audio file download circle background") });
	result.push_back({ qstr("msgFileOutBgSelected"), qstr("#50ac9b"), qstr(""), qstr("outbox selected audio file download circle background") });
	result.push_back({ qstr("msgFile1Bg"), qstr("#72b1df"), qstr(""), qstr("blue shared links / files without image square thumbnail") });
	result.push_back({ qstr("msgFile1BgDark"), qstr("#5c9ece"), qstr(""), qstr("blue shared files without image download circle background") });
	result.push_back({ qstr("msgFile1BgOver"), qstr("#5294c4"), qstr(""), qstr("blue shared files without image download circle background with mouse over") });
	result.push_back({ qstr("msgFile1BgSelected"), qstr("#5099d0"), qstr(""), qstr("blue shared files without image download circle background if file is selected") });
	result.push_back({ qstr("msgFile2Bg"), qstr("#5fbe67"), qstr(""), qstr("green shared links / shared files without image square thumbnail") });
	result.push_back({ qstr("msgFile2BgDark"), qstr("#4da859"), qstr(""), qstr("green shared files without image download circle background") });
	result.push_back({ qstr("msgFile2BgOver"), qstr("#44a050"), qstr(""), qstr("green shared files without image download circle background with mouse over") });
	result.push_back({ qstr("msgFile2BgSelected"), qstr("#50ac9b"), qstr(""), qstr("green shared files without image download circle background if file is selected") });
	result.push_back({ qstr("msgFile3Bg"), qstr("#e47272"), qstr(""), qstr("red shared links / shared files without image square thumbnail") });
	result.push_back({ qstr("msgFile3BgDark"), qstr("#cd5b5e"), qstr(""), qstr("red shared files without image download circle background") });
	result.push_back({ qstr("msgFile3BgOver"), qstr("#c35154"), qstr(""), qstr("red shared files without image download circle background with mouse over") });
	result.push_back({ qstr("msgFile3BgSelected"), qstr("#9f6a82"), qstr(""), qstr("red shared files without image download circle background if file is selected") });
	result.push_back({ qstr("msgFile4Bg"), qstr("#efc274"), qstr(""), qstr("yellow shared links / shared files without image square thumbnail") });
	result.push_back({ qstr("msgFile4BgDark"), qstr("#e6a561"), qstr(""), qstr("yellow shared files without image download circle background") });
	result.push_back({ qstr("msgFile4BgOver"), qstr("#dc9c5a"), qstr(""), qstr("yellow shared files without image download circle background with mouse over") });
	result.push_back({ qstr("msgFile4BgSelected"), qstr("#b19d84"), qstr(""), qstr("yellow shared files without image download circle background if file is selected") });
	result.push_back({ qstr("historyFileInIconFg"), qstr("msgInBg"), qstr(""), qstr("inbox file without thumbnail (like audio file) download arrow icon") });
	result.push_back({ qstr("historyFileInIconFgSelected"), qstr("msgInBgSelected"), qstr(""), qstr("inbox selected file without thumbnail (like audio file) download arrow icon") });
	result.push_back({ qstr("historyFileInRadialFg"), qstr("historyFileInIconFg"), qstr(""), qstr("inbox file without thumbnail (like audio file) radial download animation line") });
	result.push_back({ qstr("historyFileInRadialFgSelected"), qstr("historyFileInIconFgSelected"), qstr(""), qstr("\
inbox selected file without thumbnail (like audio file) radial download animation\
 line") });
	result.push_back({ qstr("historyFileOutIconFg"), qstr("msgOutBg"), qstr(""), qstr("outbox file without thumbnail (like audio file) download arrow icon") });
	result.push_back({ qstr("historyFileOutIconFgSelected"), qstr("msgOutBgSelected"), qstr(""), qstr("outbox selected file without thumbnail (like audio file) download arrow icon") });
	result.push_back({ qstr("historyFileOutRadialFg"), qstr("historyFileOutIconFg"), qstr(""), qstr("outbox file without thumbnail (like audio file) radial download animation line") });
	result.push_back({ qstr("historyFileOutRadialFgSelected"), qstr("historyFileOutIconFgSelected"), qstr(""), qstr("\
outbox selected file without thumbnail (like audio file) radial download animatio\
n line") });
	result.push_back({ qstr("historyFileThumbIconFg"), qstr("msgInBg"), qstr(""), qstr("file with thumbnail (or photo / video) download arrow icon") });
	result.push_back({ qstr("historyFileThumbIconFgSelected"), qstr("msgInBgSelected"), qstr(""), qstr("selected file with thumbnail (or photo / video) download arrow icon") });
	result.push_back({ qstr("historyFileThumbRadialFg"), qstr("historyFileThumbIconFg"), qstr(""), qstr("file with thumbnail (or photo / video) radial download animation line") });
	result.push_back({ qstr("historyFileThumbRadialFgSelected"), qstr("historyFileThumbIconFgSelected"), qstr(""), qstr("selected file with thumbnail (or photo / video) radial download animation line") });
	result.push_back({ qstr("historyVideoMessageProgressFg"), qstr("historyFileThumbIconFg"), qstr(""), qstr("radial playback progress in round video messages") });
	result.push_back({ qstr("msgWaveformInActive"), qstr("windowBgActive"), qstr(""), qstr("\
inbox voice message active waveform lines (like played part of currently playing \
voice message)") });
	result.push_back({ qstr("msgWaveformInActiveSelected"), qstr("#51a3d3"), qstr(""), qstr("\
inbox selected voice message active waveform lines (like played part of currently\
 playing voice message)") });
	result.push_back({ qstr("msgWaveformInInactive"), qstr("#d4dee6"), qstr(""), qstr("\
inbox voice message inactive waveform lines (like upcoming part of currently play\
ing voice message)") });
	result.push_back({ qstr("msgWaveformInInactiveSelected"), qstr("#9cc1e1"), qstr(""), qstr("\
inbox selected voice message inactive waveform lines (like upcoming part of curre\
ntly playing voice message)") });
	result.push_back({ qstr("msgWaveformOutActive"), qstr("#5ebd66"), qstr(""), qstr("\
outbox voice message active waveform lines (like played part of currently playing\
 voice message)") });
	result.push_back({ qstr("msgWaveformOutActiveSelected"), qstr("#6badad"), qstr(""), qstr("\
outbox selected voice message active waveform lines (like played part of currentl\
y playing voice message)") });
	result.push_back({ qstr("msgWaveformOutInactive"), qstr("#b3e2b4"), qstr(""), qstr("\
outbox voice message inactive waveform lines (like upcoming part of currently pla\
ying voice message)") });
	result.push_back({ qstr("msgWaveformOutInactiveSelected"), qstr("#91c3c3"), qstr(""), qstr("\
outbox selected voice message inactive waveform lines (like upcoming part of curr\
ently playing voice message)") });
	result.push_back({ qstr("msgBotKbOverBgAdd"), qstr("#ffffff20"), qstr(""), qstr("\
this is painted over a bot inline keyboard button (which has msgServiceBg backgro\
und) when mouse is over that button") });
	result.push_back({ qstr("msgBotKbIconFg"), qstr("msgServiceFg"), qstr(""), qstr("\
bot inline keyboard button icon in the top-right corner (like in @vote bot when a\
 poll is ready to be shared)") });
	result.push_back({ qstr("msgBotKbRippleBg"), qstr("#00000020"), qstr(""), qstr("bot inline keyboard button ripple effect") });
	result.push_back({ qstr("mediaInFg"), qstr("msgInDateFg"), qstr(""), qstr("inbox media message status text (like in file that is being downloaded)") });
	result.push_back({ qstr("mediaInFgSelected"), qstr("msgInDateFgSelected"), qstr(""), qstr("inbox selected media message status text (like in file that is being downloaded)") });
	result.push_back({ qstr("mediaOutFg"), qstr("msgOutDateFg"), qstr(""), qstr("outbox media message status text (like in file that is being downloaded)") });
	result.push_back({ qstr("mediaOutFgSelected"), qstr("msgOutDateFgSelected"), qstr(""), qstr("outbox selected media message status text (like in file that is being downloaded)") });
	result.push_back({ qstr("youtubePlayIconBg"), qstr("#e83131c8"), qstr(""), qstr("\
youtube play icon background (when a link to a youtube video with a webpage previ\
ew is sent)") });
	result.push_back({ qstr("youtubePlayIconFg"), qstr("windowFgActive"), qstr(""), qstr("\
youtube play icon arrow (when a link to a youtube video with a webpage preview is\
 sent)") });
	result.push_back({ qstr("videoPlayIconBg"), qstr("#0000007f"), qstr(""), qstr("\
other video play icon background (like when a link to a vimeo video with a webpag\
e preview is sent)") });
	result.push_back({ qstr("videoPlayIconFg"), qstr("#ffffff"), qstr(""), qstr("\
other video play icon arrow (like when a link to a vimeo video with a webpage pre\
view is sent)") });
	result.push_back({ qstr("toastBg"), qstr("#2c3033e5"), qstr(""), qstr("\
toast notification background (like when you click on your t.me link when editing\
 your username)") });
	result.push_back({ qstr("toastFg"), qstr("#ffffff"), qstr(""), qstr("\
toast notification text (like when you click on your t.me link when editing your \
username)") });
	result.push_back({ qstr("historyToDownBg"), qstr("windowBg"), qstr(""), qstr("arrow button background (to scroll to the end of the viewed chat)") });
	result.push_back({ qstr("historyToDownBgOver"), qstr("windowBgOver"), qstr(""), qstr("arrow button background with mouse over") });
	result.push_back({ qstr("historyToDownBgRipple"), qstr("windowBgRipple"), qstr(""), qstr("arrow button ripple effect") });
	result.push_back({ qstr("historyToDownFg"), qstr("menuIconFg"), qstr(""), qstr("arrow button icon") });
	result.push_back({ qstr("historyToDownFgOver"), qstr("menuIconFgOver"), qstr(""), qstr("arrow button icon with mouse over") });
	result.push_back({ qstr("historyToDownShadow"), qstr("#00000040"), qstr(""), qstr("arrow button shadow") });
	result.push_back({ qstr("historyComposeAreaBg"), qstr("msgInBg"), qstr(""), qstr("\
history compose area background (message write area / reply information / forward\
ing information)") });
	result.push_back({ qstr("historyComposeAreaFg"), qstr("historyTextInFg"), qstr(""), qstr("history compose area text") });
	result.push_back({ qstr("historyComposeAreaFgService"), qstr("msgInDateFg"), qstr(""), qstr("history compose area text when replying to a media message") });
	result.push_back({ qstr("historyComposeIconFg"), qstr("menuIconFg"), qstr(""), qstr("history compose area icon (like emoji, attach, bot command..)") });
	result.push_back({ qstr("historyComposeIconFgOver"), qstr("menuIconFgOver"), qstr(""), qstr("history compose area icon with mouse over") });
	result.push_back({ qstr("historySendIconFg"), qstr("windowBgActive"), qstr(""), qstr("send message icon") });
	result.push_back({ qstr("historySendIconFgOver"), qstr("windowBgActive"), qstr(""), qstr("send message icon with mouse over") });
	result.push_back({ qstr("historyPinnedBg"), qstr("historyComposeAreaBg"), qstr(""), qstr("pinned message area background") });
	result.push_back({ qstr("historyReplyBg"), qstr("historyComposeAreaBg"), qstr(""), qstr("reply / forward / edit message area background") });
	result.push_back({ qstr("historyReplyIconFg"), qstr("windowBgActive"), qstr(""), qstr("reply / forward / edit message left icon") });
	result.push_back({ qstr("historyReplyCancelFg"), qstr("cancelIconFg"), qstr(""), qstr("reply / forward / edit message cancel button") });
	result.push_back({ qstr("historyReplyCancelFgOver"), qstr("cancelIconFgOver"), qstr(""), qstr("reply / forward / edit message cancel button with mouse over") });
	result.push_back({ qstr("historyComposeButtonBg"), qstr("historyComposeAreaBg"), qstr(""), qstr("unblock / join channel / mute channel button background") });
	result.push_back({ qstr("historyComposeButtonBgOver"), qstr("windowBgOver"), qstr(""), qstr("unblock / join channel / mute channel button background with mouse over") });
	result.push_back({ qstr("historyComposeButtonBgRipple"), qstr("windowBgRipple"), qstr(""), qstr("unblock / join channel / mute channel button ripple effect") });
	result.push_back({ qstr("mapPointDrop"), qstr("#fd4444"), qstr(""), qstr("geo location marker background") });
	result.push_back({ qstr("mapPointDot"), qstr("#ffffff"), qstr(""), qstr("geo location marker point") });
	result.push_back({ qstr("overviewCheckBg"), qstr("#00000040"), qstr(""), qstr("\
shared media / files / links checkbox background for not selected rows when some \
rows are selected") });
	result.push_back({ qstr("overviewCheckBgActive"), qstr("windowBgActive"), qstr(""), qstr("shared media / files / links checkbox background for selected rows") });
	result.push_back({ qstr("overviewCheckBorder"), qstr("windowBg"), qstr(""), qstr("shared media round checkbox border") });
	result.push_back({ qstr("overviewCheckFgActive"), qstr("windowBg"), qstr(""), qstr("shared files / links checkbox icon for selected rows") });
	result.push_back({ qstr("overviewPhotoSelectOverlay"), qstr("#40ace333"), qstr(""), qstr("shared photos / videos / links fill for selected rows") });
	result.push_back({ qstr("profileStatusFgOver"), qstr("#7c99b2"), qstr(""), qstr("group members list in group profile user last seen text with mouse over") });
	result.push_back({ qstr("profileVerifiedCheckBg"), qstr("windowBgActive"), qstr(""), qstr("profile verified check icon background") });
	result.push_back({ qstr("profileVerifiedCheckFg"), qstr("windowFgActive"), qstr(""), qstr("profile verified check icon tick") });
	result.push_back({ qstr("profileAdminStartFg"), qstr("windowBgActive"), qstr(""), qstr("group members list creator star icon") });
	result.push_back({ qstr("notificationsBoxMonitorFg"), qstr("windowFg"), qstr(""), qstr("custom notifications settings box monitor color") });
	result.push_back({ qstr("notificationsBoxScreenBg"), qstr("dialogsBgActive"), qstr(""), qstr("#6389a8; // custom notifications settings box monitor screen background") });
	result.push_back({ qstr("notificationSampleUserpicFg"), qstr("windowBgActive"), qstr(""), qstr("custom notifications settings box small sample userpic placeholder") });
	result.push_back({ qstr("notificationSampleCloseFg"), qstr("#d7d7d7"), qstr("windowSubTextFg"), qstr("custom notifications settings box small sample close button placeholder") });
	result.push_back({ qstr("notificationSampleTextFg"), qstr("#d7d7d7"), qstr("windowSubTextFg"), qstr("custom notifications settings box small sample text placeholder") });
	result.push_back({ qstr("notificationSampleNameFg"), qstr("#939393"), qstr("windowSubTextFg"), qstr("custom notifications settings box small sample name placeholder") });
	result.push_back({ qstr("mainMenuBg"), qstr("windowBg"), qstr(""), qstr("main menu background") });
	result.push_back({ qstr("mainMenuCoverBg"), qstr("dialogsBgActive"), qstr(""), qstr("main menu top cover background") });
	result.push_back({ qstr("mainMenuCloudFg"), qstr("activeButtonFg"), qstr(""), qstr("main menu top cover saved messages / archive button icon") });
	result.push_back({ qstr("mainMenuCloudBg"), qstr("#2785bf"), qstr("activeButtonBgRipple"), qstr("main menu top cover saved messages / archive button background") });
	result.push_back({ qstr("mediaPlayerBg"), qstr("windowBg"), qstr(""), qstr("audio file player background") });
	result.push_back({ qstr("mediaPlayerActiveFg"), qstr("windowBgActive"), qstr(""), qstr("audio file player playback progress already played part") });
	result.push_back({ qstr("mediaPlayerInactiveFg"), qstr("sliderBgInactive"), qstr(""), qstr("\
audio file player playback progress upcoming (not played yet) part with mouse ove\
r") });
	result.push_back({ qstr("mediaPlayerDisabledFg"), qstr("#9dd1ef"), qstr(""), qstr("\
audio file player loading progress (when you're playing an audio file and switch \
to the previous one which is not loaded yet)") });
	result.push_back({ qstr("mediaviewFileBg"), qstr("windowBg"), qstr(""), qstr("\
file rectangle background (when you view a png file in Media Viewer and go to a p\
revious, not loaded yet, file)") });
	result.push_back({ qstr("mediaviewFileNameFg"), qstr("windowFg"), qstr(""), qstr("file name in file rectangle") });
	result.push_back({ qstr("mediaviewFileSizeFg"), qstr("windowSubTextFg"), qstr(""), qstr("file size text in file rectangle") });
	result.push_back({ qstr("mediaviewFileRedCornerFg"), qstr("#d55959"), qstr(""), qstr("\
red file thumbnail placeholder corner in file rectangle (for a file without thumb\
nail, like .pdf)") });
	result.push_back({ qstr("mediaviewFileYellowCornerFg"), qstr("#e8a659"), qstr(""), qstr("\
yellow file thumbnail placeholder corner in file rectangle (for a file without th\
umbnail, like .zip)") });
	result.push_back({ qstr("mediaviewFileGreenCornerFg"), qstr("#49a957"), qstr(""), qstr("\
green file thumbnail placeholder corner in file rectangle (for a file without thu\
mbnail, like .exe)") });
	result.push_back({ qstr("mediaviewFileBlueCornerFg"), qstr("#599dcf"), qstr(""), qstr("\
blue file thumbnail placeholder corner in file rectangle (for a file without thum\
bnail, like .dmg)") });
	result.push_back({ qstr("mediaviewFileExtFg"), qstr("activeButtonFg"), qstr(""), qstr("file extension text in file thumbnail placeholder in file rectangle") });
	result.push_back({ qstr("mediaviewMenuBg"), qstr("#383838"), qstr(""), qstr("context menu in Media Viewer background") });
	result.push_back({ qstr("mediaviewMenuBgOver"), qstr("#505050"), qstr(""), qstr("context menu item background with mouse over") });
	result.push_back({ qstr("mediaviewMenuBgRipple"), qstr("#676767"), qstr(""), qstr("context menu item ripple effect") });
	result.push_back({ qstr("mediaviewMenuFg"), qstr("windowFgActive"), qstr(""), qstr("context menu item text") });
	result.push_back({ qstr("mediaviewBg"), qstr("#222222eb"), qstr(""), qstr("Media Viewer background") });
	result.push_back({ qstr("mediaviewVideoBg"), qstr("imageBg"), qstr(""), qstr("Media Viewer background when viewing a video in full screen") });
	result.push_back({ qstr("mediaviewControlBg"), qstr("#0000003c"), qstr(""), qstr("controls background (like next photo / previous photo)") });
	result.push_back({ qstr("mediaviewControlFg"), qstr("#ffffff"), qstr(""), qstr("controls icon (like next photo / previous photo)") });
	result.push_back({ qstr("mediaviewCaptionBg"), qstr("#11111180"), qstr(""), qstr("caption text background (when viewing photo with caption)") });
	result.push_back({ qstr("mediaviewCaptionFg"), qstr("mediaviewControlFg"), qstr(""), qstr("caption text") });
	result.push_back({ qstr("mediaviewTextLinkFg"), qstr("#4db8ff"), qstr(""), qstr("caption text link") });
	result.push_back({ qstr("mediaviewSaveMsgBg"), qstr("toastBg"), qstr(""), qstr("save to file toast message background in Media Viewer") });
	result.push_back({ qstr("mediaviewSaveMsgFg"), qstr("toastFg"), qstr(""), qstr("save to file toast message text") });
	result.push_back({ qstr("mediaviewPlaybackActive"), qstr("#c7c7c7"), qstr(""), qstr("video playback progress already played part") });
	result.push_back({ qstr("mediaviewPlaybackInactive"), qstr("#252525"), qstr(""), qstr("video playback progress upcoming (not played yet) part") });
	result.push_back({ qstr("mediaviewPlaybackActiveOver"), qstr("#ffffff"), qstr(""), qstr("video playback progress already played part with mouse over") });
	result.push_back({ qstr("mediaviewPlaybackInactiveOver"), qstr("#474747"), qstr(""), qstr("video playback progress upcoming (not played yet) part with mouse over") });
	result.push_back({ qstr("mediaviewPlaybackProgressFg"), qstr("#ffffffc7"), qstr(""), qstr("video playback progress text") });
	result.push_back({ qstr("mediaviewPlaybackIconFg"), qstr("mediaviewPlaybackActive"), qstr(""), qstr("video playback controls icon") });
	result.push_back({ qstr("mediaviewPlaybackIconFgOver"), qstr("mediaviewPlaybackActiveOver"), qstr(""), qstr("video playback controls icon with mouse over") });
	result.push_back({ qstr("mediaviewPlaybackIconRipple"), qstr("#ffffff14"), qstr(""), qstr("video playback controls ripple effect") });
	result.push_back({ qstr("mediaviewPipControlsFg"), qstr("#ffffffd9"), qstr(""), qstr("picture-in-picture controls") });
	result.push_back({ qstr("mediaviewPipControlsFgOver"), qstr("#ffffff"), qstr(""), qstr("picture-in-picture controls with mouse over") });
	result.push_back({ qstr("mediaviewPipPlaybackActive"), qstr("#ffffffda"), qstr(""), qstr("picture-in-picture playback progress already played part") });
	result.push_back({ qstr("mediaviewPipPlaybackInactive"), qstr("#ffffff26"), qstr(""), qstr("picture-in-picture playback progress upcoming (not played yet) part") });
	result.push_back({ qstr("mediaviewTransparentBg"), qstr("#ffffff"), qstr(""), qstr("transparent filling part (when viewing a transparent .png file in Media Viewer)") });
	result.push_back({ qstr("mediaviewTransparentFg"), qstr("#cccccc"), qstr(""), qstr("another transparent filling part") });
	result.push_back({ qstr("notificationBg"), qstr("windowBg"), qstr(""), qstr("custom notification window background") });
	result.push_back({ qstr("callBg"), qstr("#26282cf2"), qstr(""), qstr("old phone call popup background") });
	result.push_back({ qstr("callBgOpaque"), qstr("#1b1f23"), qstr(""), qstr("phone call popup background") });
	result.push_back({ qstr("callBgButton"), qstr("#1b1f237f"), qstr(""), qstr("phone call window control buttons bg") });
	result.push_back({ qstr("callNameFg"), qstr("#ffffff"), qstr(""), qstr("phone call popup name text") });
	result.push_back({ qstr("callStatusFg"), qstr("#aaabac"), qstr(""), qstr("phone call popup status text") });
	result.push_back({ qstr("callIconBg"), qstr("#ffffff1f"), qstr(""), qstr("phone call mute mic and camera button background") });
	result.push_back({ qstr("callIconFg"), qstr("#ffffff"), qstr(""), qstr("phone call popup answer, hangup, mute mic and camera icon") });
	result.push_back({ qstr("callIconBgActive"), qstr("#ffffffe5"), qstr(""), qstr("phone call line busy cancel, muted mic and camera button background") });
	result.push_back({ qstr("callIconFgActive"), qstr("#222222"), qstr(""), qstr("phone call line busy cancel, muted mic and camera icon") });
	result.push_back({ qstr("callIconActiveRipple"), qstr("#f1f1f1"), qstr(""), qstr("phone call line busy cancel, muted mic and camera ripple effect") });
	result.push_back({ qstr("callAnswerBg"), qstr("#66c95b"), qstr(""), qstr("phone call popup answer button background") });
	result.push_back({ qstr("callAnswerRipple"), qstr("#52b149"), qstr(""), qstr("phone call popup answer button ripple effect") });
	result.push_back({ qstr("callAnswerBgOuter"), qstr("#50eb4126"), qstr(""), qstr("phone call popup answer button outer ripple effect") });
	result.push_back({ qstr("callHangupBg"), qstr("#d75a5a"), qstr(""), qstr("phone call popup hangup button background") });
	result.push_back({ qstr("callHangupRipple"), qstr("#c04646"), qstr(""), qstr("phone call popup hangup button ripple effect") });
	result.push_back({ qstr("callMuteRipple"), qstr("#ffffff12"), qstr(""), qstr("phone call popup mute mic and camera ripple effect") });
	result.push_back({ qstr("groupCallBg"), qstr("#1a2026"), qstr(""), qstr("group call popup background") });
	result.push_back({ qstr("groupCallActiveFg"), qstr("#4db8ff"), qstr(""), qstr("group call active controls text") });
	result.push_back({ qstr("groupCallMembersBg"), qstr("#2c333d"), qstr(""), qstr("group call members list background") });
	result.push_back({ qstr("groupCallMembersBgOver"), qstr("#323a45"), qstr(""), qstr("group call members list row with mouse over") });
	result.push_back({ qstr("groupCallMembersBgRipple"), qstr("#39424f"), qstr(""), qstr("group call member row ripple effect") });
	result.push_back({ qstr("groupCallMembersFg"), qstr("#ffffff"), qstr(""), qstr("group call member name text") });
	result.push_back({ qstr("groupCallMemberActiveIcon"), qstr("#8deb90"), qstr(""), qstr("group call active member icon") });
	result.push_back({ qstr("groupCallMemberActiveStatus"), qstr("#8deb90"), qstr(""), qstr("group call active member status text") });
	result.push_back({ qstr("groupCallMemberInactiveIcon"), qstr("#84888f"), qstr(""), qstr("group call inactive member icon") });
	result.push_back({ qstr("groupCallMemberInactiveStatus"), qstr("#61c0ff"), qstr(""), qstr("group call inactive member status text") });
	result.push_back({ qstr("groupCallMemberMutedIcon"), qstr("#ed7372"), qstr(""), qstr("group call muted by admin member icon") });
	result.push_back({ qstr("groupCallMemberNotJoinedStatus"), qstr("#91979e"), qstr(""), qstr("group call non joined member status text") });
	result.push_back({ qstr("groupCallIconFg"), qstr("#ffffff"), qstr(""), qstr("group call mute / settings / leave icon") });
	result.push_back({ qstr("groupCallLive1"), qstr("#0dcc39"), qstr(""), qstr("group call live button color1") });
	result.push_back({ qstr("groupCallLive2"), qstr("#0bb6bd"), qstr(""), qstr("group call live button color2") });
	result.push_back({ qstr("groupCallMuted1"), qstr("#0992ef"), qstr(""), qstr("group call muted button color1") });
	result.push_back({ qstr("groupCallMuted2"), qstr("#16ccfb"), qstr(""), qstr("group call muted button color2") });
	result.push_back({ qstr("groupCallForceMutedBar1"), qstr("#c65493"), qstr(""), qstr("group call force muted top bar color1") });
	result.push_back({ qstr("groupCallForceMutedBar2"), qstr("#7a6af1"), qstr(""), qstr("group call force muted top bar color2") });
	result.push_back({ qstr("groupCallForceMutedBar3"), qstr("#5f95e8"), qstr(""), qstr("group call force muted top bar color3") });
	result.push_back({ qstr("groupCallForceMuted1"), qstr("#4f9cff"), qstr(""), qstr("group call force muted button color1") });
	result.push_back({ qstr("groupCallForceMuted2"), qstr("#9b52e9"), qstr(""), qstr("group call force muted button color2") });
	result.push_back({ qstr("groupCallForceMuted3"), qstr("#eb5353"), qstr(""), qstr("group call force muted button color3") });
	result.push_back({ qstr("groupCallMenuBg"), qstr("#292d33"), qstr(""), qstr("group call popup menu background") });
	result.push_back({ qstr("groupCallMenuBgOver"), qstr("#343940"), qstr(""), qstr("group call popup menu with mouse over") });
	result.push_back({ qstr("groupCallMenuBgRipple"), qstr("#3a4047"), qstr(""), qstr("group call popup menu ripple effect") });
	result.push_back({ qstr("groupCallLeaveBg"), qstr("#f75c5c7f"), qstr(""), qstr("group call leave button background") });
	result.push_back({ qstr("groupCallLeaveBgRipple"), qstr("#f75c5c9e"), qstr(""), qstr("group call leave button ripple effect") });
	result.push_back({ qstr("groupCallVideoTextFg"), qstr("#ffffffe0"), qstr(""), qstr("group call text over video") });
	result.push_back({ qstr("groupCallVideoSubTextFg"), qstr("#ffffffc0"), qstr(""), qstr("group call additional text over video") });
	result.push_back({ qstr("callBarBg"), qstr("dialogsBgActive"), qstr(""), qstr("active phone call bar background") });
	result.push_back({ qstr("callBarMuteRipple"), qstr("dialogsRippleBgActive"), qstr(""), qstr("active phone call bar mute and hangup button ripple effect") });
	result.push_back({ qstr("callBarBgMuted"), qstr("#8f8f8f"), qstr("dialogsUnreadBgMuted"), qstr("phone call bar with muted mic background") });
	result.push_back({ qstr("callBarFg"), qstr("dialogsNameFgActive"), qstr(""), qstr("phone call bar text and icons") });
	result.push_back({ qstr("importantTooltipBg"), qstr("toastBg"), qstr(""), qstr("group call important tooltip background color") });
	result.push_back({ qstr("importantTooltipFg"), qstr("toastFg"), qstr(""), qstr("group call important tooltip text color") });
	result.push_back({ qstr("importantTooltipFgLink"), qstr("mediaviewTextLinkFg"), qstr(""), qstr("group call important tooltip text link color") });
	result.push_back({ qstr("outdatedFg"), qstr("#ffffff"), qstr(""), qstr("operating system version is outdated bar text") });
	result.push_back({ qstr("outdateSoonBg"), qstr("#e08543"), qstr(""), qstr("operating system version is soon outdated bar background") });
	result.push_back({ qstr("outdatedBg"), qstr("#e05745"), qstr(""), qstr("operating system version is already outdated bar background") });
	result.push_back({ qstr("spellUnderline"), qstr("#ff000088"), qstr("attentionButtonFg"), qstr("misspelled words") });
	result.push_back({ qstr("walletTitleBg"), qstr("#121213"), qstr(""), qstr("wallet window title background when window is inactive") });
	result.push_back({ qstr("walletTitleBgActive"), qstr("walletTitleBg"), qstr(""), qstr("wallet window title background when window is active") });
	result.push_back({ qstr("walletTitleButtonBg"), qstr("walletTitleBg"), qstr(""), qstr("\
wallet window title minimize/maximize/restore button background when window is in\
active (Windows only)") });
	result.push_back({ qstr("walletTitleButtonFg"), qstr("#5a5a5b"), qstr(""), qstr("\
wallet window title minimize/maximize/restore button icon when window is inactive\
 (Windows only)") });
	result.push_back({ qstr("walletTitleButtonBgOver"), qstr("#373738"), qstr(""), qstr("\
wallet window title minimize/maximize/restore button background with mouse over w\
hen window is inactive (Windows only)") });
	result.push_back({ qstr("walletTitleButtonFgOver"), qstr("#747475"), qstr(""), qstr("\
wallet window title minimize/maximize/restore button icon with mouse over when wi\
ndow is inactive (Windows only)") });
	result.push_back({ qstr("walletTitleButtonBgActive"), qstr("walletTitleButtonBg"), qstr(""), qstr("\
wallet window title minimize/maximize/restore button background when window is ac\
tive (Windows only)") });
	result.push_back({ qstr("walletTitleButtonFgActive"), qstr("walletTitleButtonFg"), qstr(""), qstr("\
wallet window title minimize/maximize/restore button icon when window is active (\
Windows only)") });
	result.push_back({ qstr("walletTitleButtonBgActiveOver"), qstr("walletTitleButtonBgOver"), qstr(""), qstr("\
wallet window title minimize/maximize/restore button background with mouse over w\
hen window is active (Windows only)") });
	result.push_back({ qstr("walletTitleButtonFgActiveOver"), qstr("walletTitleButtonFgOver"), qstr(""), qstr("\
wallet window title minimize/maximize/restore button icon with mouse over when wi\
ndow is active (Windows only)") });
	result.push_back({ qstr("walletTitleButtonCloseBg"), qstr("walletTitleButtonBg"), qstr(""), qstr("\
wallet window title close button background when window is inactive (Windows only\
)") });
	result.push_back({ qstr("walletTitleButtonCloseFg"), qstr("walletTitleButtonFg"), qstr(""), qstr("wallet window title close button icon when window is inactive (Windows only)") });
	result.push_back({ qstr("walletTitleButtonCloseBgOver"), qstr("titleButtonCloseBgOver"), qstr(""), qstr("\
wallet window title close button background with mouse over when window is inacti\
ve (Windows only)") });
	result.push_back({ qstr("walletTitleButtonCloseFgOver"), qstr("titleButtonCloseFgOver"), qstr(""), qstr("\
wallet window title close button icon with mouse over when window is inactive (Wi\
ndows only)") });
	result.push_back({ qstr("walletTitleButtonCloseBgActive"), qstr("walletTitleButtonCloseBg"), qstr(""), qstr("wallet window title close button background when window is active (Windows only)") });
	result.push_back({ qstr("walletTitleButtonCloseFgActive"), qstr("walletTitleButtonCloseFg"), qstr(""), qstr("wallet window title close button icon when window is active (Windows only)") });
	result.push_back({ qstr("walletTitleButtonCloseBgActiveOver"), qstr("walletTitleButtonCloseBgOver"), qstr(""), qstr("\
wallet window title close button background with mouse over when window is active\
 (Windows only)") });
	result.push_back({ qstr("walletTitleButtonCloseFgActiveOver"), qstr("walletTitleButtonCloseFgOver"), qstr(""), qstr("\
wallet window title close button icon with mouse over when window is active (Wind\
ows only)") });
	result.push_back({ qstr("walletTopBg"), qstr("#1e1f21"), qstr(""), qstr("wallet top part background") });
	result.push_back({ qstr("walletBalanceFg"), qstr("#ffffff"), qstr(""), qstr("wallet balance text") });
	result.push_back({ qstr("walletSubBalanceFg"), qstr("#f9f9f9"), qstr(""), qstr("wallet balance label text") });
	result.push_back({ qstr("walletTopLabelFg"), qstr("#999999"), qstr(""), qstr("wallet top updated label text") });
	result.push_back({ qstr("walletTopIconFg"), qstr("walletTopLabelFg"), qstr(""), qstr("wallet top refresh and menu icons") });
	result.push_back({ qstr("walletTopIconRipple"), qstr("#ffffff12"), qstr(""), qstr("wallet top menu icon ripple effect") });
	result.push_back({ qstr("sideBarBg"), qstr("#293a4c"), qstr(""), qstr("filters side bar background") });
	result.push_back({ qstr("sideBarBgActive"), qstr("#17212b"), qstr(""), qstr("filters side bar active background") });
	result.push_back({ qstr("sideBarBgRipple"), qstr("#1e2b38"), qstr(""), qstr("filters side bar ripple effect") });
	result.push_back({ qstr("sideBarTextFg"), qstr("#8897a6"), qstr(""), qstr("filters side bar text") });
	result.push_back({ qstr("sideBarTextFgActive"), qstr("#64b9fa"), qstr(""), qstr("filters side bar active item text") });
	result.push_back({ qstr("sideBarIconFg"), qstr("#8393a3"), qstr(""), qstr("filters side bar icon") });
	result.push_back({ qstr("sideBarIconFgActive"), qstr("#5eb5f7"), qstr(""), qstr("filters side bar active item icon") });
	result.push_back({ qstr("sideBarBadgeBg"), qstr("#5eb5f7"), qstr(""), qstr("filters side bar badge background") });
	result.push_back({ qstr("sideBarBadgeBgActive"), qstr("sideBarBadgeBg"), qstr(""), qstr("filters side bar badge background when folder is open") });
	result.push_back({ qstr("sideBarBadgeBgMuted"), qstr("#8393a3"), qstr(""), qstr("filters side bar unimportant badge background") });
	result.push_back({ qstr("sideBarBadgeBgMutedActive"), qstr("sideBarBadgeBg"), qstr(""), qstr("filters side bar unimportant badge background when folder is open") });
	result.push_back({ qstr("sideBarBadgeFg"), qstr("#ffffff"), qstr(""), qstr("filters side bar badge text") });
	result.push_back({ qstr("songCoverOverlayFg"), qstr("#00000066"), qstr(""), qstr("song cover overlay") });
	result.push_back({ qstr("photoEditorItemBaseHandleFg"), qstr("#3ccaef"), qstr(""), qstr("photo editor handle circle") });
	result.push_back({ qstr("premiumButtonBg1"), qstr("#55a5ff"), qstr(""), qstr("upgrade to premium button gradient 1") });
	result.push_back({ qstr("premiumButtonBg2"), qstr("#a767ff"), qstr(""), qstr("upgrade to premium button gradient 2") });
	result.push_back({ qstr("premiumButtonBg3"), qstr("#db5c9d"), qstr(""), qstr("upgrade to premium button gradient 3") });
	result.push_back({ qstr("premiumButtonFg"), qstr("#ffffff"), qstr(""), qstr("upgrade to premium button text") });
	result.push_back({ qstr("premiumIconBg1"), qstr("#f38926"), qstr(""), qstr("icon in premium settings gradient 1") });
	result.push_back({ qstr("premiumIconBg2"), qstr("#e44456"), qstr(""), qstr("icon in premium settings gradient 2") });
	result.push_back({ qstr("premiumIconBg3"), qstr("#4acd43"), qstr(""), qstr("icon in premium settings gradient 3") });
	result.push_back({ qstr("statisticsChartInactive"), qstr("#e2eef999"), qstr(""), qstr("inactive area in footer of statistic charts") });
	result.push_back({ qstr("statisticsChartActive"), qstr("#baccd9d8"), qstr(""), qstr("sides in footer of statistic charts") });
	result.push_back({ qstr("statisticsChartLineBlue"), qstr("#327fe5"), qstr(""), qstr("represents blue color on statistical charts") });
	result.push_back({ qstr("statisticsChartLineGreen"), qstr("#61c752"), qstr(""), qstr("represents green color on statistical charts") });
	result.push_back({ qstr("statisticsChartLineRed"), qstr("#e05356"), qstr(""), qstr("represents red color on statistical charts") });
	result.push_back({ qstr("statisticsChartLineGolden"), qstr("#eba52d"), qstr(""), qstr("represents golden color on statistical charts") });
	result.push_back({ qstr("statisticsChartLineLightblue"), qstr("#58a8ed"), qstr(""), qstr("represents lightblue color on statistical charts") });
	result.push_back({ qstr("statisticsChartLineLightgreen"), qstr("#8fcf39"), qstr(""), qstr("represents lightgreen color on statistical charts") });
	result.push_back({ qstr("statisticsChartLineOrange"), qstr("#f28c39"), qstr(""), qstr("represents orange color on statistical charts") });
	result.push_back({ qstr("statisticsChartLineIndigo"), qstr("#7f79f3"), qstr(""), qstr("represents indigo color on statistical charts") });
	result.push_back({ qstr("statisticsChartLinePurple"), qstr("#9f79e8"), qstr(""), qstr("represents purple color on statistical charts") });
	result.push_back({ qstr("statisticsChartLineCyan"), qstr("#40d0ca"), qstr(""), qstr("represents cyan color on statistical charts") });
	result.push_back({ qstr("creditsBg1"), qstr("#ffb222"), qstr(""), qstr("credits icon gradient 1, normal") });
	result.push_back({ qstr("creditsBg2"), qstr("#ffd951"), qstr(""), qstr("credits icon gradient 2, light") });
	result.push_back({ qstr("creditsBg3"), qstr("#f0b400"), qstr(""), qstr("credits icon gradient 3, dark") });
	result.push_back({ qstr("creditsFg"), qstr("#ba7000"), qstr(""), qstr("credits text on light background") });
	result.push_back({ qstr("creditsStroke"), qstr("#da8735"), qstr(""), qstr("credits icon stroke") });
	result.push_back({ qstr("currencyFg"), qstr("#168acd"), qstr(""), qstr("currency icon, blue") });
	result.push_back({ qstr("rankAdminFg"), qstr("#49a355"), qstr(""), qstr("admin badge text and pill, green") });
	result.push_back({ qstr("rankOwnerFg"), qstr("#956ac8"), qstr(""), qstr("owner badge text and pill, purple") });
	result.push_back({ qstr("rankUserFg"), qstr("windowSubTextFg"), qstr(""), qstr("regular user badge text, gray") });
	result.push_back({ qstr("dialogsMentionIconFg"), qstr("#40a7e3"), qstr("dialogsVerifiedIconBg"), qstr("chat list mention icon") });
	result.push_back({ qstr("dialogsReactionIconFg"), qstr("#e05356"), qstr("attentionButtonFg"), qstr("chat list reaction icon") });
	result.push_back({ qstr("dialogsPollIconFg"), qstr("#997be1"), qstr("historyPeer5NameFg"), qstr("chat list poll icon") });

	return result;
}

} // namespace main_palette

namespace internal {

void init_palette(int scale) {
	if (inited) return;
	inited = true;

	_palette.finalize();
}

} // namespace internal
} // namespace style
