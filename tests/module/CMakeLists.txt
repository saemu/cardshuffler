
add_test( NAME cardshuffler_failed
          COMMAND sh -c "echo FOO | $<TARGET_FILE:cardshuffler>" )

add_test( NAME cardshuffler_success
          COMMAND sh -c "echo n | $<TARGET_FILE:cardshuffler>" )

set_tests_properties( cardshuffler_failed
                      PROPERTIES WILL_FAIL True )
