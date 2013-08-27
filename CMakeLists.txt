cmake_minimum_required(VERSION 2.8)
project(gottong)

FILE(GLOB SOURCES
	"${gottong_SOURCE_DIR}/src/*.c"
	"${gottong_SOURCE_DIR}/src/*.cc")

find_library(SDL_LIB SDL)
find_library(SDL_IMAGE_LIB SDL_image)
find_library(SDL_MIXER_LIB SDL_mixer)
find_library(SDL_TTF_LIB SDL_ttf)

add_library(gottong ${SOURCES})

set_target_properties(gottong PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(gottong
	${SDL_LIB}
	${SDL_IMAGE_LIB}
	${SDL_MIXER_LIB}
	${SDL_TTF_LIB})

