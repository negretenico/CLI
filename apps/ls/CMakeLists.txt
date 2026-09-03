cmake_minimum_required(VERSION 3.28)

#Compiler Options
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_COMPILER_CLANG_SCAN_DEPS /usr/bin/clang-scan-deps-18)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -fuse-ld=lld")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Project name
project(NN_LS)

#Executable
add_executable(NN_LS)
target_sources(NN_LS
  PRIVATE
    main.cpp
)

#Libraries
add_library(Types)
target_sources(Types
  PUBLIC
    FILE_SET CXX_MODULES FILES types/index.cppm)

add_library(CWD)
target_sources(CWD
  PRIVATE
    cwd/index.cpp
  PUBLIC
    FILE_SET CXX_MODULES FILES cwd/index.cppm)




add_library(Filter)
target_sources(Filter
  PRIVATE
    filter/index.cpp
  PUBLIC
    FILE_SET CXX_MODULES FILES filter/index.cppm)

#Link type library 
target_link_libraries(Filter PRIVATE Types)
target_link_libraries(CWD  PRIVATE Types)

#Link the library to the executable
target_link_libraries(NN_LS PRIVATE Filter)
target_link_libraries(NN_LS PRIVATE CWD)
