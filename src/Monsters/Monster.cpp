//
// Created by wasta-geek on 20/01/17.
//

#include "Monsters/Monster.hpp"

Monster::Monster(unsigned hp, unsigned atkValue, float atkSpeed, float moveSpeed) : ActiveElement(hp, atkSpeed), _atkValue(atkValue), _moveSpeed(moveSpeed)
{}

Monster::~Monster()
{}

void Monster::move(unsigned &y, unsigned &x)
{
    this->_pos = {y, x};
}

void Monster::update(float &deltaTime)
{}

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