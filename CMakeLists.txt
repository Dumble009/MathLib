cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(ProjectName MathLib)
set(LibraryName MathLib)
set(ExecutableName MathLibTest)

project(${ProjectName} VERSION 0.1.0)

include("C:/MyLib/CMakeModules/deploy.cmake")

enable_testing()
add_subdirectory(tests)

file(GLOB_RECURSE LIB_SOURCES LIST_DIRECTORIES false RELATIVE "${CMAKE_SOURCE_DIR}" CONFIGURE_DEPENDS "libsources/*.cpp")
file(GLOB_RECURSE EXE_SOURCES LIST_DIRECTORIES false RELATIVE "${CMAKE_SOURCE_DIR}" CONFIGURE_DEPENDS "sources/*.cpp")

add_library(${LibraryName} ${LIB_SOURCES})
add_executable(${ExecutableName} ${EXE_SOURCES})

target_include_directories(${LibraryName} PUBLIC "${CMAKE_SOURCE_DIR}/libsources")

target_include_directories(${ExecutableName} PUBLIC "${CMAKE_SOURCE_DIR}/sources" "${CMAKE_SOURCE_DIR}/libsources")
target_link_directories(${ExecutableName} PUBLIC "${CMAKE_SOURCE_DIR}/build")
target_link_libraries(${ExecutableName} MathLib)

deploy_lib("MathLib" ${LibraryName} ${ProjectName})

add_subdirectory(libsources)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
