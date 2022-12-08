set(VECTOR_TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests/library/vector)
set(TARGET vector_tests)
set(SOURCE
    ${VECTOR_TESTS_ROOT}/vector_tests.c
)

add_executable(${TARGET} ${SOURCE} ${VECTOR_SOURCE})

add_test(${TARGET} ${TARGET})

target_link_libraries(${TARGET}
    criterion
)