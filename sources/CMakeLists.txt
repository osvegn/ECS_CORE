add_subdirectory(System)
add_subdirectory(Resource)

set(SOURCES
    ${RESOURCES_SOURCES}
    ${SYSTEMS_SOURCES}
    PARENT_SCOPE
)
