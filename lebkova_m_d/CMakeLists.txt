cmake_minimum_required (VERSION 3.8)

project ("lebkova_m_d")

include_directories(geom)

add_subdirectory(geom)

add_executable(lebkova_m_d geometry_test.cpp)

target_link_libraries(lebkova_m_d geom)


