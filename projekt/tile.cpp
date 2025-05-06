#include "tile.h"

tile::tile(unsigned int x, unsigned int y)
{
    this->x = x;
    this->y = y;
    this->isVisited = false;
    this->isWall = true;
}