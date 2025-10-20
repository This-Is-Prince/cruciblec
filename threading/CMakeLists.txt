cmake_minimum_required(VERSION 3.13)

project(threading C)

file(GLOB_RECURSE SOURCE_FILES src/*.h src/*.c)

add_executable(threading ${SOURCE_FILES})