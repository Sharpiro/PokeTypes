#include <iostream>
#include "PokeType.h"
#include "Node.h"

Node::Node(PokeType pokeType)
{
	Type = pokeType;
}

void Node::AddNeighbor(Node *newNeighbor)
{
	if (Neighbor == nullptr)
	{
		Neighbor = newNeighbor;
	}
	else
	{
		Neighbor->AddNeighbor(newNeighbor);
	}
}

void Node::Print()
{
	std::cout << Type << std::endl;
	if (Neighbor == nullptr) return;
	Neighbor->Print();
}