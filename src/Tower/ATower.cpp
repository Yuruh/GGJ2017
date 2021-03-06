//
// Created by thomas on 21/01/17.
//


#include <list>
#include "ATower.hpp"

ATower::ATower(float x, float y, unsigned int hp, int mp, int range, float atkSpeed,
               MagickAttack * magic, Projectile * projectile,
               std::list<Monster*>& monsters, std::list<Projectile*> &projs) :
        _x(x), _y(y), ActiveElement(hp, atkSpeed), _mp(mp), _range(range), _atkSpeed(atkSpeed),
        _magic(magic), _attack(projectile), _target(nullptr),
        _monsters(monsters), _projectiles(projs)
{
    _hp = 10;
    _mp = 10;
    _range = 3;
    _atkSpeed = 1;
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
        this->_timeSinceAtk = 0;
        return true;
    }
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
        nearestMonster(_monsters);
    if (_target != nullptr && _target->getHp() <= 0)
    {
        _target->isDead = true;
        _target = nullptr;
    }
    if (_target != nullptr && canAttack() == true)
    {
        if (hadRunAway() == true) {
            nearestMonster(_monsters);

        }
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
    _dist = 0.0f;

    for (auto & monster : monsters)
    {
        count++;
        if (isInCircle(monster->getPosition(), _dist) == true) {
            nb = count;
            _target = monster;
        }
    }
    return (nb);
}

bool ATower::hadRunAway()
{
    float dist;

    dist = sqrtf(powf(_target->getPosition().x - _x, 2) + powf(_target->getPosition().y - _y, 2));
    if (dist > _range * TILE_SIZE) {
        // Should be where we reset _target in a beautiful world
        return true;
    }
    return false;
}

bool ATower::isInCircle(const sf::Vector2f& _pos, float prev_dist) {
    float dist;

    dist = sqrtf(powf(_pos.x - _x, 2) + powf(_pos.y - _y, 2));
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
    _projectiles.push_back(new Projectile(_x, _y, _range, 5, *_target));
}
