#
# Copyright 2019, Samuel Brand
#

cmake_minimum_required( VERSION 3.16 FATAL_ERROR )

project( cardshuffler )

if( NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake" )
    message( STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan" )
     file( DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
          "${CMAKE_BINARY_DIR}/conan.cmake"
          TLS_VERIFY ON )
endif()

list( APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} )

include( ${CMAKE_BINARY_DIR}/conan.cmake )
include( cmake/compiler_settings.cmake )

conan_cmake_configure( REQUIRES
                       gtest/1.11.0
                       spdlog/1.10.0
                       benchmark/1.6.1
                       approvaltests.cpp/10.12.2
                       GENERATORS cmake_find_package
                       )

conan_cmake_autodetect( CONAN_SETTINGS )

conan_cmake_install( PATH_OR_REFERENCE ${CMAKE_BINARY_DIR}
                     BUILD missing
                     SETTINGS ${CONAN_SETTINGS} )

find_package( spdlog REQUIRED )

add_subdirectory( src )

enable_testing()
add_subdirectory( tests )
