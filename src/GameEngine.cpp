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
    _map->placeTower(_towers, _monsters, _projectiles);

    std::cout << "NEXT WAVE" << std::endl;
}

void GameEngine::update(float deltaTime)
{
    updateBlock(deltaTime);
    updateMonster(deltaTime);
    updateProjs(deltaTime);
    updateTower(deltaTime);
}

void GameEngine::updateBlock(float deltaTime)
{
    for (auto block = _blocks.begin(); block != _blocks.end(); ++block) {
        (*block)->update(deltaTime);
        if ((*block)->getTimeSinceCreated() >= WALL_DURATION)
        {
            _map->setType((*block)->getY(), (*block)->getX(), ROAD);
            block = _blocks.erase(block);
            if (block == _blocks.end())
                return;
        }
    }
}

void GameEngine::updateMonster(float deltaTime)
{
    for (auto & monster : _monsters) {
        // il peut arriver que le mur posé par un joueur casse les direction d'un monstre, auquel cas on recalcule son path
        if (!monster->hasDirection())
            monster->setNextPositions(_map->getPath(monster->getPos()));
        monster->update(deltaTime);
    }
}

void GameEngine::updateProjs(float deltaTime)
{
    for (auto & proj : _projectiles) {
        proj->update(deltaTime);
        // Need to check if proj had reached his target
    }
}

void GameEngine::updateTower(float deltaTime)
{
    for (auto & tower : _towers) {
        tower->update(deltaTime);
        if (tower->getPhysicalAttack() != nullptr)
            tower->getPhysicalAttack()->update(deltaTime);
    }
}


void GameEngine::handleEvent(std::pair<int, int> &event)
{
    if (_isLaunched) {
        std::cout << "J'utilise dans le gameEngine un clic en pos " <<
                  event.first << " " << event.second << std::endl;

        // Manage Wall spawn
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