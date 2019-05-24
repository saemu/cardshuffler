#
# Copyright 2016, Samuel Brand
#

cmake_minimum_required( VERSION 3.14 FATAL_ERROR )

project( cardshuffler )

if( EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake )
    include( ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake )
    conan_basic_setup()
    conan_define_targets()
else()
    message( WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first" )
endif()

set( BOOST_ROOT ${CONAN_BOOST_ROOT} )
set( BOOST_LIBRARYDIR ${BOOST_ROOT}/lib )
set( Boost_NO_SYSTEM_PATHS ON )
set( Boost_USE_STATIC_LIBS ON )
set( Boost_USE_MULTITHREADED ON )
set( Boost_USE_STATIC_RUNTIME $<$<COMPILER_ID:MSVC>:ON> )
set( Boost_DEBUG ON )
find_package( Boost 1.70.0 REQUIRED COMPONENTS unit_test_framework )

find_program( CLANG_TIDY clang-tidy )
if( CLANG_TIDY )
    set( CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY} )
endif()

add_subdirectory( src )

enable_testing()
add_subdirectory( tests )
