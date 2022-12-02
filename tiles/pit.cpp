#include "pit.h"

Pit::~Pit() {};

Pit::Pit(int row, int col) : Tile("_", row, col)
{

}

Tile* Pit::onEnter(Tile *src, Character *who)
{
  if (this->hasCharacter())
    return nullptr;
  return this;
}

Tile* Pit::onLeave(Tile *dst, Character *who)
{
  cout << "Pit[" << row << "][" << col << "::onLeave(dst["<< dst->getCol() << "][" << dst->getRow()<< "]" << endl;
  if (dst->getTexture() == "<" || dst->getTexture() == "_")
    return this;
  return nullptr;
}
