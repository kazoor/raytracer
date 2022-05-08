project(raytracer)
cmake_minimum_required(VERSION 3.6)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} 
                ${SRC_DIR}/main.cpp
                ${SRC_DIR}/util/math/vec3/vec3.h)
