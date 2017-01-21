//
// Created by yuruh on 21/01/17.
//

#ifndef GGJ2017_DISPLAY_HPP
#define GGJ2017_DISPLAY_HPP


#include <SFML/Graphics/RenderWindow.hpp>

class Display
{
public:
    Display();
    ~Display();
    void run();

    bool isActive();

    std::pair<int, int> getEvent();

    void draw();

private:
    sf::RenderWindow    *window;
};


#endif //GGJ2017_DISPLAY_HPP
