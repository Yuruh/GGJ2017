//
// Created by yuruh on 20/01/17.
//

#ifndef GGJ2017_GAMEENGINE_HPP
#define GGJ2017_GAMEENGINE_HPP

#include "Map.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <Monsters/Monster.hpp>
#include "Walls/Wall.hpp"
#include "WaveManager.hpp"
#include "Sound.hpp"
#include <Tower/ATower.hpp>
#include <list>
#include "Sound.hpp"

class Button;

class GameEngine
{
public:
    GameEngine(std::list<Button*> &b, std::list<Monster*> &m, std::list<ATower*> &t,
        std::list<Wall*> &w, std::list<Projectile*> &p) :
        _map(nullptr), _buttons{ b }, _monsters{ m }, _towers{ t }, _blocks{ w }, _projectiles{ p } {}

    void init(Map *map);
    void update(float deltaTime);
    void draw(sf::RenderWindow *window);
    void nextWave();
    void createTower();
    void handleEvent(std::pair<int, int> &event);

private:
    void updateBlock(float deltaTime);
    void updateMonster(float deltaTime);
    void updateProjs(float deltaTime);
    void updateTower(float deltaTime);

    bool    _isLaunched;
    WaveManager _waves;
    Map     *_map;
    Monster *testPathfinding;
    Sound   *_sound;
    std::list<Button*>      &_buttons;
    std::list<Monster*>     &_monsters;
    std::list<Wall*>        &_blocks;
    std::list<ATower*>      &_towers;
    std::list<Projectile*>  &_projectiles;
};


#endif //GGJ2017_GAMEENGINE_HPP
