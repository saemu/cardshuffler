#
# Copyright 2016, Samuel Brand
#

set( SRCS
     Card.cpp
     Deck.cpp )

set( HDRS
     Card.hpp
     Deck.hpp )

add_library( cards ${SRCS} ${HDRS} )
target_include_directories( cards
    PUBLIC
        ${CMAKE_SOURCE_DIR}/src
)
