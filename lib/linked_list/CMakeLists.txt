set(LINKED_LIST_SOURCE_ROOT ${PROJECT_SOURCE_DIR}/lib/linked_list/source)
set(LINKED_LIST_INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/lib/linked_list/include)
set(TARGET linked_list)
set(SOURCE
    ${LINKED_LIST_SOURCE_ROOT}/at_linked_list.c
    ${LINKED_LIST_SOURCE_ROOT}/back_linked_list.c
    ${LINKED_LIST_SOURCE_ROOT}/create_linked_list.c
    ${LINKED_LIST_SOURCE_ROOT}/destroy_linked_list.c
    ${LINKED_LIST_SOURCE_ROOT}/empty_linked_list.c
    ${LINKED_LIST_SOURCE_ROOT}/front_linked_list.c
    ${LINKED_LIST_SOURCE_ROOT}/insert_linked_list.c
    ${LINKED_LIST_SOURCE_ROOT}/push_back_linked_list.c
    ${LINKED_LIST_SOURCE_ROOT}/remove_linked_list.c
    ${LINKED_LIST_SOURCE_ROOT}/size_linked_list.c
)

add_library(${TARGET} ${SOURCE})

target_include_directories(${TARGET}
    PUBLIC ${LINKED_LIST_INCLUDE_ROOT}
)