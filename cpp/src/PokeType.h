#pragma once

typedef unsigned char byte;
typedef signed char sbyte;

enum PokeType : byte
{
  NOR, // 0
  FIR, // 1
  WAT, // 2
  ELE, // 3
  GRA, // 4
  ICE, // 5
  FIG, // 6
  POI, // 7
  GRO, // 8
  FLY, // 9
  PSY, // 10
  BUG, // 11
  ROC, // 12
  GHO, // 13
  DRA, // 14
  DAR, // 15
  STE, // 16
  FAI  // 17
};

namespace pokeTypes
{

  const char pokeTypeStrings[18][4] = {
      "NOR",
      "FIR",
      "WAT",
      "ELE",
      "GRA",
      "ICE",
      "FIG",
      "POI",
      "GRO",
      "FLY",
      "PSY",
      "BUG",
      "ROC",
      "GHO",
      "DRA",
      "DAR",
      "STE",
      "FAI"};

  inline const char *getEnumMap(byte pokeType)
  {
    return pokeTypeStrings[pokeType];
  }

  enum State : byte
  {
    Main,
    PokeTypes
  };

  enum PokeTypesState : byte
  {
    Move,
    Type
  };
}
