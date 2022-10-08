cmake_minimum_required(VERSION 3.23)
project(Stack)

set(CMAKE_CXX_STANDARD 14)

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach(file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
endforeach()
