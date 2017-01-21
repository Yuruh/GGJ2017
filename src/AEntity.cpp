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

std::pair<unsigned, unsigned>& AEntity::getPos()
{ return this->_pos; }