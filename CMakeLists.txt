cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(MeowIDI)

add_executable(meowidi meowidi/main.cpp)

include(cmake/CPM.cmake)

CPMAddPackage("gh:FluidSynth/fluidsynth#v2.3.0")

target_link_libraries(meowidi libfluidsynth)
