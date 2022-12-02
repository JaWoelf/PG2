#include "portal.h"

Portal::~Portal() {};

Portal::Portal(int _row, int _column) : Tile("O", _row, _column)
{

}

Tile* Portal::onEnter(Tile* src, Character* who)
{
  cout << "Portal:from["<<src->getRow()<<"]["<<src->getCol()<< "])" << endl;
  cout << "Portal:self["<<this->getRow()<<"]["<<this->getCol()<< "])" << endl;
  cout << "Portal:dest["<<dst->getRow()<<"]["<<dst->getCol()<< "])" << endl;

  if (this->hasCharacter())
    return nullptr;
  if (dst->hasCharacter())
    return this;
  return dst;
}

void Portal::setLink(Portal* p)
{
  dst = p;
};
