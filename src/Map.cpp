//
// Created by babou on 20/01/17.
//

#include    "Map.hpp"
//#include    "ATower.hpp"
#include    "Display/TextureManager.hpp"

#include    <iostream>
#include    <cstdlib>
#include    <ctime>

Map::Map() : _wall(TextureManager::get(TextureManager::WALL)),
             _ground(TextureManager::get(TextureManager::GROUND)),
             _block(TextureManager::get(TextureManager::BLOCK))
{
    _towers = MAP_SIZE;

    this->initWorld();
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
            else
                _map[j][i] = ROAD;

    // Build castle
    _map[(MAP_SIZE - 2) / 2][(MAP_SIZE - 2) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE - 2) / 2][(MAP_SIZE - 1) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE - 2) / 2][(MAP_SIZE + 1) / 2] = BORDER_CASTLE;

    _map[(MAP_SIZE - 1) / 2][(MAP_SIZE - 2) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE - 1) / 2][(MAP_SIZE - 1) / 2] = CASTLE;
    _map[(MAP_SIZE - 1) / 2][(MAP_SIZE + 1) / 2] = BORDER_CASTLE;

    _map[(MAP_SIZE + 1) / 2][(MAP_SIZE - 2) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE + 1) / 2][(MAP_SIZE - 1) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE + 1) / 2][(MAP_SIZE + 1) / 2] = BORDER_CASTLE;
}

void        Map::placeTower() // Will get tower list &
{
    int j = rand() % MAP_SIZE;
    int i = rand() % MAP_SIZE;

    if (_map[j][i] == WALL)
    {
        _map[j][i] = TOWER;
        _towers -= 1;
    }

    if (_towers > 0)
        placeTower();
}

