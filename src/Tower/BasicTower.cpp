//
// Created by thomas on 21/01/17.
//

#include <MagickAttack.hpp>
#include <Projectile.hpp>
#include <ATower.hpp>
#include <BasicTower.hpp>

BasicTower::BasicTower(int pv, int mp, double time_attack, int range, int speed, MagickAttack * magic, Projectile * projectile) : ATower(pv, mp, time_attack, range, speed, magic, projectile)
{

}

BasicTower::~BasicTower() {

}

void BasicTower::Speak() const {
    std::cout << "PWET" << std::endl;
}
