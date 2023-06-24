cmake_minimum_required(VERSION 3.13)  # CMake version check
project(CSC_211_Project)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp)

add_executable(CSC_211_Project main.cpp gradebook.cpp)