//
// Created by yuruh on 21/01/17.
//

#ifndef GGJ2017_CORE_HPP
#define GGJ2017_CORE_HPP

#include "GameEngine.hpp"
#include "Display/Display.hpp"
#include "Display/Button.hpp"
#include "Map.hpp"

#include <list>
#include <Tower/Projectile.hpp>
#include "Walls/Wall.hpp"
#include <Tower/BasicTower.hpp>
#include <Display/SFMLText.hpp>

class Core
{
private:
    Core() : 
        _map(nullptr) {}

    void init();

    static  Core        _instance;

    std::list<Button*>      _buttons;
    std::list<Monster*>     _monsters;
    std::list<Projectile*>  _projectiles;
    std::list<Wall*>        _blocks;
    std::list<ATower*>      _towers;

    GameEngine          _engine{ _buttons, _monsters, _towers, _blocks, _projectiles };
    Display             _display{ _buttons, _monsters, _towers, _projectiles };

    Map     *_map;

public:
    ~Core() {};
    static Core &getInstance();
    std::list<Monster*> & getMonster();
    std::list<ATower*> &_getTower();
    void addProjectile(int, int, Monster*);
    void addMonster(Monster*);
    void run();
};


#endif //GGJ2017_CORE_HPP
