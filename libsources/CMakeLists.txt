cmake_minimum_required(VERSION 3.14)

project(copy_root)

add_subdirectory(Vector)
add_subdirectory(MathFunctions)

file(GLOB HEADER_FILES "*.h")

message(STATUS "run root")

deploy_headers("MathLib" ${LibraryName})