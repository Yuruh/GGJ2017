#include <iostream>
#include <BasicTower.hpp>
#include "ATower.hpp"
#include "../include/GameEngine.hpp"
#include "../include/Core.hpp"
#include "Monsters/Soldier.hpp"

int testTom()
{
Soldier soldier;
    /*ATower(int, int, double, int, int, MagickAttack const&, Projectile const&);*/
    //:ATowerint pv, int mp, double time_attack, int range, int speed, MagickAttack * magic, Projectile * projectile)
    MagickAttack *mag = new MagickAttack(0, 0);
    Projectile *proj = new Projectile(0, 0);
    //(float x, float y, unsigned int hp, int mp, int range, float atkSpeed, MagickAttack * magic, Projectile * projectile)
    ATower *_tow = new BasicTower(0.0, 0.0, 0, 0, 0, 2.0, mag, NULL);
    _tow->Speak();
    int i;

    i = 0;
    while (i < 10) {
        std::cout << "I" << i << std::endl;
        _tow->canAttack();
        std::cout << _tow->getTimeSinceAtk() << std::endl;
        i++;
    }
    return (0);
}

int main()
{
    //testTom();
//    Core::getInstance().run();

//    GameEngine  engine;
//    sf::RenderWindow    *window = new sf::RenderWindow(sf::)


//    std::cout << "Alors Antoine on perd sur Super Meat Boy ? :)" << std::endl;
    return 0;
}