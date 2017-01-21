//
// Created by yuruh on 21/01/17.
//

#ifndef GGJ2017_DISPLAY_HPP
#define GGJ2017_DISPLAY_HPP


#include <SFML/Graphics/RenderWindow.hpp>

class Display
{
public:
    Display() :
        window(nullptr) {}
    ~Display() {
        if (this->window)
            delete this->window;
    }

    void run();
    bool isActive();

    void init();
    void draw();

    std::pair<int, int> getEvent();


private:
    sf::RenderWindow    *window;
};


#endif //GGJ2017_DISPLAY_HPP
