cmake_minimum_required(VERSION 3.0.0)

# remember to change VERSION in application.h
project(ppcurses VERSION 0.2.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  add_compile_options("-Wall")
  add_compile_options("-pedantic")
  add_compile_options("--std=c++17")
endif()

set_property(GLOBAL PROPERTY CXX_STANDARD 17)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_HOME_DIRECTORY}/include)
link_libraries(ncurses)

add_subdirectory(tests)
add_subdirectory(src)
