#
# Copyright 2019, Samuel Brand
#

cmake_minimum_required( VERSION 3.12 FATAL_ERROR )

project( cardshuffler )

if( EXISTS ${CMAKE_BINARY_DIR}/conan_paths.cmake )
    include( ${CMAKE_BINARY_DIR}/conan_paths.cmake )
else()
    message( WARNING "The file conan_paths.cmake doesn't exist, you have to run conan install first" )
endif()

find_package( GTest REQUIRED )

find_program( CLANG_TIDY clang-tidy )
if( CLANG_TIDY )
    set( CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY} )
endif()

add_subdirectory( src )

enable_testing()
add_subdirectory( tests )
