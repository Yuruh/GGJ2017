//
// Created by wasta-geek on 22/01/17.
//

#ifndef GGJ2017_SFMLTEXT_HPP
#define GGJ2017_SFMLTEXT_HPP

#include <SFML/Graphics/Text.hpp>

class SFMLText : public sf::Text
{
public:
    SFMLText(sf::Texture const &texture, sf::Vector2f position);
    ~SFMLText() {};
    void update();
private:
    sf::Font _textFont;
};


#endif //GGJ2017_SFMLTEXT_HPP
