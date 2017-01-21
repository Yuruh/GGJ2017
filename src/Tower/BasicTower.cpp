//
// Created by thomas on 21/01/17.
//

#include <MagickAttack.h>
#include <Projectile.h>
#include <ATower.h>
#include <BasicTower.h>

BasicTower::BasicTower(int pv, int mp, double time_attack, int range, int speed, MagickAttack * magic, Projectile * projectile) : ATower(pv, mp, time_attack, range, speed, magic, projectile)
{

}

BasicTower::~BasicTower() {

}

void BasicTower::Speak() const {
    std::cout << "PWET" << std::endl;
}
