//
// Created by babou on 20/01/17.
//

#include    "Map.hpp"
#include    "BasicTower.hpp"
#include    "Monsters/Monster.hpp"
#include    "Projectile.hpp"
#include    "Display/TextureManager.hpp"

#include    <iostream>
#include    <cstdlib>
#include    <ctime>
#include <queue>

Map::Map() : _wall(TextureManager::get(TextureManager::WALL)),
             _ground(TextureManager::get(TextureManager::GROUND)),
             _block(TextureManager::get(TextureManager::BLOCK)),
             _castle(TextureManager::get(TextureManager::CASTLE)),
             _tower(TextureManager::get(TextureManager::TOWER))
{
    _towers = MAP_SIZE;

    this->initWorld();
}

Map::~Map()
{
}

void        Map::initWorld()
{
    // Build wall
    for (int y = 0; y < MAP_SIZE; y += 1)
        for (int x = 0; x < MAP_SIZE; x += 1)
        {
            if (y % 2 == 0 && x % 2 == 0)
                _map[y][x] = WALL;
            else
                _map[y][x] = ROAD;

//                légal de passer l'adresse ?
            _map[y][x].y = y;
            _map[y][x].x = x;

        }
    for (int y = 0; y < MAP_SIZE; y += 1)
        for (int x = 0; x < MAP_SIZE; x += 1)
        {
            if (x < MAP_SIZE - 1)// && _map[y][x + 1] == ROAD)
                _map[y][x].links.push_back(&_map[y][x + 1]);
            if (x > 0)// && _map[y][x - 1] == ROAD)
                _map[y][x].links.push_back(&_map[y][x - 1]);
            if (y < MAP_SIZE - 1)// && _map[y + 1][x] == ROAD)
                _map[y][x].links.push_back(&_map[y + 1][x]);
            if (y > 0)// && _map[y - 1][x] == ROAD)
                _map[y][x].links.push_back(&_map[y - 1][x]);
        }


    // Build castle
    _map[(MAP_SIZE - 2) / 2][(MAP_SIZE - 2) / 2] = CASTLE;
    _map[(MAP_SIZE - 2) / 2][(MAP_SIZE - 1) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE - 2) / 2][(MAP_SIZE + 1) / 2] = BORDER_CASTLE;

    _map[(MAP_SIZE - 1) / 2][(MAP_SIZE - 2) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE - 1) / 2][(MAP_SIZE - 1) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE - 1) / 2][(MAP_SIZE + 1) / 2] = BORDER_CASTLE;

    _map[(MAP_SIZE + 1) / 2][(MAP_SIZE - 2) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE + 1) / 2][(MAP_SIZE - 1) / 2] = BORDER_CASTLE;
    _map[(MAP_SIZE + 1) / 2][(MAP_SIZE + 1) / 2] = BORDER_CASTLE;

    setPositionCastle(((MAP_SIZE - 2) / 2) * TILE_SIZE, ((MAP_SIZE - 2) / 2) * TILE_SIZE);
}

void        Map::placeTower(std::list<ATower*> &towers, std::list<Monster*> &monsters,
                            std::list<Projectile*> &projs)
{
    int y = rand() % MAP_SIZE;
    int x = rand() % MAP_SIZE;

    if (_map[y][x] == WALL)
    {
        // Create new tower in map
        _map[y][x] = TOWER;

        // instantiate new tower
        auto new_tower = new BasicTower((y - 0.5f) * TILE_SIZE, (x - 1.3f) * TILE_SIZE, 10, 10, 5, 5.0,
            nullptr, nullptr,
            monsters, projs);

        // Set tile postition and proportions
        new_tower->setPosition((y - 0.5f) * TILE_SIZE, (x - 1.3f) * TILE_SIZE);
        new_tower->setProportionalSize(70, 70);

        // Push new tower in towers list
        towers.push_back(new_tower);

        // Decrease total tower number
        _towers -= 1;
    }

    if (_towers > 0)
        placeTower(towers, monsters, projs);
}

//todo opti ?
std::list<std::pair<int, int> > Map::getPath(const std::pair<int, int> &pos)
{
    std::list<std::pair<int, int> >   ret;

    for (int i = 0; i < this->_map.size(); ++i)
    {
        for (int j = 0; j < this->_map[i].size(); ++j)
        {
            _map[i][j].dist = -1;
            _map[i][j].visited = false;
            _map[i][j].prev = nullptr;
        }
    }
//    std::cout << pos.first << " " << pos.second << std::endl;
    Tile    *current = &this->_map[pos.first][pos.second];
    current->dist = 0;
//    current->visited = true;
    std::vector <Tile*>   dist;
    this->launchAlgo(current, dist);

    auto prev = _map[(MAP_SIZE - 2) / 2][(MAP_SIZE - 2) / 2].prev;

    while (prev != nullptr)
    {
        std::cout << prev->dist << std::endl;
        ret.push_front(std::pair<int, int>(prev->x, prev->y));
        prev = prev->prev;
    }

    ret.push_back(std::pair<int, int>(0, 1));

//    exit(1);
    return ret;
}

bool    cmpTile(Tile *a, Tile *b)
{
    return a->dist < b->dist;
}

void Map::launchAlgo(Tile *tile, std::vector<Tile*> &dist)
{
    tile->visited = true;

//    std::vector <Tile*>   dist;

//    std::cout << tile->x << " " << tile->y << ": " << tile->dist << std::endl;
    for (auto it = tile->links.begin(); it != tile->links.end(); ++it)
    {
//        std::cout << tile->links.size() << std::endl;
        if (!(*it)->visited && (*it)->type == ROAD || (*it)->type == BORDER_CASTLE || (*it)->type == CASTLE)
        {
            if ((*it)->dist == -1 || (*it)->dist > tile->dist + 1)
            {
                (*it)->dist = tile->dist + 1;
                (*it)->prev = tile;
            }
            dist.push_back(*it);
        }
    }
//    std::sort(dist.begin(), dist.end(), cmpTile);
    while (!dist.empty() && dist[0]->visited)
    {
        dist.erase(dist.begin());
    }
    if (!dist.empty())
    {
        auto instance = dist[0];
        dist.erase(dist.begin());
        launchAlgo(instance, dist);
    }
//    for (int i = 0; i < dist.size(); ++i)
//    {
//        if (!dist[i]->visited)
//            launchAlgo(dist[i]);
//    }

//    if (next != nullptr)
//        launchAlgo(next);
}

