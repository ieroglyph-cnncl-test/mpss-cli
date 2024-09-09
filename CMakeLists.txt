cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -g -Wall -Wpedantic")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -Wall -Werror -Wpedantic")

include(cmake/CPM.cmake)

CPMAddPackage("gh:fmtlib/fmt#11.0.2")
CPMAddPackage("gh:ieroglyph-cnncl-test/mpss-lib#0.3.0")
CPMAddPackage(
  NAME cxxopts
  GITHUB_REPOSITORY jarro2783/cxxopts
  VERSION 3.2.0
  OPTIONS
    "CXXOPTS_BUILD_EXAMPLES Off"
    "CXXOPTS_BUILD_TESTS Off"
)

project(mpsscli LANGUAGES CXX)
add_executable(mpsscli src/main.cpp)

file(GLOB_RECURSE SOURCES "src/*")
file(GLOB_RECURSE HEADERS "include/*")

target_sources(mpsscli PRIVATE ${SOURCES} PUBLIC ${HEADERS})

target_include_directories(mpsscli PUBLIC "include")
target_link_libraries(mpsscli mpsslib fmt::fmt cxxopts)
