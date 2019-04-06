cmake_minimum_required(VERSION 3.12)
project(opencvTest)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)
add_executable(opencvTest main.cpp)

target_link_libraries(opencvTest ${OpenCV_LIBS})