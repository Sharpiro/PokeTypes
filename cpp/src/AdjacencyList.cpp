#include "AdjacencyList.h"

AdjacencyList::AdjacencyList()
{
}

AdjacencyList *AdjacencyList::Create()
{
	auto list = new AdjacencyList();
	//normal
	Node *normalNode = new Node(PokeType::NOR);
	list->nodes[0] = normalNode;
	normalNode->AddNeighbor(new NeighborNode(PokeType::ROC, 1));
	normalNode->AddNeighbor(new NeighborNode(PokeType::GHO, 0));
	normalNode->AddNeighbor(new NeighborNode(PokeType::STE, 1));
	//fire
	Node *fireNode = new Node(PokeType::FIR);
	list->nodes[1] = fireNode;
	fireNode->AddNeighbor(new NeighborNode(PokeType::FIR, 1));
	fireNode->AddNeighbor(new NeighborNode(PokeType::WAT, 1));
	fireNode->AddNeighbor(new NeighborNode(PokeType::GRA, 3));
	fireNode->AddNeighbor(new NeighborNode(PokeType::ICE, 3));
	fireNode->AddNeighbor(new NeighborNode(PokeType::BUG, 3));
	fireNode->AddNeighbor(new NeighborNode(PokeType::ROC, 1));
	fireNode->AddNeighbor(new NeighborNode(PokeType::DRA, 1));
	fireNode->AddNeighbor(new NeighborNode(PokeType::STE, 3));
	////water
	Node *waterNode = new Node(PokeType::WAT);
	list->nodes[2] = waterNode;
	waterNode->AddNeighbor(new NeighborNode(PokeType::FIR, 3));
	waterNode->AddNeighbor(new NeighborNode(PokeType::WAT, 1));
	waterNode->AddNeighbor(new NeighborNode(PokeType::GRA, 1));
	waterNode->AddNeighbor(new NeighborNode(PokeType::GRO, 3));
	waterNode->AddNeighbor(new NeighborNode(PokeType::ROC, 3));
	waterNode->AddNeighbor(new NeighborNode(PokeType::DRA, 1));
	////electric
	Node *electricNode = new Node(PokeType::ELE);
	list->nodes[3] = electricNode;
	electricNode->AddNeighbor(new NeighborNode(PokeType::WAT, 3));
	electricNode->AddNeighbor(new NeighborNode(PokeType::ELE, 1));
	electricNode->AddNeighbor(new NeighborNode(PokeType::GRA, 1));
	electricNode->AddNeighbor(new NeighborNode(PokeType::GRO, 0));
	electricNode->AddNeighbor(new NeighborNode(PokeType::FLY, 3));
	electricNode->AddNeighbor(new NeighborNode(PokeType::DRA, 1));
	////grass
	Node *grassNode = new Node(PokeType::GRA);
	list->nodes[4] = grassNode;
	grassNode->AddNeighbor(new NeighborNode(PokeType::FIR, 1));
	grassNode->AddNeighbor(new NeighborNode(PokeType::WAT, 3));
	grassNode->AddNeighbor(new NeighborNode(PokeType::GRA, 1));
	grassNode->AddNeighbor(new NeighborNode(PokeType::POI, 1));
	grassNode->AddNeighbor(new NeighborNode(PokeType::GRO, 3));
	grassNode->AddNeighbor(new NeighborNode(PokeType::FLY, 1));
	grassNode->AddNeighbor(new NeighborNode(PokeType::BUG, 1));
	grassNode->AddNeighbor(new NeighborNode(PokeType::ROC, 3));
	grassNode->AddNeighbor(new NeighborNode(PokeType::DRA, 1));
	grassNode->AddNeighbor(new NeighborNode(PokeType::STE, 1));
	//ice
	Node *iceNode = new Node(PokeType::ICE);
	list->nodes[5] = iceNode;
	iceNode->AddNeighbor(new NeighborNode(PokeType::FIR, 1));
	iceNode->AddNeighbor(new NeighborNode(PokeType::WAT, 1));
	iceNode->AddNeighbor(new NeighborNode(PokeType::GRA, 3));
	iceNode->AddNeighbor(new NeighborNode(PokeType::ICE, 1));
	iceNode->AddNeighbor(new NeighborNode(PokeType::GRO, 3));
	iceNode->AddNeighbor(new NeighborNode(PokeType::FLY, 3));
	iceNode->AddNeighbor(new NeighborNode(PokeType::DRA, 3));
	iceNode->AddNeighbor(new NeighborNode(PokeType::STE, 1));
	//fighting
	Node *fightingNode = new Node(PokeType::FIG);
	list->nodes[6] = fightingNode;
	fightingNode->AddNeighbor(new NeighborNode(PokeType::NOR, 3));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::ICE, 3));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::POI, 1));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::FLY, 1));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::PSY, 1));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::BUG, 1));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::ROC, 3));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::GHO, 0));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::DAR, 3));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::STE, 3));
	fightingNode->AddNeighbor(new NeighborNode(PokeType::FAI, 1));
	//poison
	Node *poisonNode = new Node(PokeType::POI);
	list->nodes[7] = poisonNode;
	poisonNode->AddNeighbor(new NeighborNode(PokeType::GRA, 3));
	poisonNode->AddNeighbor(new NeighborNode(PokeType::POI, 1));
	poisonNode->AddNeighbor(new NeighborNode(PokeType::GRO, 1));
	poisonNode->AddNeighbor(new NeighborNode(PokeType::ROC, 1));
	poisonNode->AddNeighbor(new NeighborNode(PokeType::GHO, 1));
	poisonNode->AddNeighbor(new NeighborNode(PokeType::STE, 0));
	poisonNode->AddNeighbor(new NeighborNode(PokeType::FAI, 3));
	//ground
	Node *groundNode = new Node(PokeType::GRO);
	list->nodes[8] = groundNode;
	groundNode->AddNeighbor(new NeighborNode(PokeType::FIR, 3));
	groundNode->AddNeighbor(new NeighborNode(PokeType::ELE, 3));
	groundNode->AddNeighbor(new NeighborNode(PokeType::GRA, 1));
	groundNode->AddNeighbor(new NeighborNode(PokeType::POI, 3));
	groundNode->AddNeighbor(new NeighborNode(PokeType::FLY, 0));
	groundNode->AddNeighbor(new NeighborNode(PokeType::BUG, 1));
	groundNode->AddNeighbor(new NeighborNode(PokeType::ROC, 3));
	groundNode->AddNeighbor(new NeighborNode(PokeType::STE, 3));
	//flying
	Node *flyingNode = new Node(PokeType::FLY);
	list->nodes[9] = flyingNode;
	flyingNode->AddNeighbor(new NeighborNode(PokeType::ELE, 1));
	flyingNode->AddNeighbor(new NeighborNode(PokeType::GRA, 3));
	flyingNode->AddNeighbor(new NeighborNode(PokeType::FIG, 3));
	flyingNode->AddNeighbor(new NeighborNode(PokeType::BUG, 3));
	flyingNode->AddNeighbor(new NeighborNode(PokeType::ROC, 1));
	flyingNode->AddNeighbor(new NeighborNode(PokeType::STE, 1));
	//psychic
	Node *psychicNode = new Node(PokeType::PSY);
	list->nodes[10] = psychicNode;
	psychicNode->AddNeighbor(new NeighborNode(PokeType::FIG, 3));
	psychicNode->AddNeighbor(new NeighborNode(PokeType::POI, 3));
	psychicNode->AddNeighbor(new NeighborNode(PokeType::PSY, 1));
	psychicNode->AddNeighbor(new NeighborNode(PokeType::DAR, 0));
	psychicNode->AddNeighbor(new NeighborNode(PokeType::STE, 1));
	//bug
	Node *bugNode = new Node(PokeType::BUG);
	list->nodes[11] = bugNode;
	bugNode->AddNeighbor(new NeighborNode(PokeType::FIR, 1));
	bugNode->AddNeighbor(new NeighborNode(PokeType::GRA, 3));
	bugNode->AddNeighbor(new NeighborNode(PokeType::FIG, 1));
	bugNode->AddNeighbor(new NeighborNode(PokeType::POI, 1));
	bugNode->AddNeighbor(new NeighborNode(PokeType::FLY, 1));
	bugNode->AddNeighbor(new NeighborNode(PokeType::PSY, 3));
	bugNode->AddNeighbor(new NeighborNode(PokeType::GHO, 1));
	bugNode->AddNeighbor(new NeighborNode(PokeType::DAR, 3));
	bugNode->AddNeighbor(new NeighborNode(PokeType::STE, 1));
	bugNode->AddNeighbor(new NeighborNode(PokeType::FAI, 1));
	//rock
	Node *rockNode = new Node(PokeType::ROC);
	list->nodes[12] = rockNode;
	rockNode->AddNeighbor(new NeighborNode(PokeType::FIR, 3));
	rockNode->AddNeighbor(new NeighborNode(PokeType::ICE, 3));
	rockNode->AddNeighbor(new NeighborNode(PokeType::FIG, 1));
	rockNode->AddNeighbor(new NeighborNode(PokeType::GRO, 1));
	rockNode->AddNeighbor(new NeighborNode(PokeType::FLY, 3));
	rockNode->AddNeighbor(new NeighborNode(PokeType::BUG, 3));
	rockNode->AddNeighbor(new NeighborNode(PokeType::STE, 1));
	//ghost
	Node *ghostNode = new Node(PokeType::GHO);
	list->nodes[13] = ghostNode;
	ghostNode->AddNeighbor(new NeighborNode(PokeType::NOR, 0));
	ghostNode->AddNeighbor(new NeighborNode(PokeType::PSY, 3));
	ghostNode->AddNeighbor(new NeighborNode(PokeType::GHO, 3));
	ghostNode->AddNeighbor(new NeighborNode(PokeType::DAR, 1));
	//dragon
	Node *dragonNode = new Node(PokeType::DRA);
	list->nodes[14] = dragonNode;
	dragonNode->AddNeighbor(new NeighborNode(PokeType::DRA, 3));
	dragonNode->AddNeighbor(new NeighborNode(PokeType::STE, 1));
	dragonNode->AddNeighbor(new NeighborNode(PokeType::FAI, 0));
	//dark
	Node *darkNode = new Node(PokeType::DAR);
	list->nodes[15] = darkNode;
	darkNode->AddNeighbor(new NeighborNode(PokeType::FIG, 1));
	darkNode->AddNeighbor(new NeighborNode(PokeType::PSY, 3));
	darkNode->AddNeighbor(new NeighborNode(PokeType::GHO, 3));
	darkNode->AddNeighbor(new NeighborNode(PokeType::DAR, 1));
	darkNode->AddNeighbor(new NeighborNode(PokeType::FAI, 1));
	//steel
	Node *steelNode = new Node(PokeType::STE);
	list->nodes[16] = steelNode;
	steelNode->AddNeighbor(new NeighborNode(PokeType::FIR, 1));
	steelNode->AddNeighbor(new NeighborNode(PokeType::WAT, 1));
	steelNode->AddNeighbor(new NeighborNode(PokeType::ELE, 1));
	steelNode->AddNeighbor(new NeighborNode(PokeType::ICE, 3));
	steelNode->AddNeighbor(new NeighborNode(PokeType::ROC, 3));
	steelNode->AddNeighbor(new NeighborNode(PokeType::STE, 1));
	steelNode->AddNeighbor(new NeighborNode(PokeType::FAI, 3));
	//fairy
	Node *fairyNode = new Node(PokeType::FAI);
	list->nodes[17] = fairyNode;
	fairyNode->AddNeighbor(new NeighborNode(PokeType::FIR, 1));
	fairyNode->AddNeighbor(new NeighborNode(PokeType::FIG, 3));
	fairyNode->AddNeighbor(new NeighborNode(PokeType::POI, 1));
	fairyNode->AddNeighbor(new NeighborNode(PokeType::DRA, 3));
	fairyNode->AddNeighbor(new NeighborNode(PokeType::DAR, 3));
	fairyNode->AddNeighbor(new NeighborNode(PokeType::STE, 1));

	return list;
}

Node *AdjacencyList::GetNode(PokeType pokeType)
{
	return nodes[pokeType];
}

float AdjacencyList::GetAttackMultiplier(PokeType moveType, PokeType pokeType)
{
	auto moveNode = nodes[moveType];
	auto pokeNode = nodes[pokeType];
	auto multiplier = ((NeighborNode *)moveNode->Neighbor)->GetMultiplier(pokeType);
	return multiplier;
}