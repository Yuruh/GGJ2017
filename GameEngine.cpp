//
// Created by yuruh on 20/01/17.
//

#include <iostream>
#include <SFML/Window/Event.hpp>
#include "GameEngine.hpp"

GameEngine::GameEngine()
{
    this->init();
}

GameEngine::~GameEngine()
{

}

void GameEngine::init()
{

}

void GameEngine::go()
{

}

void GameEngine::update(float deltaTime)
{

}

void GameEngine::draw(sf::RenderWindow *window)
{

}

void GameEngine::handleEvent(const std::pair<int, int> &event)
{
    std::cout << "J'utilise dans le gameEngine un clic en pos " <<
              event.first << " " << event.second << std::endl;
}
