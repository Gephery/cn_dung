cmake_minimum_required( VERSION 3.6 )
project( code_name )

set( CMAKE_CXX_STANDARD 11 )
set( SOURCE_FILES main.cpp )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_executable( code_name main.cpp
                src/graphics/sprite.cpp
                include/sprite.h
                include/sprite_data.h
                include/model_data.h
                src/graphics/sprite_back.cpp
                src/mob/mob.cpp src/mob/mob.h
                src/items/item.cpp
                src/items/item.h src/util/m_uuid.cpp
                src/util/m_uuid.h
                src/mob/mob_manager.cpp
                src/mob/mob_manager.h
              )

IF ( APPLE )
    TARGET_LINK_LIBRARIES( code_name /Library/Frameworks/SDL2.framework /Library/Frameworks/SDL2_image.framework )
ENDIF()
