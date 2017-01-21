//
// Created by yuruh on 20/01/17.
//

#include <iostream>
#include <SFML/Window/Event.hpp>
#include "../include/GameEngine.hpp"

void GameEngine::init(Map * map) // Will get every lists from Core
{
    std::cout << "Engine.init()" << std::endl;
}

void GameEngine::go()
{

}

void GameEngine::update(float deltaTime)
{
    // update stuff
}

// Still needed?
void GameEngine::draw(sf::RenderWindow *window)
{

}

void GameEngine::handleEvent(const std::pair<int, int> &event)
{
    std::cout << "J'utilise dans le gameEngine un clic en pos " <<
              event.first << " " << event.second << std::endl;
}
