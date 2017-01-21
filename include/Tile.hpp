//
// Created by yuruh on 21/01/17.
//

#ifndef GGJ2017_TILE_HPP
#define GGJ2017_TILE_HPP


#include <cstdlib>
#include <list>

enum    typeMap {
    ROAD = 0,
    WALL = 1,
    TOWER = 2,
    BLOCK = 3,
    BORDER_CASTLE = 8,
    CASTLE = 9
};

struct Tile
{
public:
    Tile() : visited(false), dist(0) {}
    ~Tile() {}

    bool operator==(typeMap) const;
    Tile& operator=(typeMap);
    typeMap type;
    bool    visited;
    int dist;
    Tile        *prev;
    std::list<Tile*>    links;
    int     x;
    int     y;
};


#endif //GGJ2017_TILE_HPP
