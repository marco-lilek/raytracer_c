cmake_minimum_required(VERSION 3.10)

option(CGLM_USE_C99 "" OFF) # C11 

project(raytracer)

add_executable(raytracer src/main.c)

add_library(deps STATIC src/image.c)

add_library(sclog4c STATIC external/sclog4c/src/sclog4c.c)
add_library(lodepng STATIC external/lodepng/lodepng.c)

target_link_libraries(raytracer deps cglm sclog4c lodepng)

add_subdirectory(external/cglm/)

include_directories(BEFORE SYSTEM external/cglm/include/)
include_directories(BEFORE SYSTEM external/sclog4c/include/)
include_directories(BEFORE SYSTEM external/lodepng/)
include_directories(AFTER include/)

