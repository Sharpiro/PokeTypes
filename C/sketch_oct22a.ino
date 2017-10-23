//float array [] = {
//    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 0.0, 1.0, 1.0, 0.5, 1.0,
//    1.0, 0.5, 0.5, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 2.0, 1.0,
//    1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0, 1.0,
//    1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0,
//    1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 0.5, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 0.5, 1.0,
//    1.0, 0.5, 0.5, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0,
//    2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5, 0.5, 0.5, 2.0, 0.0, 1.0, 2.0, 2.0, 0.5,
//    1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 0.0, 2.0,
//    1.0, 2.0, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0,
//    1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5, 1.0,
//    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 0.0, 0.5, 1.0,
//    1.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.5, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0, 0.5, 1.0, 2.0, 0.5, 0.5,
//    1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0,
//    0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0,
//    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 0.0,
//    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5,
//    1.0, 0.5, 0.5, 0.5, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 2.0,
//    1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 0.5, 1.0
//}; 

enum PokeType{
  NOR, FIR, WAT, ELE, GRA, ICE, FIG, POI, GRO, FLY, PSY, BUG, ROC, GHO, DRA, DAR, STE, FAI
};

class BaseNeighbor
{
  protected:
    PokeType Type;
    BaseNeighbor* Neighbor;

    public:
    BaseNeighbor(PokeType pokeType){
      Type = pokeType;
    }

  public:
    void BaseNeighbor::AddNeighbor(BaseNeighbor* newNeighbor)
    {
      if (Neighbor == nullptr)
        {
          Neighbor = newNeighbor;
        }
      else{
        Neighbor->AddNeighbor(newNeighbor);
      }
    }

    void Print(){
//       if (Neighbor == nullptr)
//        {
//          Neighbor = newNeighbor;
//        }
//      else{
//        Neighbor->AddNeighbor(newNeighbor);
//      }
    }
};

class PokeNeighbor : public BaseNeighbor{
  float Data;

  public:
  PokeNeighbor(PokeType pokeType, float data): BaseNeighbor(pokeType){
      Data = data;
    }
};

class Node: public BaseNeighbor{ 
  public:
    Node(PokeType pokeType):BaseNeighbor(pokeType){
      
    }
  };

void setup() {
  Node* node = new Node(PokeType::NOR);
  //normal
  node->AddNeighbor(new PokeNeighbor(PokeType::ROC, 0.5));
  node->AddNeighbor(new PokeNeighbor(PokeType::GHO, 0.0));
  node->AddNeighbor(new PokeNeighbor(PokeType::STE, 0.5));
  //fire
  node->AddNeighbor(new PokeNeighbor(PokeType::FIR, 0.5));
  node->AddNeighbor(new PokeNeighbor(PokeType::WAT, 0.5));
  node->AddNeighbor(new PokeNeighbor(PokeType::GRA, 2.0));
  node->AddNeighbor(new PokeNeighbor(PokeType::ICE, 2.0));
  node->AddNeighbor(new PokeNeighbor(PokeType::BUG, 2.0));
  node->AddNeighbor(new PokeNeighbor(PokeType::ROC, .05));
  node->AddNeighbor(new PokeNeighbor(PokeType::DRA, 0.5));
  node->AddNeighbor(new PokeNeighbor(PokeType::STE, 2.0));
//  node->Neighbor = new PokeNeighbor();
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:

}
