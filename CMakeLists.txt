#
# Copyright 2019, Samuel Brand
#

cmake_minimum_required( VERSION 3.16 FATAL_ERROR )

project( cardshuffler )

if( NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake" )
    message( STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan" )
    file( DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
          "${CMAKE_BINARY_DIR}/conan.cmake"
          TLS_VERIFY ON )
endif()

include( ${CMAKE_BINARY_DIR}/conan.cmake )
include( cmake/compiler_settings.cmake )

conan_cmake_run( REQUIRES
                 fmt/6.1.2
                 gtest/1.10.0
                 spdlog/1.5.0
                 benchmark/1.5.0
                 BASIC_SETUP NO_OUTPUT_DIRS
                 GENERATORS cmake_paths cmake_find_package
                 BUILD missing
                 )

include( ${CMAKE_BINARY_DIR}/conan_paths.cmake )

find_package( fmt REQUIRED )
find_package( spdlog REQUIRED )

set( GTEST_MSVC_SEARCH "MD" )
find_package( GTest REQUIRED )

find_package( benchmark REQUIRED )

add_subdirectory( src )

enable_testing()
add_subdirectory( tests )
