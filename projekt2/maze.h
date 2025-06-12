/*
// Project Maze
// Name: Gunnar Landström
// Date: 2025-05-18
// Grade: E
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
	labyrinth(size_t width, size_t height);
	void print();
	void solveMaze();
	void initialize();
	void setWidth(size_t width);
	void setHeight(size_t height);

private:
	// Variables
	size_t width;
	size_t height;

	// Functions
	void createMaze();
	void createBoard();
	void markStart();
	void markEnd();
	void markOuterNodes();
	void markAsUnvisited();
	std::pair<size_t, size_t> backtrack(std::pair<size_t, size_t> position);

	// moveFunc
	char randomizeDirection();
	bool canMove(char direction, std::pair<size_t, size_t> position);
	bool canMoveSouth(std::pair<size_t, size_t> position);
	bool canMoveNorth(std::pair<size_t, size_t> position);
	bool canMoveWest(std::pair<size_t, size_t> position);
	bool canMoveEast(std::pair<size_t, size_t> position);
	std::pair<size_t, size_t> move(char direction, std::pair<size_t, size_t> position);
	std::pair<size_t, size_t> moveSouth(std::pair<size_t, size_t> position);
	std::pair<size_t, size_t> moveNorth(std::pair<size_t, size_t> position);
	std::pair<size_t, size_t> moveWest(std::pair<size_t, size_t> position);
	std::pair<size_t, size_t> moveEast(std::pair<size_t, size_t> position);
	bool isStuck(std::pair<size_t, size_t> position);

	// 2D Maze
	std::vector<std::vector<node>> myMaze;

	// Saved positions for backtrack
	std::stack<std::pair<size_t, size_t>> savedPosition;
	// deque for drawing solution
	std::deque<char> walkedPath;
};
	
	void exitProgram();
	void startMenu();
	labyrinth wantsToGenerateMaze();
	

#endif