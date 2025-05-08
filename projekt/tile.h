#ifndef TILE_H
#define TILE_H
#include <iostream>

struct tile
{
    tile(size_t x, size_t y);
    void markAsNode();
    void markAsOuterWall();
    std::string flag;
    size_t x;
    size_t y;
    bool isVisited;
    bool isNode;
    bool isOuterWall;
};

#endif