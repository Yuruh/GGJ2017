//
// Created by wasta-geek on 21/01/17.
//

#include "Walls/Wall.hpp"

Wall::Wall() : _timeSinceCreated(0f)
{}

Wall::~Wall()
{}

void Wall::update(float &deltaTime)
{
    this->_timeSinceCreated += deltaTime;
}