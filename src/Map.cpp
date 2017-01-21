//
// Created by babou on 20/01/17.
//

#include    "../include/Map.hpp"
#include    <fstream>
#include    <iostream>
#include    <stdlib.h>
#include    <time.h>

Map::Map()
{
    for (int j = 0; j < MAP_SIZE; j += 1)
        for (int i = 0; i < MAP_SIZE; i += 1)
            _map[j][i] = ROAD;
    _towers = MAP_SIZE;
}

Map::~Map()
{
}

void        Map::initWorld()
{
    // Build wall
    for (int j = 0; j < MAP_SIZE; j += 1)
        for (int i = 0; i < MAP_SIZE; i += 1)
            if (i % 2 == 0 && j % 2 == 0)
                _map[j][i] = WALL;

    // Build castle
    _map[(MAP_SIZE - 2) / 2][(MAP_SIZE - 2) / 2] = CASTLE;
    _map[(MAP_SIZE - 2) / 2][(MAP_SIZE - 1) / 2] = CASTLE;
    _map[(MAP_SIZE - 2) / 2][(MAP_SIZE + 1) / 2] = CASTLE;

    _map[(MAP_SIZE - 1) / 2][(MAP_SIZE - 2) / 2] = CASTLE;
    _map[(MAP_SIZE - 1) / 2][(MAP_SIZE - 1) / 2] = CASTLE;
    _map[(MAP_SIZE - 1) / 2][(MAP_SIZE + 1) / 2] = CASTLE;

    _map[(MAP_SIZE + 1) / 2][(MAP_SIZE - 2) / 2] = CASTLE;
    _map[(MAP_SIZE + 1) / 2][(MAP_SIZE - 1) / 2] = CASTLE;
    _map[(MAP_SIZE + 1) / 2][(MAP_SIZE + 1) / 2] = CASTLE;


    // Build tower
    srand(time(NULL));
    placeTower();

    for (int j = 0; j < MAP_SIZE; j += 1)
    {
        for (int i = 0; i < MAP_SIZE; i += 1)
            std::cout << _map[j][i] << " ";
        std::cout << std::endl;
    }
}

void        Map::placeTower()
{
    int     j = rand() % MAP_SIZE + 1;
    int     i = rand() % MAP_SIZE + 1;

    if (_map[j][i] == 0 &&
        _map[j - 1][i - 1] != TOWER && _map[j][i - 1] != TOWER && _map[j + 1][i - 1] != TOWER &&
        _map[j - 1][i] != TOWER && _map[j][i] != TOWER && _map[j + 1][i] != TOWER &&
        _map[j - 1][i + 1] != TOWER && _map[j][i + 1] != TOWER && _map[j + 1][i + 1] != TOWER)
    {
        _map[j][i] = TOWER;
        _towers -= 1;
    }

    if (_towers > 0)
        placeTower();
}