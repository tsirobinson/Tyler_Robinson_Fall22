cmake_minimum_required(VERSION 3.20)

project(coda_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(WIN32)
	add_definitions(-DCODA_WINDOWS)
elseif(APPLE)
	add_definitions(-DCODA_MAC)
else()
	add_definitions(-DCODA_LINUX)
endif()

add_definitions(-DCODA_DEBUG)


add_subdirectory(GEFall22)
add_subdirectory(Coda)