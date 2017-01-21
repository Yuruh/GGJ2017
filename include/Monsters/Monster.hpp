//
// Created by wasta-geek on 20/01/17.
//

#ifndef GGJ2017_AMONSTER_HPP
#define GGJ2017_AMONSTER_HPP

#include "ActiveElement.hpp"
#include <list>

class Monster : public ActiveElement
{
public:
    Monster(unsigned, unsigned, float, float);
    virtual ~Monster();
    void    move(unsigned &, unsigned &);
    void    update(float&);
    float   &getMoveSpeed();
    void    setMoveSpeed(float&);
    unsigned int    &getAtkValue();
    void            setAtkValue(unsigned&);
    void    attack(ActiveElement&);
//    en fait il faut stocker une liste de direction
    bool    hasDirection() const { return (this->dir.first != 0 || this->dir.second != 0); }

    void setPosition(float, float);

    std::pair<int, int> getPos() const;

protected:
    unsigned int    _atkValue;
    float           _moveSpeed;
    float           _refreshRate;
    float           _t;
    unsigned int    _counter;

    std::pair<int, int> currentPos;
    std::list<std::pair<int, int> > nextPositions;
public:
    void setNextPositions(const std::list<std::pair<int, int>> &nextPositions);

protected:
    std::pair<int, int > dir;

    void draw(sf::RenderTarget &, sf::RenderStates) const;

    bool arrived;
};


#endif //GGJ2017_AMONSTER_HPP
