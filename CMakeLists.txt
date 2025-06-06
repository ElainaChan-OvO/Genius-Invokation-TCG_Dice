cmake_minimum_required(VERSION 3.31)
project(Genius_Invokation_TCG_Dice)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(QTXLSX_ROOT "D:/Qt/Qt5/5.15.2/mingw81_64")

set(CMAKE_PREFIX_PATH "D:/Qt/Qt5/5.15.2/mingw81_64/lib/cmake")

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(${PROJECT_NAME} WIN32
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui)

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        "${QTXLSX_ROOT}/lib/libQt5Xlsx.a"
)

