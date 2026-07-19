cmake_minimum_required(VERSION 3.21...3.30)
project(part_one LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui
)

set(APP_RESOURCES
    resources.qrc
)

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS
    src/*.h
    src/*.hpp
    src/*.cpp
)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Gui Qml Quick Charts Network)
qt_standard_project_setup()

qt_add_executable(math_guide ${APP_SOURCES} ${APP_RESOURCES})

target_include_directories(math_guide PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/math_guide_autogen/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/core
    ${CMAKE_SOURCE_DIR}/src/widget
    ${CMAKE_SOURCE_DIR}/src/ui
    ${CMAKE_SOURCE_DIR}/src/style
    ${CMAKE_SOURCE_DIR}/src/data
)

target_link_libraries(math_guide PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Charts
    Qt6::Network
)

set_target_properties(math_guide PROPERTIES
    WIN32_EXECUTABLE TRUE
)