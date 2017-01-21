//
// Created by yuruh on 21/01/17.
//

#ifndef GGJ2017_DISPLAY_HPP
#define GGJ2017_DISPLAY_HPP

#include "Map.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include <Monsters/Monster.hpp>

class Button;

class Display
{
public:
    Display(std::list<Button*> &b, std::list<Monster*> &m) :
        _map(nullptr), _buttons{ b }, _monsters{ m }, _window(nullptr) {}
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
    std::list<Button*>  &_buttons;
    std::list<Monster*> &_monsters;
    sf::RenderWindow    *_window;

    void drawMonsters();
};


#endif //GGJ2017_DISPLAY_HPP
