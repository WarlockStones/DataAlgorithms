cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
Project(DataAlgorithms)
add_executable(DataAlgorithms 
	"src/EntryPoint.cpp" "src/ItemManager.cpp" "src/Search.cpp" "src/Measurements.hpp" "src/Tree.hpp" "src/Tree.cpp" "src/Node.hpp" "src/Node.cpp" "src/Graph.cpp" "src/Map.cpp" "src/HashMap.cpp" "src/"
 "src/HashMap.cpp" "src/GraphGUI.cpp" "src/AStar.cpp")
