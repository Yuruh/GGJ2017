//
// Created by yuruh on 21/01/17.
//

#include <SFML/Window/Event.hpp>
#include <Display/TextureManager.hpp>
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
    // Init resources
    // Loader.init();

    // Init Map and all lists (ennemies, projectiles, towers, walls, buttons)
    _map = new Map(); // Will take Loader as parameter

    _engine.init(_map);// (Map, enemies, projectiles, towers, walls, button);
    _display.init(_map);// (Map, enemies, projectiles, towers, walls, button);

    Button  *_launchNextWave = new Button(TextureManager::get(TextureManager::BUTTON), L"\tLaunch next Wave.\n\t\tI'M READY !", sf::Vector2f(1980 / 2, 200));
    _buttons.push_back(_launchNextWave);
    // Init window
    this->_display.run();
}