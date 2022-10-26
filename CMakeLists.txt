cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(MeowIDI)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

include(cmake/CPM.cmake)
CPMAddPackage("gh:FluidSynth/fluidsynth#v2.3.0")

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(meowidi
	meowidi/main.cpp
)

target_link_libraries(meowidi Qt5::Widgets libfluidsynth)
