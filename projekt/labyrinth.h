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
	~labyrinth();

	// Functions
	void print();
	void createMaze();

private:
	// Variables
	size_t width;
	size_t height;

	// Functions
	void markOuterWalls();
	void createBoard();
	void markNodes();
	void initialize();
	char randomizeDirection();
	void markStart();
	void markEnd();
	bool isStuck();

	// Can move
	bool canMove(char direction);
	bool canMoveSouth();
	bool canMoveNorth();
	bool canMoveWest();
	bool canMoveEast();
	void move(char direction);
	void moveSouth();
	void moveNorth();
	void moveWest();
	void moveEast();
	
	// Current position
	std::pair<size_t, size_t> pos;

	// Saved positions for backtrack
	std::stack<std::pair<size_t, size_t>> savedPosition;

	// Maze
	std::vector<std::vector<tile>> myMaze;

};

#endif