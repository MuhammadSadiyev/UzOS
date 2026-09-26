cmake_minimum_required(VERSION 3.20)
project(uzos-shell VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS
    Core
    Gui
    Qml
    Quick
    QuickControls2
    DBus
)

add_executable(uzos-shell
    src/main.cpp
    src/system_manager.h
    src/system_manager.cpp
    qml.qrc
)

target_link_libraries(uzos-shell PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::DBus
)

install(TARGETS uzos-shell DESTINATION /usr/bin)
install(FILES session/uzos.desktop DESTINATION /usr/share/wayland-sessions)
install(PROGRAMS session/start-uzos.sh DESTINATION /usr/bin)
