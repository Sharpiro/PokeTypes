float array[] = {
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 0.0, 1.0, 1.0, 0.5, 1.0,
	1.0, 0.5, 0.5, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 2.0, 1.0,
	1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0, 1.0,
	1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0,
	1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 0.5, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 0.5, 1.0,
	1.0, 0.5, 0.5, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0,
	2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5, 0.5, 0.5, 2.0, 0.0, 1.0, 2.0, 2.0, 0.5,
	1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 0.0, 2.0,
	1.0, 2.0, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0,
	1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5, 1.0,
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 0.0, 0.5, 1.0,
	1.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.5, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0, 0.5, 1.0, 2.0, 0.5, 0.5,
	1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0,
	0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 0.0,
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5,
	1.0, 0.5, 0.5, 0.5, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 2.0,
	1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 0.5, 1.0
};

typedef unsigned char byte;

#include <iostream>

enum PokeType : byte
{
	NOR, //0
	FIR, //1
	WAT, //2
	ELE, //3
	GRA, //4
	ICE, //5
	FIG, //6
	POI, //7
	GRO, //8
	FLY, //9
	PSY, //10
	BUG, //11
	ROC, //12
	GHO, //13
	DRA, //14
	DAR, //15
	STE, //16
	FAI	 //17
};

class BaseNeighbor
{
public:
	PokeType Type;
	BaseNeighbor *Neighbor;

public:
	BaseNeighbor(PokeType pokeType)
	{
		Type = pokeType;
	}

	void BaseNeighbor::AddNeighbor(BaseNeighbor *newNeighbor)
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

	virtual void BaseNeighbor::Print()
	{
		std::cout << Type << std::endl;
		if (Neighbor == nullptr) return;
		Neighbor->Print();
	}
};

class PokeNeighbor : public BaseNeighbor
{
public:
	float Data;

	PokeNeighbor(PokeType pokeType, float data) : BaseNeighbor(pokeType)
	{
		Data = data;
	}

	void PokeNeighbor::Print()
	{
		std::cout << Type << ": " << Data << std::endl;
		if (Neighbor == nullptr) return;
		Neighbor->Print();
	}
};

class Node : public BaseNeighbor
{
public:
	Node(PokeType pokeType) : BaseNeighbor(pokeType)
	{
	}
};

float getData(PokeNeighbor* neighbor, PokeType pokeType) {
	if (neighbor == nullptr) return 1;
	if (neighbor->Type == pokeType) return neighbor->Data;
	return getData((PokeNeighbor*)neighbor->Neighbor, pokeType);
}

float getDataFromMatrix(PokeType moveType, PokeType pokeType) {
	return array[18 * moveType + pokeType];
}

int main()
{
	auto temp = sizeof(PokeType);
	//normal
	Node* normalNode = new Node(PokeType::NOR);
	normalNode->AddNeighbor(new PokeNeighbor(PokeType::ROC, 0.5));
	normalNode->AddNeighbor(new PokeNeighbor(PokeType::GHO, 0.0));
	normalNode->AddNeighbor(new PokeNeighbor(PokeType::STE, 0.5));
	////fire
	Node* fireNode = new Node(PokeType::FIR);
	fireNode->AddNeighbor(new PokeNeighbor(PokeType::FIR, 0.5));
	fireNode->AddNeighbor(new PokeNeighbor(PokeType::WAT, 0.5));
	fireNode->AddNeighbor(new PokeNeighbor(PokeType::GRA, 2.0));
	fireNode->AddNeighbor(new PokeNeighbor(PokeType::ICE, 2.0));
	fireNode->AddNeighbor(new PokeNeighbor(PokeType::BUG, 2.0));
	fireNode->AddNeighbor(new PokeNeighbor(PokeType::ROC, 0.5));
	fireNode->AddNeighbor(new PokeNeighbor(PokeType::DRA, 0.5));
	fireNode->AddNeighbor(new PokeNeighbor(PokeType::STE, 2.0));
	////water
	Node* waterNode = new Node(PokeType::WAT);
	waterNode->AddNeighbor(new PokeNeighbor(PokeType::FIR, 2.0));
	waterNode->AddNeighbor(new PokeNeighbor(PokeType::WAT, 0.5));
	waterNode->AddNeighbor(new PokeNeighbor(PokeType::GRA, 0.5));
	waterNode->AddNeighbor(new PokeNeighbor(PokeType::GRO, 2.0));
	waterNode->AddNeighbor(new PokeNeighbor(PokeType::ROC, 2.0));
	waterNode->AddNeighbor(new PokeNeighbor(PokeType::DRA, 0.5));
	////electric
	Node* electricNode = new Node(PokeType::ELE);
	electricNode->AddNeighbor(new PokeNeighbor(PokeType::WAT, 2.0));
	electricNode->AddNeighbor(new PokeNeighbor(PokeType::ELE, 0.5));
	electricNode->AddNeighbor(new PokeNeighbor(PokeType::GRA, 0.5));
	electricNode->AddNeighbor(new PokeNeighbor(PokeType::FLY, 2.0));
	electricNode->AddNeighbor(new PokeNeighbor(PokeType::DRA, 0.5));
	////grass
	Node* grassNode = new Node(PokeType::GRA);
	grassNode->AddNeighbor(new PokeNeighbor(PokeType::FIR, 0.5));
	grassNode->AddNeighbor(new PokeNeighbor(PokeType::WAT, 2.0));
	grassNode->AddNeighbor(new PokeNeighbor(PokeType::GRA, 0.5));
	grassNode->AddNeighbor(new PokeNeighbor(PokeType::POI, 0.5));
	grassNode->AddNeighbor(new PokeNeighbor(PokeType::GRO, 2.0));
	grassNode->AddNeighbor(new PokeNeighbor(PokeType::FLY, 0.5));
	grassNode->AddNeighbor(new PokeNeighbor(PokeType::BUG, 0.5));
	grassNode->AddNeighbor(new PokeNeighbor(PokeType::ROC, 2.0));
	grassNode->AddNeighbor(new PokeNeighbor(PokeType::DRA, 0.5));
	grassNode->AddNeighbor(new PokeNeighbor(PokeType::STE, 0.5));
	//ice
	Node* iceNode = new Node(PokeType::ICE);
	iceNode->AddNeighbor(new PokeNeighbor(PokeType::FIR, 0.5));
	iceNode->AddNeighbor(new PokeNeighbor(PokeType::WAT, 0.5));
	iceNode->AddNeighbor(new PokeNeighbor(PokeType::GRA, 2.0));
	iceNode->AddNeighbor(new PokeNeighbor(PokeType::ICE, 0.5));
	iceNode->AddNeighbor(new PokeNeighbor(PokeType::GRO, 2.0));
	iceNode->AddNeighbor(new PokeNeighbor(PokeType::FLY, 2.0));
	iceNode->AddNeighbor(new PokeNeighbor(PokeType::DRA, 2.0));
	iceNode->AddNeighbor(new PokeNeighbor(PokeType::STE, 0.5));
	//fighting
	Node* fightingNode = new Node(PokeType::FIG);
	fightingNode->AddNeighbor(new PokeNeighbor(PokeType::NOR, 2.0));
	fightingNode->AddNeighbor(new PokeNeighbor(PokeType::ICE, 2.0));
	fightingNode->AddNeighbor(new PokeNeighbor(PokeType::POI, 0.5));
	fightingNode->AddNeighbor(new PokeNeighbor(PokeType::FLY, 0.5));
	fightingNode->AddNeighbor(new PokeNeighbor(PokeType::PSY, 0.5));
	fightingNode->AddNeighbor(new PokeNeighbor(PokeType::BUG, 0.5));
	fightingNode->AddNeighbor(new PokeNeighbor(PokeType::ROC, 2.0));
	fightingNode->AddNeighbor(new PokeNeighbor(PokeType::GHO, 0.0));
	fightingNode->AddNeighbor(new PokeNeighbor(PokeType::DAR, 2.0));
	fightingNode->AddNeighbor(new PokeNeighbor(PokeType::STE, 2.0));
	fightingNode->AddNeighbor(new PokeNeighbor(PokeType::FAI, 0.5));
	//poison
	Node* poisonNode = new Node(PokeType::POI);
	poisonNode->AddNeighbor(new PokeNeighbor(PokeType::GRA, 2.0));
	poisonNode->AddNeighbor(new PokeNeighbor(PokeType::POI, 0.5));
	poisonNode->AddNeighbor(new PokeNeighbor(PokeType::GRO, 0.5));
	poisonNode->AddNeighbor(new PokeNeighbor(PokeType::ROC, 0.5));
	poisonNode->AddNeighbor(new PokeNeighbor(PokeType::GHO, 0.5));
	poisonNode->AddNeighbor(new PokeNeighbor(PokeType::FAI, 2.0));
	//ground
	Node* groundNode = new Node(PokeType::GRO);
	groundNode->AddNeighbor(new PokeNeighbor(PokeType::FIR, 2.0));
	groundNode->AddNeighbor(new PokeNeighbor(PokeType::ELE, 2.0));
	groundNode->AddNeighbor(new PokeNeighbor(PokeType::GRA, 0.5));
	groundNode->AddNeighbor(new PokeNeighbor(PokeType::POI, 2.0));
	groundNode->AddNeighbor(new PokeNeighbor(PokeType::FLY, 0.0));
	groundNode->AddNeighbor(new PokeNeighbor(PokeType::BUG, 0.5));
	groundNode->AddNeighbor(new PokeNeighbor(PokeType::ROC, 2.0));
	groundNode->AddNeighbor(new PokeNeighbor(PokeType::STE, 2.0));
	//flying
	Node* flyingNode = new Node(PokeType::FLY);
	flyingNode->AddNeighbor(new PokeNeighbor(PokeType::ELE, 0.5));
	flyingNode->AddNeighbor(new PokeNeighbor(PokeType::GRA, 2.0));
	flyingNode->AddNeighbor(new PokeNeighbor(PokeType::FIG, 2.0));
	flyingNode->AddNeighbor(new PokeNeighbor(PokeType::BUG, 2.0));
	flyingNode->AddNeighbor(new PokeNeighbor(PokeType::ROC, 0.5));
	flyingNode->AddNeighbor(new PokeNeighbor(PokeType::STE, 0.5));
	//psychic
	Node* psychicNode = new Node(PokeType::PSY);
	psychicNode->AddNeighbor(new PokeNeighbor(PokeType::FIG, 2.0));
	psychicNode->AddNeighbor(new PokeNeighbor(PokeType::POI, 2.0));
	psychicNode->AddNeighbor(new PokeNeighbor(PokeType::PSY, 0.5));
	psychicNode->AddNeighbor(new PokeNeighbor(PokeType::STE, 0.5));
	//bug
	Node* bugNode = new Node(PokeType::BUG);
	bugNode->AddNeighbor(new PokeNeighbor(PokeType::FIR, 0.5));
	bugNode->AddNeighbor(new PokeNeighbor(PokeType::GRA, 2.0));
	bugNode->AddNeighbor(new PokeNeighbor(PokeType::FIG, 0.5));
	bugNode->AddNeighbor(new PokeNeighbor(PokeType::POI, 0.5));
	bugNode->AddNeighbor(new PokeNeighbor(PokeType::FLY, 0.5));
	bugNode->AddNeighbor(new PokeNeighbor(PokeType::PSY, 2.0));
	bugNode->AddNeighbor(new PokeNeighbor(PokeType::GHO, 0.5));
	bugNode->AddNeighbor(new PokeNeighbor(PokeType::DAR, 2.0));
	bugNode->AddNeighbor(new PokeNeighbor(PokeType::STE, 0.5));
	bugNode->AddNeighbor(new PokeNeighbor(PokeType::FAI, 0.5));
	//rock
	Node* rockNode = new Node(PokeType::ROC);
	rockNode->AddNeighbor(new PokeNeighbor(PokeType::FIR, 2.0));
	rockNode->AddNeighbor(new PokeNeighbor(PokeType::ICE, 2.0));
	rockNode->AddNeighbor(new PokeNeighbor(PokeType::FIG, 0.5));
	rockNode->AddNeighbor(new PokeNeighbor(PokeType::GRO, 0.5));
	rockNode->AddNeighbor(new PokeNeighbor(PokeType::FLY, 2.0));
	rockNode->AddNeighbor(new PokeNeighbor(PokeType::BUG, 2.0));
	rockNode->AddNeighbor(new PokeNeighbor(PokeType::STE, 0.5));
	//ghost
	Node* ghostNode = new Node(PokeType::GHO);
	ghostNode->AddNeighbor(new PokeNeighbor(PokeType::NOR, 0.0));
	ghostNode->AddNeighbor(new PokeNeighbor(PokeType::PSY, 2.0));
	ghostNode->AddNeighbor(new PokeNeighbor(PokeType::GHO, 2.0));
	ghostNode->AddNeighbor(new PokeNeighbor(PokeType::DAR, 0.5));
	//dragon
	Node* dragonNode = new Node(PokeType::DRA);
	dragonNode->AddNeighbor(new PokeNeighbor(PokeType::DRA, 2.0));
	dragonNode->AddNeighbor(new PokeNeighbor(PokeType::STE, 0.5));
	dragonNode->AddNeighbor(new PokeNeighbor(PokeType::FAI, 0.0));
	//dark
	Node* darkNode = new Node(PokeType::DAR);
	darkNode->AddNeighbor(new PokeNeighbor(PokeType::FIG, 0.5));
	darkNode->AddNeighbor(new PokeNeighbor(PokeType::PSY, 2.0));
	darkNode->AddNeighbor(new PokeNeighbor(PokeType::GHO, 2.0));
	darkNode->AddNeighbor(new PokeNeighbor(PokeType::DAR, 0.5));
	darkNode->AddNeighbor(new PokeNeighbor(PokeType::FAI, 0.5));
	//steel
	Node* steelNode = new Node(PokeType::STE);
	steelNode->AddNeighbor(new PokeNeighbor(PokeType::FIR, 0.5));
	steelNode->AddNeighbor(new PokeNeighbor(PokeType::WAT, 0.5));
	steelNode->AddNeighbor(new PokeNeighbor(PokeType::ELE, 0.5));
	steelNode->AddNeighbor(new PokeNeighbor(PokeType::ICE, 2.0));
	steelNode->AddNeighbor(new PokeNeighbor(PokeType::ROC, 2.0));
	steelNode->AddNeighbor(new PokeNeighbor(PokeType::STE, 0.5));
	steelNode->AddNeighbor(new PokeNeighbor(PokeType::FAI, 2.0));
	//fairy
	Node* fairyNode = new Node(PokeType::FAI);
	fairyNode->AddNeighbor(new PokeNeighbor(PokeType::FIR, 0.5));
	fairyNode->AddNeighbor(new PokeNeighbor(PokeType::FIG, 2.0));
	fairyNode->AddNeighbor(new PokeNeighbor(PokeType::POI, 0.5));
	fairyNode->AddNeighbor(new PokeNeighbor(PokeType::DRA, 2.0));
	fairyNode->AddNeighbor(new PokeNeighbor(PokeType::DAR, 2.0));
	fairyNode->AddNeighbor(new PokeNeighbor(PokeType::STE, 0.5));

	Node* nodes[] = {
		normalNode, fireNode, waterNode, electricNode, grassNode, iceNode, fightingNode, poisonNode, groundNode,
		flyingNode, psychicNode, bugNode, rockNode, ghostNode, dragonNode, darkNode, steelNode, fairyNode
	};

	auto dmg1 = getData((PokeNeighbor*)darkNode->Neighbor, PokeType::PSY);
	auto dmg2 = getData((PokeNeighbor*)darkNode->Neighbor, PokeType::GHO);
	auto dmg3 = getData((PokeNeighbor*)darkNode->Neighbor, PokeType::FIG);
	auto dmg4 = getData((PokeNeighbor*)darkNode->Neighbor, PokeType::NOR);

	auto dmg5 = getDataFromMatrix(PokeType::DAR, PokeType::PSY);
	auto dmg6 = getDataFromMatrix(PokeType::DAR, PokeType::GHO);
	auto dmg7 = getDataFromMatrix(PokeType::DAR, PokeType::FIG);
	auto dmg8 = getDataFromMatrix(PokeType::DAR, PokeType::NOR);

	std::cin.get();
	return 0;
}

