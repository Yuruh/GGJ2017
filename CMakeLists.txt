cmake_minimum_required(VERSION 3.5)
project(GGJ2017)

include_directories(
        include
        include/Tower)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/main.cpp

        src/Tower/ATower.cpp include/Tower/ATower.hpp
        src/Tower/BasicTower.cpp include/Tower/BasicTower.hpp
        src/Tower/MagickAttack.cpp include/Tower/MagickAttack.hpp
        src/Tower/Projectile.cpp include/Tower/Projectile.hpp

        src/Map.cpp include/Map.hpp
        src/ASpritesHandler.cpp include/ASpritesHandler.hpp
        src/GameEngine.cpp include/GameEngine.hpp
        src/Core.cpp include/Core.hpp
        src/Display.cpp include/Display.hpp
        src/Monsters/Monster.cpp
        src/Monsters/Soldier.cpp
        src/AEntity.cpp
        src/PassiveElement.cpp
        src/ActiveElement.cpp
        src/TextureManager.cpp include/TextureManager.hpp
        src/SfmlSpriteHandler.cpp
        )
add_executable(GGJ2017 ${SOURCE_FILES})


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

