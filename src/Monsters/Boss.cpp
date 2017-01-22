//
// Created by wasta-geek on 22/01/17.
//

#include <Map.hpp>
#include <Display/TextureManager.hpp>
#include "Monsters/Boss.hpp"

Boss::Boss() : Monster(350, 30, 1.0f, 0.5f)
{
    sf::Texture const& text = TextureManager::get(TextureManager::ACTORS);
    this->addSprites(text, sf::IntRect(text.getSize().x / 4 * 3, text.getSize().y / 8 * 4, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->addSprites(text, sf::IntRect(text.getSize().x / 4 * 3, text.getSize().y / 8 * 5, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->addSprites(text, sf::IntRect(text.getSize().x / 4 * 3, text.getSize().y / 8 * 6, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->addSprites(text, sf::IntRect(text.getSize().x / 4 * 3, text.getSize().y / 8 * 7, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->setProportionalSize(TILE_SIZE * 1.5f, TILE_SIZE);
    this->_refreshRate = 0.1f;
}