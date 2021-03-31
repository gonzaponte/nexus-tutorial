## Exercise1 | CMakeLists.txt

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(Exercise1)

## Find Geant4 package, activating all available UI and Vis
## drivers by default. You can set WITH_GEANT4_UIVIS to OFF
## via the command line or ccmake/cmake-gui to build a batch
## mode only executable.
option(WITH_GEANT4_UIVIS "Build with Geant4 UI/VIS drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

## Setup Geant4 include directories and compile definitions.
include(${Geant4_USE_FILE})

## Recurse through sub-directories
add_subdirectory(src)
#add_subdirectory(mac)

add_executable(Exercise1 Exercise1.cpp $<TARGET_OBJECTS:Exercise1_SRC>)
target_include_directories(Exercise1 PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(Exercise1 ${Geant4_LIBRARIES})
