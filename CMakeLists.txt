#
# Copyright 2016, Samuel Brand
#

cmake_minimum_required( VERSION 3.0 FATAL_ERROR )

project( cardshuffler )

set( CMAKE_CXX_STANDARD 14 )

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

if( MSVC )
    set( CMAKE_CXX_FLAGS "/W4 /WX" )
else( MSVC )
    set( CMAKE_CXX_FLAGS "-Wall -Wextra -fstack-protector-all" )
    set( CMAKE_CXX_FLAGS_DEBUG  "-g" )
endif( MSVC )

add_subdirectory( src )

enable_testing()
add_subdirectory( tests )
