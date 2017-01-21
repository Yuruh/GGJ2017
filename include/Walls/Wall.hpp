//
// Created by wasta-geek on 21/01/17.
//

#ifndef GGJ2017_WALL_HPP
#define GGJ2017_WALL_HPP

#include "PassiveElement.hpp"

#define WALL_DURATION   2.0f

class Wall : public APassiveElement
{
public:
    Wall();
    virtual ~Wall();
    void update(float&);
private:
    float _timeSinceCreated;
};


#endif //GGJ2017_WALL_HPP
