//
// Created by thomas on 21/01/17.
//

#include "Projectile.hpp"
#include "Map.hpp"
#include <Display/TextureManager.hpp>
#include <iostream>

Projectile::Projectile(float x, float y, int range, int hit, Monster & monster) :
    _x(x), _y(y), _range(range), _hit(hit), _target(monster), _hp(1), _speed(10)
{
    sf::Texture const& text = TextureManager::get(TextureManager::PROJECTILE);
    this->addSprites(text, sf::IntRect(0, 0, text.getSize().x, text.getSize().y), 1);

    ASpritesHandler::setPosition(x, y);
}


void Projectile::update(float &deltaTime) {
    float dirX = _target.getPosition().x - getPosition().x;
    float dirY = _target.getPosition().y - getPosition().y;

    dirX *= _speed * deltaTime;
    dirY *= _speed * deltaTime;
    
    ASpritesHandler::move(dirX, dirY);

    if (checkCollision() == true) {
        _target.takeDmg((unsigned int) _hit);
        this->_hp = 0;
    }
    return;
}

bool Projectile::checkCollision()
{
    if (
            ((int)(this->getPosition().x - 10) <= (int)_target.getPosition().x && ((int)(this->getPosition().x + 10) >= ((int)_target.getPosition().x)))
        &&
            ((int)(this->getPosition().y - 10) <= (int)_target.getPosition().y && ((int)(this->getPosition().y + 10) >= ((int)_target.getPosition().y)))
            )
        return true;
    return false;
}


void Projectile::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    target.draw(this->sprites[0]);
}
