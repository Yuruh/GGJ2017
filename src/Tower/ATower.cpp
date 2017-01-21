//
// Created by thomas on 21/01/17.
//


#include "ATower.hpp"

ATower::ATower(int pv, int mp, double time_attack, int range, int speed, MagickAttack * magic, Projectile * projectile) : _magic(magic), _attack(projectile)
{
    _pv = pv;
    _mp = mp;
    _time_attack = time_attack;
    _range = range;
    _speed = speed;
}

ATower::~ATower() {

}

void ATower::setPhysicalAttack(Projectile const&) {

}

void ATower::setMagickAttack(MagickAttack const&) {

}

bool ATower::canAttack() {
    if (getTime() >= _speed)
    {
        std::cout << "can attack" << std::endl;
        this->_time_attack = 0;
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

int ATower::getPv() const {
    return _pv;
}

void ATower::setPv(int pv) {
    _pv = pv;
}

int ATower::getMp() const {
    return _mp;
}

void ATower::setMp(int mp)  {
    _mp = mp;
}

double ATower::getTime() const {
    return _time_attack;
}

void ATower::setTime() {
    struct tm y2k;

    memset(&y2k, 0, sizeof(tm));
    y2k.tm_hour = 0;
    y2k.tm_min = 0;
    y2k.tm_sec = 0;
    y2k.tm_year = 0;
    y2k.tm_mon = 0;
    y2k.tm_mday = 0;
    time(&timer);
    this->_time_attack = difftime(timer, mktime(&y2k));
}

void ATower::changeTime() {
    time_t second_time;
    struct tm y2k;

    memset(&y2k, 0, sizeof(tm));
    y2k.tm_hour = 0;
    y2k.tm_min = 0;
    y2k.tm_sec = 0;
    y2k.tm_year = 0;
    y2k.tm_mon = 0;
    y2k.tm_mday = 0;
    time(&second_time);
    this->_time_attack = difftime(second_time, mktime(&y2k)) - difftime(timer, mktime(&y2k));
}

int ATower::getRange() const {
    return _range;
}

void ATower::setRange(int range) {
    _range = range;
}

int ATower::getSpeed() const {
    return _speed;
}

void ATower::setSpeed(int speed) {
    _speed = speed;
}

MagickAttack* ATower::getMagickAttack() const {
    return _magic;
}

Projectile *ATower::getPhysicalAttack() const {
    return _attack;
}

