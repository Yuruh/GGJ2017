cmake_minimum_required(VERSION 3.0)
project(GGJ2017)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/tower-maze.cpp Enemy.cpp Enemy.hpp ASpritesHandler.hpp ASpritesHandler.cpp GameEngine.cpp GameEngine.hpp Window.cpp Window.hpp Core.cpp Core.hpp Display.cpp Display.hpp)
add_executable(GGJ2017 ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

