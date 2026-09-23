// WARNING! All changes made in this file will be lost!
// Created from 'colors.palette' by 'codegen_style'
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

void init_palette(int scale);

} // namespace internal

class palette;
class palette_data {
public:
	static constexpr auto kCount = 588;
	static int32 Checksum();

	inline constexpr const color &transparent() const { return _colors[0]; }; // special color
	inline constexpr const color &white() const { return _colors[1]; }; // special color
	inline constexpr const color &windowBg() const { return _colors[2]; };
	inline constexpr const color &windowFg() const { return _colors[3]; };
	inline constexpr const color &windowBgOver() const { return _colors[4]; };
	inline constexpr const color &windowBgRipple() const { return _colors[5]; };
	inline constexpr const color &windowFgOver() const { return _colors[6]; };
	inline constexpr const color &windowSubTextFg() const { return _colors[7]; };
	inline constexpr const color &windowSubTextFgOver() const { return _colors[8]; };
	inline constexpr const color &windowBoldFg() const { return _colors[9]; };
	inline constexpr const color &windowBoldFgOver() const { return _colors[10]; };
	inline constexpr const color &windowBgActive() const { return _colors[11]; };
	inline constexpr const color &windowFgActive() const { return _colors[12]; };
	inline constexpr const color &windowActiveTextFg() const { return _colors[13]; };
	inline constexpr const color &windowShadowFg() const { return _colors[14]; };
	inline constexpr const color &windowShadowFgFallback() const { return _colors[15]; };
	inline constexpr const color &shadowFg() const { return _colors[16]; };
	inline constexpr const color &slideFadeOutBg() const { return _colors[17]; };
	inline constexpr const color &slideFadeOutShadowFg() const { return _colors[18]; };
	inline constexpr const color &imageBg() const { return _colors[19]; };
	inline constexpr const color &imageBgTransparent() const { return _colors[20]; };
	inline constexpr const color &activeButtonBg() const { return _colors[21]; };
	inline constexpr const color &activeButtonBgOver() const { return _colors[22]; };
	inline constexpr const color &activeButtonBgRipple() const { return _colors[23]; };
	inline constexpr const color &activeButtonFg() const { return _colors[24]; };
	inline constexpr const color &activeButtonFgOver() const { return _colors[25]; };
	inline constexpr const color &activeButtonSecondaryFg() const { return _colors[26]; };
	inline constexpr const color &activeButtonSecondaryFgOver() const { return _colors[27]; };
	inline constexpr const color &activeLineFg() const { return _colors[28]; };
	inline constexpr const color &activeLineFgError() const { return _colors[29]; };
	inline constexpr const color &lightButtonBg() const { return _colors[30]; };
	inline constexpr const color &lightButtonBgOver() const { return _colors[31]; };
	inline constexpr const color &lightButtonBgRipple() const { return _colors[32]; };
	inline constexpr const color &lightButtonFg() const { return _colors[33]; };
	inline constexpr const color &lightButtonFgOver() const { return _colors[34]; };
	inline constexpr const color &attentionButtonFg() const { return _colors[35]; };
	inline constexpr const color &attentionButtonFgOver() const { return _colors[36]; };
	inline constexpr const color &attentionButtonBgOver() const { return _colors[37]; };
	inline constexpr const color &attentionButtonBgRipple() const { return _colors[38]; };
	inline constexpr const color &menuBg() const { return _colors[39]; };
	inline constexpr const color &menuBgOver() const { return _colors[40]; };
	inline constexpr const color &menuBgRipple() const { return _colors[41]; };
	inline constexpr const color &menuIconFg() const { return _colors[42]; };
	inline constexpr const color &menuIconFgOver() const { return _colors[43]; };
	inline constexpr const color &menuSubmenuArrowFg() const { return _colors[44]; };
	inline constexpr const color &menuFgDisabled() const { return _colors[45]; };
	inline constexpr const color &menuSeparatorFg() const { return _colors[46]; };
	inline constexpr const color &scrollBarBg() const { return _colors[47]; };
	inline constexpr const color &scrollBarBgOver() const { return _colors[48]; };
	inline constexpr const color &scrollBg() const { return _colors[49]; };
	inline constexpr const color &scrollBgOver() const { return _colors[50]; };
	inline constexpr const color &smallCloseIconFg() const { return _colors[51]; };
	inline constexpr const color &smallCloseIconFgOver() const { return _colors[52]; };
	inline constexpr const color &radialFg() const { return _colors[53]; };
	inline constexpr const color &radialBg() const { return _colors[54]; };
	inline constexpr const color &placeholderFg() const { return _colors[55]; };
	inline constexpr const color &placeholderFgActive() const { return _colors[56]; };
	inline constexpr const color &inputBorderFg() const { return _colors[57]; };
	inline constexpr const color &filterInputBorderFg() const { return _colors[58]; };
	inline constexpr const color &filterInputActiveBg() const { return _colors[59]; };
	inline constexpr const color &filterInputInactiveBg() const { return _colors[60]; };
	inline constexpr const color &checkboxFg() const { return _colors[61]; };
	inline constexpr const color &botKbBg() const { return _colors[62]; };
	inline constexpr const color &botKbDownBg() const { return _colors[63]; };
	inline constexpr const color &botKbColor() const { return _colors[64]; };
	inline constexpr const color &botKbPrimaryBg() const { return _colors[65]; };
	inline constexpr const color &botKbDangerBg() const { return _colors[66]; };
	inline constexpr const color &botKbSuccessBg() const { return _colors[67]; };
	inline constexpr const color &botKbInlinePrimaryBg() const { return _colors[68]; };
	inline constexpr const color &botKbInlineDangerBg() const { return _colors[69]; };
	inline constexpr const color &botKbInlineSuccessBg() const { return _colors[70]; };
	inline constexpr const color &sliderBgInactive() const { return _colors[71]; };
	inline constexpr const color &sliderBgActive() const { return _colors[72]; };
	inline constexpr const color &tooltipBg() const { return _colors[73]; };
	inline constexpr const color &tooltipFg() const { return _colors[74]; };
	inline constexpr const color &tooltipBorderFg() const { return _colors[75]; };
	inline constexpr const color &titleShadow() const { return _colors[76]; };
	inline constexpr const color &titleBg() const { return _colors[77]; };
	inline constexpr const color &titleBgActive() const { return _colors[78]; };
	inline constexpr const color &titleButtonBg() const { return _colors[79]; };
	inline constexpr const color &titleButtonFg() const { return _colors[80]; };
	inline constexpr const color &titleButtonBgOver() const { return _colors[81]; };
	inline constexpr const color &titleButtonFgOver() const { return _colors[82]; };
	inline constexpr const color &titleButtonBgActive() const { return _colors[83]; };
	inline constexpr const color &titleButtonFgActive() const { return _colors[84]; };
	inline constexpr const color &titleButtonBgActiveOver() const { return _colors[85]; };
	inline constexpr const color &titleButtonFgActiveOver() const { return _colors[86]; };
	inline constexpr const color &titleButtonCloseBg() const { return _colors[87]; };
	inline constexpr const color &titleButtonCloseFg() const { return _colors[88]; };
	inline constexpr const color &titleButtonCloseBgOver() const { return _colors[89]; };
	inline constexpr const color &titleButtonCloseFgOver() const { return _colors[90]; };
	inline constexpr const color &titleButtonCloseBgActive() const { return _colors[91]; };
	inline constexpr const color &titleButtonCloseFgActive() const { return _colors[92]; };
	inline constexpr const color &titleButtonCloseBgActiveOver() const { return _colors[93]; };
	inline constexpr const color &titleButtonCloseFgActiveOver() const { return _colors[94]; };
	inline constexpr const color &titleFg() const { return _colors[95]; };
	inline constexpr const color &titleFgActive() const { return _colors[96]; };
	inline constexpr const color &trayCounterBg() const { return _colors[97]; };
	inline constexpr const color &trayCounterBgMute() const { return _colors[98]; };
	inline constexpr const color &trayCounterFg() const { return _colors[99]; };
	inline constexpr const color &trayCounterBgMacInvert() const { return _colors[100]; };
	inline constexpr const color &trayCounterFgMacInvert() const { return _colors[101]; };
	inline constexpr const color &layerBg() const { return _colors[102]; };
	inline constexpr const color &cancelIconFg() const { return _colors[103]; };
	inline constexpr const color &cancelIconFgOver() const { return _colors[104]; };
	inline constexpr const color &boxBg() const { return _colors[105]; };
	inline constexpr const color &boxTextFg() const { return _colors[106]; };
	inline constexpr const color &boxTextFgGood() const { return _colors[107]; };
	inline constexpr const color &boxTextFgError() const { return _colors[108]; };
	inline constexpr const color &boxTitleFg() const { return _colors[109]; };
	inline constexpr const color &boxSearchBg() const { return _colors[110]; };
	inline constexpr const color &boxTitleAdditionalFg() const { return _colors[111]; };
	inline constexpr const color &boxTitleCloseFg() const { return _colors[112]; };
	inline constexpr const color &boxTitleCloseFgOver() const { return _colors[113]; };
	inline constexpr const color &boxDividerBg() const { return _colors[114]; };
	inline constexpr const color &boxDividerFg() const { return _colors[115]; };
	inline constexpr const color &paymentsTipActive() const { return _colors[116]; };
	inline constexpr const color &membersAboutLimitFg() const { return _colors[117]; };
	inline constexpr const color &contactsBg() const { return _colors[118]; };
	inline constexpr const color &contactsBgOver() const { return _colors[119]; };
	inline constexpr const color &contactsNameFg() const { return _colors[120]; };
	inline constexpr const color &contactsStatusFg() const { return _colors[121]; };
	inline constexpr const color &contactsStatusFgOver() const { return _colors[122]; };
	inline constexpr const color &contactsStatusFgOnline() const { return _colors[123]; };
	inline constexpr const color &photoCropFadeBg() const { return _colors[124]; };
	inline constexpr const color &photoCropPointFg() const { return _colors[125]; };
	inline constexpr const color &callArrowFg() const { return _colors[126]; };
	inline constexpr const color &callArrowMissedFg() const { return _colors[127]; };
	inline constexpr const color &introBg() const { return _colors[128]; };
	inline constexpr const color &introTitleFg() const { return _colors[129]; };
	inline constexpr const color &introDescriptionFg() const { return _colors[130]; };
	inline constexpr const color &introCoverTopBg() const { return _colors[131]; };
	inline constexpr const color &introCoverBottomBg() const { return _colors[132]; };
	inline constexpr const color &introCoverIconsFg() const { return _colors[133]; };
	inline constexpr const color &introCoverPlaneTrace() const { return _colors[134]; };
	inline constexpr const color &introCoverPlaneInner() const { return _colors[135]; };
	inline constexpr const color &introCoverPlaneOuter() const { return _colors[136]; };
	inline constexpr const color &introCoverPlaneTop() const { return _colors[137]; };
	inline constexpr const color &dialogsMenuIconFg() const { return _colors[138]; };
	inline constexpr const color &dialogsMenuIconFgOver() const { return _colors[139]; };
	inline constexpr const color &dialogsBg() const { return _colors[140]; };
	inline constexpr const color &dialogsNameFg() const { return _colors[141]; };
	inline constexpr const color &dialogsChatIconFg() const { return _colors[142]; };
	inline constexpr const color &dialogsDateFg() const { return _colors[143]; };
	inline constexpr const color &dialogsTextFg() const { return _colors[144]; };
	inline constexpr const color &dialogsTextFgService() const { return _colors[145]; };
	inline constexpr const color &dialogsDraftFg() const { return _colors[146]; };
	inline constexpr const color &dialogsVerifiedIconBg() const { return _colors[147]; };
	inline constexpr const color &dialogsVerifiedIconFg() const { return _colors[148]; };
	inline constexpr const color &dialogsSendingIconFg() const { return _colors[149]; };
	inline constexpr const color &dialogsSentIconFg() const { return _colors[150]; };
	inline constexpr const color &dialogsUnreadBg() const { return _colors[151]; };
	inline constexpr const color &dialogsUnreadBgMuted() const { return _colors[152]; };
	inline constexpr const color &dialogsUnreadFg() const { return _colors[153]; };
	inline constexpr const color &dialogsArchiveFg() const { return _colors[154]; };
	inline constexpr const color &dialogsOnlineBadgeFg() const { return _colors[155]; };
	inline constexpr const color &dialogsScamFg() const { return _colors[156]; };
	inline constexpr const color &dialogsBgOver() const { return _colors[157]; };
	inline constexpr const color &dialogsNameFgOver() const { return _colors[158]; };
	inline constexpr const color &dialogsChatIconFgOver() const { return _colors[159]; };
	inline constexpr const color &dialogsDateFgOver() const { return _colors[160]; };
	inline constexpr const color &dialogsTextFgOver() const { return _colors[161]; };
	inline constexpr const color &dialogsTextFgServiceOver() const { return _colors[162]; };
	inline constexpr const color &dialogsDraftFgOver() const { return _colors[163]; };
	inline constexpr const color &dialogsVerifiedIconBgOver() const { return _colors[164]; };
	inline constexpr const color &dialogsVerifiedIconFgOver() const { return _colors[165]; };
	inline constexpr const color &dialogsSendingIconFgOver() const { return _colors[166]; };
	inline constexpr const color &dialogsSentIconFgOver() const { return _colors[167]; };
	inline constexpr const color &dialogsUnreadBgOver() const { return _colors[168]; };
	inline constexpr const color &dialogsUnreadBgMutedOver() const { return _colors[169]; };
	inline constexpr const color &dialogsUnreadFgOver() const { return _colors[170]; };
	inline constexpr const color &dialogsArchiveFgOver() const { return _colors[171]; };
	inline constexpr const color &dialogsScamFgOver() const { return _colors[172]; };
	inline constexpr const color &dialogsBgActive() const { return _colors[173]; };
	inline constexpr const color &dialogsNameFgActive() const { return _colors[174]; };
	inline constexpr const color &dialogsChatIconFgActive() const { return _colors[175]; };
	inline constexpr const color &dialogsDateFgActive() const { return _colors[176]; };
	inline constexpr const color &dialogsTextFgActive() const { return _colors[177]; };
	inline constexpr const color &dialogsTextFgServiceActive() const { return _colors[178]; };
	inline constexpr const color &dialogsDraftFgActive() const { return _colors[179]; };
	inline constexpr const color &dialogsVerifiedIconBgActive() const { return _colors[180]; };
	inline constexpr const color &dialogsVerifiedIconFgActive() const { return _colors[181]; };
	inline constexpr const color &dialogsSendingIconFgActive() const { return _colors[182]; };
	inline constexpr const color &dialogsSentIconFgActive() const { return _colors[183]; };
	inline constexpr const color &dialogsUnreadBgActive() const { return _colors[184]; };
	inline constexpr const color &dialogsUnreadBgMutedActive() const { return _colors[185]; };
	inline constexpr const color &dialogsUnreadFgActive() const { return _colors[186]; };
	inline constexpr const color &dialogsOnlineBadgeFgActive() const { return _colors[187]; };
	inline constexpr const color &dialogsScamFgActive() const { return _colors[188]; };
	inline constexpr const color &dialogsRippleBg() const { return _colors[189]; };
	inline constexpr const color &dialogsRippleBgActive() const { return _colors[190]; };
	inline constexpr const color &searchedBarBg() const { return _colors[191]; };
	inline constexpr const color &searchedBarFg() const { return _colors[192]; };
	inline constexpr const color &searchedTextMatchBg() const { return _colors[193]; };
	inline constexpr const color &searchedTextMatchFg() const { return _colors[194]; };
	inline constexpr const color &searchedTextCurrentMatchBg() const { return _colors[195]; };
	inline constexpr const color &searchedTextCurrentMatchFg() const { return _colors[196]; };
	inline constexpr const color &topBarBg() const { return _colors[197]; };
	inline constexpr const color &emojiPanBg() const { return _colors[198]; };
	inline constexpr const color &emojiPanCategories() const { return _colors[199]; };
	inline constexpr const color &emojiPanHeaderFg() const { return _colors[200]; };
	inline constexpr const color &emojiPanHeaderBg() const { return _colors[201]; };
	inline constexpr const color &emojiIconFg() const { return _colors[202]; };
	inline constexpr const color &emojiSubIconFgActive() const { return _colors[203]; };
	inline constexpr const color &stickerPanDeleteBg() const { return _colors[204]; };
	inline constexpr const color &stickerPanDeleteFg() const { return _colors[205]; };
	inline constexpr const color &stickerPreviewBg() const { return _colors[206]; };
	inline constexpr const color &stickerPanPremium1() const { return _colors[207]; };
	inline constexpr const color &stickerPanPremium2() const { return _colors[208]; };
	inline constexpr const color &historyTextInFg() const { return _colors[209]; };
	inline constexpr const color &historyTextInFgSelected() const { return _colors[210]; };
	inline constexpr const color &historyTextOutFg() const { return _colors[211]; };
	inline constexpr const color &historyTextOutFgSelected() const { return _colors[212]; };
	inline constexpr const color &historyLinkInFg() const { return _colors[213]; };
	inline constexpr const color &historyLinkInFgSelected() const { return _colors[214]; };
	inline constexpr const color &historyLinkOutFg() const { return _colors[215]; };
	inline constexpr const color &historyLinkOutFgSelected() const { return _colors[216]; };
	inline constexpr const color &historyFileNameInFg() const { return _colors[217]; };
	inline constexpr const color &historyFileNameInFgSelected() const { return _colors[218]; };
	inline constexpr const color &historyFileNameOutFg() const { return _colors[219]; };
	inline constexpr const color &historyFileNameOutFgSelected() const { return _colors[220]; };
	inline constexpr const color &historyOutIconFg() const { return _colors[221]; };
	inline constexpr const color &historyOutIconFgSelected() const { return _colors[222]; };
	inline constexpr const color &historyIconFgInverted() const { return _colors[223]; };
	inline constexpr const color &historySendingOutIconFg() const { return _colors[224]; };
	inline constexpr const color &historySendingInIconFg() const { return _colors[225]; };
	inline constexpr const color &historySendingInvertedIconFg() const { return _colors[226]; };
	inline constexpr const color &historyCallArrowInFg() const { return _colors[227]; };
	inline constexpr const color &historyCallArrowInFgSelected() const { return _colors[228]; };
	inline constexpr const color &historyCallArrowMissedInFg() const { return _colors[229]; };
	inline constexpr const color &historyCallArrowMissedInFgSelected() const { return _colors[230]; };
	inline constexpr const color &historyCallArrowOutFg() const { return _colors[231]; };
	inline constexpr const color &historyCallArrowOutFgSelected() const { return _colors[232]; };
	inline constexpr const color &historyUnreadBarBg() const { return _colors[233]; };
	inline constexpr const color &historyUnreadBarBorder() const { return _colors[234]; };
	inline constexpr const color &historyUnreadBarFg() const { return _colors[235]; };
	inline constexpr const color &historyForwardChooseBg() const { return _colors[236]; };
	inline constexpr const color &historyForwardChooseFg() const { return _colors[237]; };
	inline constexpr const color &historyPeer1NameFg() const { return _colors[238]; };
	inline constexpr const color &historyPeer1NameFgSelected() const { return _colors[239]; };
	inline constexpr const color &historyPeer1UserpicBg() const { return _colors[240]; };
	inline constexpr const color &historyPeer2NameFg() const { return _colors[241]; };
	inline constexpr const color &historyPeer2NameFgSelected() const { return _colors[242]; };
	inline constexpr const color &historyPeer2UserpicBg() const { return _colors[243]; };
	inline constexpr const color &historyPeer3NameFg() const { return _colors[244]; };
	inline constexpr const color &historyPeer3NameFgSelected() const { return _colors[245]; };
	inline constexpr const color &historyPeer3UserpicBg() const { return _colors[246]; };
	inline constexpr const color &historyPeer4NameFg() const { return _colors[247]; };
	inline constexpr const color &historyPeer4NameFgSelected() const { return _colors[248]; };
	inline constexpr const color &historyPeer4UserpicBg() const { return _colors[249]; };
	inline constexpr const color &historyPeer5NameFg() const { return _colors[250]; };
	inline constexpr const color &historyPeer5NameFgSelected() const { return _colors[251]; };
	inline constexpr const color &historyPeer5UserpicBg() const { return _colors[252]; };
	inline constexpr const color &historyPeer6NameFg() const { return _colors[253]; };
	inline constexpr const color &historyPeer6NameFgSelected() const { return _colors[254]; };
	inline constexpr const color &historyPeer6UserpicBg() const { return _colors[255]; };
	inline constexpr const color &historyPeer7NameFg() const { return _colors[256]; };
	inline constexpr const color &historyPeer7NameFgSelected() const { return _colors[257]; };
	inline constexpr const color &historyPeer7UserpicBg() const { return _colors[258]; };
	inline constexpr const color &historyPeer8NameFg() const { return _colors[259]; };
	inline constexpr const color &historyPeer8NameFgSelected() const { return _colors[260]; };
	inline constexpr const color &historyPeer8UserpicBg() const { return _colors[261]; };
	inline constexpr const color &historyPeerUserpicFg() const { return _colors[262]; };
	inline constexpr const color &historyPeerSavedMessagesBg() const { return _colors[263]; };
	inline constexpr const color &historyPeerArchiveUserpicBg() const { return _colors[264]; };
	inline constexpr const color &historyPeer1UserpicBg2() const { return _colors[265]; };
	inline constexpr const color &historyPeer2UserpicBg2() const { return _colors[266]; };
	inline constexpr const color &historyPeer3UserpicBg2() const { return _colors[267]; };
	inline constexpr const color &historyPeer4UserpicBg2() const { return _colors[268]; };
	inline constexpr const color &historyPeer5UserpicBg2() const { return _colors[269]; };
	inline constexpr const color &historyPeer6UserpicBg2() const { return _colors[270]; };
	inline constexpr const color &historyPeer7UserpicBg2() const { return _colors[271]; };
	inline constexpr const color &historyPeer8UserpicBg2() const { return _colors[272]; };
	inline constexpr const color &historyPeerSavedMessagesBg2() const { return _colors[273]; };
	inline constexpr const color &settingsIconBg1() const { return _colors[274]; };
	inline constexpr const color &settingsIconBg2() const { return _colors[275]; };
	inline constexpr const color &settingsIconBg3() const { return _colors[276]; };
	inline constexpr const color &settingsIconBg4() const { return _colors[277]; };
	inline constexpr const color &settingsIconBg5() const { return _colors[278]; };
	inline constexpr const color &settingsIconBg6() const { return _colors[279]; };
	inline constexpr const color &settingsIconBg8() const { return _colors[280]; };
	inline constexpr const color &settingsIconBgArchive() const { return _colors[281]; };
	inline constexpr const color &settingsIconFg() const { return _colors[282]; };
	inline constexpr const color &historyScrollBarBg() const { return _colors[283]; };
	inline constexpr const color &historyScrollBarBgOver() const { return _colors[284]; };
	inline constexpr const color &historyScrollBg() const { return _colors[285]; };
	inline constexpr const color &historyScrollBgOver() const { return _colors[286]; };
	inline constexpr const color &msgInBg() const { return _colors[287]; };
	inline constexpr const color &msgInBgSelected() const { return _colors[288]; };
	inline constexpr const color &msgOutBg() const { return _colors[289]; };
	inline constexpr const color &msgOutBgSelected() const { return _colors[290]; };
	inline constexpr const color &msgSelectOverlay() const { return _colors[291]; };
	inline constexpr const color &msgStickerOverlay() const { return _colors[292]; };
	inline constexpr const color &msgInServiceFg() const { return _colors[293]; };
	inline constexpr const color &msgInServiceFgSelected() const { return _colors[294]; };
	inline constexpr const color &msgOutServiceFg() const { return _colors[295]; };
	inline constexpr const color &msgOutServiceFgSelected() const { return _colors[296]; };
	inline constexpr const color &msgInShadow() const { return _colors[297]; };
	inline constexpr const color &msgInShadowSelected() const { return _colors[298]; };
	inline constexpr const color &msgOutShadow() const { return _colors[299]; };
	inline constexpr const color &msgOutShadowSelected() const { return _colors[300]; };
	inline constexpr const color &msgInDateFg() const { return _colors[301]; };
	inline constexpr const color &msgInDateFgSelected() const { return _colors[302]; };
	inline constexpr const color &msgOutDateFg() const { return _colors[303]; };
	inline constexpr const color &msgOutDateFgSelected() const { return _colors[304]; };
	inline constexpr const color &msgServiceFg() const { return _colors[305]; };
	inline constexpr const color &msgServiceBg() const { return _colors[306]; };
	inline constexpr const color &msgServiceBgSelected() const { return _colors[307]; };
	inline constexpr const color &msgInReplyBarColor() const { return _colors[308]; };
	inline constexpr const color &msgInReplyBarSelColor() const { return _colors[309]; };
	inline constexpr const color &msgOutReplyBarColor() const { return _colors[310]; };
	inline constexpr const color &msgOutReplyBarSelColor() const { return _colors[311]; };
	inline constexpr const color &msgImgReplyBarColor() const { return _colors[312]; };
	inline constexpr const color &msgInMonoFg() const { return _colors[313]; };
	inline constexpr const color &msgOutMonoFg() const { return _colors[314]; };
	inline constexpr const color &msgInMonoFgSelected() const { return _colors[315]; };
	inline constexpr const color &msgOutMonoFgSelected() const { return _colors[316]; };
	inline constexpr const color &msgDateImgFg() const { return _colors[317]; };
	inline constexpr const color &msgDateImgBg() const { return _colors[318]; };
	inline constexpr const color &msgDateImgBgOver() const { return _colors[319]; };
	inline constexpr const color &msgDateImgBgSelected() const { return _colors[320]; };
	inline constexpr const color &msgFileThumbLinkInFg() const { return _colors[321]; };
	inline constexpr const color &msgFileThumbLinkInFgSelected() const { return _colors[322]; };
	inline constexpr const color &msgFileThumbLinkOutFg() const { return _colors[323]; };
	inline constexpr const color &msgFileThumbLinkOutFgSelected() const { return _colors[324]; };
	inline constexpr const color &msgFileInBg() const { return _colors[325]; };
	inline constexpr const color &msgFileInBgOver() const { return _colors[326]; };
	inline constexpr const color &msgFileInBgSelected() const { return _colors[327]; };
	inline constexpr const color &msgFileOutBg() const { return _colors[328]; };
	inline constexpr const color &msgFileOutBgSelected() const { return _colors[329]; };
	inline constexpr const color &msgFile1Bg() const { return _colors[330]; };
	inline constexpr const color &msgFile1BgDark() const { return _colors[331]; };
	inline constexpr const color &msgFile1BgOver() const { return _colors[332]; };
	inline constexpr const color &msgFile1BgSelected() const { return _colors[333]; };
	inline constexpr const color &msgFile2Bg() const { return _colors[334]; };
	inline constexpr const color &msgFile2BgDark() const { return _colors[335]; };
	inline constexpr const color &msgFile2BgOver() const { return _colors[336]; };
	inline constexpr const color &msgFile2BgSelected() const { return _colors[337]; };
	inline constexpr const color &msgFile3Bg() const { return _colors[338]; };
	inline constexpr const color &msgFile3BgDark() const { return _colors[339]; };
	inline constexpr const color &msgFile3BgOver() const { return _colors[340]; };
	inline constexpr const color &msgFile3BgSelected() const { return _colors[341]; };
	inline constexpr const color &msgFile4Bg() const { return _colors[342]; };
	inline constexpr const color &msgFile4BgDark() const { return _colors[343]; };
	inline constexpr const color &msgFile4BgOver() const { return _colors[344]; };
	inline constexpr const color &msgFile4BgSelected() const { return _colors[345]; };
	inline constexpr const color &historyFileInIconFg() const { return _colors[346]; };
	inline constexpr const color &historyFileInIconFgSelected() const { return _colors[347]; };
	inline constexpr const color &historyFileInRadialFg() const { return _colors[348]; };
	inline constexpr const color &historyFileInRadialFgSelected() const { return _colors[349]; };
	inline constexpr const color &historyFileOutIconFg() const { return _colors[350]; };
	inline constexpr const color &historyFileOutIconFgSelected() const { return _colors[351]; };
	inline constexpr const color &historyFileOutRadialFg() const { return _colors[352]; };
	inline constexpr const color &historyFileOutRadialFgSelected() const { return _colors[353]; };
	inline constexpr const color &historyFileThumbIconFg() const { return _colors[354]; };
	inline constexpr const color &historyFileThumbIconFgSelected() const { return _colors[355]; };
	inline constexpr const color &historyFileThumbRadialFg() const { return _colors[356]; };
	inline constexpr const color &historyFileThumbRadialFgSelected() const { return _colors[357]; };
	inline constexpr const color &historyVideoMessageProgressFg() const { return _colors[358]; };
	inline constexpr const color &msgWaveformInActive() const { return _colors[359]; };
	inline constexpr const color &msgWaveformInActiveSelected() const { return _colors[360]; };
	inline constexpr const color &msgWaveformInInactive() const { return _colors[361]; };
	inline constexpr const color &msgWaveformInInactiveSelected() const { return _colors[362]; };
	inline constexpr const color &msgWaveformOutActive() const { return _colors[363]; };
	inline constexpr const color &msgWaveformOutActiveSelected() const { return _colors[364]; };
	inline constexpr const color &msgWaveformOutInactive() const { return _colors[365]; };
	inline constexpr const color &msgWaveformOutInactiveSelected() const { return _colors[366]; };
	inline constexpr const color &msgBotKbOverBgAdd() const { return _colors[367]; };
	inline constexpr const color &msgBotKbIconFg() const { return _colors[368]; };
	inline constexpr const color &msgBotKbRippleBg() const { return _colors[369]; };
	inline constexpr const color &mediaInFg() const { return _colors[370]; };
	inline constexpr const color &mediaInFgSelected() const { return _colors[371]; };
	inline constexpr const color &mediaOutFg() const { return _colors[372]; };
	inline constexpr const color &mediaOutFgSelected() const { return _colors[373]; };
	inline constexpr const color &youtubePlayIconBg() const { return _colors[374]; };
	inline constexpr const color &youtubePlayIconFg() const { return _colors[375]; };
	inline constexpr const color &videoPlayIconBg() const { return _colors[376]; };
	inline constexpr const color &videoPlayIconFg() const { return _colors[377]; };
	inline constexpr const color &toastBg() const { return _colors[378]; };
	inline constexpr const color &toastFg() const { return _colors[379]; };
	inline constexpr const color &historyToDownBg() const { return _colors[380]; };
	inline constexpr const color &historyToDownBgOver() const { return _colors[381]; };
	inline constexpr const color &historyToDownBgRipple() const { return _colors[382]; };
	inline constexpr const color &historyToDownFg() const { return _colors[383]; };
	inline constexpr const color &historyToDownFgOver() const { return _colors[384]; };
	inline constexpr const color &historyToDownShadow() const { return _colors[385]; };
	inline constexpr const color &historyComposeAreaBg() const { return _colors[386]; };
	inline constexpr const color &historyComposeAreaFg() const { return _colors[387]; };
	inline constexpr const color &historyComposeAreaFgService() const { return _colors[388]; };
	inline constexpr const color &historyComposeIconFg() const { return _colors[389]; };
	inline constexpr const color &historyComposeIconFgOver() const { return _colors[390]; };
	inline constexpr const color &historySendIconFg() const { return _colors[391]; };
	inline constexpr const color &historySendIconFgOver() const { return _colors[392]; };
	inline constexpr const color &historyPinnedBg() const { return _colors[393]; };
	inline constexpr const color &historyReplyBg() const { return _colors[394]; };
	inline constexpr const color &historyReplyIconFg() const { return _colors[395]; };
	inline constexpr const color &historyReplyCancelFg() const { return _colors[396]; };
	inline constexpr const color &historyReplyCancelFgOver() const { return _colors[397]; };
	inline constexpr const color &historyComposeButtonBg() const { return _colors[398]; };
	inline constexpr const color &historyComposeButtonBgOver() const { return _colors[399]; };
	inline constexpr const color &historyComposeButtonBgRipple() const { return _colors[400]; };
	inline constexpr const color &mapPointDrop() const { return _colors[401]; };
	inline constexpr const color &mapPointDot() const { return _colors[402]; };
	inline constexpr const color &overviewCheckBg() const { return _colors[403]; };
	inline constexpr const color &overviewCheckBgActive() const { return _colors[404]; };
	inline constexpr const color &overviewCheckBorder() const { return _colors[405]; };
	inline constexpr const color &overviewCheckFgActive() const { return _colors[406]; };
	inline constexpr const color &overviewPhotoSelectOverlay() const { return _colors[407]; };
	inline constexpr const color &profileStatusFgOver() const { return _colors[408]; };
	inline constexpr const color &profileVerifiedCheckBg() const { return _colors[409]; };
	inline constexpr const color &profileVerifiedCheckFg() const { return _colors[410]; };
	inline constexpr const color &profileAdminStartFg() const { return _colors[411]; };
	inline constexpr const color &notificationsBoxMonitorFg() const { return _colors[412]; };
	inline constexpr const color &notificationsBoxScreenBg() const { return _colors[413]; };
	inline constexpr const color &notificationSampleUserpicFg() const { return _colors[414]; };
	inline constexpr const color &notificationSampleCloseFg() const { return _colors[415]; };
	inline constexpr const color &notificationSampleTextFg() const { return _colors[416]; };
	inline constexpr const color &notificationSampleNameFg() const { return _colors[417]; };
	inline constexpr const color &mainMenuBg() const { return _colors[418]; };
	inline constexpr const color &mainMenuCoverBg() const { return _colors[419]; };
	inline constexpr const color &mainMenuCloudFg() const { return _colors[420]; };
	inline constexpr const color &mainMenuCloudBg() const { return _colors[421]; };
	inline constexpr const color &mediaPlayerBg() const { return _colors[422]; };
	inline constexpr const color &mediaPlayerActiveFg() const { return _colors[423]; };
	inline constexpr const color &mediaPlayerInactiveFg() const { return _colors[424]; };
	inline constexpr const color &mediaPlayerDisabledFg() const { return _colors[425]; };
	inline constexpr const color &mediaviewFileBg() const { return _colors[426]; };
	inline constexpr const color &mediaviewFileNameFg() const { return _colors[427]; };
	inline constexpr const color &mediaviewFileSizeFg() const { return _colors[428]; };
	inline constexpr const color &mediaviewFileRedCornerFg() const { return _colors[429]; };
	inline constexpr const color &mediaviewFileYellowCornerFg() const { return _colors[430]; };
	inline constexpr const color &mediaviewFileGreenCornerFg() const { return _colors[431]; };
	inline constexpr const color &mediaviewFileBlueCornerFg() const { return _colors[432]; };
	inline constexpr const color &mediaviewFileExtFg() const { return _colors[433]; };
	inline constexpr const color &mediaviewMenuBg() const { return _colors[434]; };
	inline constexpr const color &mediaviewMenuBgOver() const { return _colors[435]; };
	inline constexpr const color &mediaviewMenuBgRipple() const { return _colors[436]; };
	inline constexpr const color &mediaviewMenuFg() const { return _colors[437]; };
	inline constexpr const color &mediaviewBg() const { return _colors[438]; };
	inline constexpr const color &mediaviewVideoBg() const { return _colors[439]; };
	inline constexpr const color &mediaviewControlBg() const { return _colors[440]; };
	inline constexpr const color &mediaviewControlFg() const { return _colors[441]; };
	inline constexpr const color &mediaviewCaptionBg() const { return _colors[442]; };
	inline constexpr const color &mediaviewCaptionFg() const { return _colors[443]; };
	inline constexpr const color &mediaviewTextLinkFg() const { return _colors[444]; };
	inline constexpr const color &mediaviewSaveMsgBg() const { return _colors[445]; };
	inline constexpr const color &mediaviewSaveMsgFg() const { return _colors[446]; };
	inline constexpr const color &mediaviewPlaybackActive() const { return _colors[447]; };
	inline constexpr const color &mediaviewPlaybackInactive() const { return _colors[448]; };
	inline constexpr const color &mediaviewPlaybackActiveOver() const { return _colors[449]; };
	inline constexpr const color &mediaviewPlaybackInactiveOver() const { return _colors[450]; };
	inline constexpr const color &mediaviewPlaybackProgressFg() const { return _colors[451]; };
	inline constexpr const color &mediaviewPlaybackIconFg() const { return _colors[452]; };
	inline constexpr const color &mediaviewPlaybackIconFgOver() const { return _colors[453]; };
	inline constexpr const color &mediaviewPlaybackIconRipple() const { return _colors[454]; };
	inline constexpr const color &mediaviewPipControlsFg() const { return _colors[455]; };
	inline constexpr const color &mediaviewPipControlsFgOver() const { return _colors[456]; };
	inline constexpr const color &mediaviewPipPlaybackActive() const { return _colors[457]; };
	inline constexpr const color &mediaviewPipPlaybackInactive() const { return _colors[458]; };
	inline constexpr const color &mediaviewTransparentBg() const { return _colors[459]; };
	inline constexpr const color &mediaviewTransparentFg() const { return _colors[460]; };
	inline constexpr const color &notificationBg() const { return _colors[461]; };
	inline constexpr const color &callBg() const { return _colors[462]; };
	inline constexpr const color &callBgOpaque() const { return _colors[463]; };
	inline constexpr const color &callBgButton() const { return _colors[464]; };
	inline constexpr const color &callNameFg() const { return _colors[465]; };
	inline constexpr const color &callStatusFg() const { return _colors[466]; };
	inline constexpr const color &callIconBg() const { return _colors[467]; };
	inline constexpr const color &callIconFg() const { return _colors[468]; };
	inline constexpr const color &callIconBgActive() const { return _colors[469]; };
	inline constexpr const color &callIconFgActive() const { return _colors[470]; };
	inline constexpr const color &callIconActiveRipple() const { return _colors[471]; };
	inline constexpr const color &callAnswerBg() const { return _colors[472]; };
	inline constexpr const color &callAnswerRipple() const { return _colors[473]; };
	inline constexpr const color &callAnswerBgOuter() const { return _colors[474]; };
	inline constexpr const color &callHangupBg() const { return _colors[475]; };
	inline constexpr const color &callHangupRipple() const { return _colors[476]; };
	inline constexpr const color &callMuteRipple() const { return _colors[477]; };
	inline constexpr const color &groupCallBg() const { return _colors[478]; };
	inline constexpr const color &groupCallActiveFg() const { return _colors[479]; };
	inline constexpr const color &groupCallMembersBg() const { return _colors[480]; };
	inline constexpr const color &groupCallMembersBgOver() const { return _colors[481]; };
	inline constexpr const color &groupCallMembersBgRipple() const { return _colors[482]; };
	inline constexpr const color &groupCallMembersFg() const { return _colors[483]; };
	inline constexpr const color &groupCallMemberActiveIcon() const { return _colors[484]; };
	inline constexpr const color &groupCallMemberActiveStatus() const { return _colors[485]; };
	inline constexpr const color &groupCallMemberInactiveIcon() const { return _colors[486]; };
	inline constexpr const color &groupCallMemberInactiveStatus() const { return _colors[487]; };
	inline constexpr const color &groupCallMemberMutedIcon() const { return _colors[488]; };
	inline constexpr const color &groupCallMemberNotJoinedStatus() const { return _colors[489]; };
	inline constexpr const color &groupCallIconFg() const { return _colors[490]; };
	inline constexpr const color &groupCallLive1() const { return _colors[491]; };
	inline constexpr const color &groupCallLive2() const { return _colors[492]; };
	inline constexpr const color &groupCallMuted1() const { return _colors[493]; };
	inline constexpr const color &groupCallMuted2() const { return _colors[494]; };
	inline constexpr const color &groupCallForceMutedBar1() const { return _colors[495]; };
	inline constexpr const color &groupCallForceMutedBar2() const { return _colors[496]; };
	inline constexpr const color &groupCallForceMutedBar3() const { return _colors[497]; };
	inline constexpr const color &groupCallForceMuted1() const { return _colors[498]; };
	inline constexpr const color &groupCallForceMuted2() const { return _colors[499]; };
	inline constexpr const color &groupCallForceMuted3() const { return _colors[500]; };
	inline constexpr const color &groupCallMenuBg() const { return _colors[501]; };
	inline constexpr const color &groupCallMenuBgOver() const { return _colors[502]; };
	inline constexpr const color &groupCallMenuBgRipple() const { return _colors[503]; };
	inline constexpr const color &groupCallLeaveBg() const { return _colors[504]; };
	inline constexpr const color &groupCallLeaveBgRipple() const { return _colors[505]; };
	inline constexpr const color &groupCallVideoTextFg() const { return _colors[506]; };
	inline constexpr const color &groupCallVideoSubTextFg() const { return _colors[507]; };
	inline constexpr const color &callBarBg() const { return _colors[508]; };
	inline constexpr const color &callBarMuteRipple() const { return _colors[509]; };
	inline constexpr const color &callBarBgMuted() const { return _colors[510]; };
	inline constexpr const color &callBarFg() const { return _colors[511]; };
	inline constexpr const color &importantTooltipBg() const { return _colors[512]; };
	inline constexpr const color &importantTooltipFg() const { return _colors[513]; };
	inline constexpr const color &importantTooltipFgLink() const { return _colors[514]; };
	inline constexpr const color &outdatedFg() const { return _colors[515]; };
	inline constexpr const color &outdateSoonBg() const { return _colors[516]; };
	inline constexpr const color &outdatedBg() const { return _colors[517]; };
	inline constexpr const color &spellUnderline() const { return _colors[518]; };
	inline constexpr const color &walletTitleBg() const { return _colors[519]; };
	inline constexpr const color &walletTitleBgActive() const { return _colors[520]; };
	inline constexpr const color &walletTitleButtonBg() const { return _colors[521]; };
	inline constexpr const color &walletTitleButtonFg() const { return _colors[522]; };
	inline constexpr const color &walletTitleButtonBgOver() const { return _colors[523]; };
	inline constexpr const color &walletTitleButtonFgOver() const { return _colors[524]; };
	inline constexpr const color &walletTitleButtonBgActive() const { return _colors[525]; };
	inline constexpr const color &walletTitleButtonFgActive() const { return _colors[526]; };
	inline constexpr const color &walletTitleButtonBgActiveOver() const { return _colors[527]; };
	inline constexpr const color &walletTitleButtonFgActiveOver() const { return _colors[528]; };
	inline constexpr const color &walletTitleButtonCloseBg() const { return _colors[529]; };
	inline constexpr const color &walletTitleButtonCloseFg() const { return _colors[530]; };
	inline constexpr const color &walletTitleButtonCloseBgOver() const { return _colors[531]; };
	inline constexpr const color &walletTitleButtonCloseFgOver() const { return _colors[532]; };
	inline constexpr const color &walletTitleButtonCloseBgActive() const { return _colors[533]; };
	inline constexpr const color &walletTitleButtonCloseFgActive() const { return _colors[534]; };
	inline constexpr const color &walletTitleButtonCloseBgActiveOver() const { return _colors[535]; };
	inline constexpr const color &walletTitleButtonCloseFgActiveOver() const { return _colors[536]; };
	inline constexpr const color &walletTopBg() const { return _colors[537]; };
	inline constexpr const color &walletBalanceFg() const { return _colors[538]; };
	inline constexpr const color &walletSubBalanceFg() const { return _colors[539]; };
	inline constexpr const color &walletTopLabelFg() const { return _colors[540]; };
	inline constexpr const color &walletTopIconFg() const { return _colors[541]; };
	inline constexpr const color &walletTopIconRipple() const { return _colors[542]; };
	inline constexpr const color &sideBarBg() const { return _colors[543]; };
	inline constexpr const color &sideBarBgActive() const { return _colors[544]; };
	inline constexpr const color &sideBarBgRipple() const { return _colors[545]; };
	inline constexpr const color &sideBarTextFg() const { return _colors[546]; };
	inline constexpr const color &sideBarTextFgActive() const { return _colors[547]; };
	inline constexpr const color &sideBarIconFg() const { return _colors[548]; };
	inline constexpr const color &sideBarIconFgActive() const { return _colors[549]; };
	inline constexpr const color &sideBarBadgeBg() const { return _colors[550]; };
	inline constexpr const color &sideBarBadgeBgActive() const { return _colors[551]; };
	inline constexpr const color &sideBarBadgeBgMuted() const { return _colors[552]; };
	inline constexpr const color &sideBarBadgeBgMutedActive() const { return _colors[553]; };
	inline constexpr const color &sideBarBadgeFg() const { return _colors[554]; };
	inline constexpr const color &songCoverOverlayFg() const { return _colors[555]; };
	inline constexpr const color &photoEditorItemBaseHandleFg() const { return _colors[556]; };
	inline constexpr const color &premiumButtonBg1() const { return _colors[557]; };
	inline constexpr const color &premiumButtonBg2() const { return _colors[558]; };
	inline constexpr const color &premiumButtonBg3() const { return _colors[559]; };
	inline constexpr const color &premiumButtonFg() const { return _colors[560]; };
	inline constexpr const color &premiumIconBg1() const { return _colors[561]; };
	inline constexpr const color &premiumIconBg2() const { return _colors[562]; };
	inline constexpr const color &premiumIconBg3() const { return _colors[563]; };
	inline constexpr const color &statisticsChartInactive() const { return _colors[564]; };
	inline constexpr const color &statisticsChartActive() const { return _colors[565]; };
	inline constexpr const color &statisticsChartLineBlue() const { return _colors[566]; };
	inline constexpr const color &statisticsChartLineGreen() const { return _colors[567]; };
	inline constexpr const color &statisticsChartLineRed() const { return _colors[568]; };
	inline constexpr const color &statisticsChartLineGolden() const { return _colors[569]; };
	inline constexpr const color &statisticsChartLineLightblue() const { return _colors[570]; };
	inline constexpr const color &statisticsChartLineLightgreen() const { return _colors[571]; };
	inline constexpr const color &statisticsChartLineOrange() const { return _colors[572]; };
	inline constexpr const color &statisticsChartLineIndigo() const { return _colors[573]; };
	inline constexpr const color &statisticsChartLinePurple() const { return _colors[574]; };
	inline constexpr const color &statisticsChartLineCyan() const { return _colors[575]; };
	inline constexpr const color &creditsBg1() const { return _colors[576]; };
	inline constexpr const color &creditsBg2() const { return _colors[577]; };
	inline constexpr const color &creditsBg3() const { return _colors[578]; };
	inline constexpr const color &creditsFg() const { return _colors[579]; };
	inline constexpr const color &creditsStroke() const { return _colors[580]; };
	inline constexpr const color &currencyFg() const { return _colors[581]; };
	inline constexpr const color &rankAdminFg() const { return _colors[582]; };
	inline constexpr const color &rankOwnerFg() const { return _colors[583]; };
	inline constexpr const color &rankUserFg() const { return _colors[584]; };
	inline constexpr const color &dialogsMentionIconFg() const { return _colors[585]; };
	inline constexpr const color &dialogsReactionIconFg() const { return _colors[586]; };
	inline constexpr const color &dialogsPollIconFg() const { return _colors[587]; };

protected:
	void finalize(palette &that);

	internal::ColorData *data(int index) {
		return reinterpret_cast<internal::ColorData*>(_data) + index;
	}

	const internal::ColorData *data(int index) const {
		return reinterpret_cast<const internal::ColorData*>(_data) + index;
	}

	enum class Status {
		Initial,
		Created,
		Loaded,
	};

	alignas(alignof(internal::ColorData)) char _data[sizeof(internal::ColorData) * kCount];

	color _colors[kCount] = {
		data(0),
		data(1),
		data(2),
		data(3),
		data(4),
		data(5),
		data(6),
		data(7),
		data(8),
		data(9),
		data(10),
		data(11),
		data(12),
		data(13),
		data(14),
		data(15),
		data(16),
		data(17),
		data(18),
		data(19),
		data(20),
		data(21),
		data(22),
		data(23),
		data(24),
		data(25),
		data(26),
		data(27),
		data(28),
		data(29),
		data(30),
		data(31),
		data(32),
		data(33),
		data(34),
		data(35),
		data(36),
		data(37),
		data(38),
		data(39),
		data(40),
		data(41),
		data(42),
		data(43),
		data(44),
		data(45),
		data(46),
		data(47),
		data(48),
		data(49),
		data(50),
		data(51),
		data(52),
		data(53),
		data(54),
		data(55),
		data(56),
		data(57),
		data(58),
		data(59),
		data(60),
		data(61),
		data(62),
		data(63),
		data(64),
		data(65),
		data(66),
		data(67),
		data(68),
		data(69),
		data(70),
		data(71),
		data(72),
		data(73),
		data(74),
		data(75),
		data(76),
		data(77),
		data(78),
		data(79),
		data(80),
		data(81),
		data(82),
		data(83),
		data(84),
		data(85),
		data(86),
		data(87),
		data(88),
		data(89),
		data(90),
		data(91),
		data(92),
		data(93),
		data(94),
		data(95),
		data(96),
		data(97),
		data(98),
		data(99),
		data(100),
		data(101),
		data(102),
		data(103),
		data(104),
		data(105),
		data(106),
		data(107),
		data(108),
		data(109),
		data(110),
		data(111),
		data(112),
		data(113),
		data(114),
		data(115),
		data(116),
		data(117),
		data(118),
		data(119),
		data(120),
		data(121),
		data(122),
		data(123),
		data(124),
		data(125),
		data(126),
		data(127),
		data(128),
		data(129),
		data(130),
		data(131),
		data(132),
		data(133),
		data(134),
		data(135),
		data(136),
		data(137),
		data(138),
		data(139),
		data(140),
		data(141),
		data(142),
		data(143),
		data(144),
		data(145),
		data(146),
		data(147),
		data(148),
		data(149),
		data(150),
		data(151),
		data(152),
		data(153),
		data(154),
		data(155),
		data(156),
		data(157),
		data(158),
		data(159),
		data(160),
		data(161),
		data(162),
		data(163),
		data(164),
		data(165),
		data(166),
		data(167),
		data(168),
		data(169),
		data(170),
		data(171),
		data(172),
		data(173),
		data(174),
		data(175),
		data(176),
		data(177),
		data(178),
		data(179),
		data(180),
		data(181),
		data(182),
		data(183),
		data(184),
		data(185),
		data(186),
		data(187),
		data(188),
		data(189),
		data(190),
		data(191),
		data(192),
		data(193),
		data(194),
		data(195),
		data(196),
		data(197),
		data(198),
		data(199),
		data(200),
		data(201),
		data(202),
		data(203),
		data(204),
		data(205),
		data(206),
		data(207),
		data(208),
		data(209),
		data(210),
		data(211),
		data(212),
		data(213),
		data(214),
		data(215),
		data(216),
		data(217),
		data(218),
		data(219),
		data(220),
		data(221),
		data(222),
		data(223),
		data(224),
		data(225),
		data(226),
		data(227),
		data(228),
		data(229),
		data(230),
		data(231),
		data(232),
		data(233),
		data(234),
		data(235),
		data(236),
		data(237),
		data(238),
		data(239),
		data(240),
		data(241),
		data(242),
		data(243),
		data(244),
		data(245),
		data(246),
		data(247),
		data(248),
		data(249),
		data(250),
		data(251),
		data(252),
		data(253),
		data(254),
		data(255),
		data(256),
		data(257),
		data(258),
		data(259),
		data(260),
		data(261),
		data(262),
		data(263),
		data(264),
		data(265),
		data(266),
		data(267),
		data(268),
		data(269),
		data(270),
		data(271),
		data(272),
		data(273),
		data(274),
		data(275),
		data(276),
		data(277),
		data(278),
		data(279),
		data(280),
		data(281),
		data(282),
		data(283),
		data(284),
		data(285),
		data(286),
		data(287),
		data(288),
		data(289),
		data(290),
		data(291),
		data(292),
		data(293),
		data(294),
		data(295),
		data(296),
		data(297),
		data(298),
		data(299),
		data(300),
		data(301),
		data(302),
		data(303),
		data(304),
		data(305),
		data(306),
		data(307),
		data(308),
		data(309),
		data(310),
		data(311),
		data(312),
		data(313),
		data(314),
		data(315),
		data(316),
		data(317),
		data(318),
		data(319),
		data(320),
		data(321),
		data(322),
		data(323),
		data(324),
		data(325),
		data(326),
		data(327),
		data(328),
		data(329),
		data(330),
		data(331),
		data(332),
		data(333),
		data(334),
		data(335),
		data(336),
		data(337),
		data(338),
		data(339),
		data(340),
		data(341),
		data(342),
		data(343),
		data(344),
		data(345),
		data(346),
		data(347),
		data(348),
		data(349),
		data(350),
		data(351),
		data(352),
		data(353),
		data(354),
		data(355),
		data(356),
		data(357),
		data(358),
		data(359),
		data(360),
		data(361),
		data(362),
		data(363),
		data(364),
		data(365),
		data(366),
		data(367),
		data(368),
		data(369),
		data(370),
		data(371),
		data(372),
		data(373),
		data(374),
		data(375),
		data(376),
		data(377),
		data(378),
		data(379),
		data(380),
		data(381),
		data(382),
		data(383),
		data(384),
		data(385),
		data(386),
		data(387),
		data(388),
		data(389),
		data(390),
		data(391),
		data(392),
		data(393),
		data(394),
		data(395),
		data(396),
		data(397),
		data(398),
		data(399),
		data(400),
		data(401),
		data(402),
		data(403),
		data(404),
		data(405),
		data(406),
		data(407),
		data(408),
		data(409),
		data(410),
		data(411),
		data(412),
		data(413),
		data(414),
		data(415),
		data(416),
		data(417),
		data(418),
		data(419),
		data(420),
		data(421),
		data(422),
		data(423),
		data(424),
		data(425),
		data(426),
		data(427),
		data(428),
		data(429),
		data(430),
		data(431),
		data(432),
		data(433),
		data(434),
		data(435),
		data(436),
		data(437),
		data(438),
		data(439),
		data(440),
		data(441),
		data(442),
		data(443),
		data(444),
		data(445),
		data(446),
		data(447),
		data(448),
		data(449),
		data(450),
		data(451),
		data(452),
		data(453),
		data(454),
		data(455),
		data(456),
		data(457),
		data(458),
		data(459),
		data(460),
		data(461),
		data(462),
		data(463),
		data(464),
		data(465),
		data(466),
		data(467),
		data(468),
		data(469),
		data(470),
		data(471),
		data(472),
		data(473),
		data(474),
		data(475),
		data(476),
		data(477),
		data(478),
		data(479),
		data(480),
		data(481),
		data(482),
		data(483),
		data(484),
		data(485),
		data(486),
		data(487),
		data(488),
		data(489),
		data(490),
		data(491),
		data(492),
		data(493),
		data(494),
		data(495),
		data(496),
		data(497),
		data(498),
		data(499),
		data(500),
		data(501),
		data(502),
		data(503),
		data(504),
		data(505),
		data(506),
		data(507),
		data(508),
		data(509),
		data(510),
		data(511),
		data(512),
		data(513),
		data(514),
		data(515),
		data(516),
		data(517),
		data(518),
		data(519),
		data(520),
		data(521),
		data(522),
		data(523),
		data(524),
		data(525),
		data(526),
		data(527),
		data(528),
		data(529),
		data(530),
		data(531),
		data(532),
		data(533),
		data(534),
		data(535),
		data(536),
		data(537),
		data(538),
		data(539),
		data(540),
		data(541),
		data(542),
		data(543),
		data(544),
		data(545),
		data(546),
		data(547),
		data(548),
		data(549),
		data(550),
		data(551),
		data(552),
		data(553),
		data(554),
		data(555),
		data(556),
		data(557),
		data(558),
		data(559),
		data(560),
		data(561),
		data(562),
		data(563),
		data(564),
		data(565),
		data(566),
		data(567),
		data(568),
		data(569),
		data(570),
		data(571),
		data(572),
		data(573),
		data(574),
		data(575),
		data(576),
		data(577),
		data(578),
		data(579),
		data(580),
		data(581),
		data(582),
		data(583),
		data(584),
		data(585),
		data(586),
		data(587),
	};
	Status _status[kCount] = { Status::Initial };
	bool _ready = false;

};

namespace main_palette {

not_null<const palette*> get();

struct row {
	QLatin1String name;
	QLatin1String value;
	QLatin1String fallback;
	QLatin1String description;
};
QList<row> data();

} // namespace main_palette

namespace internal {

int GetPaletteIndex(QLatin1String name);

} // namespace internal
} // namespace style

namespace st {
extern const style::color &transparent; // special color
extern const style::color &white; // special color
extern const style::color &windowBg;
extern const style::color &windowFg;
extern const style::color &windowBgOver;
extern const style::color &windowBgRipple;
extern const style::color &windowFgOver;
extern const style::color &windowSubTextFg;
extern const style::color &windowSubTextFgOver;
extern const style::color &windowBoldFg;
extern const style::color &windowBoldFgOver;
extern const style::color &windowBgActive;
extern const style::color &windowFgActive;
extern const style::color &windowActiveTextFg;
extern const style::color &windowShadowFg;
extern const style::color &windowShadowFgFallback;
extern const style::color &shadowFg;
extern const style::color &slideFadeOutBg;
extern const style::color &slideFadeOutShadowFg;
extern const style::color &imageBg;
extern const style::color &imageBgTransparent;
extern const style::color &activeButtonBg;
extern const style::color &activeButtonBgOver;
extern const style::color &activeButtonBgRipple;
extern const style::color &activeButtonFg;
extern const style::color &activeButtonFgOver;
extern const style::color &activeButtonSecondaryFg;
extern const style::color &activeButtonSecondaryFgOver;
extern const style::color &activeLineFg;
extern const style::color &activeLineFgError;
extern const style::color &lightButtonBg;
extern const style::color &lightButtonBgOver;
extern const style::color &lightButtonBgRipple;
extern const style::color &lightButtonFg;
extern const style::color &lightButtonFgOver;
extern const style::color &attentionButtonFg;
extern const style::color &attentionButtonFgOver;
extern const style::color &attentionButtonBgOver;
extern const style::color &attentionButtonBgRipple;
extern const style::color &menuBg;
extern const style::color &menuBgOver;
extern const style::color &menuBgRipple;
extern const style::color &menuIconFg;
extern const style::color &menuIconFgOver;
extern const style::color &menuSubmenuArrowFg;
extern const style::color &menuFgDisabled;
extern const style::color &menuSeparatorFg;
extern const style::color &scrollBarBg;
extern const style::color &scrollBarBgOver;
extern const style::color &scrollBg;
extern const style::color &scrollBgOver;
extern const style::color &smallCloseIconFg;
extern const style::color &smallCloseIconFgOver;
extern const style::color &radialFg;
extern const style::color &radialBg;
extern const style::color &placeholderFg;
extern const style::color &placeholderFgActive;
extern const style::color &inputBorderFg;
extern const style::color &filterInputBorderFg;
extern const style::color &filterInputActiveBg;
extern const style::color &filterInputInactiveBg;
extern const style::color &checkboxFg;
extern const style::color &botKbBg;
extern const style::color &botKbDownBg;
extern const style::color &botKbColor;
extern const style::color &botKbPrimaryBg;
extern const style::color &botKbDangerBg;
extern const style::color &botKbSuccessBg;
extern const style::color &botKbInlinePrimaryBg;
extern const style::color &botKbInlineDangerBg;
extern const style::color &botKbInlineSuccessBg;
extern const style::color &sliderBgInactive;
extern const style::color &sliderBgActive;
extern const style::color &tooltipBg;
extern const style::color &tooltipFg;
extern const style::color &tooltipBorderFg;
extern const style::color &titleShadow;
extern const style::color &titleBg;
extern const style::color &titleBgActive;
extern const style::color &titleButtonBg;
extern const style::color &titleButtonFg;
extern const style::color &titleButtonBgOver;
extern const style::color &titleButtonFgOver;
extern const style::color &titleButtonBgActive;
extern const style::color &titleButtonFgActive;
extern const style::color &titleButtonBgActiveOver;
extern const style::color &titleButtonFgActiveOver;
extern const style::color &titleButtonCloseBg;
extern const style::color &titleButtonCloseFg;
extern const style::color &titleButtonCloseBgOver;
extern const style::color &titleButtonCloseFgOver;
extern const style::color &titleButtonCloseBgActive;
extern const style::color &titleButtonCloseFgActive;
extern const style::color &titleButtonCloseBgActiveOver;
extern const style::color &titleButtonCloseFgActiveOver;
extern const style::color &titleFg;
extern const style::color &titleFgActive;
extern const style::color &trayCounterBg;
extern const style::color &trayCounterBgMute;
extern const style::color &trayCounterFg;
extern const style::color &trayCounterBgMacInvert;
extern const style::color &trayCounterFgMacInvert;
extern const style::color &layerBg;
extern const style::color &cancelIconFg;
extern const style::color &cancelIconFgOver;
extern const style::color &boxBg;
extern const style::color &boxTextFg;
extern const style::color &boxTextFgGood;
extern const style::color &boxTextFgError;
extern const style::color &boxTitleFg;
extern const style::color &boxSearchBg;
extern const style::color &boxTitleAdditionalFg;
extern const style::color &boxTitleCloseFg;
extern const style::color &boxTitleCloseFgOver;
extern const style::color &boxDividerBg;
extern const style::color &boxDividerFg;
extern const style::color &paymentsTipActive;
extern const style::color &membersAboutLimitFg;
extern const style::color &contactsBg;
extern const style::color &contactsBgOver;
extern const style::color &contactsNameFg;
extern const style::color &contactsStatusFg;
extern const style::color &contactsStatusFgOver;
extern const style::color &contactsStatusFgOnline;
extern const style::color &photoCropFadeBg;
extern const style::color &photoCropPointFg;
extern const style::color &callArrowFg;
extern const style::color &callArrowMissedFg;
extern const style::color &introBg;
extern const style::color &introTitleFg;
extern const style::color &introDescriptionFg;
extern const style::color &introCoverTopBg;
extern const style::color &introCoverBottomBg;
extern const style::color &introCoverIconsFg;
extern const style::color &introCoverPlaneTrace;
extern const style::color &introCoverPlaneInner;
extern const style::color &introCoverPlaneOuter;
extern const style::color &introCoverPlaneTop;
extern const style::color &dialogsMenuIconFg;
extern const style::color &dialogsMenuIconFgOver;
extern const style::color &dialogsBg;
extern const style::color &dialogsNameFg;
extern const style::color &dialogsChatIconFg;
extern const style::color &dialogsDateFg;
extern const style::color &dialogsTextFg;
extern const style::color &dialogsTextFgService;
extern const style::color &dialogsDraftFg;
extern const style::color &dialogsVerifiedIconBg;
extern const style::color &dialogsVerifiedIconFg;
extern const style::color &dialogsSendingIconFg;
extern const style::color &dialogsSentIconFg;
extern const style::color &dialogsUnreadBg;
extern const style::color &dialogsUnreadBgMuted;
extern const style::color &dialogsUnreadFg;
extern const style::color &dialogsArchiveFg;
extern const style::color &dialogsOnlineBadgeFg;
extern const style::color &dialogsScamFg;
extern const style::color &dialogsBgOver;
extern const style::color &dialogsNameFgOver;
extern const style::color &dialogsChatIconFgOver;
extern const style::color &dialogsDateFgOver;
extern const style::color &dialogsTextFgOver;
extern const style::color &dialogsTextFgServiceOver;
extern const style::color &dialogsDraftFgOver;
extern const style::color &dialogsVerifiedIconBgOver;
extern const style::color &dialogsVerifiedIconFgOver;
extern const style::color &dialogsSendingIconFgOver;
extern const style::color &dialogsSentIconFgOver;
extern const style::color &dialogsUnreadBgOver;
extern const style::color &dialogsUnreadBgMutedOver;
extern const style::color &dialogsUnreadFgOver;
extern const style::color &dialogsArchiveFgOver;
extern const style::color &dialogsScamFgOver;
extern const style::color &dialogsBgActive;
extern const style::color &dialogsNameFgActive;
extern const style::color &dialogsChatIconFgActive;
extern const style::color &dialogsDateFgActive;
extern const style::color &dialogsTextFgActive;
extern const style::color &dialogsTextFgServiceActive;
extern const style::color &dialogsDraftFgActive;
extern const style::color &dialogsVerifiedIconBgActive;
extern const style::color &dialogsVerifiedIconFgActive;
extern const style::color &dialogsSendingIconFgActive;
extern const style::color &dialogsSentIconFgActive;
extern const style::color &dialogsUnreadBgActive;
extern const style::color &dialogsUnreadBgMutedActive;
extern const style::color &dialogsUnreadFgActive;
extern const style::color &dialogsOnlineBadgeFgActive;
extern const style::color &dialogsScamFgActive;
extern const style::color &dialogsRippleBg;
extern const style::color &dialogsRippleBgActive;
extern const style::color &searchedBarBg;
extern const style::color &searchedBarFg;
extern const style::color &searchedTextMatchBg;
extern const style::color &searchedTextMatchFg;
extern const style::color &searchedTextCurrentMatchBg;
extern const style::color &searchedTextCurrentMatchFg;
extern const style::color &topBarBg;
extern const style::color &emojiPanBg;
extern const style::color &emojiPanCategories;
extern const style::color &emojiPanHeaderFg;
extern const style::color &emojiPanHeaderBg;
extern const style::color &emojiIconFg;
extern const style::color &emojiSubIconFgActive;
extern const style::color &stickerPanDeleteBg;
extern const style::color &stickerPanDeleteFg;
extern const style::color &stickerPreviewBg;
extern const style::color &stickerPanPremium1;
extern const style::color &stickerPanPremium2;
extern const style::color &historyTextInFg;
extern const style::color &historyTextInFgSelected;
extern const style::color &historyTextOutFg;
extern const style::color &historyTextOutFgSelected;
extern const style::color &historyLinkInFg;
extern const style::color &historyLinkInFgSelected;
extern const style::color &historyLinkOutFg;
extern const style::color &historyLinkOutFgSelected;
extern const style::color &historyFileNameInFg;
extern const style::color &historyFileNameInFgSelected;
extern const style::color &historyFileNameOutFg;
extern const style::color &historyFileNameOutFgSelected;
extern const style::color &historyOutIconFg;
extern const style::color &historyOutIconFgSelected;
extern const style::color &historyIconFgInverted;
extern const style::color &historySendingOutIconFg;
extern const style::color &historySendingInIconFg;
extern const style::color &historySendingInvertedIconFg;
extern const style::color &historyCallArrowInFg;
extern const style::color &historyCallArrowInFgSelected;
extern const style::color &historyCallArrowMissedInFg;
extern const style::color &historyCallArrowMissedInFgSelected;
extern const style::color &historyCallArrowOutFg;
extern const style::color &historyCallArrowOutFgSelected;
extern const style::color &historyUnreadBarBg;
extern const style::color &historyUnreadBarBorder;
extern const style::color &historyUnreadBarFg;
extern const style::color &historyForwardChooseBg;
extern const style::color &historyForwardChooseFg;
extern const style::color &historyPeer1NameFg;
extern const style::color &historyPeer1NameFgSelected;
extern const style::color &historyPeer1UserpicBg;
extern const style::color &historyPeer2NameFg;
extern const style::color &historyPeer2NameFgSelected;
extern const style::color &historyPeer2UserpicBg;
extern const style::color &historyPeer3NameFg;
extern const style::color &historyPeer3NameFgSelected;
extern const style::color &historyPeer3UserpicBg;
extern const style::color &historyPeer4NameFg;
extern const style::color &historyPeer4NameFgSelected;
extern const style::color &historyPeer4UserpicBg;
extern const style::color &historyPeer5NameFg;
extern const style::color &historyPeer5NameFgSelected;
extern const style::color &historyPeer5UserpicBg;
extern const style::color &historyPeer6NameFg;
extern const style::color &historyPeer6NameFgSelected;
extern const style::color &historyPeer6UserpicBg;
extern const style::color &historyPeer7NameFg;
extern const style::color &historyPeer7NameFgSelected;
extern const style::color &historyPeer7UserpicBg;
extern const style::color &historyPeer8NameFg;
extern const style::color &historyPeer8NameFgSelected;
extern const style::color &historyPeer8UserpicBg;
extern const style::color &historyPeerUserpicFg;
extern const style::color &historyPeerSavedMessagesBg;
extern const style::color &historyPeerArchiveUserpicBg;
extern const style::color &historyPeer1UserpicBg2;
extern const style::color &historyPeer2UserpicBg2;
extern const style::color &historyPeer3UserpicBg2;
extern const style::color &historyPeer4UserpicBg2;
extern const style::color &historyPeer5UserpicBg2;
extern const style::color &historyPeer6UserpicBg2;
extern const style::color &historyPeer7UserpicBg2;
extern const style::color &historyPeer8UserpicBg2;
extern const style::color &historyPeerSavedMessagesBg2;
extern const style::color &settingsIconBg1;
extern const style::color &settingsIconBg2;
extern const style::color &settingsIconBg3;
extern const style::color &settingsIconBg4;
extern const style::color &settingsIconBg5;
extern const style::color &settingsIconBg6;
extern const style::color &settingsIconBg8;
extern const style::color &settingsIconBgArchive;
extern const style::color &settingsIconFg;
extern const style::color &historyScrollBarBg;
extern const style::color &historyScrollBarBgOver;
extern const style::color &historyScrollBg;
extern const style::color &historyScrollBgOver;
extern const style::color &msgInBg;
extern const style::color &msgInBgSelected;
extern const style::color &msgOutBg;
extern const style::color &msgOutBgSelected;
extern const style::color &msgSelectOverlay;
extern const style::color &msgStickerOverlay;
extern const style::color &msgInServiceFg;
extern const style::color &msgInServiceFgSelected;
extern const style::color &msgOutServiceFg;
extern const style::color &msgOutServiceFgSelected;
extern const style::color &msgInShadow;
extern const style::color &msgInShadowSelected;
extern const style::color &msgOutShadow;
extern const style::color &msgOutShadowSelected;
extern const style::color &msgInDateFg;
extern const style::color &msgInDateFgSelected;
extern const style::color &msgOutDateFg;
extern const style::color &msgOutDateFgSelected;
extern const style::color &msgServiceFg;
extern const style::color &msgServiceBg;
extern const style::color &msgServiceBgSelected;
extern const style::color &msgInReplyBarColor;
extern const style::color &msgInReplyBarSelColor;
extern const style::color &msgOutReplyBarColor;
extern const style::color &msgOutReplyBarSelColor;
extern const style::color &msgImgReplyBarColor;
extern const style::color &msgInMonoFg;
extern const style::color &msgOutMonoFg;
extern const style::color &msgInMonoFgSelected;
extern const style::color &msgOutMonoFgSelected;
extern const style::color &msgDateImgFg;
extern const style::color &msgDateImgBg;
extern const style::color &msgDateImgBgOver;
extern const style::color &msgDateImgBgSelected;
extern const style::color &msgFileThumbLinkInFg;
extern const style::color &msgFileThumbLinkInFgSelected;
extern const style::color &msgFileThumbLinkOutFg;
extern const style::color &msgFileThumbLinkOutFgSelected;
extern const style::color &msgFileInBg;
extern const style::color &msgFileInBgOver;
extern const style::color &msgFileInBgSelected;
extern const style::color &msgFileOutBg;
extern const style::color &msgFileOutBgSelected;
extern const style::color &msgFile1Bg;
extern const style::color &msgFile1BgDark;
extern const style::color &msgFile1BgOver;
extern const style::color &msgFile1BgSelected;
extern const style::color &msgFile2Bg;
extern const style::color &msgFile2BgDark;
extern const style::color &msgFile2BgOver;
extern const style::color &msgFile2BgSelected;
extern const style::color &msgFile3Bg;
extern const style::color &msgFile3BgDark;
extern const style::color &msgFile3BgOver;
extern const style::color &msgFile3BgSelected;
extern const style::color &msgFile4Bg;
extern const style::color &msgFile4BgDark;
extern const style::color &msgFile4BgOver;
extern const style::color &msgFile4BgSelected;
extern const style::color &historyFileInIconFg;
extern const style::color &historyFileInIconFgSelected;
extern const style::color &historyFileInRadialFg;
extern const style::color &historyFileInRadialFgSelected;
extern const style::color &historyFileOutIconFg;
extern const style::color &historyFileOutIconFgSelected;
extern const style::color &historyFileOutRadialFg;
extern const style::color &historyFileOutRadialFgSelected;
extern const style::color &historyFileThumbIconFg;
extern const style::color &historyFileThumbIconFgSelected;
extern const style::color &historyFileThumbRadialFg;
extern const style::color &historyFileThumbRadialFgSelected;
extern const style::color &historyVideoMessageProgressFg;
extern const style::color &msgWaveformInActive;
extern const style::color &msgWaveformInActiveSelected;
extern const style::color &msgWaveformInInactive;
extern const style::color &msgWaveformInInactiveSelected;
extern const style::color &msgWaveformOutActive;
extern const style::color &msgWaveformOutActiveSelected;
extern const style::color &msgWaveformOutInactive;
extern const style::color &msgWaveformOutInactiveSelected;
extern const style::color &msgBotKbOverBgAdd;
extern const style::color &msgBotKbIconFg;
extern const style::color &msgBotKbRippleBg;
extern const style::color &mediaInFg;
extern const style::color &mediaInFgSelected;
extern const style::color &mediaOutFg;
extern const style::color &mediaOutFgSelected;
extern const style::color &youtubePlayIconBg;
extern const style::color &youtubePlayIconFg;
extern const style::color &videoPlayIconBg;
extern const style::color &videoPlayIconFg;
extern const style::color &toastBg;
extern const style::color &toastFg;
extern const style::color &historyToDownBg;
extern const style::color &historyToDownBgOver;
extern const style::color &historyToDownBgRipple;
extern const style::color &historyToDownFg;
extern const style::color &historyToDownFgOver;
extern const style::color &historyToDownShadow;
extern const style::color &historyComposeAreaBg;
extern const style::color &historyComposeAreaFg;
extern const style::color &historyComposeAreaFgService;
extern const style::color &historyComposeIconFg;
extern const style::color &historyComposeIconFgOver;
extern const style::color &historySendIconFg;
extern const style::color &historySendIconFgOver;
extern const style::color &historyPinnedBg;
extern const style::color &historyReplyBg;
extern const style::color &historyReplyIconFg;
extern const style::color &historyReplyCancelFg;
extern const style::color &historyReplyCancelFgOver;
extern const style::color &historyComposeButtonBg;
extern const style::color &historyComposeButtonBgOver;
extern const style::color &historyComposeButtonBgRipple;
extern const style::color &mapPointDrop;
extern const style::color &mapPointDot;
extern const style::color &overviewCheckBg;
extern const style::color &overviewCheckBgActive;
extern const style::color &overviewCheckBorder;
extern const style::color &overviewCheckFgActive;
extern const style::color &overviewPhotoSelectOverlay;
extern const style::color &profileStatusFgOver;
extern const style::color &profileVerifiedCheckBg;
extern const style::color &profileVerifiedCheckFg;
extern const style::color &profileAdminStartFg;
extern const style::color &notificationsBoxMonitorFg;
extern const style::color &notificationsBoxScreenBg;
extern const style::color &notificationSampleUserpicFg;
extern const style::color &notificationSampleCloseFg;
extern const style::color &notificationSampleTextFg;
extern const style::color &notificationSampleNameFg;
extern const style::color &mainMenuBg;
extern const style::color &mainMenuCoverBg;
extern const style::color &mainMenuCloudFg;
extern const style::color &mainMenuCloudBg;
extern const style::color &mediaPlayerBg;
extern const style::color &mediaPlayerActiveFg;
extern const style::color &mediaPlayerInactiveFg;
extern const style::color &mediaPlayerDisabledFg;
extern const style::color &mediaviewFileBg;
extern const style::color &mediaviewFileNameFg;
extern const style::color &mediaviewFileSizeFg;
extern const style::color &mediaviewFileRedCornerFg;
extern const style::color &mediaviewFileYellowCornerFg;
extern const style::color &mediaviewFileGreenCornerFg;
extern const style::color &mediaviewFileBlueCornerFg;
extern const style::color &mediaviewFileExtFg;
extern const style::color &mediaviewMenuBg;
extern const style::color &mediaviewMenuBgOver;
extern const style::color &mediaviewMenuBgRipple;
extern const style::color &mediaviewMenuFg;
extern const style::color &mediaviewBg;
extern const style::color &mediaviewVideoBg;
extern const style::color &mediaviewControlBg;
extern const style::color &mediaviewControlFg;
extern const style::color &mediaviewCaptionBg;
extern const style::color &mediaviewCaptionFg;
extern const style::color &mediaviewTextLinkFg;
extern const style::color &mediaviewSaveMsgBg;
extern const style::color &mediaviewSaveMsgFg;
extern const style::color &mediaviewPlaybackActive;
extern const style::color &mediaviewPlaybackInactive;
extern const style::color &mediaviewPlaybackActiveOver;
extern const style::color &mediaviewPlaybackInactiveOver;
extern const style::color &mediaviewPlaybackProgressFg;
extern const style::color &mediaviewPlaybackIconFg;
extern const style::color &mediaviewPlaybackIconFgOver;
extern const style::color &mediaviewPlaybackIconRipple;
extern const style::color &mediaviewPipControlsFg;
extern const style::color &mediaviewPipControlsFgOver;
extern const style::color &mediaviewPipPlaybackActive;
extern const style::color &mediaviewPipPlaybackInactive;
extern const style::color &mediaviewTransparentBg;
extern const style::color &mediaviewTransparentFg;
extern const style::color &notificationBg;
extern const style::color &callBg;
extern const style::color &callBgOpaque;
extern const style::color &callBgButton;
extern const style::color &callNameFg;
extern const style::color &callStatusFg;
extern const style::color &callIconBg;
extern const style::color &callIconFg;
extern const style::color &callIconBgActive;
extern const style::color &callIconFgActive;
extern const style::color &callIconActiveRipple;
extern const style::color &callAnswerBg;
extern const style::color &callAnswerRipple;
extern const style::color &callAnswerBgOuter;
extern const style::color &callHangupBg;
extern const style::color &callHangupRipple;
extern const style::color &callMuteRipple;
extern const style::color &groupCallBg;
extern const style::color &groupCallActiveFg;
extern const style::color &groupCallMembersBg;
extern const style::color &groupCallMembersBgOver;
extern const style::color &groupCallMembersBgRipple;
extern const style::color &groupCallMembersFg;
extern const style::color &groupCallMemberActiveIcon;
extern const style::color &groupCallMemberActiveStatus;
extern const style::color &groupCallMemberInactiveIcon;
extern const style::color &groupCallMemberInactiveStatus;
extern const style::color &groupCallMemberMutedIcon;
extern const style::color &groupCallMemberNotJoinedStatus;
extern const style::color &groupCallIconFg;
extern const style::color &groupCallLive1;
extern const style::color &groupCallLive2;
extern const style::color &groupCallMuted1;
extern const style::color &groupCallMuted2;
extern const style::color &groupCallForceMutedBar1;
extern const style::color &groupCallForceMutedBar2;
extern const style::color &groupCallForceMutedBar3;
extern const style::color &groupCallForceMuted1;
extern const style::color &groupCallForceMuted2;
extern const style::color &groupCallForceMuted3;
extern const style::color &groupCallMenuBg;
extern const style::color &groupCallMenuBgOver;
extern const style::color &groupCallMenuBgRipple;
extern const style::color &groupCallLeaveBg;
extern const style::color &groupCallLeaveBgRipple;
extern const style::color &groupCallVideoTextFg;
extern const style::color &groupCallVideoSubTextFg;
extern const style::color &callBarBg;
extern const style::color &callBarMuteRipple;
extern const style::color &callBarBgMuted;
extern const style::color &callBarFg;
extern const style::color &importantTooltipBg;
extern const style::color &importantTooltipFg;
extern const style::color &importantTooltipFgLink;
extern const style::color &outdatedFg;
extern const style::color &outdateSoonBg;
extern const style::color &outdatedBg;
extern const style::color &spellUnderline;
extern const style::color &walletTitleBg;
extern const style::color &walletTitleBgActive;
extern const style::color &walletTitleButtonBg;
extern const style::color &walletTitleButtonFg;
extern const style::color &walletTitleButtonBgOver;
extern const style::color &walletTitleButtonFgOver;
extern const style::color &walletTitleButtonBgActive;
extern const style::color &walletTitleButtonFgActive;
extern const style::color &walletTitleButtonBgActiveOver;
extern const style::color &walletTitleButtonFgActiveOver;
extern const style::color &walletTitleButtonCloseBg;
extern const style::color &walletTitleButtonCloseFg;
extern const style::color &walletTitleButtonCloseBgOver;
extern const style::color &walletTitleButtonCloseFgOver;
extern const style::color &walletTitleButtonCloseBgActive;
extern const style::color &walletTitleButtonCloseFgActive;
extern const style::color &walletTitleButtonCloseBgActiveOver;
extern const style::color &walletTitleButtonCloseFgActiveOver;
extern const style::color &walletTopBg;
extern const style::color &walletBalanceFg;
extern const style::color &walletSubBalanceFg;
extern const style::color &walletTopLabelFg;
extern const style::color &walletTopIconFg;
extern const style::color &walletTopIconRipple;
extern const style::color &sideBarBg;
extern const style::color &sideBarBgActive;
extern const style::color &sideBarBgRipple;
extern const style::color &sideBarTextFg;
extern const style::color &sideBarTextFgActive;
extern const style::color &sideBarIconFg;
extern const style::color &sideBarIconFgActive;
extern const style::color &sideBarBadgeBg;
extern const style::color &sideBarBadgeBgActive;
extern const style::color &sideBarBadgeBgMuted;
extern const style::color &sideBarBadgeBgMutedActive;
extern const style::color &sideBarBadgeFg;
extern const style::color &songCoverOverlayFg;
extern const style::color &photoEditorItemBaseHandleFg;
extern const style::color &premiumButtonBg1;
extern const style::color &premiumButtonBg2;
extern const style::color &premiumButtonBg3;
extern const style::color &premiumButtonFg;
extern const style::color &premiumIconBg1;
extern const style::color &premiumIconBg2;
extern const style::color &premiumIconBg3;
extern const style::color &statisticsChartInactive;
extern const style::color &statisticsChartActive;
extern const style::color &statisticsChartLineBlue;
extern const style::color &statisticsChartLineGreen;
extern const style::color &statisticsChartLineRed;
extern const style::color &statisticsChartLineGolden;
extern const style::color &statisticsChartLineLightblue;
extern const style::color &statisticsChartLineLightgreen;
extern const style::color &statisticsChartLineOrange;
extern const style::color &statisticsChartLineIndigo;
extern const style::color &statisticsChartLinePurple;
extern const style::color &statisticsChartLineCyan;
extern const style::color &creditsBg1;
extern const style::color &creditsBg2;
extern const style::color &creditsBg3;
extern const style::color &creditsFg;
extern const style::color &creditsStroke;
extern const style::color &currencyFg;
extern const style::color &rankAdminFg;
extern const style::color &rankOwnerFg;
extern const style::color &rankUserFg;
extern const style::color &dialogsMentionIconFg;
extern const style::color &dialogsReactionIconFg;
extern const style::color &dialogsPollIconFg;
} // namespace st
