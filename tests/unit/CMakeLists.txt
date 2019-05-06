#
# Copyright 2016, Samuel Brand
#

set( SRCS
     CardTest.cpp
     DeckTest.cpp
     main.cpp )


add_executable( testrunner ${SRCS} )
target_link_libraries( testrunner cards Boost::unit_test_framework Boost::disable_autolinking )

add_test( NAME unittests
          COMMAND testrunner )
