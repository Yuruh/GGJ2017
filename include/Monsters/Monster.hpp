//
// Created by wasta-geek on 20/01/17.
//

#ifndef GGJ2017_AMONSTER_HPP
#define GGJ2017_AMONSTER_HPP

#include "ActiveElement.hpp"
#include "Tile.hpp"

#include <list>

class Monster : public ActiveElement
{
public:
    Monster(unsigned, unsigned, float, float);
    virtual ~Monster();

    void    update(float&);
    float   &getMoveSpeed();
    void    setMoveSpeed(float&);
    unsigned int    &getAtkValue();
    void            setAtkValue(unsigned&);
    void    attack(ActiveElement&);
    void    setDirection(int, int);
//    en fait il faut stocker une liste de direction
    bool    hasDirection() const { return this->nextPositions.size() > 0; }

    void setPosition(float, float);

    const std::pair<int, int> &getPos() const;

    bool hasBlockInPath();
    std::pair<int, int> getNextPos() const;


protected:
    unsigned int    _atkValue;
    float           _moveSpeed;
    float           _refreshRate;
    float           _t;
    unsigned int    _counter;
    unsigned int    _counterOffset;

    // Current Position in Map. [WARNING] NEVER USE _pos!
    std::pair<int, int> currentPos;

    // List of all the desired nextPositions to get to the castle
    std::list<Tile*> nextPositions;

public:
    void setNextPositions(const std::list<Tile*> &nextPositions);

protected:
    std::pair<int, int > dir;

    void draw(sf::RenderTarget &, sf::RenderStates) const;

    bool arrived;

    void updateCounterOffset();
};


#endif //GGJ2017_AMONSTER_HPP
