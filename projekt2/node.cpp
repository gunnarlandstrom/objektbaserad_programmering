/*
// Project Maze
// Name: Gunnar Landström
// Date: 2025-05-18
// Grade: E
*/

#include "node.h"

node::node(size_t width, size_t height)
{
	this->x = width;
	this->y = height;
	this->isVisited = false;
	this->isOuterWall = false;
	this->walkNorth = true;
	this->walkSouth = true;
	this->walkEast = true;
	this->walkWest = true;
}

void node::markAsOuterNodesEast()
{
	this->isOuterWall = true;
	this->walkEast = false;
}

void node::markAsOuterNodesSouth()
{
	this->isOuterWall = true;
	this->walkSouth = false;
}

void node::markAsOuterNodesNorth()
{
	this->isOuterWall = true;
	this->walkNorth = false;
}

void node::markAsOuterNodesWest()
{
	this->isOuterWall = true;
	this->walkWest = false;
}

