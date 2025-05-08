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
    for (size_t row = 0; row < this->width; row++)
    {
        std::vector<tile> heightTiles;

        for (size_t col = 0; col < this->height; col++)
        {
            tile temptile(row, col);
            if (row == 0)
            {
                temptile.canVisitNorth = false;
            }
            else if (row == height - 1)
            {
                temptile.canVisitSouth = false;
            }
            if (col == 0)
            {
                temptile.canVisitWest = false;
            }
            else if (col == width - 1)
            {
                temptile.canVisitEast = false;
            }
            std::cout << "This is row: " << row << " This is col: " << col << std::endl;
            std::cout << "Visit north: " << temptile.canVisitNorth << " Visit west: " << temptile.canVisitWest << std::endl;
            std::cout << "Visit East: " << temptile.canVisitEast << " Visit south: " << temptile.canVisitSouth << std::endl
                      << std::endl;
            heightTiles.push_back(temptile);
        }
        myMaze.push_back(heightTiles);
    }
    // markStart();
    // markEnd();

    char direction = randomizeDirection();
}

labyrinth::~labyrinth()
{
}

void labyrinth::markStart()
{
    // myMaze[0][0].flag = "S";
    myMaze[0][0].isVisited = true;
    pos.first = 0;
    pos.second = 0;
}

void labyrinth::markEnd()
{
    /*
    myMaze[height - 1][width - 2].flag = "E";
    myMaze[height - 1][width - 2].isVisited = true;
    end.first = height - 2;
    end.second = width - 2;
    */
}
bool labyrinth::isEdge()
{
    return 0;
}

int labyrinth::canMove(char direction)
{
    if (direction == 'S')
    {
        if (myMaze[pos.first + 1][pos.second].isVisited)
        {
            return false;
        }
    }
    else if (direction == 'W')
    {
        if (myMaze[pos.first][pos.second - 1].isVisited)
        {
            return false;
        }
    }
    else if (direction == 'E')
    {

        if (myMaze[pos.first][pos.second + 1].isVisited)
        {
            return false;
        }
    }
    else if (direction == 'N')
    {
        if (myMaze[pos.first - 1][pos.second].isVisited)
        {
            return false;
        }
    }
    return true;
}

void labyrinth::move(char direction)
{
}

char labyrinth::randomizeDirection()
{
    char directions[] = "SWEN";
    int temp = rand() % 4;

    return directions[temp];
}

void labyrinth::print()
{
    int realWidth = (width * 2) + 1;
    int realHeight = (height * 2) + 1;
    int counterwidth = 0;
    int counterheight = 0;
    std::cout << realWidth << std::endl;
    std::cout << realHeight << std::endl;

    for (int i = 0; i < realWidth; i++)
    {

        for (int j = 0; j < realHeight; j++)
        {

            if (i == 0 || j == 0 || i == realWidth || j == realHeight)
            {
                std::cout << "#";
            }
            else
            {
                if (j % 2 == 0)
                {
                    std::cout << "#";
                }
                else if (i % 2 == 0)
                {
                    std::cout << "#";
                }
                else
                {
                    std::cout << myMaze[counterheight][counterwidth].flag;
                    counterwidth++;
                }
            }
        }
        if (counterheight < 3)
        {
            counterheight++;
        }
        counterwidth = 0;
        std::cout << std::endl;
    }
}
