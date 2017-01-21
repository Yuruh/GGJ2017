//
// Created by yuruh on 21/01/17.
//

#include <SFML/Window/Event.hpp>
#include "../include/Core.hpp"

Core    Core::_instance = Core();

Core &Core::getInstance()
{
    return _instance;
}

void Core::run()
{
    this->init();

    sf::Clock   clock;
    while (this->_display.isActive())
    {
        // Event update
        std::pair<int, int> event = this->_display.getEvent();
        if (event.first != -1 && event.second != -1)
            this->_engine.handleEvent(event);

        sf::Time deltaTime = clock.getElapsedTime();
        this->_engine.update(deltaTime.asSeconds());

        this->_display.draw();
    }
}

void Core::init()
{
    // Initialization
    this->_display.run();

    // Init Map and all lists (ennemies, projectiles, towers, walls, buttons)
    _map = new Map();

    _engine.init(_map);// (Map, enemies, projectiles, towers, walls, button);
    _display.init(_map);// (Map, enemies, projectiles, towers, walls, button);
}