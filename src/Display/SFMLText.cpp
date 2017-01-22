//
// Created by wasta-geek on 22/01/17.
//

#include "Display/SFMLText.hpp"
#include "iostream"
extern int g_monsters;

SFMLText::SFMLText(sf::Texture const &texture, sf::Vector2f position)
{
    if (!this->_textFont.loadFromFile("resources/police/upheavtt.ttf"))
        throw(std::exception());
    this->setString("Castle's life: " + std::to_string(g_monsters));
    this->setFont(_textFont);
    this->setCharacterSize(35);
    this->setPosition(position);
}

void SFMLText::update()
{
    static unsigned lastLife = g_monsters;

    if (lastLife != g_monsters)
    {
        this->setString("Castle's life: " + std::to_string(g_monsters));
        lastLife = g_monsters;
    }
}