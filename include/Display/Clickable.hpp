//
// Clickable.hpp for  in /home/yuruh/tek3/Gomoku/include/GUI/
//
// Made by Antoine Lempereur
// Login   <lemper_a@epitech.eu>
//
// Started on  Tue Oct 18 17:53:05 2016 Antoine Lempereur
// Last update Thu Oct 27 17:55:06 2016 Antoine Lempereur
//

#ifndef CLICKABLE_HPP
#define CLICKABLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Display/SfmlSpriteHandler.hpp"

class Clickable : public SfmlSpriteHandler
{
public:
    Clickable(sf::Texture const&);
    virtual ~Clickable ();
    bool    clicked();
    virtual void  setPosition(float, float);
    virtual void  move(float, float);
    virtual void setSize(float, float);
    virtual bool containMouse(std::pair<int, int>&);
    void    draw(sf::RenderTarget *target) const;
    const sf::Sprite &getSprite() const;
};

#endif /* end of include guard: CLICKABLE_HPP */
