#include "AdjacencyList.h"
#include "Console.h"

//void verifyList(AdjacencyList* adjacencyList, AdjacencyMatrix* adjacencyMatrix) {
//	for (int i = 0; i < 18; i++)
//	{
//		for (int j = 0; j < 18; j++)
//		{
//			auto moveType = (Enums)i;
//			auto pokeType = (Enums)j;
//			auto matrixData1 = adjacencyMatrix->GetDataFromMatrix(moveType, pokeType);
//			auto matrixData2 = adjacencyMatrix->GetDataFromMatrix2(moveType, pokeType);
//			auto listData1 = ((NeighborNode*)adjacencyList->nodes[i]->Neighbor)->GetMultiplier(pokeType);
//			auto listData2 = adjacencyList->GetAttackMultiplier(moveType, pokeType);
//
//			if (matrixData1 != listData1 && listData1 != matrixData2 && matrixData2 != listData2)
//			{
//				Console::WriteLine("error");
//			}
//		}
//	}
//	Console::WriteLine("verified poke data");
//}

State gameState;
PokeTypesState pokeTypesState;
int move;
int type;

void onMainState()
{
	gameState = State::Main;
	Console::WriteLine("Entered main state");
	Console::WriteLine("Press 1 for PokeTypes program");
}

void onMovesState()
{
	pokeTypesState = PokeTypesState::Move;
	Console::WriteLine("Enter move type");
}

void OnPokeState()
{
	gameState = State::PokeTypes;
	Console::WriteLine("Entered PokeTypes state");
	onMovesState();
}

void handleMainStateInput(int input)
{
	switch (input)
	{
	case State::PokeTypes:
		OnPokeState();
		break;
	}
}

void onPokeTypeState()
{
	pokeTypesState = PokeTypesState::Type;
	Console::WriteLine("Enter poke type");
}

void pokeTypesComplete()
{
	Console::Write("move: ");
	Console::WriteLine((PokeType)move);
	Console::Write("type: ");
	Console::WriteLine((PokeType)type);
	Console::WriteLine("severity is 0.5 (not true)");
	onMovesState();
}

void handlePokeTypesState(int input)
{
	if (input < 0)
	{
		pokeTypesState = PokeTypesState::Move;
		onMainState();
		return;
	}
	switch (pokeTypesState)
	{
	case PokeTypesState::Move:
		move = input;
		onPokeTypeState();
		break;
	case PokeTypesState::Type:
		type = input;
		pokeTypesComplete();
		break;
	}
}

void gameLoop(int input)
{
	switch (gameState)
	{
	case State::Main:
		handleMainStateInput(input);
		break;
	case State::PokeTypes:
		handlePokeTypesState(input);
		break;
	}
}

int main()
{
	//auto adjacencyList = new AdjacencyList();
	//auto matrix = new AdjacencyMatrix();

	//verifyList(adjacencyList, matrix);

	//Node* neighbors[15];
	//auto eleNode = adjacencyList->GetNode(Enums::ELE);
	//eleNode->GetNeighbors(neighbors, 0);

	//Console::WriteLine("completed");
	//Console::ReadInt();
	//return 0;
	onMainState();

	while (true)
	{
		int input = Console::ReadInt();
		
		gameLoop(input);
	}
}