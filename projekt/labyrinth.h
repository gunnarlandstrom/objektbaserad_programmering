#ifndef LABYRINTH_H
#define LABYRINTH_H
#include "tile.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <stack>

class labyrinth
{
public:
    labyrinth();

    labyrinth(size_t width, size_t height);
    void markStart();
    void markEnd();
    char randomizeDirection();
    bool isEdge();
    int canMove(char direction);
    void move(char direction);

    void initialize();

    ~labyrinth();

    void print();

private:
    size_t width;
    size_t height;
    
    // Current position
    std::pair<unsigned int, unsigned int> pos;
    
    // Ending
    std::pair<unsigned int, unsigned int> end;
    
    // Saved positions for backtrack
    std::stack<std::pair<unsigned int, unsigned int>> savedPosition;
    
    // Edges
    std::vector<tile> edges;
    
    // Maze
    std::vector<std::vector<tile>> myMaze;

};

#endif