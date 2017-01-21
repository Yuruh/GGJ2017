//
// Created by thomas on 21/01/17.
//

#ifndef GGJ2017_PROJECTILE_H
#define GGJ2017_PROJECTILE_H

class   Projectile
{
public:
    Projectile(int, int);
    ~Projectile();
    int getRange() const;
    int getHit()   const;
    void setRange(int);
    void setHit(int);

private:
    int _range;
    int _hit;
};
#endif //GGJ2017_PROJECTILE_H
