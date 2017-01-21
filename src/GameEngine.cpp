//
// Created by yuruh on 20/01/17.
//

#include "../include/GameEngine.hpp"
#include "Display/Button.hpp"

#include <iostream>
#include <SFML/Window/Event.hpp>


void GameEngine::init(Map * map) // Will get every lists from Core
{
    std::cout << "Engine.init()" << std::endl;
    _map = map;
    _isLaunched = false;
}

// Still needed?
void GameEngine::nextWave()
{
    if (!_isLaunched)
        _isLaunched = true;
    _map->placeTower(); // Need to pass tower list &
    std::cout << "NEXT WAVE" << std::endl;
}

void GameEngine::update(float deltaTime)
{
    // update stuff
}

// Still needed?
void GameEngine::draw(sf::RenderWindow *window)
{

}

void GameEngine::handleEvent(std::pair<int, int> &event)
{
    if (_isLaunched) {
        std::cout << "J'utilise dans le gameEngine un clic en pos " <<
                  event.first << " " << event.second << std::endl;
        return;
    }
    for (auto & button : _buttons)
        if (button->containMouse(event)) // Will need binding between button and behavior
            this->nextWave();
}
