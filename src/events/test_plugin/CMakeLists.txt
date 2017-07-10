cmake_minimum_required( VERSION 3.6 )
project( test_plugin )

set( CMAKE_CXX_STANDARD 11 )
set( SOURCE_FILES main.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_executable( test_plugin ../main_info_manager.cpp
  ../info_packet.cpp ../info_packet.h main.cpp)

