#include "src/AdjacencyList.h"
#include "src/AdjacencyMatrix.h"
#include "src/Console.h"

void verifyList(AdjacencyList* adjacencyList, AdjacencyMatrix* adjacencyMatrix);

void setup()
{
	auto adjacencyList = new AdjacencyList();
	auto matrix = new AdjacencyMatrix();

	verifyList(adjacencyList, matrix);

	Node* neighbors[15];
	auto eleNode = adjacencyList->GetNode(PokeType::ELE);
	eleNode->GetNeighbors(neighbors, 0);

	Console::Log("completed");
	Console::Get();
}

void loop()
{
  // put your main code here, to run repeatedly:
}