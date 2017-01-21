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
#include <Monsters/Monster.hpp>

class Core
{
private:
    Core() : 
        _map(nullptr) {}

    void init();

    static  Core        _instance;

    std::list<Button*>  _buttons;
    std::list<Monster*>  _monsters;
    GameEngine          _engine{ _buttons };
    Display             _display{ _buttons, _monsters };

    Map     *_map;

public:
    ~Core() {};
    static Core &getInstance();
    std::list<Monster*> & getMonster();
    void run();
};


#endif //GGJ2017_CORE_HPP
