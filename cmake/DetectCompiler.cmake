# Script that sets the COMPILER_TYPE variable according to the current variable
#
# Possible values:
# "msvc" (windows-only)
# "gcc" (linux, mingw not supported yet)


#RAYLIB
set(RAYLIB_VERSION 4.2.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

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
if (CMAKE_COMPILER_IS_GNUCC)
  set(COMPILER_TYPE "gcc")
  ## Add the flags for the compilation ##
  add_compile_options(
    "-Wall" "-Wextra" "-Wshadow"
  )

elseif (MSVC)
  set(COMPILER_TYPE "msvc")
else ()
  set(COMPILER_TYPE "unknown")
  message(WARNING "Unknown compiler type, compilation may not work as expected")
endif()
