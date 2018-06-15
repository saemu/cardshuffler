#
# Copyright 2016, Samuel Brand
#

add_library( cards Card.cpp
             Deck.cpp
             Card.hpp
             Deck.hpp
             )
target_include_directories( cards
                            PUBLIC ${CMAKE_SOURCE_DIR}/src
                            )

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
