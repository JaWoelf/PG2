#ifndef DOOR_H
#define DOOR_H

#pragma once
#include "tile.h"
#include "passive.h"

#include <string>
#include <iostream>
using std::cout, std::endl;

class Door : public Tile, public Passive
{
public:
  Door(int row, int col);
  ~Door();
  Door(Door& d);

  Tile* onEnter(Tile* src, Character* who) override;
  void notify(Active *source) override;
};

#endif // DOOR_H
