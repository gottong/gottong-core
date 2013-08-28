cmake_minimum_required(VERSION 2.8)
project(gottong)

FILE(GLOB SOURCES
	"${gottong_SOURCE_DIR}/src/*.c"
	"${gottong_SOURCE_DIR}/src/*.cc")

find_library(SDL2_LIB SDL2)
find_library(SDL2_IMAGE_LIB SDL2_image)
find_library(SDL2_MIXER_LIB SDL2_mixer)
find_library(SDL2_TTF_LIB SDL2_ttf)

add_library(gottong ${SOURCES})

set_target_properties(gottong PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(gottong
	${SDL2_LIB}
	${SDL2_IMAGE_LIB}
	${SDL2_MIXER_LIB}
	${SDL2_TTF_LIB})

