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
    _hp = 1;
    _target = monster;
    sf::Texture const& text = TextureManager::get(TextureManager::PROJECTILE);
    this->addSprites(text, sf::IntRect(_x, _y, text.getSize().x, text.getSize().y), 1);
    this->setProportionalSize(100, 100);
}

Projectile::~Projectile() {

}

int Projectile::getHP() const {
    return _hp;
}
void Projectile::update(float &deltaTime) {
    //std::cout << "POS MONSTER " << (int)_target->getPosition().x << " | " << (int)_target->getPosition().y << "POS PROJ " << (int)_x << " | " << (int)_y << std::endl;
    if (_x > _target->getPosition().x)
        _x -= 1.2;
    if (_x < _target->getPosition().x)
        _x += 1.2;
    if (_y > _target->getPosition().y)
        _y -= 1.2;
    if (_y < _target->getPosition().y)
        _y += 1.2;
    if (checkCollision() == true) {
        _target->takeDmg((unsigned int) _hit);
        this->_hp = 0;
    }
    this->sprites[0].setPosition(_x, _y);
    return;
}

bool Projectile::checkCollision()
{
    if ((int)(_x - 1) == (int)_target->getPosition().x && (int)(_y - 1) == (int)_target->getPosition().y)
        return true;
    if ((int)(_x + 1) == (int)_target->getPosition().x && (int)(_y + 1) == (int)_target->getPosition().y)
        return true;
    if ((int)(_x - 1) == (int)_target->getPosition().x && (int)_y == (int)_target->getPosition().y)
        return true;
    if ((int)(_x + 1) == (int)_target->getPosition().x && (int)_y == (int)_target->getPosition().y)
        return true;
    if ((int)(_x) == (int)_target->getPosition().x && (int)(_y - 1) == (int)_target->getPosition().y)
        return true;
    if ((int)(_x) == (int)_target->getPosition().x && (int)(_y + 1) == (int)_target->getPosition().y)
        return true;
    return false;
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
