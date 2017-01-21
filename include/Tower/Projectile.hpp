//
// Created by thomas on 21/01/17.
//

#ifndef GGJ2017_PROJECTILE_H
#define GGJ2017_PROJECTILE_H

#include <Monsters/Monster.hpp>

class   Projectile
{
public:
    Projectile(int, int, Monster*);
    ~Projectile();
    int getRange() const;
    int getHit()   const;
    void setRange(int);
    void setHit(int);
    void setMonster(Monster*);

private:
    int _range;
    int _hit;
    Monster* _target;
};
#endif //GGJ2017_PROJECTILE_H
