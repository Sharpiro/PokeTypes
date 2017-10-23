#pragma once

#include "NeighborNode.h"

NeighborNode::NeighborNode(PokeType pokeType, float data) : Node(pokeType)
{
	Data = data;
}

void NeighborNode::Print()
{
	std::cout << Type << ": " << Data << std::endl;
	if (Neighbor == nullptr) return;
	Neighbor->Print();
}

float NeighborNode::GetMultiplier(PokeType pokeType) {
	if (Type == pokeType) return Data;
	if (Neighbor == nullptr) return 1;
	return ((NeighborNode*)Neighbor)->GetMultiplier(pokeType);
}