//
// Created by yuruh on 21/01/17.
//

#ifndef GGJ2017_CORE_HPP
#define GGJ2017_CORE_HPP

#include "GameEngine.hpp"
#include "Display/Display.hpp"
#include "Display/Button.hpp"
#include "Map.hpp"

class Core
{
private:
    Core() : 
        _map(nullptr) {}

    void init();

    static  Core        _instance;
    GameEngine          _engine;
    Display             _display;
    std::vector<Button*> _buttons;
    Map     *_map;

public:
    ~Core() {};
    static Core &getInstance();

    void run();
};


#endif //GGJ2017_CORE_HPP
