#include "switch.h"

Switch::~Switch() {};

Switch::Switch(int _row, int _col)
  : Tile("?", _row, _col)//, Active()
{

}

Tile* Switch::onEnter(Tile *src, Character *who)
{
  if (this->hasCharacter())
    return nullptr;

  this->activate();
  return this;
}
