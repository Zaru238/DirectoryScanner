set(TARGET server)

set(SOURCES_PROG
  main.cpp
  directory_scanner.cpp
  server.cpp
  session.cpp)

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
    ${Boost_SYSTEM_LIBRARY}
    Boost::log)

target_include_directories(${TARGET}
  PRIVATE
    ${Boost_INCLUDE_DIR})

add_custom_command(TARGET ${TARGET} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR})

