#pragma once
#include "PokeType.h"

class Node
{
public:
	PokeType Type;
	Node *Neighbor;
	Node(PokeType pokeType);
	void AddNeighbor(Node *newNeighbor);
	virtual void GetNeighbors(Node* x[15], int currentIndex);
};