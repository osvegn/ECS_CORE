set(SYSTEM_TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests/sources/System)
set(TARGET system_tests)
set(SOURCE
    ${SYSTEM_TESTS_ROOT}/movement_tests.c
)

add_executable(${TARGET} ${SOURCE})

target_link_libraries(${TARGET}
    ecs
)

target_include_directories(${TARGET}
    ${PROJECT_SOURCE_DIR}/includes
)

add_test(${TARGET} ${TARGET})

set_target_properties(${TARGET}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/
)