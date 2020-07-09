#
# Copyright 2020, Samuel Brand
#

set( SRCS
     DeckBenchmark.cpp )

add_executable( benchmark )
target_sources( benchmark PRIVATE ${SRCS} )
target_link_libraries( benchmark PRIVATE
                       cards
                       benchmark::benchmark )
