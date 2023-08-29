# PROJECT PART
cmake_minimum_required(VERSION 3.16)
project(${TARGET} LANGUAGES C)

# VARIABLE PART
set(TARGET our_rpg)
set(SOURCE_ROOT ${PROJECT_SOURCE_DIR}/sources)
set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/includes)
set(MAIN
${SOURCE_ROOT}/main.c
)

add_subdirectory(sources)

set(GLOBAL_SOURCES
    ${SOURCES}
)

# output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# EXECUTABLE
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
# include(Dependencies)
include(Testings)
include(DetectCompiler)

#LIBRARY
add_subdirectory(submodules/ECS)
add_subdirectory(submodules/json-c)
add_subdirectory(submodules/raylib)