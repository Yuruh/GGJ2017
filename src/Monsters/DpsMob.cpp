//
// Created by wasta-geek on 22/01/17.
//

#include <Map.hpp>
#include <Display/TextureManager.hpp>
#include "Monsters/DpsMob.hpp"

DpsMob::DpsMob() : Monster(50, 25, 1.0f, 1)
{
    sf::Texture const& text = TextureManager::get(TextureManager::ACTORS);
    this->addSprites(text, sf::IntRect(0, text.getSize().y / 8 * 4, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->addSprites(text, sf::IntRect(0, text.getSize().y / 8 * 5, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->addSprites(text, sf::IntRect(0, text.getSize().y / 8 * 6, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->addSprites(text, sf::IntRect(0, text.getSize().y / 8 * 7, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->setProportionalSize(TILE_SIZE, TILE_SIZE);
    this->_refreshRate = 0.1f;
}