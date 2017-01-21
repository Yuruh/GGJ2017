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

class Core
{
private:
    Core() : 
        _map(nullptr) {}

    void init();

    static  Core        _instance;

    Map     *_map;
    std::list<Button*>  _buttons;
    GameEngine          _engine{ _map, _buttons };
    Display             _display{ _map, _buttons };

public:
    ~Core() {};
    static Core &getInstance();

    void run();
};


#endif //GGJ2017_CORE_HPP
