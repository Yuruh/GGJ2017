//
// Created by babou on 21/01/17.
//

#ifndef GGJ2017_TEXTUREMANAGER_H
#define GGJ2017_TEXTUREMANAGER_H

#include <SFML/Graphics/Texture.hpp>
#include <map>

class TextureManager {
public:
    enum TextureType {
        WALL, WALLTOPLACE, GROUND, BUTTON, ACTORS
    };

    static TextureManager &Instance();
    void    addTexture(std::string const&, TextureType);
    const sf::Texture &getTexture(TextureType);
    static const sf::Texture &get(TextureType);
private:
    TextureManager ();
    virtual ~TextureManager ();
    std::map<TextureType, sf::Texture> textures;
};

#endif //GGJ2017_TEXTUREMANAGER_H
