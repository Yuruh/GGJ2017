//
// Created by yuruh on 21/01/17.
//

#ifndef GGJ2017_DISPLAY_HPP
#define GGJ2017_DISPLAY_HPP

#include "Map.hpp"
#include "Monsters/Monster.hpp"
#include "Tower/ATower.hpp"
#include "SFMLText.hpp"
#include "TextureManager.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <list>

class Button;

class Display
{
public:
    Display(std::list<Button*> &b, std::list<Monster*> &m, std::list<ATower*> &t, 
            std::list<Projectile*> &p) :
        _map(nullptr), _buttons{ b }, _monsters{ m }, _towers{ t }, _projectiles{ p }, _window(nullptr) { }
    ~Display() {
        if (this->_window)
            delete this->_window;
    }

    void run();
    bool isActive();

    void init(Map *map);
    void draw();
    std::pair<int, int> getEvent();


private:
    void drawMap();
    void drawButtons();

    Map     *_map;

    std::list<Button*>      &_buttons;
    std::list<Monster*>     &_monsters;
    std::list<ATower*>      &_towers;
    std::list<Projectile*>  &_projectiles;

    sf::RenderWindow    *_window;

    SFMLText    *_text;
    SFMLText    *_win;

    void drawGround();
    void drawMonsters();
    void drawTowers();
    void drawProjs();
};

extern int g_monsters;

#endif //GGJ2017_DISPLAY_HPP
