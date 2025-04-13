cmake_minimum_required(VERSION 3.20.0)
project(SorterProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sorter
    main.cpp
    merge_sort.cpp
    quick_sort.cpp
    insertion_sort.cpp
    utils.cpp
)