cmake_minimum_required(VERSION 3.24)

project(final_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DCODA_WINDOWS)
elseif(APPLE)
	add_definitions(-DCODA_MAC)
else()
	add_definitions(-DCODA_LINUX)
endif()

add_definitions(-DCODA_DEBUG)
add_definitions(-DCODA_OPENGL)

add_subdirectory(GEFall22)
add_subdirectory(Coda)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)

set(VS_STARTUP_PROJECT GEFall22)

file(COPY GEFall22/Assets DESTINATION ${PROJECT_BINARY_DIR}/GEFall22)
file(COPY GEFall22/Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY GEFall22/Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)