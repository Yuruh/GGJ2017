//
// Created by wasta-geek on 20/01/17.
//


#include "Map.hpp"
#include "Monsters/Monster.hpp"

#include <iostream>
#include <zconf.h>

Monster::Monster(unsigned hp, unsigned atkValue, float atkSpeed, float moveSpeed) : ActiveElement(hp, atkSpeed), _atkValue(atkValue), _moveSpeed(moveSpeed)
{
    _t = 0;
    _counter = 0;
    currentPos.first = 0;
    currentPos.second = 0;
    dir = std::make_pair<int, int>( 0, 0 );
    arrived = false;
}

Monster::~Monster()
{}


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

    // Moving value depending on the Entity speed, deltaTime and the TILE_SIZE
    float movingValue = this->_moveSpeed * deltaTime * TILE_SIZE;

    // Direction to get closer to the castle
    float dirX = movingValue * dir.first;
    float dirY = movingValue * dir.second;

    // Move sprite with direction
    ASpritesHandler::move(dirX, dirY);

    // Check if we moved from one square on the map to the next one (AKA nextPosition)
    if (abs((int)(this->getPosition().x - this->currentPos.first * TILE_SIZE)) > TILE_SIZE ||
        abs((int)(this->getPosition().y - this->currentPos.second * TILE_SIZE)) > TILE_SIZE)
    {
        // If there is still a nextPosition to reach
        if (nextPositions.size() > 1)
        {
            // Our new position in the map is now the position of our previous desired nextPosition
            this->currentPos.first = nextPositions.front()->x;
            this->currentPos.second = this->nextPositions.front()->y;

            // Depop the old nextPosition
            this->nextPositions.pop_front();

            // Recalc the new direction to reach our new desired nextPosition
            this->dir.first = (this->nextPositions.front()->x - this->currentPos.first);
            this->dir.second = (this->nextPositions.front()->y - this->currentPos.second);
        }
        // Else we are arrived
        else
            arrived = true;
    }
}

// Should be useless now
void    Monster::checkBlockInPath(const std::pair<int, int> &pos)
{
    for (auto &path : nextPositions)
    {
        if (pos.first == path->x && pos.second == path->y)
        {
//            this->dir.first = 0;
//            this->dir.second = 0;
            this->nextPositions.clear();
            this->setPosition((float) this->getPos().first, (float) this->getPos().second);
            return;
        }
    }
}

// To fill to detect if there is a rock in our way
bool    Monster::hasBlockInPath()
{
    for (auto &path : nextPositions)
    {
//        std::cout << *path << std::endl;
       if (path->type == BLOCK)
       {
//           std::cout << "salut" << std::endl;
           return true;
       }
    }
//    std::cout << std::endl;
//    usleep(500000);
    return false;
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

const std::pair<int, int> &Monster::getPos() const
{
    return this->currentPos;
}

std::pair<int, int> Monster::getNextPos() const
{
    if (!this->nextPositions.empty())
        return std::pair<int, int>(this->nextPositions.front()->x, this->nextPositions.front()->y);
    else
        return std::pair<int, int>(-1, -1);
};

void Monster::setPosition(float x, float y)
{
    // Set position in screen
    ASpritesHandler::setPosition(x * TILE_SIZE, y * TILE_SIZE);
    // Set position in map
    this->currentPos.first = (int) x;
    this->currentPos.second = (int) y;
}

void Monster::setNextPositions(const std::list<Tile*> &nextPositions)
{
//    std::cout << "JE SET LES PROCHAINES POSITIONS" << std::endl;
    this->nextPositions = nextPositions;
    if (this->nextPositions.size() > 0)
    {
        // Set direction between our currentPos and our desired nextPosition
        this->dir.first = this->nextPositions.front()->x - currentPos.first;
        this->dir.second = this->nextPositions.front()->y - currentPos.second;
    }
}

void Monster::setDirection(int x, int y)
{
    this->dir.first = x;
    this->dir.second = y;
}