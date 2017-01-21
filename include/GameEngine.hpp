//
// Created by yuruh on 20/01/17.
//

#ifndef GGJ2017_GAMEENGINE_HPP
#define GGJ2017_GAMEENGINE_HPP

#include "Map.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <Monsters/Monster.hpp>

class GameEngine
{
public:
    GameEngine() :
        _map(nullptr) {}

    void init(Map *map);
    void update(float deltaTime);
    void draw(sf::RenderWindow *window);
    void nextWave();
    void handleEvent(const std::pair<int, int> &event);

private:
    bool    _isLaunched;
    Map     *_map;
    Monster *testPathfinding;
    //    enemies, tower, projectiles, map, walls
};


#endif //GGJ2017_GAMEENGINE_HPP
