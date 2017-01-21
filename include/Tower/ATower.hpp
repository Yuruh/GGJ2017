//
// Created by thomas on 20/01/17.
//

#ifndef GGJ2017_ITOWER_H
#define GGJ2017_ITOWER_H

#include <ctime>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <ActiveElement.hpp>
#include "Map.hpp"
#include "Projectile.hpp"
#include "MagickAttack.hpp"
#include "Monsters/Monster.hpp"

class Core;
class ATower : public ActiveElement
{
public:
    ATower(float, float, unsigned int, int, int, float, MagickAttack *, Projectile *, std::list<Monster*> &);
    ~ATower();

    bool canAttack();
    int  PhysicialAttack();
    int  MagicalAttack();

    int getMp() const;
    void setMp(int) ;

    void    changeTime();

    int getRange() const;
    void setRange(int);

    MagickAttack* getMagickAttack() const;
    void                setMagickAttack(MagickAttack const&);

    Projectile * getPhysicalAttack() const;
    void                setPhysicalAttack(Projectile const&);

    void                setMonsters(std::list<Monster*>& monsters);

    virtual void        Speak() const = 0;

    void                update(float&);

    void                attack(ActiveElement&);
    int                 nearestMonster(std::list<Monster*>& );
    bool                isInCircle(const sf::Vector2f&, float dist);
    bool                hadRunAway();

protected:
    void                draw(sf::RenderTarget &, sf::RenderStates) const;

private:
    int _mp;
    int _range;
    MagickAttack    *_magic;
    Projectile *_attack;
    Monster    *_target;
    std::list<Monster*>& _monsters;
    time_t timer;
    int _hp;
    int _atkSpeed;
    float _x;
    float _y;
    float _dist;
};
#endif //GGJ2017_ITOWER_H
