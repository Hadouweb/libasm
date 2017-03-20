cmake_minimum_required(VERSION 3.6)
project(libasm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    auteur
    Makefile)

add_executable(libasm ${SOURCE_FILES})