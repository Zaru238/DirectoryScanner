set(TARGET client)

set(SOURCES_PROG
  main.cpp)

add_executable(${TARGET}
  ${SOURCES_PROG})

target_compile_options(${TARGET}
  PRIVATE
    -Wall
    -Werror)

target_link_libraries(${TARGET}
  PRIVATE
    common
    Threads::Threads
    ${Boost_SYSTEM_LIBRARY})

target_include_directories(${TARGET}
  PRIVATE
    ${Boost_INCLUDE_DIR})
