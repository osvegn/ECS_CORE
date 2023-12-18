set(COMPONENT_TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests/unit/Component)
set(TARGET component_tests)
set(SOURCE
    ${GLOBAL_SOURCES}
    ${COMPONENT_TESTS_ROOT}/component_color.c
    ${COMPONENT_TESTS_ROOT}/component_position.c
    ${COMPONENT_TESTS_ROOT}/component_size.c
    ${COMPONENT_TESTS_ROOT}/component_velocity.c
)

add_executable(${TARGET} ${SOURCE})

target_link_libraries(${TARGET}
    ecs
    json-c
)

target_include_directories(${TARGET}
    PRIVATE ${PROJECT_SOURCE_DIR}/includes
)

add_test(${TARGET} ${TARGET})

set_target_properties(${TARGET}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/
)