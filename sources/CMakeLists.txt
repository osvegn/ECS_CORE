add_subdirectory(Component)
add_subdirectory(Resource)

set(SOURCES
    ${COMPONENTS_SOURCES}
    ${RESOURCES_SOURCES}
    PARENT_SCOPE
)
