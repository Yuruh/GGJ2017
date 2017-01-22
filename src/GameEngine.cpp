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
    _map = map;
    _isLaunched = false;
    _waves.init(map);
    this->testPathfinding = new Monster(10, 10, 10, 1);
}


void GameEngine::nextWave()
{
    if (!_isLaunched) {
        _isLaunched = true;
    }
    _map->placeTower(_towers, _monsters, _projectiles);
}

void GameEngine::update(float deltaTime)
{
    if (_isLaunched)
        _waves.updateWaves(deltaTime);
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
    for (auto monster = _monsters.begin(); monster != _monsters.end(); ++monster)
    {
        // Recalc path if there is a new block that blocks or way
        // Or if we don't have any direction to go
        if ((*monster)->hasBlockInPath() || !(*monster)->hasDirection())
            (*monster)->setNextPositions(_map->getPath((*monster)->getPos()));

        // Update
        (*monster)->update(deltaTime);

        // Delete monster if he is dead
        if ((*monster)->isDead)
        {
            monster = _monsters.erase(monster);
            if (monster == _monsters.end())
                return;
        }
    }
}

void GameEngine::updateProjs(float deltaTime)
{
        for (auto proj = _projectiles.begin(); proj != _projectiles.end(); ++proj) {

            if ((*proj)->getHP() == 0)
            {
                proj = _projectiles.erase(proj);
                if (proj == _projectiles.end())
                    return;
            }
            else
                (*proj)->update(deltaTime);
            // Need to check if proj had reached his target
        }
}

void GameEngine::updateTower(float deltaTime)
{
    for (auto & tower : _towers)
    {
        tower->update(deltaTime);
        if (tower->getPhysicalAttack() != nullptr)
            tower->getPhysicalAttack()->update(deltaTime);
    }
}

void GameEngine::handleEvent(std::pair<int, int> &event)
{
    if (_isLaunched)
    {
        // Manage Wall spawn
        if (event.second > 0 && event.second < MAP_Y * TILE_SIZE &&
            event.first > 0 && event.first < MAP_X * TILE_SIZE)
        {
            while (event.first % TILE_SIZE != 0)
                event.first -= 1;
            while (event.second % TILE_SIZE != 0)
                event.second -= 1;
            event.first /= TILE_SIZE;
            event.second /= TILE_SIZE;
            if (_map->getMap()[event.second][event.first] == ROAD)
            {
                for (auto &monster : _monsters)
                {
                    if (monster->getNextPos().first == event.first && monster->getNextPos().second == event.second)
                        return;
                }
//                std::cout << "je pose une pierre en " << event.first << " " << event.second << " aka " << &(_map->getMap()[event.first][event.second]) << std::endl;
                _blocks.push_back(new Wall(event.second, event.first));
                _map->setType(event.second, event.first, BLOCK);
            }
        }
        return;
    }

    for (auto & button : _buttons)
        if (button->containMouse(event)) // Will need binding between button and behavior
        {
            this->nextWave();
            button->setVisible(false);
        }
}