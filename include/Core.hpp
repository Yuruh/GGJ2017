//
// Created by yuruh on 21/01/17.
//

#ifndef GGJ2017_CORE_HPP
#define GGJ2017_CORE_HPP

#include "GameEngine.hpp"
#include "Display.hpp"

class Core
{
private:
    Core() {};

    void init();

    static  Core        _instance;
    GameEngine          _engine;
    Display             _display;



public:
    ~Core() {};
    static Core &getInstance();

    void run();
};


#endif //GGJ2017_CORE_HPP
