cmake_minimum_required( VERSION 3.6 )
project( code_name )

set( CMAKE_CXX_STANDARD 11 )
set( SOURCE_FILES main.cpp )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_executable( code_name main.cpp
  include/model_data.h
  src/mob/mob.cpp src/mob/mob.h
                src/items/item.cpp
                src/mob/mob_manager.cpp
                src/mob/mob_manager.h
  src/windowing/winda.cpp
  src/windowing/winda.h
                src/windowing/fonter.h
                src/windowing/fonter.cpp
  src/windowing/base_box.cpp
  src/windowing/box_of_box.cpp
  src/windowing/box_of_text.cpp src/windowing/box_of_sprite.cpp src/windowing/texture_manager.cpp src/windowing/boxxer.cpp)

IF ( APPLE )
    TARGET_LINK_LIBRARIES(
                            code_name
                            /Library/Frameworks/SDL2.framework
                            /Library/Frameworks/SDL2_image.framework
                            /Library/Frameworks/SDL2_ttf.framework
                          )
ENDIF()
