#include <iostream>
#include <BasicTower.hpp>
#include "ATower.hpp"
#include "../include/GameEngine.hpp"
#include "../include/Core.hpp"

int testTom()
{
    /*ATower(int, int, double, int, int, MagickAttack const&, Projectile const&);*/
    //:ATower(int pv, int mp, double time_attack, int range, int speed, MagickAttack * magic, Projectile * projectile)
    MagickAttack *mag = new MagickAttack(0, 0);
    Projectile *proj = new Projectile(0, 0);
    ATower *_tow = new BasicTower(0, 0, 0, 0, 2, mag, NULL);
    _tow->Speak();
    _tow->setTime();
    int i;

    i = 0;
    while (i < 10) {
        std::cout << "I" << i << std::endl;
        _tow->canAttack();
        std::cout << _tow->getTime() << std::endl;
        _tow->changeTime();
        i++;
    }
    return (0);
}

int main()
{
    //testTom();
    Core::getInstance().run();

//    GameEngine  engine;
//    sf::RenderWindow    *window = new sf::RenderWindow(sf::)


//    std::cout << "Alors Antoine on perd sur Super Meat Boy ? :)" << std::endl;
    return 0;
}