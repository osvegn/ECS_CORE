set(SRC_COMPONENTS_ROOT ${PROJECT_SOURCE_DIR}/sources/Component)

set(COMPONENTS_SOURCES
    ${SRC_COMPONENTS_ROOT}/component_position.c
    ${SRC_COMPONENTS_ROOT}/component_velocity.c
    ${SRC_COMPONENTS_ROOT}/component_size.c
    ${SRC_COMPONENTS_ROOT}/component_color.c
    ${SRC_COMPONENTS_ROOT}/component_displayable.c
    ${SRC_COMPONENTS_ROOT}/component_controllable.c
    ${SRC_COMPONENTS_ROOT}/component_collidable.c
    ${SRC_COMPONENTS_ROOT}/component_speed.c
    PARENT_SCOPE
)