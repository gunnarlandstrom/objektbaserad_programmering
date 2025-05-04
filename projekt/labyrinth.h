#ifndef LABYRINTH_H
#define LABYRINTH_H
#include <iostream>
#include <vector>
#include <string>
#include "tile.h"
#include <random>

class labyrinth
{
public:
    labyrinth();

    labyrinth(size_t width, size_t height);
    void markStart();
    void markEnd();
    char randomizeDirection();
    bool canMove(int row, int col);

    void initialize();

    ~labyrinth();


    void print();
    
    private:
    size_t width;
    size_t height;
    std::vector<std::vector<tile>> myMaze;
};

#endif