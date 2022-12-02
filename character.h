#ifndef CHARACTER_H
#define CHARACTER_H

#pragma once
#include <string>
#include "tile.h"

using std::string;
class Tile;

class Character
{
  const string texture;
  Tile* tile;
public:
  Character();
  Character(string t);

  string getTexture();
  Tile* getTile();
  bool setTile(Tile* t);
};

#endif // CHARACTER_H
