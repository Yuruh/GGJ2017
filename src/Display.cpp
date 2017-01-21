//
// Created by yuruh on 21/01/17.
//

#include <SFML/Window/Event.hpp>
#include <iostream>
#include "Display.hpp"

bool Display::isActive()
{
    return this->_window && this->_window->isOpen();
}

std::pair<int, int> Display::getEvent()
{
    sf::Event   event;
    std::pair<int, int> ret(-1, -1);

    while (this->_window->pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            ret.first = event.mouseButton.x;
            ret.second = event.mouseButton.y;
        }
        if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            this->_window->close();
    }
    return ret;
}

void Display::run()
{
    this->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "TOWER MAZE");
}

void Display::init(Map *map) // Will get everything from Core
{
    std::cout << "Display.init()" << std::endl;
    map->initWorld();
    _map = map;
}

void Display::draw()
{
    this->_window->clear();

    // Draw entities
    drawMap();

    this->_window->display();
}

void Display::drawMap()
{
    // The idea
    int tileSize = 40;
    for (int j = 0; j < MAP_SIZE; j += 1)
        for (int i = 0; i < MAP_SIZE; i += 1)
        {
            if (_map->getMap()[j][i] == WALL)
            {
                _map->setPositionWall(j * tileSize, i * tileSize);
                _window->draw(_map->getWall());
            }
            if (_map->getMap()[j][i] == ROAD)
            {
                _map->setPositionGround(j * tileSize, i * tileSize);
                _window->draw(_map->getGround());
            }
    }
}