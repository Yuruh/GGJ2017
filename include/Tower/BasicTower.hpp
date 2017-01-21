//
// Created by thomas on 21/01/17.
//

#ifndef GGJ2017_BASICTOWER_H
#define GGJ2017_BASICTOWER_H

#include "ATower.hpp"
#include <iostream>

class BasicTower : public  ATower
{
public:
    BasicTower(int, int, double, int, int, MagickAttack *, Projectile *);
    ~BasicTower();
    void Speak() const;


};
#endif //GGJ2017_BASICTOWER_H
