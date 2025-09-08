cmake_minimum_required(VERSION 3.10)
project(PointInPolygon VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(src)
add_subdirectory(mytest)

add_executable(polygon app/main.cpp)

target_link_libraries(polygon PRIVATE geometry graphics)