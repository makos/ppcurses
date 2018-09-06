file(GLOB_RECURSE SOURCES *.cpp)

add_executable(test ${SOURCES})

target_compile_options(test PRIVATE "-Wall")

set_target_properties(test PROPERTIES CXX_STANDARD 17)

target_include_directories(test PUBLIC ${CMAKE_HOME_DIRECTORY}/include)

target_link_libraries(test ncurses)