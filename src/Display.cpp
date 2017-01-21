//
// Created by yuruh on 21/01/17.
//

#include <SFML/Window/Event.hpp>
#include <iostream>
#include "../include/Display.hpp"

bool Display::isActive()
{
    return this->window && this->window->isOpen();
}

std::pair<int, int> Display::getEvent()
{
    sf::Event   event;
    std::pair<int, int> ret(-1, -1);

    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            ret.first = event.mouseButton.x;
            ret.second = event.mouseButton.y;
        }
        if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            this->window->close();
    }
    return ret;
}

void Display::run()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "TOWER MAZE");
}

void Display::init() // Will get everything from Core
{
    std::cout << "Display.init()" << std::endl;
}

void Display::draw()
{
    this->window->clear();
    // Draw entities
    this->window->display();
}
