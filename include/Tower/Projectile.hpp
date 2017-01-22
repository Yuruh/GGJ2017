//
// Created by thomas on 21/01/17.
//

#ifndef GGJ2017_PROJECTILE_H
#define GGJ2017_PROJECTILE_H

#include <Monsters/Monster.hpp>


class   Projectile : public AEntity
{
public:
    Projectile(float, float, int, int, Monster &);

    void update(float &deltaTime);
   
    void draw(sf::RenderTarget &target, sf::RenderStates) const;

    bool checkCollision();

    inline int  getRange() const    { return _range; }
    inline int  getHit()   const    { return _hit; }
    inline int  getHP()    const    { return _hp; }
    inline void setRange(int range)     { _range = range; }
    inline void setHit(int hit)         { _hit = hit; }
    inline void setMonster(Monster &t)  { _target = t; }

private:
    float   _x;
    float   _y;
    float   _init_x;
    float   _init_y;
    int     _range;
    int     _hit;
    int     _hp;
    float   _speed;

    Monster &_target;
};
#endif //GGJ2017_PROJECTILE_H
