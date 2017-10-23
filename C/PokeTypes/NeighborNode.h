#pragma once
#include <iostream>
#include "Node.h"

class NeighborNode : public Node
{
public:
	float Data;
	NeighborNode(PokeType pokeType, float data);
	void Print();
	float GetMultiplier(PokeType pokeType);
};