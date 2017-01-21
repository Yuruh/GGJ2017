//
// Created by yuruh on 21/01/17.
//

#ifndef GGJ2017_DISPLAY_HPP
#define GGJ2017_DISPLAY_HPP

#include "Map.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

class Display
{
public:
    Display() :
        _window(nullptr) {}
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
    sf::RenderWindow    *_window;

    Map     *_map;
};


#endif //GGJ2017_DISPLAY_HPP
