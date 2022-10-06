set(SOURCE_FILES
	CodaApp.cpp
)

set(HEADER_FILES
	Coda.h
	CodaApp.h
	CodaUtil.h
)

add_library(Coda SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DCODA_LIB)

target_precompile_headers(Coda PRIVATE pch.h)

include_directories(../glfw/include/)

target_link_libraries(Coda glfw)