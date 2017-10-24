#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include <iostream>

void verifyList(AdjacencyList* adjacencyList, AdjacencyMatrix* adjacencyMatrix) {
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			auto moveType = (PokeType)i;
			auto pokeType = (PokeType)j;
			auto matrixData1 = adjacencyMatrix->GetDataFromMatrix(moveType, pokeType);
			auto matrixData2 = adjacencyMatrix->GetDataFromMatrix2(moveType, pokeType);
			auto listData1 = ((NeighborNode*)adjacencyList->nodes[i]->Neighbor)->GetMultiplier(pokeType);
			auto listData2 = adjacencyList->GetAttackMultiplier(moveType, pokeType);

			if (matrixData1 != listData1 && listData1 != matrixData2 && matrixData2 != listData2)
			{
				std::cout << "error" << std::endl;
			}
		}
	}
}

int main()
{
	try {
		auto adjacencyList = new AdjacencyList();
		auto matrix = new AdjacencyMatrix();

		verifyList(adjacencyList, matrix);

	}
	catch (int e) {
		std::cout << "Exception: " << e;
		return e;
	}
	std::cout << "completed";
	std::cin.get();
	return 0;
}