//
// Created by babou on 21/01/17.
//

#include "Display/TextureManager.hpp"

TextureManager::TextureManager()
{
    this->addTexture("resources/assets/wall.png", TextureManager::WALL);
    this->addTexture("resources/assets/block.png", TextureManager::BLOCK);
    this->addTexture("resources/assets/ground.png", TextureManager::GROUND);
    this->addTexture("resources/assets/buttonNormal.png", TextureManager::BUTTON);
}

TextureManager::~TextureManager()
{

}

TextureManager& TextureManager::Instance()
{
    static TextureManager  _instance;

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
