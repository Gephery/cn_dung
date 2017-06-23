cmake_minimum_required( VERSION 3.6 )
project( code_name )

set( CMAKE_CXX_STANDARD 11 )
set( SOURCE_FILES main.cpp )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_executable( code_name main.cpp
                src/graphics/sprite.cpp
                src/graphics/sprite.h
                include/model_data.h
                src/graphics/sprite_back.cpp
                src/mob/mob.cpp src/mob/mob.h
                src/items/item.cpp
                src/mob/mob_manager.cpp
                src/mob/mob_manager.h
                src/windowing/game_winda.cpp
                src/windowing/game_winda.h
                src/windowing/fonter.h
                src/windowing/fonter.cpp
                src/windowing/winda_box.cpp
                src/windowing/winda_box_of_box.cpp
  src/windowing/winda_box_of_text.cpp src/windowing/winda_box_of_sprite.cpp)

IF ( APPLE )
    TARGET_LINK_LIBRARIES(
                            code_name
                            /Library/Frameworks/SDL2.framework
                            /Library/Frameworks/SDL2_image.framework
                            /Library/Frameworks/SDL2_ttf.framework
                          )
ENDIF()
