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

    inline const sf::Text   &getText() const    { return this->_text; }
    inline const bool       isVisible() const   { return this->_visible; }
    inline void             setVisible(bool v)  { _visible = v; }

protected:
    bool        _visible;

    sf::Text    _text;
    sf::Font    _textFont;
};


#endif //GGJ2017_BUTTON_HPP
