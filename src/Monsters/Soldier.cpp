//
// Created by wasta-geek on 21/01/17.
//

#include <Display/TextureManager.hpp>
#include "Monsters/Soldier.hpp"

Soldier::Soldier() : Monster(10, 15, 1.0f, 1)
{
    sf::Texture const& text = TextureManager::get(TextureManager::ACTORS);
    this->addSprites(text, sf::IntRect(0, 0, text.getSize().x / 4, text.getSize().y / 8), 3);
    this->setProportionalSize(40, 40);
    this->_refreshRate = 0.1;
}

Soldier::~Soldier()
{}