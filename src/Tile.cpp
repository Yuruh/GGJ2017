//
// Created by yuruh on 21/01/17.
//

#include "Tile.hpp"

bool Tile::operator==(typeMap type) const
{
    return this->type == type;
}

Tile &Tile::operator=(typeMap type)
{
    this->type = type;
    return *this;
}
