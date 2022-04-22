#
# Copyright 2016, Samuel Brand
#

set( HDRS
     Card.hpp
     Deck.hpp
     DeckApplication.hpp
     )

set( SRCS
     Card.cpp
     Deck.cpp
     DeckApplication.cpp
     )

add_library( cards STATIC )
target_sources( cards
                PRIVATE ${HDRS} ${SRCS} )

target_include_directories( cards
                            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                            )

target_link_libraries( cards PUBLIC compiler_settings spdlog::spdlog )
