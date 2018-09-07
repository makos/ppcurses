file(GLOB_RECURSE LIB *.cc)

add_library(ppcurses ${LIB})

target_compile_options(ppcurses PRIVATE "-Wall")

set_target_properties(tests PROPERTIES CXX_STANDARD 17)

target_include_directories(ppcurses PUBLIC ${CMAKE_HOME_DIRECTORY}/include)

target_link_libraries(ppcurses ncurses)