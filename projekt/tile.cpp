#include "tile.h"

tile::tile(size_t x, size_t y)
{
    this->x = x;
    this->y = y;
    this->flag = "#";
    this->isVisited = false;
    this->isNode = false;
    this->isOuterWall = false;
}

void tile::markAsOuterWall()
{
    this->flag = "#";
    this->isOuterWall = true;
}

void tile::markAsNode() {
    this->flag = "#";
    this->isNode = true;
}