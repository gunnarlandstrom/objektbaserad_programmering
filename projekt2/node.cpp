/*
// Project Maze
// Name: Gunnar Landström
// Date: 2025-05-18
// Grade: E+
*/

#include "node.h"

node::node(size_t width, size_t height)
{
	this->x = width;
	this->y = height;
	this->flag = " ";
	this->isVisited = false;
	this->isOuterWall = false;
	this->walkNorth = true;
	this->walkSouth = true;
	this->walkEast = true;
	this->walkWest = true;
	this->eastFlag = "#";
	this->northFlag = "#";
	this->westFlag = "#";
	this->southFlag = "#";


}

void node::markAsOuterNodesEast()
{
	this->eastFlag = "#";
	this->isOuterWall = true;
	this->walkEast = false;
}

void node::markAsOuterNodesSouth()
{
	this->southFlag = "#";
	this->isOuterWall = true;
	this->walkSouth = false;
}

void node::markAsOuterNodesNorth()
{
	this->northFlag = "#";
	this->isOuterWall = true;
	this->walkNorth = false;
}

void node::markAsOuterNodesWest()
{
	this->westFlag = "#";
	this->isOuterWall = true;
	this->walkWest = false;
}

