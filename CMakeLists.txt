cmake_minimum_required(VERSION 3.16)
project(test_snopt_pagmo)

set(CMAKE_CXX_STANDARD 17)

find_package(pagmo REQUIRED)
find_package(pagmo_plugins_nonfree REQUIRED)

# Building example_1.cpp
add_executable(example_1 example_1.cpp)
target_link_libraries(example_1
	Pagmo::pagmo
	Pagmo_plugins_nonfree::pagmo_plugins_nonfree
)

# Building example_2.cpp
add_executable(example_2 example_2.cpp)
target_link_libraries(example_2
	Pagmo::pagmo
	Pagmo_plugins_nonfree::pagmo_plugins_nonfree
)

# Building example_3.cpp requires more packages to be found.