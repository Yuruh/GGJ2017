//
// Created by yuruh on 20/01/17.
//

#ifndef GGJ2017_ASPRITESHANDLER_HPP
#define GGJ2017_ASPRITESHANDLER_HPP

#include <SFML/Graphics.hpp>
#include "SfmlSpriteHandler.hpp"

class ASpritesHandler : public sf::Drawable
{
protected:
    std::vector<SfmlSpriteHandler>  sprites;
    sf::Vector2f             mainPos;
public:
    ASpritesHandler();
    ~ASpritesHandler();
    virtual void setPosition(float, float);
    virtual const sf::Vector2f &getPosition() const;
    float   getWidth() const;
    float   getHeight() const;
    virtual void move(float, float);
    virtual void setSize(float, float);
    virtual void setColor(int r, int g, int b, int a);

    void setProportionalSize(float width, float height);
    void addSprites(const sf::Texture&, sf::IntRect, int qty);
};


#endif //GGJ2017_ASPRITESHANDLER_HPP
