#
# Copyright 2019, Samuel Brand
#

set( SRCS
     CardTest.cpp
     DeckTest.cpp
     DeckApplicationTest.cpp )

add_executable( testrunner )
target_sources( testrunner PRIVATE ${SRCS} )
target_link_libraries( testrunner PRIVATE cards GTest::GTest )

file( MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/results/unit )
add_test( NAME cardshuffler_test
          COMMAND testrunner --gtest_output=xml:../results/unit/ )
