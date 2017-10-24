#include "src/AdjacencyList.h"
#include "src/AdjacencyMatrix.h"

void setup()
{
  auto adjacencyList = new AdjacencyList();
  auto matrix = new AdjacencyMatrix();

  Node *x[15];
  auto eleNode = adjacencyList->GetNode(PokeType::ELE);
  eleNode->GetNeighbors(x, 0);
  // put your setup code here, to run once:
}

void loop()
{
  // put your main code here, to run repeatedly:
}