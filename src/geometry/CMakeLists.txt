file(GLOB GEOMETRY_SOURCES private/*.cpp)

add_library(geometry ${GEOMETRY_SOURCES})

target_include_directories(geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/public)