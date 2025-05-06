#ifndef LABYRINTH_H
#define LABYRINTH_H
#include "tile.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>

class labyrinth
{
public:
    labyrinth();

    labyrinth(size_t width, size_t height);
    void markStart();
    void markEnd();
    char randomizeDirection();
    bool isEdge();
    int canMove(int row, int col, char direction);
    void move(char direction, int steps);

    void initialize();

    ~labyrinth();

    void print();
    
    private:
    size_t width;
    size_t height;
    std::pair<unsigned int, unsigned int> mover;
    std::pair<unsigned int, unsigned int> end;
    std::vector<std::pair<unsigned int, unsigned int>> savedPosition;
    std::vector<std::vector<tile>> myMaze;
};

#endif