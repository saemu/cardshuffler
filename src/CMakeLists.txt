#
# Copyright 2016, Samuel Brand
#

set( SRCS
     main.cpp )

add_subdirectory( lib )

add_executable( cardshuffler )
target_sources( cardshuffler PRIVATE ${SRCS} )
target_link_libraries( cardshuffler PRIVATE cards )
