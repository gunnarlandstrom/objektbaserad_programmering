#include "tile.h"
#include "labyrinth.h"

tile::tile(unsigned int x, unsigned int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->isVisited = false;
    this->isWall = true;
    if (x == 0 || x == width - 1)
    {
        isEdge = true;
        isWall = true;
        flag = "#";
    }
    else if (y == 0 || y == height - 1)
    {
        isEdge = true;
        isWall = true;
        flag = "#";
    }
    else
    {
        isEdge = false;
    }
}

tile::tile()
{
}