#
# Copyright 2016, Samuel Brand
#

set( SRCS
     Card.cpp
     Deck.cpp )

set( HDRS
     Card.h
     Deck.h )

add_library( cards ${SRCS} ${HDRS} )
