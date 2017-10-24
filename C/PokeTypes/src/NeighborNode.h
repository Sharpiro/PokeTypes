#pragma once
#include <iostream>
#include "Node.h"

class NeighborNode : public Node
{
public:
	byte Data;
	NeighborNode(PokeType pokeType, byte data);
	void Print();
	float GetMultiplier(PokeType pokeType);
	static float GetMap(byte x);
};