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

            heightTiles.push_back(tile(row, col, width, height));
        }
        myMaze.push_back(heightTiles);
    }
    markStart();
    markEnd();

    while (mover.first != height - 2 || mover.second != width - 2)
    {

        char direction = randomizeDirection();

        int steps = canMove(mover.first, mover.second, direction);
        if (steps > 0)
        {

            move(direction, steps);
            std::cout << "-----" << std::endl
                      << std::endl;
            print();
        }
    }
}

labyrinth::~labyrinth()
{
}

void labyrinth::markStart()
{
    myMaze[0][1].flag = "S";
    myMaze[0][1].isVisited = true;
    myMaze[0][1].isWall = false;
    mover.first = 0;
    mover.second = 1;
}

void labyrinth::markEnd()
{
    myMaze[height - 1][width - 2].flag = "E";
    myMaze[height - 1][width - 2].isVisited = true;
    myMaze[height - 1][width - 2].isWall = false;
    end.first = height - 1;
    end.second = width - 2;
}
bool labyrinth::isEdge()
{
    return 0;
}

int labyrinth::canMove(int row, int col, char direction)
{
    if (mover.second == 0 && direction == 'W')
    {
        std::cout << "This would be west out of bounds!" << std::endl;
        return false;
    }
    else if (mover.second == width && direction == 'E')
    {
        std::cout << "This would be east out of bounds!" << std::endl;
        return false;
    }
    else if (mover.first == 0 && direction == 'N')
    {
        std::cout << "This would be north out of bounds!" << std::endl;
        return false;
    }
    else if (mover.first == height && direction == 'S')
    {
        std::cout << "This would be south out of bounds!" << std::endl;
        return false;
    }
    else
    {
        if (direction == 'N')
        {
            if (myMaze[mover.first - 1][mover.second].isVisited)
            {
                std::cout << "I cannot move north! " << std::endl;
                return false;
            }
            else
            {

                if (myMaze[mover.first - 1][mover.second].isEdge)
                {
                    std::cout << "Moving north once!" << std::endl;
                    return 1;
                }
                else if (myMaze[mover.first - 2][mover.second].isVisited)
                {
                    std::cout << "Moving north once!" << std::endl;
                    return 1;
                }
                std::cout << "Moving north twice!" << std::endl;
                return 2;
            }
        }
        else if (direction == 'W')
        {
            if (myMaze[mover.first][mover.second - 1].isVisited)
            {
                std::cout << "I cannot move west! " << std::endl;
                return false;
            }
            else
            {
                if (myMaze[mover.first][mover.second - 1].isEdge)
                {
                    std::cout << "Moving west once!" << std::endl;
                    return 1;
                }
                else if (myMaze[mover.first][mover.second - 2].isVisited)
                {
                    std::cout << "Moving west once!" << std::endl;
                    return 1;
                }
                std::cout << "Moving west twice!" << std::endl;
                return 2;
            }
        }
        else if (direction == 'E')
        {
            if (myMaze[mover.first][mover.second + 1].isVisited)
            {
                std::cout << "I cannot move east! " << std::endl;
                return false;
            }
            else
            {
                if (myMaze[mover.first][mover.second + 1].isEdge)
                {

                    std::cout << "Moving east once!" << std::endl;
                    return 1;
                }
                else if (myMaze[mover.first][mover.second + 2].isVisited)
                {
                    std::cout << "Moving east once!" << std::endl;
                    return 1;
                }
                std::cout << "Moving east twice!" << std::endl;
                return 2;
            }
        }
        else if (direction == 'S')
        {
            if (myMaze[mover.first + 1][mover.second].isVisited)
            {
                std::cout << "I cannot move south! " << std::endl;
                return false;
            }
            else
            {
                if (myMaze[mover.first + 1][mover.second].isEdge)
                {
                    std::cout << "Moving south once!" << std::endl;
                    return 1;
                }
                else if (myMaze[mover.first + 2][mover.second].isVisited)
                {
                    std::cout << "Moving south once!" << std::endl;
                    return 1;
                }
                std::cout << "Moving south twice!" << std::endl;
                return 2;
            }
        }
    }
    return true;
}

void labyrinth::move(char direction, int steps)
{
    if (steps == 0)
    {
        return;
    }
    if (direction == 'S')
    {
        savedPosition.push_back(mover);
        mover.first = mover.first + 1;
        myMaze[mover.first][mover.second].isVisited = true;
        myMaze[mover.first][mover.second].flag = " ";
        if (steps == 2)
        {
            mover.first = mover.first + 1;
            myMaze[mover.first][mover.second].isVisited = true;
            myMaze[mover.first][mover.second].flag = " ";
        }
    }
    else if (direction == 'W')
    {
        savedPosition.push_back(mover);
        mover.second = mover.second - 1;
        myMaze[mover.first][mover.second].isVisited = true;
        myMaze[mover.first][mover.second].flag = " ";
        if (steps == 2)
        {
            mover.second = mover.second - 1;
            myMaze[mover.first][mover.second].isVisited = true;
            myMaze[mover.first][mover.second].flag = " ";
        }
    }
    else if (direction == 'E')
    {
        savedPosition.push_back(mover);
        mover.second = mover.second + 1;
        myMaze[mover.first][mover.second].isVisited = true;
        myMaze[mover.first][mover.second].flag = " ";
        if (steps == 2)
        {
            mover.second = mover.second + 1;
            myMaze[mover.first][mover.second].isVisited = true;
            myMaze[mover.first][mover.second].flag = " ";
        }
    }
    else if (direction == 'N')
    {
        savedPosition.push_back(mover);
        mover.first = mover.first - 1;
        myMaze[mover.first][mover.second].isVisited = true;
        myMaze[mover.first][mover.second].flag = " ";
        if (steps == 2)
        {
            mover.first = mover.first - 1;
            myMaze[mover.first][mover.second].isVisited = true;
            myMaze[mover.first][mover.second].flag = " ";
        }
    }
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
