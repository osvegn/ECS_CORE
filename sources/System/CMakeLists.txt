set (SRC_SYSTEMS_ROOT ${PROJECT_SOURCE_DIR}/sources/System)

set(SYSTEMS_SOURCES
    ${SRC_SYSTEMS_ROOT}/system_world_initializer.c
    ${SRC_SYSTEMS_ROOT}/system_load_scene.c
    ${SRC_SYSTEMS_ROOT}/system_display.c
    ${SRC_SYSTEMS_ROOT}/system_reload_config.c
    ${SRC_SYSTEMS_ROOT}/system_windows_manager.c
    # ${SRC_SYSTEMS_ROOT}/system_gravity.c
    # ${SRC_SYSTEMS_ROOT}/system_jump.c
    # ${SRC_SYSTEMS_ROOT}/system_move_controllable.c
    # ${SRC_SYSTEMS_ROOT}/system_movement.c
    # ${SRC_SYSTEMS_ROOT}/system_obstacle_creation.c
    # ${SRC_SYSTEMS_ROOT}/system_camera.c
    PARENT_SCOPE
)
