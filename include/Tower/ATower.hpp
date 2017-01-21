//
// Created by thomas on 20/01/17.
//

#ifndef GGJ2017_ITOWER_H
#define GGJ2017_ITOWER_H

#include <ctime>
#include <cstring>
#include <iostream>
#include "Projectile.hpp"
#include "MagickAttack.hpp"

class ATower
{
public:
    ATower(int, int, double, int, int, MagickAttack *, Projectile *);
    ~ATower();

    bool canAttack();
    int  PhysicialAttack();
    int  MagicalAttack();

    int getPv() const;
    void setPv(int);

    int getMp() const;
    void setMp(int) ;

    double getTime() const;
    void   setTime() ;
    void    changeTime();

    int getRange() const;
    void setRange(int);

    int getSpeed() const;
    void setSpeed(int);

    MagickAttack* getMagickAttack() const;
    void                setMagickAttack(MagickAttack const&);

    Projectile * getPhysicalAttack() const;
    void                setPhysicalAttack(Projectile const&);

    virtual void        Speak() const = 0;

private:
    int _pv;
    int _mp;
    double _time_attack;
    int _range;
    int _speed;
    MagickAttack    *_magic;
    Projectile *_attack;
    time_t timer;
};
#endif //GGJ2017_ITOWER_H
