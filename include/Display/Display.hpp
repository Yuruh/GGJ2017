//
// Created by yuruh on 21/01/17.
//

#ifndef GGJ2017_DISPLAY_HPP
#define GGJ2017_DISPLAY_HPP

#include "Map.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <list>

class Button;

class Display
{
public:
    Display(Map *map, std::list<Button*> &b) :
        _map{ map }, _buttons{ b }, _window(nullptr) {}
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
    sf::RenderWindow    *_window;
};


#endif //GGJ2017_DISPLAY_HPP
