file(GLOB GRAPHICS_SOURCES private/*.cpp)

add_library(graphics ${GRAPHICS_SOURCES})

target_include_directories(graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/public)

target_link_libraries(graphics PUBLIC geometry)