//
// Created by babou on 20/01/17.
//

#ifndef GGJ2017_MAP_H
#define GGJ2017_MAP_H

# define    MAP_SIZE    21

#include    <array>
#include    <list>
#include    "Display/SfmlSpriteHandler.hpp"

enum    typeMap {
    ROAD = 0,
    WALL = 1,
    TOWER = 2,
    BORDER_CASTLE = 8,
    CASTLE = 9
};

class Map {
public:
    Map();
    ~Map();

    void    initWorld();
    void    placeTower(); // Will get tower list &

    const std::array<std::array<typeMap, MAP_SIZE>, MAP_SIZE> &getMap() const;
    const SfmlSpriteHandler &getGround() const;
    const SfmlSpriteHandler &getWall() const;
    void setPositionWall(float, float);
    void setPositionGround(float, float);

private:
    std::array<std::array<typeMap, MAP_SIZE>, MAP_SIZE>     _map;
    int     _towers;
    SfmlSpriteHandler _wall;
    SfmlSpriteHandler _ground;
};

#endif //GGJ2017_MAP_H
