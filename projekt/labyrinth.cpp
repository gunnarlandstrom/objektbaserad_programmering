#include "labyrinth.h"
#include "tile.h"

labyrinth::labyrinth()
{
	startMenu();
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
	createMaze();
}

labyrinth::~labyrinth()
{
}

void labyrinth::wantsToGenerateMaze() {

	while (myMaze.size() != 0) {
		myMaze.pop_back();
	}
	std::string desiredWidth;
	std::string desiredHeight;

	size_t userWidth;
	size_t userHeight;
	std::cout << "Enter the dimensions of the maze! (Odd numbers only)" << std::endl;

	std::cout << "Height: ";
	std::getline(std::cin, desiredWidth);

	std::cout << "Width: ";
	std::getline(std::cin, desiredHeight);

	userWidth = std::stoi(desiredWidth);
	userHeight = std::stoi(desiredHeight);
	userWidth = (userWidth * 2) + 1;
	userHeight = (userHeight * 2) + 1;
	this->width = userWidth;
	this->height = userHeight;
	initialize();
}

// Startmenu
void labyrinth::startMenu()
{
	bool wantsToPlay = true;
	std::string userChoice;
	std::cout << "This is a program that can create and solve labyrinths at the size of your choosing! \n" << std::endl;

	while (wantsToPlay) {
		std::cout << "Do you want to try?" << std::endl;
		std::cout << "[1] - Yes" << std::endl;
		std::cout << "[2] - No \n" << std::endl;
		std::cout << "Input:> ";

		std::getline(std::cin, userChoice);

		if (userChoice == "1")
		{
			wantsToPlay = true;
			break;
		}
		else if (userChoice == "2") {
			wantsToPlay = false;
			std::cout << "\n";
			std::cout << "Exiting program." << std::endl;
			exit(2);
		}
		else
		{
			std::cout << "Error: wrong input, try again." << std::endl << std::endl;
		}
	}

	while (wantsToPlay)
	{
		std::cout << "Choose an option! \n \n";
		std::cout << "[1] - Generate a maze. \n";
		std::cout << "[2] - Print the maze. \n";
		std::cout << "[3] - Solve the maze. \n";
		std::cout << "[4] - Exit program." << std::endl;
		std::cout << "Input:> ";
		std::getline(std::cin, userChoice);
		int choice = std::stoi(userChoice);
		switch (choice)
		{
		case 1:
			wantsToGenerateMaze();
			continue;
		case 2:
			print();
			continue;
		case 3:
			solveMaze();
			continue;
		case 4:
			exitProgram();

		default:
			std::cout << "\n";
			std::cout << "Wrong input, try again!" << std::endl;
			break;
		}

	}
}

void labyrinth::exitProgram() {
	std::cout << "Exiting program, untill next time!" << std::endl;
	exit(4);
}

void labyrinth::solveMaze() {
	if (savedPosition.size() == 0) {
		savedPosition.push(pos);
	}
	markAsUnvisited();
	myMaze[pos.first][pos.second].isVisited = true;
	while (pos != end) {
		char direction = randomizeDirection();
		bool wall = isWallOrVisited(direction);
		if (!wall) {
			move(direction);
			drawPath(direction);
		}
		else
		{
			if (isStuck()) {
				backtrack();
			}
		}
	}
	std::cout << std::endl;
	print();
	while (savedPosition.size() > 1) {
		backtrack();
	}
}

void labyrinth::backtrack() {
	temp = savedPosition.top();
	savedPosition.pop();
	pos = savedPosition.top();
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
			if (myMaze[col][row].flag == "v" || myMaze[col][row].flag == "^" || myMaze[col][row].flag == "<" || myMaze[col][row].flag == ">") {
				myMaze[col][row].flag = " ";
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
	while (savedPosition.size() != 0) {
		savedPosition.pop();
	}
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