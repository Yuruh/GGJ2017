//
// Created by wasta-geek on 20/01/17.
//

#include "../include/AEntity.hpp"

AEntity::AEntity()
{
    this->_pos = {0.0f, 0.0f};
}

AEntity::~AEntity()
{}

const std::pair<float, float>& AEntity::getPos() const
{ return this->_pos; }

void AEntity::setPos(float &y, float &x)
{
    this->_pos = {y, x};
}

void AEntity::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    if (this->sprites.size() > 0)
        target.draw(this->sprites[0]);
}
