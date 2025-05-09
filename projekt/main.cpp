#include "labyrinth.h"

int main()
{
	srand(time(0));

	try
	{
		labyrinth mylab2(21, 21);
		mylab2.createMaze();
		mylab2.print();
		std::cout << std::endl;
		mylab2.solveMaze();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}