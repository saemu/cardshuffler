#
# Copyright 2019, Samuel Brand
#

set( SRCS
     CardTest.cpp
     DeckTest.cpp )

add_executable( testrunner )
target_sources( testrunner PRIVATE ${SRCS} )
target_link_libraries( testrunner PRIVATE cards GTest::GTest )

include(GoogleTest)
gtest_discover_tests( testrunner )
