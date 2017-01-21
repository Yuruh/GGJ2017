//
// Created by wasta-geek on 20/01/17.
//

#ifndef GGJ2017_AENTITY_HPP
#define GGJ2017_AENTITY_HPP

#include <utility>
#include <Display/ASpritesHandler.hpp>

class AEntity : public ASpritesHandler
{
public:
    AEntity();
    virtual ~AEntity();
    const std::pair<float, float>   &getPos() const;
    void    setPos(float &y, float &x);

//   todo : pourquoi une référence ?
    virtual void    update(float&) = 0;
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
protected:
    std::pair<float, float>   _pos;
};


#endif //GGJ2017_AENTITY_HPP
