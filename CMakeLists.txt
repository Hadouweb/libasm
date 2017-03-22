cmake_minimum_required(VERSION 3.6)
project(libasm)

set(CMAKE_CXX_STANDARD 11)
include_directories(includes)

set(SOURCE_FILES
    includes/libfts.h
    main_test.c)

add_executable(libasm ${SOURCE_FILES})