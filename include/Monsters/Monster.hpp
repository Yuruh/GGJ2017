//
// Created by wasta-geek on 20/01/17.
//

#ifndef GGJ2017_AMONSTER_HPP
#define GGJ2017_AMONSTER_HPP

#include "ActiveElement.hpp"

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

protected:
    unsigned int    _atkValue;
    float           _moveSpeed;
};


#endif //GGJ2017_AMONSTER_HPP