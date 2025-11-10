cmake_minimum_required(VERSION 3.13)

project(locking C)

file(GLOB_RECURSE SOURCE_FILES src/*.h src/*.c)

add_executable(locking ${SOURCE_FILES})