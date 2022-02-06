cmake_minimum_required( VERSION 3.21 )
project( interface_with_concepts )

set( CMAKE_CXX_STANDARD 23 )

include_directories( . )

add_executable( interface_with_concepts
	src/main.cpp
)

if ( MSVC )
	#[[ https://docs.microsoft.com/en-us/cpp/build/reference/compiler-options-listed-by-category?view=msvc-170 ]]
	target_compile_options( interface_with_concepts
		BEFORE
		PRIVATE "/std:c++latest"
		PRIVATE "/permissive-"
		PRIVATE "/W4"
	)
else()
	message( SEND_ERROR "This project is not configured for this compiler." )
endif()
