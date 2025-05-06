#ifndef TILE_H
#define TILE_H
#include <iostream>

struct tile
{
    tile(unsigned int x, unsigned int y, int width, int height);
    bool isVisited;
    bool isWall;
    bool isEdge;
    std::string flag = "#";
    unsigned int x;
    unsigned int y;
};

#endif