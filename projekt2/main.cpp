/*
// Project Maze
// Name: Gunnar Landström
// Date: 2025-05-18
// Grade: E
*/

#include "maze.h"


int main()
{
	srand(time(0));

	startMenu();

	return 0;
}

// Crappy UI 2.0
void startMenu()
{
	labyrinth maze;
	bool wantsToPlay = true;
	std::string userChoice;
	std::cout << "This is a program that can create mazes at the size of your choosing! \n"
		<< std::endl;
	std::cout << "\n";
	bool isSolved = false;


	while (wantsToPlay)
	{
		std::cout << "[1] - Generate a maze. \n";
		//std::cout << "[2] - Show solution. \n";
		std::cout << "[2] - Exit program.\n";
		std::cout << "Input:> ";
		try
		{
			std::getline(std::cin, userChoice);
			int choice = std::stoi(userChoice);
			switch (choice)
			{
			case 1:
			{
				maze = wantsToGenerateMaze();
				isSolved = false;
				maze.print();
				std::cout << "\n";
				continue;
			}
			/*
			case 2:
			{
				std::cout << "\n";
				if (!isSolved) {
					maze.markAsUnvisited();
					maze.solveMaze();
					isSolved = true;
				}
				maze.print();
				std::cout << "\n";
				continue;
			}
			*/

			case 2:
			{
				exitProgram();
			}

			default:
			{

				std::cout << "\n";
				std::cout << "Wrong input, try again!\n\n";
				break;
			}
			}
		}
		catch (const std::exception&)
		{
			std::cout << "Wrong input, try again!\n\n";
		}
	}
}

// Userdefined size
labyrinth wantsToGenerateMaze()
{

	std::string desiredWidth;
	std::string desiredHeight;
	size_t userWidth;
	size_t userHeight;

	while (true)
	{
		try
		{
			std::cout << "Enter the dimensions of the maze!" << std::endl;

			std::cout << "Width (3-150): ";
			std::getline(std::cin, desiredWidth);

			std::cout << "Height (3-50): ";
			std::getline(std::cin, desiredHeight);

			std::cout << "\n";
			userWidth = std::stoi(desiredWidth);
			userHeight = std::stoi(desiredHeight);

			if (userWidth < 3 || userHeight < 3)
			{
				std::cout << "That's a little small wouldnt you say? Make it a little bigger! width: 3-150 and height: 3-50 \n\n";
				continue;
			}
			if (userWidth > 150 || userHeight > 50)
			{
				std::cout << "Woah!, relax my friend, nobody wants them that big! Try width: 3-150 and height: 3-50\n\n";
				continue;
			}
			labyrinth newMaze = labyrinth(userWidth, userHeight);
			return newMaze;
		}
		catch (const std::exception&)
		{
			std::cout << "Wrong input, please try again! " << std::endl;
			continue;
		}
	}
}