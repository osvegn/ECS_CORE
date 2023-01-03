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
set(SOURCE
)

# EXECUTABLE
add_executable(${TARGET} ${MAIN} ${SOURCE})
target_include_directories(${TARGET}
    PUBLIC ${INCLUDE_ROOT}
)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(DetectCompiler)

#LIBRARY
add_subdirectory(lib)
