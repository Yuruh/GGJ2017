//
// Created by wasta-geek on 21/01/17.
//

#ifndef GGJ2017_AACTIVEELEMENT_HPP
#define GGJ2017_AACTIVEELEMENT_HPP

#include "AEntity.hpp"

class ActiveElement : public AEntity
{
public:
    ActiveElement(unsigned, float);
    virtual ~ActiveElement();
    const unsigned int    &getHp() const;
    void            setHp(unsigned int&);

    const float     &getAtkSpeed() const;
    void            setAtkSpeed(unsigned&);
    const float     &getTimeSinceAtk() const;
    void            setTimeSinceAtk(float&);
    void            takeDmg(unsigned int&);
    virtual void    attack(ActiveElement&) = 0;
protected:
    unsigned int    _hp;
    float           _atkSpeed;
    float           _timeSinceAtk;
};


#endif //GGJ2017_AACTIVEELEMENT_HPP
