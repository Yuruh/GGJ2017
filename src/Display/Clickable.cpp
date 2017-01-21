//
// Clickable.cpp for  in /home/yuruh/tek3/Gomoku/src/GUI/
//
// Made by Antoine Lempereur
// Login   <lemper_a@epitech.eu>
//
// Started on  Tue Oct 18 18:05:38 2016 Antoine Lempereur
// Last update Thu Oct 27 17:54:16 2016 Antoine Lempereur
//

#include "Display/Clickable.hpp"

Clickable::Clickable(sf::Texture const& text) : SfmlSpriteHandler(text)
{
}

Clickable::~Clickable()
{

}

void      Clickable::setPosition(float x, float y)
{
  SfmlSpriteHandler::setPosition(x, y);
}

void      Clickable::move(float x, float y)
{
  SfmlSpriteHandler::move(x, y);
}

bool Clickable::containMouse(std::pair<int, int> &mousePos)
{
    auto rect = this->sprite.getGlobalBounds();

    return rect.contains(mousePos.first, mousePos.second);
}

void      Clickable::setSize(float width, float height)
{
  SfmlSpriteHandler::setSize(width, height);
  auto rect = this->sprite.getLocalBounds();

  this->sprite.scale(width / rect.width, height / rect.height);
}

void      Clickable::draw(sf::RenderTarget *target) const
{
  target->draw(this->sprite);
}

const sf::Sprite &Clickable::getSprite() const
{ return this->sprite; }