## TESTING ##
option(TESTING OFF)
if (TESTING)
  enable_testing()
  add_compile_options("-lcriterion" "--coverage" "-fprofile-arcs" "-ftest-coverage")
  add_link_options("-lcriterion" "--coverage" "-fprofile-arcs" "-ftest-coverage")
  add_subdirectory(tests)
else ()
  add_executable(${TARGET} ${MAIN} ${GLOBAL_SOURCES})
  target_include_directories(${TARGET}
      PUBLIC ${INCLUDE_ROOT}
  )

  target_link_libraries(${TARGET}
      ecs
      raylib
      json-c
  )
endif()