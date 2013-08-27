cmake_minimum_required(VERSION 2.8)
project(gottong)

FILE(GLOB SOURCES "${gottong_SOURCE_DIR}/src" *.cc)

find_library(SDL_LIB
	name SDL libSDL
	PATH_SUFFIXES
	lib lib64 lib32)

add_library(gottong ${SOURCES})

set_target_properties(gottong PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(gottong ${SDL_LIB})

