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

            tile temptile(row, col, width, height);
            heightTiles.push_back(temptile);
            if (heightTiles[row].isEdge)
            {
                edges.push_back(temptile);
                std::cout << "This is an edge! At column: " << col << " and row: " << row << std::endl;
            }
        }
        myMaze.push_back(heightTiles);
    }
    markStart();
    markEnd();

    char direction = randomizeDirection();
    firstStep(direction);
}

labyrinth::~labyrinth()
{
}

void labyrinth::markStart()
{
    myMaze[0][1].flag = "S";
    myMaze[0][1].isVisited = true;
    myMaze[0][1].isWall = false;
    pos.first = 0;
    pos.second = 1;
}

void labyrinth::firstStep(char direction)
{
    if (pos.first == 0)
    {
        std::cout << "Stepping south!" << std::endl;
        pos.first = pos.first + 1;
        myMaze[pos.first][pos.second].isVisited = true;
        myMaze[pos.first][pos.second].isWall = false;
        myMaze[pos.first][pos.second].flag = "?";
    }
    else if (pos.first == height - 1)
    {
        std::cout << "Stepping north!" << std::endl;
        pos.first = pos.first - 1;
        myMaze[pos.first][pos.second].isVisited = true;
        myMaze[pos.first][pos.second].isWall = false;
        myMaze[pos.first][pos.second].flag = "?";
    }
    else if (pos.second == 0)
    {
        std::cout << "Stepping east!" << std::endl;
        pos.second = pos.second + 1;
        myMaze[pos.first][pos.second].isVisited = true;
        myMaze[pos.first][pos.second].isWall = false;
        myMaze[pos.first][pos.second].flag = "?";
    }
    else if (pos.second == width - 1)
    {
        std::cout << "Stepping west!" << std::endl;
        pos.second = pos.second - 1;
        myMaze[pos.first][pos.second].isVisited = true;
        myMaze[pos.first][pos.second].isWall = false;
        myMaze[pos.first][pos.second].flag = "?";
    }
    else
    {
        std::cout << "Error, firstStep pos out of position! " << std::endl;
    }
}

void labyrinth::markEnd()
{
    myMaze[height - 1][width - 2].flag = "E";
    myMaze[height - 1][width - 2].isVisited = true;
    myMaze[height - 1][width - 2].isWall = false;
    end.first = height - 2;
    end.second = width - 2;
}
bool labyrinth::isEdge()
{
    return 0;
}

int labyrinth::canMove(char direction)
{
    if (direction == 'S')
    {
        if (myMaze[pos.first + 1][pos.second].isEdge || myMaze[pos.first + 1][pos.second].isVisited)
        {
            return false;
        }
    }
    else if (direction == 'W')
    {
        if (myMaze[pos.first][pos.second - 1].isEdge || myMaze[pos.first][pos.second - 1].isVisited)
        {
            return false;
        }
    }
    else if (direction == 'E')
    {

        if (myMaze[pos.first][pos.second + 1].isEdge || myMaze[pos.first][pos.second + 1].isVisited)
        {
            return false;
        }
    }
    else if (direction == 'N')
    {
        if (myMaze[pos.first - 1][pos.second].isEdge || myMaze[pos.first - 1][pos.second].isVisited)
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

    for (size_t col = 0; col < this->width; col++)
    {

        for (size_t row = 0; row < this->height; row++)
        {
            std::cout << myMaze[col][row].flag << " ";
            // std::cout << myMaze[col][row].x << myMaze[col][row].y << " ";
        }
        std::cout << std::endl;
    }
}
