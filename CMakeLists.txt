#
# Copyright 2016, Samuel Brand
#

cmake_minimum_required( VERSION 3.0 FATAL_ERROR )

project( cardshuffler )

set( CMAKE_CXX_STANDARD 14 )

include( ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake )
conan_basic_setup()

if( MSVC )
    add_compile_options( /W4 /WX )
else( MSVC )
    add_compile_options( -Wall -Wextra -fstack-protector-all )
endif( MSVC )

include_directories( src )
add_subdirectory( src )

enable_testing()
add_subdirectory( tests )
