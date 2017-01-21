//
// Created by thomas on 21/01/17.
//


#include <list>
#include "ATower.hpp"

ATower::ATower(float x, float y, unsigned int hp, int mp, int range, float atkSpeed, MagickAttack * magic, Projectile * projectile, std::list<Monster*>& monsters) :
            _hp(10), _mp(10), _range(1), _atkSpeed(3),
            ActiveElement(hp, atkSpeed), _magic(magic), _attack(projectile), _monsters(monsters)
{
    _x = x;
    _y = y;
    _timeSinceAtk = 0;
    _target = nullptr;

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
    //std::cout << "can't attack" << std::endl;
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
    if (_target == nullptr)
    {
        nearestMonster(_monsters);  //TO DO METTRE LE VECTOR DE MONSTRE
    }
    if (_target != nullptr && canAttack() == true && hadRunAway() == false)
    {
        if (_target != nullptr)
            this->attack(*_target);

    }
    // si je peux attaquer (atkSpeed) et que un mob est dans ma range -> attack
}

void ATower::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    target.draw(this->sprites[0]);
}

int ATower::nearestMonster(std::list<Monster*>& monsters)
{
    int nb = -1;
    int count = 0;
    _dist = 0.0;

    for (auto & monster : monsters)
    {
        count++;
        if (isInCircle(monster->getPosition(), _dist) == true) {
            nb = count;
            _target = monster;
            std::cout << "CATCHING POS MONSTER " << _target->getPosition().x << " | " << _target->getPosition().y << "POS TOUR " << _x << " | " << _y << std::endl;
        }
    }
    return (nb);
}

bool ATower::hadRunAway()
{
    float dist;

    dist = sqrtf(powf(_target->getPosition().x - _x, 2) + powf(_target->getPosition().y - _y, 2));
    if (dist > _range) {
        _target = nullptr;
        return true;
    }
    return false;
}

bool ATower::isInCircle(const sf::Vector2f& _pos, float prev_dist) {
    float dist;

    dist = sqrtf(powf(_pos.x - _x, 2) + powf(_pos.y - _y, 2));
    //std::cout << "POS MONSTER " << _pos.x << " | " << _pos.y << "POS TOUR " << _x << " | " << _y << std::endl;
    if (_dist != 0 && dist < prev_dist) {
        _dist = dist;
        return false;
    }
    if (dist <= (_range * TILE_SIZE)) {
        _dist = dist; //redondant, mais il doit être set une première fois (autrement que 0);
        return true;
    }
    return false;
}



void ATower::attack(ActiveElement &target)
{
    this->_timeSinceAtk = 0;
    if (_target != nullptr) {
        _attack->setPosition(this->_x, this->_y);
        return;
    }
    else
    {
        _attack = new Projectile(this->getPosition().x, this->getPosition().y, 0, 5, _target);
        _attack->setPosition(this->_x, this->_y);
        //set reduc hp
    }
        //Core::getInstance().addProjectile(5, 0, _target);
    //CORE ADD PROJECTILE
    // lancer projectile sur la pos du target
}
