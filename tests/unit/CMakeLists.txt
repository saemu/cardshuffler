#
# Copyright 2016, Samuel Brand
#

include_directories(${CONAN_INCLUDE_DIRS})

set( SRCS
     CardTest.cpp )


add_executable( testrunner ${SRCS} )
target_link_libraries( testrunner cards ${CONAN_LIBS} )

add_test( NAME unittests
          COMMAND testrunner )
