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

private:
	// Variables
	size_t width;
	size_t height;

	// Functions
	void startMenu();
	void print();
	void initialize();
	void createMaze();
	void createBoard();
	void wantsToGenerateMaze();
	void markStart();
	void markEnd();
	void markNodes();
	void markOuterWalls();
	void drawPath(char direction);
	void markAsUnvisited();
	void solveMaze();
	void backtrack();
	void exitProgram();

	// move
	char randomizeDirection();
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
	bool isWallOrVisited(char direction);
	bool isWallSouth();
	bool isWallNorth();
	bool isWallEast();
	bool isWallWest();
	bool isStuck();

	// Positions
	std::pair<size_t, size_t> pos;
	std::pair<size_t, size_t> temp;
	std::pair<size_t, size_t> end;

	// Saved positions for backtrack
	std::stack<std::pair<size_t, size_t>> savedPosition;

	// Maze
	std::vector<std::vector<tile>> myMaze;

};

#endif