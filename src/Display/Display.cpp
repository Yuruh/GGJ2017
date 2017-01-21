//
// Created by yuruh on 21/01/17.
//

#include "Display/Display.hpp"
#include "Display/Button.hpp"

#include <SFML/Window/Event.hpp>
#include <iostream>

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
    drawMonsters();
    drawTowers();
    drawButtons();
    this->_window->display();
}

void Display::drawMap()
{
    // The idea
    int tileSize = 40;
    for (int y = 0; y < MAP_SIZE; y += 1)
        for (int x = 0; x < MAP_SIZE; x += 1)
        {
            if (_map->getMap()[y][x] == WALL ||
                    _map->getMap()[y][x] == TOWER)
            {
                _map->setPositionWall(y * tileSize, x * tileSize);
                _window->draw(_map->getWall());
            }
            if (_map->getMap()[y][x] == ROAD ||
                    _map->getMap()[y][x] == CASTLE ||
                    _map->getMap()[y][x] == BORDER_CASTLE)
            {
                _map->setPositionGround(y * tileSize, x * tileSize);
                _window->draw(_map->getGround());
            }
            if (_map->getMap()[y][x] == BLOCK)
            {
                _map->setPositionBlock(y * tileSize, x * tileSize);
                _window->draw(_map->getBlock());
            }
    }
    _window->draw(_map->getCastle());
}

void Display::drawButtons()
{
    for (auto & button : _buttons) {
        _window->draw(button->getSprite());
        _window->draw(button->getText());
    }
}

void Display::drawMonsters()
{
    for (auto & monster : _monsters) {
        _window->draw(*monster);
    }
}

void Display::drawTowers() {
    std::cout << "Tower size: " << _towers.size() << std::endl;
    for (auto & tower : _towers) {
        _window->draw(*tower);
    }
}
