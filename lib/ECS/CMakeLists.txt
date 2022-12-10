set(ECS_SOURCE_ROOT ${PROJECT_SOURCE_DIR}/lib/ECS/source)
set(ECS_INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/lib/ECS/include)
set(TARGET ecs)
set(SOURCE
    ${ECS_SOURCE_ROOT}/world.c
)

add_library(${TARGET} ${SOURCE})

target_include_directories(${TARGET}
    PUBLIC ${ECS_INCLUDE_ROOT}
)

target_link_libraries(${TARGET}
    linked_list
)