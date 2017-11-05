#pragma once
#include "NeighborNode.h"

class AdjacencyList
{
private:
	AdjacencyList();

public:
	Node* nodes[18];
	static AdjacencyList* Create();
	Node* GetNode(PokeType pokeType);
	float GetAttackMultiplier(PokeType moveType, PokeType pokeType);
};