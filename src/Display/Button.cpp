//
// Created by wasta-geek on 21/01/17.
//

#include "Display/Button.hpp"

Button::Button(sf::Texture const &texture, std::wstring text, sf::Vector2f position) : Clickable(texture)
{
    if (!this->_textFont.loadFromFile("resources/police/upheavtt.ttf"))
        throw(std::exception());
    this->sprite.setPosition(position);
    this->_text.setFont(this->_textFont);
    this->_text.setCharacterSize(35);
    this->_text.setPosition(position.x + text.size(), position.y + 35);
    this->_text.setString(text);

}