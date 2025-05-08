#ifndef TILE_H
#define TILE_H
#include <iostream>

struct tile
{
    tile();
    tile(unsigned int x, unsigned int y);
    std::string flag = "+";
    unsigned int x;
    unsigned int y;
    bool isVisited;
    bool canVisitNorth;
    bool canVisitSouth;
    bool canVisitEast;
    bool canVisitWest;
};

#endif