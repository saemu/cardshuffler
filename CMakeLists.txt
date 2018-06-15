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

find_program( CLANG_TIDY clang-tidy )
if( CLANG_TIDY )
    set(CMAKE_CXX_CLANG_TIDY  ${CLANG_TIDY} )
endif()

add_subdirectory( src )

enable_testing()
add_subdirectory( tests )
