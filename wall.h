#ifndef WALL_H
#define WALL_H

#pragma once
#include "tile.h"

class Wall : public Tile
{
public:
  Wall(int row, int col);
  ~Wall();
  Wall(Wall& w);

  Tile* onEnter(Tile* src, Character* who) override;
  //Tile* onLeave(Tile* dst, Character* whi) override;
};

#endif // WALL_H
