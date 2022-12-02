#ifndef TILE_H
#define TILE_H

#pragma once
#include <string>
#include "character.h"

// DBG //
#include <iostream>
using std::cout; using std::endl;

using std::string;

class Character;

class Tile
{
protected:
  string texture;
  Character* character;
  const int row, col;

public:
  Tile(string texture, int row, int col);
  virtual ~Tile();
  Tile(Tile& t);

  string getTexture();
  bool hasCharacter();
  void setCharacter(Character* c);
  int getRow();
  int getCol();

  bool moveTo(Tile* dst, Character* who);
  virtual Tile* onEnter(Tile* src, Character* who) = 0;
  virtual Tile* onLeave(Tile* dst, Character* who);

};

#endif // TILE_H
