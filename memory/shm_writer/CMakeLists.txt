cmake_minimum_required(VERSION 3.13)

project(shm_writer C)

file(GLOB_RECURSE SOURCE_FILES src/*.h src/*.c)

add_executable(shm_writer ${SOURCE_FILES})