//
// Created by wasta-geek on 20/01/17.
//

#include <iostream>
#include <Map.hpp>
#include "Monsters/Monster.hpp"

Monster::Monster(unsigned hp, unsigned atkValue, float atkSpeed, float moveSpeed) : ActiveElement(hp, atkSpeed), _atkValue(atkValue), _moveSpeed(moveSpeed)
{
    _t = 0;
    _counter = 0;
    currentPos.first = 0;
    currentPos.second = 0;
    dir.first = 0;
    dir.second = 0;
    arrived = false;
}

Monster::~Monster()
{}

void Monster::move(unsigned &y, unsigned &x)
{
    this->_pos = {y, x};
}

void Monster::update(float &deltaTime)
{
    if (arrived)
        return;
    _t += deltaTime;
    if (this->_t > this->_refreshRate)
    {
        if (_counter < this->sprites.size() - 1)
            _counter++;
        else
            _counter = 0;
        _t = 0;
    }

    float movingValue = this->_moveSpeed * deltaTime * TILE_SIZE;
    ASpritesHandler::move(movingValue * dir.first, movingValue * dir.second);

    if (abs((int) (this->getPosition().x - this->currentPos.first * TILE_SIZE)) > TILE_SIZE ||
            abs((int) (this->getPosition().y - this->currentPos.second * TILE_SIZE)) > TILE_SIZE)
    {
        if (nextPositions.size() > 1)
        {
//            std::cout << currentPos.first << " " << currentPos.second << std::endl;
            this->currentPos = this->nextPositions.front();
//            std::cout << currentPos.first << " " << currentPos.second << std::endl << std::endl;
            this->nextPositions.pop_front();
            this->dir.first = (this->nextPositions.front().first - this->currentPos.first);
            this->dir.second = (this->nextPositions.front().second - this->currentPos.second);
        }
        else
            arrived = true;
    }
}

void    Monster::checkBlockInPath(const std::pair<int, int> &pos)
{
    for (auto &path : nextPositions)
    {
        if (pos.first == path.first && pos.second == path.second)
        {
//            this->dir.first = 0;
//            this->dir.second = 0;
            this->nextPositions.clear();
            this->setPosition(this->getPos().first, this->getPos().second);
            return;
        }
    }
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

std::pair<int, int> Monster::getPos() const
{
    return this->currentPos;
}

void Monster::setPosition(float x, float y)
{
    ASpritesHandler::setPosition(x * TILE_SIZE, y * TILE_SIZE);
    this->currentPos.first = (int) x;
    this->currentPos.second = (int) y;

}

void Monster::setNextPositions(const std::list<std::pair<int, int>> &nextPositions)
{
    this->nextPositions = nextPositions;
    if (this->nextPositions.size() > 0)
    {
        this->dir.first = (int) (this->nextPositions.front().first - this->_pos.first);
        this->dir.second = (int) (this->nextPositions.front().second - this->_pos.second);
    }
}
