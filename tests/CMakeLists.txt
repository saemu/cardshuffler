#
# Copyright 2016, Samuel Brand
#

set( GTEST_MSVC_SEARCH "MD" )
find_package( GTest REQUIRED )
find_package( ApprovalTests REQUIRED )
find_package( benchmark REQUIRED )

add_subdirectory( unit )
add_subdirectory( benchmark )
add_subdirectory( module )

add_test( NAME cardshuffler_failed
          COMMAND sh -c "echo FOO | $<TARGET_FILE:cardshuffler>" )

add_test( NAME cardshuffler_success
          COMMAND sh -c "echo n | $<TARGET_FILE:cardshuffler>" )

set_tests_properties( cardshuffler_failed
                      PROPERTIES WILL_FAIL True )
