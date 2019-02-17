cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(cpp2python)

set (CMAKE_CXX_FLAGS "-Wno-deprecated-declarations -Wno-register")

set(EXTERNALS_SOURCE_DIR "${CMAKE_SOURCE_DIR}/externals")

# Find default python libraries and interpreter
find_package(PythonInterp REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories("${EXTERNALS_SOURCE_DIR}/include")
include_directories("${PYTHON_INCLUDE_DIRS}")

LINK_DIRECTORIES("${EXTERNALS_SOURCE_DIR}/lib")


file(GLOB sources src/*.cpp src/*.h )


add_library(cpp2python SHARED ${sources})

target_link_libraries(cpp2python boost_python boost_exception)

# Tweaks the name of the library to match what Python expects
set_target_properties(cpp2python PROPERTIES SUFFIX .so)
set_target_properties(cpp2python PROPERTIES PREFIX "")
add_custom_command(TARGET cpp2python 
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:cpp2python> ${CMAKE_SOURCE_DIR}/src)


