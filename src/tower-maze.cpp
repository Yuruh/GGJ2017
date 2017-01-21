#include <iostream>
#include <BasicTower.hpp>
#include <zconf.h>
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
    _tow->canAttack();
    _tow->changeTime();
    std::cout << _tow->getTime() << std::endl;
    sleep(1);
    _tow->changeTime();
    std::cout << _tow->getTime() << std::endl;
    sleep(1);
    _tow->changeTime();
    _tow->canAttack();
    std::cout << _tow->getTime() << std::endl;
    _tow->changeTime();
    std::cout << _tow->getTime() << std::endl;
    sleep(1);
    _tow->changeTime();
    std::cout << _tow->getTime() << std::endl;
}
int main()
{
    Core::getInstance().run();
//    GameEngine  engine;
//    sf::RenderWindow    *window = new sf::RenderWindow(sf::)


//    std::cout << "Alors Antoine on perd sur Super Meat Boy ? :)" << std::endl;
    return 0;
}