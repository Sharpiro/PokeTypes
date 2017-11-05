#ifdef Windows
#include "AdjacencyList.h"
#include "Console.h"
#include <string>
#include <iostream>

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

AdjacencyList* adjacencyList;

//const char pokeTypeStrings[18][4] = {
//	"NOR",
//	"FIR",
//	"WAT",
//	"ELE",
//	"GRA",
//	"ICE",
//	"FIG",
//	"POI",
//	"GRO",
//	"FLY",
//	"PSY",
//	"BUG",
//	"ROC",
//	"GHO",
//	"DRA",
//	"DAR",
//	"STE",
//	"FAI"
//};
//
//const char* getEnumMap(byte pokeType)
//{
//	auto type = pokeTypeStrings[pokeType];
//	return type;
//}

pokeTypes::State gameState;
pokeTypes::PokeTypesState pokeTypesState;
PokeType move;
PokeType type;

void onMainState()
{
	gameState = pokeTypes::State::Main;
	Console::WriteLine("Entered main state");
	Console::WriteLine("Press 1 for PokeTypes program");
}

void onMovesState()
{
	pokeTypesState = pokeTypes::PokeTypesState::Move;
	Console::WriteLine("Enter move type");
}

void OnPokeState()
{
	gameState = pokeTypes::State::PokeTypes;
	Console::WriteLine("Entered PokeTypes state");
	onMovesState();
}

void handleMainStateInput(int input)
{
	switch (input)
	{
	case pokeTypes::State::PokeTypes:
		OnPokeState();
		break;
	}
}

void onPokeTypeState()
{
	pokeTypesState = pokeTypes::PokeTypesState::Type;
	Console::WriteLine("Enter poke type");
}

void pokeTypesComplete()
{
	Console::Write("move: ");
	Console::WriteLine(pokeTypes::getEnumMap(move));
	Console::Write("type: ");
	Console::WriteLine(pokeTypes::getEnumMap(type));
	auto multiplier = adjacencyList->GetAttackMultiplier(move, type);
	auto data = std::to_string(multiplier);
	auto cppString = data.c_str();
	Console::WriteLine(cppString);
	onMovesState();
}

void handlePokeTypesState(int input)
{
	if (input < 0)
	{
		pokeTypesState = pokeTypes::PokeTypesState::Move;
		onMainState();
		return;
	}
	switch (pokeTypesState)
	{
	case pokeTypes::PokeTypesState::Move:
		move = (PokeType)input;
		onPokeTypeState();
		break;
	case pokeTypes::PokeTypesState::Type:
		type = (PokeType)input;
		pokeTypesComplete();
		break;
	}
}

void gameLoop(int input)
{
	switch (gameState)
	{
	case pokeTypes::State::Main:
		handleMainStateInput(input);
		break;
	case pokeTypes::State::PokeTypes:
		handlePokeTypesState(input);
		break;
	}
}

int main()
{
	adjacencyList = AdjacencyList::Create();
	onMainState();

	while (true)
	{
		int input = Console::ReadInt();

		gameLoop(input);
	}
}
#endif