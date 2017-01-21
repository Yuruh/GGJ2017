//
// Created by wasta-geek on 20/01/17.
//

#include <iostream>
#include "Monsters/Monster.hpp"

Monster::Monster(unsigned hp, unsigned atkValue, float atkSpeed, float moveSpeed) : ActiveElement(hp, atkSpeed), _atkValue(atkValue), _moveSpeed(moveSpeed)
{
    _t = 0;
    _counter = 0;
    pos.first = 0;
    pos.second = 0;
    dir.first = 0;
    dir.second = 1;
}

Monster::~Monster()
{}

void Monster::move(unsigned &y, unsigned &x)
{
    this->_pos = {y, x};
}

void Monster::update(float &deltaTime)
{
    _t += deltaTime;
    if (this->_t > this->_refreshRate)
    {
        if (_counter < this->sprites.size() - 1)
            _counter++;
        else
            _counter = 0;
        _t = 0;
    }
//    todo : normaliser ? Pas besoin si pas diagonale
    float movingValue = this->_moveSpeed * deltaTime * 40;
    ASpritesHandler::move(movingValue * dir.first, movingValue * dir.second);
}

float& Monster::getMoveSpeed()
{ return this->_moveSpeed; }

void Monster::setMoveSpeed(float &moveSpeed)
{
    this->_moveSpeed = moveSpeed;
}

unsigned int& Monster::getAtkValue()
{ return this->_atkValue; }


void Monster::setAtkValue(unsigned &atkValue)
{
    this->_atkValue = atkValue;
}

void Monster::attack(ActiveElement &target)
{
    target.takeDmg(this->_atkValue);
}

void Monster::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    if (this->_counter < this->sprites.size() && this->_counter >= 0)
        target.draw(this->sprites[this->_counter]);

}