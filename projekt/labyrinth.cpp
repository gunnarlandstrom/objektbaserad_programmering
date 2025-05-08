#include "labyrinth.h"
#include "tile.h"

labyrinth::labyrinth()
{
	width = 7;
	height = 7;
	initialize();
}

labyrinth::labyrinth(size_t width, size_t height)
{
	this->width = width;
	this->height = height;
	initialize();
}

void labyrinth::initialize()
{
	createBoard();
	markOuterWalls();
	markNodes();
	markStart();
	markEnd();
}

labyrinth::~labyrinth()
{
}

void labyrinth::createMaze() {
	while (savedPosition.size() != 0) {
		char direction = randomizeDirection();
		bool canFlytt = canMove(direction);
		if (canFlytt) {
			move(direction);
		}
		else {
			if (isStuck()) {
				savedPosition.pop();
				if (savedPosition.size() != 0) {
					pos = savedPosition.top();
				}
			}
		}
	}
}

void labyrinth::markStart()
{
	myMaze[0][1].flag = "S";
	myMaze[0][0].isVisited = true;
	pos = std::make_pair(1, 1);
	myMaze[pos.first][pos.second].flag = " ";
	myMaze[pos.first][pos.second].isVisited = true;
	savedPosition.push(pos);
}

void labyrinth::markEnd()
{
	myMaze[height - 1][width - 2].flag = "E";
	myMaze[height - 1][width - 2].isVisited = true;
}

bool labyrinth::canMove(char direction)
{
	if (direction == 'S')
	{
		return canMoveSouth();
	}
	else if (direction == 'W')
	{
		return canMoveWest();
	}
	else if (direction == 'E')
	{
		return canMoveEast();
	}
	else if (direction == 'N')
	{
		return canMoveNorth();
	}
	throw std::invalid_argument("Invalid direction");
}

bool labyrinth::isStuck() {
	return !(canMoveNorth() || canMoveSouth() || canMoveEast() || canMoveWest());
}

bool labyrinth::canMoveSouth()
{
	if (myMaze[pos.first + 1][pos.second].isOuterWall) {
		return false;
	}
	if (myMaze[pos.first + 2][pos.second].isVisited) {
		return false;
	}
	return true;
}

bool labyrinth::canMoveNorth()
{
	if (myMaze[pos.first - 1][pos.second].isOuterWall) {
		return false;
	}
	if (myMaze[pos.first - 2][pos.second].isVisited) {
		return false;
	}
	return true;
}

bool labyrinth::canMoveEast()
{
	if (myMaze[pos.first][pos.second + 1].isOuterWall) {
		return false;
	}
	if (myMaze[pos.first][pos.second + 2].isVisited) {
		return false;
	}
	return true;
}

bool labyrinth::canMoveWest()
{
	if (myMaze[pos.first][pos.second - 1].isOuterWall) {
		return false;
	}
	if (myMaze[pos.first][pos.second - 2].isVisited) {
		return false;
	}
	return true;
}


void labyrinth::move(char direction)
{
	if (direction == 'S')
	{
		return moveSouth();
	}
	else if (direction == 'W')
	{
		return moveWest();
	}
	else if (direction == 'E')
	{
		return moveEast();
	}
	else if (direction == 'N')
	{
		return moveNorth();
	}
	throw std::invalid_argument("Invalid direction");
}

void labyrinth::moveSouth()
{
	myMaze[pos.first + 1][pos.second].flag = " ";
	myMaze[pos.first + 2][pos.second].flag = " ";
	myMaze[pos.first + 1][pos.second].isVisited = true;
	myMaze[pos.first + 2][pos.second].isVisited = true;
	pos.first += 2;
	savedPosition.push(pos);
}

void labyrinth::moveNorth()
{
	myMaze[pos.first - 1][pos.second].flag = " ";
	myMaze[pos.first - 2][pos.second].flag = " ";
	myMaze[pos.first - 1][pos.second].isVisited = true;
	myMaze[pos.first - 2][pos.second].isVisited = true;
	pos.first -= 2;
	savedPosition.push(pos);
}

void labyrinth::moveEast()
{
	myMaze[pos.first][pos.second + 1].flag = " ";
	myMaze[pos.first][pos.second + 2].flag = " ";
	myMaze[pos.first][pos.second + 1].isVisited = true;
	myMaze[pos.first][pos.second + 2].isVisited = true;
	pos.second += 2;
	savedPosition.push(pos);
}

void labyrinth::moveWest()
{
	myMaze[pos.first][pos.second - 1].flag = " ";
	myMaze[pos.first][pos.second - 2].flag = " ";
	myMaze[pos.first][pos.second - 1].isVisited = true;
	myMaze[pos.first][pos.second - 2].isVisited = true;
	pos.second -= 2;
	savedPosition.push(pos);
}

char labyrinth::randomizeDirection()
{
	char directions[] = "SWEN";
	int temp = rand() % 4;

	return directions[temp];
}

void labyrinth::print()
{
	for (int col = 0; col < this->myMaze.size(); col++)
	{
		for (int row = 0; row < this->myMaze[col].size(); row++)
		{
			if (col == pos.first && row == pos.second) {
				std::cout << "*" << " ";
			}
			else {
				std::cout << myMaze[col][row].flag << " ";
			}
		}
		std::cout << std::endl;
	}
}

void labyrinth::markOuterWalls()
{
	for (size_t col = 0; col < this->height; col++)
	{
		for (size_t row = 0; row < this->width; row++)
		{
			bool xCondition = myMaze[col][row].x == 0 || myMaze[col][row].x == this->width - 1;
			bool yCondition = myMaze[col][row].y == 0 || myMaze[col][row].y == this->height - 1;

			if (xCondition || yCondition)
			{
				myMaze[col][row].markAsOuterWall();
			}
		}
	}
}

void labyrinth::markNodes()
{
	for (size_t col = 0; col < this->height; col++)
	{
		for (size_t row = 0; row < this->width; row++)
		{
			bool xCondition = myMaze[col][row].x % 2 == 1;
			bool yCondition = myMaze[col][row].y % 2 == 1;

			if (xCondition && yCondition)
			{
				myMaze[col][row].markAsNode();
			}
		}
	}
}

void labyrinth::createBoard()
{
	for (size_t col = 0; col < this->height; col++)
	{
		std::vector<tile> inner;

		for (size_t row = 0; row < this->width; row++)
		{
			tile temp(row, col);
			inner.push_back(temp);
		}
		myMaze.push_back(inner);
	}
}