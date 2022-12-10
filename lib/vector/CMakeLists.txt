set(VECTOR_SOURCE_ROOT ${PROJECT_SOURCE_DIR}/lib/vector/source)
set(VECTOR_INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/lib/vector/include)
set(TARGET vector)
set(SOURCE
    ${VECTOR_SOURCE_ROOT}/vector.c
)

add_library(${TARGET} ${SOURCE})

target_include_directories(${TARGET}
    PUBLIC ${VECTOR_INCLUDE_ROOT}
)
