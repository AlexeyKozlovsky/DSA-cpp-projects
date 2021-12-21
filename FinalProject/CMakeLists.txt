cmake_minimum_required(VERSION 3.20)
project(FinalProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(models)
include_directories(services)
include_directories(ui)
include_directories(services/managers)
include_directories(models/enums)
include_directories(ui/views)
include_directories(ui/delegates)
include_directories(ui/components)
include_directories(ui/windows)
include_directories(ui/dialogs)
include_directories(ui/models/proxies)
include_directories(ui/models/tables)
include_directories(ui/models/trees)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

file(GLOB SOURCES
        "${CMAKE_SOURCE_DIR}/models/*.cpp"
        "${CMAKE_SOURCE_DIR}/models/enums/*.cpp"
        "${CMAKE_SOURCE_DIR}/services/*.cpp"
        "${CMAKE_SOURCE_DIR}/ui/*.cpp"
        "${CMAKE_SOURCE_DIR}/ui/models/proxies/*.cpp"
        "${CMAKE_SOURCE_DIR}/ui/models/tables/*.cpp"
        "${CMAKE_SOURCE_DIR}/ui/models/trees/*.cpp"
        "${CMAKE_SOURCE_DIR}/ui/delegates/*.cpp"
        "${CMAKE_SOURCE_DIR}/ui/views/*.cpp"
        "${CMAKE_SOURCE_DIR}/ui/windows/*.cpp"
        "${CMAKE_SOURCE_DIR}/ui/dialogs/*.cpp"
        "${CMAKE_SOURCE_DIR}/ui/components/*.cpp"
        "${CMAKE_SOURCE_DIR}/services/managers/*.cpp"
        "${CMAKE_SOURCE_DIR}/models/*.h"
        "${CMAKE_SOURCE_DIR}/models/enums/*.h"
        "${CMAKE_SOURCE_DIR}/services/*.h"
        "${CMAKE_SOURCE_DIR}/ui/*.h"
        "${CMAKE_SOURCE_DIR}/ui/models/proxies/*.h"
        "${CMAKE_SOURCE_DIR}/ui/models/tables/*.h"
        "${CMAKE_SOURCE_DIR}/ui/models/trees/*.h"
        "${CMAKE_SOURCE_DIR}/ui/delegates/*.h"
        "${CMAKE_SOURCE_DIR}/ui/views/*.h"
        "${CMAKE_SOURCE_DIR}/ui/windows/*.h"
        "${CMAKE_SOURCE_DIR}/ui/dialogs/*.h"
        "${CMAKE_SOURCE_DIR}/ui/components/*.h"
        "${CMAKE_SOURCE_DIR}/services/managers/*.h"
        "main.cpp")

set(SOURCES ${SOURCES})
add_executable(FinalProject ${SOURCES})

target_link_libraries(FinalProject
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )



