//
// Created by thomas on 21/01/17.
//

#include <MagickAttack.hpp>

MagickAttack::MagickAttack(int range, int hit) {
    _range = range;
    _hit = hit;
    _typeMagic  = FIRE;
    _target  = FOE;
}

MagickAttack::~MagickAttack() {

}

int MagickAttack::getRange() const {
    return _range;
}

int MagickAttack::getHit() const {
    return _hit;
}

Target MagickAttack::getTarget() const {
    return FOE;
}

TypeMagic MagickAttack::getTypeMagic() const {
    return FIRE;
}

void MagickAttack::setTarget(Target target) {
    _target = target;
}

void MagickAttack::setTypeMagic(TypeMagic typeMagic) {
    typeMagic = _typeMagic;
}

void MagickAttack::setRange(int range) {
    _range = range;
}

void MagickAttack::setHit(int hit) {
    _hit = hit;
}
