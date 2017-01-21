//
// Created by babou on 20/01/17.
//

#include    "Map.hpp"
#include    "TextureManager.hpp"
#include    <iostream>
#include    <cstdlib>
#include    <ctime>

Map::Map() : _wall(TextureManager::get(TextureManager::WALL)),
             _ground(TextureManager::get(TextureManager::GROUND))
{
    for (int j = 0; j < MAP_SIZE; j += 1)
        for (int i = 0; i < MAP_SIZE; i += 1)
            _map[j][i] = ROAD;
    _towers = MAP_SIZE;
}

Map::~Map()
{
}

void        Map::initWorld() {
    // Build wall
    for (int j = 0; j < MAP_SIZE; j += 1)
        for (int i = 0; i < MAP_SIZE; i += 1)
            if (i % 2 == 0 && j % 2 == 0)
                _map[j][i] = WALL;

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


    // Build tower
    srand(time(0));
    placeTower();
}

void        Map::placeTower()
{
    int j = rand() % MAP_SIZE + 1;
    int i = rand() % MAP_SIZE + 1;

    if (_map[j][i] == 0 &&
        _map[j - 1][i - 1] != TOWER && _map[j][i - 1] != TOWER && _map[j + 1][i - 1] != TOWER &&
        _map[j - 1][i] != TOWER && _map[j][i] != TOWER && _map[j + 1][i] != TOWER &&
        _map[j - 1][i + 1] != TOWER && _map[j][i + 1] != TOWER && _map[j + 1][i + 1] != TOWER) {
        _map[j][i] = TOWER;
        _towers -= 1;
    }

    if (_towers > 0)
        placeTower();
}

const std::array<std::array<typeMap, MAP_SIZE>, MAP_SIZE> &Map::getMap() const {
    return _map;
}

const SfmlSpriteHandler &Map::getWall() const {
    return _wall;
}

const SfmlSpriteHandler &Map::getGround() const {
    return _ground;
}

void    Map::setPositionWall(float x, float y)
{
    _wall.setPosition(x, y);
}

void    Map::setPositionGround(float x, float y)
{
    _ground.setPosition(x, y);
}

