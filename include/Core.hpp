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
#include <Tower/BasicTower.hpp>

class Core
{
private:
    Core() : 
        _map(nullptr) {}

    void init();

    static  Core        _instance;

    std::list<Button*>  _buttons;
    std::list<Monster*>  _monsters;
    std::list<Projectile*>  _projectile;
    std::list<ATower*>  _towers;
    GameEngine          _engine{ _buttons, _monsters, _towers };
    Display             _display{ _buttons, _monsters, _towers };

    Map     *_map;

public:
    ~Core() {};
    static Core &getInstance();
    std::list<Monster*> & getMonster();
    std::list<ATower*> &_getTower();
    void addProjectile(int, int, Monster*);
    void run();
};


#endif //GGJ2017_CORE_HPP
