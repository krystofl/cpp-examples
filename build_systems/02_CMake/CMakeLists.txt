cmake_minimum_required(VERSION 3.10)
project(krystofs-cmake-template)

# Bring the headers, such as Person.h into the project
include_directories(include libs/include)

# source files
# excludes main.cpp so that we can also use this variable when building tests
set(SOURCES
    src/Person.cpp
    "libs/src/easylogging++.cc"
)

# shared libs we're linking to
# (include any needed .so files there like libMYLIB.so)
set(PROJECT_LINK_LIBS)
link_directories(libs/lib)

set(CMAKE_CXX_STANDARD 20) # use C++ 20
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# set flags for DEBUG builds
SET(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g3 -ggdb -Wall -Wno-deprecated -Wno-unknown-pragmas -Wno-reorder -Wno-unused-local-typedefs")

# set flags for RELEASE builds
SET(CMAKE_CXX_FLAGS_RELEASE  "-O3 -Wall -Wno-deprecated -Wno-unknown-pragmas -Wno-reorder -Wno-unused-local-typedefs")


# build an executable called demo-exec
add_executable(demo-exec ${SOURCES} src/main.cpp)

# link the libraries
# target_link_libraries(demo-exec ${PROJECT_LINK_LIBS})



########################################################################
# TESTS

add_executable(run_person_tests ${SOURCES} tests/person_tests.cpp)
target_link_libraries(run_person_tests
                      ${PROJECT_LINK_LIBS} gtest gtest_main
                      -pthread)
