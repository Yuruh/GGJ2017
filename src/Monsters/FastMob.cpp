//
// Created by wasta-geek on 22/01/17.
//

#include <Map.hpp>
#include <Display/TextureManager.hpp>
#include "Monsters/FastMob.hpp"

FastMob::FastMob() : Monster(20, 5, 1.0f, 2.5)
{
    sf::Texture const& text = TextureManager::get(TextureManager::ACTORS);
    this->addSprites(text, sf::IntRect(text.getSize().x / 2, 0, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->addSprites(text, sf::IntRect(text.getSize().x / 2, text.getSize().y / 8, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->addSprites(text, sf::IntRect(text.getSize().x / 2, text.getSize().y / 8 * 2, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->addSprites(text, sf::IntRect(text.getSize().x / 2, text.getSize().y / 8 * 3, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->setProportionalSize(TILE_SIZE / 1.8, TILE_SIZE / 1.8);
    this->_refreshRate = 0.1f;
}
