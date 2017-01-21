//
// Created by wasta-geek on 21/01/17.
//

#include "ActiveElement.hpp"

ActiveElement::ActiveElement(unsigned hp, float atkSpeed) : _hp(hp), _atkSpeed(atkSpeed), _timeSinceAtk(0.0f)
{}

ActiveElement::~ActiveElement()
{}

const unsigned int& ActiveElement::getHp() const
{ return this->_hp; }

void ActiveElement::setHp(unsigned &hp)
{
    this->_hp = hp;
}

const float& ActiveElement::getAtkSpeed() const
{ return this->_atkSpeed; }

void ActiveElement::setAtkSpeed(float &atkSpeed)
{
    this->_atkSpeed = atkSpeed;
}

void ActiveElement::takeDmg(unsigned int dmg)
{
    this->_hp = _hp < dmg ? 0 : _hp - dmg;
}

const float& ActiveElement::getTimeSinceAtk() const
{ return this->_timeSinceAtk; }

void ActiveElement::setTimeSinceAtk(float &timeSinceAtk)
{
    this->_timeSinceAtk = timeSinceAtk;
}