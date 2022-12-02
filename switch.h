#ifndef SWITCH_H
#define SWITCH_H

#pragma once
#include "tile.h"
#include "active.h"
#include "passive.h"

class Switch : public Tile, public Active
{
public:
  Switch(int row, int col);
  ~Switch();
  Switch(Switch& s);

  // : public Tile
  Tile* onEnter(Tile* src, Character* who) override;

  // : public Active


};

#endif // SWITCH_H
