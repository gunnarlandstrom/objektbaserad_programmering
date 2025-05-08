#include "tile.h"
#include "labyrinth.h"

tile::tile(unsigned int x, unsigned int y)
{
    this->x = x;
    this->y = y;

    isVisited = false;
    canVisitNorth = true;
    canVisitWest = true;
    canVisitEast = true;
    canVisitSouth = true;
}

tile::tile()
{
}