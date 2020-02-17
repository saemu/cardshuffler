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
                PRIVATE ${HDRS} ${SRCS} )

target_include_directories( cards
                            PUBLIC ${CMAKE_SOURCE_DIR}/src
                            )

target_compile_features( cards
                         PUBLIC cxx_std_14 )

target_compile_options( cards
                        PUBLIC
                        $<$<CXX_COMPILER_ID:MSVC>:/W4;/WX>
                        $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall;-Wextra;-fstack-protector-all>
                        $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:$<$<CONFIG:Debug>:-g;-O0;-fno-inline>>
                        )

target_link_libraries( cards PUBLIC fmt::fmt )
