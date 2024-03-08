cmake_minimum_required(VERSION 3.0)
project(Genetic-Knapsack)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)

include_directories(include)

add_executable(genetic_knapsack src/main.cpp)

target_include_directories(genetic_knapsack PRIVATE ${Boost_INCLUDE_DIRS})

target_link_libraries(genetic_knapsack ${Boost_LIBRARIES})
