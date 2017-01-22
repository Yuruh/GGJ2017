//
// Created by wasta-geek on 21/01/17.
//

#include "Walls/Wall.hpp"
#include <iostream>

Wall::Wall(int y, int x) : _timeSinceCreated(0.0)
{
    _pos.first = x;
    _pos.second = y;
}

Wall::~Wall()
{}

void Wall::update(float &deltaTime)
{
    this->_timeSinceCreated += deltaTime;
}