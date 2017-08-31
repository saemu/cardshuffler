
set( SRCS
     CardTest.cpp )


add_executable( testrunner ${SRCS} )
target_link_libraries( testrunner cards gtest gtest_main )

add_test( NAME unittests
          COMMAND testrunner )