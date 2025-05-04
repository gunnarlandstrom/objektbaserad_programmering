#ifndef LABYRINTH_H
#define LABYRINTH_H
#include <iostream>
#include <vector>
#include <string>

class labyrinth{


    labyrinth();

    labyrinth(size_t width, size_t height);

    ~labyrinth();

    void generateLabyrinth();

    void print() const;



    struct node {
        node(bool visited);
        bool visited;
        node* north;
        node* south;
        node* east;
        node* west;
    };
    node* startNode;
    node* endNode;
};



#endif