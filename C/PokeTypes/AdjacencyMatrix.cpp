#include "AdjacencyMatrix.h"

float AdjacencyMatrix::GetDataFromMatrix(PokeType moveType, PokeType pokeType) {
	return array1[18 * moveType + pokeType];
}

float AdjacencyMatrix::GetDataFromMatrix2(PokeType moveType, PokeType pokeType) {
	return GetMap(array2[18 * moveType + pokeType]);
}

float AdjacencyMatrix::GetMap(byte x) {
	switch (x) {
	case 0: return 0;
	case 1: return 0.5;
	case 2: return 1;
	case 3: return 2;
	default: return -1;
	}
}