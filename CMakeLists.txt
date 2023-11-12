cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
Project(DataAlgorithms)
add_executable(DataAlgorithms 
	src/data_algorithms.cpp
	src/ItemManager.cpp 
	src/Search.cpp
	src/Measurements.hpp
)
