#ifndef LEVEL_H
#define LEVEL_H

#pragma once
#include <vector>
#include <string>
#include <math.h>

#include "tile.h"
#include "portal.h"
#include "floor.h"
#include "wall.h"
#include "door.h"
#include "switch.h"
#include "pit.h"
#include "ramp.h"

#include "active.h"
#include "passive.h"

#include "character.h"
#include "npc.h"

#include "guardcontroller.h"

using std::string;
using std::vector;

class Level
{
public:
  Level();
  Level(string map);
  Level(Level& l);
  ~Level();


  Tile* getTile(int row, int col);
  const Tile* getTile(int row, int col) const;

  void placeCharacter(Character* c, int& row, int& col);
  void placeTile(Tile* t, int& row, int& col);

  Level & operator=(const Level& rhs);

  void swapTile(Tile* t0, Tile* t1);
  void swapCharacter(Character* c0, Character* c1);

  int getHeight();// const;
  int getWidth();// const;

  void setCharacter(Character *c, int row, int col);
  Character* getCharacter();
  vector<Npc*> getNpcs();

  Tile* buildTileFromChar(char t, int trow, int tcol);

protected:
  vector<vector<Tile*>> grid{};
  Character* character;
  vector<Npc*> npcs;
  const int height, width;

};

#endif // LEVEL_H
