add_subdirectory(Component)
add_subdirectory(Resource)
add_subdirectory(System)

set(SOURCES
    ${COMPONENTS_SOURCES}
    ${RESOURCES_SOURCES}
    ${SYSTEMS_SOURCES}
    PARENT_SCOPE
)
