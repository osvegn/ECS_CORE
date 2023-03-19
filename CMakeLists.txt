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
    ${SOURCE_ROOT}/System/movement.c
    ${SOURCE_ROOT}/System/display.c
    ${SOURCE_ROOT}/System/world_initializer.c
    ${SOURCE_ROOT}/System/windows_manager.c
    ${SOURCE_ROOT}/System/move_controllable.c
    ${SOURCE_ROOT}/System/gravity.c
    ${SOURCE_ROOT}/System/jump.c
    ${SOURCE_ROOT}/System/createObstacle.c

    ${SOURCES}

    ${SOURCE_ROOT}/Resource/window_resource.c
    ${SOURCE_ROOT}/Resource/gravity.c

    ${SOURCE_ROOT}/Entity/player.c
    ${SOURCE_ROOT}/Entity/plateform.c
    ${SOURCE_ROOT}/Entity/obstacle.c
)

# set_property(GLOBAL PROPERTY GLOBAL_SOURCES ${GLOBAL_SOURCES})

# EXECUTABLE
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(DetectCompiler)

#LIBRARY
add_subdirectory(ECS)