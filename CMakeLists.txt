cmake_minimum_required(VERSION 3.0.0)

project(RTML VERSION 0.02)
file(GLOB SOURCES sources/*.c)

add_executable(RTML ${SOURCES})
