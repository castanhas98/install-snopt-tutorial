cmake_minimum_required(VERSION 3.16)
project(test_snopt_pagmo)

set(CMAKE_CXX_STANDARD 17)

find_package(pagmo REQUIRED)
find_package(pagmo_plugins_nonfree REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main
	Pagmo::pagmo
	Pagmo_plugins_nonfree::pagmo_plugins_nonfree
)


