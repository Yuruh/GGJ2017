//
// Created by yuruh on 20/01/17.
//

#include <iostream>
#include "GameEngine.hpp"
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

        // Will have an IG_state to differenciate interaction with button (before game is launched) and
        // interaction with map (place a wall InGame)
        return;
    }
    for (auto & button : _buttons)
        if (button->containMouse(event))
            this->nextWave();

    int x = 0, y = 0, tileSize = 40;

    while (event.first % tileSize != 0)
        event.first -= 1;
    while (event.second % tileSize != 0)
        event.second -= 1;
    event.first /= tileSize;
    event.second /= tileSize;
    std::cout << event.first << " " << event.second << std::endl;
    if (_map->getMap()[event.first][event.second] == ROAD)
        _map->setType(event.first, event.second, BLOCK);
}
