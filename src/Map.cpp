//
// Created by babou on 20/01/17.
//

#include    "Map.hpp"
#include    "BasicTower.hpp"
#include    "Monsters/Monster.hpp"
#include    "Display/TextureManager.hpp"

#include    <iostream>
#include    <cstdlib>
#include    <ctime>

Map::Map() : _wall(TextureManager::get(TextureManager::WALL)),
             _ground(TextureManager::get(TextureManager::GROUND)),
             _block(TextureManager::get(TextureManager::BLOCK)),
             _castle(TextureManager::get(TextureManager::CASTLE))
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
    for (int y = 0; y < MAP_SIZE; y += 1)
        for (int x = 0; x < MAP_SIZE; x += 1)
            if (y % 2 == 0 && x % 2 == 0)
              _map[y][x] = WALL;
            else
                _map[y][x] = ROAD;

    // Build castle
    _map[(MAP_SIZE - 2) / 2][(MAP_SIZE - 2) / 2] = CASTLE;
    _map[(MAP_SIZE - 2) / 2][(MAP_SIZE - 1) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE - 2) / 2][(MAP_SIZE + 1) / 2] = BORDER_CASTLE;

    _map[(MAP_SIZE - 1) / 2][(MAP_SIZE - 2) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE - 1) / 2][(MAP_SIZE - 1) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE - 1) / 2][(MAP_SIZE + 1) / 2] = BORDER_CASTLE;

    _map[(MAP_SIZE + 1) / 2][(MAP_SIZE - 2) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE + 1) / 2][(MAP_SIZE - 1) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE + 1) / 2][(MAP_SIZE + 1) / 2] = BORDER_CASTLE;

    setPositionCastle(((MAP_SIZE - 2) / 2) * TILE_SIZE, ((MAP_SIZE - 2) / 2) * TILE_SIZE);
}

void        Map::placeTower(std::list<ATower*> &towers, std::list<Monster*> &monsters)
{
    int y = rand() % MAP_SIZE;
    int x = rand() % MAP_SIZE;

    if (_map[y][x] == WALL)
    {
        _map[y][x] = TOWER;
        towers.push_back(new BasicTower((x - 1) * TILE_SIZE, (y - 1) * TILE_SIZE, 10, 10, 5, 5.0, nullptr, nullptr, monsters));
        towers.back()->setPosition((y - 1) * TILE_SIZE, (x - 2) * TILE_SIZE);
        towers.back()->setProportionalSize(100, 100);
        std::cout << "place tower :" << towers.size() << std::endl;
        _towers -= 1;
    }

    if (_towers > 0)
        placeTower(towers, monsters);
}

