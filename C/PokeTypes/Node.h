#pragma once
#include <iostream>
#include "PokeType.h"

class Node
{
public:
	PokeType Type;
	Node *Neighbor;
	Node(PokeType pokeType);
	void AddNeighbor(Node *newNeighbor);
	virtual void Node::Print();
};