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
    this->_display.run();
    sf::Clock   clock;

    while (this->_display.isActive())
    {
        sf::Time deltaTime = clock.getElapsedTime();
        this->_engine.update(deltaTime.asSeconds());
        this->_display.draw();
        std::pair<int, int> event = this->_display.getEvent();
        if (event.first != -1 && event.second != -1)
            this->_engine.handleEvent(event);
    }
}
