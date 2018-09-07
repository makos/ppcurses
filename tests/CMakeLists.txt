file(GLOB_RECURSE TESTSRC *.cc)
file(GLOB_RECURSE LIBSRC ${CMAKE_HOME_DIRECTORY}/src/*.cc)

add_executable(tests ${TESTSRC} ${LIBSRC})
