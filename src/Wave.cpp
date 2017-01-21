//
// Created by wasta-geek on 21/01/17.
//

#include <Monsters/Soldier.hpp>
#include <iostream>
#include "Wave.hpp"

Wave::Wave(Map *map, waveType type, float startTime, enum side sideToSpawn) : _sideToSpawn(sideToSpawn), _startTime(startTime), _timeSinceLastSpawn(0)
{
    (void)map;
    switch (type)
    {
        case BASIC:
            _monsters.push_back(new Soldier);
            _monsters.push_back(new Soldier);
            _monsters.push_back(new Soldier);
            _monsters.push_back(new Soldier);
            break;
        case FAST:
            break;
        case TANK:
            break;
        case DPS:
            break;
        case MAGICIAN:
            break;
        case BOSS:
            break;
    }
}

Wave::~Wave()
{}

const float& Wave::getStartTime() const
{ return this->_startTime; }


Monster* Wave::spawnNextMonster(float &deltatTime)
{
    if (_monsters.size() == 0)
        return NULL;
    Monster *toDelete = _monsters.front();
    this->putMonster(toDelete);
    _monsters.erase(_monsters.begin());
    return toDelete;
}

unsigned long Wave::getSize() const
{ return _monsters.size(); }

bool Wave::isSpawnReady()
{
    return this->_timeSinceLastSpawn >= INTERVAL_SPAWN;
}

void Wave::updateTime(const float &deltaTime)
{
    this->_timeSinceLastSpawn += deltaTime;
}

void Wave::putMonster(Monster *toPlace)
{
    if (this->_sideToSpawn == SOUTH || this->_sideToSpawn == NORTH)
    {
        int random = std::rand() % (MAP_X / 2);
        int randomTile = (random * 2 + 1) % MAP_X;
        unsigned    y = this->_sideToSpawn == SOUTH ? MAP_Y - 1 : 0;
        //float       offset = this->_sideToSpawn == SOUTH ? TILE_SIZE / 2 : -TILE_SIZE / 2;

        //std::cout << "PLACER EN :" << randomTile << "||" << y << std::endl;
        toPlace->setPosition(randomTile, y);
    }
    else
    {
        int random = std::rand() % (MAP_Y / 2);
        int randomTile = (random * 2 + 1) % MAP_Y;
        unsigned    x = this->_sideToSpawn == EAST ? MAP_X - 1 : 0;
        //float       offset = this->_sideToSpawn == EAST ?
        //std::cout << "PLACER EN [2] :" << x << "||" << randomTile << std::endl;
        toPlace->setPosition(x, randomTile);
    }
}