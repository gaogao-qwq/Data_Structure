cmake_minimum_required(VERSION 3.23)
project(Cpp_Data_Structure)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Headers)

FILE(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Sources *.c *.cpp)
foreach(source ${SOURCE_FILES})
    get_filename_component(name ${source} NAME)
    add_executable(${name} ${source})
endforeach()
