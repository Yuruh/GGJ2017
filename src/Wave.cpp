//
// Created by wasta-geek on 21/01/17.
//

#include <Monsters/Soldier.hpp>
#include <iostream>
#include <Monsters/FastMob.hpp>
#include <Monsters/TankMob.hpp>
#include <Monsters/DpsMob.hpp>
#include <Monsters/Boss.hpp>
#include "Wave.hpp"

Wave::Wave(Map *map, waveType type, float startTime, enum side sideToSpawn, unsigned nbrToSpawn) : _sideToSpawn(sideToSpawn), _startTime(startTime), _timeSinceLastSpawn(0)
{
    (void)map;
    for (unsigned i = 0;i < nbrToSpawn;i++)
        switch (type)
        {
            case BASIC:
                _monsters.push_back(new Soldier);
                break;
            case FAST:
                _monsters.push_back(new FastMob);
                break;
            case TANK:
                _monsters.push_back(new TankMob);
                break;
            case DPS:
                _monsters.push_back(new DpsMob);
                break;
            case MAGICIAN:
                break;
            case BOSS:
                _monsters.push_back(new Boss);
                break;
        }
}

Wave::~Wave()
{}



Monster* Wave::spawnNextMonster(float &deltaTime)
{
    if (_monsters.size() == 0)
        return NULL;
    Monster *toDelete = _monsters.front();
    this->putMonster(toDelete);
    _monsters.erase(_monsters.begin());
    this->_timeSinceLastSpawn = 0;
    return toDelete;
}


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