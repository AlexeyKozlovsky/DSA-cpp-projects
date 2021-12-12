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
        "${CMAKE_SOURCE_DIR}/ui/models/*.cpp"
        "${CMAKE_SOURCE_DIR}/ui/delegates/*.cpp"
        "${CMAKE_SOURCE_DIR}/ui/views/*.cpp"
        "${CMAKE_SOURCE_DIR}/services/builders/*.cpp"
        "${CMAKE_SOURCE_DIR}/services/managers/*.cpp"
        "${CMAKE_SOURCE_DIR}/models/*.h"
        "${CMAKE_SOURCE_DIR}/models/enums/*.h"
        "${CMAKE_SOURCE_DIR}/services/*.h"
        "${CMAKE_SOURCE_DIR}/ui/*.h"
        "${CMAKE_SOURCE_DIR}/ui/models/*.h"
        "${CMAKE_SOURCE_DIR}/ui/delegates/*.h"
        "${CMAKE_SOURCE_DIR}/ui/views/*.h"
        "${CMAKE_SOURCE_DIR}/services/builders/*.h"
        "${CMAKE_SOURCE_DIR}/services/managers/*.h"
        "main.cpp")

set(SOURCES ${SOURCES})
add_executable(FinalProject ${SOURCES})

target_link_libraries(FinalProject
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )



