//
// Created by wasta-geek on 21/01/17.
//

#include <Monsters/Soldier.hpp>
#include "Wave.hpp"

Wave::Wave(Map *map, waveType type, float startTime, enum side sideToSpawn) : _sideToSpawn(sideToSpawn), _startTime(startTime), _timeSinceLastSpawn(0)
{
    _map = map;
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
    auto map = _map->getMap();;
    unsigned randomTile = (std::rand() % (MAP_SIZE / 2)) * 2 + TILE_SIZE / 2;

    if (this->_sideToSpawn == SOUTH || this->_sideToSpawn == NORTH)
    {
        unsigned    y = this->_sideToSpawn == SOUTH ? MAP_SIZE : 0;
        //float       offset = this->_sideToSpawn == SOUTH ? TILE_SIZE / 2 : -TILE_SIZE / 2;

        toPlace->setPosition(randomTile + TILE_SIZE / 2, y);
    }
    else
    {
        unsigned    x = this->_sideToSpawn == EAST ? MAP_SIZE : 0;
        //float       offset = this->_sideToSpawn == EAST ?
        toPlace->setPosition(x, randomTile + TILE_SIZE / 2);
    }
}