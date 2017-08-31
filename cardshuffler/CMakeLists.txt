#
# RUAG Schweiz AG
# RUAG Aviation
# Boenigstrasse 17
# CH-3812 Wilderswil - Switzerland
#
# Copyright (c) 2015, RUAG Schweiz AG, all rights reserved.
#

cmake_minimum_required( VERSION 3.0 FATAL_ERROR )

project( cardshuffler )

if( MSVC )
   add_compile_options( /W4 /WX )
else( MSVC )
   add_compile_options( -std=c++11 -Wall -Wextra -Werror -fstack-protector-all )
endif( MSVC )

include_directories( src )

add_subdirectory( src )
