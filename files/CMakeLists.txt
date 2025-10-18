cmake_minimum_required(VERSION 3.13)

project(files C)

file(GLOB_RECURSE SOURCE_FILES src/*.h src/*.c)

add_executable(files ${SOURCE_FILES})