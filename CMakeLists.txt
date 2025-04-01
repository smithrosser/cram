cmake_minimum_required(VERSION 3.20)
project(cram LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_VERSION 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # prevent override of parent project settings
FetchContent_MakeAvailable(googletest) 
include(GoogleTest)
enable_testing()

# CLI option parser
add_subdirectory(third_party/cxxopts)

add_subdirectory(cram)
add_subdirectory(cli)
