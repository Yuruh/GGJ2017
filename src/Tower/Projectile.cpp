//
// Created by thomas on 21/01/17.
//

#include "Projectile.hpp"

Projectile::Projectile(float x, float y, int range, int hit, Monster* monster) {
    _x = x;
    _y = y;
    _range = range;
    _hit = hit;
    _target = monster;
}

Projectile::~Projectile() {

}

void Projectile::update(float &deltaTime) {
    return;
}
int Projectile::getRange() const {
    return _range;
}

int Projectile::getHit() const {
    return _hit;
}

void Projectile::setHit(int hit) {
    _hit = hit;
}

void Projectile::setRange(int range) {
    _range = range;
}

void Projectile::setMonster(Monster* target) {
    _target = target;
}
