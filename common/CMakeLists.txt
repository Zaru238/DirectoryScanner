set(TARGET common)

set(SOURCES
  common.cpp)

add_library(${TARGET} STATIC
  ${SOURCES})

target_compile_options(${TARGET}
  PRIVATE
    -Wall
    -Werror)

target_include_directories(${TARGET}
  INTERFACE
    include
  PRIVATE
    include/${TARGET})
