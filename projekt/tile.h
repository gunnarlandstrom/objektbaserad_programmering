#ifndef TILE_H
#define TILE_H
#include <iostream>

struct tile
{
    tile(unsigned int x, unsigned int y);
    bool isVisited;
    bool isWall;
    std::string flag = "#";
    unsigned int x;
    unsigned int y;
};

#endif