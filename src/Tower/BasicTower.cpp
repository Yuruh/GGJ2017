//
// Created by thomas on 21/01/17.
//

#include <MagickAttack.hpp>
#include <Projectile.hpp>
#include <ATower.hpp>
#include <BasicTower.hpp>

BasicTower::BasicTower(float x, float y, unsigned hp, int mp, int range, float atkSpeed, MagickAttack * magic, Projectile * projectile) : ATower(x, y, hp, mp, range, atkSpeed, magic, projectile)
{

}

BasicTower::~BasicTower() {

}

void BasicTower::Speak() const {
    std::cout << "PWET" << std::endl;
}
