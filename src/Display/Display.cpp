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
    this->_window = new sf::RenderWindow(sf::VideoMode(MAP_Y * TILE_SIZE, 1000), "TOWER MAZE");
}

void Display::init(Map *map) // Will get everything from Core
{
    std::cout << "Display.init()" << std::endl;
//    map->initWorld();
    _map = map;
}

void Display::draw()
{
    this->_window->clear();

    // Draw entities
    drawGround();
    drawMonsters();
    drawMap();
    drawTowers();
    drawProjs();
    drawButtons();
    this->_window->display();
}

void Display::drawGround()
{
    for (int y = 0; y < MAP_Y; y += 1)
        for (int x = 0; x < MAP_X; x += 1)
        {
            _map->setPositionGround((float) y * TILE_SIZE, (float) x * TILE_SIZE);
            _window->draw(_map->getGround());
        }
}

void Display::drawMap()
{
    // The idea

    for (int y = 0; y < MAP_Y; y += 1)
        for (int x = 0; x < MAP_X; x += 1)
        {
            if (_map->getMap()[y][x] == WALL)
            {
                _map->setPositionWall((float)y * TILE_SIZE, ((float)x * TILE_SIZE) - 63 + TILE_SIZE);
                _window->draw(_map->getWall());
            }
            if (_map->getMap()[y][x] == BLOCK)
            {
                _map->setPositionBlock((float)y * TILE_SIZE, (float)x * TILE_SIZE - 51 + TILE_SIZE);
                _window->draw(_map->getBlock());
            }
            if (_map->getMap()[y][x] == TOWER)
            {
                _map->setPositionTower((float)y * TILE_SIZE, ((float)x * TILE_SIZE) - 61 + TILE_SIZE);
                _window->draw(_map->getTower());
            }
            if (_map->getMap()[y][x] == CASTLE)
                _window->draw(_map->getCastle());
        }
}

void Display::drawButtons()
{
    for (auto & button : _buttons) {
        if (button->isVisible()) {
            _window->draw(button->getSprite());
            _window->draw(button->getText());
        }
    }
}

void Display::drawMonsters()
{
    for (auto & monster : _monsters) {
        _window->draw(*monster);
    }
}

void Display::drawTowers() {
    for (auto & tower : _towers) {
        if (tower->getPhysicalAttack() != nullptr)
            _window->draw(*tower->getPhysicalAttack());
    }
}

void Display::drawProjs() {
    for (auto & proj : _projectiles) {
        _window->draw(*proj);
    }
}