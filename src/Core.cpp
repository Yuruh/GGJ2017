//
// Created by yuruh on 21/01/17.
//

#include <SFML/Window/Event.hpp>
#include <Display/TextureManager.hpp>
#include <Monsters/Soldier.hpp>
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
    // Init Map and all lists (ennemies, projectiles, towers, walls, buttons)
    _map = new Map();

    _engine.init(_map);// (Map, enemies, projectiles, towers, walls, button);
    _display.init(_map);// (Map, enemies, projectiles, towers, walls, button);

    Button  *_launchNextWave = new Button(TextureManager::get(TextureManager::BUTTON), L"\tLaunch next Wave.\n\t\tI'M READY !", sf::Vector2f(1980 / 2, 200));
    _buttons.push_back(_launchNextWave);

    Monster *soldier = new Soldier();
    _monsters.push_back(soldier);
    // Init window
    this->_display.run();
}

std::list<Monster*>& Core::getMonster() {
    return _monsters;
}

void Core::addProjectile(int hit, int range, Monster* _monster) {
    _projectile.push_back(new Projectile(range, hit, _monster));

}
