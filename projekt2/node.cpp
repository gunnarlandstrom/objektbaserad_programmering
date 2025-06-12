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

	// Dessa ska väl bort
	this->flag = "*";
	this->eastFlag = "#";
	this->northFlag = "#";
	this->westFlag = "#";
	this->southFlag = "#";


}

void node::markAsOuterNodesEast()
{
	// Flagga ska väl bort, fixa print
	this->eastFlag = "#";
	this->isOuterWall = true;
	this->walkEast = false;
}

void node::markAsOuterNodesSouth()
{
	// Flagga ska väl bort, fixa print
	this->southFlag = "#";
	this->isOuterWall = true;
	this->walkSouth = false;
}

void node::markAsOuterNodesNorth()
{
	// Flagga ska väl bort, fixa print
	this->northFlag = "#";
	this->isOuterWall = true;
	this->walkNorth = false;
}

void node::markAsOuterNodesWest()
{
	// Flagga ska väl bort, fixa print
	this->westFlag = "#";
	this->isOuterWall = true;
	this->walkWest = false;
}

