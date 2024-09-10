cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/BuildConfig.cmake)
include(cmake/CPM.cmake)

CPMAddPackage("gh:fmtlib/fmt#11.0.2")

if(USE_LOCAL_MPSSLIB)
  add_subdirectory(mpss-lib)
else()
  CPMAddPackage("gh:ieroglyph-cnncl-test/mpss-lib#1.0.0")
endif(USE_LOCAL_MPSSLIB)

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
