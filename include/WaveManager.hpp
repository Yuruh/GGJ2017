//
// Created by wasta-geek on 21/01/17.
//

#ifndef GGJ2017_WAVEMANAGER_HPP
#define GGJ2017_WAVEMANAGER_HPP

#include "Map.hpp"
#include "Wave.hpp"

class WaveManager
{
public:
    WaveManager();
    ~WaveManager();
    void updateWaves(float&);
    void init(Map*);
private:
    std::list<Wave*>    _waves;
    float               _timeSinceBeginning;
};


#endif //GGJ2017_WAVEMANAGER_HPP
