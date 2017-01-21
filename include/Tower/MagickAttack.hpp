//
// Created by thomas on 21/01/17.
//

#ifndef GGJ2017_MAGICKATTACK_H
#define GGJ2017_MAGICKATTACK_H

enum TypeMagic {
    FIRE,
    WATER,
    ICE,
    WIND
};

enum Target
{
    FRIEND,
    FOE
};

class   MagickAttack
{
public:
    MagickAttack(int, int);
    ~MagickAttack();

    int getRange() const;
    int getHit()   const;

    Target getTarget() const;
    TypeMagic getTypeMagic() const;

    void setTarget(Target);
    void setTypeMagic(TypeMagic);

    void setRange(int);
    void setHit(int);

private:
    int _range;
    int _hit;
    Target _target;
    TypeMagic  _typeMagic;


};
#endif //GGJ2017_MAGICKATTACK_H
