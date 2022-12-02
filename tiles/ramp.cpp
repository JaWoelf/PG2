#include "ramp.h"

Ramp::~Ramp() {};

Ramp::Ramp(int row, int col) : Tile("<", row, col)
{

}

Tile* Ramp::onEnter(Tile *src, Character *who)
{
  if (this->hasCharacter())
    return nullptr;
  return this;
}

