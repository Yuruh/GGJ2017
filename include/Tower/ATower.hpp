//
// Created by thomas on 20/01/17.
//

#ifndef GGJ2017_ITOWER_H
#define GGJ2017_ITOWER_H

#include <ctime>
#include <cstring>
#include <iostream>
#include <ActiveElement.hpp>
#include "Projectile.hpp"
#include "MagickAttack.hpp"

class ATower : public ActiveElement
{
public:
    ATower(unsigned int, int, int, float, MagickAttack *, Projectile *);
    ~ATower();

    bool canAttack();
    int  PhysicialAttack();
    int  MagicalAttack();

    int getMp() const;
    void setMp(int) ;

    void    changeTime();

    int getRange() const;
    void setRange(int);

    MagickAttack* getMagickAttack() const;
    void                setMagickAttack(MagickAttack const&);

    Projectile * getPhysicalAttack() const;
    void                setPhysicalAttack(Projectile const&);

    virtual void        Speak() const = 0;
    void                update(float&);
    void                attack(ActiveElement&);
private:
    int _mp;
    int _range;
    MagickAttack    *_magic;
    Projectile *_attack;
    time_t timer;
};
#endif //GGJ2017_ITOWER_H
