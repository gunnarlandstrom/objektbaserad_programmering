#include "labyrinth.h"

int main()
{
	srand(time(0));

	try
	{
		labyrinth mylab;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}