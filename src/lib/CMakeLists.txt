#
# Copyright 2016, Samuel Brand
#

set( HDRS
     Card.hpp
     Deck.hpp
     DeckApplication.hpp )

set( SRCS
     Card.cpp
     Deck.cpp
     DeckApplication.cpp )

add_library( cards STATIC )
target_sources( cards
                PRIVATE ${HDRS} ${SRCS} )

target_include_directories( cards
                            PUBLIC ${CMAKE_SOURCE_DIR}/src
                            )

target_link_libraries( cards PUBLIC compiler_settings fmt::fmt spdlog::spdlog )
