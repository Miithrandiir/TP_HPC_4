cmake_minimum_required(VERSION 3.21)
project(TP4)

set(CMAKE_CXX_STANDARD 14)

add_definitions(-O2)
add_subdirectory(exercice3)

add_executable(TP4.1 hpcOpenmpSchedule.cpp)
add_executable(TP4.2 exercice2.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(TP4.1 PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(TP4.2 PUBLIC OpenMP::OpenMP_CXX)
endif()

