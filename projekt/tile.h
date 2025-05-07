#ifndef TILE_H
#define TILE_H
#include <iostream>

struct tile
{
    tile();
    tile(unsigned int x, unsigned int y, int width, int height);
    bool isVisited;
    bool isWall;
    bool isEdge;
    std::string flag = "+";
    unsigned int x;
    unsigned int y;
    std::pair<int,int> north;
    std::pair<int,int> south;
    std::pair<int,int> west;
    std::pair<int,int> east;

};

#endif