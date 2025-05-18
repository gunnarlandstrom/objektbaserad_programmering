#include "maze.h"
#include "node.h"

labyrinth::labyrinth()
{
	this->height = 7;
	this->width = 7;
}

labyrinth::~labyrinth()
{
}

void labyrinth::initialize()
{
	createBoard();
	markStart();
	markEnd();
	markOuterNodes();
	createMaze();
	markAsUnvisited();
}

// Startmenu
void labyrinth::startMenu()
{
	bool wantsToPlay = true;
	std::string userChoice;
	std::cout << "This is a program that can create and solve labyrinths at the size of your choosing! \n"
			  << std::endl;
	while (wantsToPlay)
	{
		std::cout << "[1] - Generate a maze. \n";
		std::cout << "[2] - Show solution. \n";
		std::cout << "[3] - Exit program.\n";
		std::cout << "Input:> ";
		try
		{
			std::getline(std::cin, userChoice);
			int choice = std::stoi(userChoice);
			switch (choice)
			{
			case 1:
				wantsToGenerateMaze();
				print();
				solveMaze();

				continue;
			case 2:

				print();
				continue;

			case 3:
				exitProgram();

			default:
				std::cout << "\n";
				std::cout << "Wrong input, try again!" << std::endl;
				break;
			}
		}
		catch (const std::exception &)
		{
			std::cout << "Wrong input, try again! " << std::endl;
		}
	}
}

void labyrinth::wantsToGenerateMaze()
{

	std::string desiredWidth;
	std::string desiredHeight;
	size_t userWidth;
	size_t userHeight;

	bool unvalidInput = true;

	while (unvalidInput)
	{
		try
		{
			std::cout << "Enter the dimensions of the maze!" << std::endl;

			std::cout << "Width (3-150): ";
			std::getline(std::cin, desiredWidth);

			std::cout << "Height (3-50): ";
			std::getline(std::cin, desiredHeight);

			userWidth = std::stoi(desiredWidth);
			userHeight = std::stoi(desiredHeight);

			if (userWidth < 3 || userHeight < 3)
			{
				std::cout << "That's a little small wouldnt you say? Make it a little bigger!\n\n";
				continue;
			}
			if (userWidth > 150 || userHeight > 50)
			{
				std::cout << "Woah!, relax my friend, nobody wants them that big! Try width: 3-150 and height: 3-50\n\n";
				continue;
			}
		}
		catch (const std::exception &)
		{
			std::cout << "Wrong input, please try again! " << std::endl;
			continue;
		}
		unvalidInput = false;
	}
	this->width = userWidth;
	this->height = userHeight;
	initialize();
}

void labyrinth::createMaze()
{
	while (walkedPath.size() != 0)
	{
		walkedPath.pop_back();
	}
	while (savedPosition.size() > 1)
	{
		savedPosition.pop();
	}
	while (savedPosition.size() != 0)
	{
		char direction = randomizeDirection();
		bool moveable = canMove(direction);
		if (moveable)
		{
			move(direction);
		}

		else
		{
			if (isStuck())
			{
				if (savedPosition.size() != 0)
				{
					backtrack();
				}
			}
		}
	}
}

void labyrinth::exitProgram()
{
	std::cout << "Exiting program, until next time!" << std::endl;
	exit(0);
}

void labyrinth::solveMaze()
{
	while (savedPosition.size() != 0)
	{
		backtrack();
	}
	markAsUnvisited();
	markOuterNodes();
	markStart();
	char draw = ' ';
	while (pos != end)
	{

		draw = walkedPath.front();

		if (canMove(draw))
		{

			move(draw);
			walkedPath.pop_front();
		}
		else
		{
			if (isStuck())
			{

				if (savedPosition.size() != 0)
				{
					if (walkedPath.size() != 0)
					{
						walkedPath.pop_back();
					}
					backtrack();
				}
			}
		}
	}
	drawPath('S');
}

void labyrinth::backtrack()
{
	if (savedPosition.size() != 0)
	{
		temp = pos;
		savedPosition.pop();
		if (savedPosition.size() != 0)
		{
			pos = savedPosition.top();
		}
	}
	myMaze[pos.first][pos.second].flag = " ";
	myMaze[temp.first][temp.second].flag = " ";
}

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
			if (myMaze[col][row].flag == "v" || myMaze[col][row].flag == "^" || myMaze[col][row].flag == "<" || myMaze[col][row].flag == ">")
			{
				myMaze[col][row].flag = " ";
			}
		}
	}
}

void labyrinth::drawPath(char direction)
{
	if (direction == 'S')
	{
		myMaze[pos.first][pos.second].flag = "v";
	}
	else if (direction == 'W')
	{
		myMaze[pos.first][pos.second].flag = "<";
	}
	else if (direction == 'E')
	{
		myMaze[pos.first][pos.second].flag = ">";
	}
	else if (direction == 'N')
	{
		myMaze[pos.first][pos.second].flag = "^";
	}
}

void labyrinth::markStart()
{
	myMaze[0][0].northFlag = "S";
	myMaze[0][0].isVisited = true;
	pos = std::make_pair(0, 0);
	savedPosition.push(pos);
}

void labyrinth::markEnd()
{
	myMaze[height - 1][width - 1].southFlag = "E";
	myMaze[height - 1][width - 1].isVisited = false;
	end = std::make_pair(height - 1, width - 1);
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
	return false;
}

bool labyrinth::isStuck()
{
	return !(canMoveNorth() || canMoveSouth() || canMoveEast() || canMoveWest());
}

bool labyrinth::canMoveSouth()
{
	if (myMaze[pos.first][pos.second].isOuterWall)
	{
		if (myMaze[pos.first][pos.second].walkSouth)
		{
			if (myMaze[pos.first + 1][pos.second].isVisited)
			{
				return false;
			}
			return true;
		}
		return false;
	}
	return myMaze[pos.first][pos.second].walkSouth && !myMaze[pos.first + 1][pos.second].isVisited;
}

bool labyrinth::canMoveNorth()
{
	if (myMaze[pos.first][pos.second].isOuterWall)
	{
		if (myMaze[pos.first][pos.second].walkNorth)
		{
			if (myMaze[pos.first - 1][pos.second].isVisited)
			{
				return false;
			}
			return true;
		}
		return false;
	}
	return myMaze[pos.first][pos.second].walkNorth && !myMaze[pos.first - 1][pos.second].isVisited;
}

bool labyrinth::canMoveEast()
{
	if (myMaze[pos.first][pos.second].isOuterWall)
	{
		if (myMaze[pos.first][pos.second].walkEast)
		{
			if (myMaze[pos.first][pos.second + 1].isVisited)
			{
				return false;
			}
			return true;
		}
		return false;
	}
	return myMaze[pos.first][pos.second].walkEast && !myMaze[pos.first][pos.second + 1].isVisited;
}

bool labyrinth::canMoveWest()
{
	if (myMaze[pos.first][pos.second].isOuterWall)
	{
		if (myMaze[pos.first][pos.second].walkWest)
		{
			if (myMaze[pos.first][pos.second - 1].isVisited)
			{
				return false;
			}
			return true;
		}
		return false;
	}
	return myMaze[pos.first][pos.second].walkWest && !myMaze[pos.first][pos.second - 1].isVisited;
}

void labyrinth::move(char direction)
{
	if (direction == 'S')
	{
		walkedPath.push_back(direction);
		moveSouth();
	}
	else if (direction == 'W')
	{
		walkedPath.push_back(direction);
		moveWest();
	}
	else if (direction == 'E')
	{
		walkedPath.push_back(direction);
		moveEast();
	}
	else if (direction == 'N')
	{
		walkedPath.push_back(direction);
		moveNorth();
	}
}

void labyrinth::moveSouth()
{
	myMaze[pos.first][pos.second].walkSouth = false;
	myMaze[pos.first][pos.second].southFlag = " ";
	myMaze[pos.first][pos.second].flag = "v";
	myMaze[pos.first + 1][pos.second].isVisited = true;
	myMaze[pos.first + 1][pos.second].walkNorth = false;
	myMaze[pos.first + 1][pos.second].northFlag = " ";
	pos.first += 1;
	savedPosition.push(pos);
}

void labyrinth::moveNorth()
{
	myMaze[pos.first][pos.second].walkNorth = false;
	myMaze[pos.first][pos.second].flag = "^";
	myMaze[pos.first][pos.second].northFlag = " ";
	myMaze[pos.first - 1][pos.second].isVisited = true;
	myMaze[pos.first - 1][pos.second].walkSouth = false;
	myMaze[pos.first - 1][pos.second].southFlag = " ";
	pos.first -= 1;
	savedPosition.push(pos);
}

void labyrinth::moveEast()
{
	myMaze[pos.first][pos.second].walkEast = false;
	myMaze[pos.first][pos.second].eastFlag = " ";
	myMaze[pos.first][pos.second].flag = ">";
	myMaze[pos.first][pos.second + 1].isVisited = true;
	myMaze[pos.first][pos.second + 1].walkWest = false;
	myMaze[pos.first][pos.second + 1].westFlag = " ";
	pos.second += 1;
	savedPosition.push(pos);
}

void labyrinth::moveWest()
{
	myMaze[pos.first][pos.second].walkWest = false;
	myMaze[pos.first][pos.second].westFlag = " ";
	myMaze[pos.first][pos.second].flag = "<";
	myMaze[pos.first][pos.second - 1].isVisited = true;
	myMaze[pos.first][pos.second - 1].walkEast = false;
	myMaze[pos.first][pos.second - 1].eastFlag = " ";
	pos.second -= 1;
	savedPosition.push(pos);
}

char labyrinth::randomizeDirection()
{
	char directions[] = "SWEN";
	unsigned int temp = rand() % 4;

	return directions[temp];
}

void labyrinth::print()
{
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
			if (col == width - 1)
			{
				std::cout << myMaze[col][row].flag << myMaze[col][row].eastFlag;
				row++;
				continue;
			}
			else
			{
				std::cout << myMaze[col][row].flag << myMaze[col][row].eastFlag;

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
				if (row == this->width - 1)
				{
				}
				std::cout << myMaze[col][row].southFlag << "#";
			}
			std::cout << "\n";
		}
	}
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