#pragma once
#include "Node.h"

class NeighborNode : public Node
{
public:
	byte Data;
	NeighborNode(PokeType pokeType, byte data);
	float GetMultiplier(PokeType pokeType);
	static float GetMap(byte x);
	void GetNeighbors(NeighborNode* x[15], int currentIndex);
};