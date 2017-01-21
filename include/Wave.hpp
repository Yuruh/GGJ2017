//
// Created by wasta-geek on 21/01/17.
//

#ifndef GGJ2017_WAVE_HPP
#define GGJ2017_WAVE_HPP

#include <Monsters/Monster.hpp>
#include "Map.hpp"

#define INTERVAL_SPAWN      0.5f

enum side { WEST, EAST, NORTH, SOUTH };

enum waveType { BASIC, FAST, TANK, DPS, MAGICIAN, BOSS};

class Wave
{
public:
    Wave(Map *map, waveType type, float startTime, enum side);
    ~Wave();
    Monster*            spawnNextMonster(float&);
    bool                isSpawnReady();
    void                updateTime(const float&);

    inline float        getStartTime() const { return this->_startTime; }
    inline unsigned long    getSize() const { return _monsters.size(); }

private:
   void                 putMonster(Monster*);

    std::list<Monster*> _monsters;
    side                _sideToSpawn;
    float               _startTime;
    float               _timeSinceLastSpawn;
    Map                 *_map;
};


#endif //GGJ2017_WAVE_HPP
