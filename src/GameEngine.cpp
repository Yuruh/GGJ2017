//
// Created by yuruh on 20/01/17.
//

#include <iostream>
#include "GameEngine.hpp"
#include "Display/Button.hpp"

#include <iostream>
#include <SFML/Window/Event.hpp>
#include <Tower/BasicTower.hpp>


void GameEngine::init(Map * map) // Will get every lists from Core
{
    std::cout << "Engine.init()" << std::endl;
    _map = map;
    _isLaunched = false;

    this->testPathfinding = new Monster(10, 10, 10, 1);
}


void GameEngine::nextWave()
{
    if (!_isLaunched) {
        _isLaunched = true;
    }
    _map->placeTower(_towers, _monsters);
    std::cout << "NEXT WAVE" << std::endl;
}

void GameEngine::createTower() {
    int x;
    int y;

    x = 300.0;
    y = 100.0;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Draw tower!" << std::endl;
        _towers.push_back(new BasicTower(x, y, 10, 10, 5, 5.0, nullptr, nullptr, _monsters));
        x += 100.0;
        if (x >= 900) {
            x = 100.0;
            y += 100.0;
        }
    }
}

void GameEngine::update(float deltaTime)
{
    for (auto & monster : _monsters)
    {
        monster->update(deltaTime);
    }
    for (auto block = _blocks.begin(); block != _blocks.end(); ++block)
    {
        (*block)->update(deltaTime);
        if ((*block)->getTimeSinceCreated() >= WALL_DURATION)
        {
            _map->setType((*block)->getY(), (*block)->getX(), ROAD);
            block = _blocks.erase(block);
        }
    }

    for (auto & tower : _towers)
    {
        tower->update(deltaTime);
    }
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

        if (event.first > 0 && event.first < MAP_SIZE * TILE_SIZE &&
            event.second > 0 && event.second < MAP_SIZE * TILE_SIZE)
        {
            while (event.first % TILE_SIZE != 0)
                event.first -= 1;
            while (event.second % TILE_SIZE != 0)
                event.second -= 1;
            event.first /= TILE_SIZE;
            event.second /= TILE_SIZE;
            if (_map->getMap()[event.first][event.second] == ROAD)
            {
                _blocks.push_back(new Wall(event.first, event.second));
                _map->setType(event.first, event.second, BLOCK);
            }
        }
        return;
    }

    for (auto & button : _buttons)
        if (button->containMouse(event)) // Will need binding between button and behavior
            this->nextWave();
}