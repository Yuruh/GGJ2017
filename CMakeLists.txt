cmake_minimum_required(VERSION 3.5)
project(GGJ2017)

include_directories(
        include
        include/Tower)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES
        src/main.cpp

        src/Tower/ATower.cpp include/Tower/ATower.hpp
        src/Tower/BasicTower.cpp include/Tower/BasicTower.hpp
        src/Tower/MagickAttack.cpp include/Tower/MagickAttack.hpp
        src/Tower/Projectile.cpp include/Tower/Projectile.hpp

        src/Map.cpp include/Map.hpp
        src/Display/ASpritesHandler.cpp include/Display/ASpritesHandler.hpp
        src/GameEngine.cpp include/GameEngine.hpp
        src/Core.cpp include/Core.hpp
        src/Display/Display.cpp include/Display/Display.hpp
        src/Monsters/Monster.cpp
        src/Monsters/Soldier.cpp
        src/AEntity.cpp
        src/PassiveElement.cpp
        src/ActiveElement.cpp
        src/Display/TextureManager.cpp include/Display/TextureManager.hpp
        src/Display/SfmlSpriteHandler.cpp
        src/Display/Clickable.cpp
        src/Display/Button.cpp
        src/Walls/Wall.cpp

        include
        src/Tile.cpp include/Tile.hpp src/WaveManager.cpp include/WaveManager.hpp src/Wave.cpp include/Wave.hpp src/Monsters/FastMob.cpp include/Monsters/FastMob.hpp src/Monsters/TankMob.cpp include/Monsters/TankMob.hpp src/Monsters/DpsMob.cpp include/Monsters/DpsMob.hpp src/Monsters/Boss.cpp include/Monsters/Boss.hpp)
add_executable(GGJ2017 ${SOURCE_FILES})


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

