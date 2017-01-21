//
// Created by wasta-geek on 21/01/17.
//

#ifndef GGJ2017_BUTTON_HPP
#define GGJ2017_BUTTON_HPP

#include "Clickable.hpp"

class Button : public Clickable
{
public:
    Button(sf::Texture const&, std::wstring, sf::Vector2f);
    ~Button();
    const sf::Text    &getText() const;
protected:
    sf::Text    _text;
    sf::Font    _textFont;
};


#endif //GGJ2017_BUTTON_HPP
