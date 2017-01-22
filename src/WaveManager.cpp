//
// Created by wasta-geek on 21/01/17.
//

#include <Core.hpp>
#include "WaveManager.hpp"

WaveManager::WaveManager() : _timeSinceBeginning(0.0f)
{}

WaveManager::~WaveManager()
{}

void WaveManager::updateWaves(float &deltaTime)
{
//    if (this->_waves.empty())
//    {
//        g_monsters = 424242;
//        return;
//    }
    _timeSinceBeginning += deltaTime;
    std::list<Wave *> toDelete;

    for (auto it = _waves.begin(); it != _waves.end(); it++) {
        (*it)->updateTime(deltaTime);
        if ((*it)->getStartTime() < _timeSinceBeginning && (*it)->isSpawnReady()) {
            Core::getInstance().addMonster((*it)->spawnNextMonster(deltaTime));
            if ((*it)->getSize() == 0)
                toDelete.push_back((*it));
        }
    }
    for (auto it = toDelete.begin(); it != toDelete.end(); it++)
        _waves.remove(*it);
}

void WaveManager::init(Map *map)
{
    enum side sideToSpawn = static_cast<enum side>(std::rand() % 4);
    _waves.push_back(new Wave(map, BASIC, 0.0f, sideToSpawn, 4));

    sideToSpawn = static_cast<enum side>(std::rand() % 4);
    _waves.push_back(new Wave(map, BASIC, 10.0f, sideToSpawn, 8));


//
    sideToSpawn = static_cast<enum side>(std::rand() % 4);
    _waves.push_back(new Wave(map, FAST, 20.0f, sideToSpawn, 6));
//
    sideToSpawn = static_cast<enum side>(std::rand() % 4);
    _waves.push_back(new Wave(map, DPS, 30.0f, sideToSpawn, 3));
    //_waves.push_back(new Wave(map, MAGICIAN, 55.0f, sideToSpawn));
//
   sideToSpawn = static_cast<enum side>(std::rand() % 4);
    _waves.push_back(new Wave(map, TANK, 40.0f/*65.0f*/, sideToSpawn, 4));

    sideToSpawn = static_cast<enum side>(std::rand() % 4);
    _waves.push_back(new Wave(map, FAST, 60.0f, sideToSpawn, 4));

    sideToSpawn = static_cast<enum side>(std::rand() % 4);
    _waves.push_back(new Wave(map, BOSS, 80.0f, sideToSpawn, 2));
}

bool WaveManager::isOver() const
{
    return this->_waves.empty();
}
