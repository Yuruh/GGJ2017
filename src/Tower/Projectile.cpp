//
// Created by thomas on 21/01/17.
//

#include <Display/TextureManager.hpp>
#include <iostream>
#include "Projectile.hpp"

Projectile::Projectile(float x, float y, int range, int hit, Monster* monster) {
    _x = x;
    _y = y;
    _range = range;
    _hit = hit;
    _target = monster;
    sf::Texture const& text = TextureManager::get(TextureManager::ACTORS);
    this->addSprites(text, sf::IntRect(_x, _y, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->setProportionalSize(40, 40);
}

Projectile::~Projectile() {

}

void Projectile::update(float &deltaTime) {
    if (_x >= _target->getPosition().x)
        _x -= 1;
    if (_x <= _target->getPosition().x)
        _x += 1;
    if (_y >= _target->getPosition().y)
        _y -= 1;
    if (_y <= _target->getPosition().y)
        _y += 1;
        this->sprites[0].setPosition(_x, _y);
    return;
}

void Projectile::resetPos(float _x, float _y)
{
    this->sprites[0].setPosition(_x, _y);
}
void Projectile::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    target.draw(this->sprites[0]);
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
