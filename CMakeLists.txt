cmake_minimum_required(VERSION 4.0)
project(Algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(Algorithms
        "Greedy Algorithms/Krushkal.cpp"
        Backtracking/NQueen.cpp
        Backtracking/Hamiltonian.cpp)
