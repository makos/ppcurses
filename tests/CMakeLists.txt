file(GLOB_RECURSE TESTSRC *.cc)
file(GLOB_RECURSE SRC ${CMAKE_HOME_DIRECTORY}/src/*.cc)

add_executable(tests ${TESTSRC} ${SRC})

target_compile_options(tests PRIVATE "-Wall")

set_target_properties(tests PROPERTIES CXX_STANDARD 17)

target_include_directories(tests PUBLIC ${CMAKE_HOME_DIRECTORY}/include)

target_link_libraries(tests ncurses)