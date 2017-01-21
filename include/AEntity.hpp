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
    std::pair<unsigned, unsigned>   &getPos();
    virtual void    update(float&) = 0;
protected:
    std::pair<unsigned, unsigned>   _pos;
};


#endif //GGJ2017_AENTITY_HPP
