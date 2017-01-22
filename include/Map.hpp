//
// Created by babou on 20/01/17.
//

#ifndef GGJ2017_MAP_H
#define GGJ2017_MAP_H

#include    <array>
#include    <list>
#include    "Display/SfmlSpriteHandler.hpp"
#include    "Tile.hpp"

# define    MAP_Y       21
# define    MAP_X       41
# define    TILE_SIZE   40


class ATower;
class Monster;
class Projectile;

class Map {
public:
    Map();
    ~Map();

    void    initWorld();
    void    placeTower(std::list<ATower*> &towers, std::list<Monster*> &monsters,
                       std::list<Projectile*> &projs);

    inline const std::array<std::array<Tile, MAP_X>, MAP_Y> &getMap() const { return _map; };
    inline const SfmlSpriteHandler &getGround() const { return _ground; };
    inline const SfmlSpriteHandler &getWall() const { return _wall; };
    inline const SfmlSpriteHandler &getBlock() const { return _block;};
    inline const SfmlSpriteHandler &getCastle() const { return _castle;};
    inline const SfmlSpriteHandler &getTower() const { return _tower;};

    inline void setPositionWall(float y, float x) { _wall.setPosition(x, y); };
    inline void setPositionGround(float y, float x) { _ground.setPosition(x, y); };
    inline void setPositionBlock(float y, float x) { _block.setPosition(x, y); };
    inline void setPositionCastle(float y, float x) { _castle.setPosition(x, y); };
    inline void setPositionTower(float y, float x) { _tower.setPosition(x, y); };
    inline void setType(int y, int x, typeMap type) { _map[y][x] = type; };

    std::list<Tile*> getPath(const std::pair<int, int> &pos);


private:
    std::array<std::array<Tile, MAP_X>, MAP_Y>     _map;
    int     _towers;
    SfmlSpriteHandler _wall;
    SfmlSpriteHandler _ground;
    SfmlSpriteHandler _block;
    SfmlSpriteHandler _castle;
    SfmlSpriteHandler _tower;

public:

    void set_block(const SfmlSpriteHandler &_block);

    void launchAlgo(Tile *tile, std::list<Tile *> &dist);
};

#endif //GGJ2017_MAP_H
