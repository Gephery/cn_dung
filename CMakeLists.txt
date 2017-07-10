cmake_minimum_required( VERSION 3.6 )
project( code_name )

set( CMAKE_CXX_STANDARD 11 )
set( SOURCE_FILES main.cpp )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_executable( code_name main.cpp
  include/model_data.h
  src/mob/mob.cpp
  src/mob/mob.h
  src/items/item.cpp
  src/mob/mob_manager.cpp
  src/mob/mob_manager.h
  src/windowing/winda.cpp
  src/windowing/winda.h
  src/windowing/fonter.h
  src/windowing/fonter.cpp
  src/windowing/base_box.cpp
  src/windowing/base_box.h
  src/windowing/box_types/layer.cpp
  src/windowing/box_types/box_of_text.cpp
  src/windowing/box_types/sprite_area.cpp
  src/windowing/texture_manager.cpp
  src/windowing/boxxer.h
  src/windowing/boxxer.cpp
  src/events/info_packet.cpp
  src/events/info_packet.h
  src/events/main_info_manager.cpp
  src/events/handy.h
  src/windowing/box_types/layer.h
  src/windowing/box_types/box_of_text.h
  src/windowing/box_types/sprite_area.h
  src/windowing/box_types.h
  src/windowing/texture_manager.h
  src/events/built_in_packets/click_packet.h src/events/built_in_packets/click_packet.cpp src/events/built_in_handlers/default_handlers.cpp src/events/built_in_handlers/default_handlers.h src/events/handy_handler.cpp src/events/handy_handler.h src/windowing/box_types/button.cpp src/windowing/box_types/button.h src/windowing/enums_fonter.h src/flat_buffers/main.cpp)


IF ( APPLE )
    TARGET_LINK_LIBRARIES(
                            code_name
                            /Library/Frameworks/SDL2.framework
                            /Library/Frameworks/SDL2_image.framework
                            /Library/Frameworks/SDL2_ttf.framework
                          )
ENDIF()
