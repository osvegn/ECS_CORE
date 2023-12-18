set (SRC_SYSTEMS_ROOT ${PROJECT_SOURCE_DIR}/sources/System)

set(SYSTEMS_SOURCES
    ${SRC_SYSTEMS_ROOT}/system_world_initializer.c
    ${SRC_SYSTEMS_ROOT}/system_load_scene.c
    ${SRC_SYSTEMS_ROOT}/system_windows_manager.c
    ${SRC_SYSTEMS_ROOT}/system_reset_game_clock.c
    ${SRC_SYSTEMS_ROOT}/system_movement.c
    PARENT_SCOPE
)
