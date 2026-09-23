cmake_minimum_required(VERSION 3.20)
project(UzOS_TelegramUI LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_definitions(
    -DUNICODE
    -D_UNICODE
    -DCRL_USE_QT
    -DCRL_USE_WINAPI_TIME
    -DCRL_ENABLE_RPL_INTEGRATION
)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Svg)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/generated
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/emoji
    ${CMAKE_CURRENT_SOURCE_DIR}/tdesktop-dev/Telegram/lib_ui
    ${CMAKE_CURRENT_SOURCE_DIR}/tdesktop-dev/Telegram/lib_ui/emoji_suggestions
    ${CMAKE_CURRENT_SOURCE_DIR}/tdesktop-dev/Telegram/lib_base
    ${CMAKE_CURRENT_SOURCE_DIR}/tdesktop-dev/Telegram/lib_rpl
    ${CMAKE_CURRENT_SOURCE_DIR}/tdesktop-dev/Telegram/lib_crl
    ${CMAKE_CURRENT_SOURCE_DIR}/tdesktop-dev/Telegram/ThirdParty/GSL/include
    ${CMAKE_CURRENT_SOURCE_DIR}/tdesktop-dev/Telegram/ThirdParty/expected/include
    ${CMAKE_CURRENT_SOURCE_DIR}/tdesktop-dev/Telegram/ThirdParty/range-v3/include
    C:/Qt/6.8.0/llvm-mingw_64/include/QtZlib
    C:/Qt/6.8.0/llvm-mingw_64/include/QtJpeg
    C:/Qt/6.8.0/llvm-mingw_64/include/QtGui/6.8.0/QtGui
    C:/Qt/6.8.0/llvm-mingw_64/include/QtCore/6.8.0/QtCore
    C:/Qt/6.8.0/llvm-mingw_64/include/QtGui/6.8.0
    C:/Qt/6.8.0/llvm-mingw_64/include/QtCore/6.8.0
    ${CMAKE_CURRENT_SOURCE_DIR}/tdesktop-dev/Telegram/ThirdParty/xxHash
    ${CMAKE_CURRENT_SOURCE_DIR}/tdesktop-dev/Telegram/ThirdParty/lz4/lib
)

set(SOURCES
    src/main.cpp
    src/UiIntegration.cpp
    src/UzWindow.cpp
    src/apps/UzTerminal.cpp
    src/apps/UzFiles.cpp
    src/apps/UzSettings.cpp
    src/UzAppLauncher.cpp
    src/UzTaskbar.cpp
    src/UzDesktopView.cpp
    resources.qrc
    
    # Official Telegram lib_ui widgets
    tdesktop-dev/Telegram/lib_ui/ui/widgets/buttons.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/fields/input_field.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/fields/custom_field_object.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/scroll_area.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/elastic_scroll.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/labels.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/checkbox.cpp
    tdesktop-dev/Telegram/lib_ui/ui/rp_widget.cpp
    tdesktop-dev/Telegram/lib_ui/ui/abstract_button.cpp
    tdesktop-dev/Telegram/lib_ui/ui/round_rect.cpp
    tdesktop-dev/Telegram/lib_ui/ui/ui_utility.cpp
    tdesktop-dev/Telegram/lib_ui/ui/emoji_config.cpp
    
    # Animations & effects
    tdesktop-dev/Telegram/lib_ui/ui/effects/animations.cpp
    tdesktop-dev/Telegram/lib_ui/ui/effects/animation_value.cpp
    tdesktop-dev/Telegram/lib_ui/ui/effects/fade_animation.cpp
    tdesktop-dev/Telegram/lib_ui/ui/effects/slide_animation.cpp
    tdesktop-dev/Telegram/lib_ui/ui/effects/ripple_animation.cpp
    tdesktop-dev/Telegram/lib_ui/ui/effects/cross_animation.cpp
    tdesktop-dev/Telegram/lib_ui/ui/effects/numbers_animation.cpp
    tdesktop-dev/Telegram/lib_ui/ui/effects/radial_animation.cpp
    
    # Text engine
    tdesktop-dev/Telegram/lib_ui/ui/text/text.cpp
    tdesktop-dev/Telegram/lib_ui/ui/text/text_block.cpp
    tdesktop-dev/Telegram/lib_ui/ui/text/text_block_parser.cpp
    tdesktop-dev/Telegram/lib_ui/ui/text/text_entity.cpp
    tdesktop-dev/Telegram/lib_ui/ui/text/text_extended_data.cpp
    tdesktop-dev/Telegram/lib_ui/ui/text/text_html_tags.cpp
    tdesktop-dev/Telegram/lib_ui/ui/text/text_renderer.cpp
    tdesktop-dev/Telegram/lib_ui/ui/text/text_shaper_qt.cpp
    tdesktop-dev/Telegram/lib_ui/ui/text/text_stack_engine.cpp
    tdesktop-dev/Telegram/lib_ui/ui/text/text_utilities.cpp
    tdesktop-dev/Telegram/lib_ui/ui/text/text_word_parser.cpp
    
    # Images & Styles
    tdesktop-dev/Telegram/lib_ui/ui/image/image_prepare.cpp
    tdesktop-dev/Telegram/lib_ui/ui/style/style_core.cpp
    tdesktop-dev/Telegram/lib_ui/ui/style/style_core_color.cpp
    tdesktop-dev/Telegram/lib_ui/ui/style/style_core_font.cpp
    tdesktop-dev/Telegram/lib_ui/ui/style/style_core_icon.cpp
    tdesktop-dev/Telegram/lib_ui/ui/style/style_core_palette.cpp
    tdesktop-dev/Telegram/lib_ui/ui/style/style_core_scale.cpp
    tdesktop-dev/Telegram/lib_ui/ui/style/style_core_types.cpp
    tdesktop-dev/Telegram/lib_ui/ui/integration.cpp
    
    # Platform
    tdesktop-dev/Telegram/lib_ui/ui/platform/win/ui_utility_win.cpp
    
    # lib_base & lib_crl
    tdesktop-dev/Telegram/lib_base/base/platform/win/base_windows_safe_library.cpp
    tdesktop-dev/Telegram/lib_base/base/timer.cpp
    tdesktop-dev/Telegram/lib_base/base/algorithm.cpp
    tdesktop-dev/Telegram/lib_base/base/bytes.cpp
    tdesktop-dev/Telegram/lib_crl/crl/crl_time.cpp
    tdesktop-dev/Telegram/lib_crl/crl/winapi/crl_winapi_list.cpp
    tdesktop-dev/Telegram/lib_crl/crl/winapi/crl_winapi_time.cpp
    tdesktop-dev/Telegram/lib_crl/crl/common/crl_common_on_main.cpp
    tdesktop-dev/Telegram/lib_crl/crl/common/crl_common_list.cpp
    
    # More widgets
    tdesktop-dev/Telegram/lib_ui/ui/widgets/popup_menu.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/box_content_divider.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/tooltip.cpp
    tdesktop-dev/Telegram/lib_ui/ui/inactive_press.cpp
    tdesktop-dev/Telegram/lib_ui/ui/click_handler.cpp
    tdesktop-dev/Telegram/lib_ui/ui/basic_click_handlers.cpp
    tdesktop-dev/Telegram/lib_ui/ui/main_queue_processor.cpp

    # Menu system (required by popup_menu)
    tdesktop-dev/Telegram/lib_ui/ui/widgets/menu/menu.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/menu/menu_action.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/menu/menu_add_action_callback.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/menu/menu_add_action_callback_factory.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/menu/menu_common.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/menu/menu_item_base.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/menu/menu_multiline_action.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/menu/menu_separator.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/menu/menu_toggle.cpp

    # Wrap widgets (PaddingWrap etc.)
    tdesktop-dev/Telegram/lib_ui/ui/wrap/padding_wrap.cpp

    # Accessibility
    tdesktop-dev/Telegram/lib_ui/ui/accessible/ui_accessible_widget.cpp
    tdesktop-dev/Telegram/lib_ui/ui/accessible/ui_accessible_item.cpp
    tdesktop-dev/Telegram/lib_ui/ui/accessible/ui_accessible_factory.cpp
    tdesktop-dev/Telegram/lib_ui/ui/screen_reader_mode.cpp

    # Spoiler / custom emoji effects
    tdesktop-dev/Telegram/lib_ui/ui/effects/spoiler_mess.cpp
    tdesktop-dev/Telegram/lib_ui/ui/text/text_custom_emoji.cpp
    tdesktop-dev/Telegram/lib_ui/ui/text/custom_emoji_instance.cpp

    # Image extras (SVG safety, etc.)
    tdesktop-dev/Telegram/lib_ui/ui/image/svg_safety.cpp

    # lz4 (needed by custom_emoji_instance.cpp)
    tdesktop-dev/Telegram/ThirdParty/lz4/lib/lz4.c

    # lib_base extras
    tdesktop-dev/Telegram/lib_base/base/assertion.cpp
    tdesktop-dev/Telegram/lib_base/base/random.cpp
    tdesktop-dev/Telegram/lib_base/base/integration.cpp
    tdesktop-dev/Telegram/lib_base/base/debug_log.cpp
    tdesktop-dev/Telegram/lib_base/base/parse_helper.cpp
    tdesktop-dev/Telegram/lib_base/base/crc32hash.cpp
    tdesktop-dev/Telegram/lib_base/base/qthelp_url.cpp

    # lib_crl queue + on_main stub
    tdesktop-dev/Telegram/lib_crl/crl/common/crl_common_queue.cpp
    src/crl_on_main_stubs.cpp

    # More widgets (shadows, animation, dropdown, toast)
    tdesktop-dev/Telegram/lib_ui/ui/widgets/shadow.cpp
    tdesktop-dev/Telegram/lib_ui/ui/widgets/dropdown_menu.cpp
    tdesktop-dev/Telegram/lib_ui/ui/effects/panel_animation.cpp
    tdesktop-dev/Telegram/lib_ui/ui/delayed_activation.cpp
    tdesktop-dev/Telegram/lib_ui/ui/ui_touch_forward.cpp
    tdesktop-dev/Telegram/lib_ui/ui/toast/toast.cpp
    tdesktop-dev/Telegram/lib_ui/ui/toast/toast_manager.cpp
    tdesktop-dev/Telegram/lib_ui/ui/toast/toast_widget.cpp

    # Style colorizer
    tdesktop-dev/Telegram/lib_ui/ui/style/style_palette_colorizer.cpp

    # lib_base time/timer extras
    tdesktop-dev/Telegram/lib_base/base/concurrent_timer.cpp
    tdesktop-dev/Telegram/lib_base/base/unixtime.cpp
    tdesktop-dev/Telegram/lib_base/base/call_delayed.cpp
    tdesktop-dev/Telegram/lib_base/base/screen_reader_state.cpp
    tdesktop-dev/Telegram/lib_base/base/platform/win/base_file_utilities_win.cpp

    # More dropdown widget
    tdesktop-dev/Telegram/lib_ui/ui/widgets/inner_dropdown.cpp

    # Style direction
    tdesktop-dev/Telegram/lib_ui/ui/style/style_core_direction.cpp

    # xxHash (needed by spoiler_mess.cpp)
    tdesktop-dev/Telegram/ThirdParty/lz4/lib/xxhash.c

    # Emoji suggestions (needed by emoji_suggestions_data.cpp)
    tdesktop-dev/Telegram/lib_ui/emoji_suggestions/emoji_suggestions.cpp

    # Win screen reader state
    tdesktop-dev/Telegram/lib_base/base/platform/win/base_screen_reader_state_win.cpp

    # Generated styles and emoji
    generated/styles/palette.cpp
    generated/styles/style_basic.cpp
    generated/styles/style_widgets.cpp
    generated/styles/style_layers.cpp
    generated/emoji/emoji.cpp
    generated/emoji/emoji_suggestions_data.cpp
    generated/qrc_fonts.cpp
    generated/qrc_win.cpp
)

add_executable(UzOS_TelegramUI ${SOURCES})

# Exclude plain C sources from the C++ PCH forced include
set_source_files_properties(
    tdesktop-dev/Telegram/ThirdParty/lz4/lib/lz4.c
    tdesktop-dev/Telegram/ThirdParty/lz4/lib/xxhash.c
    PROPERTIES COMPILE_OPTIONS ""
               COMPILE_FLAGS "-std=c11 -w"
               SKIP_PRECOMPILE_HEADERS ON
)

target_compile_options(UzOS_TelegramUI PRIVATE
    $<$<COMPILE_LANGUAGE:CXX>:-include ${CMAKE_CURRENT_SOURCE_DIR}/tdesktop-dev/Telegram/lib_ui/ui/ui_pch.h>
    -w
)

target_link_libraries(UzOS_TelegramUI PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Svg
    C:/Qt/6.8.0/llvm-mingw_64/lib/libQt6BundledLibjpeg.a
)
