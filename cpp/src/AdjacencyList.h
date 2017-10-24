#pragma once
#include "NeighborNode.h"

class AdjacencyList
{
public:
	Node* nodes[18];
	AdjacencyList();
	Node* GetNode(PokeType pokeType);
	float GetAttackMultiplier(PokeType moveType, PokeType pokeType);
};