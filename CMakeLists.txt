#
# Copyright 2019, Samuel Brand
#

cmake_minimum_required( VERSION 3.15 FATAL_ERROR )

project( cardshuffler )

if( EXISTS ${CMAKE_BINARY_DIR}/conan_paths.cmake )
    include( ${CMAKE_BINARY_DIR}/conan_paths.cmake )
else()
    message( WARNING "The file conan_paths.cmake doesn't exist, you have to run conan install first" )
endif()

find_package( fmt REQUIRED )

set( GTEST_MSVC_SEARCH "MD" )
find_package( GTest REQUIRED )

add_subdirectory( src )

enable_testing()
add_subdirectory( tests )
