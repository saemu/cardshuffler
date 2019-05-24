#
# Copyright 2016, Samuel Brand
#

set( HDRS
     Card.hpp
     Deck.hpp )

set( SRCS
     Card.cpp
     Deck.cpp )

add_library( cards STATIC )
target_sources( cards
                PUBLIC ${HDRS}
                PRIVATE ${SRCS} )

target_include_directories( cards
                            PUBLIC ${CMAKE_SOURCE_DIR}/src
                            )

target_compile_features( cards
                         PUBLIC cxx_std_14 )

if( WIN32 )
    target_compile_options( cards
                            PUBLIC /W4 /WX
                            )
else()
    target_compile_options( cards
                            PUBLIC
                            -Wall -Wextra -fstack-protector-all
                            $<$<CONFIG:Debug>:-ggdb -O0 -fno-inline>
                            )
endif()
