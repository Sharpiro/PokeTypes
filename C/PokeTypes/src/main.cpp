
#include "../Node.h"
#include "../PokeType.h"
#include <iostream>

typedef unsigned char byte;

const float array[] = {
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

const byte array2[] = {
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 2, 2, 1, 2,
	2, 1, 1, 2, 3, 3, 2, 2, 2, 2, 2, 3, 1, 2, 1, 2, 3, 2,
	2, 3, 1, 2, 1, 2, 2, 2, 3, 2, 2, 2, 3, 2, 1, 2, 2, 2,
	2, 2, 3, 1, 1, 2, 2, 2, 0, 3, 2, 2, 2, 2, 1, 2, 2, 2,
	2, 1, 3, 2, 1, 2, 2, 1, 3, 1, 2, 1, 3, 2, 1, 2, 1, 2,
	2, 1, 1, 2, 3, 1, 2, 2, 3, 3, 2, 2, 2, 2, 3, 2, 1, 2,
	3, 2, 2, 2, 2, 3, 2, 1, 2, 1, 1, 1, 3, 0, 2, 3, 3, 1,
	2, 2, 2, 2, 3, 2, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 0, 3,
	2, 3, 2, 3, 1, 2, 2, 3, 2, 0, 2, 1, 3, 2, 2, 2, 3, 2,
	2, 2, 2, 1, 3, 2, 3, 2, 2, 2, 2, 3, 1, 2, 2, 2, 1, 2,
	2, 2, 2, 2, 2, 2, 3, 3, 2, 2, 1, 2, 2, 2, 2, 0, 1, 2,
	2, 1, 2, 2, 3, 2, 1, 1, 2, 1, 3, 2, 2, 1, 2, 3, 1, 1,
	2, 3, 2, 2, 2, 3, 1, 2, 1, 3, 2, 3, 2, 2, 2, 2, 1, 2,
	0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 3, 2, 1, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 1, 0,
	2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 3, 2, 2, 3, 2, 1, 2, 1,
	2, 1, 1, 1, 2, 3, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 1, 3,
	2, 1, 2, 2, 2, 2, 3, 1, 2, 2, 2, 2, 2, 2, 3, 3, 1, 2
};

float getMap(byte x) {
	switch (x) {
	case 0: return 0;
	case 1: return 0.5;
	case 2: return 1;
	case 3: return 2;
	}
}

const int x = 12;


float getDataFromMatrix(PokeType moveType, PokeType pokeType) {
	return array[18 * moveType + pokeType];
}

float getDataFromMatrix2(PokeType moveType, PokeType pokeType) {
	return array2[18 * moveType + pokeType];
}

class Node
{
public:
	PokeType Type;
	Node *Neighbor;

	Node(PokeType pokeType)
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

	virtual void Node::Print()
	{
		std::cout << Type << std::endl;
		if (Neighbor == nullptr) return;
		Neighbor->Print();
	}
};

class NeighborNode : public Node
{
public:
	float Data;

	NeighborNode(PokeType pokeType, float data) : Node(pokeType)
	{
		Data = data;
	}

	void NeighborNode::Print()
	{
		std::cout << Type << ": " << Data << std::endl;
		if (Neighbor == nullptr) return;
		Neighbor->Print();
	}

	float NeighborNode::GetMultiplier(PokeType pokeType) {
		if (Type == pokeType) return Data;
		if (Neighbor == nullptr) return 1;
		return ((NeighborNode*)Neighbor)->GetMultiplier(pokeType);
	}
};

void verifyList(Node* nodes[]) {
	auto temp = nodes[1];
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			auto moveType = (PokeType)i;
			auto pokeType = (PokeType)j;
			//auto matrixData = getDataFromMatrix(moveType, pokeType);
			auto matrixData = getMap(getDataFromMatrix2(moveType, pokeType));
			auto listData = ((NeighborNode*)nodes[i]->Neighbor)->GetMultiplier(pokeType);
			auto temp = 5;

			if (matrixData != listData)
			{
				std::cout << "error" << std::endl;
			}
		}
	}
}

int main()
{
	//normal
	Node* normalNode = new Node(PokeType::NOR);
	normalNode->AddNeighbor(new NeighborNode(PokeType::ROC, 0.5));
	normalNode->AddNeighbor(new NeighborNode(PokeType::GHO, 0.0));
	normalNode->AddNeighbor(new NeighborNode(PokeType::STE, 0.5));
	////fire
	Node* fireNode = new Node(PokeType::FIR);
	fireNode->AddNeighbor(new NeighborNode(PokeType::FIR, 0.5));
	fireNode->AddNeighbor(new NeighborNode(PokeType::WAT, 0.5));
	fireNode->AddNeighbor(new NeighborNode(PokeType::GRA, 2.0));
	fireNode->AddNeighbor(new NeighborNode(PokeType::ICE, 2.0));
	fireNode->AddNeighbor(new NeighborNode(PokeType::BUG, 2.0));
	fireNode->AddNeighbor(new NeighborNode(PokeType::ROC, 0.5));
	fireNode->AddNeighbor(new NeighborNode(PokeType::DRA, 0.5));
	fireNode->AddNeighbor(new NeighborNode(PokeType::STE, 2.0));
	////water
	Node* waterNode = new Node(PokeType::WAT);
	waterNode->AddNeighbor(new NeighborNode(PokeType::FIR, 2.0));
	waterNode->AddNeighbor(new NeighborNode(PokeType::WAT, 0.5));
	waterNode->AddNeighbor(new NeighborNode(PokeType::GRA, 0.5));
	waterNode->AddNeighbor(new NeighborNode(PokeType::GRO, 2.0));
	waterNode->AddNeighbor(new NeighborNode(PokeType::ROC, 2.0));
	waterNode->AddNeighbor(new NeighborNode(PokeType::DRA, 0.5));
	////electric
	Node* electricNode = new Node(PokeType::ELE);
	electricNode->AddNeighbor(new NeighborNode(PokeType::WAT, 2.0));
	electricNode->AddNeighbor(new NeighborNode(PokeType::ELE, 0.5));
	electricNode->AddNeighbor(new NeighborNode(PokeType::GRA, 0.5));
	electricNode->AddNeighbor(new NeighborNode(PokeType::GRO, 0.0));
	electricNode->AddNeighbor(new NeighborNode(PokeType::FLY, 2.0));
	electricNode->AddNeighbor(new NeighborNode(PokeType::DRA, 0.5));
	////grass
	Node* grassNode = new Node(PokeType::GRA);
	grassNode->AddNeighbor(new NeighborNode(PokeType::FIR, 0.5));
	grassNode->AddNeighbor(new NeighborNode(PokeType::WAT, 2.0));
	grassNode->AddNeighbor(new NeighborNode(PokeType::GRA, 0.5));
	grassNode->AddNeighbor(new NeighborNode(PokeType::POI, 0.5));
	grassNode->AddNeighbor(new NeighborNode(PokeType::GRO, 2.0));
	grassNode->AddNeighbor(new NeighborNode(PokeType::FLY, 0.5));
	grassNode->AddNeighbor(new NeighborNode(PokeType::BUG, 0.5));
	grassNode->AddNeighbor(new NeighborNode(PokeType::ROC, 2.0));
	grassNode->AddNeighbor(new NeighborNode(PokeType::DRA, 0.5));
	grassNode->AddNeighbor(new NeighborNode(PokeType::STE, 0.5));
	//ice
	Node* iceNode = new Node(PokeType::ICE);
	iceNode->AddNeighbor(new NeighborNode(PokeType::FIR, 0.5));
	iceNode->AddNeighbor(new NeighborNode(PokeType::WAT, 0.5));
	iceNode->AddNeighbor(new NeighborNode(PokeType::GRA, 2.0));
	iceNode->AddNeighbor(new NeighborNode(PokeType::ICE, 0.5));
	iceNode->AddNeighbor(new NeighborNode(PokeType::GRO, 2.0));
	iceNode->AddNeighbor(new NeighborNode(PokeType::FLY, 2.0));
	iceNode->AddNeighbor(new NeighborNode(PokeType::DRA, 2.0));
	iceNode->AddNeighbor(new NeighborNode(PokeType::STE, 0.5));
	//fighting
	Node* fightingNode = new Node(PokeType::FIG);
	fightingNode->AddNeighbor(new NeighborNode(PokeType::NOR, 2.0));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::ICE, 2.0));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::POI, 0.5));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::FLY, 0.5));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::PSY, 0.5));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::BUG, 0.5));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::ROC, 2.0));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::GHO, 0.0));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::DAR, 2.0));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::STE, 2.0));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::FAI, 0.5));
	//poison
	Node* poisonNode = new Node(PokeType::POI);
	poisonNode->AddNeighbor(new NeighborNode(PokeType::GRA, 2.0));
	poisonNode->AddNeighbor(new NeighborNode(PokeType::POI, 0.5));
	poisonNode->AddNeighbor(new NeighborNode(PokeType::GRO, 0.5));
	poisonNode->AddNeighbor(new NeighborNode(PokeType::ROC, 0.5));
	poisonNode->AddNeighbor(new NeighborNode(PokeType::GHO, 0.5));
	poisonNode->AddNeighbor(new NeighborNode(PokeType::STE, 0.0));
	poisonNode->AddNeighbor(new NeighborNode(PokeType::FAI, 2.0));
	//ground
	Node* groundNode = new Node(PokeType::GRO);
	groundNode->AddNeighbor(new NeighborNode(PokeType::FIR, 2.0));
	groundNode->AddNeighbor(new NeighborNode(PokeType::ELE, 2.0));
	groundNode->AddNeighbor(new NeighborNode(PokeType::GRA, 0.5));
	groundNode->AddNeighbor(new NeighborNode(PokeType::POI, 2.0));
	groundNode->AddNeighbor(new NeighborNode(PokeType::FLY, 0.0));
	groundNode->AddNeighbor(new NeighborNode(PokeType::BUG, 0.5));
	groundNode->AddNeighbor(new NeighborNode(PokeType::ROC, 2.0));
	groundNode->AddNeighbor(new NeighborNode(PokeType::STE, 2.0));
	//flying
	Node* flyingNode = new Node(PokeType::FLY);
	flyingNode->AddNeighbor(new NeighborNode(PokeType::ELE, 0.5));
	flyingNode->AddNeighbor(new NeighborNode(PokeType::GRA, 2.0));
	flyingNode->AddNeighbor(new NeighborNode(PokeType::FIG, 2.0));
	flyingNode->AddNeighbor(new NeighborNode(PokeType::BUG, 2.0));
	flyingNode->AddNeighbor(new NeighborNode(PokeType::ROC, 0.5));
	flyingNode->AddNeighbor(new NeighborNode(PokeType::STE, 0.5));
	//psychic
	Node* psychicNode = new Node(PokeType::PSY);
	psychicNode->AddNeighbor(new NeighborNode(PokeType::FIG, 2.0));
	psychicNode->AddNeighbor(new NeighborNode(PokeType::POI, 2.0));
	psychicNode->AddNeighbor(new NeighborNode(PokeType::PSY, 0.5));
	psychicNode->AddNeighbor(new NeighborNode(PokeType::DAR, 0.0));
	psychicNode->AddNeighbor(new NeighborNode(PokeType::STE, 0.5));
	//bug
	Node* bugNode = new Node(PokeType::BUG);
	bugNode->AddNeighbor(new NeighborNode(PokeType::FIR, 0.5));
	bugNode->AddNeighbor(new NeighborNode(PokeType::GRA, 2.0));
	bugNode->AddNeighbor(new NeighborNode(PokeType::FIG, 0.5));
	bugNode->AddNeighbor(new NeighborNode(PokeType::POI, 0.5));
	bugNode->AddNeighbor(new NeighborNode(PokeType::FLY, 0.5));
	bugNode->AddNeighbor(new NeighborNode(PokeType::PSY, 2.0));
	bugNode->AddNeighbor(new NeighborNode(PokeType::GHO, 0.5));
	bugNode->AddNeighbor(new NeighborNode(PokeType::DAR, 2.0));
	bugNode->AddNeighbor(new NeighborNode(PokeType::STE, 0.5));
	bugNode->AddNeighbor(new NeighborNode(PokeType::FAI, 0.5));
	//rock
	Node* rockNode = new Node(PokeType::ROC);
	rockNode->AddNeighbor(new NeighborNode(PokeType::FIR, 2.0));
	rockNode->AddNeighbor(new NeighborNode(PokeType::ICE, 2.0));
	rockNode->AddNeighbor(new NeighborNode(PokeType::FIG, 0.5));
	rockNode->AddNeighbor(new NeighborNode(PokeType::GRO, 0.5));
	rockNode->AddNeighbor(new NeighborNode(PokeType::FLY, 2.0));
	rockNode->AddNeighbor(new NeighborNode(PokeType::BUG, 2.0));
	rockNode->AddNeighbor(new NeighborNode(PokeType::STE, 0.5));
	//ghost
	Node* ghostNode = new Node(PokeType::GHO);
	ghostNode->AddNeighbor(new NeighborNode(PokeType::NOR, 0.0));
	ghostNode->AddNeighbor(new NeighborNode(PokeType::PSY, 2.0));
	ghostNode->AddNeighbor(new NeighborNode(PokeType::GHO, 2.0));
	ghostNode->AddNeighbor(new NeighborNode(PokeType::DAR, 0.5));
	//dragon
	Node* dragonNode = new Node(PokeType::DRA);
	dragonNode->AddNeighbor(new NeighborNode(PokeType::DRA, 2.0));
	dragonNode->AddNeighbor(new NeighborNode(PokeType::STE, 0.5));
	dragonNode->AddNeighbor(new NeighborNode(PokeType::FAI, 0.0));
	//dark
	Node* darkNode = new Node(PokeType::DAR);
	darkNode->AddNeighbor(new NeighborNode(PokeType::FIG, 0.5));
	darkNode->AddNeighbor(new NeighborNode(PokeType::PSY, 2.0));
	darkNode->AddNeighbor(new NeighborNode(PokeType::GHO, 2.0));
	darkNode->AddNeighbor(new NeighborNode(PokeType::DAR, 0.5));
	darkNode->AddNeighbor(new NeighborNode(PokeType::FAI, 0.5));
	//steel
	Node* steelNode = new Node(PokeType::STE);
	steelNode->AddNeighbor(new NeighborNode(PokeType::FIR, 0.5));
	steelNode->AddNeighbor(new NeighborNode(PokeType::WAT, 0.5));
	steelNode->AddNeighbor(new NeighborNode(PokeType::ELE, 0.5));
	steelNode->AddNeighbor(new NeighborNode(PokeType::ICE, 2.0));
	steelNode->AddNeighbor(new NeighborNode(PokeType::ROC, 2.0));
	steelNode->AddNeighbor(new NeighborNode(PokeType::STE, 0.5));
	steelNode->AddNeighbor(new NeighborNode(PokeType::FAI, 2.0));
	//fairy
	Node* fairyNode = new Node(PokeType::FAI);
	fairyNode->AddNeighbor(new NeighborNode(PokeType::FIR, 0.5));
	fairyNode->AddNeighbor(new NeighborNode(PokeType::FIG, 2.0));
	fairyNode->AddNeighbor(new NeighborNode(PokeType::POI, 0.5));
	fairyNode->AddNeighbor(new NeighborNode(PokeType::DRA, 2.0));
	fairyNode->AddNeighbor(new NeighborNode(PokeType::DAR, 2.0));
	fairyNode->AddNeighbor(new NeighborNode(PokeType::STE, 0.5));

	Node* nodes[] = {
		normalNode, fireNode, waterNode, electricNode, grassNode, iceNode, fightingNode, poisonNode, groundNode,
		flyingNode, psychicNode, bugNode, rockNode, ghostNode, dragonNode, darkNode, steelNode, fairyNode
	};

	verifyList(nodes);

	std::cout << "completed";
	std::cin.get();
	return 0;
}