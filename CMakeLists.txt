cmake_minimum_required(VERSION 3.0.0)

project(RTML)
file(GLOB SOURCES sources/*.c)

add_executable(RTML ${SOURCES})
