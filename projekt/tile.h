#ifndef TILE_H
#define TILE_H
#include <iostream>

struct tile
{
    tile();
    bool isVisited;
    bool isWall = true;
    std::string flag = "#";
};

#endif