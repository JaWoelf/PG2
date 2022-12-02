#ifndef FLOOR_H
#define FLOOR_H

#pragma once
#include "tile.h"

class Floor : public Tile
{
public:
  ~Floor();
  Floor(Floor& f);
  Floor(int row, int col);

  Tile* onEnter(Tile* src, Character* who) override;
  //Tile* onLeave(Tile* dst, Character* whi) override;
};

#endif // FLOOR_H
