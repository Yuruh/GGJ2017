//
// Created by wasta-geek on 21/01/17.
//

#ifndef GGJ2017_WAVE_HPP
#define GGJ2017_WAVE_HPP

#include <Monsters/Monster.hpp>
#include "Map.hpp"

#define INTERVAL_SPAWN      0.1f

enum side { WEST, EAST, NORTH, SOUTH };

enum waveType { BASIC, FAST, TANK, DPS, MAGICIAN, BOSS};

class Wave
{
public:
    Wave(Map *map, waveType type, float startTime, enum side);
    ~Wave();
    const float         &getStartTime() const;
    Monster*            spawnNextMonster(float&);
    unsigned long       getSize() const;
    bool                isSpawnReady();
    void                updateTime(const float&);
private:
   void                 putMonster(Monster*);

    std::list<Monster*> _monsters;
    side                _sideToSpawn;
    float               _startTime;
    float               _timeSinceLastSpawn;
    Map                 *_map;
};


#endif //GGJ2017_WAVE_HPP
