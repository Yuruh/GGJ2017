//
// Created by wasta-geek on 22/01/17.
//

#include <Display/TextureManager.hpp>
#include <Map.hpp>
#include "Monsters/TankMob.hpp"

TankMob::TankMob() : Monster(200, 10, 1.0f, 0.5)
{
    sf::Texture const& text = TextureManager::get(TextureManager::ACTORS);
    this->addSprites(text, sf::IntRect(0, 0, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->addSprites(text, sf::IntRect(0, text.getSize().y / 8, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->addSprites(text, sf::IntRect(0, text.getSize().y / 8 * 2, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->addSprites(text, sf::IntRect(0, text.getSize().y / 8 * 3, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->setProportionalSize(TILE_SIZE, TILE_SIZE);
    this->_refreshRate = 0.1f;
}
