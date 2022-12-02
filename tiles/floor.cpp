#include "floor.h"

Floor::~Floor() {};

Floor::Floor(int row, int col) : Tile(".", row, col)
{

}

Tile* Floor::onEnter(Tile* src, Character* who)
{
//  cout << "Floor::onEnter(Tile["<<src->getRow()<<"]["<<src->getCol()<< "])" << endl;
  if (this->hasCharacter())
    return nullptr;
  return this;
}
