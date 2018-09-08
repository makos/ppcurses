file(GLOB_RECURSE TESTSRC *.cpp)
file(GLOB_RECURSE LIBSRC ${CMAKE_HOME_DIRECTORY}/src/*.cpp)

add_executable(tests ${TESTSRC} ${LIBSRC})
