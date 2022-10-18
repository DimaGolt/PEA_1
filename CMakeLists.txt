cmake_minimum_required(VERSION 3.23)
project(PEA_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(PEA_1 main.cpp src/Parser.cpp include/Parser.h src/Path.cpp include/Path.h src/Matrix.cpp include/Matrix.h src/Settings.cpp include/Settings.h src/Stopwatch.cpp include/Stopwatch.h)
