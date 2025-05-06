#include "labyrinth.h"

int main()
{
    srand(time(0));

    try
    {
        labyrinth mylab2(9, 9);
        mylab2.print();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}