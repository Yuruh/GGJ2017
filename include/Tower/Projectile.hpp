//
// Created by thomas on 21/01/17.
//

#ifndef GGJ2017_PROJECTILE_H
#define GGJ2017_PROJECTILE_H

#include <Monsters/Monster.hpp>


class   Projectile : public AEntity
{
public:
    Projectile(float, float, int, int, Monster*);
    ~Projectile();
    int getRange() const;
    int getHit()   const;
    void setRange(int);
    void setHit(int);
    void setMonster(Monster*);
    void update(float &deltaTime);
    void draw(sf::RenderTarget &target, sf::RenderStates) const;
    void resetPos(float _x, float _y);

private:
    int _range;
    int _hit;
    float _ori;
    float _x;
    float _y;
    Monster* _target;
};
#endif //GGJ2017_PROJECTILE_H
