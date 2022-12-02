#include "wall.h"

Wall::~Wall() {} ;

Wall::Wall(int row, int col) : Tile("#", row, col)
{

}

Tile* Wall::onEnter(Tile* src, Character* who)
{
//  cout << "Wall::onEnter(Tile["<<src->getRow()<<"]["<<src->getCol()<< "])" << endl;
  return nullptr;
}
