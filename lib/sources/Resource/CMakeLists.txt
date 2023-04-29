set (SRC_RESOURCES_ROOT ${PROJECT_SOURCE_DIR}/sources/Resource)

set (RESOURCES_SOURCES
    ${SRC_RESOURCES_ROOT}/resource_gravity.c
    ${SRC_RESOURCES_ROOT}/resource_window.c
    ${SRC_RESOURCES_ROOT}/resource_camera.c
    ${SRC_RESOURCES_ROOT}/resource_scene_filename.c
    PARENT_SCOPE
)