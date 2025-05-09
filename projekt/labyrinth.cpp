#include "labyrinth.h"
#include "tile.h"

labyrinth::labyrinth()
{
	width = 7;
	height = 7;
	initialize();
}

labyrinth::labyrinth(size_t height, size_t width)
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

void labyrinth::solveMaze() {
	savedPosition.push(pos);
	markAsUnvisited();
	myMaze[pos.first][pos.second].isVisited = true;
	char tempDirection = '?';
	while (pos != end) {
		char direction = randomizeDirection();
		bool wall = isWallOrVisited(direction);
		if (!wall) {
			move(direction);
			drawPath(direction);
			print();
			std::cout << std::endl << std::endl;
		}
		else
		{
			if (isStuck()) {
				temp = savedPosition.top();
				savedPosition.pop();
				pos = savedPosition.top();
				backtrack();
			}
		}

		tempDirection = direction;
	}
	myMaze[pos.first][pos.second].flag = tempDirection;
	print();
}

void labyrinth::backtrack() {
	if (temp.first > pos.first) {
		myMaze[pos.first + 1][pos.second].flag = " ";
		myMaze[pos.first][pos.second].flag = " ";
	}
	else if (temp.first < pos.first) {
		myMaze[pos.first - 1][pos.second].flag = " ";
		myMaze[pos.first][pos.second].flag = " ";
	}
	else if (temp.second > pos.second) {
		myMaze[pos.first][pos.second + 1].flag = " ";
		myMaze[pos.first][pos.second].flag = " ";
	}
	else if (temp.second < pos.second) {
		myMaze[pos.first][pos.second - 1].flag = " ";
		myMaze[pos.first][pos.second].flag = " ";
	}

}

bool labyrinth::isWallOrVisited(char direction) {

	if (direction == 'S')
	{
		return isWallSouth();
	}
	else if (direction == 'W')
	{
		return isWallWest();
	}
	else if (direction == 'E')
	{
		return isWallEast();
	}
	else if (direction == 'N')
	{
		return isWallNorth();
	}
	throw std::invalid_argument("Invalid direction");
}

bool labyrinth::isWallSouth() {
	if (myMaze[pos.first + 1][pos.second].flag == "S") {
		return true;
	}
	return (myMaze[pos.first + 1][pos.second].flag == "#") || (myMaze[pos.first + 2][pos.second].isVisited);
}

bool labyrinth::isWallNorth() {
	if ((myMaze[pos.first - 1][pos.second].flag == "S")) {
		return true;
	}
	return (myMaze[pos.first - 1][pos.second].flag == "#") || (myMaze[pos.first - 2][pos.second].isVisited);
}

bool labyrinth::isWallEast() {
	if ((myMaze[pos.first][pos.second + 1].flag == "S")) {
		return true;
	}
	return (myMaze[pos.first][pos.second + 1].flag == "#") || (myMaze[pos.first][pos.second + 2].isVisited);
}

bool labyrinth::isWallWest() {
	if ((myMaze[pos.first][pos.second - 1].flag == "S")) {
		return true;
	}
	return (myMaze[pos.first][pos.second - 1].flag == "#") || (myMaze[pos.first][pos.second - 2].isVisited);
}

void labyrinth::markAsUnvisited() {
	for (size_t col = 0; col < this->height; col++)
	{

		for (size_t row = 0; row < this->width; row++)
		{
			if (myMaze[col][row].isNode) {
				myMaze[col][row].isVisited = false;
			}
		}
	}
}

void labyrinth::drawPath(char direction) {
	if (direction == 'S')
	{
		myMaze[pos.first - 1][pos.second].flag = "v";
		myMaze[pos.first - 2][pos.second].flag = "v";
	}
	else if (direction == 'W')
	{
		myMaze[pos.first][pos.second + 1].flag = "<";
		myMaze[pos.first][pos.second + 2].flag = "<";
	}
	else if (direction == 'E')
	{
		myMaze[pos.first][pos.second - 1].flag = ">";
		myMaze[pos.first][pos.second - 2].flag = ">";
	}
	else if (direction == 'N')
	{
		myMaze[pos.first + 1][pos.second].flag = "^";
		myMaze[pos.first + 2][pos.second].flag = "^";
	}

}

void labyrinth::createMaze() {
	while (savedPosition.size() != 0) {
		char direction = randomizeDirection();
		bool moveable = canMove(direction);
		if (moveable) {
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
	end = std::make_pair(height - 2, width - 2);
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
				std::cout << "o" << " ";
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