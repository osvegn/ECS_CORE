set(TARGET "test")

set(SOURCES
    "test.c"
)
add_compile_options("-fPIC")
add_library(${TARGET} SHARED ${SOURCES})