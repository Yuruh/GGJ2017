//
// Created by thomas on 21/01/17.
//

#include "Projectile.h"

Projectile::Projectile(int range, int hit) {
    _range = range;
    _hit = hit;
}

Projectile::~Projectile() {

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