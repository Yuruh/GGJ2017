//
// Created by babou on 20/01/17.
//

#ifndef GGJ2017_MAP_H
#define GGJ2017_MAP_H

#include    <array>
#include    <list>
#include    "Display/SfmlSpriteHandler.hpp"

# define    MAP_SIZE    21
# define    TILE_SIZE   40

enum    typeMap {
    ROAD = 0,
    WALL = 1,
    TOWER = 2,
    BLOCK = 3,
    BORDER_CASTLE = 8,
    CASTLE = 9
};

class Map {
public:
    Map();
    ~Map();

    void    initWorld();
    void    placeTower(); // Will get tower list &

    inline const std::array<std::array<typeMap, MAP_SIZE>, MAP_SIZE> &getMap() const { return _map; };
    inline const SfmlSpriteHandler &getGround() const { return _ground; };
    inline const SfmlSpriteHandler &getWall() const { return _wall; };
    inline const SfmlSpriteHandler &getBlock() const { return _block;};

    inline void setPositionWall(float x, float y) { _wall.setPosition(x, y); };
    inline void setPositionGround(float x, float y) { _ground.setPosition(x, y); };
    inline void setPositionBlock(float x, float y) { _block.setPosition(x, y); };
    inline void setType(int y, int x, typeMap type) { _map[y][x] = type; };

private:
    std::array<std::array<typeMap, MAP_SIZE>, MAP_SIZE>     _map;
    int     _towers;
    SfmlSpriteHandler _wall;
    SfmlSpriteHandler _ground;
    SfmlSpriteHandler _block;
public:

    void set_block(const SfmlSpriteHandler &_block);
};

#endif //GGJ2017_MAP_H
