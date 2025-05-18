#ifndef NODE_H
#define NODE_H
#include <iostream>

struct node
{
    node(size_t x, size_t y);
    
    void markAsOuterNodesNorth();
    void markAsOuterNodesSouth();
    void markAsOuterNodesEast();
    void markAsOuterNodesWest();

    size_t x;
    size_t y;

    std::string flag;
    std::string westFlag = "";
    std::string eastFlag = "";
    std::string northFlag = "";
    std::string southFlag = "";

    bool isVisited;
    bool isOuterWall;
    bool walkNorth;
    bool walkSouth;
    bool walkEast;
    bool walkWest;
};

#endif