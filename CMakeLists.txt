cmake_minimum_required( VERSION 3.21 )
project( interface_with_concepts )

set( CMAKE_CXX_STANDARD 23 )

include_directories( . )

if ( MSVC )
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest /permissive- /W4")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2b -Wall -Wextra -Werror")
endif()

add_executable( interface_with_concepts
	src/main.cpp
)
