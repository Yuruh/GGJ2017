//
// Created by yuruh on 20/01/17.
//

#ifndef GGJ2017_GAMEENGINE_HPP
#define GGJ2017_GAMEENGINE_HPP

#include "Map.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <Monsters/Monster.hpp>
#include "Walls/Wall.hpp"
#include <list>

class Button;

class GameEngine
{
public:
    GameEngine(std::list<Button*> &b, std::list<Monster*> &m, std::list<Wall*> &w) :
        _map(nullptr), _buttons{ b }, _monsters{ m }, _blocks { w } {}

    void init(Map *map);
    void update(float deltaTime);
    void draw(sf::RenderWindow *window);
    void nextWave();
    void handleEvent(std::pair<int, int> &event);

private:
    bool    _isLaunched;

    Map     *_map;
    Monster *testPathfinding;
    std::list<Button*>  &_buttons;
    std::list<Monster*>  &_monsters;
    std::list<Wall*>  &_blocks;
};


#endif //GGJ2017_GAMEENGINE_HPP
