#ifndef TILE_H
#define TILE_H
#include <iostream>

struct tile
{
    tile(size_t x, size_t y);
    
    void markAsNode();

    void markAsOuterWall();
    size_t x;
    size_t y;

    std::string flag;
    bool isVisited;
    bool isNode;
    bool isOuterWall;
};

#endif