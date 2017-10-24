#pragma once
#include "NeighborNode.h"

NeighborNode::NeighborNode(PokeType pokeType, byte data) : Node(pokeType)
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
	if (Type == pokeType) return GetMap(Data);
	if (Neighbor == nullptr) return GetMap(2);
	return ((NeighborNode*)Neighbor)->GetMultiplier(pokeType);
}

float NeighborNode::GetMap(byte x) {
	switch (x) {
	case 0: return 0;
	case 1: return 0.5;
	case 2: return 1;
	case 3: return 2;
	default: return -1;
	}
}