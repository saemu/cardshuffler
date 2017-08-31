#
# Copyright 2016, Samuel Brand
#

set( SRCS
     CardTest.cpp )


add_executable( testrunner ${SRCS} )
target_link_libraries( testrunner cards ${CONAN_LIBS} )

add_test( NAME unittests
          COMMAND testrunner )
