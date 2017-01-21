//
// Created by wasta-geek on 20/01/17.
//

#include "../include/AEntity.hpp"

AEntity::AEntity()
{
    this->_pos = {0, 0};
}

AEntity::~AEntity()
{}

const std::pair<float, float>& AEntity::getPos() const
{ return this->_pos; }

void AEntity::setPos(float &y, float &x)
{
    this->_pos = {y, x};
}