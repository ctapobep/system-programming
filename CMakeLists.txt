cmake_minimum_required(VERSION 3.6)
project(main)

#add_definitions(-std=c++11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})

include_directories(src/rsa)
add_subdirectory(src/rsa)
add_subdirectory(test)

target_link_libraries(main rsa)

