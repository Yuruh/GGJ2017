//
// Created by wasta-geek on 20/01/17.
//

#ifndef GGJ2017_AENTITY_HPP
#define GGJ2017_AENTITY_HPP

#include <utility>

class AEntity
{
public:
    AEntity();
    virtual ~AEntity();
    const std::pair<float, float>   &getPos() const;
    void    setPos(float &y, float &x);
    virtual void    update(float&) = 0;
protected:
    std::pair<float, float>   _pos;
};


#endif //GGJ2017_AENTITY_HPP
