//
// Created by yuruh on 20/01/17.
//

#ifndef GGJ2017_GAMEENGINE_HPP
#define GGJ2017_GAMEENGINE_HPP

#include <SFML/Graphics/RenderWindow.hpp>

class GameEngine
{
private:
//    enemies, tower, projectiles, map, walls
public:
    GameEngine();
    ~GameEngine();
    void init();
    void go();
    void update(float deltaTime);
    void draw(sf::RenderWindow *window);

    void handleEvent(const std::pair<int, int> &event);
};


#endif //GGJ2017_GAMEENGINE_HPP
