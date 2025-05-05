cmake_minimum_required(VERSION 3.20)
project(KnapsackSolver)

# 設定 C++ 標準
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含頭文件資料夾
include_directories(${CMAKE_SOURCE_DIR}/include)

# 加入所有 algorithms 中的 cpp 檔案
file(GLOB ALGO_SOURCES ${CMAKE_SOURCE_DIR}/code/algorithms/*.cpp)

# 加入主程式
set(MAIN_SOURCE ${CMAKE_SOURCE_DIR}/code/main.cpp)

# 建立執行檔
add_executable(knapsack_solver ${MAIN_SOURCE} ${ALGO_SOURCES})

# 加入編譯器警告設定（僅限 GCC / Clang）
if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(knapsack_solver PRIVATE -Wall -Wextra -Wpedantic)
endif()
