//
// Created by thomas on 20/01/17.
//

#ifndef GGJ2017_ITOWER_H
#define GGJ2017_ITOWER_H

#include <ctime>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <ActiveElement.hpp>
#include "Projectile.hpp"
#include "MagickAttack.hpp"
#include "Monsters/Monster.hpp"

class ATower : public ActiveElement
{
public:
    ATower(float, float, unsigned int, int, int, float, MagickAttack *, Projectile *);
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
    int                 nearestMonster(std::vector<Monster> &_monster);
    bool                isInCircle(std::pair<float, float> const&, float dist);
    bool                hadRunAway();
private:
    int _mp;
    int _range;
    MagickAttack    *_magic;
    Projectile *_attack;
    Monster    *_target;
    time_t timer;
    float _x;
    float _y;
    float _dist;
};
#endif //GGJ2017_ITOWER_H
