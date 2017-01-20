//
// Created by babou on 20/01/17.
//

#ifndef GGJ2017_MAP_H
#define GGJ2017_MAP_H

# define    MAP_SIZE    11

enum    _type {
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

private:
    int     _map[MAP_SIZE][MAP_SIZE];
    int     _towers;
};

#endif //GGJ2017_MAP_H
