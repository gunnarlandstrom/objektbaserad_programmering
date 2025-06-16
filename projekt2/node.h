/*
// Project Maze
// Name: Gunnar Landström
// Date: 2025-05-18
// Grade: E
*/

#ifndef NODE_H
#define NODE_H
#include <iostream>

struct node
{
    node(size_t x, size_t y);
    
    // Funcs
    void markAsOuterNodesNorth();
    void markAsOuterNodesSouth();
    void markAsOuterNodesEast();
    void markAsOuterNodesWest();

    // Width Height positions in 2D container
    size_t x;
    size_t y;

    // Moveable checks
    bool isVisited;
    bool isOuterWall;
    bool walkNorth;
    bool walkSouth;
    bool walkEast;
    bool walkWest;
};

#endif