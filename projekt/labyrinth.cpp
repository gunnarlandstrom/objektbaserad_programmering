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
    for (size_t col = 0; col < this->width; col++)
    {
        std::vector<tile> heightTiles;

        for (size_t row = 0; row < this->height; row++)
        {
            heightTiles.push_back(tile());
        }
        myMaze.push_back(heightTiles);
    }
    markStart();
    markEnd();
}

labyrinth::~labyrinth()
{
}

void labyrinth::markStart()
{
    myMaze[0][1].flag = "S";
    myMaze[0][1].isWall = false;
}

void labyrinth::markEnd()
{
    myMaze[height-1][width-2].flag = "E";
    myMaze[height-1][width-2].isWall = false;
}

bool labyrinth::canMove(int row, int col)
{
    return 0;
}

char labyrinth::randomizeDirection()
{
    char directions[] = "SWEN";
    int temp = rand() % 4;

    return directions[temp];
}

void labyrinth::print()
{

    for (size_t col = 0; col < this->width; col++)
    {

        for (size_t row = 0; row < this->height; row++)
        {
            std::cout << myMaze[col][row].flag << " ";
        }
        std::cout << std::endl;
    }
}
