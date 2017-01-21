//
// Created by babou on 20/01/17.
//

#ifndef GGJ2017_MAP_H
#define GGJ2017_MAP_H

# define    MAP_SIZE    11

#include    <array>

enum    typeMap {
    ROAD = 0,
    WALL = 1,
    TOWER = 2,
    CASTLE = 9
};

class Map {
public:
    Map();
    ~Map();

    void    initWorld();
    void    placeTower();

    const std::array<std::array<typeMap, MAP_SIZE>, MAP_SIZE> &get_map() const;

private:
    std::array<std::array<typeMap, MAP_SIZE>, MAP_SIZE>     _map;
    int     _towers;
};

#endif //GGJ2017_MAP_H
