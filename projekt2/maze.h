/*
// Project Maze
// Name: Gunnar Landström
// Date: 2025-05-18
// Grade: E+
*/

#ifndef MAZE_H
#define MAZE_H
#include "node.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <stack>

class labyrinth
{
public:
	labyrinth();
	~labyrinth();

	// Functions
	void startMenu();
private:
	// Variables
	size_t width;
	size_t height;

	// Functions
	void print();
	void initialize();
	void createMaze();
	void createBoard();
	void wantsToGenerateMaze();
	void markStart();
	void markEnd();
	void markOuterNodes();
	void markAsUnvisited();
	void solveMaze();
	void backtrack();
	void exitProgram();

	// moveFunc
	void drawPath(char direction);
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
	bool isStuck();

	// Positions
	std::pair<size_t, size_t> pos;
	std::pair<size_t, size_t> temp;
	std::pair<size_t, size_t> end;

	// Saved positions for backtrack
	std::stack<std::pair<size_t, size_t>> savedPosition;
	// deque for drawing solution
	std::deque<char> walkedPath;

	// 2D Maze
	std::vector<std::vector<node>> myMaze;

};

#endif