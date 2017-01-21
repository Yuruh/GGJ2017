//
// Created by thomas on 21/01/17.
//


#include "ATower.hpp"

ATower::ATower(unsigned int hp, int mp, int range, float atkSpeed, MagickAttack * magic, Projectile * projectile) : ActiveElement(hp, atkSpeed), _magic(magic), _attack(projectile)
{
    _mp = mp;
    _range = range;
    _timeSinceAtk = 0;
    _atkSpeed = atkSpeed;
}

ATower::~ATower() {

}

void ATower::setPhysicalAttack(Projectile const&) {

}

void ATower::setMagickAttack(MagickAttack const&) {

}

bool ATower::canAttack() {
    if (this->_timeSinceAtk >= _atkSpeed)
    {
        std::cout << "can attack" << std::endl;
        this->_timeSinceAtk = 0;
        return true;
    }
    std::cout << "can't attack" << std::endl;
    return false;
}

int ATower::PhysicialAttack() {
    return 0;
}

int ATower::MagicalAttack() {
    return 0;
}

int ATower::getMp() const {
    return _mp;
}

void ATower::setMp(int mp)  {
    _mp = mp;
}

//void ATower::setTime() {
//    struct tm y2k;
//    time_t _tim;
//
//    memset(&y2k, 0, sizeof(tm));
//    y2k.tm_hour = 0;
//    y2k.tm_min = 0;
//    y2k.tm_sec = 0;
//    y2k.tm_year = 0;
//    y2k.tm_mon = 0;
//    y2k.tm_mday = 0;
//    time(&_tim);
//    timer = _tim;
//    //this->_time_attack =  0;
//}
//
//void ATower::changeTime() {
//    time_t second_time;
//    struct tm y2k;
//
//    memset(&y2k, 0, sizeof(tm));
//    y2k.tm_hour = 0;
//    y2k.tm_min = 0;
//    y2k.tm_sec = 0;
//    y2k.tm_year = 0;
//    y2k.tm_mon = 0;
//    y2k.tm_mday = 0;
//    time(&second_time);
//    this->_timeSinceAtk = difftime(second_time, mktime(&y2k)) - difftime(timer, mktime(&y2k));
//}

int ATower::getRange() const {
    return _range;
}

void ATower::setRange(int range) {
    _range = range;
}
 MagickAttack* ATower::getMagickAttack() const {
    return _magic;
}

Projectile *ATower::getPhysicalAttack() const {
    return _attack;
}

void ATower::update(float &deltaTime)
{
    this->_timeSinceAtk += deltaTime;
    // si je peux attaquer (atkSpeed) et que un mob est dans ma range -> attack
}

void ATower::attack(ActiveElement &target)
{
    this->_timeSinceAtk = 0;
    // lancer projectile sur la pos du target
}
