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

void Node::GetNeighbors(Node* x[15], int currentIndex)
{
	if (Neighbor == nullptr) return;
	x[currentIndex] = Neighbor;
	Neighbor->GetNeighbors(x, ++currentIndex);
}