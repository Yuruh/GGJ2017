//
// Created by babou on 21/01/17.
//

#include "TextureManager.hpp"

TextureManager  TextureManager::_instance = TextureManager();

TextureManager::TextureManager()
{
    this->addTexture("resources/assets/wall11.png", TextureManager::WALL);
    this->addTexture("resources/assets/ground11.png", TextureManager::GROUND);

}

TextureManager::~TextureManager()
{

}

TextureManager& TextureManager::Instance()
{
    return (_instance);
}

void    TextureManager::addTexture(std::string const& path, TextureType type)
{
    if (!this->textures[type].loadFromFile(path))
        this->textures.erase(type);
}

const sf::Texture &TextureManager::getTexture(TextureType type)
{
    if (this->textures.find(type) != this->textures.end())
        return (this->textures[type]);
    else
        throw std::runtime_error("Could not find texture");
}

const sf::Texture &TextureManager::get(TextureManager::TextureType type)
{
    return TextureManager::Instance().getTexture(type);
}
