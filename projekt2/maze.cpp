/*
// Project Maze
// Name: Gunnar Landström
// Date: 2025-05-18
// Grade: E
*/

#include "maze.h"
#include "node.h"

labyrinth::labyrinth()
{
	this->height = 7;
	this->width = 7;
	initialize();
}

labyrinth::labyrinth(size_t width, size_t height) {
	this->height = height;
	this->width = width;
	initialize();
}

// Generates the maze
void labyrinth::initialize()
{
	createBoard();
	markStart();
	markOuterNodes();
	createMaze();
	//markAsUnvisited();
}


void labyrinth::setWidth(size_t width) {

	this->width = width;
}

void labyrinth::setHeight(size_t height) {
	this->height = height;
}


void labyrinth::createMaze()
{
	std::pair<size_t, size_t> position = { 0,0 };

	walkedPath.clear();
	savedPosition.push(position);
	while (savedPosition.size() != 0)
	{
		char direction = randomizeDirection();
		bool moveable = canMove(direction, position);
		if (moveable)
		{
			position = move(direction, position);
		}
		else
		{
			if (isStuck(position))
			{
				if (savedPosition.size() != 0)
				{
					position = backtrack(position);
				}
			}
		}
	}
}

void exitProgram()
{
	std::cout << "Exiting program, until next time!" << std::endl;
	exit(0);
}

/*
void labyrinth::solveMaze()
{
	std::pair<size_t, size_t> position = { 0,0 };
	while (savedPosition.size() != 0)
	{
		position = backtrack(position);
	}
	markAsUnvisited();
	markOuterNodes();
	markStart();
	savedPosition.push(position);
	char draw = ' ';
	std::pair<size_t, size_t> end = std::make_pair(height - 1, width - 1);
	while (position != end)
	{
		draw = walkedPath.front();
		if (canMove(draw, position))
		{
			position = move(draw, position);
			walkedPath.pop_front();
		}
		else
		{
			if (isStuck(position))
			{
				if (savedPosition.size() != 0)
				{
					if (walkedPath.size() != 0)
					{
						walkedPath.pop_back();
					}
					position = backtrack(position);
				}
			}
		}
	}
}
*/

// Revert steps taken
std::pair<size_t, size_t> labyrinth::backtrack(std::pair<size_t, size_t> position)
{
	std::pair<size_t, size_t> temp;
	if (savedPosition.size() != 0)
	{
		temp = position;
		savedPosition.pop();
		if (savedPosition.size() != 0)
		{
			position = savedPosition.top();
		}
	}
	return position;
}

// Remove markers
void labyrinth::markAsUnvisited()
{
	for (size_t col = 0; col < this->height; col++)
	{
		for (size_t row = 0; row < this->width; row++)
		{
			myMaze[col][row].isVisited = false;
			myMaze[col][row].walkNorth = true;
			myMaze[col][row].walkSouth = true;
			myMaze[col][row].walkWest = true;
			myMaze[col][row].walkEast = true;
		}
	}
}

void labyrinth::markStart()
{
	myMaze[0][0].isVisited = true;
}

void labyrinth::markEnd()
{
	myMaze[height - 1][width - 1].isVisited = false;
}

// Walkcheck
bool labyrinth::canMove(char direction, std::pair<size_t, size_t> position)
{
	if (direction == 'S')
	{
		return canMoveSouth(position);
	}
	else if (direction == 'W')
	{
		return canMoveWest(position);
	}
	else if (direction == 'E')
	{
		return canMoveEast(position);
	}
	else if (direction == 'N')
	{
		return canMoveNorth(position);
	}
	return false;
}

// Stuckcheck
bool labyrinth::isStuck(std::pair<size_t, size_t> position)
{
	return !(canMoveNorth(position) || canMoveSouth(position) || canMoveEast(position) || canMoveWest(position));
}

bool labyrinth::canMoveSouth(std::pair<size_t, size_t> position)
{
	if (myMaze[position.first][position.second].isOuterWall)
	{
		if (myMaze[position.first][position.second].walkSouth)
		{
			if (myMaze[position.first + 1][position.second].isVisited)
			{
				return false;
			}
			return true;
		}
		return false;
	}
	return myMaze[position.first][position.second].walkSouth && !myMaze[position.first + 1][position.second].isVisited;
}

bool labyrinth::canMoveNorth(std::pair<size_t, size_t> position)
{
	if (myMaze[position.first][position.second].isOuterWall)
	{
		if (myMaze[position.first][position.second].walkNorth)
		{
			if (myMaze[position.first - 1][position.second].isVisited)
			{
				return false;
			}
			return true;
		}
		return false;
	}
	return myMaze[position.first][position.second].walkNorth && !myMaze[position.first - 1][position.second].isVisited;
}

bool labyrinth::canMoveEast(std::pair<size_t, size_t> position)
{
	if (myMaze[position.first][position.second].isOuterWall)
	{
		if (myMaze[position.first][position.second].walkEast)
		{
			if (myMaze[position.first][position.second + 1].isVisited)
			{
				return false;
			}
			return true;
		}
		return false;
	}
	return myMaze[position.first][position.second].walkEast && !myMaze[position.first][position.second + 1].isVisited;
}

bool labyrinth::canMoveWest(std::pair<size_t, size_t> position)
{
	if (myMaze[position.first][position.second].isOuterWall)
	{
		if (myMaze[position.first][position.second].walkWest)
		{
			if (myMaze[position.first][position.second - 1].isVisited)
			{
				return false;
			}
			return true;
		}
		return false;
	}
	return myMaze[position.first][position.second].walkWest && !myMaze[position.first][position.second - 1].isVisited;
}

// Move around 
std::pair<size_t, size_t> labyrinth::move(char direction, std::pair<size_t, size_t> position)
{
	if (direction == 'S')
	{
		walkedPath.push_back(direction);
		position = moveSouth(position);
	}
	else if (direction == 'W')
	{
		walkedPath.push_back(direction);
		position = moveWest(position);
	}
	else if (direction == 'E')
	{
		walkedPath.push_back(direction);
		position = moveEast(position);
	}
	else if (direction == 'N')
	{
		walkedPath.push_back(direction);
		position = moveNorth(position);
	}
	return position;
}

std::pair<size_t, size_t> labyrinth::moveSouth(std::pair<size_t, size_t> position)
{
	myMaze[position.first][position.second].walkSouth = false;
	myMaze[position.first + 1][position.second].isVisited = true;
	myMaze[position.first + 1][position.second].walkNorth = false;
	position.first += 1;
	savedPosition.push(position);
	return position;
}

std::pair<size_t, size_t> labyrinth::moveNorth(std::pair<size_t, size_t> position)
{
	myMaze[position.first][position.second].walkNorth = false;
	myMaze[position.first - 1][position.second].isVisited = true;
	myMaze[position.first - 1][position.second].walkSouth = false;
	position.first -= 1;
	savedPosition.push(position);
	return position;
}

std::pair<size_t, size_t> labyrinth::moveEast(std::pair<size_t, size_t> position)
{
	myMaze[position.first][position.second].walkEast = false;
	myMaze[position.first][position.second + 1].isVisited = true;
	myMaze[position.first][position.second + 1].walkWest = false;
	position.second += 1;
	savedPosition.push(position);
	return position;
}

std::pair<size_t, size_t> labyrinth::moveWest(std::pair<size_t, size_t> position)
{
	myMaze[position.first][position.second].walkWest = false;
	myMaze[position.first][position.second - 1].isVisited = true;
	myMaze[position.first][position.second - 1].walkEast = false;
	position.second -= 1;
	savedPosition.push(position);
	return position;
}

// Randomizer
char labyrinth::randomizeDirection()
{
	char directions[] = "SWEN";
	unsigned int temp = rand() % 4;

	return directions[temp];
}

// Disgusting mazeprinter
void labyrinth::print()
{
	// Upper wall
	for (int i = 0; i < (width * 2) + 1; i++)
	{
		if (i == 1)
		{
			std::cout << "S";
			continue;
		}
		std::cout << "#";
	}
	std::cout << std::endl;
	for (int col = 0; col < this->height; col++)
	{
		std::cout << "#";
		for (int row = 0; row < this->width;)
		{
			if (row == this->width - 1) {
				std::cout << " " << "#";
				row++;
			}
			else if (myMaze[col][row].walkEast) {

				std::cout << " " << "#";
				row++;
			}
			else {
				std::cout << " " << " ";
				row++;
			}
		}
		std::cout << "\n";
		if (col != height - 1)
		{
			for (int row = 0; row < this->width; row++)
			{
				if (row == 0)
				{
					std::cout << "#";
				}
				if (myMaze[col][row].walkSouth) {

					std::cout << "#" << "#";
				}
				else {
					std::cout << " " << "#";
				}
			}
			std::cout << "\n";
		}
	}

	//Lower wall
	for (int i = 0; i < (width * 2) + 1; i++)
	{
		if (i == (width * 2) - 1)
		{
			std::cout << "E";
			continue;
		}
		std::cout << "#";
	}
	std::cout << std::endl;
}

// Marks out of bound potential nodes
void labyrinth::markOuterNodes()
{
	for (size_t col = 0; col < this->height; col++)
	{
		for (size_t row = 0; row < this->width; row++)
		{
			bool westCondition = myMaze[col][row].x == 0;
			bool southCondition = myMaze[col][row].y == this->height - 1;
			bool eastCondition = myMaze[col][row].x == this->width - 1;
			bool northCondition = myMaze[col][row].y == 0;

			if (northCondition)
			{
				myMaze[col][row].markAsOuterNodesNorth();
			}
			if (southCondition)
			{
				myMaze[col][row].markAsOuterNodesSouth();
			}
			if (eastCondition)
			{
				myMaze[col][row].markAsOuterNodesEast();
			}
			if (westCondition)
			{
				myMaze[col][row].markAsOuterNodesWest();
			}
		}
	}
}

// 2d container
void labyrinth::createBoard()
{

	while (myMaze.size() != 0)
	{
		myMaze.pop_back();
	}
	for (size_t col = 0; col < this->height; col++)
	{
		std::vector<node> inner;

		for (size_t row = 0; row < this->width; row++)
		{
			node temp(row, col);
			inner.push_back(temp);
		}
		myMaze.push_back(inner);
	}
}