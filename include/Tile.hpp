//
// Created by yuruh on 21/01/17.
//

#ifndef GGJ2017_TILE_HPP
#define GGJ2017_TILE_HPP


#include <cstdlib>

enum    typeMap {
    ROAD = 0,
    WALL = 1,
    TOWER = 2,
    BLOCK = 3,
    BORDER_CASTLE = 8,
    CASTLE = 9
};

class Tile
{
public:
    Tile() : visited(false), dist(0) {}
    ~Tile() {}

    bool operator==(typeMap) const;
    Tile& operator=(typeMap);

private:
    typeMap type;
    bool    visited;
    unsigned dist;
};


#endif //GGJ2017_TILE_HPP
