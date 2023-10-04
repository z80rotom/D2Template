cmake_minimum_required(VERSION 3.8)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project(d2grimharvest)

add_compile_definitions(WIN32)

add_library(d2grimharvest SHARED src/DLLmain.cpp src/PusBolt.cpp src/Hirelings.cpp)

target_include_directories(d2grimharvest PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

set_target_properties(d2grimharvest PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/dist
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/dist
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/dist
        PREFIX ""
)

# set_target_properties(libusb )