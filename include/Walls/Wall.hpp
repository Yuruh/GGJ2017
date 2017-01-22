//
// Created by wasta-geek on 21/01/17.
//

#ifndef GGJ2017_WALL_HPP
#define GGJ2017_WALL_HPP

#include "PassiveElement.hpp"

#define WALL_DURATION   5.0

class Wall : public PassiveElement
{
public:
    Wall(int, int);
    virtual ~Wall();
    void update(float&);

    inline float    getTimeSinceCreated() const { return _timeSinceCreated; };
    inline int      getY() const { return _pos.second; };
    inline int      getX() const { return _pos.first; };

private:
    std::pair<int, int> _pos;
    float _timeSinceCreated;
};


#endif //GGJ2017_WALL_HPP
