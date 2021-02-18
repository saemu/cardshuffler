
set( SRCS
     main.cpp
     DeckApplicationTest.cpp
     )

add_executable( moduletest )
target_sources( moduletest PRIVATE ${SRCS} )
target_link_libraries( moduletest PRIVATE cards ApprovalTests::ApprovalTests GTest::gtest )
