cmake_minimum_required(VERSION 3.11)
project(vecDB)

#显示make命令
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -g -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")
set(CMAKE_C_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")

include_directories(${PROJECT_SOURCE_DIR}/apps/include)
link_directories(${PROJECT_SOURCE_DIR}/apps/lib)

file(GLOB HTTPLIB ${PROJECT_SOURCE_DIR}/src/base/*.cc)

file(GLOB LIB_SRC ${PROJECT_SOURCE_DIR}/src/*.cc ${PROJECT_SOURCE_DIR}/src/*.h)

add_library(vec SHARED ${LIB_SRC} ${HTTPLIB})
TARGET_LINK_LIBRARIES(vec libfaiss.a librocksdb.a)


add_executable(test test/test.cc)
add_dependencies(test vec)
target_link_libraries(test vec libfaiss.a librocksdb.a)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
